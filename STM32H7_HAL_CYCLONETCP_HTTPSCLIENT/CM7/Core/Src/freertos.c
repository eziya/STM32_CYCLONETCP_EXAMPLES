/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * File Name          : freertos.c
 * Description        : Code for freertos applications
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "core/net.h"
#include "http/http_client.h"
#include "tls.h"
#include "tls_cipher_suites.h"
#include "rng/hmac_drbg.h"
#include "debug.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define APP_HTTP_SERVER_NAME "www.httpbin.org"
#define APP_HTTP_SERVER_PORT 443
#define APP_HTTP_URI "/anything"

#define APP_SET_CIPHER_SUITES ENABLED
#define APP_SET_SERVER_NAME ENABLED
#define APP_SET_TRUSTED_CA_LIST ENABLED
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern UART_HandleTypeDef huart1;
extern HmacDrbgContext hmacDrbgContext;

const uint16_t cipherSuites[] =
{
    // TLS 1.3 Suites
    TLS_CHACHA20_POLY1305_SHA256,
    TLS_AES_256_GCM_SHA384,
    TLS_AES_128_GCM_SHA256,

    // TLS 1.2 Suites
    TLS_ECDHE_ECDSA_WITH_CHACHA20_POLY1305_SHA256,
    TLS_ECDHE_RSA_WITH_CHACHA20_POLY1305_SHA256,
    TLS_ECDHE_ECDSA_WITH_AES_256_GCM_SHA384,
    TLS_ECDHE_RSA_WITH_AES_256_GCM_SHA384,
    TLS_ECDHE_ECDSA_WITH_AES_128_GCM_SHA256,
    TLS_ECDHE_RSA_WITH_AES_128_GCM_SHA256,
};

const char trustedCaList[] =
{
    "-----BEGIN CERTIFICATE-----"
    "MIID7zCCAtegAwIBAgIBADANBgkqhkiG9w0BAQsFADCBmDELMAkGA1UEBhMCVVMx"
    "EDAOBgNVBAgTB0FyaXpvbmExEzARBgNVBAcTClNjb3R0c2RhbGUxJTAjBgNVBAoT"
    "HFN0YXJmaWVsZCBUZWNobm9sb2dpZXMsIEluYy4xOzA5BgNVBAMTMlN0YXJmaWVs"
    "ZCBTZXJ2aWNlcyBSb290IENlcnRpZmljYXRlIEF1dGhvcml0eSAtIEcyMB4XDTA5"
    "MDkwMTAwMDAwMFoXDTM3MTIzMTIzNTk1OVowgZgxCzAJBgNVBAYTAlVTMRAwDgYD"
    "VQQIEwdBcml6b25hMRMwEQYDVQQHEwpTY290dHNkYWxlMSUwIwYDVQQKExxTdGFy"
    "ZmllbGQgVGVjaG5vbG9naWVzLCBJbmMuMTswOQYDVQQDEzJTdGFyZmllbGQgU2Vy"
    "dmljZXMgUm9vdCBDZXJ0aWZpY2F0ZSBBdXRob3JpdHkgLSBHMjCCASIwDQYJKoZI"
    "hvcNAQEBBQADggEPADCCAQoCggEBANUMOsQq+U7i9b4Zl1+OiFOxHz/Lz58gE20p"
    "OsgPfTz3a3Y4Y9k2YKibXlwAgLIvWX/2h/klQ4bnaRtSmpDhcePYLQ1Ob/bISdm2"
    "8xpWriu2dBTrz/sm4xq6HZYuajtYlIlHVv8loJNwU4PahHQUw2eeBGg6345AWh1K"
    "Ts9DkTvnVtYAcMtS7nt9rjrnvDH5RfbCYM8TWQIrgMw0R9+53pBlbQLPLJGmpufe"
    "hRhJfGZOozptqbXuNC66DQO4M99H67FrjSXZm86B0UVGMpZwh94CDklDhbZsc7tk"
    "6mFBrMnUVN+HL8cisibMn1lUaJ/8viovxFUcdUBgF4UCVTmLfwUCAwEAAaNCMEAw"
    "DwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMCAQYwHQYDVR0OBBYEFJxfAN+q"
    "AdcwKziIorhtSpzyEZGDMA0GCSqGSIb3DQEBCwUAA4IBAQBLNqaEd2ndOxmfZyMI"
    "bw5hyf2E3F/YNoHN2BtBLZ9g3ccaaNnRbobhiCPPE95Dz+I0swSdHynVv/heyNXB"
    "ve6SbzJ08pGCL72CQnqtKrcgfU28elUSwhXqvfdqlS5sdJ/PHLTyxQGjhdByPq1z"
    "qwubdQxtRbeOlKyWN7Wg0I8VRw7j6IPdj/3vQQF3zCepYoUz8jcI73HPdwbeyBkd"
    "iEDPfUYd/x7H4c7/I9vG+o1VTqkC50cRRj70/b17KSa7qWFiNyi2LSr2EIZkyXCn"
    "0q23KXB56jzaYyWf/Wi3MOxw+3WKt21gZ7IeyLnp2KhvAotnDU0mV3HaIPzBSlCN"
    "sSi6"
    "-----END CERTIFICATE-----"
};

HttpClientContext httpClientContext;

osThreadId_t httpsTaskHandle;
const osThreadAttr_t httpsTask_attributes = {
    .name = "httpsTask",
    .stack_size = 1024 * 4,
    .priority = (osPriority_t) osPriorityNormal,
};

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
    .name = "defaultTask",
    .stack_size = 512 * 4,
    .priority = (osPriority_t) osPriorityNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
error_t httpsClientTlsInitCallback(HttpClientContext *context, TlsContext *tlsContext);
void httpsClientTask(void *argument);
error_t httpsClientTest(void);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
  /* Run time stack overflow checking is performed if
   configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2. This hook function is
   called if a stack overflow is detected. */

  __disable_irq();

  while(1)
  {
    HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
    HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, GPIO_PIN_RESET);
  }
}
/* USER CODE END 4 */

/**
 * @brief  FreeRTOS initialization
 * @param  None
 * @retval None
 */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  httpsTaskHandle = osThreadNew(httpsClientTask, NULL, &httpsTask_attributes);
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
 * @brief  Function implementing the defaultTask thread.
 * @param  argument: Not used
 * @retval None
 */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */
  /* Infinite loop */
  for(;;)
  {
    HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
    osDelay(500);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */
/* https client task */
void httpsClientTask(void *argument)
{
  /* Start HTTPS Task */
  TRACE_INFO("Start HTTPS Task.\r\n");

  for(;;)
  {
    /* When click PC13, initiate HTTPS test */
    if(HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_SET)
    {
      httpsClientTest();
    }

    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
    osDelay(200);
  }
}

/* https initialization callback */
error_t httpsClientTlsInitCallback(HttpClientContext *context, TlsContext *tlsContext)
{
   error_t err;

   TRACE_INFO("HTTPS Client: TLS initialization callback\r\n");

   err = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
   if(err) { return err; }

#if (APP_SET_CIPHER_SUITES == ENABLED)
   err = tlsSetCipherSuites(tlsContext, cipherSuites, arraysize(cipherSuites));
   if(err) { return err; }
#endif

#if (APP_SET_SERVER_NAME == ENABLED)
   err = tlsSetServerName(tlsContext, APP_HTTP_SERVER_NAME);
   if(err) { return err; }
#endif

#if (APP_SET_TRUSTED_CA_LIST == ENABLED)
   err = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList));
   if(err) { return err; }
#endif

   return NO_ERROR;
}

/* https client test */
error_t httpsClientTest(void)
{
  error_t error;
  size_t length;
  uint_t status;
  const char_t *value;
  IpAddr ipAddr;
  char_t buffer[128];

  /* Initialize HTTP client context */
  httpClientInit(&httpClientContext);

  do
  {
    if((error = getHostByName(NULL, APP_HTTP_SERVER_NAME, &ipAddr, 0)) != NO_ERROR)
    {
      TRACE_INFO("getHostByName() failed: %d\r\n", error);
      break;
    }

#if (APP_HTTP_SERVER_PORT == 443)
    if((error = httpClientRegisterTlsInitCallback(&httpClientContext, httpsClientTlsInitCallback)) != NO_ERROR)
    {
      TRACE_INFO("httpClientRegisterTlsInitCallback() failed: %d\r\n", error);
      break;
    }
#endif

    if((error = httpClientSetVersion(&httpClientContext, HTTP_VERSION_1_1)) != NO_ERROR)
    {
      TRACE_INFO("httpClientSetVersion() failed: %d\r\n", error);
      break;
    }

    if((error = httpClientSetTimeout(&httpClientContext, 20000)) != NO_ERROR)
    {
      TRACE_INFO("httpClientSetTimeout() failed: %d\r\n", error);
      break;
    }

    TRACE_INFO("Connecting to HTTP server %s...\r\n", ipAddrToString(&ipAddr, NULL));
    if((error = httpClientConnect(&httpClientContext, &ipAddr, APP_HTTP_SERVER_PORT)) != NO_ERROR)
    {
      TRACE_INFO("httpClientConnect() failed: %d\r\n", error);
      break;
    }

    httpClientCreateRequest(&httpClientContext);
    httpClientSetMethod(&httpClientContext, "POST");
    httpClientSetUri(&httpClientContext, APP_HTTP_URI);

    httpClientAddQueryParam(&httpClientContext, "param1", "value1");
    httpClientAddQueryParam(&httpClientContext, "param2", "value2");

    httpClientAddHeaderField(&httpClientContext, "Host", APP_HTTP_SERVER_NAME);
    httpClientAddHeaderField(&httpClientContext, "User-Agent", "Mozilla/5.0");
    httpClientAddHeaderField(&httpClientContext, "Content-Type", "text/plain");
    httpClientAddHeaderField(&httpClientContext, "Transfer-Encoding", "chunked");

    if((error = httpClientWriteHeader(&httpClientContext)) != NO_ERROR)
    {
      TRACE_INFO("httpClientWriteHeader() failed: %d\r\n", error);
      break;
    }

    if((error = httpClientWriteBody(&httpClientContext, "Hello World!", 12, NULL, 0)) != NO_ERROR)
    {
      TRACE_INFO("httpClientWriteBody() failed: %d\r\n", error);
      break;
    }

    if((error = httpClientReadHeader(&httpClientContext)) != NO_ERROR)
    {
      TRACE_INFO("httpClientReadHeader() failed: %d\r\n", error);
      break;
    }

    status = httpClientGetStatus(&httpClientContext);
    TRACE_INFO("HTTP status code: %u\r\n", status);

    value = httpClientGetHeaderField(&httpClientContext, "Content-Type");
    if(value != NULL)
    {
      TRACE_INFO("Content-Type header field value: %s\r\n", value);
    }
    else
    {
      TRACE_INFO("Content-Type header field not found!\r\n");
    }

    while(!error)
    {
      error = httpClientReadBody(&httpClientContext, buffer, sizeof(buffer) - 1, &length, 0);

      if(!error)
      {
        buffer[length] = '\0';
        TRACE_INFO("%s", buffer);
      }
    }

    TRACE_INFO("\r\n");
    if(error != ERROR_END_OF_STREAM)
    {
      break;
    }

    if((error = httpClientCloseBody(&httpClientContext)) != NO_ERROR)
    {
      TRACE_INFO("httpClientReadHeader() failed: %d\r\n", error);
      break;
    }

    httpClientDisconnect(&httpClientContext);
    TRACE_INFO("Connection closed.\r\n");
  } while(0);


  httpClientDeinit(&httpClientContext);
  return error;
}

/* debug output */
int __io_putchar (int ch)
{
  HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

/**
 * @brief Display the contents of an array
 * @param[in] stream Pointer to a FILE object that identifies an output stream
 * @param[in] prepend String to prepend to the left of each line
 * @param[in] data Pointer to the data array
 * @param[in] length Number of bytes to display
 **/
void debugDisplayArray(FILE *stream, const char_t *prepend, const void *data, size_t length)
{
   uint_t i;

   for(i = 0; i < length; i++)
   {
      //Beginning of a new line?
      if((i % 16) == 0)
      {
         fprintf(stream, "%s", prepend);
      }
      //Display current data byte
      fprintf(stream, "%02" PRIX8 " ", *((uint8_t *) data + i));
      //End of current line?
      if((i % 16) == 15 || i == (length - 1))
      {
         fprintf(stream, "\r\n");
      }
   }
}
/* USER CODE END Application */

