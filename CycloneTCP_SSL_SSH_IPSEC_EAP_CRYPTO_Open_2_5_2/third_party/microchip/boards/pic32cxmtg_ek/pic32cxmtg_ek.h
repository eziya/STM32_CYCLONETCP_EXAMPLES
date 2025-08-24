/**
 * @file pic32cxmtg_ek.h
 * @brief PIC32CXMTG-EK evaluation kit
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

#ifndef _PIC32CXMTG_EK_H
#define _PIC32CXMTG_EK_H

//Dependencies
#include "pic32c.h"

//Green LED
#define LED_G             PIO_PD16
#define PIO_GROUP_LED_G   PIO1_REGS->PIO_GROUP[0]
#define ID_PIO_LED_G      ID_PIOD

//Blue LED
#define LED_B             PIO_PD3
#define PIO_GROUP_LED_B   PIO1_REGS->PIO_GROUP[0]
#define ID_PIO_LED_B      ID_PIOD

//User button
#define SW_USER           PIO_PA7
#define PIO_GROUP_SW_USER PIO0_REGS->PIO_GROUP[0]
#define ID_PIO_SW_USER    ID_PIOA

#endif
