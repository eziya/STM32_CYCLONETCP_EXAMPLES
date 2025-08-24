/**
 * @file spi_driver.c
 * @brief SPI driver
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
#include "stm32h5xx.h"
#include "core/net.h"
#include "spi_driver.h"
#include "debug.h"

//SPI instance
static SPI_HandleTypeDef SPI_Handle;


/**
 * @brief SPI driver
 **/

const SpiDriver spiDriver =
{
   spiInit,
   spiSetMode,
   spiSetBitrate,
   spiAssertCs,
   spiDeassertCs,
   spiTransfer
};


/**
 * @brief SPI initialization
 * @return Error code
 **/

error_t spiInit(void)
{
   GPIO_InitTypeDef GPIO_InitStructure = {0};
   RCC_PeriphCLKInitTypeDef RCC_PeriphClkInitStruct = {0};

   //Enable GPIO clocks
   __HAL_RCC_GPIOA_CLK_ENABLE();
   __HAL_RCC_GPIOC_CLK_ENABLE();

   //Enable SPI1 clock
   __HAL_RCC_SPI1_CLK_ENABLE();

   //Configure SPI1_NSS (PC9)
   GPIO_InitStructure.Pin = GPIO_PIN_9;
   GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStructure.Pull = GPIO_NOPULL;
   GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
   HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

   //Deassert SPI1_NSS pin
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);

   //Configure SPI1_SCK (PA5), SPI1_MISO (PA6) and SPI1_MOSI (PA7)
   GPIO_InitStructure.Pin = GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
   GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
   GPIO_InitStructure.Pull = GPIO_NOPULL;
   GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
   GPIO_InitStructure.Alternate = GPIO_AF5_SPI1;
   HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

   //Select clock source for SPI1 peripheral
   RCC_PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_SPI1;
   RCC_PeriphClkInitStruct.RngClockSelection = RCC_SPI1CLKSOURCE_PLL1Q;
   HAL_RCCEx_PeriphCLKConfig(&RCC_PeriphClkInitStruct);

#if 0
   //Configure SPI1 module
   SPI_Handle.Instance = SPI1;
   SPI_Handle.Init.Mode = SPI_MODE_MASTER;
   SPI_Handle.Init.Direction = SPI_DIRECTION_2LINES;
   SPI_Handle.Init.DataSize = SPI_DATASIZE_8BIT;
   SPI_Handle.Init.CLKPolarity = SPI_POLARITY_LOW;
   SPI_Handle.Init.CLKPhase = SPI_PHASE_1EDGE;
   SPI_Handle.Init.NSS = SPI_NSS_SOFT;
   SPI_Handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
   SPI_Handle.Init.FirstBit = SPI_FIRSTBIT_MSB;
   SPI_Handle.Init.TIMode = SPI_TIMODE_DISABLED;
   SPI_Handle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
   SPI_Handle.Init.CRCPolynomial = 7;
   HAL_SPI_Init(&SPI_Handle);

   //Enable SPI1 module
   __HAL_SPI_ENABLE(&SPI_Handle);
#else
   //Disable SPI1
   SPI1->CR1 &= ~SPI_CR1_SPE;

   //Configure SPI1 module
   SPI1->CFG1 = ((3 << 28) & SPI_CFG1_MBR) | ((7 << 16) & SPI_CFG1_CRCSIZE) | (7 & SPI_CFG1_DSIZE);
   SPI1->CFG2 = SPI_CFG2_MASTER | SPI_CFG2_SSOE;
   SPI1->I2SCFGR = 0;
   SPI1->CR2 = 0;

   //Enable SPI1 module
   SPI1->CR1 = SPI_CR1_SPE;
   SPI1->CR1 |= SPI_CR1_CSTART;
#endif

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Set SPI mode
 * @param mode SPI mode (0, 1, 2 or 3)
 **/

error_t spiSetMode(uint_t mode)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Set SPI bitrate
 * @param bitrate Bitrate value
 **/

error_t spiSetBitrate(uint_t bitrate)
{
   //Not implemented
   return ERROR_NOT_IMPLEMENTED;
}


/**
 * @brief Assert CS
 **/

void spiAssertCs(void)
{
   //Assert SPI1_NSS pin
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_RESET);
   //CS setup time
   usleep(1);
}


/**
 * @brief Deassert CS
 **/

void spiDeassertCs(void)
{
   //CS hold time
   usleep(1);
   //Deassert SPI1_NSS pin
   HAL_GPIO_WritePin(GPIOC, GPIO_PIN_9, GPIO_PIN_SET);
   //CS disable time
   usleep(1);
}


/**
 * @brief Transfer a single byte
 * @param[in] data The data to be written
 * @return The data received from the slave device
 **/

uint8_t spiTransfer(uint8_t data)
{
   uint8_t temp;

#if 0
   //Perform SPI transfer
   HAL_SPI_TransmitReceive(&SPI_Handle, &data, &temp, 1, HAL_MAX_DELAY);
#else
   //Write character
   *((uint8_t *) &SPI1->TXDR) = data;

   //Wait for the operation to complete
   while((SPI1->SR & SPI_SR_TXC) == 0)
   {
   }

   //Receive data
   temp = *((uint8_t *) &SPI1->RXDR);
#endif

   //Return the received character
   return temp;
}
