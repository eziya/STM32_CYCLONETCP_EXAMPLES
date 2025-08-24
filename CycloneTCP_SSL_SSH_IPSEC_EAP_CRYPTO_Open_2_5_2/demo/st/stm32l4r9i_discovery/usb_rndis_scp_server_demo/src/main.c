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
#include "stm32l4r9i_discovery.h"
#include "usbd_core.h"
#include "core/net.h"
#include "drivers/usb_rndis/rndis_driver.h"
#include "drivers/usb_rndis/usbd_desc.h"
#include "drivers/usb_rndis/usbd_rndis.h"
#include "dhcp/dhcp_server.h"
#include "ipv6/ndp_router_adv.h"
#include "scp/scp_server.h"
#include "hardware/stm32l4xx/stm32l4xx_crypto.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "path.h"
#include "resource_manager.h"
#include "debug.h"

//USB/RNDIS interface configuration
#define APP_IF_NAME "usb0"
#define APP_HOST_NAME "scp-server-demo"
#define APP_MAC_ADDR "00-00-00-00-00-49"

#define APP_USE_DHCP_SERVER ENABLED
#define APP_IPV4_HOST_ADDR "192.168.9.1"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "0.0.0.0"
#define APP_IPV4_PRIMARY_DNS "0.0.0.0"
#define APP_IPV4_SECONDARY_DNS "0.0.0.0"
#define APP_IPV4_ADDR_RANGE_MIN "192.168.9.10"
#define APP_IPV4_ADDR_RANGE_MAX "192.168.9.99"

#define APP_USE_ROUTER_ADV ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::49"
#define APP_IPV6_PREFIX "fd00:1:2:3::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "fd00:1:2:3::49"

//Application configuration
#define APP_SSH_MAX_CONNECTIONS 4
#define APP_SSH_MAX_CHANNELS 4
#define APP_SCP_MAX_SESSIONS 4
#define APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY "keys/server_ecdsa_p256_public_key.pem"
#define APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY "keys/server_ecdsa_p256_private_key.pem"
#define APP_SSH_SERVER_ED25519_PUBLIC_KEY "keys/server_ed25519_public_key.pem"
#define APP_SSH_SERVER_ED25519_PRIVATE_KEY "keys/server_ed25519_private_key.pem"

//Global variables
USBD_HandleTypeDef USBD_Device;
DhcpServerSettings dhcpServerSettings;
DhcpServerContext dhcpServerContext;
NdpRouterAdvSettings ndpRouterAdvSettings;
NdpRouterAdvPrefixInfo ndpRouterAdvPrefixInfo[1];
NdpRouterAdvContext ndpRouterAdvContext;
SshServerSettings sshServerSettings;
SshServerContext sshServerContext;
SshConnection sshConnections[APP_SSH_MAX_CONNECTIONS];
SshChannel sshChannels[APP_SSH_MAX_CHANNELS];
ScpServerSettings scpServerSettings;
ScpServerContext scpServerContext;
ScpServerSession scpSessions[APP_SCP_MAX_SESSIONS];
HmacDrbgContext hmacDrbgContext;
uint8_t seed[48];

//Forward declaration of functions
void initTask(void *param);
error_t sshServerImportKeys(SshServerContext *context);

SshAuthStatus sshServerPasswordAuthCallback(SshConnection *connection,
   const char_t *user, const char_t *password, size_t passwordLen);

ScpAccessStatus scpServerCheckUserCallback(ScpServerSession *session,
   const char_t *user);

uint_t scpServerGetFilePermCallback(ScpServerSession *session,
   const char_t *user, const char_t *path);


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

   //Enable voltage range 1 boost mode for frequency above 80 MHz
   HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);
   __HAL_RCC_PWR_CLK_DISABLE();

   //Enable MSI oscillator and activate PLL with MSI as source
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE | RCC_OSCILLATORTYPE_MSI;
   RCC_OscInitStruct.MSIState = RCC_MSI_ON;
   RCC_OscInitStruct.LSEState = RCC_LSE_ON;
   RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_11;
   RCC_OscInitStruct.MSICalibrationValue = RCC_MSICALIBRATION_DEFAULT;
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
   RCC_OscInitStruct.PLL.PLLM = 12;
   RCC_OscInitStruct.PLL.PLLN = 60;
   RCC_OscInitStruct.PLL.PLLR = 2;
   RCC_OscInitStruct.PLL.PLLQ = 2;
   RCC_OscInitStruct.PLL.PLLP = 7;
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Enable MSI auto-calibration through LSE
   HAL_RCCEx_EnableMSIPLLMode();

   //To avoid undershoot due to maximum frequency, select PLL as system clock
   //source with AHB prescaler divider 2 as first step
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3);

   //Select AHB prescaler divider 1 as second step
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5);

   //Select clock source for RNG peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG;
   RCC_PeriphClkInitStruct.RngClockSelection = RCC_RNGCLKSOURCE_MSI;
   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);

   //Select clock source for USB peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USB;
   RCC_PeriphClkInitStruct.UsbClockSelection = RCC_USBCLKSOURCE_MSI;
   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);
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
   OsTaskId taskId;
   OsTaskParameters taskParams;

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
   TRACE_INFO("********************************************\r\n");
   TRACE_INFO("*** CycloneTCP USB/RNDIS SCP Server Demo ***\r\n");
   TRACE_INFO("********************************************\r\n");
   TRACE_INFO("Copyright: 2010-2025 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32L4R9\r\n");
   TRACE_INFO("\r\n");

   //LED configuration
   BSP_LED_Init(LED1);
   BSP_LED_Init(LED2);

   //Clear LEDs
   BSP_LED_Off(LED1);
   BSP_LED_Off(LED2);

   //Initialize joystick
   BSP_JOY_Init(JOY_MODE_GPIO);

   //Initialize USB device library
   USBD_Init(&USBD_Device, &usbdRndisDescriptors, 0);
   //Register RNDIS class driver
   USBD_RegisterClass(&USBD_Device, USBD_RNDIS_CLASS);
   //Start USB device core
   USBD_Start(&USBD_Device);

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_HIGH;

   //Initialization task
   taskId = osCreateTask("Init", initTask, NULL, &taskParams);
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


/**
 * @brief Initialization task
 * @param[in] param Unused parameter
 **/

void initTask(void *param)
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

   //File system initialization
   error = fsInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize file system!\r\n");
   }

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure USB/RNDIS interface
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF_NAME);
   //Set host name
   netSetHostname(interface, APP_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant network adapter
   netSetDriver(interface, &rndisDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
   }

#if (IPV4_SUPPORT == ENABLED)
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

#if (APP_USE_DHCP_SERVER == ENABLED)
   //Get default settings
   dhcpServerGetDefaultSettings(&dhcpServerSettings);
   //Set the network interface to be configured by DHCP
   dhcpServerSettings.interface = interface;
   //Lease time, in seconds, assigned to the DHCP clients
   dhcpServerSettings.leaseTime = 3600;

   //Lowest and highest IP addresses in the pool that are available
   //for dynamic address assignment
   ipv4StringToAddr(APP_IPV4_ADDR_RANGE_MIN, &dhcpServerSettings.ipAddrRangeMin);
   ipv4StringToAddr(APP_IPV4_ADDR_RANGE_MAX, &dhcpServerSettings.ipAddrRangeMax);

   //Subnet mask
   ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &dhcpServerSettings.subnetMask);
   //Default gateway
   ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &dhcpServerSettings.defaultGateway);
   //DNS servers
   ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &dhcpServerSettings.dnsServer[0]);
   ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &dhcpServerSettings.dnsServer[1]);

   //DHCP server initialization
   error = dhcpServerInit(&dhcpServerContext, &dhcpServerSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP server!\r\n");
   }

   //Start DHCP server
   error = dhcpServerStart(&dhcpServerContext);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP server!\r\n");
   }
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
   //Set link-local address
   ipv6StringToAddr(APP_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);

   //Set IPv6 prefix
   ipv6StringToAddr(APP_IPV6_PREFIX, &ipv6Addr);
   ipv6SetPrefix(interface, 0, &ipv6Addr, APP_IPV6_PREFIX_LENGTH);

   //Set global address
   ipv6StringToAddr(APP_IPV6_GLOBAL_ADDR, &ipv6Addr);
   ipv6SetGlobalAddr(interface, 0, &ipv6Addr);

#if (APP_USE_ROUTER_ADV == ENABLED)
   //List of IPv6 prefixes to be advertised
   ipv6StringToAddr(APP_IPV6_PREFIX, &ndpRouterAdvPrefixInfo[0].prefix);
   ndpRouterAdvPrefixInfo[0].length = APP_IPV6_PREFIX_LENGTH;
   ndpRouterAdvPrefixInfo[0].onLinkFlag = TRUE;
   ndpRouterAdvPrefixInfo[0].autonomousFlag = TRUE;
   ndpRouterAdvPrefixInfo[0].validLifetime = 3600;
   ndpRouterAdvPrefixInfo[0].preferredLifetime = 1800;

   //Get default settings
   ndpRouterAdvGetDefaultSettings(&ndpRouterAdvSettings);
   //Set the underlying network interface
   ndpRouterAdvSettings.interface = interface;
   //Maximum time interval between unsolicited Router Advertisements
   ndpRouterAdvSettings.maxRtrAdvInterval = 60000;
   //Minimum time interval between unsolicited Router Advertisements
   ndpRouterAdvSettings.minRtrAdvInterval = 20000;
   //Router lifetime
   ndpRouterAdvSettings.defaultLifetime = 0;
   //List of IPv6 prefixes
   ndpRouterAdvSettings.prefixList = ndpRouterAdvPrefixInfo;
   ndpRouterAdvSettings.prefixListLength = arraysize(ndpRouterAdvPrefixInfo);

   //RA service initialization
   error = ndpRouterAdvInit(&ndpRouterAdvContext, &ndpRouterAdvSettings);
   //Failed to initialize DHCPv6 client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize RA service!\r\n");
   }

   //Start RA service
   error = ndpRouterAdvStart(&ndpRouterAdvContext);
   //Failed to start RA service?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start RA service!\r\n");
   }
#endif
#endif

   //Get default settings
   sshServerGetDefaultSettings(&sshServerSettings);
   //Bind SSH server to the desired interface
   sshServerSettings.interface = &netInterface[0];
   //Listen to port 22
   sshServerSettings.port = SSH_PORT;
   //SSH connections
   sshServerSettings.numConnections = APP_SSH_MAX_CONNECTIONS;
   sshServerSettings.connections = sshConnections;
   //SSH channels
   sshServerSettings.numChannels = APP_SSH_MAX_CHANNELS;
   sshServerSettings.channels = sshChannels;
   //Pseudo-random number generator
   sshServerSettings.prngAlgo = HMAC_DRBG_PRNG_ALGO;
   sshServerSettings.prngContext = &hmacDrbgContext;
   //Password authentication callback function
   sshServerSettings.passwordAuthCallback = sshServerPasswordAuthCallback;

   //SSH server initialization
   error = sshServerInit(&sshServerContext, &sshServerSettings);
   //Failed to initialize SSH server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SSH server!\r\n");
   }

   //Load keys
   error = sshServerImportKeys(&sshServerContext);
   //Failed to load keys?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to load keys!\r\n");
   }

   //Start SSH server
   error = sshServerStart(&sshServerContext);
   //Failed to start SSH server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SSH server!\r\n");
   }

   //Get default settings
   scpServerGetDefaultSettings(&scpServerSettings);
   //SSH server context
   scpServerSettings.sshServerContext = &sshServerContext;
   //SCP sessions
   scpServerSettings.numSessions = APP_SCP_MAX_SESSIONS;
   scpServerSettings.sessions = scpSessions;
   //Root directory
   scpServerSettings.rootDir = "/";
   //User verification callback function
   scpServerSettings.checkUserCallback = scpServerCheckUserCallback;
   //Callback used to retrieve file permissions
   scpServerSettings.getFilePermCallback = scpServerGetFilePermCallback;

   //SCP server initialization
   error = scpServerInit(&scpServerContext, &scpServerSettings);
   //Failed to initialize SCP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SCP server!\r\n");
   }

   //Start SCP server
   error = scpServerStart(&scpServerContext);
   //Failed to start SCP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SCP server!\r\n");
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

   //Kill ourselves
   osDeleteTask(OS_SELF_TASK_ID);
}


/**
 * @brief Load SSH server's keys
 * @param[in] context Pointer to the SSH server context
 * @return Error code
 **/

error_t sshServerImportKeys(SshServerContext *context)
{
   error_t error;
   const char_t *publicKey;
   size_t publicKeyLen;
   const char_t *privateKey;
   size_t privateKeyLen;

   //Get server's ECDSA P-256 public key
   error = resGetData(APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's ECDSA P-256 private key
   error = resGetData(APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load ECDSA P-256 key pair
   error = sshServerLoadHostKey(context, 0, publicKey, publicKeyLen,
      privateKey, privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Get server's Ed25519 public key
   error = resGetData(APP_SSH_SERVER_ED25519_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's Ed25519 private key
   error = resGetData(APP_SSH_SERVER_ED25519_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load Ed25519 key pair
   error = sshServerLoadHostKey(context, 1, publicKey, publicKeyLen,
      privateKey, privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Password authentication callback function
 * @param[in] connection Handle referencing a client connection
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] password NULL-terminated string that contains the corresponding password
 * @return Authentication status (SSH_AUTH_STATUS_SUCCESS, SSH_AUTH_STATUS_FAILURE or
 *   SSH_AUTH_STATUS_PASSWORD_EXPIRED)
 **/

SshAuthStatus sshServerPasswordAuthCallback(SshConnection *connection,
   const char_t *user, const char_t *password, size_t passwordLen)
{
   SshAuthStatus status;

   //Debug message
   TRACE_INFO("SSH server: Password verification\r\n");

   //Manage authentication policy
   if(!strcmp(user, "anonymous"))
   {
      //Anonymous users do not need any password
      status = SSH_AUTH_STATUS_SUCCESS;
   }
   else if(!strcmp(user, "admin"))
   {
      //Check password
      if(passwordLen == 8 && !strncmp(password, "password", 8))
      {
         //The provided password is valid
         status = SSH_AUTH_STATUS_SUCCESS;
      }
      else
      {
         //The provided password is not valid
         status = SSH_AUTH_STATUS_FAILURE;
      }
   }
   else
   {
      //Unknown user name
      status = SSH_AUTH_STATUS_FAILURE;
   }

   //Return access status
   return status;
}


/**
 * @brief User verification callback function
 * @param[in] session Handle referencing an SCP session
 * @param[in] user NULL-terminated string that contains the user name
 * @return Access status
 **/

ScpAccessStatus scpServerCheckUserCallback(ScpServerSession *session,
   const char_t *user)
{
   //Debug message
   TRACE_INFO("SCP server: User verification\r\n");

   //All SSH users are granted access to the SCP service
   return SCP_ACCESS_ALLOWED;
}


/**
 * @brief Callback used to retrieve file permissions
 * @param[in] session Handle referencing an SCP session
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] path Canonical path of the file
 * @return Permissions for the specified file
 **/

uint_t scpServerGetFilePermCallback(ScpServerSession *session,
   const char_t *user, const char_t *path)
{
   uint_t perm;

   //Debug message
   TRACE_INFO("SCP server: Checking access rights for %s\r\n", path);

   //Manage access rights
   if(!strcmp(user, "anonymous"))
   {
      //Check path name
      if(pathMatch(path, "/temp/*"))
      {
         //Allow read/write access to temp directory
         perm = SCP_FILE_PERM_LIST | SCP_FILE_PERM_READ | SCP_FILE_PERM_WRITE;
      }
      else
      {
         //Allow read access only to other directories
         perm = SCP_FILE_PERM_LIST | SCP_FILE_PERM_READ;
      }
   }
   else if(!strcmp(user, "admin"))
   {
      //Allow read/write access
      perm = SCP_FILE_PERM_LIST | SCP_FILE_PERM_READ | SCP_FILE_PERM_WRITE;
   }
   else
   {
      //Deny access
      perm = 0;
   }

   //Return the relevant permissions
   return perm;
}
