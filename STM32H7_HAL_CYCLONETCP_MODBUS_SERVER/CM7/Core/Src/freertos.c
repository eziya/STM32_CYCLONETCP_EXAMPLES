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
#include "dhcp/dhcp_client.h"
#include "modbus/modbus_server.h"
#include "debug.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define APP_MODBUS_SERVER_PORT 502
#define APP_MODBUS_SERVER_TIMEOUT 600000
#define APP_MODBUS_SERVER_KEEP_ALIVE_IDLE 10000
#define APP_MODBUS_SERVER_KEEP_ALIVE_INTERVAL 5000
#define APP_MODBUS_SERVER_KEEP_ALIVE_PROBES 4

#define DHCP_TIMEOUT_MS 10000
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern UART_HandleTypeDef huart1;
extern DhcpClientContext dhcpClientContext;

ModbusServerSettings modbusServerSettings;
ModbusServerContext modbusServerContext;

uint16_t modbusData[100];
SemaphoreHandle_t modbusDataMutex;

osThreadId_t modbusTaskHandle;
const osThreadAttr_t modbusTask_attributes =
{
    .name = "modbusTask",
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
void ModbusServerTask(void *argument);
error_t InitModbusServer(void);

void modbusServerLockCallback(ModbusClientConnection *connection);
void modbusServerUnlockCallback(ModbusClientConnection *connection);
error_t modbusServerOpenCallback(ModbusClientConnection *connection, IpAddr clientIpAddr, uint16_t clientPort);
error_t modbusServerReadCoilCallback(ModbusClientConnection *connection, uint16_t address, bool_t *state);
error_t modbusServerWriteCoilCallback(ModbusClientConnection *connection, uint16_t address, bool_t state, bool_t commit);
error_t modbusServerReadRegCallback(ModbusClientConnection *connection, uint16_t address, uint16_t *value);
error_t modbusServerWriteRegCallback(ModbusClientConnection *connection, uint16_t address, uint16_t value, bool_t commit);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* Hook prototypes */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName);

/* USER CODE BEGIN 4 */
void vApplicationStackOverflowHook(xTaskHandle xTask, signed char *pcTaskName)
{
  __disable_irq();
  while(1)
  {
    // Turn off all LEDs in case of stack overflow
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
  modbusDataMutex = xSemaphoreCreateMutex();
  if(modbusDataMutex == NULL)
  {
    TRACE_ERROR("Failed to create Modbus data mutex!\r\n");
    Error_Handler();
  }

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
  modbusTaskHandle = osThreadNew(ModbusServerTask, NULL, &modbusTask_attributes);
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
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/**
 * @brief freertos modbus task procedure
 **/
void ModbusServerTask(void *argument)
{
  uint32_t startTime = osKernelGetTickCount();
  TRACE_INFO("Waiting for DHCP to complete...\r\n");

  while(dhcpClientContext.state != DHCP_STATE_BOUND)
  {
    if((osKernelGetTickCount() - startTime) > DHCP_TIMEOUT_MS)
    {
      TRACE_ERROR("DHCP client timeout!\r\n");
      osThreadTerminate(NULL);
    }
    osDelay(500);
  }

  /* Print IP, Gateway, DNS address */
  NetInterface *interface = &netInterface[0];
  Ipv4Addr ipAddr;
  char ipStr[14];

  ipAddr = interface->ipv4Context.addrList[0].addr;
  if(ipAddr != IPV4_UNSPECIFIED_ADDR)
  {
    TRACE_INFO("DHCP IP Assigned: %s\r\n", ipv4AddrToString(ipAddr, ipStr));
  }

  ipAddr = interface->ipv4Context.addrList[0].defaultGateway;
  if(ipAddr != IPV4_UNSPECIFIED_ADDR)
  {
    TRACE_INFO("DHCP Gateway: %s\r\n", ipv4AddrToString(ipAddr, ipStr));
  }

  ipAddr = interface->ipv4Context.dnsServerList[0];
  if(ipAddr != IPV4_UNSPECIFIED_ADDR)
  {
    TRACE_INFO("DHCP DNS Server: %s\r\n", ipv4AddrToString(ipAddr, ipStr));
  }

  /* Initialize data array */
  for(int i = 0; i < 100; i++)
  {
    modbusData[i] = i;
  }

  /* Initialize server */
  if(InitModbusServer() != NO_ERROR)
  {
    TRACE_ERROR("Modbus Server failed to start. Halting task.\r\n");
    osThreadTerminate(NULL);
  }

  for(;;)
  {
    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
    osDelay(500);
  }
}

/**
 * @brief Initialize modbus server
 **/
error_t InitModbusServer(void)
{
  error_t error;

  /* Configure Modbus server */
  modbusServerGetDefaultSettings(&modbusServerSettings);
  modbusServerSettings.unitId = 1;
  modbusServerSettings.interface = &netInterface[0];
  modbusServerSettings.port = APP_MODBUS_SERVER_PORT;
  modbusServerSettings.timeout = APP_MODBUS_SERVER_TIMEOUT;

  /* Register callback functions */
  modbusServerSettings.openCallback = modbusServerOpenCallback;
  modbusServerSettings.lockCallback = modbusServerLockCallback;
  modbusServerSettings.unlockCallback = modbusServerUnlockCallback;
  modbusServerSettings.readCoilCallback = modbusServerReadCoilCallback;
  modbusServerSettings.writeCoilCallback = modbusServerWriteCoilCallback;
  modbusServerSettings.readRegCallback = modbusServerReadRegCallback;
  modbusServerSettings.writeRegCallback = modbusServerWriteRegCallback;

  /* Initialize server */
  error = modbusServerInit(&modbusServerContext, &modbusServerSettings);
  if(error)
  {
    TRACE_ERROR("Failed to initialize Modbus/TCP server!\r\n");
    return error;
  }

  /* Start server */
  error = modbusServerStart(&modbusServerContext);
  if(error)
  {
    TRACE_ERROR("Failed to start Modbus/TCP server!\r\n");
    return error;
  }

  TRACE_INFO("Modbus/TCP server started on port %u\r\n", APP_MODBUS_SERVER_PORT);
  return NO_ERROR;
}

/**
 * @brief Server connection callback
 **/
error_t modbusServerOpenCallback(ModbusClientConnection *connection, IpAddr clientIpAddr, uint16_t clientPort)
{
  error_t error;
  TRACE_INFO("Modbus client connected from %s port %u\r\n", ipAddrToString(&clientIpAddr, NULL), clientPort);

  /* TCP_KEEP_ALIVE_SUPPORT should be enabled */
  error = socketSetKeepAliveParams(connection->socket, APP_MODBUS_SERVER_KEEP_ALIVE_IDLE, APP_MODBUS_SERVER_KEEP_ALIVE_INTERVAL, APP_MODBUS_SERVER_KEEP_ALIVE_PROBES);
  if(error)
  {
    TRACE_ERROR("socketSetKeepAliveParams failed: %d\r\n", error);
    return error;
  }

  error = socketEnableKeepAlive(connection->socket, TRUE);
  if(error)
  {
    TRACE_ERROR("socketEnableKeepAlive failed: %d\r\n", error);
    return error;
  }

  return NO_ERROR;
}

/**
 * @brief Lock the Modbus data table before access
 **/
void modbusServerLockCallback(ModbusClientConnection *connection)
{
  xSemaphoreTake(modbusDataMutex, portMAX_DELAY);
}

/**
 * @brief Unlock the Modbus data table after access
 **/
void modbusServerUnlockCallback(ModbusClientConnection *connection)
{
  xSemaphoreGive(modbusDataMutex);
}

/**
 * @brief Read coil callback
 **/
error_t modbusServerReadCoilCallback(ModbusClientConnection *connection, uint16_t address, bool_t *state)
{
  if(address < 100)
  {
    *state = (modbusData[address] != 0);
  }
  else if(address == 100)
  {
    /* Return user button state */
    *state = (HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_SET);
  }
  else
  {
    return ERROR_INVALID_ADDRESS;
  }

  return NO_ERROR;
}

/**
 * @brief Write coil callback
 **/
error_t modbusServerWriteCoilCallback(ModbusClientConnection *connection, uint16_t address, bool_t state, bool_t commit)
{
  if(commit && address < 100)
  {
    modbusData[address] = state ? 1 : 0;

    /* Control LED 3 & 4 for address 0 and address 1 */
    if(address == 0)
    {
      HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
    else if(address == 1)
    {
      HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, state ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
  }
  else if(commit)
  {
    return ERROR_INVALID_ADDRESS;
  }

  return NO_ERROR;
}

/**
 * @brief Read register callback
 **/
error_t modbusServerReadRegCallback(ModbusClientConnection *connection, uint16_t address, uint16_t *value)
{
  uint16_t index = 0;
  bool_t valid_address = FALSE;

  /* Input Registers: 30001-30100 (address 30000-30099) */
  if(address >= 30000 && address < 30100)
  {
    index = address - 30000;
    valid_address = TRUE;
  }
  /* Holding Registers: 40001-40100 (address 40000-40099) */
  else if(address >= 40000 && address < 40100)
  {
    index = address - 40000;
    valid_address = TRUE;
  }

  if(valid_address)
  {
    *value = modbusData[index];
  }
  else
  {
    return ERROR_INVALID_ADDRESS;
  }

  return NO_ERROR;
}

/**
 * @brief Write register callback
 **/
error_t modbusServerWriteRegCallback(ModbusClientConnection *connection, uint16_t address, uint16_t value, bool_t commit)
{
  // Holding Registers: 40001-40100 (address 40000-40099)
  if(commit && (address >= 40000 && address < 40100))
  {
    uint16_t index = address - 40000;
    modbusData[index] = value;

    /* Control LED 3 & 4 for address 40000 and address 40001 */
    if(index == 0)
    {
      HAL_GPIO_WritePin(LED3_GPIO_Port, LED3_Pin, (value != 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
    else if(index == 1)
    {
      HAL_GPIO_WritePin(LED4_GPIO_Port, LED4_Pin, (value != 0) ? GPIO_PIN_RESET : GPIO_PIN_SET);
    }
  }
  else if(commit)
  {
    return ERROR_INVALID_ADDRESS;
  }

  return NO_ERROR;
}

/**
 * @brief Debug out redirection
 **/
int __io_putchar (int ch)
{
  HAL_UART_Transmit(&huart1, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
  return ch;
}

/**
 * @brief Display the contents of an array
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

