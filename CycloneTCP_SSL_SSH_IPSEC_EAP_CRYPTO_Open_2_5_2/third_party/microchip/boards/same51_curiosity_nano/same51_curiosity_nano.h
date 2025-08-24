/**
 * @file same51_curiosity_nano.h
 * @brief SAME51-Curiosity-Nano evaluation kit
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

#ifndef _SAME51_CURIOSITY_NANO_H
#define _SAME51_CURIOSITY_NANO_H

//Dependencies
#include "sam.h"

//LED0 (PA14)
#define LED0_GROUP 0
#define LED0_PIN   14
#define LED0_MASK  (1U << 14)

//SW0 button (PA15)
#define SW0_GROUP  0
#define SW0_PIN    15
#define SW0_MASK   (1U << 15)

#endif
