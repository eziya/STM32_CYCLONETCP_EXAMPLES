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
//#define APP_SERVER_PORT 8883 //MQTT over TLS
#define APP_SERVER_PORT 8884 //MQTT over TLS (mutual authentication)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern UART_HandleTypeDef huart1;
extern HmacDrbgContext hmacDrbgContext;

const char_t clientCert[] =
{ "-----BEGIN CERTIFICATE-----"
    "MIICmzCCAYOgAwIBAgIBADANBgkqhkiG9w0BAQsFADCBkDELMAkGA1UEBhMCR0Ix"
    "FzAVBgNVBAgMDlVuaXRlZCBLaW5nZG9tMQ4wDAYDVQQHDAVEZXJieTESMBAGA1UE"
    "CgwJTW9zcXVpdHRvMQswCQYDVQQLDAJDQTEWMBQGA1UEAwwNbW9zcXVpdHRvLm9y"
    "ZzEfMB0GCSqGSIb3DQEJARYQcm9nZXJAYXRjaG9vLm9yZzAeFw0yNDA1MjAxMjIw"
    "MTJaFw0yNDA4MTgxMjIwMTJaMEAxCzAJBgNVBAYTAkZSMRYwFAYDVQQKDA1Pcnl4"
    "IEVtYmVkZGVkMRkwFwYDVQQDDBBtcXR0LWNsaWVudC1kZW1vMFkwEwYHKoZIzj0C"
    "AQYIKoZIzj0DAQcDQgAEWT/enOkLuY+9NzUQPOuNVFARl5Y3bc4lLt3TyVwWG0Ez"
    "IIk8Wll5Ljjrv+buPSKBVQtOwF9VgyW4QuQ1uYSAIaMaMBgwCQYDVR0TBAIwADAL"
    "BgNVHQ8EBAMCBeAwDQYJKoZIhvcNAQELBQADggEBALW6YSU2jqs7TegW2CoydK7W"
    "rEzy/8ecasdeDy+8vIkxC1chtm2VgYsndFUaLhSD31I0paLqE67kGzyD8TKhBAyp"
    "4trhLsgFUjTsKYj8kPj147am2wwP0hbd1dygr+kaNxV3glZqot8IK2+topA3BbFO"
    "34wvdNI81o63ldKn+Q3sp522osxfwiCy8/5DZ+2VLzGBwbsKaYNk2RwhUNbF88eD"
    "IHAi9iY3YYx7hE9UvMA3CbWBOmz06lFWr2Nwyr3lYM6qO87GKKMZaFjdrFtzQlaB"
    "ngH1f6yCuM0iwd7gbWKwPWoilIDdg8DVi38fN/Clv5PbTt+KJslVbNElV6ykbyA="
    "-----END CERTIFICATE-----" };

const char_t clientKey[] =
{ "-----BEGIN EC PRIVATE KEY-----"
    "MHcCAQEEICYULY0KQ6nDAXFl5tgK9ljqAZyb14JQmI3iT7tdScDloAoGCCqGSM49"
    "AwEHoUQDQgAEWT/enOkLuY+9NzUQPOuNVFARl5Y3bc4lLt3TyVwWG0EzIIk8Wll5"
    "Ljjrv+buPSKBVQtOwF9VgyW4QuQ1uYSAIQ=="
    "-----END EC PRIVATE KEY-----" };

const char trustedCaList[] =
{ "-----BEGIN CERTIFICATE-----"
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
    "-----END CERTIFICATE-----" };

MqttClientContext mqttClientContext;

osThreadId_t mqttTaskHandle;
const osThreadAttr_t mqttTask_attributes =
{ .name = "mqttTask", .stack_size = 1024 * 4, .priority = (osPriority_t) osPriorityNormal, };

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes =
{ .name = "defaultTask", .stack_size = 512 * 4, .priority = (osPriority_t) osPriorityNormal, };

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
static MqttState_t handleStateInit(void);
static MqttState_t handleStateDisconnected(void);
static MqttState_t handleStateConnected(uint_t *prevButtonState);
void mqttTestTask(void *argument);
error_t mqttTestTlsInitCallback(MqttClientContext *context, TlsContext *tlsContext);
void mqttTestPublishCallback(MqttClientContext *context, const char_t *topic, const uint8_t *message, size_t length, bool_t dup, MqttQosLevel qos,
    bool_t retain, uint16_t packetId);
error_t mqttTestConnect(void);
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
  mqttTaskHandle = osThreadNew(mqttTestTask, NULL, &mqttTask_attributes);
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

/**
 * @brief Handles the one-time initialization state.
 * @return MqttState_t The next state to transition to (always DISCONNECTED).
 */
static MqttState_t handleStateInit(void)
{
  mqttClientInit(&mqttClientContext);
  TRACE_INFO("Start MQTT Task.\r\n");
  return MQTT_STATE_DISCONNECTED;
}

/**
 * @brief Handles the disconnected state, attempting to establish a connection.
 * @return MqttState_t The next state (CONNECTED on success, DISCONNECTED on failure).
 */
static MqttState_t handleStateDisconnected(void)
{
  if(netGetLinkState(&netInterface[0]))
  {
    if(mqttTestConnect() == NO_ERROR)
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
  // Stay in the disconnected state if connection fails or link is down
  return MQTT_STATE_DISCONNECTED;
}

/**
 * @brief Handles the connected state, processing MQTT logic and monitoring the connection.
 * @param[in,out] prevButtonState Pointer to the previous button state for change detection.
 * @return MqttState_t The next state (DISCONNECTED on error, CONNECTED otherwise).
 */
static MqttState_t handleStateConnected(uint_t *prevButtonState)
{
  error_t error = NO_ERROR;
  uint_t buttonState;
  char_t buffer[16];

  do
  {
    buttonState = (HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_SET);
    if(buttonState != *prevButtonState)
    {
      strcpy(buffer, buttonState ? "pressed" : "released");

      if((error = mqttClientPublish(&mqttClientContext, "board/buttons/1", buffer, strlen(buffer), MQTT_QOS_LEVEL_1, TRUE, NULL)) != NO_ERROR)
      {
        TRACE_INFO("mqttClientPublish() failed: %d\r\n", error);
        break;
      }
      *prevButtonState = buttonState;
    }

    if((error = mqttClientTask(&mqttClientContext, 100)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientTask() failed or disconnected: %d\r\n", error);
      break;
    }
  }while(0);

  if(error != NO_ERROR)
  {
    TRACE_INFO("Connection lost. Reconnecting...\r\n");
    mqttClientClose(&mqttClientContext);
    osDelayTask(2000);
    return MQTT_STATE_DISCONNECTED;
  }

  // Stay in the connected state if everything is OK
  return MQTT_STATE_CONNECTED;
}

/**
 * @brief Main task for the MQTT client, implemented as a state machine dispatcher.
 * @details This task runs an infinite loop that calls a handler function
 * based on the current state and transitions to the next state returned by the handler.
 * @param[in] argument The argument passed when the task is created (unused).
 */
void mqttTestTask(void *argument)
{
  MqttState_t currentState = MQTT_STATE_INIT;
  uint_t prevButtonState = 0;

  for(;;)
  {
    switch(currentState)
    {
    case MQTT_STATE_INIT:
      currentState = handleStateInit();
      break;

    case MQTT_STATE_DISCONNECTED:
      currentState = handleStateDisconnected();
      // Upon successful connection, reset the button state
      if(currentState == MQTT_STATE_CONNECTED)
      {
        prevButtonState = (HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_SET);
      }
      break;

    case MQTT_STATE_CONNECTED:
      currentState = handleStateConnected(&prevButtonState);
      break;

    default:
      // Should not happen, but as a safeguard, reset to INIT state.
      currentState = MQTT_STATE_INIT;
      break;
    }
  }
}

/**
 * @brief Callback function for initializing TLS communication for the MQTT client.
 * @details Sets up the Pseudo-Random Number Generator (PRNG), Server Name
 * Indication (SNI), client certificate, and trusted CA list for the TLS context.
 * @param[in] context Pointer to the MQTT client context.
 * @param[in] tlsContext Pointer to the TLS context to be initialized.
 * @return error_t Returns NO_ERROR on success, or an error code on failure.
 */
error_t mqttTestTlsInitCallback(MqttClientContext *context, TlsContext *tlsContext)
{
  error_t error;

  TRACE_INFO("MQTT Client: TLS initialization callback\r\n");

  do
  {
    if((error = tlsSetPrng(tlsContext, HMAC_DRBG_PRNG_ALGO, &hmacDrbgContext)) != NO_ERROR)
      break;

    if((error = tlsSetServerName(tlsContext, APP_SERVER_NAME)) != NO_ERROR)
      break;

#if (APP_SERVER_PORT == 8884)
    if((error = tlsLoadCertificate(tlsContext, 0, clientCert, strlen(clientCert), clientKey, strlen(clientKey), NULL)) != NO_ERROR)
      break;
#endif

    if((error = tlsSetTrustedCaList(tlsContext, trustedCaList, strlen(trustedCaList))) != NO_ERROR)
      break;

  }while(0);

  return error;
}

/**
 * @brief Callback function invoked upon receiving an MQTT PUBLISH packet.
 * @details Defines the logic for handling messages received from the server on
 * specific topics. It controls an LED based on the received topic and message payload.
 * @param[in] context Pointer to the MQTT client context.
 * @param[in] topic The topic string on which the message was received.
 * @param[in] message Pointer to the received message data.
 * @param[in] length The length of the received message.
 * @param[in] dup The DUP (duplicate) flag.
 * @param[in] qos The Quality of Service (QoS) level.
 * @param[in] retain The Retain flag.
 * @param[in] packetId The packet identifier.
 */
void mqttTestPublishCallback(MqttClientContext *context, const char_t *topic, const uint8_t *message, size_t length, bool_t dup, MqttQosLevel qos,
    bool_t retain, uint16_t packetId)
{
  static const char *MQTT_TOPIC_LED_3 = "board/leds/3";
  static const char *MQTT_CMD_TOGGLE = "toggle";
  static const char *MQTT_CMD_ON = "on";

  TRACE_INFO("PUBLISH packet received...\r\n");
  TRACE_INFO("  Topic: %s\r\n", topic);
  TRACE_INFO("  Message (%" PRIuSIZE " bytes):\r\n", length);
  TRACE_INFO_ARRAY("    ", message, length);

  if(!strcmp(topic, MQTT_TOPIC_LED_3))
  {
    if(length == strlen(MQTT_CMD_TOGGLE) && !strncasecmp((char_t*) message, MQTT_CMD_TOGGLE, length))
    {
      HAL_GPIO_TogglePin(LED3_GPIO_Port, LED3_Pin);
    }
    else if(length == strlen(MQTT_CMD_ON) && !strncasecmp((char_t*) message, MQTT_CMD_ON, length))
    {
      HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_RESET); // Active Low LED ON
    }
    else
    {
      HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, GPIO_PIN_SET); // Active Low LED OFF
    }
  }
}

/**
 * @brief Establishes a connection to the MQTT server and performs initial setup.
 * @details Resolves the server name, sets the MQTT protocol version, registers
 * callbacks, sets the Will message, then connects to the server, subscribes to
 * a topic, and publishes an "online" status message.
 * @return error_t Returns NO_ERROR on success, or an error code on failure.
 */
error_t mqttTestConnect(void)
{
  error_t error;
  IpAddr ipAddr;

  do
  {
    TRACE_INFO("\r\n\r\nResolving server name...\r\n");
    if((error = getHostByName(NULL, APP_SERVER_NAME, &ipAddr, 0)) != NO_ERROR)
    {
      TRACE_INFO("getHostByName() failed: %d\r\n", error);
      break;
    }

    if((error = mqttClientSetVersion(&mqttClientContext, MQTT_VERSION_3_1_1)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientSetVersion() failed: %d\r\n", error);
      break;
    }

#if (APP_SERVER_PORT == 1883)
    mqttClientSetTransportProtocol(&mqttClientContext, MQTT_TRANSPORT_PROTOCOL_TCP);
#elif (APP_SERVER_PORT == 8883 || APP_SERVER_PORT == 8884)
    mqttClientSetTransportProtocol(&mqttClientContext, MQTT_TRANSPORT_PROTOCOL_TLS);

    if((error = mqttClientRegisterTlsInitCallback(&mqttClientContext, mqttTestTlsInitCallback)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientRegisterTlsInitCallback() failed: %d\r\n", error);
      break;
    }
#endif

    if((error = mqttClientRegisterPublishCallback(&mqttClientContext, mqttTestPublishCallback)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientRegisterPublishCallback() failed: %d\r\n", error);
      break;
    }

    if((error = mqttClientSetTimeout(&mqttClientContext, 20000)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientSetTimeout() failed: %d\r\n", error);
      break;
    }

    if((error = mqttClientSetKeepAlive(&mqttClientContext, 30)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientSetKeepAlive() failed: %d\r\n", error);
      break;
    }

    if((error = mqttClientSetWillMessage(&mqttClientContext, "board/status", "offline", 7, MQTT_QOS_LEVEL_0, FALSE)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientSetWillMessage() failed: %d\r\n", error);
      break;
    }

    TRACE_INFO("Connecting to MQTT server %s...\r\n", ipAddrToString(&ipAddr, NULL));
    if((error = mqttClientConnect(&mqttClientContext, &ipAddr, APP_SERVER_PORT, TRUE)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientConnect() failed: %d\r\n", error);
      mqttClientClose(&mqttClientContext);
      break;
    }

    if((error = mqttClientSubscribe(&mqttClientContext, "board/leds/+", MQTT_QOS_LEVEL_1, NULL)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientSubscribe() failed: %d\r\n", error);
      mqttClientClose(&mqttClientContext);
      break;
    }

    if((error = mqttClientPublish(&mqttClientContext, "board/status", "online", 6, MQTT_QOS_LEVEL_1, TRUE, NULL)) != NO_ERROR)
    {
      TRACE_INFO("mqttClientPublish() failed: %d\r\n", error);
      mqttClientClose(&mqttClientContext);
      break;
    }

  }while(0);

  return error;
}

/**
 * @brief Outputs a single character to the UART.
 * @details Redirects standard I/O functions like `printf` to the debug UART.
 * (Part of the `_write` implementation often auto-generated by STM32 CubeIDE).
 * @param[in] ch The character to be transmitted.
 * @return int The transmitted character.
 */
int __io_putchar(int ch)
{
  HAL_UART_Transmit(&huart1, (uint8_t*) &ch, 1, HAL_MAX_DELAY);
  return ch;
}

/**
 * @brief Debug function to display the contents of a data array in hexadecimal format.
 * @param[in] stream The output file stream (e.g., stdout).
 * @param[in] prepend The string to prepend to the beginning of each line.
 * @param[in] data Pointer to the data array to be displayed.
 * @param[in] length The number of bytes to display.
 */
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

