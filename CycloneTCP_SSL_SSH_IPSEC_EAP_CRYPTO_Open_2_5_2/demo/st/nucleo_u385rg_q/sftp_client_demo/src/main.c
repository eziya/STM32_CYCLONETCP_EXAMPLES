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
#include "stm32u3xx.h"
#include "stm32u3xx_hal.h"
#include "stm32u3xx_nucleo.h"
#include "core/net.h"
#include "drivers/eth/w3150a_driver.h"
#include "drivers/eth/w5100_driver.h"
#include "drivers/eth/w5100s_driver.h"
#include "drivers/eth/w5200_driver.h"
#include "drivers/eth/w5500_driver.h"
#include "drivers/eth/w6100_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "sftp/sftp_client.h"
#include "ssh/ssh_key_verify.h"
#include "hardware/stm32u3xx/stm32u3xx_crypto.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "spi_driver.h"
#include "ext_int_driver.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "sftp-client-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-03-85"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::385"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::385"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

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
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
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

   //Enable Power Control clock
   __HAL_RCC_PWR_CLK_ENABLE();

   //Enable EPOD Booster
   HAL_RCCEx_EpodBoosterClkConfig(RCC_EPODBOOSTER_SOURCE_MSIS, RCC_EPODBOOSTER_DIV1);
   HAL_PWREx_EnableEpodBooster();

   //Configure the main internal regulator output voltage
   HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

   //Set Flash latency before increasing MSIS
   __HAL_FLASH_SET_LATENCY(FLASH_LATENCY_2);

   //Enable HSI and MSI oscillators and activate PLL with MSI as source
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48 | RCC_OSCILLATORTYPE_MSIS;
   RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
   RCC_OscInitStruct.MSISState = RCC_MSI_ON;
   RCC_OscInitStruct.MSISSource = RCC_MSI_RC0;
   RCC_OscInitStruct.MSISDiv = RCC_MSI_DIV1;
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Select system clock source and configure bus clocks dividers
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_PCLK3;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSIS;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
   RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;
   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);

   //Select clock source for RNG peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG;
   RCC_PeriphClkInitStruct.RngClockSelection = RCC_RNGCLKSOURCE_HSI48;
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
 * @brief User task
 * @param[in] param Unused parameter
 **/

void userTask(void *param)
{
   //Endless loop
   while(1)
   {
      //User button pressed?
      if(BSP_PB_GetState(BUTTON_USER))
      {
         //SFTP client test routine
         sftpClientTest();

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
      BSP_LED_On(LD2);
      osDelayTask(100);
      BSP_LED_Off(LD2);
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
   TRACE_INFO("*** CycloneSSH SFTP Client Demo ***\r\n");
   TRACE_INFO("***********************************\r\n");
   TRACE_INFO("Copyright: 2010-2025 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32U385\r\n");
   TRACE_INFO("\r\n");

   //LED configuration
   BSP_LED_Init(LD2);
   BSP_LED_Off(LD2);

   //Initialize user button
   BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

   //Initialize hardware cryptographic accelerator
   error = stm32u3xxCryptoInit();
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

#if defined(USE_W3150A)
   //Select the relevant network adapter
   netSetDriver(interface, &w3150aDriver);
#elif defined(USE_W5100)
   //Select the relevant network adapter
   netSetDriver(interface, &w5100Driver);
#elif defined(USE_W5100S)
   //Select the relevant network adapter
   netSetDriver(interface, &w5100sDriver);
#elif defined(USE_W5200)
   //Select the relevant network adapter
   netSetDriver(interface, &w5200Driver);
#elif defined(USE_W5500)
   //Select the relevant network adapter
   netSetDriver(interface, &w5500Driver);
#elif defined(USE_W6100)
   //Select the relevant network adapter
   netSetDriver(interface, &w6100Driver);
#endif

   //Underlying SPI driver
   netSetSpiDriver(interface, &spiDriver);
   //Set external interrupt line driver
   netSetExtIntDriver(interface, &extIntDriver);

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
   taskParams.stackSize = 750;
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
