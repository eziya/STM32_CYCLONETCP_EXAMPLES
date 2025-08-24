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
#include "sftp/sftp_client.h"
#include "ssh/ssh_key_verify.h"
#include "hardware/stm32l4xx/stm32l4xx_crypto.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "modem.h"
#include "uart_driver.h"
#include "debug.h"

//PPP interface configuration
#define APP_IF_NAME "ppp0"

//Application configuration
#define APP_SFTP_SERVER_NAME "test.rebex.net"
#define APP_SFTP_SERVER_PORT 22
#define APP_SFTP_USERNAME "demo"
#define APP_SFTP_PASSWORD "password"
#define APP_SFTP_FILENAME "readme.txt"

//List of trusted host keys
const char_t *trustedHostKeys[] =
{
   //Rebex 1024-bit RSA host key
   "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAAAgQC+6dRUWPl1iar2X3BT51cD0/Hr"
   "lXd3UTuSctj2bvRwJxKRt7iG8H/b5xUjplsbenEzVDHzlz+PliivDMhHd4kv0gFg"
   "Bj4YrAWyau4MR/2ZIbHzPf+S1ma0u9n6cyv8dsYjvRtHj7iAkHmzhMKJBOgJeMrR"
   "clbqlKAz/fSYUQH18w==",

   //Rebex 2048-bit RSA host key
   "ssh-rsa AAAAB3NzaC1yc2EAAAABJQAAAQEAkRM6RxDdi3uAGogR3nsQMpmt43X4"
   "WnwgMzs8VkwUCqikewxqk4U7EyUSOUeT3CoUNOtywrkNbH83e6/yQgzc3M8i/eDz"
   "YtXaNGcKyLfy3Ci6XOwiLLOx1z2AGvvTXln1RXtve+Tn1RTr1BhXVh2cUYbiuVtT"
   "WqbEgErT20n4GWD4wv7FhkDbLXNi8DX07F9v7+jH67i0kyGm+E3rE+SaCMRo3zXE"
   "6VO+ijcm9HdVxfltQwOYLfuPXM2t5aUSfa96KJcA0I4RCMzA/8Dl9hXGfbWdbD2h"
   "K1ZQ1pLvvpNPPyKKjPZcMpOznprbg+jIlsZMWIHt7mq2OJXSdruhRrGzZw==",

   //Rebex NIST P-256 host key
   "ecdsa-sha2-nistp256 AAAAE2VjZHNhLXNoYTItbmlzdHAyNTYAAAAIbmlzdHAy"
   "NTYAAABBBLZcZopPvkxYERubWeSrWOSHpxJdR14WFVES/Q3hFguTn6L+0EANqYcb"
   "RXhGBUV6SjR7SaxZACXSxOzgCtG4kwc=",

   //Rebex NIST P-384 host key
   "ecdsa-sha2-nistp384 AAAAE2VjZHNhLXNoYTItbmlzdHAzODQAAAAIbmlzdHAz"
   "ODQAAABhBCSvNmFAneBPS/4KQt3HCzXDuX9c5DBgwM2OyQzvdIsD3EHOIS5XDdM8"
   "fQlar6+7AgcjNzjfE7xm1gp+0CxKJZWZqkTacR7Ji8GJhfJBKxhIyV65OBYstU/y"
   "NMtPXwsQRQ==",

   //Rebex NIST P-521 host key
   "ecdsa-sha2-nistp521 AAAAE2VjZHNhLXNoYTItbmlzdHA1MjEAAAAIbmlzdHA1"
   "MjEAAACFBAHR9Z8D+m2XTsRdBgN7cyyxLWzoOaahQ1H6W7ivEVhm/qmx098BYD0c"
   "lQoZWufKTuSDc+5tjPpi68jJpbta5eqgbAGPA8+Ydxln+gcFkEhbmjoiCR2/zNH1"
   "ThzlGtiZPkc8uZDU7+n/6iH41mNdGUPfE2T70qhQbPG9Q/Y2cHT7Eu8rZA==",

   //Rebex Ed25519 host key
   "ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIOdXzF+Jx/wvEBun5fxi8FQK30mi"
   "LZFND0rxkYwNcYlE"
};

//Global variables
PppSettings pppSettings;
PppContext pppContext;
SftpClientContext sftpClientContext;
HmacDrbgContext hmacDrbgContext;
uint8_t seed[48];


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
 * @brief Server's host key verification callback
 * @param[in] connection Pointer to the SSH connection
 * @param[in] hostKey Pointer to the server's host key
 * @param[in] hostKeyLen Length of the host key, in bytes
 * @return Error code
 **/

error_t sftpClientHostKeyVerifyCallback(SshConnection *connection,
   const uint8_t *hostKey, size_t hostKeyLen)
{
   error_t error;
   uint_t i;

   //Debug message
   TRACE_INFO("SFTP Client: Public key verification callback\r\n");

   //Initialize status code
   error = ERROR_INVALID_KEY;

   //Loop through the list of known host keys
   for(i = 0; i < arraysize(trustedHostKeys) && error; i++)
   {
      //Check whether the host key is trusted
      error = sshVerifyHostKey(hostKey, hostKeyLen, trustedHostKeys[i],
         strlen(trustedHostKeys[i]));
   }

   //Return status code
   return error;
}


/**
 * @brief SSH initialization callback
 * @param[in] context Pointer to the SFTP client context
 * @param[in] sshContext Pointer to the SSH context
 * @return Error code
 **/

error_t sftpClientSshInitCallback(SftpClientContext *context,
   SshContext *sshContext)
{
   error_t error;

   //Debug message
   TRACE_INFO("SFTP Client: SSH initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = sshSetPrng(sshContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
   //Any error to report?
   if(error)
      return error;

   //Set the user name to be used for authentication
   error = sshSetUsername(sshContext, APP_SFTP_USERNAME);
   //Any error to report?
   if(error)
      return error;

   //Set the password to be used for authentication
   error = sshSetPassword(sshContext, APP_SFTP_PASSWORD);
   //Any error to report?
   if(error)
      return error;

   //Register host key verification callback function
   error = sshRegisterHostKeyVerifyCallback(sshContext,
      sftpClientHostKeyVerifyCallback);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief SFTP client test routine
 * @return Error code
 **/

error_t sftpClientTest(void)
{
   error_t error;
   size_t n;
   IpAddr ipAddr;
   char_t buffer[128];

   //Initialize SFTP client context
   sftpClientInit(&sftpClientContext);

   //Start of exception handling block
   do
   {
      //Debug message
      TRACE_INFO("\r\n\r\nResolving server name...\r\n");

      //Resolve SFTP server name
      error = getHostByName(NULL, APP_SFTP_SERVER_NAME, &ipAddr, 0);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to resolve server name!\r\n");
         break;
      }

      //Register SSH initialization callback
      error = sftpClientRegisterSshInitCallback(&sftpClientContext,
         sftpClientSshInitCallback);
      //Any error to report?
      if(error)
         break;

      //Set timeout value for blocking operations
      error = sftpClientSetTimeout(&sftpClientContext, 20000);
      //Any error to report?
      if(error)
         break;

      //Debug message
      TRACE_INFO("Connecting to SFTP server %s...\r\n",
         ipAddrToString(&ipAddr, NULL));

      //Connect to the SFTP server
      error = sftpClientConnect(&sftpClientContext, &ipAddr,
         APP_SFTP_SERVER_PORT);
      //Any error to report?
      if(error)
      {
         //Debug message
         TRACE_INFO("Failed to connect to SFTP server!\r\n");
         break;
      }

      //Open the specified file for reading
      error = sftpClientOpenFile(&sftpClientContext, APP_SFTP_FILENAME,
         SSH_FXF_READ);
      //Any error to report?
      if(error)
         break;

      //Read the contents of the file
      while(!error)
      {
         //Read data
         error = sftpClientReadFile(&sftpClientContext, buffer,
            sizeof(buffer) - 1, &n, 0);

         //Check status code
         if(!error)
         {
            //Properly terminate the string with a NULL character
            buffer[n] = '\0';
            //Dump the contents of the file
            TRACE_INFO("%s", buffer);
         }
      }

      //Terminate the string with a line feed
      TRACE_INFO("\r\n");

      //Any error to report?
      if(error != ERROR_END_OF_STREAM)
         break;

      //Close file
      error = sftpClientCloseFile(&sftpClientContext);
      //Any error to report?
      if(error)
         break;

      //Gracefully disconnect from the SFTP server
      sftpClientDisconnect(&sftpClientContext);

      //Debug message
      TRACE_INFO("Connection closed\r\n");

      //End of exception handling block
   } while(0);

   //Release SFTP client context
   sftpClientDeinit(&sftpClientContext);

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
               //SFTP client test routine
               sftpClientTest();
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
   TRACE_INFO("*** CycloneSSH SFTP Client Demo ***\r\n");
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

   //Initialize hardware cryptographic accelerator
   error = stm32l4xxCryptoInit();
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
