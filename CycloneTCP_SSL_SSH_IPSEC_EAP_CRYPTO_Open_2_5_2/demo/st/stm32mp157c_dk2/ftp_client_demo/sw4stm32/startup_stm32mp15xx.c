//Dependencies
#include "stm32mp157cxx_cm4.h"

//Linker file constants
extern uint32_t _sidata;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _estack;

//Function declaration
void SystemInit(void);
void __libc_init_array(void);
int main(void);

//Default empty handler
void Default_Handler(void);

//Cortex-M4 core handlers
void Reset_Handler             (void);
void NMI_Handler               (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler         (void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler        (void) __attribute__((weak, alias("Default_Handler")));
void SVC_Handler               (void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler          (void) __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler            (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler           (void) __attribute__((weak, alias("Default_Handler")));

//Peripheral handlers
void WWDG1_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void PVD_AVD_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void TAMP_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_ALARM_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void RESERVED4_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void ADC1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN1_IT0_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN2_IT0_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN1_IT1_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN2_IT1_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void EXTI5_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EXTI10_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void RTC_TIMESTAMP_IRQHandler  (void) __attribute__((weak, alias("Default_Handler")));
void EXTI11_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void FMC_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void SDMMC1_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void TIM6_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void ETH1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void ETH1_WKUP_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN_CAL_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void EXTI6_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void EXTI7_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void EXTI8_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void EXTI9_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler   (void) __attribute__((weak, alias("Default_Handler")));
void USART6_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void USBH_OHCI_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void USBH_EHCI_IRQHandler      (void) __attribute__((weak, alias("Default_Handler")));
void EXTI12_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void EXTI13_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void DCMI_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void CRYP1_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void HASH1_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void UART7_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void UART8_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void SPI4_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void SPI5_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void SPI6_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void SAI1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void LTDC_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void LTDC_ER_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void ADC2_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void SAI2_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void QUADSPI_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void LPTIM1_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void CEC_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void I2C4_EV_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void I2C4_ER_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void SPDIF_RX_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void OTG_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void RESERVED99_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void IPCC_RX0_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void IPCC_TX0_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void DMAMUX1_OVR_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void IPCC_RX1_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void IPCC_TX1_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void CRYP2_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void HASH2_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void I2C5_EV_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void I2C5_ER_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void GPU_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT0_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT1_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT2_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT3_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void SAI3_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT4_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void TIM15_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void TIM16_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void TIM17_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void TIM12_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void MDIOS_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void EXTI14_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void MDMA_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DSI_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void SDMMC2_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void HSEM_IT2_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT5_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void nCTIIRQ1_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void nCTIIRQ2_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void TIM13_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void TIM14_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void DAC_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void RNG1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void RNG2_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void I2C6_EV_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void I2C6_ER_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void SDMMC3_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void LPTIM2_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void LPTIM3_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void LPTIM4_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void LPTIM5_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void ETH1_LPI_IRQHandler       (void) __attribute__((weak, alias("Default_Handler")));
void RESERVED143_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void MPU_SEV_IRQHandler        (void) __attribute__((weak, alias("Default_Handler")));
void RCC_WAKEUP_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void SAI4_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DTS_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void RESERVED148_IRQHandler    (void) __attribute__((weak, alias("Default_Handler")));
void WAKEUP_PIN_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));

//Vector table
__attribute__((section(".isr_vector")))
const uint32_t vectorTable[166] =
{
   //Initial stack pointer
   (uint32_t) (&_estack),

   //Core handlers
   (uint32_t) Reset_Handler,
   (uint32_t) NMI_Handler,
   (uint32_t) HardFault_Handler,
   (uint32_t) MemManage_Handler,
   (uint32_t) BusFault_Handler,
   (uint32_t) UsageFault_Handler,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) 0,
   (uint32_t) SVC_Handler,
   (uint32_t) DebugMon_Handler,
   (uint32_t) 0,
   (uint32_t) PendSV_Handler,
   (uint32_t) SysTick_Handler,

   //Peripheral handlers
   (uint32_t) WWDG1_IRQHandler,          //Window WatchDog 1
   (uint32_t) PVD_AVD_IRQHandler,        //PVD and AVD through EXTI Line detection
   (uint32_t) TAMP_IRQHandler,           //Tamper and TimeStamps through the EXTI line
   (uint32_t) RTC_WKUP_ALARM_IRQHandler, //RTC Wakeup and Alarm through the EXTI line
   (uint32_t) RESERVED4_IRQHandler,      //Reserved
   (uint32_t) RCC_IRQHandler,            //RCC
   (uint32_t) EXTI0_IRQHandler,          //EXTI Line0
   (uint32_t) EXTI1_IRQHandler,          //EXTI Line1
   (uint32_t) EXTI2_IRQHandler,          //EXTI Line2
   (uint32_t) EXTI3_IRQHandler,          //EXTI Line3
   (uint32_t) EXTI4_IRQHandler,          //EXTI Line4
   (uint32_t) DMA1_Stream0_IRQHandler,   //DMA1 Stream 0
   (uint32_t) DMA1_Stream1_IRQHandler,   //DMA1 Stream 1
   (uint32_t) DMA1_Stream2_IRQHandler,   //DMA1 Stream 2
   (uint32_t) DMA1_Stream3_IRQHandler,   //DMA1 Stream 3
   (uint32_t) DMA1_Stream4_IRQHandler,   //DMA1 Stream 4
   (uint32_t) DMA1_Stream5_IRQHandler,   //DMA1 Stream 5
   (uint32_t) DMA1_Stream6_IRQHandler,   //DMA1 Stream 6
   (uint32_t) ADC1_IRQHandler,           //ADC1
   (uint32_t) FDCAN1_IT0_IRQHandler,     //FDCAN1 Interrupt line 0
   (uint32_t) FDCAN2_IT0_IRQHandler,     //FDCAN2 Interrupt line 0
   (uint32_t) FDCAN1_IT1_IRQHandler,     //FDCAN1 Interrupt line 1
   (uint32_t) FDCAN2_IT1_IRQHandler,     //FDCAN2 Interrupt line 1
   (uint32_t) EXTI5_IRQHandler,          //External Line5 interrupts through AIEC
   (uint32_t) TIM1_BRK_IRQHandler,       //TIM1 Break interrupt
   (uint32_t) TIM1_UP_IRQHandler,        //TIM1 Update Interrupt
   (uint32_t) TIM1_TRG_COM_IRQHandler,   //TIM1 Trigger and Commutation Interrupt
   (uint32_t) TIM1_CC_IRQHandler,        //TIM1 Capture Compare
   (uint32_t) TIM2_IRQHandler,           //TIM2
   (uint32_t) TIM3_IRQHandler,           //TIM3
   (uint32_t) TIM4_IRQHandler,           //TIM4
   (uint32_t) I2C1_EV_IRQHandler,        //I2C1 Event
   (uint32_t) I2C1_ER_IRQHandler,        //I2C1 Error
   (uint32_t) I2C2_EV_IRQHandler,        //I2C2 Event
   (uint32_t) I2C2_ER_IRQHandler,        //I2C2 Error
   (uint32_t) SPI1_IRQHandler,           //SPI1
   (uint32_t) SPI2_IRQHandler,           //SPI2
   (uint32_t) USART1_IRQHandler,         //USART1
   (uint32_t) USART2_IRQHandler,         //USART2
   (uint32_t) USART3_IRQHandler,         //USART3
   (uint32_t) EXTI10_IRQHandler,         //External Line10 interrupts through AIEC
   (uint32_t) RTC_TIMESTAMP_IRQHandler,  //RTC TimeStamp through EXTI Line
   (uint32_t) EXTI11_IRQHandler,         //External Line11 interrupts through AIEC
   (uint32_t) TIM8_BRK_IRQHandler,       //TIM8 Break Interrupt
   (uint32_t) TIM8_UP_IRQHandler,        //TIM8 Update Interrupt
   (uint32_t) TIM8_TRG_COM_IRQHandler,   //TIM8 Trigger and Commutation Interrupt
   (uint32_t) TIM8_CC_IRQHandler,        //TIM8 Capture Compare Interrupt
   (uint32_t) DMA1_Stream7_IRQHandler,   //DMA1 Stream7
   (uint32_t) FMC_IRQHandler,            //FMC
   (uint32_t) SDMMC1_IRQHandler,         //SDMMC1
   (uint32_t) TIM5_IRQHandler,           //TIM5
   (uint32_t) SPI3_IRQHandler,           //SPI3
   (uint32_t) UART4_IRQHandler,          //UART4
   (uint32_t) UART5_IRQHandler,          //UART5
   (uint32_t) TIM6_IRQHandler,           //TIM6
   (uint32_t) TIM7_IRQHandler,           //TIM7
   (uint32_t) DMA2_Stream0_IRQHandler,   //DMA2 Stream 0
   (uint32_t) DMA2_Stream1_IRQHandler,   //DMA2 Stream 1
   (uint32_t) DMA2_Stream2_IRQHandler,   //DMA2 Stream 2
   (uint32_t) DMA2_Stream3_IRQHandler,   //DMA2 Stream 3
   (uint32_t) DMA2_Stream4_IRQHandler,   //DMA2 Stream 4
   (uint32_t) ETH1_IRQHandler,            //Ethernet
   (uint32_t) ETH1_WKUP_IRQHandler,       //Ethernet Wakeup through EXTI line
   (uint32_t) FDCAN_CAL_IRQHandler,       //FDCAN Calibration
   (uint32_t) EXTI6_IRQHandler,          //EXTI Line6 interrupts through AIEC
   (uint32_t) EXTI7_IRQHandler,          //EXTI Line7 interrupts through AIEC
   (uint32_t) EXTI8_IRQHandler,          //EXTI Line8 interrupts through AIEC
   (uint32_t) EXTI9_IRQHandler,          //EXTI Line9 interrupts through AIEC
   (uint32_t) DMA2_Stream5_IRQHandler,   //DMA2 Stream 5
   (uint32_t) DMA2_Stream6_IRQHandler,   //DMA2 Stream 6
   (uint32_t) DMA2_Stream7_IRQHandler,   //DMA2 Stream 7
   (uint32_t) USART6_IRQHandler,         //USART6
   (uint32_t) I2C3_EV_IRQHandler,        //I2C3 event
   (uint32_t) I2C3_ER_IRQHandler,        //I2C3 error
   (uint32_t) USBH_OHCI_IRQHandler,      //USB Host OHCI
   (uint32_t) USBH_EHCI_IRQHandler,      //USB Host EHCI
   (uint32_t) EXTI12_IRQHandler,         //EXTI Line12 interrupts through AIEC
   (uint32_t) EXTI13_IRQHandler,         //EXTI Line13 interrupts through AIEC
   (uint32_t) DCMI_IRQHandler,           //DCMI
   (uint32_t) CRYP1_IRQHandler,          //Crypto1 global interrupt
   (uint32_t) HASH1_IRQHandler,          //Crypto Hash1 interrupt
   (uint32_t) FPU_IRQHandler,            //FPU
   (uint32_t) UART7_IRQHandler,          //UART7
   (uint32_t) UART8_IRQHandler,          //UART8
   (uint32_t) SPI4_IRQHandler,           //SPI4
   (uint32_t) SPI5_IRQHandler,           //SPI5
   (uint32_t) SPI6_IRQHandler,           //SPI6
   (uint32_t) SAI1_IRQHandler,           //SAI1
   (uint32_t) LTDC_IRQHandler,           //LTDC
   (uint32_t) LTDC_ER_IRQHandler,        //LTDC error
   (uint32_t) ADC2_IRQHandler,           //ADC2
   (uint32_t) SAI2_IRQHandler,           //SAI2
   (uint32_t) QUADSPI_IRQHandler,        //QUADSPI
   (uint32_t) LPTIM1_IRQHandler,         //LPTIM1 global interrupt
   (uint32_t) CEC_IRQHandler,            //HDMI_CEC
   (uint32_t) I2C4_EV_IRQHandler,        //I2C4 Event
   (uint32_t) I2C4_ER_IRQHandler,        //I2C4 Error
   (uint32_t) SPDIF_RX_IRQHandler,       //SPDIF_RX
   (uint32_t) OTG_IRQHandler,            //USB On The Go HS global interrupt
   (uint32_t) RESERVED99_IRQHandler,     //Reserved
   (uint32_t) IPCC_RX0_IRQHandler,       //Mailbox RX0 Free interrupt
   (uint32_t) IPCC_TX0_IRQHandler,       //Mailbox TX0 Free interrupt
   (uint32_t) DMAMUX1_OVR_IRQHandler,    //DMAMUX1 Overrun interrupt
   (uint32_t) IPCC_RX1_IRQHandler,       //Mailbox RX1 Free interrupt
   (uint32_t) IPCC_TX1_IRQHandler,       //Mailbox TX1 Free interrupt
   (uint32_t) CRYP2_IRQHandler,          //Crypto2 global interrupt
   (uint32_t) HASH2_IRQHandler,          //Crypto Hash2 interrupt
   (uint32_t) I2C5_EV_IRQHandler,        //I2C5 Event Interrupt
   (uint32_t) I2C5_ER_IRQHandler,        //I2C5 Error Interrupt
   (uint32_t) GPU_IRQHandler,            //GPU Global Interrupt
   (uint32_t) DFSDM1_FLT0_IRQHandler,    //DFSDM Filter0 Interrupt
   (uint32_t) DFSDM1_FLT1_IRQHandler,    //DFSDM Filter1 Interrupt
   (uint32_t) DFSDM1_FLT2_IRQHandler,    //DFSDM Filter2 Interrupt
   (uint32_t) DFSDM1_FLT3_IRQHandler,    //DFSDM Filter3 Interrupt
   (uint32_t) SAI3_IRQHandler,           //SAI3 global Interrupt
   (uint32_t) DFSDM1_FLT4_IRQHandler,    //DFSDM Filter4 Interrupt
   (uint32_t) TIM15_IRQHandler,          //TIM15 global Interrupt
   (uint32_t) TIM16_IRQHandler,          //TIM16 global Interrupt
   (uint32_t) TIM17_IRQHandler,          //TIM17 global Interrupt
   (uint32_t) TIM12_IRQHandler,          //TIM12 global Interrupt
   (uint32_t) MDIOS_IRQHandler,          //MDIOS global Interrupt
   (uint32_t) EXTI14_IRQHandler,         //EXTI Line14 interrupts through AIEC
   (uint32_t) MDMA_IRQHandler,           //MDMA global Interrupt
   (uint32_t) DSI_IRQHandler,            //DSI global Interrupt
   (uint32_t) SDMMC2_IRQHandler,         //SDMMC2 global Interrupt
   (uint32_t) HSEM_IT2_IRQHandler,       //HSEM global Interrupt
   (uint32_t) DFSDM1_FLT5_IRQHandler,    //DFSDM Filter5 Interrupt
   (uint32_t) EXTI15_IRQHandler,         //EXTI Line15 interrupts through AIEC
   (uint32_t) nCTIIRQ1_IRQHandler,       //Cortex-M4 CTI interrupt 1
   (uint32_t) nCTIIRQ2_IRQHandler,       //Cortex-M4 CTI interrupt 2
   (uint32_t) TIM13_IRQHandler,          //TIM13 global interrupt
   (uint32_t) TIM14_IRQHandler,          //TIM14 global interrupt
   (uint32_t) DAC_IRQHandler,            //DAC1 and DAC2 underrun error interrupts
   (uint32_t) RNG1_IRQHandler,           //RNG1 interrupt
   (uint32_t) RNG2_IRQHandler,           //RNG2 interrupt
   (uint32_t) I2C6_EV_IRQHandler,        //I2C6 Event Interrupt
   (uint32_t) I2C6_ER_IRQHandler,        //I2C6 Error Interrupt
   (uint32_t) SDMMC3_IRQHandler,         //SDMMC3 global Interrupt
   (uint32_t) LPTIM2_IRQHandler,         //LPTIM2 global interrupt
   (uint32_t) LPTIM3_IRQHandler,         //LPTIM3 global interrupt
   (uint32_t) LPTIM4_IRQHandler,         //LPTIM4 global interrupt
   (uint32_t) LPTIM5_IRQHandler,         //LPTIM5 global interrupt
   (uint32_t) ETH1_LPI_IRQHandler,       //ETH1_LPI interrupt
   (uint32_t) RESERVED143_IRQHandler,    //Reserved
   (uint32_t) MPU_SEV_IRQHandler,        //MPU Send Event through AIEC
   (uint32_t) RCC_WAKEUP_IRQHandler,     //RCC Wake up interrupt
   (uint32_t) SAI4_IRQHandler,           //SAI4 global interrupt
   (uint32_t) DTS_IRQHandler,            //Temperature sensor interrupt
   (uint32_t) RESERVED148_IRQHandler,    //Reserved
   (uint32_t) WAKEUP_PIN_IRQHandler,     //Interrupt for all 6 wake-up pins
};


/**
 * @brief Reset handler
 **/

void Reset_Handler(void)
{
   uint32_t *src;
   uint32_t *dest;

   //Set stack pointer
   __set_MSP((uint32_t) &_estack);

   //System initialization
   SystemInit();

   //Initialize the relocate segment
   src = &_sidata;
   dest = &_sdata;

   if(src != dest)
   {
      while(dest < &_edata)
      {
         *dest++ = *src++;
      }
   }

   //Clear the zero segment
   for(dest = &_sbss; dest < &_ebss;)
   {
      *dest++ = 0;
   }

   //C library initialization
   __libc_init_array();

   //Branch to main function
   main();

   //Endless loop
   while(1);
}


/**
 * @brief Default interrupt handler
 **/

void Default_Handler(void)
{
   while(1)
   {
   }
}
