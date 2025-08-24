/**
 * @file pic32cz_ca70_curiosity_ultra.h
 * @brief PIC32CZ CA70 Curiosity Ultra evaluation kit
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

#ifndef _PIC32CZ_CA70_CURIOSITY_ULTRA_H
#define _PIC32CZ_CA70_CURIOSITY_ULTRA_H

//Dependencies
#include "pic32c.h"

//LED0 (PD23)
#define LED0        PIO_PD23
#define PIO_LED0    PIOD_REGS
#define ID_PIO_LED0 ID_PIOD

//LED1 (PD29)
#define LED1        PIO_PD29
#define PIO_LED1    PIOD_REGS
#define ID_PIO_LED1 ID_PIOD

//SW0 button (PA1)
#define SW0         PIO_PA1
#define PIO_SW0     PIOA_REGS
#define ID_PIO_SW0  ID_PIOA

//SW2 button (PA9)
#define SW1         PIO_PA9
#define PIO_SW1     PIOA_REGS
#define ID_PIO_SW1  ID_PIOA

#endif
