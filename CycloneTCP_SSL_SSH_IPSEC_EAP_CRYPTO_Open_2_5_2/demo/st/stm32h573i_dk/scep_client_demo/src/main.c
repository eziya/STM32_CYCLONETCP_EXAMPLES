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
#include "stm32h5xx.h"
#include "stm32h5xx_hal.h"
#include "stm32h573i_discovery.h"
#include "stm32h573i_discovery_lcd.h"
#include "stm32_lcd.h"
#include "core/net.h"
#include "drivers/mac/stm32h5xx_eth_driver.h"
#include "drivers/phy/lan8742_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "hardware/stm32h5xx/stm32h5xx_crypto.h"
#include "scep/scep_client.h"
#include "pkix/x509_csr_create.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "scep-client-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-05-73"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::573"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::573"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SCEP_SERVER_NAME "interop.redwax.eu"
#define APP_SCEP_SERVER_PORT 80
#define APP_SCEP_URI "/test/simple/scep"

//Global variables
uint_t lcdLine = 0;
uint_t lcdColumn = 0;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
ScepClientContext scepClientContext;
HmacDrbgContext hmacDrbgContext;
uint8_t seed[48];
char_t clientCert[2048];
size_t clientCertLen;

//Client's public key
const char_t clientPublicKey[] =
   "-----BEGIN RSA PUBLIC KEY-----"
   "MIIBCgKCAQEA5qQrMvtQltl9zoyk72FyHPziiiYT4AkDv/8kuO9yGQkIo+zUTDtu"
   "6Aa3Ki6HAWe4Xw2r6bl/wl77BvIKlRUBvjCGeAM7t7eZTEB8CxfLVweDb5l6aFHM"
   "wY7Cu69+8sqi7PgNmRnZ1vo8pagSO/6wXwqxreqODLAkeq4D8vitLSBBB+JLKb9b"
   "Tf3wwFN2HPeLr/3xltmj6PWtQbu9WvHo2D8hX1g5mKOz5QFJb8C14Hm58ikpBDBE"
   "J8fgGz/NPmwmmKYdWbWPYniiKMm8o/xH5Ip6FFKAQ5Mi18kGGLbVRKD3R8wR+Z2a"
   "TkpMmznp8j8xBIxg9QxCTYioRghLP6gkNwIDAQAB"
   "-----END RSA PUBLIC KEY-----";

//Client's private key
const char_t clientPrivateKey[] =
   "-----BEGIN RSA PRIVATE KEY-----"
   "MIIEowIBAAKCAQEA5qQrMvtQltl9zoyk72FyHPziiiYT4AkDv/8kuO9yGQkIo+zU"
   "TDtu6Aa3Ki6HAWe4Xw2r6bl/wl77BvIKlRUBvjCGeAM7t7eZTEB8CxfLVweDb5l6"
   "aFHMwY7Cu69+8sqi7PgNmRnZ1vo8pagSO/6wXwqxreqODLAkeq4D8vitLSBBB+JL"
   "Kb9bTf3wwFN2HPeLr/3xltmj6PWtQbu9WvHo2D8hX1g5mKOz5QFJb8C14Hm58ikp"
   "BDBEJ8fgGz/NPmwmmKYdWbWPYniiKMm8o/xH5Ip6FFKAQ5Mi18kGGLbVRKD3R8wR"
   "+Z2aTkpMmznp8j8xBIxg9QxCTYioRghLP6gkNwIDAQABAoIBABaTdUMNRIsviNgB"
   "/lcMM85QlqAtL/7bAwn1IJQVpBZ9QuJA2VsI6kc9+Qng+ggSLgLn5K8BIFdXUr0Q"
   "TibfoocKWu8+accG6rODEGFJl/bR3nS7EjdJ4oADyF30xLlhSmdltHcLB766Sdtx"
   "Qy+qM3tqIZBDiFoHl9qGVA6hdtoWwZATxphFt+6NqHqhOQFWo7i9u0Ds6sUBbloa"
   "+RNl8+4knwOmmJbq55AF/8wx8iPlNXNqZsQylUFswf/5warU7G+MyeBbmhN3cRTg"
   "h6sg66guKIft6R5GoEHvEK9+plQvxnNiy1oWrpykNO8pCDXU1YRkOFlTqoujll4v"
   "nRBf/QkCgYEA+eLL9XLdOoG2Z9AC47aCFLFJSkUV4hY1m+X19KGHBbuTgx6s2RzW"
   "rMUUHa2phHVHjuwlPK5C1uSOZpyr5GukkKY0eyOtwB2ekrp29ewmZ++owgh8etbw"
   "CqD/PLkvTA2yP+a82NLNVsvZLGz0S34ASIeWCLKNh1+41edbexi9bD0CgYEA7EjU"
   "dlsgNuUyivZkdbmZI4kLF1m9OYF+IMfn+girrqGTqwMHjR5R+h46W3BK5gB43laX"
   "plDYavzUNwVaBPlOQmdmmjlS2zz4NSt0opOTrbXWPMWLCPf19YNQ4pySrUvrTIDQ"
   "s0UkHoDaVgoypgqw/KHEO4uQLKZ0KASllH4H1YMCgYEAlQMKz1Zs2FvLk0J2xqXq"
   "Ej7aTqC9+PF3jHzoW7YLF38Q6yratim9Vo+7fCs4IFXzkyX82p+sGgt3Y3dgBbmv"
   "C9chCqFvFlZTXno1QFdPW8GNqA95c6NCx4PUULi5nKe6OOL2kHG8o1qyKgza7T25"
   "G4dHD+6x+R060svBQLmzE50CgYB7VQiRPr9x5/CZ2EJXsKjeg4nmhlDe01iig7Xy"
   "LNRwMqaBfPNUFZ90jpKnZ9WweE6ev1Qo28obDh03GvQB5J+UyaQknAdDqG9mUWhv"
   "89gBtAg/cF1CMSuRGxn9Lvzgt9/57sMAz/YqddeBUZFeWfZH56gl7JM0uy2mNca3"
   "25D7QQKBgC0aWNlpX58G2hLq/sf9D3PCo8NBvUgWA+lHi5eKoChp11+1J5BHYg75"
   "paC1LR44DIaKheIwI1ltZwHeMKm9+BTSuK7Keb+1FtIsfYZTdcBkcYhsRYyYNJ+t"
   "baYP7GQXt+bBZrZzwvDeqQUh3andMM8hpDFA10HHbmbyDypiBNU8"
   "-----END RSA PRIVATE KEY-----";

//SCEP CA certificate footprint
const uint8_t caCertFingerprint[SHA256_DIGEST_SIZE] =
{
   0xD5, 0x06, 0xB6, 0xFB, 0xD0, 0xCB, 0x08, 0x2F, 0x06, 0x1F, 0x26, 0xC7, 0x53, 0xF2, 0xD7, 0xDA,
   0x6E, 0x66, 0x4F, 0x4A, 0x62, 0xF1, 0xF7, 0xD7, 0xBE, 0x5A, 0x22, 0x06, 0xD3, 0xAF, 0xD9, 0xF3
};


/**
 * @brief Set cursor location
 * @param[in] line Line number
 * @param[in] column Column number
 **/

void lcdSetCursor(uint_t line, uint_t column)
{
   lcdLine = MIN(line, 12);
   lcdColumn = MIN(column, 18);
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
   else if(lcdLine < 12 && lcdColumn < 18)
   {
      //Display current character
      UTIL_LCD_DisplayChar(lcdColumn * 13 + 4, lcdLine * 20 + 2, c);

      //Advance the cursor position
      if(++lcdColumn >= 18)
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
   RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct = {0};
   RCC_CRSInitTypeDef RCC_CRSInitStruct = {0};

   //Configure the main internal regulator output voltage
   __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

   //Wait for the voltage scaling ready flag to be set
   while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY))
   {
   }

   //Configure PLL with HSE as source
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_HSI48;
   RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS_DIGITAL;
   RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLL1_SOURCE_HSE;
   RCC_OscInitStruct.PLL.PLLM = 5;
   RCC_OscInitStruct.PLL.PLLN = 100;
   RCC_OscInitStruct.PLL.PLLP = 2;
   RCC_OscInitStruct.PLL.PLLQ = 2;
   RCC_OscInitStruct.PLL.PLLR = 2;
   RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1_VCIRANGE_2;
   RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1_VCORANGE_WIDE;
   RCC_OscInitStruct.PLL.PLLFRACN = 0;
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Select PLL as system clock source and configure bus clocks dividers
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK3;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
   RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;
   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

   //Select clock source for RNG peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG;
   RCC_PeriphClkInitStruct.RngClockSelection = RCC_RNGCLKSOURCE_HSI48;
   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);

   //Configure CRS
   RCC_CRSInitStruct.Prescaler = RCC_CRS_SYNC_DIV1;
   RCC_CRSInitStruct.Source = RCC_CRS_SYNC_SOURCE_USB;
   RCC_CRSInitStruct.Polarity = RCC_CRS_SYNC_POLARITY_RISING;
   RCC_CRSInitStruct.ReloadValue = __HAL_RCC_CRS_RELOADVALUE_CALCULATE(48000000, 1000);
   RCC_CRSInitStruct.ErrorLimitValue = 34;
   RCC_CRSInitStruct.HSI48CalibrationValue = 32;
   HAL_RCCEx_CRSConfig(&RCC_CRSInitStruct);

   //Enable CRS clock
   __HAL_RCC_CRS_CLK_ENABLE();
}


/**
 * @brief CA certificate verification callback
 * @param[in] context Pointer to the SCEP client context
 * @param[in] certInfo Pointer to the CA certificate to be verified
 * @return Error code
 **/

error_t scepClientCaCertVerifyCallback(ScepClientContext *context,
   const X509CertInfo *certInfo)
{
   error_t error;
   uint8_t fingerprint[SHA256_DIGEST_SIZE];

   //Debug message
   TRACE_INFO("SCEP Client: CA certificate verification callback\r\n");

   //The CA certificate fingerprint may be used to authenticate a CA
   //certificate distributed by the GetCACert response. The fingerprint is
   //created by calculating a SHA-256 hash over the whole CA certificate
   //(refer to RFC 8894, section 2.2)
   error = sha256Compute(certInfo->raw.value, certInfo->raw.length,
      fingerprint);

   //Check status code
   if(!error)
   {
      //Check status code
      if(memcmp(fingerprint, caCertFingerprint, SHA256_DIGEST_SIZE) == 0)
      {
         //Debug message
         TRACE_INFO("  Valid fingerprint\r\n");
         //The fingerprint is valid
         error = NO_ERROR;
      }
      else
      {
         //Debug message
         TRACE_INFO("  Invalid fingerprint\r\n");
         //Report an error
         error = ERROR_UNKNOWN_CA;
      }
   }

   //Return status code
   return error;
}


/**
 * @brief CSR generation callback
 * @param[in] context Pointer to the SCEP client context
 * @param[out] buffer Buffer where to store the CSR
 * @param[in] size Size of the buffer, in bytes
 * @param[out] length Actual length of the CSR, in bytes
 * @return Error code
 **/

error_t scepClientCsrGenCallback(ScepClientContext *context,
   uint8_t *buffer, size_t size, size_t *length)
{
   error_t error;
   X509CertRequestInfo *certReqInfo;
   X509SignAlgoId signatureAlgo;

   //Debug message
   TRACE_INFO("SCEP Client: CSR generation callback\r\n");

   //Initialize status code
   error = NO_ERROR;

   //Allocate a memory buffer to hold the certificate request information
   certReqInfo = cryptoAllocMem(sizeof(X509CertRequestInfo));

   //Successful memory allocation?
   if(certReqInfo != NULL)
   {
      //Clear certificate request information
      osMemset(certReqInfo, 0, sizeof(X509CertRequestInfo));

      //The certificate request must contain at least the subject Distinguished
      //Name and the subject public key (refer to RFC 8894, section 3.3.1)
      certReqInfo->subject.commonName.value = APP_HOST_NAME;
      certReqInfo->subject.commonName.length = osStrlen(APP_HOST_NAME);
      certReqInfo->subject.countryName.value = "US";
      certReqInfo->subject.countryName.length = osStrlen("US");
      certReqInfo->subject.organizationName.value = "My Company";
      certReqInfo->subject.organizationName.length = osStrlen("My Company");

      //Set public key identifier
      certReqInfo->subjectPublicKeyInfo.oid.value = RSA_ENCRYPTION_OID;
      certReqInfo->subjectPublicKeyInfo.oid.length = sizeof(RSA_ENCRYPTION_OID);

      //For a PKCSReq, the certificate request must contain a challengePassword
      //attribute if authorisation based on a shared secret is being used
      certReqInfo->attributes.challengePwd.value = "secret";
      certReqInfo->attributes.challengePwd.length = osStrlen("secret");

      //Select the signature algorithm
      signatureAlgo.oid.value = SHA256_WITH_RSA_ENCRYPTION_OID;
      signatureAlgo.oid.length = sizeof(SHA256_WITH_RSA_ENCRYPTION_OID);

      //The CSR is signed by the private key corresponding to the public key
      error = x509CreateCsr(context->prngAlgo, context->prngContext, certReqInfo,
         &context->rsaPublicKey, &signatureAlgo, &context->rsaPrivateKey, buffer,
         length);

      //Release previously allocated memory
      cryptoFreeMem(certReqInfo);
   }
   else
   {
      //Failed to allocate memory
      error = ERROR_OUT_OF_MEMORY;
   }

   //Return status code
   return error;
}


/**
 * @brief SCEP client test routine
 * @return Error code
 **/

error_t scepClientTest(void)
{
   error_t error;
   IpAddr ipAddr;
   ScepFailInfo failInfo;

   //Initialize SCEP client context
   scepClientInit(&scepClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve SCEP server name
      error = getHostByName(NULL, APP_SCEP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

      //Register CA certificate verification callback
      error = scepClientRegisterCaCertVerifyCallback(&scepClientContext,
         scepClientCaCertVerifyCallback);
      //Any error to report?
      if(error)
         break;

      //Register CSR generation callback
      error = scepClientRegisterCsrGenCallback(&scepClientContext,
         scepClientCsrGenCallback);
      //Any error to report?
      if(error)
         break;

      //Set the pseudo-random number generator to be used to generate nonces
      error = scepClientSetPrng(&scepClientContext, HMAC_DRBG_PRNG_ALGO,
         &hmacDrbgContext);
      //Any error to report?
      if(error)
         break;

      //Load public/private key pair
      error = scepClientLoadKeyPair(&scepClientContext, clientPublicKey,
         strlen(clientPublicKey), clientPrivateKey, strlen(clientPrivateKey),
         NULL);
      //Any error to report?
      if(error)
         break;

      //Set the domain name of the SCEP server
      error = scepClientSetHost(&scepClientContext, APP_SCEP_SERVER_NAME);
      //Any error to report?
      if(error)
         break;

      //Set timeout value for blocking operations
      error = scepClientSetTimeout(&scepClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to SCEP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Connect to the SCEP server
      error = scepClientConnect(&scepClientContext, &ipAddr,
         APP_SCEP_SERVER_PORT);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to SCEP server!\r\n");
         break;
      }

      //Set URI
      error = scepClientSetUri(&scepClientContext, APP_SCEP_URI);
      //Any error to report?
      if(error)
         break;

      //Certificate enrollment
      error = scepClientEnroll(&scepClientContext);

      //Check status code
      if(error == NO_ERROR)
      {
         //Request granted
         TRACE_INFO("Request granted\r\n");
      }
      else if(error == ERROR_REQUEST_REJECTED)
      {
         //Retrieve failure reason
         failInfo = scepClientGetFailInfo(&scepClientContext);

         //Debug message
         TRACE_INFO("Request rejected!\r\n");
         TRACE_INFO("  failInfo = %u\r\n", failInfo);
         break;
      }
      else
      {
         //Debug message
         TRACE_INFO("Request failed!\r\n");
         break;
      }

      //Store client's certificate
      error = scepClientStoreCert(&scepClientContext, clientCert,
         &clientCertLen);
      if(error)
         break;

      //Dump client's certificate
      TRACE_INFO("Client's certificate (%" PRIuSIZE " bytes):\r\n%s\r\n",
         clientCertLen, clientCert);

      //Gracefully disconnect from the SCEP server
      scepClientDisconnect(&scepClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release SCEP client context
   scepClientDeinit(&scepClientContext);

   //Return status code
   return error;
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
#endif
#if (IPV6_SUPPORT == ENABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Point to the network interface
   NetInterface *interface = &netInterface[0];

   //Initialize LCD display
   lcdSetCursor(2, 0);
   printf("IPv4 Addr\r\n");
   lcdSetCursor(5, 0);
   printf("IPv6 Link-Local\r\nAddr\r\n");
   lcdSetCursor(9, 0);
   printf("IPv6 Global Addr\r\n");

   //Endless loop
   while(1)
   {
#if (IPV4_SUPPORT == ENABLED)
      //Display IPv4 host address
      lcdSetCursor(3, 0);
      ipv4GetHostAddr(interface, &ipv4Addr);
      printf("%-16s\r\n", ipv4AddrToString(ipv4Addr, buffer));
#endif

#if (IPV6_SUPPORT == ENABLED)
      //Display IPv6 link-local address
      lcdSetCursor(7, 0);
      ipv6GetLinkLocalAddr(interface, &ipv6Addr);
      printf("%-36s\r\n", ipv6AddrToString(&ipv6Addr, buffer));

      //Display IPv6 global address
      lcdSetCursor(10, 0);
      ipv6GetGlobalAddr(interface, 0, &ipv6Addr);
      printf("%-36s\r\n", ipv6AddrToString(&ipv6Addr, buffer));
#endif

      //User button pressed?
      if(BSP_PB_GetState(BUTTON_USER))
      {
         //SCEP client test routine
         scepClientTest();

         //Wait for the user button to be released
         while(BSP_PB_GetState(BUTTON_USER));
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

   //Enable instruction cache
   HAL_ICACHE_ConfigAssociativityMode(ICACHE_2WAYS);
   HAL_ICACHE_Enable();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("*** CycloneTCP SCEP Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2025 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32H573\r\n");
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
   BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

   //Initialize LCD display
   BSP_LCD_Init(0, LCD_ORIENTATION_PORTRAIT);
   UTIL_LCD_SetFuncDriver(&LCD_Driver);
   UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLUE);
   UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
   UTIL_LCD_SetFont(&Font20);
   BSP_LCD_DisplayOn(0);

   //Clear LCD display
   UTIL_LCD_Clear(UTIL_LCD_COLOR_BLUE);

   //Welcome message
   lcdSetCursor(0, 0);
   printf("SCEP Client Demo\r\n");

   //Initialize hardware cryptographic accelerator
   error = stm32h5xxCryptoInit();
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
   netSetDriver(interface, &stm32h5xxEthDriver);
   netSetPhyDriver(interface, &lan8742PhyDriver);

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
   taskParams.stackSize = 1500;
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
