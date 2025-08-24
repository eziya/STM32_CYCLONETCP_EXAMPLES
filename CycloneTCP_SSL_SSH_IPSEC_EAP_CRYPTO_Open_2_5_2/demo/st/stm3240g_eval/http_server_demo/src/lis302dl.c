/**
 * @file lis302dl.c
 * @brief LIS302DL accelerometer
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
#include "stm32f4xx.h"
#include "stm324xg_eval.h"
#include "stm324xg_eval_io.h"
#include "lis302dl.h"
#include "debug.h"

//Global variables
extern I2C_HandleTypeDef  heval_I2c;


/**
 * @brief LIS302DL initialization
 * @return Error code
 **/

error_t lis302dlInit(void)
{
   error_t error;
   uint8_t value;

   //Debug message
   TRACE_INFO("Initializing LIS302DL accelerometer...\r\n");

   //Read device identification register
   error = lis302dlReadReg(LIS302DL_REG_WHO_AM_I, &value);
   //Any error to report?
   if(error)
      return error;

   //Check device identifier
   if(value != LIS302DL_DEVICE_ID)
      return ERROR_WRONG_IDENTIFIER;

   //Power up LIS302DL
   error = lis302dlWriteReg(LIS302DL_REG_CTRL1, LIS302DL_CTRL1_PD |
      LIS302DL_CTRL1_ZEN | LIS302DL_CTRL1_YEN | LIS302DL_CTRL1_XEN);
   //Any error to report?
   if(error)
      return error;

   //Successful initialization
   return NO_ERROR;
}


/**
 * @brief Get acceleration data
 * @param[out] ax Acceleration value (X axis)
 * @param[out] ay Acceleration value (Y axis)
 * @param[out] az Acceleration value (Z axis)
 * @param[in] data Register value
 * @return Error code
 **/

error_t lis302dlGetAcc(int8_t *ax, int8_t *ay, int8_t *az)
{
   error_t error;

   //Retrieve acceleration along the X axis
   error = lis302dlReadReg(LIS302DL_REG_OUT_X, (uint8_t *) ax);

   //Retrieve acceleration along the Y axis
   if(!error)
      error = lis302dlReadReg(LIS302DL_REG_OUT_Y, (uint8_t *) ay);

   //Retrieve acceleration along the Z axis
   if(!error)
      error = lis302dlReadReg(LIS302DL_REG_OUT_Z, (uint8_t *) az);

   //Return status code
   return error;
}


/**
 * @brief Write LIS302DL register
 * @param[in] address Register address
 * @param[in] data Register value
 * @return Error code
 **/

error_t lis302dlWriteReg(uint8_t address, uint8_t data)
{
   HAL_StatusTypeDef status;

   //Write the specified register
   status = HAL_I2C_Mem_Write(&heval_I2c, LIS302DL_ADDR, address,
      I2C_MEMADD_SIZE_8BIT, &data, 1, 1000);

   //Return status code
   if(status == HAL_OK)
      return NO_ERROR;
   else
      return ERROR_FAILURE;
}


/**
 * @brief Read LIS302DL register
 * @param[in] address Register address
 * @param[out] data Register value
 * @return Error code
 **/

error_t lis302dlReadReg(uint8_t address, uint8_t *data)
{
   HAL_StatusTypeDef status;

   //Read register contents
   status = HAL_I2C_Mem_Read(&heval_I2c, LIS302DL_ADDR, address,
      I2C_MEMADD_SIZE_8BIT, data, 1, 1000);

   //Return status code
   if(status == HAL_OK)
      return NO_ERROR;
   else
      return ERROR_FAILURE;
}
