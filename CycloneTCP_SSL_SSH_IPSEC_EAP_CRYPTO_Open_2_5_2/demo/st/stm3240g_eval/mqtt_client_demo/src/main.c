/**
 * @file main.c
 * @brief Main routine
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2025 Oryx Embedded SARL. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.5.2
 **/

//Dependencies
#include <stdlib.h>
#include "stm32f4xx.h"
#include "stm324xg_eval.h"
#include "stm324xg_eval_lcd.h"
#include "core/net.h"
#include "drivers/mac/stm32f4xx_eth_driver.h"
#include "drivers/phy/dp83848_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "mqtt/mqtt_client.h"
#include "hardware/stm32f4xx/stm32f4xx_crypto.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "mqtt-client-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-04-07"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::407"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::407"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//MQTT server name
#define APP_SERVER_NAME "test.mosquitto.org"

//MQTT server port
#define APP_SERVER_PORT 1883   //MQTT over TCP
//#define APP_SERVER_PORT 8883 //MQTT over TLS
//#define APP_SERVER_PORT 8884 //MQTT over TLS (mutual authentication)
//#define APP_SERVER_PORT 8080 //MQTT over WebSocket
//#define APP_SERVER_PORT 8081 //MQTT over secure WebSocket

//URI (for MQTT over WebSocket only)
#define APP_SERVER_URI "/ws"

//Client's certificate
const char_t clientCert[] =
   "-----BEGIN CERTIFICATE-----"
   "MIICmzCCAYOgAwIBAgIBADANBgkqhkiG9w0BAQsFADCBkDELMAkGA1UEBhMCR0Ix"
   "FzAVBgNVBAgMDlVuaXRlZCBLaW5nZG9tMQ4wDAYDVQQHDAVEZXJieTESMBAGA1UE"
   "CgwJTW9zcXVpdHRvMQswCQYDVQQLDAJDQTEWMBQGA1UEAwwNbW9zcXVpdHRvLm9y"
   "ZzEfMB0GCSqGSIb3DQEJARYQcm9nZXJAYXRjaG9vLm9yZzAeFw0yNDA1MjAxMjIw"
   "MTJaFw0yNDA4MTgxMjIwMTJaMEAxCzAJBgNVBAYTAkZSMRYwFAYDVQQKDA1Pcnl4"
   "IEVtYmVkZGVkMRkwFwYDVQQDDBBtcXR0LWNsaWVudC1kZW1vMFkwEwYHKoZIzj0C"
   "AQYIKoZIzj0DAQcDQgAEWT/enOkLuY+9NzUQPOuNVFARl5Y3bc4lLt3TyVwWG0Ez"
   "IIk8Wll5Ljjrv+buPSKBVQtOwF9VgyW4QuQ1uYSAIaMaMBgwCQYDVR0TBAIwADAL"
   "BgNVHQ8EBAMCBeAwDQYJKoZIhvcNAQELBQADggEBALW6YSU2jqs7TegW2CoydK7W"
   "rEzy/8ecasdeDy+8vIkxC1chtm2VgYsndFUaLhSD31I0paLqE67kGzyD8TKhBAyp"
   "4trhLsgFUjTsKYj8kPj147am2wwP0hbd1dygr+kaNxV3glZqot8IK2+topA3BbFO"
   "34wvdNI81o63ldKn+Q3sp522osxfwiCy8/5DZ+2VLzGBwbsKaYNk2RwhUNbF88eD"
   "IHAi9iY3YYx7hE9UvMA3CbWBOmz06lFWr2Nwyr3lYM6qO87GKKMZaFjdrFtzQlaB"
   "ngH1f6yCuM0iwd7gbWKwPWoilIDdg8DVi38fN/Clv5PbTt+KJslVbNElV6ykbyA="
   "-----END CERTIFICATE-----";

//Client's private key
const char_t clientKey[] =
   "-----BEGIN EC PRIVATE KEY-----"
   "MHcCAQEEICYULY0KQ6nDAXFl5tgK9ljqAZyb14JQmI3iT7tdScDloAoGCCqGSM49"
   "AwEHoUQDQgAEWT/enOkLuY+9NzUQPOuNVFARl5Y3bc4lLt3TyVwWG0EzIIk8Wll5"
   "Ljjrv+buPSKBVQtOwF9VgyW4QuQ1uYSAIQ=="
   "-----END EC PRIVATE KEY-----";

//List of trusted CA certificates
const char_t trustedCaList[] =
   "-----BEGIN CERTIFICATE-----"
   "MIIEAzCCAuugAwIBAgIUBY1hlCGvdj4NhBXkZ/uLUZNILAwwDQYJKoZIhvcNAQEL"
   "BQAwgZAxCzAJBgNVBAYTAkdCMRcwFQYDVQQIDA5Vbml0ZWQgS2luZ2RvbTEOMAwG"
   "A1UEBwwFRGVyYnkxEjAQBgNVBAoMCU1vc3F1aXR0bzELMAkGA1UECwwCQ0ExFjAU"
   "BgNVBAMMDW1vc3F1aXR0by5vcmcxHzAdBgkqhkiG9w0BCQEWEHJvZ2VyQGF0Y2hv"
   "by5vcmcwHhcNMjAwNjA5MTEwNjM5WhcNMzAwNjA3MTEwNjM5WjCBkDELMAkGA1UE"
   "BhMCR0IxFzAVBgNVBAgMDlVuaXRlZCBLaW5nZG9tMQ4wDAYDVQQHDAVEZXJieTES"
   "MBAGA1UECgwJTW9zcXVpdHRvMQswCQYDVQQLDAJDQTEWMBQGA1UEAwwNbW9zcXVp"
   "dHRvLm9yZzEfMB0GCSqGSIb3DQEJARYQcm9nZXJAYXRjaG9vLm9yZzCCASIwDQYJ"
   "KoZIhvcNAQEBBQADggEPADCCAQoCggEBAME0HKmIzfTOwkKLT3THHe+ObdizamPg"
   "UZmD64Tf3zJdNeYGYn4CEXbyP6fy3tWc8S2boW6dzrH8SdFf9uo320GJA9B7U1FW"
   "Te3xda/Lm3JFfaHjkWw7jBwcauQZjpGINHapHRlpiCZsquAthOgxW9SgDgYlGzEA"
   "s06pkEFiMw+qDfLo/sxFKB6vQlFekMeCymjLCbNwPJyqyhFmPWwio/PDMruBTzPH"
   "3cioBnrJWKXc3OjXdLGFJOfj7pP0j/dr2LH72eSvv3PQQFl90CZPFhrCUcRHSSxo"
   "E6yjGOdnz7f6PveLIB574kQORwt8ePn0yidrTC1ictikED3nHYhMUOUCAwEAAaNT"
   "MFEwHQYDVR0OBBYEFPVV6xBUFPiGKDyo5V3+Hbh4N9YSMB8GA1UdIwQYMBaAFPVV"
   "6xBUFPiGKDyo5V3+Hbh4N9YSMA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEL"
   "BQADggEBAGa9kS21N70ThM6/Hj9D7mbVxKLBjVWe2TPsGfbl3rEDfZ+OKRZ2j6AC"
   "6r7jb4TZO3dzF2p6dgbrlU71Y/4K0TdzIjRj3cQ3KSm41JvUQ0hZ/c04iGDg/xWf"
   "+pp58nfPAYwuerruPNWmlStWAXf0UTqRtg4hQDWBuUFDJTuWuuBvEXudz74eh/wK"
   "sMwfu1HFvjy5Z0iMDU8PUDepjVolOCue9ashlS4EB5IECdSR2TItnAIiIwimx839"
   "LdUdRudafMu5T5Xma182OC0/u/xRlEm+tvKGGmfFcN0piqVl8OrSPBgIlb+1IKJE"
   "m/XriWr/Cq4h/JfB7NTsezVslgkBaoU="
   "-----END CERTIFICATE-----"
   "-----BEGIN CERTIFICATE-----"
   "MIIFFjCCAv6gAwIBAgIRAJErCErPDBinU/bWLiWnX1owDQYJKoZIhvcNAQELBQAw"
   "TzELMAkGA1UEBhMCVVMxKTAnBgNVBAoTIEludGVybmV0IFNlY3VyaXR5IFJlc2Vh"
   "cmNoIEdyb3VwMRUwEwYDVQQDEwxJU1JHIFJvb3QgWDEwHhcNMjAwOTA0MDAwMDAw"
   "WhcNMjUwOTE1MTYwMDAwWjAyMQswCQYDVQQGEwJVUzEWMBQGA1UEChMNTGV0J3Mg"
   "RW5jcnlwdDELMAkGA1UEAxMCUjMwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEK"
   "AoIBAQC7AhUozPaglNMPEuyNVZLD+ILxmaZ6QoinXSaqtSu5xUyxr45r+XXIo9cP"
   "R5QUVTVXjJ6oojkZ9YI8QqlObvU7wy7bjcCwXPNZOOftz2nwWgsbvsCUJCWH+jdx"
   "sxPnHKzhm+/b5DtFUkWWqcFTzjTIUu61ru2P3mBw4qVUq7ZtDpelQDRrK9O8Zutm"
   "NHz6a4uPVymZ+DAXXbpyb/uBxa3Shlg9F8fnCbvxK/eG3MHacV3URuPMrSXBiLxg"
   "Z3Vms/EY96Jc5lP/Ooi2R6X/ExjqmAl3P51T+c8B5fWmcBcUr2Ok/5mzk53cU6cG"
   "/kiFHaFpriV1uxPMUgP17VGhi9sVAgMBAAGjggEIMIIBBDAOBgNVHQ8BAf8EBAMC"
   "AYYwHQYDVR0lBBYwFAYIKwYBBQUHAwIGCCsGAQUFBwMBMBIGA1UdEwEB/wQIMAYB"
   "Af8CAQAwHQYDVR0OBBYEFBQusxe3WFbLrlAJQOYfr52LFMLGMB8GA1UdIwQYMBaA"
   "FHm0WeZ7tuXkAXOACIjIGlj26ZtuMDIGCCsGAQUFBwEBBCYwJDAiBggrBgEFBQcw"
   "AoYWaHR0cDovL3gxLmkubGVuY3Iub3JnLzAnBgNVHR8EIDAeMBygGqAYhhZodHRw"
   "Oi8veDEuYy5sZW5jci5vcmcvMCIGA1UdIAQbMBkwCAYGZ4EMAQIBMA0GCysGAQQB"
   "gt8TAQEBMA0GCSqGSIb3DQEBCwUAA4ICAQCFyk5HPqP3hUSFvNVneLKYY611TR6W"
   "PTNlclQtgaDqw+34IL9fzLdwALduO/ZelN7kIJ+m74uyA+eitRY8kc607TkC53wl"
   "ikfmZW4/RvTZ8M6UK+5UzhK8jCdLuMGYL6KvzXGRSgi3yLgjewQtCPkIVz6D2QQz"
   "CkcheAmCJ8MqyJu5zlzyZMjAvnnAT45tRAxekrsu94sQ4egdRCnbWSDtY7kh+BIm"
   "lJNXoB1lBMEKIq4QDUOXoRgffuDghje1WrG9ML+Hbisq/yFOGwXD9RiX8F6sw6W4"
   "avAuvDszue5L3sz85K+EC4Y/wFVDNvZo4TYXao6Z0f+lQKc0t8DQYzk1OXVu8rp2"
   "yJMC6alLbBfODALZvYH7n7do1AZls4I9d1P4jnkDrQoxB3UqQ9hVl3LEKQ73xF1O"
   "yK5GhDDX8oVfGKF5u+decIsH4YaTw7mP3GFxJSqv3+0lUFJoi5Lc5da149p90Ids"
   "hCExroL1+7mryIkXPeFM5TgO9r0rvZaBFOvV2z0gp35Z0+L4WPlbuEjN/lxPFin+"
   "HlUjr8gRsI3qfJOQFy/9rKIJR0Y/8Omwt/8oTWgy1mdeHmmjk7j1nYsvC9JSQ6Zv"
   "MldlTTKB3zhThV1+XWYp6rjd5JW1zbVWEkLNxE7GJThEUG3szgBVGP7pSWTUTsqX"
   "nLRbwHOoq7hHwg=="
   "-----END CERTIFICATE-----";

//Global variables
uint_t lcdLine = 0;
uint_t lcdColumn = 0;
uint_t adcValue = 0;

ADC_HandleTypeDef ADC_Handle;
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
MqttClientContext mqttClientContext;
HmacDrbgContext hmacDrbgContext;
uint8_t seed[48];


/**
 * @brief Set cursor location
 * @param[in] line Line number
 * @param[in] column Column number
 **/

void lcdSetCursor(uint_t line, uint_t column)
{
   lcdLine = MIN(line, 10);
   lcdColumn = MIN(column, 20);
}


/**
 * @brief Write a character to the LCD display
 * @param[in] c Character to be written
 **/

void lcdPutChar(char_t c)
{
   if(c == '\r')
   {
      lcdColumn = 0;
   }
   else if(c == '\n')
   {
      lcdColumn = 0;
      lcdLine++;
   }
   else if(lcdLine < 10 && lcdColumn < 20)
   {
      //Display current character
      BSP_LCD_DisplayChar(lcdColumn * 16, lcdLine * 24, c);

      //Advance the cursor position
      if(++lcdColumn >= 20)
      {
         lcdColumn = 0;
         lcdLine++;
      }
   }
}


/**
 * @brief System clock configuration
 **/

void SystemClock_Config(void)
{
   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

   //Enable Power Control clock
   __HAL_RCC_PWR_CLK_ENABLE();

   //The voltage scaling allows optimizing the power consumption when the
   //device is clocked below the maximum system frequency
   __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

   //Enable HSE Oscillator and activate PLL with HSE as source
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
   RCC_OscInitStruct.HSEState = RCC_HSE_ON;
   RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
   RCC_OscInitStruct.PLL.PLLM = 25;
   RCC_OscInitStruct.PLL.PLLN = 336;
   RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
   RCC_OscInitStruct.PLL.PLLQ = 7;
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
   //clocks dividers
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;
   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

   //Revision Z devices?
   if (HAL_GetREVID() == 0x1001)
   {
      //Enable Flash prefetch
      __HAL_FLASH_PREFETCH_BUFFER_ENABLE();
   }
}


/**
 * @brief ADC3 initialization
 **/

void adc3Init(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;
   ADC_ChannelConfTypeDef ADC_ChannelConfig;

   //Enable peripheral clocks
   __HAL_RCC_GPIOF_CLK_ENABLE();
   __HAL_RCC_ADC3_CLK_ENABLE();

   //Configure PF9 as an analog input
   GPIO_InitStructure.Pin = GPIO_PIN_9;
   GPIO_InitStructure.Mode = GPIO_MODE_ANALOG;
   GPIO_InitStructure.Pull = GPIO_NOPULL;
   HAL_GPIO_Init(GPIOF, &GPIO_InitStructure);

   //Configure ADC peripheral
   ADC_Handle.Instance = ADC3;
   ADC_Handle.Init.ClockPrescaler = ADC_CLOCKPRESCALER_PCLK_DIV2;
   ADC_Handle.Init.Resolution = ADC_RESOLUTION12b;
   ADC_Handle.Init.ScanConvMode = DISABLE;
   ADC_Handle.Init.ContinuousConvMode = DISABLE;
   ADC_Handle.Init.DiscontinuousConvMode = DISABLE;
   ADC_Handle.Init.NbrOfDiscConversion = 0;
   ADC_Handle.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_NONE;
   ADC_Handle.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
   ADC_Handle.Init.DataAlign = ADC_DATAALIGN_RIGHT;
   ADC_Handle.Init.NbrOfConversion = 1;
   ADC_Handle.Init.DMAContinuousRequests = DISABLE;
   ADC_Handle.Init.EOCSelection = DISABLE;
   HAL_ADC_Init(&ADC_Handle);

   //Configure ADC regular channel
   ADC_ChannelConfig.Channel = ADC_CHANNEL_7;
   ADC_ChannelConfig.Rank = 1;
   ADC_ChannelConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
   ADC_ChannelConfig.Offset = 0;
   HAL_ADC_ConfigChannel(&ADC_Handle, &ADC_ChannelConfig);
}


/**
 * @brief Random data generation callback function
 * @param[out] data Buffer where to store the random data
 * @param[in] length Number of bytes that are required
 * @return Error code
 **/

error_t webSocketRngCallback(uint8_t *data, size_t length)
{
   //Generate some random data
   return hmacDrbgGenerate(&hmacDrbgContext, data, length);
}


/**
 * @brief TLS initialization callback
 * @param[in] context Pointer to the MQTT client context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t mqttTestTlsInitCallback(MqttClientContext *context,
   TlsContext *tlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("MQTT: TLS initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
   //Any error to report?
   if(error)
      return error;

   //Set the fully qualified domain name of the server
   error = tlsSetServerName(tlsContext, APP_SERVER_NAME);
   //Any error to report?
   if(error)
      return error;

#if (APP_SERVER_PORT == 8884)
   //Load client's certificate
   error = tlsLoadCertificate(tlsContext, 0, clientCert, strlen(clientCert),
      clientKey, strlen(clientKey), NULL);
   //Any error to report?
   if(error)
      return error;
#endif

   //Import trusted CA certificates
   error = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList));
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Publish callback function
 * @param[in] context Pointer to the MQTT client context
 * @param[in] topic Topic name
 * @param[in] message Message payload
 * @param[in] length Length of the message payload
 * @param[in] dup Duplicate delivery of the PUBLISH packet
 * @param[in] qos QoS level used to publish the message
 * @param[in] retain This flag specifies if the message is to be retained
 * @param[in] packetId Packet identifier
 **/

void mqttTestPublishCallback(MqttClientContext *context,
   const char_t *topic, const uint8_t *message, size_t length,
   bool_t dup, MqttQosLevel qos, bool_t retain, uint16_t packetId)
{
   //Debug message
   TRACE_INFO("PUBLISH packet received...\r\n");
   TRACE_INFO("  Dup: %u\r\n", dup);
   TRACE_INFO("  QoS: %u\r\n", qos);
   TRACE_INFO("  Retain: %u\r\n", retain);
   TRACE_INFO("  Packet Identifier: %u\r\n", packetId);
   TRACE_INFO("  Topic: %s\r\n", topic);
   TRACE_INFO("  Message (%" PRIuSIZE " bytes):\r\n", length);
   TRACE_INFO_ARRAY("    ", message, length);

   //Check topic name
   if(!strcmp(topic, "board/leds/1"))
   {
      if(length == 6 && !strncasecmp((char_t *) message, "toggle", 6))
         BSP_LED_Toggle(LED2);
      else if(length == 2 && !strncasecmp((char_t *) message, "on", 2))
         BSP_LED_On(LED2);
      else
         BSP_LED_Off(LED2);
   }
   else if(!strcmp(topic, "board/leds/2"))
   {
      if(length == 6 && !strncasecmp((char_t *) message, "toggle", 6))
         BSP_LED_Toggle(LED3);
      else if(length == 2 && !strncasecmp((char_t *) message, "on", 2))
         BSP_LED_On(LED3);
      else
         BSP_LED_Off(LED3);
   }
   else if(!strcmp(topic, "board/leds/3"))
   {
      if(length == 6 && !strncasecmp((char_t *) message, "toggle", 6))
         BSP_LED_Toggle(LED4);
      else if(length == 2 && !strncasecmp((char_t *) message, "on", 2))
         BSP_LED_On(LED4);
      else
         BSP_LED_Off(LED4);
   }
}


/**
 * @brief Establish MQTT connection
 **/

error_t mqttTestConnect(void)
{
   error_t error;
   IpAddr ipAddr;

   //Debug message
   TRACE_INFO("\r\n\r\nResolving server name...\r\n");

   //Resolve MQTT server name
   error = getHostByName(NULL, APP_SERVER_NAME, &ipAddr, 0);
   //Any error to report?
   if(error)
      return error;

#if (APP_SERVER_PORT == 8080 || APP_SERVER_PORT == 8081)
   //Register RNG callback
   webSocketRegisterRandCallback(webSocketRngCallback);
#endif

   //Set the MQTT version to be used
   mqttClientSetVersion(&mqttClientContext, MQTT_VERSION_3_1_1);

#if (APP_SERVER_PORT == 1883)
   //MQTT over TCP
   mqttClientSetTransportProtocol(&mqttClientContext, MQTT_TRANSPORT_PROTOCOL_TCP);
#elif (APP_SERVER_PORT == 8883 || APP_SERVER_PORT == 8884)
   //MQTT over TLS
   mqttClientSetTransportProtocol(&mqttClientContext, MQTT_TRANSPORT_PROTOCOL_TLS);
   //Register TLS initialization callback
   mqttClientRegisterTlsInitCallback(&mqttClientContext, mqttTestTlsInitCallback);
#elif (APP_SERVER_PORT == 8080)
   //MQTT over WebSocket
   mqttClientSetTransportProtocol(&mqttClientContext, MQTT_TRANSPORT_PROTOCOL_WS);
#elif (APP_SERVER_PORT == 8081)
   //MQTT over secure WebSocket
   mqttClientSetTransportProtocol(&mqttClientContext, MQTT_TRANSPORT_PROTOCOL_WSS);
   //Register TLS initialization callback
   mqttClientRegisterTlsInitCallback(&mqttClientContext, mqttTestTlsInitCallback);
#endif

   //Register publish callback function
   mqttClientRegisterPublishCallback(&mqttClientContext, mqttTestPublishCallback);

   //Set communication timeout
   mqttClientSetTimeout(&mqttClientContext, 20000);
   //Set keep-alive value
   mqttClientSetKeepAlive(&mqttClientContext, 30);

#if (APP_SERVER_PORT == 8080 || APP_SERVER_PORT == 8081)
   //Set the hostname of the resource being requested
   mqttClientSetHost(&mqttClientContext, APP_SERVER_NAME);
   //Set the name of the resource being requested
   mqttClientSetUri(&mqttClientContext, APP_SERVER_URI);
#endif

   //Set client identifier
   //mqttClientSetIdentifier(&mqttClientContext, "client12345678");

   //Set user name and password
   //mqttClientSetAuthInfo(&mqttClientContext, "username", "password");

   //Set Will message
   mqttClientSetWillMessage(&mqttClientContext, "board/status",
      "offline", 7, MQTT_QOS_LEVEL_0, FALSE);

   //Debug message
   TRACE_INFO("Connecting to MQTT server %s...\r\n", ipAddrToString(&ipAddr, NULL));

   //Start of exception handling block
   do
   {
      //Establish connection with the MQTT server
      error = mqttClientConnect(&mqttClientContext,
         &ipAddr, APP_SERVER_PORT, TRUE);
      //Any error to report?
      if(error)
         break;

      //Subscribe to the desired topics
      error = mqttClientSubscribe(&mqttClientContext,
         "board/leds/+", MQTT_QOS_LEVEL_1, NULL);
      //Any error to report?
      if(error)
         break;

      //Send PUBLISH packet
      error = mqttClientPublish(&mqttClientContext, "board/status",
         "online", 6, MQTT_QOS_LEVEL_1, TRUE, NULL);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Check status code
   if(error)
   {
      //Close connection
      mqttClientClose(&mqttClientContext);
   }

   //Return status code
   return error;
}


/**
 * @brief MQTT test task
 **/

void mqttTestTask(void *param)
{
   error_t error;
   uint_t n;
   bool_t connectionState;
   uint_t buttonState;
   uint_t prevButtonState;
   uint_t prevAdcValue;
   char_t buffer[16];

   //Initialize variables
   connectionState = FALSE;
   prevButtonState = 0;
   prevAdcValue = 0;

   //Initialize MQTT client context
   mqttClientInit(&mqttClientContext);

   //Endless loop
   while(1)
   {
      //Check connection state
      if(!connectionState)
      {
         //Make sure the link is up
         if(netGetLinkState(&netInterface[0]))
         {
            //Try to connect to the MQTT server
            error = mqttTestConnect();

            //Successful connection?
            if(!error)
            {
               //The MQTT client is connected to the server
               connectionState = TRUE;
            }
            else
            {
               //Delay between subsequent connection attempts
               osDelayTask(2000);
            }
         }
         else
         {
            //The link is down
            osDelayTask(1000);
         }
      }
      else
      {
         //Initialize status code
         error = NO_ERROR;

         //Get user button state
         buttonState = BSP_PB_GetState(BUTTON_KEY);

         //Any change detected?
         if(buttonState != prevButtonState)
         {
            if(buttonState)
               strcpy(buffer, "pressed");
            else
               strcpy(buffer, "released");

            //Send PUBLISH packet
            error = mqttClientPublish(&mqttClientContext, "board/buttons/1",
               buffer, strlen(buffer), MQTT_QOS_LEVEL_1, TRUE, NULL);

            //Save current state
            prevButtonState = buttonState;
         }

         //Check status code
         if(!error)
         {
            //Get ADC value
            n = adcValue * 100 / 4095;

            //Any change detected?
            if(n != prevAdcValue)
            {
               //Convert ADC value to string
               sprintf(buffer, "%u", n);

               //Send PUBLISH packet
               error = mqttClientPublish(&mqttClientContext, "board/adc",
                  buffer, strlen(buffer), MQTT_QOS_LEVEL_1, TRUE, NULL);

               //Save current value
               prevAdcValue = n;
            }
         }

         //Check status code
         if(!error)
         {
            //Process events
            error = mqttClientTask(&mqttClientContext, 100);
         }

         //Connection to MQTT server lost?
         if(error)
         {
            //Close connection
            mqttClientClose(&mqttClientContext);
            //Update connection state
            connectionState = FALSE;
            //Recovery delay
            osDelayTask(2000);
         }
      }
   }
}


/**
 * @brief User task
 * @param[in] param Unused parameter
 **/

void userTask(void *param)
{
   char_t buffer[40];
#if (IPV4_SUPPORT == ENABLED)
   Ipv4Addr ipv4Addr;
   Ipv4Addr ipv4HostAddr = IPV4_UNSPECIFIED_ADDR;;
#endif
#if (IPV6_SUPPORT == ENABLED)
   Ipv6Addr ipv6Addr;
   Ipv6Addr ipv6LinkLocalAddr = IPV6_UNSPECIFIED_ADDR;;
   Ipv6Addr ipv6GlobalAddr = IPV6_UNSPECIFIED_ADDR;
#endif

   //Point to the network interface
   NetInterface *interface = &netInterface[0];

   //Initialize LCD display
   lcdSetCursor(1, 0);
   printf("IPv4 Addr\r\n");
   lcdSetCursor(2, 0);
   printf("0.0.0.0\r\n");
   lcdSetCursor(4, 0);
   printf("IPv6 Link-Local Addr\r\n");
   lcdSetCursor(5, 0);
   printf("::\r\n");
   lcdSetCursor(7, 0);
   printf("IPv6 Global Addr\r\n");
   lcdSetCursor(8, 0);
   printf("::\r\n");

   //Endless loop
   while(1)
   {
#if (IPV4_SUPPORT == ENABLED)
      //Retrieve IPv4 host address
      ipv4GetHostAddr(interface, &ipv4Addr);

      //Check for any changes
      if(ipv4Addr != ipv4HostAddr)
      {
         //Save IPv4 host address
         ipv4HostAddr = ipv4Addr;

         //Refresh LCD display
         lcdSetCursor(2, 0);
         ipv4GetHostAddr(interface, &ipv4Addr);
         printf("%-16s\r\n", ipv4AddrToString(ipv4Addr, buffer));
      }
#endif

#if (IPV6_SUPPORT == ENABLED)
      //Retrieve IPv6 link-local address
      ipv6GetLinkLocalAddr(interface, &ipv6Addr);

      //Check for any changes
      if(!ipv6CompAddr(&ipv6Addr, &ipv6LinkLocalAddr))
      {
         //Save IPv6 link-local address
         ipv6LinkLocalAddr = ipv6Addr;

         //Refresh LCD display
         lcdSetCursor(5, 0);
         ipv6GetLinkLocalAddr(interface, &ipv6Addr);
         printf("%-40s\r\n", ipv6AddrToString(&ipv6Addr, buffer));
      }

      //Retrieve IPv6 global address
      ipv6GetGlobalAddr(interface, 0, &ipv6Addr);

      //Check for any changes
      if(!ipv6CompAddr(&ipv6Addr, &ipv6GlobalAddr))
      {
         //Save IPv6 global address
         ipv6GlobalAddr = ipv6Addr;

         //Refresh LCD display
         lcdSetCursor(8, 0);
         ipv6GetGlobalAddr(interface, 0, &ipv6Addr);
         printf("%-40s\r\n", ipv6AddrToString(&ipv6Addr, buffer));
      }
#endif

      //Start A/D conversion
      HAL_ADC_Start(&ADC_Handle);
      //Wait until conversion completion
      HAL_ADC_PollForConversion(&ADC_Handle, 10);

      //Check whether the conversion is complete
      if(HAL_ADC_GetState(&ADC_Handle) & HAL_ADC_STATE_EOC_REG)
      {
         //Get conversion result
         adcValue = HAL_ADC_GetValue(&ADC_Handle);
      }

      //Loop delay
      osDelayTask(100);
   }
}


/**
 * @brief LED task
 * @param[in] param Unused parameter
 **/

void ledTask(void *param)
{
   //Endless loop
   while(1)
   {
      BSP_LED_On(LED1);
      osDelayTask(100);
      BSP_LED_Off(LED1);
      osDelayTask(900);
   }
}


/**
 * @brief Main entry point
 * @return Unused value
 **/

int_t main(void)
{
   error_t error;
   OsTaskId taskId;
   OsTaskParameters taskParams;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //HAL library initialization
   HAL_Init();
   //Configure the system clock
   SystemClock_Config();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneTCP MQTT Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2025 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32F407\r\n");
   TRACE_INFO("\r\n");

   //LED configuration
   BSP_LED_Init(LED1);
   BSP_LED_Init(LED2);
   BSP_LED_Init(LED3);
   BSP_LED_Init(LED4);

   //Clear LEDs
   BSP_LED_Off(LED1);
   BSP_LED_Off(LED2);
   BSP_LED_Off(LED3);
   BSP_LED_Off(LED4);

   //Initialize user button
   BSP_PB_Init(BUTTON_KEY, BUTTON_MODE_GPIO);
   //Initialize joystick
   BSP_JOY_Init(JOY_MODE_GPIO);

   //Initialize LCD display
   BSP_LCD_Init();
   BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
   BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
   BSP_LCD_SetFont(&Font24);
   BSP_LCD_DisplayOn();

   //Clear LCD display
   BSP_LCD_Clear(LCD_COLOR_BLUE);

   //Welcome message
   lcdSetCursor(0, 0);
   printf("MQTT Client Demo\r\n");

   //ADC3 initialization
   adc3Init();

   //Initialize hardware cryptographic accelerator
   error = stm32f4xxCryptoInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize hardware crypto accelerator!\r\n");
   }

   //Generate a random seed
   error = trngGetRandomData(seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to generate random data!\r\n");
   }

   //PRNG initialization
   error = hmacDrbgInit(&hmacDrbgContext, SHA256_HASH_ALGO);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize PRNG!\r\n");
   }

   //Properly seed the PRNG
   error = hmacDrbgSeed(&hmacDrbgContext, seed, sizeof(seed));
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to seed PRNG!\r\n");
   }

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure the first Ethernet interface
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF_NAME);
   //Set host name
   netSetHostname(interface, APP_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &stm32f4xxEthDriver);
   netSetPhyDriver(interface, &dp83848PhyDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext, &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext, &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

   //Set default router
   ipv6StringToAddr(APP_IPV6_ROUTER, &ipv6Addr);
   ipv6SetDefaultRouter(interface, 0, &ipv6Addr);

   //Set primary and secondary DNS servers
   ipv6StringToAddr(APP_IPV6_PRIMARY_DNS, &ipv6Addr);
   ipv6SetDnsServer(interface, 0, &ipv6Addr);
   ipv6StringToAddr(APP_IPV6_SECONDARY_DNS, &ipv6Addr);
   ipv6SetDnsServer(interface, 1, &ipv6Addr);
#endif
#endif

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create user task
   taskId = osCreateTask("User", userTask, NULL, &taskParams);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 750;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create MQTT test task
   taskId = osCreateTask("MQTT", mqttTestTask, NULL, &taskParams);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 200;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create a task to blink the LED
   taskId = osCreateTask("LED", ledTask, NULL, &taskParams);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Start the execution of tasks
   osStartKernel();

   //This function should never return
   return 0;
}
