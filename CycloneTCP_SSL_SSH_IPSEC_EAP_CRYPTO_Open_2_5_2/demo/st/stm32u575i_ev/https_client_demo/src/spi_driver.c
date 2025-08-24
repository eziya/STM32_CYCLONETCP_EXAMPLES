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
#include "stm32u5xx.h"
#include "stm32u5xx_hal.h"
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
   GPIO_InitTypeDef GPIO_InitStructure;

   //Enable PWR clock
   __HAL_RCC_PWR_CLK_ENABLE();
   //Enable VDDIO2 power supply for pins PG[15:2]
   HAL_PWREx_EnableVddIO2();

   //Enable GPIO clocks
   __HAL_RCC_GPIOA_CLK_ENABLE();
   __HAL_RCC_GPIOC_CLK_ENABLE();
   __HAL_RCC_GPIOG_CLK_ENABLE();

   //Enable SPI3 clock
   __HAL_RCC_SPI3_CLK_ENABLE();

   //Configure SPI3_NSS (PA4)
   GPIO_InitStructure.Pin = GPIO_PIN_4;
   GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
   GPIO_InitStructure.Pull = GPIO_NOPULL;
   GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
   HAL_GPIO_Init(GPIOA, &GPIO_InitStructure);

   //Deassert SPI3_NSS pin
   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);

   //Configure SPI3_MOSI (PC12)
   GPIO_InitStructure.Pin = GPIO_PIN_12;
   GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
   GPIO_InitStructure.Pull = GPIO_NOPULL;
   GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
   GPIO_InitStructure.Alternate = GPIO_AF6_SPI3;
   HAL_GPIO_Init(GPIOC, &GPIO_InitStructure);

   //Configure SPI3_SCK (PG9) and SPI3_MISO (PG10)
   GPIO_InitStructure.Pin = GPIO_PIN_9 | GPIO_PIN_10;
   GPIO_InitStructure.Mode = GPIO_MODE_AF_PP;
   GPIO_InitStructure.Pull = GPIO_NOPULL;
   GPIO_InitStructure.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
   GPIO_InitStructure.Alternate = GPIO_AF6_SPI3;
   HAL_GPIO_Init(GPIOG, &GPIO_InitStructure);

   //Configure SPI3 module
   SPI_Handle.Instance = SPI3;
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

   //Enable SPI3 module
   __HAL_SPI_ENABLE(&SPI_Handle);

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
   //Assert SPI3_NSS pin
   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
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
   //Deassert SPI3_NSS pin
   HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
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

   //Perform SPI transfer
   HAL_SPI_TransmitReceive(&SPI_Handle, &data, &temp, 1, HAL_MAX_DELAY);

   //Return the received data
   return temp;
}
