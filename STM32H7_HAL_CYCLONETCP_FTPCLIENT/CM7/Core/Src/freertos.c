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
#include "drivers/mac/stm32h7xx_eth_driver.h"
#include "drivers/phy/lan8742_driver.h"
#include "dhcp/dhcp_client.h"
#include "core/bsd_socket.h"
#include "ftp/ftp_client.h"
#include "debug.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define APP_IF_NAME "eth0"
#define APP_HOST_NAME "ftp-client-demo"
#define APP_MAC_ADDR "00-80-E1-00-00-00"

#define APP_USE_DHCP_CLIENT ENABLED
#define APP_IPV4_HOST_ADDR "192.168.1.20"
#define APP_IPV4_SUBNET_MASK "255.255.255.0"
#define APP_IPV4_DEFAULT_GATEWAY "192.168.1.1"
#define APP_IPV4_PRIMARY_DNS "8.8.8.8"
#define APP_IPV4_SECONDARY_DNS "8.8.4.4"

#define APP_FTP_SERVER_NAME "test.rebex.net"
#define APP_FTP_SERVER_PORT 21
#define APP_FTP_LOGIN "demo"
#define APP_FTP_PASSWORD "password"
#define APP_FTP_FILENAME "readme.txt"

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */
extern UART_HandleTypeDef huart1;
DhcpClientSettings dhcpClientSettings;
DhcpClientContext dhcpClientContext;
FtpClientContext ftpClientContext;

osThreadId_t ftpTaskHandle;
const osThreadAttr_t ftpTask_attributes = {
  .name = "ftpTask",
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
void FtpClientTask(void *argument);
error_t FtpTest(void);
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

  NetInterface *interface;
    MacAddr macAddr;

    //Start-up message
    TRACE_INFO("\r\n");
    TRACE_INFO("***********************************\r\n");
    TRACE_INFO("*** CycloneTCP Echo Server Demo ***\r\n");
    TRACE_INFO("***********************************\r\n");
    TRACE_INFO("Target: STM32H747I-DISCO\r\n");
    TRACE_INFO("\r\n");

    /* Initialize stack */
    TRACE_INFO("Initialize TCP/IP stack.\r\n");
    if(netInit())
    {
      TRACE_ERROR("Failed to initialize TCP/IP stack!\r\n");
    }

    /* Initialize Layer1 & Layer2 */
    interface = &netInterface[0];
    netSetInterfaceName(interface, APP_IF_NAME);
    netSetHostname(interface, APP_HOST_NAME);
    macStringToAddr(APP_MAC_ADDR, &macAddr);
    netSetMacAddr(interface, &macAddr);
    netSetDriver(interface, &stm32h7xxEthDriver);
    netSetPhyDriver(interface, &lan8742PhyDriver);

    TRACE_INFO("Initialize interface.\r\n");
    if(netConfigInterface(interface))
    {
      TRACE_ERROR("Failed to initialize interface %s!\r\n", interface->name);
    }

  #if (APP_USE_DHCP_CLIENT == ENABLED)
    /* Initialize DHCP */
    dhcpClientGetDefaultSettings(&dhcpClientSettings);
    dhcpClientSettings.interface = interface;
    dhcpClientSettings.rapidCommit = FALSE;

    TRACE_INFO("Initialize DHCP client.\r\n");
    if(dhcpClientInit(&dhcpClientContext, &dhcpClientSettings))
    {
      TRACE_ERROR("Failed to initialize DHCP client!\r\n");
    }

    TRACE_INFO("Start DHCP client.\r\n");
    if(dhcpClientStart(&dhcpClientContext))
    {
      TRACE_ERROR("Failed to start DHCP client!\r\n");
    }
  #else
    /* Configure static ip address */
    TRACE_INFO("Configure static IP address.\r\n");
    Ipv4Addr ipv4Addr;
    ipv4StringToAddr(APP_IPV4_HOST_ADDR, &ipv4Addr);
    ipv4SetHostAddr(interface, ipv4Addr);
    ipv4StringToAddr(APP_IPV4_SUBNET_MASK, &ipv4Addr);
    ipv4SetSubnetMask(interface, ipv4Addr);
    ipv4StringToAddr(APP_IPV4_DEFAULT_GATEWAY, &ipv4Addr);
    ipv4SetDefaultGateway(interface, ipv4Addr);
    ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &ipv4Addr);
    ipv4SetDnsServer(interface, 0, ipv4Addr);
    ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &ipv4Addr);
    ipv4SetDnsServer(interface, 1, ipv4Addr);
  #endif

    Ipv4Addr ipv4Addr;
    ipv4StringToAddr(APP_IPV4_PRIMARY_DNS, &ipv4Addr);
    ipv4SetDnsServer(interface, 0, ipv4Addr);
    ipv4StringToAddr(APP_IPV4_SECONDARY_DNS, &ipv4Addr);
    ipv4SetDnsServer(interface, 1, ipv4Addr);

    /* Start FTP Task */
    TRACE_INFO("Start FTP Task.\r\n");
    ftpTaskHandle = osThreadNew(FtpClientTask, NULL, &ftpTask_attributes);

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
void FtpClientTask(void *argument)
{
  for(;;)
  {
    /* When click PC13, initiate FTP test */
    if(HAL_GPIO_ReadPin(USER_BTN_GPIO_Port, USER_BTN_Pin) == GPIO_PIN_SET)
    {
      FtpTest();
    }

    HAL_GPIO_TogglePin(LED2_GPIO_Port, LED2_Pin);
    osDelay(200);
  }
}

error_t FtpTest(void)
{
  error_t error;
  size_t recv_len;
  IpAddr ipAddr;
  char_t buffer[128];

  TRACE_INFO("FTP context initialize...\r\n");
  ftpClientInit(&ftpClientContext);

  error = NO_ERROR;

  do
  {
    TRACE_INFO("Resolving server name...\r\n");
    if((error = getHostByName(NULL, APP_FTP_SERVER_NAME, &ipAddr, 0)) != NO_ERROR)
    {
      TRACE_INFO("Failed to resolve server name!\r\n");
      break;
    }

    TRACE_INFO("Set FTP Timeout...\r\n");
    if((error = ftpClientSetTimeout(&ftpClientContext, 20000)) != NO_ERROR)
    {
      TRACE_INFO("Failed to set timeout!\r\n");
      break;
    }

    TRACE_INFO("Connect to FTP server...\r\n");
    if((error = ftpClientConnect(&ftpClientContext, &ipAddr, APP_FTP_SERVER_PORT, FTP_MODE_PLAINTEXT|FTP_MODE_PASSIVE)) != NO_ERROR)
    {
      TRACE_INFO("Failed to connect to FTP server!\r\n");
      break;
    }

    TRACE_INFO("Login to FTP server...\r\n");
    if((error = ftpClientLogin(&ftpClientContext, APP_FTP_LOGIN, APP_FTP_PASSWORD)) != NO_ERROR)
    {
      TRACE_INFO("Failed to login to FTP server!\r\n");
      break;
    }

    TRACE_INFO("Open file to read from server...\r\n");
    if((error = ftpClientOpenFile(&ftpClientContext, APP_FTP_FILENAME, FTP_FILE_MODE_READ|FTP_FILE_MODE_BINARY)) != NO_ERROR)
    {
      TRACE_INFO("Failed to open file to read from server!\r\n");
      break;
    }

    while(!(error = ftpClientReadFile(&ftpClientContext, buffer, sizeof(buffer) - 1, &recv_len, 0)))
    {
      buffer[recv_len] = '\0';
      TRACE_INFO("%s", buffer);
    }

    TRACE_INFO("Close file...\r\n");
    if((error = ftpClientCloseFile(&ftpClientContext)) != NO_ERROR)
    {
      TRACE_INFO("Failed to close file!\r\n");
      break;
    }

    TRACE_INFO("Disconnect from FTP server...\r\n");
    if((error = ftpClientDisconnect(&ftpClientContext)) != NO_ERROR)
    {
      TRACE_INFO("Disconnect from FTP server!\r\n");
      break;
    }

  }while(0); //error handling while block

  TRACE_INFO("FTP context deinitialize...\r\n");
  ftpClientDeinit(&ftpClientContext);

  return error;
}

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

