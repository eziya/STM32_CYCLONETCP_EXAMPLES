/**
 * @file eap_config.h
 * @brief CycloneEAP configuration file
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2025 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneEAP Open.
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

#ifndef _EAP_CONFIG_H
#define _EAP_CONFIG_H

//Desired trace level (for debugging purposes)
#define EAP_TRACE_LEVEL           TRACE_LEVEL_INFO
#define RADIUS_TRACE_LEVEL        TRACE_LEVEL_OFF
#define SUPPLICANT_TRACE_LEVEL    TRACE_LEVEL_INFO
#define AUTHENTICATOR_TRACE_LEVEL TRACE_LEVEL_OFF

//802.1X supplicant support
#define SUPPLICANT_SUPPORT ENABLED
//802.1X authenticator support
#define AUTHENTICATOR_SUPPORT DISABLED

//MD5-Challenge authentication method support
#define EAP_MD5_SUPPORT ENABLED
//EAP-TLS authentication method support
#define EAP_TLS_SUPPORT ENABLED

//Maximum fragment size
#define EAP_MAX_FRAG_SIZE 1000

#endif
