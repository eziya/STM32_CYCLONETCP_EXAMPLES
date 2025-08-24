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
#include "web_socket/web_socket.h"
#include "hardware/stm32f4xx/stm32f4xx_crypto.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "websocket-client-demo"
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

//Application configuration
#define APP_WS_SERVER_NAME "socketsbay.com"
#define APP_WS_SERVER_PORT 443
#define APP_WS_SERVER_URI "/wss/v2/1/demo/"

#define APP_SET_CIPHER_SUITES DISABLED
#define APP_SET_SERVER_NAME DISABLED
#define APP_SET_TRUSTED_CA_LIST DISABLED

//Global variables
uint_t lcdLine = 0;
uint_t lcdColumn = 0;

OsEvent appEvent;
bool_t buttonEventFlag;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
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
 * @brief Random data generation callback function
 * @param[out] data Buffer where to store the random data
 * @param[in] length Number of bytes that are required
 * @return Error code
 **/

error_t webSocketClientRngCallback(uint8_t *data, size_t length)
{
   error_t error;

   //Generate some random data
   error = hmacDrbgGenerate(&hmacDrbgContext, data, length);
   //Return status code
   return error;
}


/**
 * @brief TLS initialization callback
 * @param[in] webSocket Handle referencing a WebSocket
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t webSocketClientTlsInitCallback(WebSocket *webSocket,
   TlsContext *tlsContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("WebSocket: TLS initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
   //Any error to report?
   if(error)
      return error;

#if (APP_SET_CIPHER_SUITES == ENABLED)
   //Preferred cipher suite list
   error = tlsSetCipherSuites(tlsContext, cipherSuites, arraysize(cipherSuites));
   //Any error to report?
   if(error)
      return error;
#endif

#if (APP_SET_SERVER_NAME == ENABLED)
   //Set the fully qualified domain name of the server
   error = tlsSetServerName(tlsContext, APP_WS_SERVER_NAME);
   //Any error to report?
   if(error)
      return error;
#endif

#if (APP_SET_TRUSTED_CA_LIST == ENABLED)
   //Import the list of trusted CA certificates
   error = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList));
   //Any error to report?
   if(error)
      return error;
#endif

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief WebSocket client test routine
 * @return Error code
 **/

error_t webSocketClientTest(void)
{
   error_t error;
   size_t length;
   systime_t timestamp;
   systime_t currentTime;
   WebSocket *webSocket;
   WebSocketFrameType type;
   IpAddr serverIpAddr;
   SocketEventDesc eventDesc[1];
   char_t buffer[256];

   //Debug message
   TRACE_INFO("\r\n\r\nWebSocket: Resolving server name...\r\n");

   //Resolve server name
   error = getHostByName(NULL, APP_WS_SERVER_NAME, &serverIpAddr, 0);

   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_INFO("WebSocket: Failed to resolve server name!\r\n");
      //Exit immediately
      return error;
   }

   //Open a new WebSocket
   webSocket = webSocketOpen();
   //Failed to open WebSocket?
   if(webSocket == NULL)
      return ERROR_OPEN_FAILED;

   //Start of exception handling block
   do
   {
      //Set timeout value for blocking operations
      error = webSocketSetTimeout(webSocket, 30000);
      //Any error to report?
      if(error)
         break;

      //Set the hostname of the remote server
      error = webSocketSetHost(webSocket, APP_WS_SERVER_NAME);
      //Any error to report?
      if(error)
         break;

#if (APP_WS_SERVER_PORT == 443)
      //Register TLS initialization callback
      error = webSocketRegisterTlsInitCallback(webSocket,
         webSocketClientTlsInitCallback);
      //Any error to report?
      if(error)
         return error;
#endif

      //Debug message
      TRACE_INFO("\r\nWebSocket: Connecting to server...\r\n");

      //Establish the WebSocket connection
      error = webSocketConnect(webSocket, &serverIpAddr,
         APP_WS_SERVER_PORT, APP_WS_SERVER_URI);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("WebSocket: Connected to server\r\n");

      //Format message
      length = sprintf(buffer, "Hello World!");

      //Debug message
      TRACE_INFO("WebSocket: Sending message (%" PRIuSIZE " bytes)...\r\n", length);
      TRACE_INFO("  %s\r\n", buffer);

      //Send data to the WebSocket server
      error = webSocketSend(webSocket, buffer, length,
         WS_FRAME_TYPE_TEXT, NULL);
      //Any error to report?
      if(error)
         break;

      //Save current time
      timestamp = osGetSystemTime();

      //Process events
      while(1)
      {
         //Set the events the application is interested in
         eventDesc[0].socket = webSocket->socket;
         eventDesc[0].eventMask = SOCKET_EVENT_RX_READY;

         //Check whether application data are pending in the receive buffer
         if(webSocketIsRxReady(webSocket))
         {
            //No need to poll the underlying socket for incoming traffic...
            eventDesc[0].eventFlags = SOCKET_EVENT_RX_READY;
            error = NO_ERROR;
         }
         else
         {
            //Wait for incoming traffic from the remote host. A non-infinite timeout is provided
            //to manage the idle timeout (60s). refer to the end of the loop
            error = socketPoll(eventDesc, arraysize(eventDesc), &appEvent, 1000);
         }

         //Check status code
         if(error == NO_ERROR || error == ERROR_WAIT_CANCELED)
         {
            if(eventDesc[0].eventFlags & SOCKET_EVENT_RX_READY)
            {
               //Receive data from the remote WebSocket server
               error = webSocketReceive(webSocket, buffer,
                  sizeof(buffer) - 1, &type, &length);
               //Any error to report?
               if(error)
                  break;

               //Check the type of received data
               if(type == WS_FRAME_TYPE_TEXT ||
                  type == WS_FRAME_TYPE_BINARY)
               {
                  //Properly terminate the string with a NULL character
                  buffer[length] = '\0';

                  //Debug message
                  TRACE_INFO("WebSocket: Message received (%" PRIuSIZE " bytes)...\r\n", length);
                  TRACE_INFO("  %s\r\n", buffer);
               }
               else if(type == WS_FRAME_TYPE_PING)
               {
                  //Debug message
                  TRACE_INFO("WebSocket: Ping message received (%" PRIuSIZE " bytes)...\r\n", length);
                  //Debug message
                  TRACE_INFO("WebSocket: Sending pong message (%" PRIuSIZE " bytes)...\r\n", length);

                  //Send a Pong frame in response
                  error = webSocketSend(webSocket, buffer, length,
                     WS_FRAME_TYPE_PONG, NULL);
                  //Any error to report?
                  if(error)
                     break;
               }

               //Save current time
               timestamp = osGetSystemTime();
            }
         }

         //Check user button state
         if(buttonEventFlag)
         {
            //Clear flag
            buttonEventFlag = FALSE;

            //Format event message
            length = sprintf(buffer, "User button pressed!");

            //Debug message
            TRACE_INFO("WebSocket: Sending message (%" PRIuSIZE " bytes)...\r\n", length);
            TRACE_INFO("  %s\r\n", buffer);

            //Send a message to the WebSocket server
            error = webSocketSend(webSocket, buffer, length,
               WS_FRAME_TYPE_TEXT, NULL);
            //Any error to report?
            if(error)
               break;

            //Save current time
            timestamp = osGetSystemTime();
         }

         //Get current time
         currentTime = osGetSystemTime();

         //Manage idle timeout (if applicable)
         if(timeCompare(currentTime, timestamp + 60000) >= 0)
         {
            //Close WebSocket connection
            error = NO_ERROR;
            break;
         }
      }

      //Properly close the WebSocket connection
      webSocketShutdown(webSocket);

      //End of exception handling block
   } while(0);

   //Release the WebSocket
   webSocketClose(webSocket);

   //Return error code
   return error;
}


/**
 * @brief User task
 * @param[in] param Unused parameter
 **/

void userTask(void *param)
{
   //Endless loop
   while(1)
   {
      //Wait for the user button to be pressed
      osWaitForEvent(&appEvent, INFINITE_DELAY);

      //Clear flag
      buttonEventFlag = FALSE;

      //WebSocket client test routine
      webSocketClientTest();
   }
}


/**
 * @brief Button task
 **/

void buttonTask(void *param)
{
   bool_t state = FALSE;
   bool_t prevState = FALSE;

   //Endless loop
   while(1)
   {
      //Retrieve user button state
      state = BSP_PB_GetState(BUTTON_KEY);

      //User button pressed?
      if(state && !prevState)
      {
         //Notify the WebSocket task of the event
         buttonEventFlag = TRUE;
         osSetEvent(&appEvent);
      }

      //Save current state
      prevState = state;

      //Loop delay
      osDelayTask(100);
   }
}


/**
 * @brief LCD display task
 * @param[in] param Unused parameter
 **/

void lcdTask(void *param)
{
   char_t buffer[40];
#if (IPV4_SUPPORT == ENABLED)
   Ipv4Addr ipv4Addr;
#endif

   //Point to the network interface
   NetInterface *interface = &netInterface[0];

   //Initialize LCD display
   lcdSetCursor(3, 0);
   printf("IPv4 Addr\r\n");
   lcdSetCursor(6, 0);
   printf("Press user button\r\nto run test\r\n");

   //Endless loop
   while(1)
   {
#if (IPV4_SUPPORT == ENABLED)
      //Display IPv4 host address
      lcdSetCursor(4, 0);
      ipv4GetHostAddr(interface, &ipv4Addr);
      printf("%-16s\r\n", ipv4AddrToString(ipv4Addr, buffer));
#endif

      //Loop delay
      osDelayTask(500);
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
   TRACE_INFO("****************************************\r\n");
   TRACE_INFO("*** CycloneTCP WebSocket Client Demo ***\r\n");
   TRACE_INFO("****************************************\r\n");
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
   printf("WebSocket Client\r\nDemo\r\n");

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

   //Register RNG callback
   webSocketRegisterRandCallback(webSocketClientRngCallback);

   //Create an event object
   if(!osCreateEvent(&appEvent))
   {
      //Debug message
      TRACE_ERROR("Failed to create event!\r\n");
   }

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
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create a task to manage button events
   taskId = osCreateTask("Button", buttonTask, NULL, &taskParams);
   //Failed to create the task?
   if(taskId == OS_INVALID_TASK_ID)
   {
      //Debug message
      TRACE_ERROR("Failed to create task!\r\n");
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create a task to manage the LCD display
   taskId = osCreateTask("LCD", lcdTask, NULL, &taskParams);
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
