/**
 * @file tls_config.h
 * @brief CycloneSSL configuration file
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2025 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneSSL Open.
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

#ifndef _TLS_CONFIG_H
#define _TLS_CONFIG_H

//Dependencies
#include "RTE_Components.h"

//*** <<< Use Configuration Wizard in Context Menu >>> ***

// <o>Trace level
// <i>Set the desired debugging level
// <i>Default: Info
// <0=>Off
// <1=>Fatal
// <2=>Error
// <3=>Warning
// <4=>Info
// <5=>Debug
// <6=>Verbose
#define TLS_TRACE_LEVEL 4

// <o>Minimum SSL/TLS version
// <i>Minimum version that can be negotiated
// <i>Default: TLS 1.0
// <0x0301=>TLS 1.0
// <0x0302=>TLS 1.1
// <0x0303=>TLS 1.2
// <0x0304=>TLS 1.3
#define TLS_MIN_VERSION 0x0301

// <o>Maximum SSL/TLS version
// <i>Maximum version that can be negotiated
// <i>Default: TLS 1.2
// <0x0301=>TLS 1.0
// <0x0302=>TLS 1.1
// <0x0303=>TLS 1.2
// <0x0304=>TLS 1.3
#define TLS_MAX_VERSION 0x0303

// <q>Session resumption
// <i>Enable session resumption mechanism
// <i>Default: Enabled
#define TLS_SESSION_RESUME_SUPPORT 1

// <o>Session cache entry lifetime
// <i>Lifetime of session cache entries (in seconds)
// <i>Default: 3600
// <10-86400>
// <#*1000>
#define TLS_SESSION_CACHE_LIFETIME 3600000

// <q>Session tickets
// <i>Enable session ticket mechanism
// <i>Default: Disabled
#define TLS_TICKET_SUPPORT 0

// <o>Session ticket lifetime
// <i>Lifetime of session tickets (in seconds)
// <i>Default: 3600
// <10-86400>
// <#*1000>
#define TLS_TICKET_LIFETIME 3600000

// <q>SNI extension
// <i>Enable SNI (Server Name Indication) extension
// <i>Default: Enabled
#define TLS_SNI_SUPPORT 1

// <q>Maximum Fragment Length extension
// <i>Enable Maximum Fragment Length extension
// <i>Default: Disabled
#define TLS_MAX_FRAG_LEN_SUPPORT 0

// <q>Record Size Limit extension
// <i>Enable Record Size Limit extension
// <i>Default: Enabled
#define TLS_RECORD_SIZE_LIMIT_SUPPORT 1

// <q>ALPN extension
// <i>Enable ALPN (Application-Layer Protocol Negotiation) extension
// <i>Default: Disabled
#define TLS_ALPN_SUPPORT 0

// <q>Encrypt-then-MAC extension
// <i>Enable Encrypt-then-MAC extension
// <i>Default: Enabled
#define TLS_ENCRYPT_THEN_MAC_SUPPORT 0

// <q>Extended Master Secret extension
// <i>Enable Extended Master Secret extension
// <i>Default: Enabled
#define TLS_EXT_MASTER_SECRET_SUPPORT 1

// <q>ClientHello Padding extension
// <i>Enable ClientHello Padding extension
// <i>Default: Enabled
#define TLS_CLIENT_HELLO_PADDING_SUPPORT 1

// <q>Signature Algorithms Certificate extension
// <i>Enable Signature Algorithms Certificate extension
// <i>Default: Disabled
#define TLS_SIGN_ALGOS_CERT_SUPPORT 0

// <q>Raw public keys
// <i>Enable RPK (Raw Public Key) support
// <i>Default: Disabled
#define TLS_RAW_PUBLIC_KEY_SUPPORT 0

// <q>Secure renegotiation
// <i>Enable secure renegotiation
// <i>Default: Enabled
#define TLS_SECURE_RENEGOTIATION_SUPPORT 1

// <q>Fallback SCSV
// <i>Enable sallback SCSV
// <i>Default: Disabled
#define TLS_FALLBACK_SCSV_SUPPORT 0

// <o>Maximum number of certificates
// <i>Maximum number of certificates the end entity can load
// <i>Default: 3
// <1-8>
#define TLS_MAX_CERTIFICATES 3

//TLS support
#ifdef RTE_CYCLONE_SSL
   #define TLS_SUPPORT ENABLED
#else
   #define TLS_SUPPORT DISABLED
#endif

//DTLS support
#ifdef RTE_CYCLONE_SSL_DTLS
   #define DTLS_SUPPORT ENABLED
#else
   #define DTLS_SUPPORT DISABLED
#endif

//Client mode of operation
#ifdef RTE_CYCLONE_SSL_CLIENT
   #define TLS_CLIENT_SUPPORT ENABLED
#else
   #define TLS_CLIENT_SUPPORT DISABLED
#endif

//Server mode of operation
#ifdef RTE_CYCLONE_SSL_SERVER
   #define TLS_SERVER_SUPPORT ENABLED
#else
   #define TLS_SERVER_SUPPORT DISABLED
#endif

//RSA key exchange support
#ifdef RTE_CYCLONE_SSL_RSA_KE
   #define TLS_RSA_KE_SUPPORT ENABLED
#else
   #define TLS_RSA_KE_SUPPORT DISABLED
#endif

//DHE_RSA key exchange support
#ifdef RTE_CYCLONE_SSL_DHE_RSA_KE
   #define TLS_DHE_RSA_KE_SUPPORT ENABLED
#else
   #define TLS_DHE_RSA_KE_SUPPORT DISABLED
#endif

//DHE_DSS key exchange support
#ifdef RTE_CYCLONE_SSL_DHE_DSS_KE
   #define TLS_DHE_DSS_KE_SUPPORT ENABLED
#else
   #define TLS_DHE_DSS_KE_SUPPORT DISABLED
#endif

//DH_anon key exchange support (insecure)
#ifdef RTE_CYCLONE_SSL_DH_ANON_KE
   #define TLS_DH_ANON_KE_SUPPORT ENABLED
#else
   #define TLS_DH_ANON_KE_SUPPORT DISABLED
#endif

//ECDHE_RSA key exchange support
#ifdef RTE_CYCLONE_SSL_ECDHE_RSA_KE
   #define TLS_ECDHE_RSA_KE_SUPPORT ENABLED
#else
   #define TLS_ECDHE_RSA_KE_SUPPORT DISABLED
#endif

//ECDHE_ECDSA key exchange support
#ifdef RTE_CYCLONE_SSL_ECDHE_ECDSA_KE
   #define TLS_ECDHE_ECDSA_KE_SUPPORT ENABLED
#else
   #define TLS_ECDHE_ECDSA_KE_SUPPORT DISABLED
#endif

//ECDH_anon key exchange support (insecure)
#ifdef RTE_CYCLONE_SSL_ECDH_ANON_KE
   #define TLS_ECDH_ANON_KE_SUPPORT ENABLED
#else
   #define TLS_ECDH_ANON_KE_SUPPORT DISABLED
#endif

//PSK key exchange support
#ifdef RTE_CYCLONE_SSL_PSK_KE
   #define TLS_PSK_KE_SUPPORT ENABLED
#else
   #define TLS_PSK_KE_SUPPORT DISABLED
#endif

//RSA_PSK key exchange support
#ifdef RTE_CYCLONE_SSL_RSA_PSK_KE
   #define TLS_RSA_PSK_KE_SUPPORT ENABLED
#else
   #define TLS_RSA_PSK_KE_SUPPORT DISABLED
#endif

//DHE_PSK key exchange support
#ifdef RTE_CYCLONE_SSL_DHE_PSK_KE
   #define TLS_DHE_PSK_KE_SUPPORT ENABLED
#else
   #define TLS_DHE_PSK_KE_SUPPORT DISABLED
#endif

//ECDHE_PSK key exchange support
#ifdef RTE_CYCLONE_SSL_ECDHE_PSK_KE
   #define TLS_ECDHE_PSK_KE_SUPPORT ENABLED
#else
   #define TLS_ECDHE_PSK_KE_SUPPORT DISABLED
#endif

//DHE key exchange support (TLS 1.3)
#ifdef RTE_CYCLONE_SSL_TLS13_DHE_KE
   #define TLS13_DHE_KE_SUPPORT ENABLED
#else
   #define TLS13_DHE_KE_SUPPORT DISABLED
#endif

//ECDHE key exchange support (TLS 1.3)
#ifdef RTE_CYCLONE_SSL_TLS13_ECDHE_KE
   #define TLS13_ECDHE_KE_SUPPORT ENABLED
#else
   #define TLS13_ECDHE_KE_SUPPORT DISABLED
#endif

//PSK-only key exchange support (TLS 1.3)
#ifdef RTE_CYCLONE_SSL_TLS13_PSK_KE
   #define TLS13_PSK_KE_SUPPORT ENABLED
#else
   #define TLS13_PSK_KE_SUPPORT DISABLED
#endif

//PSK with DHE key exchange support (TLS 1.3)
#ifdef RTE_CYCLONE_SSL_TLS13_PSK_DHE_KE
   #define TLS13_PSK_DHE_KE_SUPPORT ENABLED
#else
   #define TLS13_PSK_DHE_KE_SUPPORT DISABLED
#endif

//PSK with ECDHE key exchange support (TLS 1.3)
#ifdef RTE_CYCLONE_SSL_TLS13_PSK_ECDHE_KE
   #define TLS13_PSK_ECDHE_KE_SUPPORT ENABLED
#else
   #define TLS13_PSK_ECDHE_KE_SUPPORT DISABLED
#endif

//RSA signature capability
#ifdef RTE_CYCLONE_SSL_RSA_SIGN
   #define TLS_RSA_SIGN_SUPPORT ENABLED
#else
   #define TLS_RSA_SIGN_SUPPORT DISABLED
#endif

//RSA-PSS signature capability
#ifdef RTE_CYCLONE_SSL_RSA_PSS_SIGN
   #define TLS_RSA_PSS_SIGN_SUPPORT ENABLED
#else
   #define TLS_RSA_PSS_SIGN_SUPPORT DISABLED
#endif

//DSA signature capability
#ifdef RTE_CYCLONE_SSL_DSA_SIGN
   #define TLS_DSA_SIGN_SUPPORT ENABLED
#else
   #define TLS_DSA_SIGN_SUPPORT DISABLED
#endif

//ECDSA signature capability
#ifdef RTE_CYCLONE_SSL_ECDSA_SIGN
   #define TLS_ECDSA_SIGN_SUPPORT ENABLED
#else
   #define TLS_ECDSA_SIGN_SUPPORT DISABLED
#endif

//SM2 signature capability (not recommended by the IETF)
#ifdef RTE_CYCLONE_SSL_SM2_SIGN
   #define TLS_SM2_SIGN_SUPPORT ENABLED
#else
   #define TLS_SM2_SIGN_SUPPORT DISABLED
#endif

//Ed25519 signature capability
#ifdef RTE_CYCLONE_SSL_ED25519_SIGN
   #define TLS_ED25519_SIGN_SUPPORT ENABLED
#else
   #define TLS_ED25519_SIGN_SUPPORT DISABLED
#endif

//Ed448 signature capability
#ifdef RTE_CYCLONE_SSL_ED448_SIGN
   #define TLS_ED448_SIGN_SUPPORT ENABLED
#else
   #define TLS_ED448_SIGN_SUPPORT DISABLED
#endif

//Stream cipher support
#ifdef RTE_CYCLONE_SSL_STREAM
   #define TLS_STREAM_CIPHER_SUPPORT ENABLED
#else
   #define TLS_STREAM_CIPHER_SUPPORT DISABLED
#endif

//CBC block cipher support
#ifdef RTE_CYCLONE_SSL_CBC
   #define TLS_CBC_CIPHER_SUPPORT ENABLED
#else
   #define TLS_CBC_CIPHER_SUPPORT DISABLED
#endif

//CCM AEAD support
#ifdef RTE_CYCLONE_SSL_CCM
   #define TLS_CCM_CIPHER_SUPPORT ENABLED
#else
   #define TLS_CCM_CIPHER_SUPPORT DISABLED
#endif

//GCM AEAD support
#ifdef RTE_CYCLONE_SSL_GCM
   #define TLS_GCM_CIPHER_SUPPORT ENABLED
#else
   #define TLS_GCM_CIPHER_SUPPORT DISABLED
#endif

//ChaCha20Poly1305 AEAD support
#ifdef RTE_CYCLONE_SSL_CHACHA20POLY1305
   #define TLS_CHACHA20_POLY1305_SUPPORT ENABLED
#else
   #define TLS_CHACHA20_POLY1305_SUPPORT DISABLED
#endif

//RC4 cipher support (insecure)
#ifdef RTE_CYCLONE_SSL_RC4
   #define TLS_RC4_SUPPORT ENABLED
#else
   #define TLS_RC4_SUPPORT DISABLED
#endif

//IDEA cipher support (insecure)
#ifdef RTE_CYCLONE_SSL_IDEA
   #define TLS_IDEA_SUPPORT ENABLED
#else
   #define TLS_IDEA_SUPPORT DISABLED
#endif

//DES cipher support (insecure)
#ifdef RTE_CYCLONE_SSL_DES
   #define TLS_DES_SUPPORT ENABLED
#else
   #define TLS_DES_SUPPORT DISABLED
#endif

//Triple DES cipher support (weak)
#ifdef RTE_CYCLONE_SSL_3DES
   #define TLS_3DES_SUPPORT ENABLED
#else
   #define TLS_3DES_SUPPORT DISABLED
#endif

//AES 128-bit cipher support
#ifdef RTE_CYCLONE_SSL_AES
   #define TLS_AES_128_SUPPORT ENABLED
#else
   #define TLS_AES_128_SUPPORT DISABLED
#endif

//AES 256-bit cipher support
#ifdef RTE_CYCLONE_SSL_AES
   #define TLS_AES_256_SUPPORT ENABLED
#else
   #define TLS_AES_256_SUPPORT DISABLED
#endif

//Camellia 128-bit cipher support
#ifdef RTE_CYCLONE_SSL_CAMELLIA
   #define TLS_CAMELLIA_128_SUPPORT ENABLED
#else
   #define TLS_CAMELLIA_128_SUPPORT DISABLED
#endif

//Camellia 256-bit cipher support
#ifdef RTE_CYCLONE_SSL_CAMELLIA
   #define TLS_CAMELLIA_256_SUPPORT ENABLED
#else
   #define TLS_CAMELLIA_256_SUPPORT DISABLED
#endif

//ARIA 128-bit cipher support
#ifdef RTE_CYCLONE_SSL_ARIA
   #define TLS_ARIA_128_SUPPORT ENABLED
#else
   #define TLS_ARIA_128_SUPPORT DISABLED
#endif

//ARIA 256-bit cipher support
#ifdef RTE_CYCLONE_SSL_ARIA
   #define TLS_ARIA_256_SUPPORT ENABLED
#else
   #define TLS_ARIA_256_SUPPORT DISABLED
#endif

//SEED cipher support
#ifdef RTE_CYCLONE_SSL_SEED
   #define TLS_SEED_SUPPORT ENABLED
#else
   #define TLS_SEED_SUPPORT DISABLED
#endif

//SM4 cipher support (not recommended by the IETF)
#ifdef RTE_CYCLONE_SSL_SM4
   #define TLS_SM4_SUPPORT ENABLED
#else
   #define TLS_SM4_SUPPORT DISABLED
#endif

//MD5 hash support (insecure)
#ifdef RTE_CYCLONE_SSL_MD5
   #define TLS_MD5_SUPPORT ENABLED
#else
   #define TLS_MD5_SUPPORT DISABLED
#endif

//SHA-1 hash support (weak)
#ifdef RTE_CYCLONE_SSL_SHA1
   #define TLS_SHA1_SUPPORT ENABLED
#else
   #define TLS_SHA1_SUPPORT DISABLED
#endif

//SHA-224 hash support (weak)
#ifdef RTE_CYCLONE_SSL_SHA224
   #define TLS_SHA224_SUPPORT ENABLED
#else
   #define TLS_SHA224_SUPPORT DISABLED
#endif

//SHA-256 hash support
#ifdef RTE_CYCLONE_SSL_SHA256
   #define TLS_SHA256_SUPPORT ENABLED
#else
   #define TLS_SHA256_SUPPORT DISABLED
#endif

//SHA-384 hash support
#ifdef RTE_CYCLONE_SSL_SHA384
   #define TLS_SHA384_SUPPORT ENABLED
#else
   #define TLS_SHA384_SUPPORT DISABLED
#endif

//SHA-512 hash support
#ifdef RTE_CYCLONE_SSL_SHA512
   #define TLS_SHA512_SUPPORT ENABLED
#else
   #define TLS_SHA512_SUPPORT DISABLED
#endif

//SM3 hash support (not recommended by the IETF)
#ifdef RTE_CYCLONE_SSL_SM3
   #define TLS_SM3_SUPPORT ENABLED
#else
   #define TLS_SM3_SUPPORT DISABLED
#endif

//FFDHE key exchange mechanism
#if defined(RTE_CYCLONE_SSL_FFDHE2048) || defined(RTE_CYCLONE_SSL_FFDHE3072) || defined(RTE_CYCLONE_SSL_FFDHE4096)
   #define TLS_FFDHE_SUPPORT ENABLED
#else
   #define TLS_FFDHE_SUPPORT DISABLED
#endif

//ffdhe2048 group support
#ifdef RTE_CYCLONE_SSL_FFDHE2048
   #define TLS_FFDHE2048_SUPPORT ENABLED
#else
   #define TLS_FFDHE2048_SUPPORT DISABLED
#endif

//ffdhe3072 group support
#ifdef RTE_CYCLONE_SSL_FFDHE3072
   #define TLS_FFDHE3072_SUPPORT ENABLED
#else
   #define TLS_FFDHE3072_SUPPORT DISABLED
#endif

//ffdhe4096 group support
#ifdef RTE_CYCLONE_SSL_FFDHE4096
   #define TLS_FFDHE4096_SUPPORT ENABLED
#else
   #define TLS_FFDHE4096_SUPPORT DISABLED
#endif

//secp160k1 elliptic curve support (weak)
#ifdef RTE_CYCLONE_SSL_SECP160K1
   #define TLS_SECP160K1_SUPPORT ENABLED
#else
   #define TLS_SECP160K1_SUPPORT DISABLED
#endif

//secp160r1 elliptic curve support (weak)
#ifdef RTE_CYCLONE_SSL_SECP160R1
   #define TLS_SECP160R1_SUPPORT ENABLED
#else
   #define TLS_SECP160R1_SUPPORT DISABLED
#endif

//secp160r2 elliptic curve support (weak)
#ifdef RTE_CYCLONE_SSL_SECP160R2
   #define TLS_SECP160R2_SUPPORT ENABLED
#else
   #define TLS_SECP160R2_SUPPORT DISABLED
#endif

//secp192k1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_SECP192K1
   #define TLS_SECP192K1_SUPPORT ENABLED
#else
   #define TLS_SECP192K1_SUPPORT DISABLED
#endif

//secp192r1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_SECP192R1
   #define TLS_SECP192R1_SUPPORT ENABLED
#else
   #define TLS_SECP192R1_SUPPORT DISABLED
#endif

//secp224k1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_SECP224K1
   #define TLS_SECP224K1_SUPPORT ENABLED
#else
   #define TLS_SECP224K1_SUPPORT DISABLED
#endif

//secp224r1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_SECP224R1
   #define TLS_SECP224R1_SUPPORT ENABLED
#else
   #define TLS_SECP224R1_SUPPORT DISABLED
#endif

//secp256k1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_SECP256K1
   #define TLS_SECP256K1_SUPPORT ENABLED
#else
   #define TLS_SECP256K1_SUPPORT DISABLED
#endif

//secp256r1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_SECP256R1
   #define TLS_SECP256R1_SUPPORT ENABLED
#else
   #define TLS_SECP256R1_SUPPORT DISABLED
#endif

//secp384r1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_SECP384R1
   #define TLS_SECP384R1_SUPPORT ENABLED
#else
   #define TLS_SECP384R1_SUPPORT DISABLED
#endif

//secp521r1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_SECP521R1
   #define TLS_SECP521R1_SUPPORT ENABLED
#else
   #define TLS_SECP521R1_SUPPORT DISABLED
#endif

//brainpoolP256r1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_BRAINPOOLP256R1
   #define TLS_BRAINPOOLP256R1_SUPPORT ENABLED
#else
   #define TLS_BRAINPOOLP256R1_SUPPORT DISABLED
#endif

//brainpoolP384r1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_BRAINPOOLP384R1
   #define TLS_BRAINPOOLP384R1_SUPPORT ENABLED
#else
   #define TLS_BRAINPOOLP384R1_SUPPORT DISABLED
#endif

//brainpoolP512r1 elliptic curve support
#ifdef RTE_CYCLONE_SSL_BRAINPOOLP512R1
   #define TLS_BRAINPOOLP512R1_SUPPORT ENABLED
#else
   #define TLS_BRAINPOOLP512R1_SUPPORT DISABLED
#endif

//SM2 elliptic curve support (not recommended by the IETF)
#ifdef RTE_CYCLONE_SSL_SM2
   #define TLS_SM2_SUPPORT ENABLED
#else
   #define TLS_SM2_SUPPORT DISABLED
#endif

//Curve25519 elliptic curve support
#ifdef RTE_CYCLONE_SSL_X25519
   #define TLS_X25519_SUPPORT ENABLED
#else
   #define TLS_X25519_SUPPORT DISABLED
#endif

//Curve448 elliptic curve support
#ifdef RTE_CYCLONE_SSL_X448
   #define TLS_X448_SUPPORT ENABLED
#else
   #define TLS_X448_SUPPORT DISABLED
#endif

#endif
