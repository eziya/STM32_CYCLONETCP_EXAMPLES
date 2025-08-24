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
#include "stm32n6xx.h"
#include "stm32n6xx_hal.h"
#include "stm32n6xx_nucleo.h"
#include "core/net.h"
#include "drivers/mac/stm32n6xx_eth_driver.h"
#include "drivers/phy/lan8742_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "shell/shell_server.h"
#include "hardware/stm32n6xx/stm32n6xx_crypto.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "resource_manager.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "ssh-server-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-06-57"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::657"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::657"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SSH_MAX_CONNECTIONS 2
#define APP_SSH_MAX_CHANNELS 2
#define APP_SHELL_MAX_SESSIONS 2
#define APP_SSH_SERVER_RSA_PUBLIC_KEY "keys/server_rsa_public_key.pem"
#define APP_SSH_SERVER_RSA_PRIVATE_KEY "keys/server_rsa_private_key.pem"
#define APP_SSH_SERVER_DSA_PUBLIC_KEY "keys/server_dsa_public_key.pem"
#define APP_SSH_SERVER_DSA_PRIVATE_KEY "keys/server_dsa_private_key.pem"
#define APP_SSH_SERVER_ECDSA_P256_PUBLIC_KEY "keys/server_ecdsa_p256_public_key.pem"
#define APP_SSH_SERVER_ECDSA_P256_PRIVATE_KEY "keys/server_ecdsa_p256_private_key.pem"

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
SshServerSettings sshServerSettings;
SshServerContext sshServerContext;
SshConnection sshConnections[APP_SSH_MAX_CONNECTIONS];
SshChannel sshChannels[APP_SSH_MAX_CHANNELS];
ShellServerSettings shellServerSettings;
ShellServerContext shellServerContext;
ShellServerSession shellSessions[APP_SHELL_MAX_SESSIONS];
HmacDrbgContext hmacDrbgContext;
uint8_t seed[48];

//Forward declaration of functions
error_t sshServerImportKeys(SshServerContext *context);

SshAuthStatus sshServerPasswordAuthCallback(SshConnection *connection,
   const char_t *user, const char_t *password, size_t passwordLen);

ShellAccessStatus shellServerCheckUserCallback(ShellServerSession *session,
   const char_t *user);

error_t shellServerCommandLineCallback(ShellServerSession *session,
   char_t *commandLine);


/**
 * @brief System clock configuration
 **/

void SystemClock_Config(void)
{
   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

   //Configure the system power supply
   HAL_PWREx_ConfigSupply(PWR_EXTERNAL_SOURCE_SUPPLY);

   //Enable HSI
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
   RCC_OscInitStruct.HSIState = RCC_HSI_ON;
   RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV1;
   RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
   RCC_OscInitStruct.PLL1.PLLState = RCC_PLL_NONE;
   RCC_OscInitStruct.PLL2.PLLState = RCC_PLL_NONE;
   RCC_OscInitStruct.PLL3.PLLState = RCC_PLL_NONE;
   RCC_OscInitStruct.PLL4.PLLState = RCC_PLL_NONE;
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Get current CPU/system bus clocks configuration 
   HAL_RCC_GetClockConfig(&RCC_ClkInitStruct);

   //If necessary, switch to intermediate HSI clock to ensure target clock can
   //be set
   if(RCC_ClkInitStruct.CPUCLKSource == RCC_CPUCLKSOURCE_IC1 ||
      RCC_ClkInitStruct.SYSCLKSource == RCC_SYSCLKSOURCE_IC2_IC6_IC11)
   {
      RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_CPUCLK | RCC_CLOCKTYPE_SYSCLK;
      RCC_ClkInitStruct.CPUCLKSource = RCC_CPUCLKSOURCE_HSI;
      RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
      HAL_RCC_ClockConfig(&RCC_ClkInitStruct);
   }

   //Initialize RCC oscillators
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_NONE;
   RCC_OscInitStruct.PLL1.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL1.PLLSource = RCC_PLLSOURCE_HSI;
   RCC_OscInitStruct.PLL1.PLLM = 4;
   RCC_OscInitStruct.PLL1.PLLN = 75;
   RCC_OscInitStruct.PLL1.PLLFractional = 0;
   RCC_OscInitStruct.PLL1.PLLP1 = 1;
   RCC_OscInitStruct.PLL1.PLLP2 = 1;
   RCC_OscInitStruct.PLL2.PLLState = RCC_PLL_NONE;
   RCC_OscInitStruct.PLL3.PLLState = RCC_PLL_NONE;
   RCC_OscInitStruct.PLL4.PLLState = RCC_PLL_NONE;
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Initialize CPU, AHB and APB bus clocks
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_CPUCLK | RCC_CLOCKTYPE_HCLK |
      RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 |
      RCC_CLOCKTYPE_PCLK5 | RCC_CLOCKTYPE_PCLK4;
   RCC_ClkInitStruct.CPUCLKSource = RCC_CPUCLKSOURCE_IC1;
   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_IC2_IC6_IC11;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV1;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV1;
   RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV1;
   RCC_ClkInitStruct.APB5CLKDivider = RCC_APB5_DIV1;
   RCC_ClkInitStruct.IC1Selection.ClockSelection = RCC_ICCLKSOURCE_PLL1;
   RCC_ClkInitStruct.IC1Selection.ClockDivider = 2;
   RCC_ClkInitStruct.IC2Selection.ClockSelection = RCC_ICCLKSOURCE_PLL1;
   RCC_ClkInitStruct.IC2Selection.ClockDivider = 3;
   RCC_ClkInitStruct.IC6Selection.ClockSelection = RCC_ICCLKSOURCE_PLL1;
   RCC_ClkInitStruct.IC6Selection.ClockDivider = 4;
   RCC_ClkInitStruct.IC11Selection.ClockSelection = RCC_ICCLKSOURCE_PLL1;
   RCC_ClkInitStruct.IC11Selection.ClockDivider = 3;
   HAL_RCC_ClockConfig(&RCC_ClkInitStruct);
}


/**
 * @brief MPU configuration
 **/

void MPU_Config(void)
{
   uint32_t primask;
   MPU_Region_InitTypeDef MPU_InitStruct = {0};
   MPU_Attributes_InitTypeDef MPU_AttrConfig = {0};

   //Get priority mask and disable interrupts
   primask = __get_PRIMASK();
   __disable_irq();

   //Disable MPU
   HAL_MPU_Disable();

   //ROM
   MPU_AttrConfig.Attributes = INNER_OUTER(MPU_R_ALLOCATE);
   MPU_AttrConfig.Number = MPU_ATTRIBUTES_NUMBER0;
   HAL_MPU_ConfigMemoryAttributes(&MPU_AttrConfig);

   MPU_InitStruct.Enable = MPU_REGION_ENABLE;
   MPU_InitStruct.Number = MPU_REGION_NUMBER0;
   MPU_InitStruct.BaseAddress = 0x34180000;
   MPU_InitStruct.LimitAddress = 0x341FFFFF;
   MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
   MPU_InitStruct.AccessPermission = MPU_REGION_ALL_RW;
   MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
   MPU_InitStruct.AttributesIndex = MPU_ATTRIBUTES_NUMBER0;
   HAL_MPU_ConfigRegion(&MPU_InitStruct);

   //RAM
   MPU_AttrConfig.Attributes = INNER_OUTER(MPU_RW_ALLOCATE);
   MPU_AttrConfig.Number = MPU_ATTRIBUTES_NUMBER1;
   HAL_MPU_ConfigMemoryAttributes(&MPU_AttrConfig);

   MPU_InitStruct.Enable = MPU_REGION_ENABLE;
   MPU_InitStruct.Number = MPU_REGION_NUMBER1;
   MPU_InitStruct.BaseAddress = 0x34106000;
   MPU_InitStruct.LimitAddress = 0x34177FFF;
   MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
   MPU_InitStruct.AccessPermission = MPU_REGION_ALL_RW;
   MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
   MPU_InitStruct.AttributesIndex = MPU_ATTRIBUTES_NUMBER1;
   HAL_MPU_ConfigRegion(&MPU_InitStruct);

   //RAM (no cache)
   MPU_AttrConfig.Attributes = INNER_OUTER(MPU_NOT_CACHEABLE);
   MPU_AttrConfig.Number = MPU_ATTRIBUTES_NUMBER2;
   HAL_MPU_ConfigMemoryAttributes(&MPU_AttrConfig);

   MPU_InitStruct.Enable = MPU_REGION_ENABLE;
   MPU_InitStruct.Number = MPU_REGION_NUMBER2;
   MPU_InitStruct.BaseAddress = 0x34178000;
   MPU_InitStruct.LimitAddress = 0x3417FFFF;
   MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
   MPU_InitStruct.AccessPermission = MPU_REGION_ALL_RW;
   MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
   MPU_InitStruct.AttributesIndex = MPU_ATTRIBUTES_NUMBER2;
   HAL_MPU_ConfigRegion(&MPU_InitStruct);

   //Enable MPU
   HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);

   //Restore priority mask
   __set_PRIMASK(primask);
}


/**
 * @brief RISAF configuration
 **/

void RISAF_Config(void)
{
   RIMC_MasterConfig_t RIMC_MasterConfig = {0};

   //Enable RIFSC clock
   __HAL_RCC_RIFSC_CLK_ENABLE();

   //Configure CID, Security and Privilege attributes for the master
   RIMC_MasterConfig.MasterCID = RIF_CID_1;
   RIMC_MasterConfig.SecPriv = RIF_ATTRIBUTE_SEC | RIF_ATTRIBUTE_PRIV;
   HAL_RIF_RIMC_ConfigMasterAttributes(RIF_MASTER_INDEX_ETH1, &RIMC_MasterConfig);

   //Configure the Security and Privilege attributes for the ETH1 slave peripheral
   HAL_RIF_RISC_SetSlaveSecureAttributes(RIF_RISC_PERIPH_INDEX_ETH1,
      RIF_ATTRIBUTE_SEC | RIF_ATTRIBUTE_PRIV);
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

   //Disable I-cache and D-cache
   SCB_DisableICache();
   SCB_DisableDCache();

   //MPU configuration
   MPU_Config();

   //Enable I-cache and D-cache
   SCB_EnableICache();
   SCB_EnableDCache();

   //RISAF configuration
   RISAF_Config();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneSSH SSH Server Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2025 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32N657\r\n");
   TRACE_INFO("\r\n");

   //LED configuration
   BSP_LED_Init(LED1);
   BSP_LED_Init(LED2);
   BSP_LED_Init(LED3);

   //Clear LEDs
   BSP_LED_Off(LED1);
   BSP_LED_Off(LED2);
   BSP_LED_Off(LED3);

   //Initialize user button
   BSP_PB_Init(BUTTON_USER, BUTTON_MODE_GPIO);

   //Initialize hardware cryptographic accelerator
   error = stm32n6xxCryptoInit();
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
   netSetDriver(interface, &stm32n6xxEthDriver);
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

   //Get default settings
   sshServerGetDefaultSettings(&sshServerSettings);
   //Bind SSH server to the desired interface
   sshServerSettings.interface = NULL;
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
   shellServerGetDefaultSettings(&shellServerSettings);
   //SSH server context
   shellServerSettings.sshServerContext = &sshServerContext;
   //Shell sessions
   shellServerSettings.numSessions = APP_SHELL_MAX_SESSIONS;
   shellServerSettings.sessions = shellSessions;
   //User verification callback function
   shellServerSettings.checkUserCallback = shellServerCheckUserCallback;
   //Command line processing callback function
   shellServerSettings.commandLineCallback = shellServerCommandLineCallback;

   //Shell server initialization
   error = shellServerInit(&shellServerContext, &shellServerSettings);
   //Failed to initialize shell server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize shell server!\r\n");
   }

   //Start shell server
   error = shellServerStart(&shellServerContext);
   //Failed to start shell server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start shell server!\r\n");
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

   //Get server's RSA public key
   error = resGetData(APP_SSH_SERVER_RSA_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's RSA private key
   error = resGetData(APP_SSH_SERVER_RSA_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load RSA key pair
   error = sshServerLoadHostKey(context, 0, publicKey, publicKeyLen,
      privateKey, privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Get server's DSA public key
   error = resGetData(APP_SSH_SERVER_DSA_PUBLIC_KEY,
      (const uint8_t **) &publicKey, &publicKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Get server's DSA private key
   error = resGetData(APP_SSH_SERVER_DSA_PRIVATE_KEY,
      (const uint8_t **) &privateKey, &privateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load DSA key pair
   error = sshServerLoadHostKey(context, 1, publicKey, publicKeyLen,
      privateKey, privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

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
   error = sshServerLoadHostKey(context, 2, publicKey, publicKeyLen,
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
   if(!strcmp(user, "admin"))
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
 * @param[in] session Handle referencing a shell session
 * @param[in] user NULL-terminated string that contains the user name
 * @return Access status
 **/

ShellAccessStatus shellServerCheckUserCallback(ShellServerSession *session,
   const char_t *user)
{
   //Debug message
   TRACE_INFO("Shell server: User verification\r\n");

   //Set welcome banner
   shellServerSetBanner(session,
      "You are connected to \x1b[32mCycloneSSH\x1b[39m Server\r\n");

   //Set shell prompt
   shellServerSetPrompt(session, ">");

   //All SSH users are granted access to the shell service
   return SHELL_ACCESS_ALLOWED;
}


/**
 * @brief Command line processing callback function
 * @param[in] session Handle referencing an SCP session
 * @param[in] user NULL-terminated string that contains the user name
 * @param[in] path Canonical path of the file
 * @return Permissions for the specified file
 **/

error_t shellServerCommandLineCallback(ShellServerSession *session,
   char_t *commandLine)
{
   error_t error;

   //Debug message
   TRACE_INFO("Shell server: Command line received\r\n");
   TRACE_INFO("  %s\r\n", commandLine);

   //Check command name
   if(!strcasecmp(commandLine, "hello"))
   {
      //Send response to the client
      error = shellServerWriteStream(session, "Hello World!\r\n", 14,
         NULL, 0);
   }
   else if(!strcasecmp(commandLine, "exit") ||
      !strcasecmp(commandLine, "quit"))
   {
      //Close shell session
      error = ERROR_END_OF_STREAM;
   }
   else
   {
      //Unknown command received
      error = shellServerWriteStream(session, "Unknown command!\r\n", 18,
         NULL, 0);
   }

   //Return status code
   return error;
}
