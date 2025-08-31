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
#include "ftp/ftp_client.h"
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
#define APP_FTP_SERVER_NAME "test.rebex.net"
#define APP_FTP_SERVER_PORT 21
#define APP_FTP_LOGIN "demo"
#define APP_FTP_PASSWORD "password"
#define APP_FTP_FILENAME "readme.txt"

#define APP_FTP_IMPLICIT_TLS DISABLED
#define APP_FTP_EXPLICIT_TLS ENABLED
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
    "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"
    "-----END CERTIFICATE-----"
};

FtpClientContext ftpClientContext;

osThreadId_t sftpTaskHandle;
const osThreadAttr_t sftpTask_attributes = {
  .name = "sftpTask",
  .stack_size = 512 * 4,
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
error_t ftpClientTlsInitCallback(FtpClientContext *context, TlsContext *tlsContext);
void sftpClientTask(void *argument);
error_t sftpTest(void);
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
  sftpTaskHandle = osThreadNew(sftpClientTask, NULL, &sftpTask_attributes);
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

/* sftp client task */
void sftpClientTask(void *argument)
{
  /* Start sFTP Task */
  TRACE_INFO("Start sFTP Task.\r\n");

  for(;;)
  {
    /* When click PC13, initiate FTP test */
    if(HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_SET)
    {
      sftpTest();
    }

    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
    osDelay(200);
  }
}

/* sftp initialization callback */
error_t ftpClientTlsInitCallback(FtpClientContext *context, TlsContext *tlsContext)
{
   error_t err;

   TRACE_INFO("SFTP Client: TLS initialization callback\r\n");

   err = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
   if(err) { return err; }

#if (APP_SET_CIPHER_SUITES == ENABLED)
   err = tlsSetCipherSuites(tlsContext, cipherSuites, arraysize(cipherSuites));
   if(err) { return err; }
#endif

#if (APP_SET_SERVER_NAME == ENABLED)
   err = tlsSetServerName(tlsContext, APP_FTP_SERVER_NAME);
   if(err) { return err; }
#endif

#if (APP_SET_TRUSTED_CA_LIST == ENABLED)
   err = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList));
   if(err) { return err; }
#endif

   return NO_ERROR;
}

/* sftp connect & read file */
error_t sftpTest(void)
{
  error_t err;
  size_t recv_len;
  IpAddr ipAddr;
  char_t buffer[128];

  TRACE_INFO("FTP context initialize...\r\n");
  ftpClientInit(&ftpClientContext);

  err = NO_ERROR;

  do
  {
    TRACE_INFO("Resolving server name...\r\n");
    if((err = getHostByName(NULL, APP_FTP_SERVER_NAME, &ipAddr, 0)) != NO_ERROR)
    {
      TRACE_INFO("Failed to resolve server name!\r\n");
      break;
    }

#if (APP_FTP_IMPLICIT_TLS == ENABLED || APP_FTP_EXPLICIT_TLS == ENABLED)
    if((err = ftpClientRegisterTlsInitCallback(&ftpClientContext, ftpClientTlsInitCallback)) != NO_ERROR)
    {
      TRACE_INFO("Failed to register TLS initialize callback!\r\n");
      break;
    }
#endif

    TRACE_INFO("Set FTP Timeout...\r\n");
    if((err = ftpClientSetTimeout(&ftpClientContext, 20000)) != NO_ERROR)
    {
      TRACE_INFO("Failed to set timeout!\r\n");
      break;
    }

    TRACE_INFO("Connect to FTP server...\r\n");
#if (APP_FTP_IMPLICIT_TLS == ENABLED)
      err = ftpClientConnect(&ftpClientContext, &ipAddr, 990, FTP_MODE_IMPLICIT_TLS | FTP_MODE_PASSIVE);
#elif (APP_FTP_EXPLICIT_TLS == ENABLED)
      err = ftpClientConnect(&ftpClientContext, &ipAddr, APP_FTP_SERVER_PORT, FTP_MODE_EXPLICIT_TLS | FTP_MODE_PASSIVE);
#else
      err = ftpClientConnect(&ftpClientContext, &ipAddr, APP_FTP_SERVER_PORT, FTP_MODE_PLAINTEXT | FTP_MODE_PASSIVE);
#endif

    if(err != NO_ERROR)
    {
      TRACE_INFO("Failed to connect to FTP server!:Error Code:%d\r\n", err);
      break;
    }

    TRACE_INFO("Login to FTP server...\r\n");
    if((err = ftpClientLogin(&ftpClientContext, APP_FTP_LOGIN, APP_FTP_PASSWORD)) != NO_ERROR)
    {
      TRACE_INFO("Failed to login to FTP server!\r\n");
      break;
    }

    TRACE_INFO("Open file to read from server...\r\n");
    if((err = ftpClientOpenFile(&ftpClientContext, APP_FTP_FILENAME, FTP_FILE_MODE_READ|FTP_FILE_MODE_BINARY)) != NO_ERROR)
    {
      TRACE_INFO("Failed to open file to read from server!\r\n");
      break;
    }

    while(!err)
    {
      err = ftpClientReadFile(&ftpClientContext, buffer, sizeof(buffer) - 1, &recv_len, 0);

      if(!err)
      {
        buffer[recv_len] = '\0';
        TRACE_INFO("%s", buffer);
      }
    }

    TRACE_INFO("Close file...\r\n");
    if((err = ftpClientCloseFile(&ftpClientContext)) != NO_ERROR)
    {
      TRACE_INFO("Failed to close file!\r\n");
      break;
    }

    TRACE_INFO("Disconnect from FTP server...\r\n");
    if((err = ftpClientDisconnect(&ftpClientContext)) != NO_ERROR)
    {
      TRACE_INFO("Disconnect from FTP server!\r\n");
      break;
    }

  }while(0); //error handling while block

  TRACE_INFO("FTP context deinitialize...\r\n");
  ftpClientDeinit(&ftpClientContext);

  return err;
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

