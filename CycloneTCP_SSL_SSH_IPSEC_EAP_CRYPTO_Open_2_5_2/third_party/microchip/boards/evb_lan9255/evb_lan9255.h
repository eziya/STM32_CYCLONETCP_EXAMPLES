/**
 * @file evb_lan9255.h
 * @brief EVB-LAN9255 evaluation kit
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

#ifndef _EVB_LAN9255_H
#define _EVB_LAN9255_H

//Dependencies
#include "sam.h"

//LED1 (PB4)
#define LED1_GROUP 1
#define LED1_PIN   4
#define LED1_MASK  (1U << 4)

//LED2 (PB5)
#define LED2_GROUP 1
#define LED2_PIN   5
#define LED2_MASK  (1U << 5)

//LED3 (PB6)
#define LED3_GROUP 1
#define LED3_PIN   6
#define LED3_MASK  (1U << 6)

//LED4 (PB7)
#define LED4_GROUP 1
#define LED4_PIN   7
#define LED4_MASK  (1U << 7)

#endif
