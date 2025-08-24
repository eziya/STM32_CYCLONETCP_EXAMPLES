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
#include "stm32mp13xx.h"
#include "stm32mp13xx_hal.h"
#include "stm32mp13xx_disco.h"
#include "stm32mp13xx_disco_io.h"
#include "stm32mp13xx_disco_stpmic1.h"
#include "core/net.h"
#include "drivers/mac/stm32mp13xx_eth1_driver.h"
#include "drivers/mac/stm32mp13xx_eth2_driver.h"
#include "drivers/phy/lan8742_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "snmp/snmp_agent.h"
#include "mibs/mib2_module.h"
#include "mibs/mib2_impl.h"
#include "hardware/stm32mp13xx/stm32mp13xx_crypto.h"
#include "encoding/oid.h"
#include "rng/trng.h"
#include "private_mib_module.h"
#include "private_mib_impl.h"
#include "debug.h"

//First Ethernet interface configuration
#define APP_IF1_NAME "eth1"
#define APP_IF1_HOST_NAME "snmp-agent-demo-1"
#define APP_IF1_MAC_ADDR "00-AB-CD-01-35-01"

#define APP_IF1_USE_DHCP_CLIENT ENABLED
#define APP_IF1_IPV4_HOST_ADDR "192.168.0.21"
#define APP_IF1_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF1_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF1_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF1_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF1_USE_SLAAC ENABLED
#define APP_IF1_IPV6_LINK_LOCAL_ADDR "fe80::135:1"
#define APP_IF1_IPV6_PREFIX "2001:db8::"
#define APP_IF1_IPV6_PREFIX_LENGTH 64
#define APP_IF1_IPV6_GLOBAL_ADDR "2001:db8::135:1"
#define APP_IF1_IPV6_ROUTER "fe80::1"
#define APP_IF1_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IF1_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Second Ethernet interface configuration
#define APP_IF2_NAME "eth2"
#define APP_IF2_HOST_NAME "snmp-agent-demo-2"
#define APP_IF2_MAC_ADDR "00-AB-CD-01-35-02"

#define APP_IF2_USE_DHCP_CLIENT ENABLED
#define APP_IF2_IPV4_HOST_ADDR "192.168.0.22"
#define APP_IF2_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IF2_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IF2_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IF2_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_IF2_USE_SLAAC ENABLED
#define APP_IF2_IPV6_LINK_LOCAL_ADDR "fe80::135:2"
#define APP_IF2_IPV6_PREFIX "2001:db8::"
#define APP_IF2_IPV6_PREFIX_LENGTH 64
#define APP_IF2_IPV6_GLOBAL_ADDR "2001:db8::135:2"
#define APP_IF2_IPV6_ROUTER "fe80::1"
#define APP_IF2_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IF2_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
#define APP_SNMP_PRIVATE_ENTERPRISE_NUMBER 8072
#define APP_SNMP_ENTERPRISE_OID "1.3.6.1.4.1.8072.9999.9999"
#define APP_SNMP_TRAP_DEST_IP_ADDR "192.168.0.100"

//Global variables
TIM_HandleTypeDef TIM_Handle;

bool_t ledState = FALSE;
systime_t ledTime = 0;
DhcpState dhcpPrevState = DHCP_STATE_INIT;

DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext[2];
SlaacSettings slaacSettings;
SlaacContext slaacContext[2];
SnmpAgentSettings snmpAgentSettings;
SnmpAgentContext snmpAgentContext;

//Forward declaration of functions
error_t eth1InterfaceInit(void);
error_t eth2InterfaceInit(void);

void dhcpClientStateChangeCallback(DhcpClientContext *context,
   NetInterface *interface, DhcpState state);

error_t snmpAgentRandCallback(uint8_t *data, size_t length);


/**
 * @brief System clock configuration
 **/

void SystemClock_Config(void)
{
   RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct = {0};

#if !defined(USE_DDR)
   HAL_RCC_DeInit();
   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

   //Enable oscillators
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI |
   RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_CSI |
   RCC_OSCILLATORTYPE_LSI | RCC_OSCILLATORTYPE_LSE;

   RCC_OscInitStruct.HSIState = RCC_HSI_ON;
   RCC_OscInitStruct.HSEState = RCC_HSE_ON;
   RCC_OscInitStruct.LSEState = RCC_LSE_ON;
   RCC_OscInitStruct.LSIState = RCC_LSI_ON;
   RCC_OscInitStruct.CSIState = RCC_CSI_ON;

   RCC_OscInitStruct.HSICalibrationValue = 0;
   RCC_OscInitStruct.CSICalibrationValue = 16;
   RCC_OscInitStruct.HSIDivValue = RCC_HSI_DIV1;

   //PLL configuration
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLL12SOURCE_HSE;
   RCC_OscInitStruct.PLL.PLLM = 3;
   RCC_OscInitStruct.PLL.PLLN = 81;
   RCC_OscInitStruct.PLL.PLLP = 1;
   RCC_OscInitStruct.PLL.PLLQ = 2;
   RCC_OscInitStruct.PLL.PLLR = 2;
   RCC_OscInitStruct.PLL.PLLFRACV = 0x800;
   RCC_OscInitStruct.PLL.PLLMODE = RCC_PLL_FRACTIONAL;

   //PLL2 configuration
   RCC_OscInitStruct.PLL2.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL2.PLLSource = RCC_PLL12SOURCE_HSE;
   RCC_OscInitStruct.PLL2.PLLM = 3;
   RCC_OscInitStruct.PLL2.PLLN = 66;
   RCC_OscInitStruct.PLL2.PLLP = 2;
   RCC_OscInitStruct.PLL2.PLLQ = 2;
   RCC_OscInitStruct.PLL2.PLLR = 1;
   RCC_OscInitStruct.PLL2.PLLFRACV = 0x1400;
   RCC_OscInitStruct.PLL2.PLLMODE = RCC_PLL_FRACTIONAL;

   //PLL3 configuration
   RCC_OscInitStruct.PLL3.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL3.PLLSource = RCC_PLL3SOURCE_HSE;
   RCC_OscInitStruct.PLL3.PLLM = 2;
   RCC_OscInitStruct.PLL3.PLLN = 34;
   RCC_OscInitStruct.PLL3.PLLP = 2;
   RCC_OscInitStruct.PLL3.PLLQ = 17;
   RCC_OscInitStruct.PLL3.PLLR = 2;
   RCC_OscInitStruct.PLL3.PLLRGE = RCC_PLL3IFRANGE_1;
   RCC_OscInitStruct.PLL3.PLLFRACV = 0x1a04;
   RCC_OscInitStruct.PLL3.PLLMODE = RCC_PLL_FRACTIONAL;

   //PLL4 configuration
   RCC_OscInitStruct.PLL4.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL4.PLLSource = RCC_PLL4SOURCE_HSE;
   RCC_OscInitStruct.PLL4.PLLM = 2;
   RCC_OscInitStruct.PLL4.PLLN = 50;
   RCC_OscInitStruct.PLL4.PLLP = 12;
   RCC_OscInitStruct.PLL4.PLLQ = 60;
   RCC_OscInitStruct.PLL4.PLLR = 6;
   RCC_OscInitStruct.PLL4.PLLRGE = RCC_PLL4IFRANGE_1;
   RCC_OscInitStruct.PLL4.PLLFRACV = 0;
   RCC_OscInitStruct.PLL4.PLLMODE = RCC_PLL_INTEGER;

   //Enable access to RTC and backup registers
   SET_BIT(PWR->CR1, PWR_CR1_DBP);
   //Configure LSEDRIVE value
   __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_MEDIUMHIGH);

   //Initialize PLLx
   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Select PLLx as MPU, AXI and MCU clock sources
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_MPU | RCC_CLOCKTYPE_ACLK |
      RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK4 | RCC_CLOCKTYPE_PCLK5 |
      RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK6 | RCC_CLOCKTYPE_PCLK2 |
      RCC_CLOCKTYPE_PCLK3;

   RCC_ClkInitStruct.MPUInit.MPU_Clock = RCC_MPUSOURCE_PLL1;
   RCC_ClkInitStruct.MPUInit.MPU_Div = RCC_MPU_DIV2;
   RCC_ClkInitStruct.AXISSInit.AXI_Clock = RCC_AXISSOURCE_PLL2;
   RCC_ClkInitStruct.AXISSInit.AXI_Div = RCC_AXI_DIV1;
   RCC_ClkInitStruct.MLAHBInit.MLAHB_Clock = RCC_MLAHBSSOURCE_PLL3;
   RCC_ClkInitStruct.MLAHBInit.MLAHB_Div = RCC_MLAHB_DIV1;
   RCC_ClkInitStruct.APB1_Div = RCC_APB1_DIV2;
   RCC_ClkInitStruct.APB2_Div = RCC_APB2_DIV2;
   RCC_ClkInitStruct.APB3_Div = RCC_APB3_DIV2;
   RCC_ClkInitStruct.APB4_Div = RCC_APB4_DIV2;
   RCC_ClkInitStruct.APB5_Div = RCC_APB5_DIV4;
   RCC_ClkInitStruct.APB6_Div = RCC_APB6_DIV2;

   HAL_RCC_ClockConfig(&RCC_ClkInitStruct);
#endif

   //Select clock source for RNG peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG1;
   RCC_PeriphClkInitStruct.Rng1ClockSelection = RCC_RNG1CLKSOURCE_LSI;
   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);
}


/**
 * @brief Timer initialization
 **/

void TIM6_Init(void)
{
   uint32_t freq;
   uint32_t prescaler;

   //Enable TIM6 clock
   __HAL_RCC_TIM6_CLK_ENABLE();

   //Get TIM6 peripheral clock
   freq = HAL_RCCEx_GetPeriphCLKFreq(RCC_PERIPHCLK_TIM6);
   //Compute prescaler value
   prescaler = (freq / 1000000) - 1;

   //Initialize TIM6
   TIM_Handle.Instance = TIM6;
   TIM_Handle.Init.Period = (1000000 / 1000) - 1;
   TIM_Handle.Init.Prescaler = prescaler;
   TIM_Handle.Init.ClockDivision = 0;
   TIM_Handle.Init.CounterMode = TIM_COUNTERMODE_UP;
   HAL_TIM_Base_Init(&TIM_Handle);

   //Start timer
   HAL_TIM_Base_Start_IT(&TIM_Handle);

   //Configure TIM6 interrupt priority
   IRQ_SetPriority(TIM6_IRQn, 0U);
   //Enable TIM6 interrupts
   IRQ_Enable(TIM6_IRQn);
}


/**
 * @brief Timer interrupt handler
 **/

void TIM6_IRQHandler(void)
{
   if(TIM_Handle.Instance != NULL)
   {
      HAL_TIM_IRQHandler(&TIM_Handle);
      systemTicks++;
   }
   else
   {
      IRQ_Disable(TIM6_IRQn);
   }
}


/**
 * @brief LED task
 **/

void ledTask(void)
{
   //Check current time
   if((int32_t)(systemTicks - ledTime) > 0)
   {
      //Toggle LED state
      if(ledState == 0)
      {
         BSP_LED_On(LED3);
         ledState = 1;
         ledTime = systemTicks + 100;
      }
      else
      {
         BSP_LED_Off(LED3);
         ledState = 0;
         ledTime = systemTicks + 900;
      }
   }
}


/**
 * @brief Main entry point
 * @return Unused value
 **/

int_t main(void)
{
   error_t error;
   size_t oidLen;
   uint8_t oid[SNMP_MAX_OID_SIZE];
#if (SNMP_V3_SUPPORT == ENABLED)
   MacAddr macAddr;
   uint8_t contextEngine[11];
#endif

   //HAL library initialization
   HAL_Init();
   //Configure the system clock
   SystemClock_Config();

 #if (USE_STPMIC1x) && !defined(USE_DDR)
   //Configure PMIC
   BSP_PMIC_Init();
   BSP_PMIC_InitRegulators();
 #endif

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("*** CycloneTCP SNMP Agent Demo ***\r\n");
   TRACE_INFO("**********************************\r\n");
   TRACE_INFO("Copyright: 2010-2025 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32MP135F\r\n");
   TRACE_INFO("\r\n");

   //Initialize the IO expander
   BSP_IOEXPANDER_Init(0, IOEXPANDER_IO_MODE);

   //LED configuration
   BSP_LED_Init(LED3);
   BSP_LED_Init(LED4);
   BSP_LED_Init(LED6);
   BSP_LED_Init(LED7);

   //Clear LEDs
   BSP_LED_Off(LED3);
   BSP_LED_Off(LED4);
   BSP_LED_Off(LED6);
   BSP_LED_Off(LED7);

   //Initialize user button
   BSP_PB_Init(BUTTON_TAMPER, BUTTON_MODE_GPIO);

   //Initialize hardware cryptographic accelerator
   error = stm32mp13xxCryptoInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize hardware crypto accelerator!\r\n");
   }

   //Standard MIB-II initialization
   error = mib2Init();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize MIB!\r\n");
   }

   //Private MIB initialization
   error = privateMibInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize MIB!\r\n");
   }

   //TCP/IP stack initialization
   error = netInit();
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
   }

   //Configure network interfaces
   eth1InterfaceInit();
   eth2InterfaceInit();

   //Get default settings
   snmpAgentGetDefaultSettings(&snmpAgentSettings);
   //Bind SNMP agent to the desired network interface
   snmpAgentSettings.interface = NULL;
   //Minimum version accepted by the SNMP agent
   snmpAgentSettings.versionMin = SNMP_VERSION_1;
   //Maximum version accepted by the SNMP agent
   snmpAgentSettings.versionMax = SNMP_VERSION_2C;

#if (SNMP_V3_SUPPORT == ENABLED)
   //Maximum version accepted by the SNMP agent
   snmpAgentSettings.versionMax = SNMP_VERSION_3;
   //Random data generation callback function
   snmpAgentSettings.randCallback = snmpAgentRandCallback;
#endif

   //SNMP agent initialization
   error = snmpAgentInit(&snmpAgentContext, &snmpAgentSettings);
   //Failed to initialize SNMP agent?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SNMP agent!\r\n");
   }

   //Load standard MIB-II
   snmpAgentLoadMib(&snmpAgentContext, &mib2Module);
   //Load private MIB
   snmpAgentLoadMib(&snmpAgentContext, &privateMibModule);

   //Convert enterprise OID from string representation
   oidFromString(APP_SNMP_ENTERPRISE_OID, oid, sizeof(oid), &oidLen);
   //Set enterprise OID
   snmpAgentSetEnterpriseOid(&snmpAgentContext, oid, oidLen);

   //Set read-only community string
   snmpAgentCreateCommunity(&snmpAgentContext, "public",
      SNMP_ACCESS_READ_ONLY);

   //Set read-write community string
   snmpAgentCreateCommunity(&snmpAgentContext, "private",
      SNMP_ACCESS_READ_WRITE);

#if (SNMP_V3_SUPPORT == ENABLED)
   //The first part of the context engine ID is the enterprise number
   contextEngine[0] = 0x80 | ((APP_SNMP_PRIVATE_ENTERPRISE_NUMBER >> 24) & 0x7F);
   contextEngine[1] = (APP_SNMP_PRIVATE_ENTERPRISE_NUMBER >> 16) & 0xFF;
   contextEngine[2] = (APP_SNMP_PRIVATE_ENTERPRISE_NUMBER >> 8) & 0xFF;
   contextEngine[3] = APP_SNMP_PRIVATE_ENTERPRISE_NUMBER & 0xFF;

   //The format value 3 indicates a MAC address
   contextEngine[4] = 0x03;

   //Append MAC address
   netGetMacAddr(&netInterface[0], &macAddr);
   macCopyAddr(contextEngine + 5, &macAddr);

   //Set context engine ID
   snmpAgentSetContextEngine(&snmpAgentContext, contextEngine,
      sizeof(contextEngine));

   //Add a new user
   snmpAgentCreateUser(&snmpAgentContext, "usr-md5-none",
      SNMP_ACCESS_READ_WRITE, SNMP_KEY_FORMAT_TEXT,
      SNMP_AUTH_PROTOCOL_MD5, "authkey1",
      SNMP_PRIV_PROTOCOL_NONE, "");

   //Add a new user
   snmpAgentCreateUser(&snmpAgentContext, "usr-md5-des",
      SNMP_ACCESS_READ_WRITE, SNMP_KEY_FORMAT_TEXT,
      SNMP_AUTH_PROTOCOL_MD5, "authkey1",
      SNMP_PRIV_PROTOCOL_DES, "privkey1");
#endif

   //Start SNMP agent
   error = snmpAgentStart(&snmpAgentContext);
   //Failed to start SNMP agent?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SNMP agent!\r\n");
   }

   //Configure timer
   TIM6_Init();

   //Endless loop
   while(1)
   {
      //Handle TCP/IP events
      netTask();
      //Handle SNMP agent events
      snmpAgentTask(&snmpAgentContext);
      //LED blinking task
      ledTask();
   }
}


/**
 * @brief First Ethernet interface initialization
 **/

error_t eth1InterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF1_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF1_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the first network interface
   interface = &netInterface[0];

   //Set interface name
   netSetInterfaceName(interface, APP_IF1_NAME);
   //Set host name
   netSetHostname(interface, APP_IF1_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF1_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant MAC driver
   netSetDriver(interface, &stm32mp13xxEth1Driver);
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &lan8742PhyDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF1_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[0], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[0]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF1_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF1_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF1_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF1_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF1_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF1_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext[0], &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[0]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF1_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Second Ethernet interface initialization
 **/

error_t eth2InterfaceInit(void)
{
   error_t error;
   NetInterface *interface;
   MacAddr macAddr;
#if (APP_IF2_USE_DHCP_CLIENT == DISABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (APP_IF2_USE_SLAAC == DISABLED)
   Ipv6Addr ipv6Addr;
#endif

   //Configure the second network interface
   interface = &netInterface[1];

   //Set interface name
   netSetInterfaceName(interface, APP_IF2_NAME);
   //Set host name
   netSetHostname(interface, APP_IF2_HOST_NAME);
   //Set host MAC address
   macStringToAddr(APP_IF2_MAC_ADDR, &macAddr);
   netSetMacAddr(interface, &macAddr);
   //Select the relevant MAC driver
   netSetDriver(interface, &stm32mp13xxEth2Driver);
   //Select the relevant PHY driver
   netSetPhyDriver(interface, &lan8742PhyDriver);

   //Initialize network interface
   error = netConfigInterface(interface);
   //Any error to report?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to configure interface %s!\r\n", interface->name);
      //Exit immediately
      return error;
   }

#if (IPV4_SUPPORT == ENABLED)
#if (APP_IF2_USE_DHCP_CLIENT == ENABLED)
   //Get default settings
   dhcpClientGetDefaultSettings(&dhcpClientSettings);
   //Set the network interface to be configured by DHCP
   dhcpClientSettings.interface = interface;
   //Disable rapid commit option
   dhcpClientSettings.rapidCommit = FALSE;

   //DHCP client initialization
   error = dhcpClientInit(&dhcpClientContext[1], &dhcpClientSettings);
   //Failed to initialize DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
      //Exit immediately
      return error;
   }

   //Start DHCP client
   error = dhcpClientStart(&dhcpClientContext[1]);
   //Failed to start DHCP client?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start DHCP client!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set IPv4 host address
   ipv4StringToAddr(APP_IF2_IPV4_HOST_ADDR, &ipv4Addr);
   ipv4SetHostAddr(interface, ipv4Addr);

   //Set subnet mask
   ipv4StringToAddr(APP_IF2_IPV4_SUBNET_MASK, &ipv4Addr);
   ipv4SetSubnetMask(interface, ipv4Addr);

   //Set default gateway
   ipv4StringToAddr(APP_IF2_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
   ipv4SetDefaultGateway(interface, ipv4Addr);

   //Set primary and secondary DNS servers
   ipv4StringToAddr(APP_IF2_IPV4_PRIMARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 0, ipv4Addr);
   ipv4StringToAddr(APP_IF2_IPV4_SECONDARY_DNS, &ipv4Addr);
   ipv4SetDnsServer(interface, 1, ipv4Addr);
#endif
#endif

#if (IPV6_SUPPORT == ENABLED)
#if (APP_IF2_USE_SLAAC == ENABLED)
   //Get default settings
   slaacGetDefaultSettings(&slaacSettings);
   //Set the network interface to be configured
   slaacSettings.interface = interface;

   //SLAAC initialization
   error = slaacInit(&slaacContext[1], &slaacSettings);
   //Failed to initialize SLAAC?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize SLAAC!\r\n");
      //Exit immediately
      return error;
   }

   //Start IPv6 address autoconfiguration process
   error = slaacStart(&slaacContext[1]);
   //Failed to start SLAAC process?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start SLAAC!\r\n");
      //Exit immediately
      return error;
   }
#else
   //Set link-local address
   ipv6StringToAddr(APP_IF2_IPV6_LINK_LOCAL_ADDR, &ipv6Addr);
   ipv6SetLinkLocalAddr(interface, &ipv6Addr);
#endif
#endif

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief FSM state change callback
 * @param[in] context Pointer to the DHCP client context
 * @param[in] interface interface Underlying network interface
 * @param[in] state New DHCP state
 **/

void dhcpClientStateChangeCallback(DhcpClientContext *context,
   NetInterface *interface, DhcpState state)
{
   error_t error;
   IpAddr destIpAddr;
   SnmpTrapObject trapObjects[2];

   //DHCP process complete?
   if(state == DHCP_STATE_BOUND && dhcpPrevState == DHCP_STATE_ANNOUNCING)
   {
      //Destination IP address
      ipStringToAddr(APP_SNMP_TRAP_DEST_IP_ADDR, &destIpAddr);

      //Add the ifDescr.1 object to the variable binding list of the message
      oidFromString("1.3.6.1.2.1.2.2.1.2.1", trapObjects[0].oid,
         SNMP_MAX_OID_SIZE, &trapObjects[0].oidLen);

      //Add the ifPhysAddress.1 object to the variable binding list of the message
      oidFromString("1.3.6.1.2.1.2.2.1.6.1", trapObjects[1].oid,
         SNMP_MAX_OID_SIZE, &trapObjects[1].oidLen);

      //Send a SNMP trap
      error = snmpAgentSendTrap(&snmpAgentContext, &destIpAddr, SNMP_VERSION_2C,
         "public", SNMP_TRAP_LINK_UP, 0, trapObjects, 2);

      //Failed to send trap message?
      if(error)
      {
         //Debug message
         TRACE_ERROR("Failed to send SNMP trap message!\r\n");
      }
   }

   //Save current state
   dhcpPrevState = state;
}


/**
 * @brief Random data generation callback function
 * @param[out] data Buffer where to store the random data
 * @param[in] length Number of bytes that are required
 * @return Error code
 **/

error_t snmpAgentRandCallback(uint8_t *data, size_t length)
{
   //Generate some random data
   return trngGetRandomData(data, length);
}
