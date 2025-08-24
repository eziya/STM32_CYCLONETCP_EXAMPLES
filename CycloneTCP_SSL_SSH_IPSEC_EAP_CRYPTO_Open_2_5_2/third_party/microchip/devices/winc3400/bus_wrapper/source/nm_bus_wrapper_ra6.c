/**
 * @file nm_bus_wrapper_ra6.c
 * @brief SPI bus wrapper for RA6 microcontrollers
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
 * @version 2.2.2
 **/

//Dependencies
#include <stdio.h>
#include "bsp_api.h"
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
   CONF_WINC_CS_PORT->PCNTR3 = CONF_WINC_CS_MASK << R_PORT0_PCNTR3_PORR_Pos;

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

      //Clear error sources
      CONF_WINC_SPI->SPSR &= ~(R_SPI0_SPSR_MODF_Msk | R_SPI0_SPSR_OVRF_Msk |
         R_SPI0_SPSR_PERF_Msk | R_SPI0_SPSR_UDRF_Msk);

      //Enable SPI receive buffer full interrupt
      CONF_WINC_SPI->SPCR |= R_SPI0_SPCR_SPRIE_Msk;

      //Wait for the transmitter to be ready
      while((CONF_WINC_SPI->SPSR & R_SPI0_SPSR_SPTEF_Msk) == 0)
      {
      }

      //Start to transfer data
      CONF_WINC_SPI->SPDR = data;

      //Wait for the operation to complete
      while((CONF_WINC_SPI->SPSR & R_SPI0_SPSR_SPRF_Msk) == 0)
      {
      }

      //Get the received character
      data = CONF_WINC_SPI->SPDR;

      //Disable SPI receive buffer full interrupt
      CONF_WINC_SPI->SPCR &= ~R_SPI0_SPCR_SPRIE_Msk;

      //Save the received character
      if(pu8Miso != NULL)
      {
         pu8Miso[i] = data;
      }
   }

   //Terminate the operation by raising the CS pin
   CONF_WINC_CS_PORT->PCNTR3 = CONF_WINC_CS_MASK << R_PORT0_PCNTR3_POSR_Pos;

   //Successful operation
   return M2M_SUCCESS;
}


/**
 * @brief SPI bus initialization
 * @param[in] pvinit Unused parameter
 * @return Status code (M2M_SUCCESS or M2M_ERR_BUS_FAIL)
 **/

sint8 nm_bus_init(uint8 *req_com_port, uint32 req_serial_number)
{
   //Disable protection
   R_SYSTEM->PRCR = 0xA50B;
   //Cancel SPI module stop state
   R_MSTP->CONF_WINC_SPI_MSTPCR &= ~CONF_WINC_SPI_MSTP_MASK;
   //Enable protection
   R_SYSTEM->PRCR = 0xA500;

   //Reset SPI module
   CONF_WINC_SPI->SPCR = 0;

   //Unlock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_B0WI_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_PFSWE_Msk;

   //Configure SCK pin
   R_PFS->CONF_WINC_SCK_PFS = R_PFS_PORT_PIN_PmnPFS_PMR_Msk |
      (CONF_WINC_SCK_PSEL << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos);

   //Configure MOSI pin
   R_PFS->CONF_WINC_MOSI_PFS = R_PFS_PORT_PIN_PmnPFS_PMR_Msk |
      (CONF_WINC_MOSI_PSEL << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos);

   //Configure MISO pin
   R_PFS->CONF_WINC_MISO_PFS = R_PFS_PORT_PIN_PmnPFS_PMR_Msk |
      (CONF_WINC_MISO_PSEL << R_PFS_PORT_PIN_PmnPFS_PSEL_Pos);

   //Lock PFS registers
   R_PMISC->PWPR &= ~R_PMISC_PWPR_PFSWE_Msk;
   R_PMISC->PWPR |= R_PMISC_PWPR_B0WI_Msk;

   //Set bit rate
   CONF_WINC_SPI->SPBR = CONF_WINC_SPI_SPBR;

   //Configure SPI mode (8 bits, MSB first)
   CONF_WINC_SPI->SPCMD[0] = (7 << R_SPI0_SPCMD_SPB_Pos);

   //SPDR is accessed in long words
   CONF_WINC_SPI->SPDCR = R_SPI0_SPDCR_SPLW_Msk;

   //Clear SPRF interrupt flag
   CONF_WINC_SPI->SPSR |= R_SPI0_SPSR_SPRF_Msk;

   //Enable SPI module (master mode)
   CONF_WINC_SPI->SPCR = R_SPI0_SPCR_SPE_Msk | R_SPI0_SPCR_MSTR_Msk;

   //Reset WINC3400
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
