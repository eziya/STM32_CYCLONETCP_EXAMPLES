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
#include "stm32h7xx.h"
#include "stm32h7xx_hal.h"
#include "stm32h7xx_nucleo.h"
#include "core/net.h"
#include "drivers/mac/stm32h7xx_eth_driver.h"
#include "drivers/phy/lan8742_driver.h"
#include "dhcp/dhcp_client.h"
#include "ipv6/slaac.h"
#include "acme/acme_client.h"
#include "http/http_server.h"
#include "http/mime.h"
#include "tls.h"
#include "tls_cipher_suites.h"
#include "pkix/pem_key_export.h"
#include "hardware/stm32h7xx/stm32h7xx_crypto.h"
#include "rng/trng.h"
#include "rng/hmac_drbg.h"
#include "path.h"
#include "date_time.h"
#include "resource_manager.h"
#include "debug.h"

//Ethernet interface configuration
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "acme-client-demo"
#define APP_MAC_ADDR "00-AB-CD-EF-07-53"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.0.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.0.254"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_USE_SLAAC ENABLED
#define APP_IPV6_LINK_LOCAL_ADDR "fe80::753"
#define APP_IPV6_PREFIX "2001:db8::"
#define APP_IPV6_PREFIX_LENGTH 64
#define APP_IPV6_GLOBAL_ADDR "2001:db8::753"
#define APP_IPV6_ROUTER "fe80::1"
#define APP_IPV6_PRIMARY_DNS "2001:4860:4860::8888"
#define APP_IPV6_SECONDARY_DNS "2001:4860:4860::8844"

//Application configuration
//#define APP_ACME_SERVER_NAME "acme-v02.api.letsencrypt.org"
#define APP_ACME_SERVER_NAME "acme-staging-v02.api.letsencrypt.org"
#define APP_ACME_SERVER_PORT 443
#define APP_ACME_DIRECTORY_URI "/directory"
#define APP_ACME_ACCOUNT_CONTACT "test@example.com"
#define APP_ACME_DOMAIN_NAME "acme-demo.oryx-embedded.com"
#define APP_ACME_SET_TRUSTED_CA_LIST DISABLED

#define APP_HTTP_MAX_CONNECTIONS 4
#define APP_HTTP_SET_CIPHER_SUITES ENABLED

//List of preferred ciphersuites
const uint16_t cipherSuites[] =
{
   TLS_CHACHA20_POLY1305_SHA256,
   TLS_AES_128_GCM_SHA256,
   TLS_AES_256_GCM_SHA384,
   TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256,
   TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256,
   TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,
   TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256,
   TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384,
   TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384,
   TLS_ECDHE_ECDSA_WITH_AES_128_CBC_SHA,
   TLS_ECDHE_RSA_WITH_AES_128_CBC_SHA,
   TLS_ECDHE_ECDSA_WITH_AES_256_CBC_SHA,
   TLS_ECDHE_RSA_WITH_AES_256_CBC_SHA,
   TLS_DHE_RSA_WITH_AES_128_GCM_SHA256,
   TLS_DHE_RSA_WITH_AES_256_GCM_SHA384,
   TLS_DHE_RSA_WITH_AES_128_CBC_SHA,
   TLS_DHE_RSA_WITH_AES_256_CBC_SHA,
   TLS_RSA_WITH_AES_128_GCM_SHA256,
   TLS_RSA_WITH_AES_256_GCM_SHA384,
   TLS_RSA_WITH_AES_128_CBC_SHA,
   TLS_RSA_WITH_AES_256_CBC_SHA,
   TLS_RSA_WITH_3DES_EDE_CBC_SHA
};

//Global variables
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
SlaacSettings slaacSettings;
SlaacContext slaacContext;
AcmeClientContext acmeClientContext;
HttpServerSettings httpServerSettings;
HttpServerContext httpServerContext;
HttpConnection httpConnections[APP_HTTP_MAX_CONNECTIONS];
TlsCache *tlsCache;
HmacDrbgContext hmacDrbgContext;
uint8_t seed[48];
char_t accountPublicKey[256];
char_t accountPrivateKey[256];
char_t certPublicKey[256];
char_t certPrivateKey[256];
char_t certChain[6144];

//Forward declaration of functions
error_t httpServerTlsInitCallback(HttpConnection *connection,
   TlsContext *tlsContext);

error_t httpServerAlpnCallback(TlsContext *context,
   const char_t *selectedProtocol);

error_t httpServerCgiCallback(HttpConnection *connection,
   const char_t *param);

error_t httpServerRequestCallback(HttpConnection *connection,
   const char_t *uri);

error_t httpServerUriNotFoundCallback(HttpConnection *connection,
   const char_t *uri);


/**
 * @brief System clock configuration
 **/

void SystemClock_Config(void)
{
   RCC_OscInitTypeDef RCC_OscInitStruct = {0};
   RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
   RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct = {0};

   //Supply configuration update enable
   HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

   //Configure voltage scaling
   __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
   while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY));

   //Enable HSE oscillator and activate PLL with HSE as source
   RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
   RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
   RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
   RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
   RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
   RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
   RCC_OscInitStruct.PLL.PLLM = 4;
   RCC_OscInitStruct.PLL.PLLN = 400;
   RCC_OscInitStruct.PLL.PLLFRACN = 0;
   RCC_OscInitStruct.PLL.PLLP = 2;
   RCC_OscInitStruct.PLL.PLLR = 2;
   RCC_OscInitStruct.PLL.PLLQ = 4;
   RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
   RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;

   HAL_RCC_OscConfig(&RCC_OscInitStruct);

   //Select PLL as system clock source and configure bus clocks dividers
   RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
      RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_PCLK1 |
      RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_D3PCLK1;

   RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
   RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
   RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
   RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
   RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
   RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
   RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

   HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);

   //Select clock source for RNG peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_RNG;
   RCC_PeriphClkInitStruct.RngClockSelection = RCC_RNGCLKSOURCE_PLL;

   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);

   //Enable CSI clock
   __HAL_RCC_CSI_ENABLE();
   //Enable SYSCFG clock
   __HAL_RCC_SYSCFG_CLK_ENABLE() ;

   //Enable the I/O compensation cell
   HAL_EnableCompensationCell();
}


/**
 * @brief MPU configuration
 **/

void MPU_Config(void)
{
   MPU_Region_InitTypeDef MPU_InitStruct;

   //Disable MPU
   HAL_MPU_Disable();

   //AHB SRAM3 (no cache)
   MPU_InitStruct.Enable = MPU_REGION_ENABLE;
   MPU_InitStruct.Number = MPU_REGION_NUMBER0;
   MPU_InitStruct.BaseAddress = 0x30040000;
   MPU_InitStruct.Size = MPU_REGION_SIZE_32KB;
   MPU_InitStruct.SubRegionDisable = 0;
   MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
   MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
   MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;
   MPU_InitStruct.IsShareable = MPU_ACCESS_SHAREABLE;
   MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
   MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
   HAL_MPU_ConfigRegion(&MPU_InitStruct);

   //Enable MPU
   HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}


/**
 * @brief TLS initialization callback
 * @param[in] context Pointer to the HTTP client context
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t acmeTestTlsInitCallback(HttpClientContext *context,
   TlsContext *tlsContext)
{
   error_t error;

   //Check parameters
   if(context == NULL || tlsContext == NULL)
      return ERROR_INVALID_PARAMETER;

   //Debug message
   TRACE_INFO("ACME Client: TLS initialization callback\r\n");

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
   //Any error to report?
   if(error)
      return error;

   //Set the fully qualified domain name of the server
   error = tlsSetServerName(tlsContext, APP_ACME_SERVER_NAME);
   //Any error to report?
   if(error)
      return error;

#if (APP_ACME_SET_TRUSTED_CA_LIST == ENABLED)
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
 * @brief ACME account key pair generation
 * @return Error code
 **/

error_t acmeTestGenerateAccountKeys(void)
{
   error_t error;
   size_t n;
   EcPrivateKey privateKey;
   EcPublicKey publicKey;

   //Initialize EC key pair
   ecInitPrivateKey(&privateKey);
   ecInitPublicKey(&publicKey);

   //Start of exception handling block
   do
   {
      //Generate an EC key pair
      error = ecGenerateKeyPair(HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext,
         SECP256R1_CURVE, &privateKey, &publicKey);
      //Any error to report?
      if(error)
         break;

      //Export the EC private key to PEM format
      error = pemExportEcPrivateKey(&privateKey, accountPrivateKey, &n,
         PEM_PRIVATE_KEY_FORMAT_DEFAULT);
      //Any error to report?
      if(error)
         break;

      //Dump private key (for debugging purpose only)
      TRACE_INFO("Account private key (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n", accountPrivateKey);

      //Export the EC public key to PEM format
      error = pemExportEcPublicKey(&publicKey, accountPublicKey, &n,
         PEM_PUBLIC_KEY_FORMAT_DEFAULT);
      //Any error to report?
      if(error)
         break;

      //Dump public key
      TRACE_INFO("Account public key (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n", accountPublicKey);

      //End of exception handling block
   } while(0);

   //Release EC key pair
   ecFreePrivateKey(&privateKey);
   ecFreePublicKey(&publicKey);

   //Return status code
   return error;
}


/**
 * @brief Certificate key pair generation
 * @return Error code
 **/

error_t acmeTestGenerateCertKeys(void)
{
   error_t error;
   size_t n;
   EcPrivateKey privateKey;
   EcPublicKey publicKey;

   //Initialize EC key pair
   ecInitPrivateKey(&privateKey);
   ecInitPublicKey(&publicKey);

   //Start of exception handling block
   do
   {
      //Generate an EC key pair
      error = ecGenerateKeyPair(HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext,
         SECP256R1_CURVE, &privateKey, &publicKey);
      //Any error to report?
      if(error)
         break;

      //Export the EC private key to PEM format
      error = pemExportEcPrivateKey(&privateKey, certPrivateKey, &n,
         PEM_PRIVATE_KEY_FORMAT_DEFAULT);
      //Any error to report?
      if(error)
         break;

      //Dump private key (for debugging purpose only)
      TRACE_INFO("Certificate private key (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n", certPrivateKey);

      //Export the EC public key to PEM format
      error = pemExportEcPublicKey(&publicKey, certPublicKey, &n,
         PEM_PUBLIC_KEY_FORMAT_DEFAULT);
      //Any error to report?
      if(error)
         break;

      //Dump public key
      TRACE_INFO("Certificate public key (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n", certPublicKey);

      //End of exception handling block
   } while(0);

   //Release EC key pair
   ecFreePrivateKey(&privateKey);
   ecFreePublicKey(&publicKey);

   //Return status code
   return error;
}


/**
 * @brief Create a new ACME account
 * @return Error code
 **/

error_t acmeTestCreateAccount(void)
{
   error_t error;
   IpAddr serverIpAddr;
   AcmeAccountParams accountParams;

   //Start of exception handling block
   do
   {
      //Resolve ACME server host name
      error = getHostByName(NULL, APP_ACME_SERVER_NAME, &serverIpAddr, 0);
      //Any error to report?
      if(error)
         break;

      //Establish connection with the ACME server
      error = acmeClientConnect(&acmeClientContext, &serverIpAddr,
         APP_ACME_SERVER_PORT);
      //Any error to report?
      if(error)
         break;

      //Initialize account parameters
      memset(&accountParams, 0, sizeof(AcmeAccountParams));

      //Set ACME account parameters
      accountParams.numContacts = 1;
      accountParams.contacts[0] = APP_ACME_ACCOUNT_CONTACT;
      accountParams.termsOfServiceAgreed = TRUE;
      accountParams.publicKey = accountPublicKey;
      accountParams.publicKeyLen = strlen(accountPublicKey);
      accountParams.privateKey = accountPrivateKey;
      accountParams.privateKeyLen = strlen(accountPrivateKey);

      //Create a new ACME account
      error = acmeClientCreateAccount(&acmeClientContext, &accountParams);
      //Any error to report?
      if(error)
         break;

      //Gracefully disconnect from the ACME server
      error = acmeClientDisconnect(&acmeClientContext);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Close the connection with the ACME server
   acmeClientClose(&acmeClientContext);

   //Return status code
   return error;
}


/**
 * @brief Order a new certificate
 * @return Error code
 **/

error_t acmeTestOrderCert(void)
{
   error_t error;
   uint_t i;
   size_t n;
   IpAddr serverIpAddr;
   AcmeOrderParams orderParams;
   AcmeOrderStatus orderStatus;

   //Start of exception handling block
   do
   {
      //Resolve ACME server host name
      error = getHostByName(NULL, APP_ACME_SERVER_NAME, &serverIpAddr, 0);
      //Any error to report?
      if(error)
         break;

      //Establish connection with the ACME server
      error = acmeClientConnect(&acmeClientContext, &serverIpAddr,
         APP_ACME_SERVER_PORT);
      //Any error to report?
      if(error)
         break;

      //Initialize certificate order parameters
      memset(&orderParams, 0, sizeof(AcmeOrderParams));

      //Set certificate order parameters
      orderParams.numDomains = 1;
      orderParams.domains[0].name = APP_ACME_DOMAIN_NAME;
      orderParams.domains[0].challengeType = ACME_CHALLENGE_TYPE_TLS_ALPN_01;
      orderParams.publicKey = certPublicKey;
      orderParams.publicKeyLen = strlen(certPublicKey);
      orderParams.privateKey = certPrivateKey;
      orderParams.privateKeyLen = strlen(certPrivateKey);

      //Create a new certificate
      error = acmeClientCreateOrder(&acmeClientContext, &orderParams);
      //Any error to report?
      if(error)
         break;

      //Default order status
      orderStatus = ACME_ORDER_STATUS_NONE;

      //Poll the status of the order
      for(i = 0; i < 30; i++)
      {
         //Get the current status of the order
         error = acmeClientPollOrderStatus(&acmeClientContext, &orderStatus);
         //Any error to report?
         if(error)
            break;

         //Once the certificate is issued, the order enters the "valid" state.
         //If an error occurs, the order moves to the "invalid" state
         if(orderStatus == ACME_ORDER_STATUS_VALID ||
            orderStatus == ACME_ORDER_STATUS_INVALID)
         {
            break;
         }

         //Polling delay
         osDelayTask(2000);
      }

      //Check the status of the order
      if(orderStatus != ACME_ORDER_STATUS_VALID)
      {
         error = ERROR_INVALID_STATUS;
         break;
      }

      //Download the certificate from the ACME server
      error = acmeClientDownloadCertificate(&acmeClientContext, certChain,
         sizeof(certChain) - 1, &n);
      //Any error to report?
      if(error)
         break;

      //Properly terminate the certificate chain with a NULL character
      certChain[n] = '\0';

      //Debug message
      TRACE_INFO("Certificate chain (%" PRIuSIZE " bytes):\r\n", n);
      TRACE_INFO("%s\r\n\r\n", certChain);

      //Gracefully disconnect from the ACME server
      error = acmeClientDisconnect(&acmeClientContext);
      //Any error to report?
      if(error)
         break;

      //End of exception handling block
   } while(0);

   //Close the connection with the ACME server
   acmeClientClose(&acmeClientContext);

   //Return status code
   return error;
}


/**
 * @brief ACME task
 * @param[in] param Unused parameter
 **/

void acmeTestTask(void *param)
{
   error_t error;
   uint_t i;

   //Debug message
   TRACE_INFO("Generating account key pair...\r\n");

   //Generate account key pair
   error = acmeTestGenerateAccountKeys();
   //Check status code
   if(error)
   {
      //Debug message
      TRACE_INFO("Failed to generate account key pair!\r\n");
   }

   //Debug message
   TRACE_INFO("Generating certificate key pair...\r\n");

   //Generate certificate key pair
   error = acmeTestGenerateCertKeys();
   //Check status code
   if(error)
   {
      //Debug message
      TRACE_INFO("Failed to generate certificate key pair!\r\n");
   }

   //Initialize ACME client context
   acmeClientInit(&acmeClientContext);

   //Register TLS initialization callback
   acmeClientRegisterTlsInitCallback(&acmeClientContext,
      acmeTestTlsInitCallback);

   //Set the PRNG algorithm to be used
   acmeClientSetPrng(&acmeClientContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);

   //Set communication timeout
   acmeClientSetTimeout(&acmeClientContext, 30000);
   //Set the domain name of the ACME server
   acmeClientSetHost(&acmeClientContext, APP_ACME_SERVER_NAME);
   //Set the URI of the directory object
   acmeClientSetDirectoryUri(&acmeClientContext, APP_ACME_DIRECTORY_URI);

   //Account creation process
   do
   {
      //Create a new ACME account
      error = acmeTestCreateAccount();

      //Check status code
      if(error)
      {
         //Delay between unsuccessful attempts
         osDelayTask(10 * 1000);
      }

      //Check whether the ACME account has been successfully created
   } while(error);

   //Certificate order process
   while(1)
   {
      //Order a new certificate
      error = acmeTestOrderCert();

      //Check status code
      if(!error)
      {
         //The certificate is renewed every month
         for(i = 0; i < 30; i++)
         {
            osDelayTask(86400 * 1000);
         }
      }
      else
      {
         //Delay between unsuccessful attempts
         osDelayTask(86400 * 1000);
      }
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

   //MPU configuration
   MPU_Config();
   //HAL library initialization
   HAL_Init();
   //Configure the system clock
   SystemClock_Config();

   //Enable I-cache and D-cache
   SCB_EnableICache();
   SCB_EnableDCache();

   //Initialize kernel
   osInitKernel();
   //Configure debug UART
   debugInit(115200);

   //Start-up message
   TRACE_INFO("\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("*** CycloneACME ACME Client Demo ***\r\n");
   TRACE_INFO("************************************\r\n");
   TRACE_INFO("Copyright: 2010-2025 Oryx Embedded SARL\r\n");
   TRACE_INFO("Compiled: %s %s\r\n", __DATE__, __TIME__);
   TRACE_INFO("Target: STM32H753\r\n");
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
   error = stm32h7xxCryptoInit();
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
   netSetDriver(interface, &stm32h7xxEthDriver);
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

   //TLS session cache initialization
   tlsCache = tlsInitCache(8);
   //Any error to report?
   if(tlsCache == NULL)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize TLS session cache!\r\n");
   }

   //Get default settings
   httpServerGetDefaultSettings(&httpServerSettings);
   //Bind HTTP server to the desired interface
   httpServerSettings.interface = &netInterface[0];
   //Listen to port 443
   httpServerSettings.port = HTTPS_PORT;
   //Maximum length of the pending connection queue
   httpServerSettings.backlog = 2;
   //Client connections
   httpServerSettings.maxConnections = APP_HTTP_MAX_CONNECTIONS;
   httpServerSettings.connections = httpConnections;
   //Specify the server's root directory
   strcpy(httpServerSettings.rootDirectory, "/www/");
   //Set default home page
   strcpy(httpServerSettings.defaultDocument, "index.shtm");
   //Callback functions
   httpServerSettings.tlsInitCallback = httpServerTlsInitCallback;
   httpServerSettings.cgiCallback = httpServerCgiCallback;
   httpServerSettings.requestCallback = httpServerRequestCallback;
   httpServerSettings.uriNotFoundCallback = httpServerUriNotFoundCallback;

   //HTTP server initialization
   error = httpServerInit(&httpServerContext, &httpServerSettings);
   //Failed to initialize HTTP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to initialize HTTP server!\r\n");
   }

   //Start HTTP server
   error = httpServerStart(&httpServerContext);
   //Failed to start HTTP server?
   if(error)
   {
      //Debug message
      TRACE_ERROR("Failed to start HTTP server!\r\n");
   }

   //Set task parameters
   taskParams = OS_TASK_DEFAULT_PARAMS;
   taskParams.stackSize = 500;
   taskParams.priority = OS_TASK_PRIORITY_NORMAL;

   //Create ACME task
   taskId = osCreateTask("ACME", acmeTestTask, NULL, &taskParams);
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


/**
 * @brief TLS initialization callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] tlsContext Pointer to the TLS context
 * @return Error code
 **/

error_t httpServerTlsInitCallback(HttpConnection *connection,
   TlsContext *tlsContext)
{
   error_t error;

   //Set TX and RX buffer size
   error = tlsSetBufferSize(tlsContext, 6144, 2048);
   //Any error to report?
   if(error)
      return error;

   //Set the PRNG algorithm to be used
   error = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
   //Any error to report?
   if(error)
      return error;

   //Session cache that will be used to save/resume TLS sessions
   error = tlsSetCache(tlsContext, tlsCache);
   //Any error to report?
   if(error)
      return error;

   //Client authentication is not required
   error = tlsSetClientAuthMode(tlsContext, TLS_CLIENT_AUTH_NONE);
   //Any error to report?
   if(error)
      return error;

   //Enable secure renegotiation
   error = tlsEnableSecureRenegotiation(tlsContext, TRUE);
   //Any error to report?
   if(error)
      return error;

   //Set the list of supported ALPN protocols
   error = tlsSetAlpnProtocolList(tlsContext, "acme-tls/1");
   //Any error to report?
   if(error)
      return error;

   //Allow unknown ALPN protocols
   error = tlsAllowUnknownAlpnProtocols(tlsContext, TRUE);
   //Any error to report?
   if(error)
      return error;

   //Register ALPN callback function
   error = tlsSetAlpnCallback(tlsContext, httpServerAlpnCallback);
   //Any error to report?
   if(error)
      return error;

#if (APP_HTTP_SET_CIPHER_SUITES == ENABLED)
   //Preferred cipher suite list
   error = tlsSetCipherSuites(tlsContext, cipherSuites, arraysize(cipherSuites));
   //Any error to report?
   if(error)
      return error;
#endif

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief TLS ALPN callback function
 * @param[in] context Pointer to the TLS context
 * @param[in] selectedProtocol Pointer to the selected ALPN protocol
 * @return Error code
 **/

error_t httpServerAlpnCallback(TlsContext *context,
   const char_t *selectedProtocol)
{
   error_t error;
   size_t certLen;
   size_t privateKeyLen;
   const char_t *cert;
   const char_t *privateKey;
   const char_t *serverName;

   //Initialize pointer
   cert = NULL;

   //Check whether the "acme-tls/1" application-layer protocol has been
   //negotiated
   if(selectedProtocol != NULL && !strcmp(selectedProtocol, "acme-tls/1"))
   {
      //The ACME server must provide a SNI extension containing the domain name
      //being validated
      serverName = tlsGetServerName(context);

      //Valid domain name?
      if(serverName != NULL)
      {
         //Debug message
         TRACE_INFO("### TLS-ALPN challenge validation (%s) ###\r\n",
            serverName);

         //Get the TLS-ALPN certificate that matches the specified identifier
         cert = acmeClientGetTlsAlpnCertificate(&acmeClientContext, serverName);
      }
   }

   //Select the relevant certificate
   if(cert != NULL)
   {
      //Select the TLS-ALPN certificate
      certLen = strlen(cert);
      privateKey = certPrivateKey;
      privateKeyLen = strlen(certPrivateKey);
   }
   else
   {
      //Select the active certificate
      cert = certChain;
      certLen = strlen(certChain);
      privateKey = certPrivateKey;
      privateKeyLen = strlen(certPrivateKey);
   }

   //Load server's certificate
   error = tlsLoadCertificate(context, 0, cert, certLen, privateKey,
      privateKeyLen, NULL);
   //Any error to report?
   if(error)
      return error;

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief CGI callback function
 * @param[in] connection Handle referencing a client connection
 * @param[in] param NULL-terminated string that contains the CGI parameter
 * @return Error code
 **/

error_t httpServerCgiCallback(HttpConnection *connection,
   const char_t *param)
{
   static uint_t pageCounter = 0;
   uint_t length;
   MacAddr macAddr;
#if (IPV4_SUPPORT == ENABLED)
   Ipv4Addr ipv4Addr;
#endif
#if (IPV6_SUPPORT == ENABLED)
   uint_t n;
   Ipv6Addr ipv6Addr;
#endif

   //Underlying network interface
   NetInterface *interface = connection->socket->interface;

   //Check parameter name
   if(!strcasecmp(param, "PAGE_COUNTER"))
   {
      pageCounter++;
      sprintf(connection->buffer, "%u time%s", pageCounter, (pageCounter >= 2) ? "s" : "");
   }
   else if(!strcasecmp(param, "BOARD_NAME"))
   {
      strcpy(connection->buffer, "Nucleo-H753ZI");
   }
   else if(!strcasecmp(param, "SYSTEM_TIME"))
   {
      systime_t time = osGetSystemTime();
      formatSystemTime(time, connection->buffer);
   }
   else if(!strcasecmp(param, "MAC_ADDR"))
   {
      netGetMacAddr(interface, &macAddr);
      macAddrToString(&macAddr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_ADDR"))
   {
      ipv4GetHostAddr(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "SUBNET_MASK"))
   {
      ipv4GetSubnetMask(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "DEFAULT_GATEWAY"))
   {
      ipv4GetDefaultGateway(interface, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_PRIMARY_DNS"))
   {
      ipv4GetDnsServer(interface, 0, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV4_SECONDARY_DNS"))
   {
      ipv4GetDnsServer(interface, 1, &ipv4Addr);
      ipv4AddrToString(ipv4Addr, connection->buffer);
   }
#if (IPV6_SUPPORT == ENABLED)
   else if(!strcasecmp(param, "LINK_LOCAL_ADDR"))
   {
      ipv6GetLinkLocalAddr(interface, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "GLOBAL_ADDR"))
   {
      ipv6GetGlobalAddr(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_PREFIX"))
   {
      ipv6GetPrefix(interface, 0, &ipv6Addr, &n);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
      length = strlen(connection->buffer);
      sprintf(connection->buffer + length, "/%u", n);
   }
   else if(!strcasecmp(param, "ROUTER"))
   {
      ipv6GetDefaultRouter(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_PRIMARY_DNS"))
   {
      ipv6GetDnsServer(interface, 0, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
   else if(!strcasecmp(param, "IPV6_SECONDARY_DNS"))
   {
      ipv6GetDnsServer(interface, 1, &ipv6Addr);
      ipv6AddrToString(&ipv6Addr, connection->buffer);
   }
#endif
   else
   {
      return ERROR_INVALID_TAG;
   }

   //Get the length of the resulting string
   length = strlen(connection->buffer);

   //Send the contents of the specified environment variable
   return httpWriteStream(connection, connection->buffer, length);
}


/**
 * @brief HTTP request callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] uri NULL-terminated string containing the path to the requested resource
 * @return Error code
 **/

error_t httpServerRequestCallback(HttpConnection *connection,
   const char_t *uri)
{
   //Not implemented
   return ERROR_NOT_FOUND;
}


/**
 * @brief URI not found callback
 * @param[in] connection Handle referencing a client connection
 * @param[in] uri NULL-terminated string containing the path to the requested resource
 * @return Error code
 **/

error_t httpServerUriNotFoundCallback(HttpConnection *connection,
   const char_t *uri)
{
   //Not implemented
   return ERROR_NOT_FOUND;
}
