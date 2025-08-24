/**
 * @file ext_int_driver.c
 * @brief External interrupt line driver
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
#include "stm32g4xx.h"
#include "core/net.h"
#include "drivers/eth/w3150a_driver.h"
#include "drivers/eth/w5100_driver.h"
#include "drivers/eth/w5100s_driver.h"
#include "drivers/eth/w5200_driver.h"
#include "drivers/eth/w5500_driver.h"
#include "drivers/eth/w6100_driver.h"
#include "ext_int_driver.h"
#include "debug.h"


/**
 * @brief External interrupt line driver
 **/

const ExtIntDriver extIntDriver =
{
   extIntInit,
   extIntEnableIrq,
   extIntDisableIrq
};


/**
 * @brief EXTI configuration
 * @return Error code
 **/

error_t extIntInit(void)
{
   GPIO_InitTypeDef GPIO_InitStructure;

   //Enable GPIOA clock
   __HAL_RCC_GPIOA_CLK_ENABLE();
   //Enable SYSCFG clock
   __HAL_RCC_SYSCFG_CLK_ENABLE();

   //Configure IRQ pin
   GPIO_InitStructure.Pin = GPIO_PIN_10;
   GPIO_InitStructure.Mode = GPIO_MODE_IT_FALLING;
   GPIO_InitStructure.Pull = GPIO_PULLUP;
   HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

   //Set priority grouping
   NVIC_SetPriorityGrouping(3);
   //Configure interrupt priority
   NVIC_SetPriority(EXTI15_10_IRQn, NVIC_EncodePriority(3, 15, 0));

   //Set EXTI interrupt to pending
   NVIC_SetPendingIRQ(EXTI15_10_IRQn);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Enable external interrupts
 **/

void extIntEnableIrq(void)
{
   //Enable EXTI interrupts
   NVIC_EnableIRQ(EXTI15_10_IRQn);
}


/**
 * @brief Disable external interrupts
 **/

void extIntDisableIrq(void)
{
   //Disable EXTI interrupts
   NVIC_DisableIRQ(EXTI15_10_IRQn);
}


/**
 * @brief External interrupt handler
 **/

void EXTI15_10_IRQHandler(void)
{
   bool_t flag;
   NetInterface *interface;

   //Enter interrupt service routine
   osEnterIsr();

   //Point to the structure describing the network interface
   interface = &netInterface[0];
   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Check interrupt status
   if(__HAL_GPIO_EXTI_GET_IT(GPIO_PIN_10) != RESET)
   {
      //Clear interrupt flag
      __HAL_GPIO_EXTI_CLEAR_IT(GPIO_PIN_10);

#if defined(USE_W3150A)
      //Call interrupt handler
      flag = w3150aIrqHandler(interface);
#elif defined(USE_W5100)
      //Call interrupt handler
      flag = w5100IrqHandler(interface);
#elif defined(USE_W5100S)
      //Call interrupt handler
      flag = w5100sIrqHandler(interface);
#elif defined(USE_W5200)
      //Call interrupt handler
      flag = w5200IrqHandler(interface);
#elif defined(USE_W5500)
      //Call interrupt handler
      flag = w5500IrqHandler(interface);
#elif defined(USE_W6100)
      //Call interrupt handler
      flag = w6100IrqHandler(interface);
#endif
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
