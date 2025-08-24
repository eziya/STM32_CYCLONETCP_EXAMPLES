/**
 * @file pic32cx_sg41_curiosity_ultra.h
 * @brief PIC32CX SG41 Curiosity Ultra evaluation kit
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

#ifndef _PIC32CX_SG41_CURIOSITY_ULTRA_H
#define _PIC32CX_SG41_CURIOSITY_ULTRA_H

//Dependencies
#include "pic32c.h"

//LED1 (PC21)
#define LED1_GROUP 2
#define LED1_PIN   21
#define LED1_MASK  (1U << 21)

//LED2 (PA16)
#define LED2_GROUP 0
#define LED2_PIN   16
#define LED2_MASK  (1U << 16)

//SW1 button (PD0)
#define SW1_GROUP  3
#define SW1_PIN    0
#define SW1_MASK   (1U << 0)

//SW2 button (PD1)
#define SW2_GROUP  3
#define SW2_PIN    1
#define SW2_MASK   (1U << 1)

#endif
