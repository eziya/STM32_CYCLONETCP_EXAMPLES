/**
 * @file nm_bsp_ra6.c
 * @brief BSP for RA6 microcontrollers
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
#include "bsp_api.h"
#include "bsp/include/nm_bsp.h"
#include "common/include/nm_common.h"
#include "core/net.h"
#include "drivers/wifi/winc1500_driver.h"

//IRQ handler
static tpfNmBspIsr gpfIsr;


/**
 * @brief GPIO initialization
 **/

static void init_chip_pins(void)
{
   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure RST pin
   R_PFS->CONF_WINC_RST_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;
   //Configure CE pin
   R_PFS->CONF_WINC_CE_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;
   //Configure WAKE pin
   R_PFS->CONF_WINC_WAKE_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;
   //Configure CS pin
   R_PFS->CONF_WINC_CS_PFS = R_PFS_PORT_PIN_PmnPFS_PDR_Msk;
   //Configure IRQ pin
   R_PFS->CONF_WINC_IRQ_PFS = R_PFS_PORT_PIN_PmnPFS_ISEL_Msk;

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Set default state for RST pin
   CONF_WINC_RST_PORT->PCNTR3 = CONF_WINC_RST_MASK << R_PORT0_PCNTR3_PORR_Pos;
   //Set default state for CE pin
   CONF_WINC_CE_PORT->PCNTR3 = CONF_WINC_CE_MASK << R_PORT0_PCNTR3_PORR_Pos;
   //Set default state for WAKE pin
   CONF_WINC_WAKE_PORT->PCNTR3 = CONF_WINC_WAKE_MASK << R_PORT0_PCNTR3_PORR_Pos;
   //Set default state for CS pin
   CONF_WINC_CS_PORT->PCNTR3 = CONF_WINC_CS_MASK << R_PORT0_PCNTR3_POSR_Pos;

   //Set digital filter sampling clock (PCLK)
   R_ICU->IRQCR_b[CONF_WINC_IRQ_NUM].FCLKSEL = 0;
   //Enable digital filter
   R_ICU->IRQCR_b[CONF_WINC_IRQ_NUM].FLTEN = 1;
   //Configure IRQ polarity (falling edge)
   R_ICU->IRQCR_b[CONF_WINC_IRQ_NUM].IRQMD = 0;

   //Redirect the event to the NVIC
   R_ICU->IELSR_b[CONF_WINC_IRQn].DTCE = 0;
}


/**
 * @brief BSP initialization
 * @return Status code
 **/

sint8 nm_bsp_init(void)
{
   //Initialize IRQ handler
   gpfIsr = NULL;

   //Initialize WINC1500 pins
   init_chip_pins();

   //Reset WINC1500 chip
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
   CONF_WINC_CE_PORT->PCNTR3 = CONF_WINC_CE_MASK << R_PORT0_PCNTR3_PORR_Pos;
   CONF_WINC_RST_PORT->PCNTR3 = CONF_WINC_RST_MASK << R_PORT0_PCNTR3_PORR_Pos;
   nm_bsp_sleep(100);

   //Set CE pin high
   CONF_WINC_CE_PORT->PCNTR3 = CONF_WINC_CE_MASK << R_PORT0_PCNTR3_POSR_Pos;
   nm_bsp_sleep(100);

   //Set RST pin high
   CONF_WINC_RST_PORT->PCNTR3 = CONF_WINC_RST_MASK << R_PORT0_PCNTR3_POSR_Pos;
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

   //Set priority grouping
   NVIC_SetPriorityGrouping(CONF_WINC_IRQ_PRIORITY_GROUPING);

   //Configure ICU interrupt priority
   NVIC_SetPriority(CONF_WINC_IRQn, NVIC_EncodePriority(CONF_WINC_IRQ_PRIORITY_GROUPING,
      CONF_WINC_IRQ_GROUP_PRIORITY, CONF_WINC_IRQ_SUB_PRIORITY));

   //Enable ICU interrupts
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
      //Enable ICU interrupts
      NVIC_EnableIRQ(CONF_WINC_IRQn);
   }
   else
   {
      //Disable ICU interrupts
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
   R_ICU->IELSR_b[CONF_WINC_IRQn].IR = 0;

   //WINC1500 interrupt processing
   if(gpfIsr != NULL)
   {
      gpfIsr();
   }

   //Call interrupt handler
   flag = winc1500IrqHandler();

   //Leave interrupt service routine
   osExitIsr(flag);
}
