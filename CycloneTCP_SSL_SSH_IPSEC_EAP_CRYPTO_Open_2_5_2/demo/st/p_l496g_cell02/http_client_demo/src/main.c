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
#include "stm32l4xx.h"
#include "stm32l4xx_hal.h"
#include "stm32l496g_discovery.h"
#include "core/net.h"
#include "ppp/ppp.h"
#include "http/http_client.h"
#include "modem.h"
#include "uart_driver.h"
#include "debug.h"

//PPP interface configuration
#define APP_IF_NAME "ppp0"

//Application configuration
#define APP_HTTP_SERVER_NAME "www.httpbin.org"
#define APP_HTTP_SERVER_PORT 80
#define APP_HTTP_URI "/anything"

//Global variables
PppSettings pppSettings;
PppContext pppContext;
HttpClientContext httpClientContext;


/**
 * @brief System clock configuration
 **/

void SystemClock_Config(void)
{
   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
   RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct = {0};

   //MSI is enabled after System reset, activate PLL with MSI as source
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
   RCC_OscInitStruct.MSIState = RCC_MSI_ON;
   RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
   RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
   RCC_OscInitStruct.PLL.PLLM = 1;
   RCC_OscInitStruct.PLL.PLLN = 40;
   RCC_OscInitStruct.PLL.PLLR = 2;
   RCC_OscInitStruct.PLL.PLLP = 7;
   RCC_OscInitStruct.PLL.PLLQ = 4;
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2
   //clocks dividers
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);

   //Select clock source for RNG peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG;
   RCC_PeriphClkInitStruct.RngClockSelection = RCC_RNGCLKSOURCE_MSI;
   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);
}


/**
 * @brief HTTP client test routine
 * @return Error code
 **/

error_t httpClientTest(void)
{
   error_t error;
   size_t length;
   uint_t status;
   const char_t *value;
   IpAddr ipAddr;
   char_t buffer[128];

   //Initialize HTTP client context
   httpClientInit(&httpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve HTTP server name
      error = getHostByName(NULL, APP_HTTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

      //Select HTTP protocol version
      error = httpClientSetVersion(&httpClientContext, HTTP_VERSION_1_1);
      //Any error to report?
      if(error)
         break;

      //Set timeout value for blocking operations
      error = httpClientSetTimeout(&httpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to HTTP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Connect to the HTTP server
      error = httpClientConnect(&httpClientContext, &ipAddr,
         APP_HTTP_SERVER_PORT);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to HTTP server!\r\n");
         break;
      }

      //Create an HTTP request
      httpClientCreateRequest(&httpClientContext);
      httpClientSetMethod(&httpClientContext, "POST");
      httpClientSetUri(&httpClientContext, APP_HTTP_URI);

      //Set query string
      httpClientAddQueryParam(&httpClientContext, "param1", "value1");
      httpClientAddQueryParam(&httpClientContext, "param2", "value2");

      //Add HTTP header fields
      httpClientAddHeaderField(&httpClientContext, "Host", APP_HTTP_SERVER_NAME);
      httpClientAddHeaderField(&httpClientContext, "User-Agent", "Mozilla/5.0");
      httpClientAddHeaderField(&httpClientContext, "Content-Type", "text/plain");
      httpClientAddHeaderField(&httpClientContext, "Transfer-Encoding", "chunked");

      //Send HTTP request header
      error = httpClientWriteHeader(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to write HTTP request header!\r\n");
         break;
      }

      //Send HTTP request body
      error = httpClientWriteBody(&httpClientContext, "Hello World!", 12,
         NULL, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to write HTTP request body!\r\n");
         break;
      }

      //Receive HTTP response header
      error = httpClientReadHeader(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to read HTTP response header!\r\n");
         break;
      }

      //Retrieve HTTP status code
      status = httpClientGetStatus(&httpClientContext);
      //Debug message
      TRACE_INFO("HTTP status code: %u\r\n", status);

      //Retrieve the value of the Content-Type header field
      value = httpClientGetHeaderField(&httpClientContext, "Content-Type");

      //Header field found?
      if(value != NULL)
      {
         //Debug message
         TRACE_INFO("Content-Type header field value: %s\r\n", value);
      }
      else
      {
         //Debug message
         TRACE_INFO("Content-Type header field not found!\r\n");
      }

      //Receive HTTP response body
      while(!error)
      {
         //Read data
         error = httpClientReadBody(&httpClientContext, buffer,
            sizeof(buffer) - 1, &length, 0);

         //Check status code
         if(!error)
         {
            //Properly terminate the string with a NULL character
            buffer[length] = '\0';
            //Dump HTTP response body
            TRACE_INFO("%s", buffer);
         }
      }

      //Terminate the HTTP response body with a CRLF
      TRACE_INFO("\r\n");

      //Any error to report?
      if(error != ERROR_END_OF_STREAM)
         break;

      //Close HTTP response body
      error = httpClientCloseBody(&httpClientContext);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to read HTTP response trailer!\r\n");
         break;
      }

      //Gracefully disconnect from the HTTP server
      httpClientDisconnect(&httpClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release HTTP client context
   httpClientDeinit(&httpClientContext);

   //Return status code
   return error;
}


/**
 * @brief PPP test task
 **/

void pppTestTask(void *param)
{
   error_t error;
   bool_t initialized;
   NetInterface *interface;

   //The modem is not yet initialized
   initialized = FALSE;

   //Point to the PPP network interface
   interface = &netInterface[0];

   //Endless loop
   while(1)
   {
      //Joystick pressed?
      if(BSP_JOY_GetState() != JOY_NONE)
      {
         //Modem initialization is performed only once
         if(!initialized)
         {
            //Modem initialization
            error = modemInit(interface);

            //Check status code
            if(error)
            {
               //Debug message
               TRACE_WARNING("Modem initialization failed!\r\n");
            }
            else
            {
               //Successful initialization
               initialized = TRUE;
            }
         }
         else
         {
            //Modem is already initialized
            error = NO_ERROR;
         }

         //Check status code
         if(!error)
         {
            //Establish PPP connection
            error = modemConnect(interface);

            //Check status code
            if(error)
            {
               //Debug message
               TRACE_WARNING("Failed to established PPP connection!\r\n");
            }
            else
            {
               //HTTP client test routine
               httpClientTest();
               //Close PPP connetion
               modemDisconnect(interface);
            }
         }

         //Wait for the joystick to be released
         while(BSP_JOY_GetState() != JOY_NONE);
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
   TRACE_INFO("*** CycloneTCP HTTP Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2025 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32L496\r\n");
   TRACE_INFO("\r\n");

   //LED configuration
   BSP_LED_Init(LED1);
   BSP_LED_Init(LED2);

   //Clear LEDs
   BSP_LED_Off(LED1);
   BSP_LED_Off(LED2);

   //Initialize joystick
   BSP_JOY_Init(JOY_MODE_GPIO);

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure the first network interface
   interface = &netInterface[0];

   //Get default PPP settings
   pppGetDefaultSettings(&pppSettings);
   //Select the underlying interface
   pppSettings.interface = interface;
   //Default async control character map
   pppSettings.accm = 0x00000000;
   //Allowed authentication protocols
   pppSettings.authProtocol = PPP_AUTH_PROTOCOL_PAP | PPP_AUTH_PROTOCOL_CHAP_MD5;

   //Initialize PPP
   error = pppInit(&pppContext, &pppSettings);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize PPP!\r\n");
   }

   //Set interface name
   netSetInterfaceName(interface, APP_IF_NAME);
   //Select the relevant UART driver
   netSetUartDriver(interface, &uartDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create user task
   taskId = osCreateTask("PPP", pppTestTask, NULL, &taskParams);
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
