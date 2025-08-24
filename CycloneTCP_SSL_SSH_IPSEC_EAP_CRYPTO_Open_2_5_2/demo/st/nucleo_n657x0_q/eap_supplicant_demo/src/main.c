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
#include "supplicant/supplicant.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "hardware/stm32n6xx/stm32n6xx_crypto.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "resource_manager.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "eap-supplicant-demo"
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

//802.1X supplicant configuration
#define APP_SUPPLICANT_IDENTITY "user@example.org"
#define APP_SUPPLICANT_PASSWORD ""
#define APP_SUPPLICANT_CERT "/certs/supplicant_cert.pem"
#define APP_SUPPLICANT_KEY "/certs/supplicant_key.pem"
#define APP_SUPPLICANT_KEY_PASSWORD ""
#define APP_SUPPLICANT_CA_CERT_BUNDLE "/certs/ca_cert.pem"

//Global variables
SupplicantSettings supplicantSettings;
SupplicantContext supplicantContext;
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
HmacDrbgContext hmacDrbgContext;
uint8_t seed[48];

//Forward declaration of functions
error_t supplicantTlsInitCallback(SupplicantContext *context,
   TlsContext *tlsContext);

void supplicantPaeStateChangeCallback(SupplicantContext *context,
   SupplicantPaeState state);


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
   TRACE_INFO("*****************************************\r\n");
   TRACE_INFO("*** CycloneEAP 802.1X Supplicant Demo ***\r\n");
   TRACE_INFO("*****************************************\r\n");
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

   //Get default settings
   supplicantGetDefaultSettings(&supplicantSettings);
   //Bind 802.1X supplicant to the desired interface
   supplicantSettings.interface = interface;
   //Supplicant PAE state change callback function
   supplicantSettings.paeStateChangeCallback = supplicantPaeStateChangeCallback;
   //TLS initialization callback function (only for EAP-TLS)
   supplicantSettings.tlsInitCallback = supplicantTlsInitCallback;

   //802.1X supplicant initialization
   error = supplicantInit(&supplicantContext, &supplicantSettings);
   //Failed to initialize 802.1X supplicant?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize 802.1X supplicant!\r\n");
   }

   //Set user name
   error = supplicantSetUsername(&supplicantContext, APP_SUPPLICANT_IDENTITY);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to set username!\r\n");
   }

   //Set password (only for EAP-MD5)
   error = supplicantSetPassword(&supplicantContext, APP_SUPPLICANT_PASSWORD);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to set password!\r\n");
   }

   //Start 802.1X supplicant
   error = supplicantStart(&supplicantContext);
   //Failed to start 802.1X supplicant?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start 802.1X supplicant!\r\n");
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
 * @brief TLS initialization callback
 * @param[in] context Pointer to the 802.1X supplicant context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t supplicantTlsInitCallback(SupplicantContext *context,
   TlsContext *tlsContext)
{
   error_t error;
   const char_t *clientCert;
   size_t clientCertLen;
   const char_t *clientPrivateKey;
   size_t clientPrivateKeyLen;
   const char_t *trustedCaList;
   size_t trustedCaListLen;

   //Debug message
   TRACE_INFO("802.1X Supplicant: TLS initialization callback\r\n");

   //Set TX and RX buffer size
   error = tlsSetBufferSize(tlsContext, 3072, 3072);
   //Any error to report?
   if(error)
      return error;

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
   //Any error to report?
   if(error)
      return error;

   //Get supplicant's certificate
   error = resGetData(APP_SUPPLICANT_CERT,
      (const uint8_t **) &clientCert, &clientCertLen);
   //Any error to report?
   if(error)
      return error;

   //Get supplicant's private key
   error = resGetData(APP_SUPPLICANT_KEY,
      (const uint8_t **) &clientPrivateKey, &clientPrivateKeyLen);
   //Any error to report?
   if(error)
      return error;

   //Load supplicant's certificate
   error = tlsLoadCertificate(tlsContext, 0, clientCert, clientCertLen,
      clientPrivateKey, clientPrivateKeyLen, APP_SUPPLICANT_KEY_PASSWORD);
   //Any error to report?
   if(error)
      return error;

   //Get the list of trusted CA certificates
   error = resGetData(APP_SUPPLICANT_CA_CERT_BUNDLE,
      (const uint8_t **) &trustedCaList, &trustedCaListLen);
   //Any error to report?
   if(error)
      return error;

   //Import the list of trusted CA certificates
   error = tlsSetTrustedCaList(tlsContext, trustedCaList, trustedCaListLen);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Supplicant PAE state change callback function
 * @param[in] context Pointer to the 802.1X supplicant context
 * @param[in] state Supplicant PAE state
 **/

void supplicantPaeStateChangeCallback(SupplicantContext *context,
   SupplicantPaeState state)
{
   //Check current state
   if(state == SUPPLICANT_PAE_STATE_LOGOFF)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**************\r\n");
      TRACE_INFO("*** LOGOFF ***\r\n");
      TRACE_INFO("**************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_DISCONNECTED)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("*** DISCONNECTED ***\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_CONNECTING)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("******************\r\n");
      TRACE_INFO("*** CONNECTING ***\r\n");
      TRACE_INFO("******************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_AUTHENTICATING)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("*** AUTHENTICATING ***\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_AUTHENTICATED)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("*********************\r\n");
      TRACE_INFO("*** AUTHENTICATED ***\r\n");
      TRACE_INFO("*********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_HELD)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("************\r\n");
      TRACE_INFO("*** HELD ***\r\n");
      TRACE_INFO("************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_RESTART)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("***************\r\n");
      TRACE_INFO("*** RESTART ***\r\n");
      TRACE_INFO("***************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_S_FORCE_AUTH)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("********************\r\n");
      TRACE_INFO("*** S_FORCE_AUTH ***\r\n");
      TRACE_INFO("********************\r\n");
      TRACE_INFO("\r\n");
   }
   else if(state == SUPPLICANT_PAE_STATE_S_FORCE_UNAUTH)
   {
      TRACE_INFO("\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("*** S_FORCE_UNAUTH ***\r\n");
      TRACE_INFO("**********************\r\n");
      TRACE_INFO("\r\n");
   }
   else
   {
   }
}
