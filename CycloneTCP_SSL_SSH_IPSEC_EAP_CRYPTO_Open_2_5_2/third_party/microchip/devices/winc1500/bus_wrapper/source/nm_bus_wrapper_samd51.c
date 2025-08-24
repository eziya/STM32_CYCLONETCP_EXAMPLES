/**
 * @file nm_bus_wrapper_samd51.c
 * @brief SPI bus wrapper for SAMD51 microcontrollers
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
#include <stdio.h>
#include "sam.h"
#include "bsp/include/nm_bsp.h"
#include "common/include/nm_common.h"
#include "bus_wrapper/include/nm_bus_wrapper.h"

//Maximum transfer size
#define NM_BUS_MAX_TRX_SZ 4096


/**
 * @brief Bus capabilities information
 **/

tstrNmBusCapabilities egstrNmBusCapabilities =
{
   NM_BUS_MAX_TRX_SZ
};


/**
 * @brief SPI transfer
 * @param[in] pu8Mosi The data to be written to the slave device
 * @param[out] pu8Miso The data received from the slave device
 * @param[in] u16Sz Number of bytes to be transferred
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

sint8 nm_spi_rw(uint8 *pu8Mosi, uint8 *pu8Miso, uint16 u16Sz)
{
   uint16_t i;
   uint8_t data;

   //Pull the CS pin low
   PORT_REGS->GROUP[CONF_WINC_CS_PIN / 32].PORT_OUTCLR = CONF_WINC_CS_MASK;

   //Perform SPI transfer
   for(i = 0; i < u16Sz; i++)
   {
      //Full-duplex transfer?
      if(pu8Mosi != NULL)
      {
         data = pu8Mosi[i];
      }
      else
      {
         data = 0x00;
      }

      //Ensure the TX buffer is empty
      while((CONF_WINC_SERCOM->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_DRE_Msk) == 0)
      {
      }

      //Write character
      CONF_WINC_SERCOM->SPIM.SERCOM_DATA = data;

      //Wait for the operation to complete
      while((CONF_WINC_SERCOM->SPIM.SERCOM_INTFLAG & SERCOM_SPIM_INTFLAG_RXC_Msk) == 0)
      {
      }

      //Read character
      data = CONF_WINC_SERCOM->SPIM.SERCOM_DATA;

      //Save the received character
      if(pu8Miso != NULL)
      {
         pu8Miso[i] = data;
      }
   }

   //Terminate the operation by raising the CS pin
   PORT_REGS->GROUP[CONF_WINC_CS_PIN / 32].PORT_OUTSET = CONF_WINC_CS_MASK;

   //Successful operation
   return M2M_SUCCESS;
}


/**
 * @brief SPI bus initialization
 * @param[in] pvinit Unused parameter
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

sint8 nm_bus_init(void *pvinit)
{
   //Enable SERCOM core clock
   GCLK_REGS->GCLK_PCHCTRL[CONF_WINC_SERCOM_GCLK_ID_CORE] = GCLK_PCHCTRL_GEN_GCLK0 |
      GCLK_PCHCTRL_CHEN_Msk;

   //Enable PORT bus clock (CLK_PORT_APB)
   MCLK_REGS->MCLK_APBBMASK |= MCLK_APBBMASK_PORT_Msk;;
   //Enable SERCOM bus clock (CLK_SERCOM_APB)
   CONF_WINC_SERCOM_APB_CLK_EN();

   //Configure SCK pin
   PORT_REGS->GROUP[CONF_WINC_SCK_PIN / 32].PORT_PINCFG[CONF_WINC_SCK_PIN % 32] |= PORT_PINCFG_DRVSTR_Msk;
   PORT_REGS->GROUP[CONF_WINC_SCK_PIN / 32].PORT_PINCFG[CONF_WINC_SCK_PIN % 32] |= PORT_PINCFG_PMUXEN_Msk;
   CONF_WINC_SCK_MUX();

   //Configure MOSI pin
   PORT_REGS->GROUP[CONF_WINC_MOSI_PIN / 32].PORT_PINCFG[CONF_WINC_MOSI_PIN % 32] |= PORT_PINCFG_DRVSTR_Msk;
   PORT_REGS->GROUP[CONF_WINC_MOSI_PIN / 32].PORT_PINCFG[CONF_WINC_MOSI_PIN % 32] |= PORT_PINCFG_PMUXEN_Msk;
   CONF_WINC_MOSI_MUX();

   //Configure MISO pin
   PORT_REGS->GROUP[CONF_WINC_MISO_PIN / 32].PORT_PINCFG[CONF_WINC_MISO_PIN % 32] |= PORT_PINCFG_DRVSTR_Msk;
   PORT_REGS->GROUP[CONF_WINC_MISO_PIN / 32].PORT_PINCFG[CONF_WINC_MISO_PIN % 32] |= PORT_PINCFG_PMUXEN_Msk;
   CONF_WINC_MISO_MUX();

   //Perform software reset
   CONF_WINC_SERCOM->SPIM.SERCOM_CTRLA = SERCOM_SPIM_CTRLA_SWRST_Msk;

   //Resetting the SERCOM (CTRLA.SWRST) requires synchronization
   while((CONF_WINC_SERCOM->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_SWRST_Msk) != 0)
   {
   }

   //Select master mode operation
   CONF_WINC_SERCOM->SPIM.SERCOM_CTRLA = SERCOM_SPIM_CTRLA_DIPO(CONF_WINC_SERCOM_DIPO) |
      SERCOM_SPIM_CTRLA_DOPO(CONF_WINC_SERCOM_DOPO) | SERCOM_SPIM_CTRLA_MODE(3);

   //Configure clock divider
   CONF_WINC_SERCOM->SPIM.SERCOM_BAUD = SystemCoreClock / (2 * CONF_WINC_SPI_CLOCK) - 1;

   //Enable the receiver
   CONF_WINC_SERCOM->SPIM.SERCOM_CTRLB = SERCOM_SPIM_CTRLB_RXEN_Msk;

   //Writing to the CTRLB register when the SERCOM is enabled requires
   //synchronization
   while((CONF_WINC_SERCOM->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_CTRLB_Msk) != 0)
   {
   }

   //Enable SERCOM
   CONF_WINC_SERCOM->SPIM.SERCOM_CTRLA |= SERCOM_SPIM_CTRLA_ENABLE_Msk;

   //Enabling and disabling the SERCOM requires synchronization
   while((CONF_WINC_SERCOM->SPIM.SERCOM_SYNCBUSY & SERCOM_SPIM_SYNCBUSY_ENABLE_Msk) != 0)
   {
   }

   //Reset WINC1500
   nm_bsp_reset();

   //Successful operation
   return M2M_SUCCESS;
}


/**
 * @brief IOCTL command processing
 * @param[in] u8Cmd Command opcode
 * @param[in] pvParameter Command parameters
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

sint8 nm_bus_ioctl(uint8 u8Cmd, void *pvParameter)
{
   sint8 ret;
#ifdef CONF_WINC_USE_SPI
   tstrNmSpiRw *spiRwParams;
#endif

   //Check commande opcode
   switch(u8Cmd)
   {
#ifdef CONF_WINC_USE_SPI
   //Read/write command?
   case NM_BUS_IOCTL_RW:
      //Retrieve command parameters
      spiRwParams = (tstrNmSpiRw *) pvParameter;
      //Perform SPI transfer
      ret = nm_spi_rw(spiRwParams->pu8InBuf, spiRwParams->pu8OutBuf, spiRwParams->u16Sz);
      break;
#endif
   //Invalid command?
   default:
      //Debug message
      M2M_ERR("Invalid IOCTL command!\r\n");
      //Report an error
      ret = M2M_ERR_BUS_FAIL;
      break;
   }

   //Return status code
   return ret;
}


/**
 * @brief SPI bus deinitialization
 * @param[in] pvinit Unused parameter
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

sint8 nm_bus_deinit(void)
{
   //Not implemented
   return M2M_SUCCESS;
}
