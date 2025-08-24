/**
 * @file nm_bsp_samd51.c
 * @brief BSP for SAMD51 microcontrollers
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
#include "sam.h"
#include "bsp/include/nm_bsp.h"
#include "common/include/nm_common.h"
#include "core/net.h"
#include "drivers/wifi/winc3400_driver.h"

//IRQ handler
static tpfNmBspIsr gpfIsr;


/**
 * @brief GPIO initialization
 **/

static void init_chip_pins(void)
{
   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_PORT_Msk;

   //Configure RST pin
   PORT_REGS->GROUP[CONF_WINC_RST_PIN / 32].PORT_DIRSET = CONF_WINC_RST_MASK;
   PORT_REGS->GROUP[CONF_WINC_RST_PIN / 32].PORT_OUTCLR = CONF_WINC_RST_MASK;

   //Configure CE pin
   PORT_REGS->GROUP[CONF_WINC_CE_PIN / 32].PORT_DIRSET = CONF_WINC_CE_MASK;
   PORT_REGS->GROUP[CONF_WINC_CE_PIN / 32].PORT_OUTCLR = CONF_WINC_CE_MASK;

   //Configure WAKE pin
   PORT_REGS->GROUP[CONF_WINC_WAKE_PIN / 32].PORT_DIRSET = CONF_WINC_WAKE_MASK;
   PORT_REGS->GROUP[CONF_WINC_WAKE_PIN / 32].PORT_OUTCLR = CONF_WINC_WAKE_MASK;

   //Configure CS pin
   PORT_REGS->GROUP[CONF_WINC_CS_PIN / 32].PORT_DIRSET = CONF_WINC_CS_MASK;
   PORT_REGS->GROUP[CONF_WINC_CS_PIN / 32].PORT_OUTSET = CONF_WINC_CS_MASK;
   PORT_REGS->GROUP[CONF_WINC_CS_PIN / 32].PORT_PINCFG[CONF_WINC_CS_PIN % 32] |= PORT_PINCFG_DRVSTR_Msk;

   //Configure IRQ pin
   PORT_REGS->GROUP[CONF_WINC_IRQ_PIN / 32].PORT_DIRCLR = CONF_WINC_IRQ_MASK;
   PORT_REGS->GROUP[CONF_WINC_IRQ_PIN / 32].PORT_OUTSET = CONF_WINC_IRQ_MASK;
   PORT_REGS->GROUP[CONF_WINC_IRQ_PIN / 32].PORT_PINCFG[CONF_WINC_IRQ_PIN % 32] |= PORT_PINCFG_PULLEN_Msk;
   PORT_REGS->GROUP[CONF_WINC_IRQ_PIN / 32].PORT_PINCFG[CONF_WINC_IRQ_PIN % 32] |= PORT_PINCFG_INEN_Msk;
   PORT_REGS->GROUP[CONF_WINC_IRQ_PIN / 32].PORT_PINCFG[CONF_WINC_IRQ_PIN % 32] |= PORT_PINCFG_PMUXEN_Msk;
   CONF_WINC_IRQ_MUX();
}


/**
 * @brief BSP initialization
 * @return Status code
 **/

sint8 nm_bsp_init(void)
{
   //Initialize IRQ handler
   gpfIsr = NULL;

   //Initialize WINC3400 pins
   init_chip_pins();

   //Reset WINC3400 chip
   nm_bsp_reset();

   //No error to report
   return M2M_SUCCESS;
}


/**
 * @brief Reset chip
 **/

void nm_bsp_reset(void)
{
   //Debug message
   M2M_PRINT("nm_bsp_reset\r\n");

   //Set CE and RST pins low
   PORT_REGS->GROUP[CONF_WINC_CE_PIN / 32].PORT_OUTCLR = CONF_WINC_CE_MASK;
   PORT_REGS->GROUP[CONF_WINC_RST_PIN / 32].PORT_OUTCLR = CONF_WINC_RST_MASK;
   nm_bsp_sleep(100);

   //Set CE pin high
   PORT_REGS->GROUP[CONF_WINC_CE_PIN / 32].PORT_OUTSET = CONF_WINC_CE_MASK;
   nm_bsp_sleep(100);

   //Set RST pin high
   PORT_REGS->GROUP[CONF_WINC_RST_PIN / 32].PORT_OUTSET = CONF_WINC_RST_MASK;
   nm_bsp_sleep(100);
}


/**
 * @brief Delay routine
 * @param[in] u32TimeMsec Time interval in milliseconds
 **/

void nm_bsp_sleep(uint32 u32TimeMsec)
{
   while(u32TimeMsec--)
   {
      sleep(1);
   }
}

/**
 * @brief Register interrupt service routine
 * @param[in] pfIsr ISR handler
 **/

void nm_bsp_register_isr(tpfNmBspIsr pfIsr)
{
   //Save ISR handler
   gpfIsr = pfIsr;

   //Enable EIC core clock
   GCLK_REGS->GCLK_PCHCTRL[EIC_GCLK_ID] = GCLK_PCHCTRL_GEN_GCLK0 |
      GCLK_PCHCTRL_CHEN_Msk;

   //Enable EIC bus clock (CLK_EIC_APB)
   MCLK_REGS->MCLK_APBAMASK |= MCLK_APBAMASK_EIC_Msk;

   //Configure the EIC input sense and filtering
   CONF_WINC_IRQ_CONFIG();

   //Enable the EIC
   EIC_REGS->EIC_CTRLA |= EIC_CTRLA_ENABLE_Msk;

   //Enabling and disabling the EIC requires synchronization
   while((EIC_REGS->EIC_SYNCBUSY & EIC_SYNCBUSY_ENABLE_Msk) != 0)
   {
   }

   //Enable external interrupts
   EIC_REGS->EIC_INTENSET = CONF_WINC_IRQ_MASK;

   //Set priority grouping
   NVIC_SetPriorityGrouping(CONF_WINC_IRQ_PRIORITY_GROUPING);

   //Configure EIC interrupt priority
   NVIC_SetPriority(CONF_WINC_IRQn, NVIC_EncodePriority(CONF_WINC_IRQ_PRIORITY_GROUPING,
      CONF_WINC_IRQ_GROUP_PRIORITY, CONF_WINC_IRQ_SUB_PRIORITY));

   //Enable EIC interrupt
   NVIC_EnableIRQ(CONF_WINC_IRQn);
   NVIC_SetPendingIRQ(CONF_WINC_IRQn);
}


/**
 * @brief Enable/disable interrupts
 * @param[in] u8Enable Interrupt enable state
 **/

void nm_bsp_interrupt_ctrl(uint8 u8Enable)
{
   if(u8Enable)
   {
      //Enable external interrupt
      NVIC_EnableIRQ(CONF_WINC_IRQn);
   }
   else
   {
      //Disable external interrupt
      NVIC_DisableIRQ(CONF_WINC_IRQn);
   }
}


/**
 * @brief IRQ handler
 **/

void CONF_WINC_IRQHandler(void)
{
   bool_t flag;

   //Enter interrupt service routine
   osEnterIsr();

   //This flag will be set if a higher priority task must be woken
   flag = FALSE;

   //Clear interrupt flag
   EIC_REGS->EIC_INTFLAG = CONF_WINC_IRQ_MASK;

   //Ensure the IRQ pin is asserted
   if(!(PORT_REGS->GROUP[CONF_WINC_IRQ_PIN / 32].PORT_IN & CONF_WINC_IRQ_MASK))
   {
      //WINC3400 interrupt processing
      if(gpfIsr != NULL)
         gpfIsr();

      //Call interrupt handler
      flag = winc3400IrqHandler();
   }

   //Leave interrupt service routine
   osExitIsr(flag);
}
