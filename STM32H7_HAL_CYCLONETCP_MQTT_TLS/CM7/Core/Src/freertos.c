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
#include "mqtt/mqtt_client.h"
#include "tls.h"
#include "tls_cipher_suites.h"
#include "rng/hmac_drbg.h"
#include "debug.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
/**
 * @brief Defines the states for the MQTT client state machine.
 */
typedef enum
{
  MQTT_STATE_INIT, MQTT_STATE_DISCONNECTED, MQTT_STATE_CONNECTED,
} MqttState_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define APP_SERVER_NAME "test.mosquitto.org"
#define APP_SERVER_PORT 8883 //MQTT over TLS

#define APP_SET_CIPHER_SUITES ENABLED
#define APP_SET_SERVER_NAME ENABLED
#define APP_SET_TRUSTED_CA_LIST ENABLED

#define MQTT_TOPIC_BUTTON       "board/buttons/1"
#define MQTT_TOPIC_STATUS       "board/status"
#define MQTT_TOPIC_LEDS_WILD    "board/leds/+"
#define MQTT_TOPIC_LED_3        "board/leds/3"

#define MQTT_PAYLOAD_PRESSED    "pressed"
#define MQTT_PAYLOAD_RELEASED   "released"
#define MQTT_PAYLOAD_ONLINE     "online"
#define MQTT_PAYLOAD_OFFLINE    "offline"
#define MQTT_PAYLOAD_TOGGLE     "toggle"
#define MQTT_PAYLOAD_ON         "on"

#define DEFAULT_TASK_LOOP_DELAY_MS 100
#define LED_TOGGLE_INTERVAL_MS     500
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
volatile uint_t g_btnState = 0;

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
{ "-----BEGIN CERTIFICATE-----"
    "MIIEAzCCAuugAwIBAgIUBY1hlCGvdj4NhBXkZ/uLUZNILAwwDQYJKoZIhvcNAQEL"
    "BQAwgZAxCzAJBgNVBAYTAkdCMRcwFQYDVQQIDA5Vbml0ZWQgS2luZ2RvbTEOMAwG"
    "A1UEBwwFRGVyYnkxEjAQBgNVBAoMCU1vc3F1aXR0bzELMAkGA1UECwwCQ0ExFjAU"
    "BgNVBAMMDW1vc3F1aXR0by5vcmcxHzAdBgkqhkiG9w0BCQEWEHJvZ2VyQGF0Y2hv"
    "by5vcmcwHhcNMjAwNjA5MTEwNjM5WhcNMzAwNjA3MTEwNjM5WjCBkDELMAkGA1UE"
    "BhMCR0IxFzAVBgNVBAgMDlVuaXRlZCBLaW5nZG9tMQ4wDAYDVQQHDAVEZXJieTES"
    "MBAGA1UECgwJTW9zcXVpdHRvMQswCQYDVQQLDAJDQTEWMBQGA1UEAwwNbW9zcXVp"
    "dHRvLm9yZzEfMB0GCSqGSIb3DQEJARYQcm9nZXJAYXRjaG9vLm9yZzCCASIwDQYJ"
    "KoZIhvcNAQEBBQADggEPADCCAQoCggEBAME0HKmIzfTOwkKLT3THHe+ObdizamPg"
    "UZmD64Tf3zJdNeYGYn4CEXbyP6fy3tWc8S2boW6dzrH8SdFf9uo320GJA9B7U1FW"
    "Te3xda/Lm3JFfaHjkWw7jBwcauQZjpGINHapHRlpiCZsquAthOgxW9SgDgYlGzEA"
    "s06pkEFiMw+qDfLo/sxFKB6vQlFekMeCymjLCbNwPJyqyhFmPWwio/PDMruBTzPH"
    "3cioBnrJWKXc3OjXdLGFJOfj7pP0j/dr2LH72eSvv3PQQFl90CZPFhrCUcRHSSxo"
    "E6yjGOdnz7f6PveLIB574kQORwt8ePn0yidrTC1ictikED3nHYhMUOUCAwEAAaNT"
    "MFEwHQYDVR0OBBYEFPVV6xBUFPiGKDyo5V3+Hbh4N9YSMB8GA1UdIwQYMBaAFPVV"
    "6xBUFPiGKDyo5V3+Hbh4N9YSMA8GA1UdEwEB/wQFMAMBAf8wDQYJKoZIhvcNAQEL"
    "BQADggEBAGa9kS21N70ThM6/Hj9D7mbVxKLBjVWe2TPsGfbl3rEDfZ+OKRZ2j6AC"
    "6r7jb4TZO3dzF2p6dgbrlU71Y/4K0TdzIjRj3cQ3KSm41JvUQ0hZ/c04iGDg/xWf"
    "+pp58nfPAYwuerruPNWmlStWAXf0UTqRtg4hQDWBuUFDJTuWuuBvEXudz74eh/wK"
    "sMwfu1HFvjy5Z0iMDU8PUDepjVolOCue9ashlS4EB5IECdSR2TItnAIiIwimx839"
    "LdUdRudafMu5T5Xma182OC0/u/xRlEm+tvKGGmfFcN0piqVl8OrSPBgIlb+1IKJE"
    "m/XriWr/Cq4h/JfB7NTsezVslgkBaoU="
    "-----END CERTIFICATE-----" };

MqttClientContext mqttClientContext;

osThreadId_t mqttTaskHandle;
const osThreadAttr_t mqttTask_attributes =
{ .name = "mqttTask", .stack_size = 2048 * 4, .priority = (osPriority_t) osPriorityNormal, };
/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes =
{ .name = "defaultTask", .stack_size = 512 * 4, .priority = (osPriority_t) osPriorityNormal, };

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
void mqttTestTask(void *argument);

static MqttState_t mqttInitialize(void);
static MqttState_t mqttDisconnected(void);
static MqttState_t mqttConnected(void);

error_t mqttConnectBroker(void);
error_t mqttClientTlsInitCallback(MqttClientContext *context, TlsContext *tlsContext);
void mqttClientPublishCallback(MqttClientContext *context, const char_t *topic, const uint8_t *message, size_t length, bool_t dup, MqttQosLevel qos, bool_t retain, uint16_t packetId);
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
void MX_FREERTOS_Init(void)
{
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Create the thread(s) */
  /* creation of defaultTask */
  defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

  /* creation of mqttTask */
  mqttTaskHandle = osThreadNew(mqttTestTask, NULL, &mqttTask_attributes);

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
  uint32_t lastLedToggleTick = 0;

  /* Infinite loop */
  for(;;)
  {
    // 실제 제품에서는 불필요한 task 동작을 최소화 위해 interrupt 를 사용하도록 구현
    g_btnState = (HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_SET);

    uint32_t currentTick = osKernelGetTickCount();
    if(currentTick - lastLedToggleTick >= LED_TOGGLE_INTERVAL_MS)
    {
      HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
      lastLedToggleTick = currentTick;
    }

    osDelay(DEFAULT_TASK_LOOP_DELAY_MS);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

void mqttTestTask(void *argument)
{
  MqttState_t mqttState = MQTT_STATE_INIT;

  for(;;)
  {
    switch(mqttState)
    {
    case MQTT_STATE_INIT:
      mqttState = mqttInitialize();
      break;

    case MQTT_STATE_DISCONNECTED:
      mqttState = mqttDisconnected();
      break;

    case MQTT_STATE_CONNECTED:
      mqttState = mqttConnected();
      break;

    default:
      mqttState = MQTT_STATE_INIT;
      break;
    }
  }
}

static MqttState_t mqttInitialize(void)
{
  mqttClientInit(&mqttClientContext);
  TRACE_INFO("Start MQTT Task.\r\n");
  return MQTT_STATE_DISCONNECTED;
}

static MqttState_t mqttDisconnected(void)
{
  if(netGetLinkState(&netInterface[0]))
  {
    if(mqttConnectBroker() == NO_ERROR)
    {
      TRACE_INFO("MQTT client connected.\r\n");
      return MQTT_STATE_CONNECTED;
    }
    else
    {
      osDelayTask(2000);
    }
  }
  else
  {
    osDelayTask(1000);
  }

  return MQTT_STATE_DISCONNECTED;
}

static MqttState_t mqttConnected()
{
  error_t err = NO_ERROR;
  char_t buffer[16];
  static uint8_t lastPublishedState = 0;

  if(lastPublishedState != g_btnState)
  {
    snprintf(buffer, sizeof(buffer), "%s", g_btnState ? MQTT_PAYLOAD_PRESSED : MQTT_PAYLOAD_RELEASED);

    err = mqttClientPublish(&mqttClientContext, MQTT_TOPIC_BUTTON, buffer, strlen(buffer), MQTT_QOS_LEVEL_1, TRUE, NULL);
    if(err != NO_ERROR)
    {
      TRACE_INFO("mqttClientPublish() failed: %d\r\n", err);
    }
    else
    {
      lastPublishedState = g_btnState;
    }
  }

  if(err == NO_ERROR)
  {
    err = mqttClientTask(&mqttClientContext, 100);
    if(err != NO_ERROR && err != ERROR_TIMEOUT)
    {
      TRACE_INFO("mqttClientTask() failed or disconnected: %d\r\n", err);
    }
    else
    {
      err = NO_ERROR;
    }
  }

  if(err != NO_ERROR)
  {
    TRACE_INFO("Connection lost. Reconnecting...\r\n");
    mqttClientClose(&mqttClientContext);
    osDelayTask(2000);
    return MQTT_STATE_DISCONNECTED;
  }

  return MQTT_STATE_CONNECTED;
}

error_t mqttClientTlsInitCallback(MqttClientContext *context, TlsContext *tlsContext)
{
  error_t err;

  TRACE_INFO("MQTT Client: TLS initialization callback\r\n");

  err = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext);
  if(err)
  {
    return err;
  }

#if (APP_SET_CIPHER_SUITES == ENABLED)
  err = tlsSetCipherSuites(tlsContext, cipherSuites, arraysize(cipherSuites));
  if(err)
  {
    return err;
  }
#endif

#if (APP_SET_SERVER_NAME == ENABLED)
  err = tlsSetServerName(tlsContext, APP_SERVER_NAME);
  if(err)
  {
    return err;
  }
#endif

#if (APP_SET_TRUSTED_CA_LIST == ENABLED)
  err = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList));
  if(err)
  {
    return err;
  }
#endif

  return NO_ERROR;
}

void mqttClientPublishCallback(MqttClientContext *context, const char_t *topic, const uint8_t *message, size_t length, bool_t dup, MqttQosLevel qos,
    bool_t retain, uint16_t packetId)
{
  TRACE_INFO("PUBLISH packet received...\r\n");
  TRACE_INFO("Topic: %s\r\n", topic);
  TRACE_INFO("Message (%" PRIuSIZE " bytes): ", length);
  TRACE_INFO("%.*s\r\n", length, message);
  TRACE_INFO_ARRAY("", message, length);

  if(!strcmp(topic, MQTT_TOPIC_LED_3))
  {
    if(length == strlen(MQTT_PAYLOAD_TOGGLE) && !strncasecmp((char_t*) message, MQTT_PAYLOAD_TOGGLE, length))
    {
      HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
    }
    else if(length == strlen(MQTT_PAYLOAD_ON) && !strncasecmp((char_t*) message, MQTT_PAYLOAD_ON, length))
    {
      HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET);
    }
    else
    {
      HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET);
    }
  }
}

error_t mqttConnectBroker(void)
{
  error_t err;
  IpAddr ipAddr;

  do
  {
    TRACE_INFO("\r\n\r\nResolving server name...\r\n");
    if((err = getHostByName(NULL, APP_SERVER_NAME, &ipAddr, 0)) != NO_ERROR)
    {
      TRACE_INFO("getHostByName() failed: %d\r\n", err);
      break;
    }

    if((err = mqttClientSetVersion(&mqttClientContext, MQTT_VERSION_3_1_1)) != NO_ERROR)
    {
      break;
    }
    if((err = mqttClientSetTransportProtocol(&mqttClientContext, MQTT_TRANSPORT_PROTOCOL_TLS)) != NO_ERROR)
    {
      break;
    }
    if((err = mqttClientRegisterTlsInitCallback(&mqttClientContext, mqttClientTlsInitCallback)) != NO_ERROR)
    {
      break;
    }
    if((err = mqttClientRegisterPublishCallback(&mqttClientContext, mqttClientPublishCallback)) != NO_ERROR)
    {
      break;
    }
    if((err = mqttClientSetTimeout(&mqttClientContext, 20000)) != NO_ERROR)
    {
      break;
    }
    if((err = mqttClientSetKeepAlive(&mqttClientContext, 30)) != NO_ERROR)
    {
      break;
    }
    if((err = mqttClientSetWillMessage(&mqttClientContext, MQTT_TOPIC_STATUS, MQTT_PAYLOAD_OFFLINE, strlen(MQTT_PAYLOAD_OFFLINE), MQTT_QOS_LEVEL_0, FALSE)) != NO_ERROR)
    {
      break;
    }

    TRACE_INFO("Connecting to MQTT server %s...\r\n", ipAddrToString(&ipAddr, NULL));
    if((err = mqttClientConnect(&mqttClientContext, &ipAddr, APP_SERVER_PORT, TRUE)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientConnect() failed: %d\r\n", err);
      mqttClientClose(&mqttClientContext);
      break;
    }

    if((err = mqttClientSubscribe(&mqttClientContext, MQTT_TOPIC_LEDS_WILD, MQTT_QOS_LEVEL_1, NULL)) != NO_ERROR)
    {
      mqttClientClose(&mqttClientContext);
      break;
    }

    if((err = mqttClientPublish(&mqttClientContext, MQTT_TOPIC_STATUS, MQTT_PAYLOAD_ONLINE, strlen(MQTT_PAYLOAD_ONLINE), MQTT_QOS_LEVEL_1, TRUE, NULL)) != NO_ERROR)
    {
      mqttClientClose(&mqttClientContext);
      break;
    }

  }while(0);

  return err;
}

int __io_putchar(int ch)
{
  HAL_UART_Transmit(&huart1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
  return ch;
}

void debugDisplayArray(FILE *stream, const char_t *prepend, const void *data, size_t length)
{
  for(size_t i = 0;i < length;i++)
  {
    if((i % 16) == 0)
      fprintf(stream, "%s", prepend);

    fprintf(stream, "%02" PRIX8 " ", *((uint8_t*) data + i));

    if((i % 16) == 15 || i == (length - 1))
      fprintf(stream, "\r\n");
  }
}

/* USER CODE END Application */
