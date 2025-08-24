/**
 * @file eval_adin2111ebz.h
 * @brief EVAL-ADIN2111EBZ evaluation board
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

#ifndef _EVAL_ADIN2111EBZ_H
#define _EVAL_ADIN2111EBZ_H

//Dependencies
#include "stm32l4xx.h"

//NET LED (red)
#define NET_LED_R_PIN  GPIO_PIN_2
#define NET_LED_R_GPIO GPIOE

//NET LED (green)
#define NET_LED_G_PIN  GPIO_PIN_6
#define NET_LED_G_GPIO GPIOE

//MOD LED (red)
#define MOD_LED_R_PIN  GPIO_PIN_10
#define MOD_LED_R_GPIO GPIOB

//MOD LED (green)
#define MOD_LED_G_PIN  GPIO_PIN_11
#define MOD_LED_G_GPIO GPIOB

//DEBUG LED (blue)
#define DEBUG_LED_PIN  GPIO_PIN_6
#define DEBUG_LED_GPIO GPIOB

//BOOT button
#define BOOT_SW_PIN    GPIO_PIN_3
#define BOOT_SW_GPIO   GPIOH

#endif
