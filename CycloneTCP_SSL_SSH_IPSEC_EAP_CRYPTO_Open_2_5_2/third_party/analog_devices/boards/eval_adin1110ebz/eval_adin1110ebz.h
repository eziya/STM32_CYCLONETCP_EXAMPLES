/**
 * @file eval_adin1110ebz.h
 * @brief EVAL-ADIN1110EBZ evaluation board
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

#ifndef _EVAL_ADIN1110EBZ_H
#define _EVAL_ADIN1110EBZ_H

//Dependencies
#include "stm32l4xx.h"

//Green LED
#define LED_G_PIN    GPIO_PIN_13
#define LED_G_GPIO   GPIOC

//Red LED
#define LED_R_PIN    GPIO_PIN_2
#define LED_R_GPIO   GPIOE

//Yellow LED
#define LED_Y_PIN    GPIO_PIN_6
#define LED_Y_GPIO   GPIOE

//Blue LED
#define LED_B_PIN    GPIO_PIN_15
#define LED_B_GPIO   GPIOG

//BOOT button
#define BOOT_SW_PIN  GPIO_PIN_3
#define BOOT_SW_GPIO GPIOH

#endif
