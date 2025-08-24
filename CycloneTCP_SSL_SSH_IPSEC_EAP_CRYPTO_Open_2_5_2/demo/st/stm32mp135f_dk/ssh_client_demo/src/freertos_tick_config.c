#include "stm32mp13xx.h"
#include "stm32mp13xx_hal.h"
#include "FreeRTOS.h"
#include "task.h"

//Global variables
TIM_HandleTypeDef TIM_Handle;

//Forward declaration of functions
void TIM6_IRQHandler(void);


void vConfigureTickInterrupt(void)
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

   //Set interrupt handler
   IRQ_SetHandler(TIM6_IRQn, TIM6_IRQHandler);
   //Configure TIM6 interrupt priority
   IRQ_SetPriority(TIM6_IRQn, 0U);
   //Enable TIM6 interrupts
   IRQ_Enable(TIM6_IRQn);
}


void TIM6_IRQHandler(void)
{
   if(TIM_Handle.Instance != NULL)
   {
      HAL_TIM_IRQHandler(&TIM_Handle);
      FreeRTOS_Tick_Handler();
   }
   else
   {
      IRQ_Disable(TIM6_IRQn);
   }
}


void vApplicationFPUSafeIRQHandler( uint32_t ulICCIAR )
{
   uint32_t id;
   IRQHandler_t handler;

   //Re-enable interrupts
   __asm ( "cpsie i" );

   //Get the ID of the interrupt
   id = ulICCIAR & 0x3FFUL;

   if(id < MAX_IRQ_n)
   {
      handler = IRQ_GetHandler(id);
      handler();
   }
}
