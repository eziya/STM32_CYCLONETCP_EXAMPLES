/**
 * @file pic32cz_ca80_curiosity_ultra.h
 * @brief PIC32CZ CA80 Curiosity Ultra evaluation kit
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2025 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
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

#ifndef _PIC32CZ_CA80_CURIOSITY_ULTRA_H
#define _PIC32CZ_CA80_CURIOSITY_ULTRA_H

//Dependencies
#include "pic32c.h"

//LED0 (PB21)
#define LED0_GROUP 1
#define LED0_PIN   21
#define LED0_MASK  (1U << 21)

//LED1 (PB22)
#define LED1_GROUP 1
#define LED1_PIN   22
#define LED1_MASK  (1U << 22)

//SW0 button (PB24)
#define SW0_GROUP  1
#define SW0_PIN    24
#define SW0_MASK   (1U << 24)

//SW2 button (PC23)
#define SW1_GROUP  2
#define SW1_PIN    23
#define SW1_MASK   (1U << 23)

#endif
