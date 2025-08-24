/**
 * @file m13_ra6m4_ek.h
 * @brief M13Design M13-RA6M4-EK evaluation kit
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

#ifndef _M13_RA6M4_EK_H
#define _M13_RA6M4_EK_H

//Dependencies
#include "bsp_api.h"

//LED1
#define LED1_MASK (1 << 7)
#define LED1_PORT R_PORT0
#define LED1_PFS PORT[0].PIN[7].PmnPFS

//LED2
#define LED2_MASK (1 << 12)
#define LED2_PORT R_PORT7
#define LED2_PFS PORT[7].PIN[12].PmnPFS

//LED3
#define LED3_MASK (1 << 9)
#define LED3_PORT R_PORT4
#define LED3_PFS PORT[4].PIN[9].PmnPFS

//LED4
#define LED4_MASK (1 << 11)
#define LED4_PORT R_PORT7
#define LED4_PFS PORT[7].PIN[11].PmnPFS

//SW1 push button
#define SW1_MASK (1 << 7)
#define SW1_PORT R_PORT2
#define SW1_PFS PORT[2].PIN[7].PmnPFS

//SW2 push button
#define SW2_MASK (1 << 8)
#define SW2_PORT R_PORT7
#define SW2_PFS PORT[7].PIN[8].PmnPFS

//MDIO pin
#define MDIO_MASK (1 << 14)
#define MDIO_PORT R_PORT0
#define MDIO_PFS PORT[0].PIN[14].PmnPFS

//MDC pin
#define MDC_MASK (1 << 13)
#define MDC_PORT R_PORT7
#define MDC_PFS PORT[7].PIN[13].PmnPFS

#endif
