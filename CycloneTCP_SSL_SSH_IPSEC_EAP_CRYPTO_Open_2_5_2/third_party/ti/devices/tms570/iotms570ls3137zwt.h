/***************************************************************************
 **
 **    This file defines the Special Function Registers for
 **    Texas Instruments TMS570LS3137ZWT
 **
 **    Used with ARM IAR C/C++ Compiler and Assembler.
 **    (c) Copyright IAR Systems and Texas Instruments 2011
 **
 **    $Revision: 11344 $
 **
***************************************************************************/

#ifndef __IOTMS570LS3137ZWT_H
#define __IOTMS570LS3137ZWT_H

#if ( __ICCARM__ != 1 && __IASMARM__ != 1)
#error This file should only be compiled by ARM IAR compiler and assembler
#endif

#include "io_macros.h"

/***************************************************************************
 ***************************************************************************
 **
 **    TMS570LS3137ZWT SPECIAL FUNCTION REGISTERS
 **
 ***************************************************************************
***************************************************************************/

/* C-compiler specific declarations **********************************************/

#ifdef __IAR_SYSTEMS_ICC__

#ifndef _SYSTEM_BUILD
  #pragma system_include
#endif

#if __LITTLE_ENDIAN__ == 1
#error This file should only be compiled in big endian mode
#endif

/* Reverse the bitfield order in the structs */
#pragma bitfields=disjoint_types

/* SYS Pin Control Register 1 (SYSPC1) */
typedef struct {
  __REG32 ECPCLKFUN       : 1;
  __REG32                 :31;
} __syspc1_bits;

/* SYS Pin Control Register 2 (SYSPC2) */
typedef struct {
  __REG32 ECPCLKDIR       : 1;
  __REG32                 :31;
} __syspc2_bits;

/* SYS Pin Control Register 3 (SYSPC3) */
typedef struct {
  __REG32 ECPCLKDIN       : 1;
  __REG32                 :31;
} __syspc3_bits;

/* SYS Pin Control Register 4 (SYSPC4) */
typedef struct {
  __REG32 ECPCLKDOUT      : 1;
  __REG32                 :31;
} __syspc4_bits;

/* SYS Pin Control Register 5 (SYSPC5) */
typedef struct {
  __REG32 ECPCLKSET       : 1;
  __REG32                 :31;
} __syspc5_bits;

/* SYS Pin Control Register 6 (SYSPC6) */
typedef struct {
  __REG32 ECPCLKCLR       : 1;
  __REG32                 :31;
} __syspc6_bits;

/* SYS Pin Control Register 7 (SYSPC7) */
typedef struct {
  __REG32 ECPCLKODE       : 1;
  __REG32                 :31;
} __syspc7_bits;

/* SYS Pin Control Register 8 (SYSPC8) */
typedef struct {
  __REG32 ECPCLKPUE       : 1;
  __REG32                 :31;
} __syspc8_bits;

/* SYS Pin Control Register 9 (SYSPC9) */
typedef struct {
  __REG32 ECPCLKPS        : 1;
  __REG32                 :31;
} __syspc9_bits;

/* SSW PLL BIST Control Register 1 (SSWPLL1) */
typedef struct {
  __REG32 EXT_COUNTER_EN      : 1;
  __REG32 TAP_COUNTER_DIS     : 3;
  __REG32 COUNTER_EN          : 1;
  __REG32 COUNTER_RESET       : 1;
  __REG32 COUNTER_READ_READY  : 1;
  __REG32                     : 1;
  __REG32 CAPTURE_WINDOW_INDEX: 8;
  __REG32                     :16;
} __sswpll1_bits;

/* Clock Source Disable Register (CSDIS) */
typedef struct {
  __REG32 CLKSR0OFF       : 1;
  __REG32 CLKSR1OFF       : 1;
  __REG32                 : 1;
  __REG32 CLKSR3OFF       : 1;
  __REG32 CLKSR4OFF       : 1;
  __REG32 CLKSR5OFF       : 1;
  __REG32 CLKSR6OFF       : 1;
  __REG32 CLKSR7OFF       : 1;
  __REG32                 :24;
} __csdis_bits;

/* Clock Source Disable Set Register (CSDISSET) */
typedef struct {
  __REG32 SETCLKSR0OFF    : 1;
  __REG32 SETCLKSR1OFF    : 1;
  __REG32                 : 1;
  __REG32 SETCLKSR3OFF    : 1;
  __REG32 SETCLKSR4OFF    : 1;
  __REG32 SETCLKSR5OFF    : 1;
  __REG32 SETCLKSR6OFF    : 1;
  __REG32 SETCLKSR7OFF    : 1;
  __REG32                 :24;
} __csdisset_bits;

/* Clock Source Disable Clear Register (CSDISCLR) */
typedef struct {
  __REG32 CLRCLKSR0OFF    : 1;
  __REG32 CLRCLKSR1OFF    : 1;
  __REG32                 : 1;
  __REG32 CLRCLKSR3OFF    : 1;
  __REG32 CLRCLKSR4OFF    : 1;
  __REG32 CLRCLKSR5OFF    : 1;
  __REG32 CLRCLKSR6OFF    : 1;
  __REG32 CLRCLKSR7OFF    : 1;
  __REG32                 :24;
} __csdisclr_bits;

/* Clock Domain Disable Register (CDDIS) */
typedef struct {
  __REG32 GCLKOFF         : 1;
  __REG32 HCLKOFF         : 1;
  __REG32 VCLKPOFF        : 1;
  __REG32 VCLK2OFF        : 1;
  __REG32 VCLKA1OFF       : 1;
  __REG32 VCLKA2OFF       : 1;
  __REG32 RTICLK1OFF      : 1;
  __REG32                 : 1;
  __REG32 VCLK3OFF        : 1;
  __REG32                 : 1;
  __REG32 VCLKA3OFF       : 1;
  __REG32 VCLKA4OFF       : 1;
  __REG32                 :20;
} __cddis_bits;

/* Clock Domain Disable Set Register (CDDISSET) */
typedef struct {
  __REG32 SETGCLKOFF      : 1;
  __REG32 SETHCLKOFF      : 1;
  __REG32 SETVCLKPOFF     : 1;
  __REG32 SETVCLK2OFF     : 1;
  __REG32 SETVCLKA1OFF    : 1;
  __REG32 SETVCLKA2OFF    : 1;
  __REG32 SETRTICLK1OFF   : 1;
  __REG32                 : 1;
  __REG32 SETVCLK3OFF     : 1;
  __REG32                 : 1;
  __REG32 SETVCLKA3OFF    : 1;
  __REG32 SETVCLKA4OFF    : 1;
  __REG32                 :20;
} __cddisset_bits;

/* Clock Domain Disable Clear Register (CDDISCLR) */
typedef struct {
  __REG32 CLRGCLKOFF      : 1;
  __REG32 CLRHCLKOFF      : 1;
  __REG32 CLRVCLKPOFF     : 1;
  __REG32 CLRVCLK2OFF     : 1;
  __REG32 CLRVCLKA1OFF    : 1;
  __REG32 CLRVCLKA2OFF    : 1;
  __REG32 CLRRTICLK1OFF   : 1;
  __REG32                 : 1;
  __REG32 CLRVCLK3OFF     : 1;
  __REG32                 : 1;
  __REG32 CLRVCLKA3OFF    : 1;
  __REG32 CLRVCLKA4OFF    : 1;
  __REG32                 :20;
} __cddisclr_bits;

/* GCLK, HCLK, VCLK, and VCLK2 Source Register (GHVSRC) */
typedef struct {
  __REG32 GHVSRC          : 4;
  __REG32                 :12;
  __REG32 HVLPM           : 4;
  __REG32                 : 4;
  __REG32 GHVWAKE         : 4;
  __REG32                 : 4;
} __ghvsrc_bits;

/* Peripheral Asynchronous Clock Source Register (VCLKASRC) */
typedef struct {
  __REG32 VCLKA1S         : 4;
  __REG32                 : 4;
  __REG32 VCLKA2S         : 4;
  __REG32                 :20;
} __vclkasrc_bits;

/* RTI Clock Source Register (RCLKSRC) */
typedef struct {
  __REG32 RTI1SRC         : 4;
  __REG32                 : 4;
  __REG32 RTI1DIV         : 2;
  __REG32                 :22;
} __rclksrc_bits;

/* Clock Source Valid Status Register (CSVSTAT) */
typedef struct {
  __REG32 CLKSR0V         : 1;
  __REG32 CLKSR1V         : 1;
  __REG32                 : 1;
  __REG32 CLKSR3V         : 1;
  __REG32 CLKSR4V         : 1;
  __REG32 CLKSR5V         : 1;
  __REG32 CLKSR6V         : 1;
  __REG32 CLKSR7V         : 1;
  __REG32                 :24;
} __csvstat_bits;

/* Memory Self-Test Global Control Register (MSTGCR) */
typedef struct {
  __REG32 MSTGENA         : 4;
  __REG32                 : 4;
  __REG32 ROM_DIV         : 2;
  __REG32                 :22;
} __mstgcr_bits;

/* Memory Hardware Initialization Global Control Register (MINITGCR) */
typedef struct {
  __REG32 MINITGENA       : 4;
  __REG32                 :28;
} __minitgcr_bits;

/* MBIST Controller/Memory Initialization Enable Register (MSINENA) */
typedef struct {
  __REG32 MSIENA0         : 1;
  __REG32 MSIENA1         : 1;
  __REG32 MSIENA2         : 1;
  __REG32 MSIENA3         : 1;
  __REG32 MSIENA4         : 1;
  __REG32 MSIENA5         : 1;
  __REG32 MSIENA6         : 1;
  __REG32 MSIENA7         : 1;
  __REG32 MSIENA8         : 1;
  __REG32 MSIENA9         : 1;
  __REG32 MSIENA10        : 1;
  __REG32 MSIENA11        : 1;
  __REG32 MSIENA12        : 1;
  __REG32 MSIENA13        : 1;
  __REG32 MSIENA14        : 1;
  __REG32 MSIENA15        : 1;
  __REG32 MSIENA16        : 1;
  __REG32 MSIENA17        : 1;
  __REG32 MSIENA18        : 1;
  __REG32 MSIENA19        : 1;
  __REG32 MSIENA20        : 1;
  __REG32 MSIENA21        : 1;
  __REG32 MSIENA22        : 1;
  __REG32 MSIENA23        : 1;
  __REG32 MSIENA24        : 1;
  __REG32 MSIENA25        : 1;
  __REG32 MSIENA26        : 1;
  __REG32 MSIENA27        : 1;
  __REG32 MSIENA28        : 1;
  __REG32 MSIENA29        : 1;
  __REG32 MSIENA30        : 1;
  __REG32 MSIENA31        : 1;
} __msiena_bits;

/* MSTC Global Status Register (MSTCGSTAT) */
typedef struct {
  __REG32 MSTDONE         : 1;
  __REG32                 : 7;
  __REG32 MINIDONE        : 1;
  __REG32                 :23;
} __mstcgstat_bits;

/* Memory Hardware Initialization Status Register (MINISTAT) */
typedef struct {
  __REG32 MIDONE0         : 1;
  __REG32 MIDONE1         : 1;
  __REG32 MIDONE2         : 1;
  __REG32 MIDONE3         : 1;
  __REG32 MIDONE4         : 1;
  __REG32 MIDONE5         : 1;
  __REG32 MIDONE6         : 1;
  __REG32 MIDONE7         : 1;
  __REG32 MIDONE8         : 1;
  __REG32 MIDONE9         : 1;
  __REG32 MIDONE10        : 1;
  __REG32 MIDONE11        : 1;
  __REG32 MIDONE12        : 1;
  __REG32 MIDONE13        : 1;
  __REG32 MIDONE14        : 1;
  __REG32 MIDONE15        : 1;
  __REG32 MIDONE16        : 1;
  __REG32 MIDONE17        : 1;
  __REG32 MIDONE18        : 1;
  __REG32 MIDONE19        : 1;
  __REG32 MIDONE20        : 1;
  __REG32 MIDONE21        : 1;
  __REG32 MIDONE22        : 1;
  __REG32 MIDONE23        : 1;
  __REG32 MIDONE24        : 1;
  __REG32 MIDONE25        : 1;
  __REG32 MIDONE26        : 1;
  __REG32 MIDONE27        : 1;
  __REG32 MIDONE28        : 1;
  __REG32 MIDONE29        : 1;
  __REG32 MIDONE30        : 1;
  __REG32 MIDONE31        : 1;
} __ministat_bits;

/* PLL Control Register 1 (PLLCTL1) */
typedef struct {
  __REG32 PLLMUL          :16;
  __REG32 REFCLKDIV       : 6;
  __REG32                 : 1;
  __REG32 ROF             : 1;
  __REG32 PLLDIV          : 5;
  __REG32 MASK_SLIP       : 2;
  __REG32 ROS             : 1;
} __pllctl1_bits;

/* PLL Control Register 2 (PLLCTL2) */
typedef struct {
  __REG32 SPR_AMOUNT      : 9;
  __REG32 ODPLL           : 3;
  __REG32 MULMOD          : 9;
  __REG32                 : 1;
  __REG32 SPREADINGRATE   : 9;
  __REG32 FMENA           : 1;
} __pllctl2_bits;

/* SYS Pin Control Register 10 (SYSPC10) */
typedef struct {
  __REG32 ECPCLK_SLEW     : 1;
  __REG32                 :31;
} __syspc10_bits;

/* Die Identification Register, Lower Word (DIEIDL) */
typedef struct {
  __REG32 X_WAFER_COORDINATE  : 8;
  __REG32 Y_WAFER_COORDINATE  : 8;
  __REG32 WAFER               : 6;
  __REG32 LOT                 :10;
} __dieidl_bits;

/* Die Identification Register, Upper Word (DIEIDH) */
typedef struct {
  __REG32 LOT                 :14;
  __REG32                     :18;
} __dieidh_bits;

/* LPO/Clock Monitor Control Register (LPOMONCTL) */
typedef struct {
  __REG32 LFTRIM              : 5;
  __REG32                     : 3;
  __REG32 HFTRIM              : 5;
  __REG32                     : 3;
  __REG32 OSCFRQCONFIGCNT     : 1;
  __REG32                     : 7;
  __REG32 BIAS_ENABLE         : 1;
  __REG32                     : 7;
} __lpomonctl_bits;

/* Clock Test Register (CLKTEST) */
typedef struct {
  __REG32 SEL_ECP_PIN         : 4;
  __REG32                     : 4;
  __REG32 SEL_GIO_PIN         : 4;
  __REG32                     : 4;
  __REG32 CLK_TEST_EN         : 4;
  __REG32                     : 4;
  __REG32 RANGEDETENASSEL     : 1;
  __REG32 RANGEDETCTRL        : 1;
  __REG32 ALTLIMPCLOCKENABLE  : 1;
  __REG32                     : 5;
} __clktest_bits;

/* DFT Control Register (DFTCTRLREG) */
typedef struct {
  __REG32 TEST_MODE_KEY       : 4;
  __REG32                     : 4;
  __REG32 DFTREAD             : 2;
  __REG32                     : 2;
  __REG32 DFTWRITE            : 2;
  __REG32                     :18;
} __dftctrlreg_bits;

/* DFT Control Register (DFTCTRLREG2) */
typedef struct {
  __REG32 TEST_MODE_KEY       : 4;
  __REG32 IMPDF0              : 1;
  __REG32 IMPDF1              : 1;
  __REG32 IMPDF2              : 1;
  __REG32 IMPDF3              : 1;
  __REG32 IMPDF4              : 1;
  __REG32 IMPDF5              : 1;
  __REG32 IMPDF6              : 1;
  __REG32 IMPDF7              : 1;
  __REG32 IMPDF8              : 1;
  __REG32 IMPDF9              : 1;
  __REG32 IMPDF10             : 1;
  __REG32 IMPDF11             : 1;
  __REG32 IMPDF12             : 1;
  __REG32 IMPDF13             : 1;
  __REG32 IMPDF14             : 1;
  __REG32 IMPDF15             : 1;
  __REG32 IMPDF16             : 1;
  __REG32 IMPDF17             : 1;
  __REG32 IMPDF18             : 1;
  __REG32 IMPDF19             : 1;
  __REG32 IMPDF20             : 1;
  __REG32 IMPDF21             : 1;
  __REG32 IMPDF22             : 1;
  __REG32 IMPDF23             : 1;
  __REG32 IMPDF24             : 1;
  __REG32 IMPDF25             : 1;
  __REG32 IMPDF26             : 1;
  __REG32 IMPDF27             : 1;
} __dftctrlreg2_bits;

/* General Purpose Register (GPREG1) */
typedef struct {
  __REG32 OUTPUT_BUFFER_LOW_EMI_MODE  :16;
  __REG32 PLL1_RFSLIP_FILTER_KEY      : 4;
  __REG32 PLL1_FBSLIP_FILTER_COUNT    : 6;
  __REG32                             : 5;
  __REG32 EMIF_FUNC                   : 1;
} __gpreg1_bits;

/* Imprecise Fault Status Register (IMPFASTS) */
typedef struct {
  __REG32 ATYPE               : 1;
  __REG32                     : 7;
  __REG32 VBUSA               : 1;
  __REG32 NCBA                : 1;
  __REG32 EMIFA               : 1;
  __REG32                     : 5;
  __REG32 MASTERID            : 8;
  __REG32                     : 8;
} __impfasts_bits;

/* System Software Interrupt Request 1 Register (SSIR1) */
typedef struct {
  __REG32 SSDATA1             : 8;
  __REG32 SSKEY1              : 8;
  __REG32                     :16;
} __ssir1_bits;

/* System Software Interrupt Request 2 Register (SSIR2) */
typedef struct {
  __REG32 SSDATA2             : 8;
  __REG32 SSKEY2              : 8;
  __REG32                     :16;
} __ssir2_bits;

/* System Software Interrupt Request 3 Register (SSIR3) */
typedef struct {
  __REG32 SSDATA3             : 8;
  __REG32 SSKEY3              : 8;
  __REG32                     :16;
} __ssir3_bits;

/* System Software Interrupt Request 4 Register (SSIR4) */
typedef struct {
  __REG32 SSDATA4             : 8;
  __REG32 SSKEY4              : 8;
  __REG32                     :16;
} __ssir4_bits;

/* RAM Control Register (RAMGCR) */
typedef struct {
  __REG32 WST_DENA0           : 1;
  __REG32                     : 1;
  __REG32 WST_AENA0           : 1;
  __REG32                     :13;
  __REG32 RAM_DFT_EN          : 4;
  __REG32                     :12;
} __ramgcr_bits;

/* Bus Matrix Module Control Register 1 (BMMCR) */
typedef struct {
  __REG32 MEMSW               : 4;
  __REG32                     :28;
} __bmmcr_bits;

/* CPU Reset Control Register (CPURSTCR) */
typedef struct {
  __REG32 CPURESET            : 1;
  __REG32                     :31;
} __cpurstcr_bits;

/* Clock Control Register (CLKCNTL) */
typedef struct {
  __REG32                     : 8;
  __REG32 PENA                : 1;
  __REG32                     : 7;
  __REG32 VCLKR               : 4;
  __REG32                     : 4;
  __REG32 VCLK2R              : 4;
  __REG32                     : 4;
} __clkcntl_bits;

/* ECP Control Register (ECPCNTL) */
typedef struct {
  __REG32 ECPDIV              :16;
  __REG32 ECPINSEL            : 2;
  __REG32                     : 5;
  __REG32 ECPCOS              : 1;
  __REG32 ECPSSEL             : 1;
  __REG32                     : 7;
} __ecpcntl_bits;

/* DEV Parity Control Register1 (DEVCR1) */
typedef struct {
  __REG32 DEVPARSEL           : 4;
  __REG32                     :28;
} __devcr1_bits;

/* System Exception Control Register (SYSECR) */
typedef struct {
  __REG32                     :14;
  __REG32 RESET               : 2;
  __REG32                     :16;
} __sysecr_bits;

/* System Exception Status Register (SYSESR) */
typedef struct {
  __REG32 MPMODE              : 1;
  __REG32                     : 2;
  __REG32 EXTRST              : 1;
  __REG32 SWRST               : 1;
  __REG32 CPURST              : 1;
  __REG32                     : 7;
  __REG32 WDRST               : 1;
  __REG32 OSCRST              : 1;
  __REG32 PORST               : 1;
  __REG32                     :16;
} __sysesr_bits;

/* System Test Abort Status Register (SYSTASR) */
typedef struct {
  __REG32 EFUSE_Abort         : 5;
  __REG32                     :27;
} __systasr_bits;

/* Global Status Register (GLBSTAT) */
typedef struct {
  __REG32 OSCFAIL             : 1;
  __REG32                     : 7;
  __REG32 RFSLIP              : 1;
  __REG32 FBSLIP              : 1;
  __REG32                     :22;
} __glbstat_bits;

/* Device Identification Register (DEV) */
typedef struct {
  __REG32 PLATFORM_ID         : 3;
  __REG32 VERSION             : 5;
  __REG32 RAM_ECC             : 1;
  __REG32 FLASH_ECC           : 2;
  __REG32 PERIPHERAL_PARITY   : 1;
  __REG32 IO_VOLTAGE          : 1;
  __REG32 TECH                : 4;
  __REG32 UNIQUE_ID           :14;
  __REG32 CP15                : 1;
} __devid_bits;

/* Software Interrupt Vector Register (SSIVEC) */
typedef struct {
  __REG32 SSIVECT             : 8;
  __REG32 SSIDATA             : 8;
  __REG32                     :16;
} __ssivec_bits;

/* System Software Interrupt Flag Register (SSIF) */
typedef struct {
  __REG32 SSI_FLAG1           : 1;
  __REG32 SSI_FLAG2           : 1;
  __REG32 SSI_FLAG3           : 1;
  __REG32 SSI_FLAG4           : 1;
  __REG32                     :28;
} __ssif_bits;

/* PLL Control Register 3 (PLLCTL3) */
typedef struct {
  __REG32 PLL_MUL2            :16;
  __REG32 REFCLKDIV2          : 6;
  __REG32                     : 2;
  __REG32 PLLDIV2             : 5;
  __REG32 ODPLL2              : 3;
} __pllctl3_bits;

/* CPU Logic BIST Clock Prescaler (STCLKDIV) */
typedef struct {
  __REG32                     :24;
  __REG32 CLKDIV              : 3;
  __REG32                     : 5;
} __stcclkdiv_bits;

/* Clock 2 Control Register (CLK2CNTRL) */
typedef struct {
  __REG32 VCLK3R              : 4;
  __REG32                     :28;
} __clk2cntl_bits;

/* Peripheral Asynchronous Clock Configuration 1 Register (VCLKACON1) */
typedef struct {
  __REG32 VCLKA3S             : 4;
  __REG32 VCLKA3_DIV_CDDIS    : 1;
  __REG32                     : 3;
  __REG32 VCLKA3R             : 3;
  __REG32                     : 5;
  __REG32 VCLKA4S             : 4;
  __REG32 VCLKA4_DIV_CDDIS    : 1;
  __REG32                     : 3;
  __REG32 VCLKA4R             : 3;
  __REG32                     : 5;
} __vclkacon1_bits;

/* Clock Slip Register (CLKSLIP) */
typedef struct {
  __REG32 PLL1_SLIP_FILTER_KEY    : 4;
  __REG32                         : 4;
  __REG32 PLL1_SLIP_FILTER_COUNT  : 6;
  __REG32                         :18;
} __clkslip_bits;

/* EFUSE Controller Control Register (EFC_CTLREG) */
typedef struct {
  __REG32 EFC_INSTR_WEN           : 4;
  __REG32                         :28;
} __efc_ctlreg_bits;

/* Peripheral Memory Protection Set Register 0 (PMPROTSET0) */
typedef struct {
  __REG32 PCS0PROTSET         : 1;
  __REG32 PCS1PROTSET         : 1;
  __REG32 PCS2PROTSET         : 1;
  __REG32 PCS3PROTSET         : 1;
  __REG32 PCS4PROTSET         : 1;
  __REG32 PCS5PROTSET         : 1;
  __REG32 PCS6PROTSET         : 1;
  __REG32 PCS7PROTSET         : 1;
  __REG32 PCS8PROTSET         : 1;
  __REG32 PCS9PROTSET         : 1;
  __REG32 PCS10PROTSET        : 1;
  __REG32 PCS11PROTSET        : 1;
  __REG32 PCS12PROTSET        : 1;
  __REG32 PCS13PROTSET        : 1;
  __REG32 PCS14PROTSET        : 1;
  __REG32 PCS15PROTSET        : 1;
  __REG32 PCS16PROTSET        : 1;
  __REG32 PCS17PROTSET        : 1;
  __REG32 PCS18PROTSET        : 1;
  __REG32 PCS19PROTSET        : 1;
  __REG32 PCS20PROTSET        : 1;
  __REG32 PCS21PROTSET        : 1;
  __REG32 PCS22PROTSET        : 1;
  __REG32 PCS23PROTSET        : 1;
  __REG32 PCS24PROTSET        : 1;
  __REG32 PCS25PROTSET        : 1;
  __REG32 PCS26PROTSET        : 1;
  __REG32 PCS27PROTSET        : 1;
  __REG32 PCS28PROTSET        : 1;
  __REG32 PCS29PROTSET        : 1;
  __REG32 PCS30PROTSET        : 1;
  __REG32 PCS31PROTSET        : 1;
} __pmprotset0_bits;

/* Peripheral Memory Protection Set Register 1 (PMPROTSET1) */
typedef struct {
  __REG32 PCS32PROTSET        : 1;
  __REG32 PCS33PROTSET        : 1;
  __REG32 PCS34PROTSET        : 1;
  __REG32 PCS35PROTSET        : 1;
  __REG32 PCS36PROTSET        : 1;
  __REG32 PCS37PROTSET        : 1;
  __REG32 PCS38PROTSET        : 1;
  __REG32 PCS39PROTSET        : 1;
  __REG32 PCS40PROTSET        : 1;
  __REG32 PCS41PROTSET        : 1;
  __REG32 PCS42PROTSET        : 1;
  __REG32 PCS43PROTSET        : 1;
  __REG32 PCS44PROTSET        : 1;
  __REG32 PCS45PROTSET        : 1;
  __REG32 PCS46PROTSET        : 1;
  __REG32 PCS47PROTSET        : 1;
  __REG32 PCS48PROTSET        : 1;
  __REG32 PCS49PROTSET        : 1;
  __REG32 PCS50PROTSET        : 1;
  __REG32 PCS51PROTSET        : 1;
  __REG32 PCS52PROTSET        : 1;
  __REG32 PCS53PROTSET        : 1;
  __REG32 PCS54PROTSET        : 1;
  __REG32 PCS55PROTSET        : 1;
  __REG32 PCS56PROTSET        : 1;
  __REG32 PCS57PROTSET        : 1;
  __REG32 PCS58PROTSET        : 1;
  __REG32 PCS59PROTSET        : 1;
  __REG32 PCS60PROTSET        : 1;
  __REG32 PCS61PROTSET        : 1;
  __REG32 PCS62PROTSET        : 1;
  __REG32 PCS63PROTSET        : 1;
} __pmprotset1_bits;

/* Peripheral Memory Protection Clear Register 0 (PMPROTCLR0) */
typedef struct {
  __REG32 PCS0PROTCLR         : 1;
  __REG32 PCS1PROTCLR         : 1;
  __REG32 PCS2PROTCLR         : 1;
  __REG32 PCS3PROTCLR         : 1;
  __REG32 PCS4PROTCLR         : 1;
  __REG32 PCS5PROTCLR         : 1;
  __REG32 PCS6PROTCLR         : 1;
  __REG32 PCS7PROTCLR         : 1;
  __REG32 PCS8PROTCLR         : 1;
  __REG32 PCS9PROTCLR         : 1;
  __REG32 PCS10PROTCLR        : 1;
  __REG32 PCS11PROTCLR        : 1;
  __REG32 PCS12PROTCLR        : 1;
  __REG32 PCS13PROTCLR        : 1;
  __REG32 PCS14PROTCLR        : 1;
  __REG32 PCS15PROTCLR        : 1;
  __REG32 PCS16PROTCLR        : 1;
  __REG32 PCS17PROTCLR        : 1;
  __REG32 PCS18PROTCLR        : 1;
  __REG32 PCS19PROTCLR        : 1;
  __REG32 PCS20PROTCLR        : 1;
  __REG32 PCS21PROTCLR        : 1;
  __REG32 PCS22PROTCLR        : 1;
  __REG32 PCS23PROTCLR        : 1;
  __REG32 PCS24PROTCLR        : 1;
  __REG32 PCS25PROTCLR        : 1;
  __REG32 PCS26PROTCLR        : 1;
  __REG32 PCS27PROTCLR        : 1;
  __REG32 PCS28PROTCLR        : 1;
  __REG32 PCS29PROTCLR        : 1;
  __REG32 PCS30PROTCLR        : 1;
  __REG32 PCS31PROTCLR        : 1;
} __pmprotclr0_bits;

/* Peripheral Memory Protection Clear Register 1 (PMPROTCLR1) */
typedef struct {
  __REG32 PCS32PROTCLR        : 1;
  __REG32 PCS33PROTCLR        : 1;
  __REG32 PCS34PROTCLR        : 1;
  __REG32 PCS35PROTCLR        : 1;
  __REG32 PCS36PROTCLR        : 1;
  __REG32 PCS37PROTCLR        : 1;
  __REG32 PCS38PROTCLR        : 1;
  __REG32 PCS39PROTCLR        : 1;
  __REG32 PCS40PROTCLR        : 1;
  __REG32 PCS41PROTCLR        : 1;
  __REG32 PCS42PROTCLR        : 1;
  __REG32 PCS43PROTCLR        : 1;
  __REG32 PCS44PROTCLR        : 1;
  __REG32 PCS45PROTCLR        : 1;
  __REG32 PCS46PROTCLR        : 1;
  __REG32 PCS47PROTCLR        : 1;
  __REG32 PCS48PROTCLR        : 1;
  __REG32 PCS49PROTCLR        : 1;
  __REG32 PCS50PROTCLR        : 1;
  __REG32 PCS51PROTCLR        : 1;
  __REG32 PCS52PROTCLR        : 1;
  __REG32 PCS53PROTCLR        : 1;
  __REG32 PCS54PROTCLR        : 1;
  __REG32 PCS55PROTCLR        : 1;
  __REG32 PCS56PROTCLR        : 1;
  __REG32 PCS57PROTCLR        : 1;
  __REG32 PCS58PROTCLR        : 1;
  __REG32 PCS59PROTCLR        : 1;
  __REG32 PCS60PROTCLR        : 1;
  __REG32 PCS61PROTCLR        : 1;
  __REG32 PCS62PROTCLR        : 1;
  __REG32 PCS63PROTCLR        : 1;
} __pmprotclr1_bits;

/* Peripheral Protection Set Register 0 (PPROTSET0) */
typedef struct {
  __REG32 PCS0QUAD0PROTSET     : 1;
  __REG32 PCS0QUAD1PROTSET     : 1;
  __REG32 PCS0QUAD2PROTSET     : 1;
  __REG32 PCS0QUAD3PROTSET     : 1;
  __REG32 PCS1QUAD0PROTSET     : 1;
  __REG32 PCS1QUAD1PROTSET     : 1;
  __REG32 PCS1QUAD2PROTSET     : 1;
  __REG32 PCS1QUAD3PROTSET     : 1;
  __REG32 PCS2QUAD0PROTSET     : 1;
  __REG32 PCS2QUAD1PROTSET     : 1;
  __REG32 PCS2QUAD2PROTSET     : 1;
  __REG32 PCS2QUAD3PROTSET     : 1;
  __REG32 PCS3QUAD0PROTSET     : 1;
  __REG32 PCS3QUAD1PROTSET     : 1;
  __REG32 PCS3QUAD2PROTSET     : 1;
  __REG32 PCS3QUAD3PROTSET     : 1;
  __REG32 PCS4QUAD0PROTSET     : 1;
  __REG32 PCS4QUAD1PROTSET     : 1;
  __REG32 PCS4QUAD2PROTSET     : 1;
  __REG32 PCS4QUAD3PROTSET     : 1;
  __REG32 PCS5QUAD0PROTSET     : 1;
  __REG32 PCS5QUAD1PROTSET     : 1;
  __REG32 PCS5QUAD2PROTSET     : 1;
  __REG32 PCS5QUAD3PROTSET     : 1;
  __REG32 PCS6QUAD0PROTSET     : 1;
  __REG32 PCS6QUAD1PROTSET     : 1;
  __REG32 PCS6QUAD2PROTSET     : 1;
  __REG32 PCS6QUAD3PROTSET     : 1;
  __REG32 PCS7QUAD0PROTSET     : 1;
  __REG32 PCS7QUAD1PROTSET     : 1;
  __REG32 PCS7QUAD2PROTSET     : 1;
  __REG32 PCS7QUAD3PROTSET     : 1;
} __pprotset0_bits;

/* Peripheral Protection Set Register 1 (PPROTSET1) */
typedef struct {
  __REG32 PCS8QUAD0PROTSET     : 1;
  __REG32 PCS8QUAD1PROTSET     : 1;
  __REG32 PCS8QUAD2PROTSET     : 1;
  __REG32 PCS8QUAD3PROTSET     : 1;
  __REG32 PCS9QUAD0PROTSET     : 1;
  __REG32 PCS9QUAD1PROTSET     : 1;
  __REG32 PCS9QUAD2PROTSET     : 1;
  __REG32 PCS9QUAD3PROTSET     : 1;
  __REG32 PCS10QUAD0PROTSET    : 1;
  __REG32 PCS10QUAD1PROTSET    : 1;
  __REG32 PCS10QUAD2PROTSET    : 1;
  __REG32 PCS10QUAD3PROTSET    : 1;
  __REG32 PCS11QUAD0PROTSET    : 1;
  __REG32 PCS11QUAD1PROTSET    : 1;
  __REG32 PCS11QUAD2PROTSET    : 1;
  __REG32 PCS11QUAD3PROTSET    : 1;
  __REG32 PCS12QUAD0PROTSET    : 1;
  __REG32 PCS12QUAD1PROTSET    : 1;
  __REG32 PCS12QUAD2PROTSET    : 1;
  __REG32 PCS12QUAD3PROTSET    : 1;
  __REG32 PCS13QUAD0PROTSET    : 1;
  __REG32 PCS13QUAD1PROTSET    : 1;
  __REG32 PCS13QUAD2PROTSET    : 1;
  __REG32 PCS13QUAD3PROTSET    : 1;
  __REG32 PCS14QUAD0PROTSET    : 1;
  __REG32 PCS14QUAD1PROTSET    : 1;
  __REG32 PCS14QUAD2PROTSET    : 1;
  __REG32 PCS14QUAD3PROTSET    : 1;
  __REG32 PCS15QUAD0PROTSET    : 1;
  __REG32 PCS15QUAD1PROTSET    : 1;
  __REG32 PCS15QUAD2PROTSET    : 1;
  __REG32 PCS15QUAD3PROTSET    : 1;
} __pprotset1_bits;

/* Peripheral Protection Set Register 2 (PPROTSET2) */
typedef struct {
  __REG32 PCS16QUAD0PROTSET    : 1;
  __REG32 PCS16QUAD1PROTSET    : 1;
  __REG32 PCS16QUAD2PROTSET    : 1;
  __REG32 PCS16QUAD3PROTSET    : 1;
  __REG32 PCS17QUAD0PROTSET    : 1;
  __REG32 PCS17QUAD1PROTSET    : 1;
  __REG32 PCS17QUAD2PROTSET    : 1;
  __REG32 PCS17QUAD3PROTSET    : 1;
  __REG32 PCS18QUAD0PROTSET    : 1;
  __REG32 PCS18QUAD1PROTSET    : 1;
  __REG32 PCS18QUAD2PROTSET    : 1;
  __REG32 PCS18QUAD3PROTSET    : 1;
  __REG32 PCS19QUAD0PROTSET    : 1;
  __REG32 PCS19QUAD1PROTSET    : 1;
  __REG32 PCS19QUAD2PROTSET    : 1;
  __REG32 PCS19QUAD3PROTSET    : 1;
  __REG32 PCS20QUAD0PROTSET    : 1;
  __REG32 PCS20QUAD1PROTSET    : 1;
  __REG32 PCS20QUAD2PROTSET    : 1;
  __REG32 PCS20QUAD3PROTSET    : 1;
  __REG32 PCS21QUAD0PROTSET    : 1;
  __REG32 PCS21QUAD1PROTSET    : 1;
  __REG32 PCS21QUAD2PROTSET    : 1;
  __REG32 PCS21QUAD3PROTSET    : 1;
  __REG32 PCS22QUAD0PROTSET    : 1;
  __REG32 PCS22QUAD1PROTSET    : 1;
  __REG32 PCS22QUAD2PROTSET    : 1;
  __REG32 PCS22QUAD3PROTSET    : 1;
  __REG32 PCS23QUAD0PROTSET    : 1;
  __REG32 PCS23QUAD1PROTSET    : 1;
  __REG32 PCS23QUAD2PROTSET    : 1;
  __REG32 PCS23QUAD3PROTSET    : 1;
} __pprotset2_bits;

/* Peripheral Protection Set Register 3 (PPROTSET3) */
typedef struct {
  __REG32 PCS24QUAD0PROTSET    : 1;
  __REG32 PCS24QUAD1PROTSET    : 1;
  __REG32 PCS24QUAD2PROTSET    : 1;
  __REG32 PCS24QUAD3PROTSET    : 1;
  __REG32 PCS25QUAD0PROTSET    : 1;
  __REG32 PCS25QUAD1PROTSET    : 1;
  __REG32 PCS25QUAD2PROTSET    : 1;
  __REG32 PCS25QUAD3PROTSET    : 1;
  __REG32 PCS26QUAD0PROTSET    : 1;
  __REG32 PCS26QUAD1PROTSET    : 1;
  __REG32 PCS26QUAD2PROTSET    : 1;
  __REG32 PCS26QUAD3PROTSET    : 1;
  __REG32 PCS27QUAD0PROTSET    : 1;
  __REG32 PCS27QUAD1PROTSET    : 1;
  __REG32 PCS27QUAD2PROTSET    : 1;
  __REG32 PCS27QUAD3PROTSET    : 1;
  __REG32 PCS28QUAD0PROTSET    : 1;
  __REG32 PCS28QUAD1PROTSET    : 1;
  __REG32 PCS28QUAD2PROTSET    : 1;
  __REG32 PCS28QUAD3PROTSET    : 1;
  __REG32 PCS29QUAD0PROTSET    : 1;
  __REG32 PCS29QUAD1PROTSET    : 1;
  __REG32 PCS29QUAD2PROTSET    : 1;
  __REG32 PCS29QUAD3PROTSET    : 1;
  __REG32 PCS30QUAD0PROTSET    : 1;
  __REG32 PCS30QUAD1PROTSET    : 1;
  __REG32 PCS30QUAD2PROTSET    : 1;
  __REG32 PCS30QUAD3PROTSET    : 1;
  __REG32 PCS31QUAD0PROTSET    : 1;
  __REG32 PCS31QUAD1PROTSET    : 1;
  __REG32 PCS31QUAD2PROTSET    : 1;
  __REG32 PCS31QUAD3PROTSET    : 1;
} __pprotset3_bits;

/* Peripheral Protection Clear Register 0 (PPROTCLR0) */
typedef struct {
  __REG32 PCS0QUAD0PROTCLR     : 1;
  __REG32 PCS0QUAD1PROTCLR     : 1;
  __REG32 PCS0QUAD2PROTCLR     : 1;
  __REG32 PCS0QUAD3PROTCLR     : 1;
  __REG32 PCS1QUAD0PROTCLR     : 1;
  __REG32 PCS1QUAD1PROTCLR     : 1;
  __REG32 PCS1QUAD2PROTCLR     : 1;
  __REG32 PCS1QUAD3PROTCLR     : 1;
  __REG32 PCS2QUAD0PROTCLR     : 1;
  __REG32 PCS2QUAD1PROTCLR     : 1;
  __REG32 PCS2QUAD2PROTCLR     : 1;
  __REG32 PCS2QUAD3PROTCLR     : 1;
  __REG32 PCS3QUAD0PROTCLR     : 1;
  __REG32 PCS3QUAD1PROTCLR     : 1;
  __REG32 PCS3QUAD2PROTCLR     : 1;
  __REG32 PCS3QUAD3PROTCLR     : 1;
  __REG32 PCS4QUAD0PROTCLR     : 1;
  __REG32 PCS4QUAD1PROTCLR     : 1;
  __REG32 PCS4QUAD2PROTCLR     : 1;
  __REG32 PCS4QUAD3PROTCLR     : 1;
  __REG32 PCS5QUAD0PROTCLR     : 1;
  __REG32 PCS5QUAD1PROTCLR     : 1;
  __REG32 PCS5QUAD2PROTCLR     : 1;
  __REG32 PCS5QUAD3PROTCLR     : 1;
  __REG32 PCS6QUAD0PROTCLR     : 1;
  __REG32 PCS6QUAD1PROTCLR     : 1;
  __REG32 PCS6QUAD2PROTCLR     : 1;
  __REG32 PCS6QUAD3PROTCLR     : 1;
  __REG32 PCS7QUAD0PROTCLR     : 1;
  __REG32 PCS7QUAD1PROTCLR     : 1;
  __REG32 PCS7QUAD2PROTCLR     : 1;
  __REG32 PCS7QUAD3PROTCLR     : 1;
} __pprotclr0_bits;

/* Peripheral Protection Clear Register 1 (PPROTCLR1) */
typedef struct {
  __REG32 PCS8QUAD0PROTCLR     : 1;
  __REG32 PCS8QUAD1PROTCLR     : 1;
  __REG32 PCS8QUAD2PROTCLR     : 1;
  __REG32 PCS8QUAD3PROTCLR     : 1;
  __REG32 PCS9QUAD0PROTCLR     : 1;
  __REG32 PCS9QUAD1PROTCLR     : 1;
  __REG32 PCS9QUAD2PROTCLR     : 1;
  __REG32 PCS9QUAD3PROTCLR     : 1;
  __REG32 PCS10QUAD0PROTCLR    : 1;
  __REG32 PCS10QUAD1PROTCLR    : 1;
  __REG32 PCS10QUAD2PROTCLR    : 1;
  __REG32 PCS10QUAD3PROTCLR    : 1;
  __REG32 PCS11QUAD0PROTCLR    : 1;
  __REG32 PCS11QUAD1PROTCLR    : 1;
  __REG32 PCS11QUAD2PROTCLR    : 1;
  __REG32 PCS11QUAD3PROTCLR    : 1;
  __REG32 PCS12QUAD0PROTCLR    : 1;
  __REG32 PCS12QUAD1PROTCLR    : 1;
  __REG32 PCS12QUAD2PROTCLR    : 1;
  __REG32 PCS12QUAD3PROTCLR    : 1;
  __REG32 PCS13QUAD0PROTCLR    : 1;
  __REG32 PCS13QUAD1PROTCLR    : 1;
  __REG32 PCS13QUAD2PROTCLR    : 1;
  __REG32 PCS13QUAD3PROTCLR    : 1;
  __REG32 PCS14QUAD0PROTCLR    : 1;
  __REG32 PCS14QUAD1PROTCLR    : 1;
  __REG32 PCS14QUAD2PROTCLR    : 1;
  __REG32 PCS14QUAD3PROTCLR    : 1;
  __REG32 PCS15QUAD0PROTCLR    : 1;
  __REG32 PCS15QUAD1PROTCLR    : 1;
  __REG32 PCS15QUAD2PROTCLR    : 1;
  __REG32 PCS15QUAD3PROTCLR    : 1;
} __pprotclr1_bits;

/* Peripheral Protection Clear Register 2 (PPROTCLR2) */
typedef struct {
  __REG32 PCS16QUAD0PROTCLR    : 1;
  __REG32 PCS16QUAD1PROTCLR    : 1;
  __REG32 PCS16QUAD2PROTCLR    : 1;
  __REG32 PCS16QUAD3PROTCLR    : 1;
  __REG32 PCS17QUAD0PROTCLR    : 1;
  __REG32 PCS17QUAD1PROTCLR    : 1;
  __REG32 PCS17QUAD2PROTCLR    : 1;
  __REG32 PCS17QUAD3PROTCLR    : 1;
  __REG32 PCS18QUAD0PROTCLR    : 1;
  __REG32 PCS18QUAD1PROTCLR    : 1;
  __REG32 PCS18QUAD2PROTCLR    : 1;
  __REG32 PCS18QUAD3PROTCLR    : 1;
  __REG32 PCS19QUAD0PROTCLR    : 1;
  __REG32 PCS19QUAD1PROTCLR    : 1;
  __REG32 PCS19QUAD2PROTCLR    : 1;
  __REG32 PCS19QUAD3PROTCLR    : 1;
  __REG32 PCS20QUAD0PROTCLR    : 1;
  __REG32 PCS20QUAD1PROTCLR    : 1;
  __REG32 PCS20QUAD2PROTCLR    : 1;
  __REG32 PCS20QUAD3PROTCLR    : 1;
  __REG32 PCS21QUAD0PROTCLR    : 1;
  __REG32 PCS21QUAD1PROTCLR    : 1;
  __REG32 PCS21QUAD2PROTCLR    : 1;
  __REG32 PCS21QUAD3PROTCLR    : 1;
  __REG32 PCS22QUAD0PROTCLR    : 1;
  __REG32 PCS22QUAD1PROTCLR    : 1;
  __REG32 PCS22QUAD2PROTCLR    : 1;
  __REG32 PCS22QUAD3PROTCLR    : 1;
  __REG32 PCS23QUAD0PROTCLR    : 1;
  __REG32 PCS23QUAD1PROTCLR    : 1;
  __REG32 PCS23QUAD2PROTCLR    : 1;
  __REG32 PCS23QUAD3PROTCLR    : 1;
} __pprotclr2_bits;

/* Peripheral Protection Clear Register 3 (PPROTCLR3) */
typedef struct {
  __REG32 PCS24QUAD0PROTCLR    : 1;
  __REG32 PCS24QUAD1PROTCLR    : 1;
  __REG32 PCS24QUAD2PROTCLR    : 1;
  __REG32 PCS24QUAD3PROTCLR    : 1;
  __REG32 PCS25QUAD0PROTCLR    : 1;
  __REG32 PCS25QUAD1PROTCLR    : 1;
  __REG32 PCS25QUAD2PROTCLR    : 1;
  __REG32 PCS25QUAD3PROTCLR    : 1;
  __REG32 PCS26QUAD0PROTCLR    : 1;
  __REG32 PCS26QUAD1PROTCLR    : 1;
  __REG32 PCS26QUAD2PROTCLR    : 1;
  __REG32 PCS26QUAD3PROTCLR    : 1;
  __REG32 PCS27QUAD0PROTCLR    : 1;
  __REG32 PCS27QUAD1PROTCLR    : 1;
  __REG32 PCS27QUAD2PROTCLR    : 1;
  __REG32 PCS27QUAD3PROTCLR    : 1;
  __REG32 PCS28QUAD0PROTCLR    : 1;
  __REG32 PCS28QUAD1PROTCLR    : 1;
  __REG32 PCS28QUAD2PROTCLR    : 1;
  __REG32 PCS28QUAD3PROTCLR    : 1;
  __REG32 PCS29QUAD0PROTCLR    : 1;
  __REG32 PCS29QUAD1PROTCLR    : 1;
  __REG32 PCS29QUAD2PROTCLR    : 1;
  __REG32 PCS29QUAD3PROTCLR    : 1;
  __REG32 PCS30QUAD0PROTCLR    : 1;
  __REG32 PCS30QUAD1PROTCLR    : 1;
  __REG32 PCS30QUAD2PROTCLR    : 1;
  __REG32 PCS30QUAD3PROTCLR    : 1;
  __REG32 PCS31QUAD0PROTCLR    : 1;
  __REG32 PCS31QUAD1PROTCLR    : 1;
  __REG32 PCS31QUAD2PROTCLR    : 1;
  __REG32 PCS31QUAD3PROTCLR    : 1;
} __pprotclr3_bits;

/* Peripheral Memory Power-Down Set Register 0 (PCSPWRDWNSET0) */
typedef struct {
  __REG32 PCS0PWRDWNSET       : 1;
  __REG32 PCS1PWRDWNSET       : 1;
  __REG32 PCS2PWRDWNSET       : 1;
  __REG32 PCS3PWRDWNSET       : 1;
  __REG32 PCS4PWRDWNSET       : 1;
  __REG32 PCS5PWRDWNSET       : 1;
  __REG32 PCS6PWRDWNSET       : 1;
  __REG32 PCS7PWRDWNSET       : 1;
  __REG32 PCS8PWRDWNSET       : 1;
  __REG32 PCS9PWRDWNSET       : 1;
  __REG32 PCS10PWRDWNSET      : 1;
  __REG32 PCS11PWRDWNSET      : 1;
  __REG32 PCS12PWRDWNSET      : 1;
  __REG32 PCS13PWRDWNSET      : 1;
  __REG32 PCS14PWRDWNSET      : 1;
  __REG32 PCS15PWRDWNSET      : 1;
  __REG32 PCS16PWRDWNSET      : 1;
  __REG32 PCS17PWRDWNSET      : 1;
  __REG32 PCS18PWRDWNSET      : 1;
  __REG32 PCS19PWRDWNSET      : 1;
  __REG32 PCS20PWRDWNSET      : 1;
  __REG32 PCS21PWRDWNSET      : 1;
  __REG32 PCS22PWRDWNSET      : 1;
  __REG32 PCS23PWRDWNSET      : 1;
  __REG32 PCS24PWRDWNSET      : 1;
  __REG32 PCS25PWRDWNSET      : 1;
  __REG32 PCS26PWRDWNSET      : 1;
  __REG32 PCS27PWRDWNSET      : 1;
  __REG32 PCS28PWRDWNSET      : 1;
  __REG32 PCS29PWRDWNSET      : 1;
  __REG32 PCS30PWRDWNSET      : 1;
  __REG32 PCS31PWRDWNSET      : 1;
} __pcspwrdwnset0_bits;

/* Peripheral Memory Power-Down Set Register 1 (PCSPWRDWNSET1) */
typedef struct {
  __REG32 PCS32PWRDWNSET      : 1;
  __REG32 PCS33PWRDWNSET      : 1;
  __REG32 PCS34PWRDWNSET      : 1;
  __REG32 PCS35PWRDWNSET      : 1;
  __REG32 PCS36PWRDWNSET      : 1;
  __REG32 PCS37PWRDWNSET      : 1;
  __REG32 PCS38PWRDWNSET      : 1;
  __REG32 PCS39PWRDWNSET      : 1;
  __REG32 PCS40PWRDWNSET      : 1;
  __REG32 PCS41PWRDWNSET      : 1;
  __REG32 PCS42PWRDWNSET      : 1;
  __REG32 PCS43PWRDWNSET      : 1;
  __REG32 PCS44PWRDWNSET      : 1;
  __REG32 PCS45PWRDWNSET      : 1;
  __REG32 PCS46PWRDWNSET      : 1;
  __REG32 PCS47PWRDWNSET      : 1;
  __REG32 PCS48PWRDWNSET      : 1;
  __REG32 PCS49PWRDWNSET      : 1;
  __REG32 PCS50PWRDWNSET      : 1;
  __REG32 PCS51PWRDWNSET      : 1;
  __REG32 PCS52PWRDWNSET      : 1;
  __REG32 PCS53PWRDWNSET      : 1;
  __REG32 PCS54PWRDWNSET      : 1;
  __REG32 PCS55PWRDWNSET      : 1;
  __REG32 PCS56PWRDWNSET      : 1;
  __REG32 PCS57PWRDWNSET      : 1;
  __REG32 PCS58PWRDWNSET      : 1;
  __REG32 PCS59PWRDWNSET      : 1;
  __REG32 PCS60PWRDWNSET      : 1;
  __REG32 PCS61PWRDWNSET      : 1;
  __REG32 PCS62PWRDWNSET      : 1;
  __REG32 PCS63PWRDWNSET      : 1;
} __pcspwrdwnset1_bits;

/* Peripheral Memory Power-Down Clear Register 0 (PCSPWRDWNCLR0) */
typedef struct {
  __REG32 PCS0PWRDWNCLR       : 1;
  __REG32 PCS1PWRDWNCLR       : 1;
  __REG32 PCS2PWRDWNCLR       : 1;
  __REG32 PCS3PWRDWNCLR       : 1;
  __REG32 PCS4PWRDWNCLR       : 1;
  __REG32 PCS5PWRDWNCLR       : 1;
  __REG32 PCS6PWRDWNCLR       : 1;
  __REG32 PCS7PWRDWNCLR       : 1;
  __REG32 PCS8PWRDWNCLR       : 1;
  __REG32 PCS9PWRDWNCLR       : 1;
  __REG32 PCS10PWRDWNCLR      : 1;
  __REG32 PCS11PWRDWNCLR      : 1;
  __REG32 PCS12PWRDWNCLR      : 1;
  __REG32 PCS13PWRDWNCLR      : 1;
  __REG32 PCS14PWRDWNCLR      : 1;
  __REG32 PCS15PWRDWNCLR      : 1;
  __REG32 PCS16PWRDWNCLR      : 1;
  __REG32 PCS17PWRDWNCLR      : 1;
  __REG32 PCS18PWRDWNCLR      : 1;
  __REG32 PCS19PWRDWNCLR      : 1;
  __REG32 PCS20PWRDWNCLR      : 1;
  __REG32 PCS21PWRDWNCLR      : 1;
  __REG32 PCS22PWRDWNCLR      : 1;
  __REG32 PCS23PWRDWNCLR      : 1;
  __REG32 PCS24PWRDWNCLR      : 1;
  __REG32 PCS25PWRDWNCLR      : 1;
  __REG32 PCS26PWRDWNCLR      : 1;
  __REG32 PCS27PWRDWNCLR      : 1;
  __REG32 PCS28PWRDWNCLR      : 1;
  __REG32 PCS29PWRDWNCLR      : 1;
  __REG32 PCS30PWRDWNCLR      : 1;
  __REG32 PCS31PWRDWNCLR      : 1;
} __pcspwrdwnclr0_bits;

/* Peripheral Memory Power-Down Clear Register 1 (PCSPWRDWNCLR1) */
typedef struct {
  __REG32 PCS32PWRDWNCLR      : 1;
  __REG32 PCS33PWRDWNCLR      : 1;
  __REG32 PCS34PWRDWNCLR      : 1;
  __REG32 PCS35PWRDWNCLR      : 1;
  __REG32 PCS36PWRDWNCLR      : 1;
  __REG32 PCS37PWRDWNCLR      : 1;
  __REG32 PCS38PWRDWNCLR      : 1;
  __REG32 PCS39PWRDWNCLR      : 1;
  __REG32 PCS40PWRDWNCLR      : 1;
  __REG32 PCS41PWRDWNCLR      : 1;
  __REG32 PCS42PWRDWNCLR      : 1;
  __REG32 PCS43PWRDWNCLR      : 1;
  __REG32 PCS44PWRDWNCLR      : 1;
  __REG32 PCS45PWRDWNCLR      : 1;
  __REG32 PCS46PWRDWNCLR      : 1;
  __REG32 PCS47PWRDWNCLR      : 1;
  __REG32 PCS48PWRDWNCLR      : 1;
  __REG32 PCS49PWRDWNCLR      : 1;
  __REG32 PCS50PWRDWNCLR      : 1;
  __REG32 PCS51PWRDWNCLR      : 1;
  __REG32 PCS52PWRDWNCLR      : 1;
  __REG32 PCS53PWRDWNCLR      : 1;
  __REG32 PCS54PWRDWNCLR      : 1;
  __REG32 PCS55PWRDWNCLR      : 1;
  __REG32 PCS56PWRDWNCLR      : 1;
  __REG32 PCS57PWRDWNCLR      : 1;
  __REG32 PCS58PWRDWNCLR      : 1;
  __REG32 PCS59PWRDWNCLR      : 1;
  __REG32 PCS60PWRDWNCLR      : 1;
  __REG32 PCS61PWRDWNCLR      : 1;
  __REG32 PCS62PWRDWNCLR      : 1;
  __REG32 PCS63PWRDWNCLR      : 1;
} __pcspwrdwnclr1_bits;

/* Peripheral Power-Down Set Register 0 (PSPWRDWNSET0) */
typedef struct {
  __REG32 PS0QUAD0PWRDWNSET   : 1;
  __REG32 PS0QUAD1PWRDWNSET   : 1;
  __REG32 PS0QUAD2PWRDWNSET   : 1;
  __REG32 PS0QUAD3PWRDWNSET   : 1;
  __REG32 PS1QUAD0PWRDWNSET   : 1;
  __REG32 PS1QUAD1PWRDWNSET   : 1;
  __REG32 PS1QUAD2PWRDWNSET   : 1;
  __REG32 PS1QUAD3PWRDWNSET   : 1;
  __REG32 PS2QUAD0PWRDWNSET   : 1;
  __REG32 PS2QUAD1PWRDWNSET   : 1;
  __REG32 PS2QUAD2PWRDWNSET   : 1;
  __REG32 PS2QUAD3PWRDWNSET   : 1;
  __REG32 PS3QUAD0PWRDWNSET   : 1;
  __REG32 PS3QUAD1PWRDWNSET   : 1;
  __REG32 PS3QUAD2PWRDWNSET   : 1;
  __REG32 PS3QUAD3PWRDWNSET   : 1;
  __REG32 PS4QUAD0PWRDWNSET   : 1;
  __REG32 PS4QUAD1PWRDWNSET   : 1;
  __REG32 PS4QUAD2PWRDWNSET   : 1;
  __REG32 PS4QUAD3PWRDWNSET   : 1;
  __REG32 PS5QUAD0PWRDWNSET   : 1;
  __REG32 PS5QUAD1PWRDWNSET   : 1;
  __REG32 PS5QUAD2PWRDWNSET   : 1;
  __REG32 PS5QUAD3PWRDWNSET   : 1;
  __REG32 PS6QUAD0PWRDWNSET   : 1;
  __REG32 PS6QUAD1PWRDWNSET   : 1;
  __REG32 PS6QUAD2PWRDWNSET   : 1;
  __REG32 PS6QUAD3PWRDWNSET   : 1;
  __REG32 PS7QUAD0PWRDWNSET   : 1;
  __REG32 PS7QUAD1PWRDWNSET   : 1;
  __REG32 PS7QUAD2PWRDWNSET   : 1;
  __REG32 PS7QUAD3PWRDWNSET   : 1;
} __pspwrdwnset0_bits;

/* Peripheral Power-Down Set Register 1 (PSPWRDWNSET1) */
typedef struct {
  __REG32 PS8QUAD0PWRDWNSET   : 1;
  __REG32 PS8QUAD1PWRDWNSET   : 1;
  __REG32 PS8QUAD2PWRDWNSET   : 1;
  __REG32 PS8QUAD3PWRDWNSET   : 1;
  __REG32 PS9QUAD0PWRDWNSET   : 1;
  __REG32 PS9QUAD1PWRDWNSET   : 1;
  __REG32 PS9QUAD2PWRDWNSET   : 1;
  __REG32 PS9QUAD3PWRDWNSET   : 1;
  __REG32 PS10QUAD0PWRDWNSET  : 1;
  __REG32 PS10QUAD1PWRDWNSET  : 1;
  __REG32 PS10QUAD2PWRDWNSET  : 1;
  __REG32 PS10QUAD3PWRDWNSET  : 1;
  __REG32 PS11QUAD0PWRDWNSET  : 1;
  __REG32 PS11QUAD1PWRDWNSET  : 1;
  __REG32 PS11QUAD2PWRDWNSET  : 1;
  __REG32 PS11QUAD3PWRDWNSET  : 1;
  __REG32 PS12QUAD0PWRDWNSET  : 1;
  __REG32 PS12QUAD1PWRDWNSET  : 1;
  __REG32 PS12QUAD2PWRDWNSET  : 1;
  __REG32 PS12QUAD3PWRDWNSET  : 1;
  __REG32 PS13QUAD0PWRDWNSET  : 1;
  __REG32 PS13QUAD1PWRDWNSET  : 1;
  __REG32 PS13QUAD2PWRDWNSET  : 1;
  __REG32 PS13QUAD3PWRDWNSET  : 1;
  __REG32 PS14QUAD0PWRDWNSET  : 1;
  __REG32 PS14QUAD1PWRDWNSET  : 1;
  __REG32 PS14QUAD2PWRDWNSET  : 1;
  __REG32 PS14QUAD3PWRDWNSET  : 1;
  __REG32 PS15QUAD0PWRDWNSET  : 1;
  __REG32 PS15QUAD1PWRDWNSET  : 1;
  __REG32 PS15QUAD2PWRDWNSET  : 1;
  __REG32 PS15QUAD3PWRDWNSET  : 1;
} __pspwrdwnset1_bits;

/* Peripheral Power-Down Set Register 2 (PSPWRDWNSET2) */
typedef struct {
  __REG32 PS16QUAD0PWRDWNSET  : 1;
  __REG32 PS16QUAD1PWRDWNSET  : 1;
  __REG32 PS16QUAD2PWRDWNSET  : 1;
  __REG32 PS16QUAD3PWRDWNSET  : 1;
  __REG32 PS17QUAD0PWRDWNSET  : 1;
  __REG32 PS17QUAD1PWRDWNSET  : 1;
  __REG32 PS17QUAD2PWRDWNSET  : 1;
  __REG32 PS17QUAD3PWRDWNSET  : 1;
  __REG32 PS18QUAD0PWRDWNSET  : 1;
  __REG32 PS18QUAD1PWRDWNSET  : 1;
  __REG32 PS18QUAD2PWRDWNSET  : 1;
  __REG32 PS18QUAD3PWRDWNSET  : 1;
  __REG32 PS19QUAD0PWRDWNSET  : 1;
  __REG32 PS19QUAD1PWRDWNSET  : 1;
  __REG32 PS19QUAD2PWRDWNSET  : 1;
  __REG32 PS19QUAD3PWRDWNSET  : 1;
  __REG32 PS20QUAD0PWRDWNSET  : 1;
  __REG32 PS20QUAD1PWRDWNSET  : 1;
  __REG32 PS20QUAD2PWRDWNSET  : 1;
  __REG32 PS20QUAD3PWRDWNSET  : 1;
  __REG32 PS21QUAD0PWRDWNSET  : 1;
  __REG32 PS21QUAD1PWRDWNSET  : 1;
  __REG32 PS21QUAD2PWRDWNSET  : 1;
  __REG32 PS21QUAD3PWRDWNSET  : 1;
  __REG32 PS22QUAD0PWRDWNSET  : 1;
  __REG32 PS22QUAD1PWRDWNSET  : 1;
  __REG32 PS22QUAD2PWRDWNSET  : 1;
  __REG32 PS22QUAD3PWRDWNSET  : 1;
  __REG32 PS23QUAD0PWRDWNSET  : 1;
  __REG32 PS23QUAD1PWRDWNSET  : 1;
  __REG32 PS23QUAD2PWRDWNSET  : 1;
  __REG32 PS23QUAD3PWRDWNSET  : 1;
} __pspwrdwnset2_bits;

/* Peripheral Power-Down Set Register 3 (PSPWRDWNSET3) */
typedef struct {
  __REG32 PS24QUAD0PWRDWNSET  : 1;
  __REG32 PS24QUAD1PWRDWNSET  : 1;
  __REG32 PS24QUAD2PWRDWNSET  : 1;
  __REG32 PS24QUAD3PWRDWNSET  : 1;
  __REG32 PS25QUAD0PWRDWNSET  : 1;
  __REG32 PS25QUAD1PWRDWNSET  : 1;
  __REG32 PS25QUAD2PWRDWNSET  : 1;
  __REG32 PS25QUAD3PWRDWNSET  : 1;
  __REG32 PS26QUAD0PWRDWNSET  : 1;
  __REG32 PS26QUAD1PWRDWNSET  : 1;
  __REG32 PS26QUAD2PWRDWNSET  : 1;
  __REG32 PS26QUAD3PWRDWNSET  : 1;
  __REG32 PS27QUAD0PWRDWNSET  : 1;
  __REG32 PS27QUAD1PWRDWNSET  : 1;
  __REG32 PS27QUAD2PWRDWNSET  : 1;
  __REG32 PS27QUAD3PWRDWNSET  : 1;
  __REG32 PS28QUAD0PWRDWNSET  : 1;
  __REG32 PS28QUAD1PWRDWNSET  : 1;
  __REG32 PS28QUAD2PWRDWNSET  : 1;
  __REG32 PS28QUAD3PWRDWNSET  : 1;
  __REG32 PS29QUAD0PWRDWNSET  : 1;
  __REG32 PS29QUAD1PWRDWNSET  : 1;
  __REG32 PS29QUAD2PWRDWNSET  : 1;
  __REG32 PS29QUAD3PWRDWNSET  : 1;
  __REG32 PS30QUAD0PWRDWNSET  : 1;
  __REG32 PS30QUAD1PWRDWNSET  : 1;
  __REG32 PS30QUAD2PWRDWNSET  : 1;
  __REG32 PS30QUAD3PWRDWNSET  : 1;
  __REG32 PS31QUAD0PWRDWNSET  : 1;
  __REG32 PS31QUAD1PWRDWNSET  : 1;
  __REG32 PS31QUAD2PWRDWNSET  : 1;
  __REG32 PS31QUAD3PWRDWNSET  : 1;
} __pspwrdwnset3_bits;

/* Peripheral Power-Down Clear Register 0 (PSPWRDWNCLR0) */
typedef struct {
  __REG32 PS0QUAD0PWRDWNCLR   : 1;
  __REG32 PS0QUAD1PWRDWNCLR   : 1;
  __REG32 PS0QUAD2PWRDWNCLR   : 1;
  __REG32 PS0QUAD3PWRDWNCLR   : 1;
  __REG32 PS1QUAD0PWRDWNCLR   : 1;
  __REG32 PS1QUAD1PWRDWNCLR   : 1;
  __REG32 PS1QUAD2PWRDWNCLR   : 1;
  __REG32 PS1QUAD3PWRDWNCLR   : 1;
  __REG32 PS2QUAD0PWRDWNCLR   : 1;
  __REG32 PS2QUAD1PWRDWNCLR   : 1;
  __REG32 PS2QUAD2PWRDWNCLR   : 1;
  __REG32 PS2QUAD3PWRDWNCLR   : 1;
  __REG32 PS3QUAD0PWRDWNCLR   : 1;
  __REG32 PS3QUAD1PWRDWNCLR   : 1;
  __REG32 PS3QUAD2PWRDWNCLR   : 1;
  __REG32 PS3QUAD3PWRDWNCLR   : 1;
  __REG32 PS4QUAD0PWRDWNCLR   : 1;
  __REG32 PS4QUAD1PWRDWNCLR   : 1;
  __REG32 PS4QUAD2PWRDWNCLR   : 1;
  __REG32 PS4QUAD3PWRDWNCLR   : 1;
  __REG32 PS5QUAD0PWRDWNCLR   : 1;
  __REG32 PS5QUAD1PWRDWNCLR   : 1;
  __REG32 PS5QUAD2PWRDWNCLR   : 1;
  __REG32 PS5QUAD3PWRDWNCLR   : 1;
  __REG32 PS6QUAD0PWRDWNCLR   : 1;
  __REG32 PS6QUAD1PWRDWNCLR   : 1;
  __REG32 PS6QUAD2PWRDWNCLR   : 1;
  __REG32 PS6QUAD3PWRDWNCLR   : 1;
  __REG32 PS7QUAD0PWRDWNCLR   : 1;
  __REG32 PS7QUAD1PWRDWNCLR   : 1;
  __REG32 PS7QUAD2PWRDWNCLR   : 1;
  __REG32 PS7QUAD3PWRDWNCLR   : 1;
} __pspwrdwnclr0_bits;

/* Peripheral Power-Down Clear Register 1 (PSPWRDWNCLR1) */
typedef struct {
  __REG32 PS8QUAD0PWRDWNCLR   : 1;
  __REG32 PS8QUAD1PWRDWNCLR   : 1;
  __REG32 PS8QUAD2PWRDWNCLR   : 1;
  __REG32 PS8QUAD3PWRDWNCLR   : 1;
  __REG32 PS9QUAD0PWRDWNCLR   : 1;
  __REG32 PS9QUAD1PWRDWNCLR   : 1;
  __REG32 PS9QUAD2PWRDWNCLR   : 1;
  __REG32 PS9QUAD3PWRDWNCLR   : 1;
  __REG32 PS10QUAD0PWRDWNCLR  : 1;
  __REG32 PS10QUAD1PWRDWNCLR  : 1;
  __REG32 PS10QUAD2PWRDWNCLR  : 1;
  __REG32 PS10QUAD3PWRDWNCLR  : 1;
  __REG32 PS11QUAD0PWRDWNCLR  : 1;
  __REG32 PS11QUAD1PWRDWNCLR  : 1;
  __REG32 PS11QUAD2PWRDWNCLR  : 1;
  __REG32 PS11QUAD3PWRDWNCLR  : 1;
  __REG32 PS12QUAD0PWRDWNCLR  : 1;
  __REG32 PS12QUAD1PWRDWNCLR  : 1;
  __REG32 PS12QUAD2PWRDWNCLR  : 1;
  __REG32 PS12QUAD3PWRDWNCLR  : 1;
  __REG32 PS13QUAD0PWRDWNCLR  : 1;
  __REG32 PS13QUAD1PWRDWNCLR  : 1;
  __REG32 PS13QUAD2PWRDWNCLR  : 1;
  __REG32 PS13QUAD3PWRDWNCLR  : 1;
  __REG32 PS14QUAD0PWRDWNCLR  : 1;
  __REG32 PS14QUAD1PWRDWNCLR  : 1;
  __REG32 PS14QUAD2PWRDWNCLR  : 1;
  __REG32 PS14QUAD3PWRDWNCLR  : 1;
  __REG32 PS15QUAD0PWRDWNCLR  : 1;
  __REG32 PS15QUAD1PWRDWNCLR  : 1;
  __REG32 PS15QUAD2PWRDWNCLR  : 1;
  __REG32 PS15QUAD3PWRDWNCLR  : 1;
} __pspwrdwnclr1_bits;

/* Peripheral Power-Down Clear Register 2 (PSPWRDWNCLR2) */
typedef struct {
  __REG32 PS16QUAD0PWRDWNCLR  : 1;
  __REG32 PS16QUAD1PWRDWNCLR  : 1;
  __REG32 PS16QUAD2PWRDWNCLR  : 1;
  __REG32 PS16QUAD3PWRDWNCLR  : 1;
  __REG32 PS17QUAD0PWRDWNCLR  : 1;
  __REG32 PS17QUAD1PWRDWNCLR  : 1;
  __REG32 PS17QUAD2PWRDWNCLR  : 1;
  __REG32 PS17QUAD3PWRDWNCLR  : 1;
  __REG32 PS18QUAD0PWRDWNCLR  : 1;
  __REG32 PS18QUAD1PWRDWNCLR  : 1;
  __REG32 PS18QUAD2PWRDWNCLR  : 1;
  __REG32 PS18QUAD3PWRDWNCLR  : 1;
  __REG32 PS19QUAD0PWRDWNCLR  : 1;
  __REG32 PS19QUAD1PWRDWNCLR  : 1;
  __REG32 PS19QUAD2PWRDWNCLR  : 1;
  __REG32 PS19QUAD3PWRDWNCLR  : 1;
  __REG32 PS20QUAD0PWRDWNCLR  : 1;
  __REG32 PS20QUAD1PWRDWNCLR  : 1;
  __REG32 PS20QUAD2PWRDWNCLR  : 1;
  __REG32 PS20QUAD3PWRDWNCLR  : 1;
  __REG32 PS21QUAD0PWRDWNCLR  : 1;
  __REG32 PS21QUAD1PWRDWNCLR  : 1;
  __REG32 PS21QUAD2PWRDWNCLR  : 1;
  __REG32 PS21QUAD3PWRDWNCLR  : 1;
  __REG32 PS22QUAD0PWRDWNCLR  : 1;
  __REG32 PS22QUAD1PWRDWNCLR  : 1;
  __REG32 PS22QUAD2PWRDWNCLR  : 1;
  __REG32 PS22QUAD3PWRDWNCLR  : 1;
  __REG32 PS23QUAD0PWRDWNCLR  : 1;
  __REG32 PS23QUAD1PWRDWNCLR  : 1;
  __REG32 PS23QUAD2PWRDWNCLR  : 1;
  __REG32 PS23QUAD3PWRDWNCLR  : 1;
} __pspwrdwnclr2_bits;

/* Peripheral Power-Down Clear Register 3 (PSPWRDWNCLR) */
typedef struct {
  __REG32 PS24QUAD0PWRDWNCLR  : 1;
  __REG32 PS24QUAD1PWRDWNCLR  : 1;
  __REG32 PS24QUAD2PWRDWNCLR  : 1;
  __REG32 PS24QUAD3PWRDWNCLR  : 1;
  __REG32 PS25QUAD0PWRDWNCLR  : 1;
  __REG32 PS25QUAD1PWRDWNCLR  : 1;
  __REG32 PS25QUAD2PWRDWNCLR  : 1;
  __REG32 PS25QUAD3PWRDWNCLR  : 1;
  __REG32 PS26QUAD0PWRDWNCLR  : 1;
  __REG32 PS26QUAD1PWRDWNCLR  : 1;
  __REG32 PS26QUAD2PWRDWNCLR  : 1;
  __REG32 PS26QUAD3PWRDWNCLR  : 1;
  __REG32 PS27QUAD0PWRDWNCLR  : 1;
  __REG32 PS27QUAD1PWRDWNCLR  : 1;
  __REG32 PS27QUAD2PWRDWNCLR  : 1;
  __REG32 PS27QUAD3PWRDWNCLR  : 1;
  __REG32 PS28QUAD0PWRDWNCLR  : 1;
  __REG32 PS28QUAD1PWRDWNCLR  : 1;
  __REG32 PS28QUAD2PWRDWNCLR  : 1;
  __REG32 PS28QUAD3PWRDWNCLR  : 1;
  __REG32 PS29QUAD0PWRDWNCLR  : 1;
  __REG32 PS29QUAD1PWRDWNCLR  : 1;
  __REG32 PS29QUAD2PWRDWNCLR  : 1;
  __REG32 PS29QUAD3PWRDWNCLR  : 1;
  __REG32 PS30QUAD0PWRDWNCLR  : 1;
  __REG32 PS30QUAD1PWRDWNCLR  : 1;
  __REG32 PS30QUAD2PWRDWNCLR  : 1;
  __REG32 PS30QUAD3PWRDWNCLR  : 1;
  __REG32 PS31QUAD0PWRDWNCLR  : 1;
  __REG32 PS31QUAD1PWRDWNCLR  : 1;
  __REG32 PS31QUAD2PWRDWNCLR  : 1;
  __REG32 PS31QUAD3PWRDWNCLR  : 1;
} __pspwrdwnclr3_bits;

/* PBIST RAM Configuration Register (RAMT) */
typedef struct {
  __REG32 RLS                   : 2;
  __REG32 PLS                   : 4;
  __REG32 SMS                   : 2;
  __REG32 DWR                   : 8;
  __REG32 RDS                   : 8;
  __REG32 RGS                   : 8;
} __pbist_ramt_bits;

/* PBIST Datalogger Register (DLR) */
typedef struct {
  __REG32                       : 2;
  __REG32 DLR2                  : 1;
  __REG32                       : 1;
  __REG32 DLR4                  : 1;
  __REG32                       :27;
} __pbist_dlr_bits;

/* PBIST PBIST Activate/ROM Clock Enable Register (PACT) */
typedef struct {
  __REG32 PACT0                 : 1;
  __REG32 PACT1                 : 1;
  __REG32                       :30;
} __pbist_pact_bits;

/* PBIST ID Register (PBIST_ID) */
typedef struct {
  __REG32 PBIST_ID              : 8;
  __REG32                       :24;
} __pbist_id_bits;

/* PBIST Override Register (OVER) */
typedef struct {
  __REG32 OVER0                 : 1;
  __REG32                       :31;
} __pbist_over_bits;

/* PBIST Fail Status Fail Register 0 (FSRF0) */
typedef struct {
  __REG32 FSRF0                 : 1;
  __REG32                       :31;
} __pbist_fsrf0_bits;

/* PBIST Fail Status Fail Register 1 (FSRF1) */
typedef struct {
  __REG32 FSRF1                 : 1;
  __REG32                       :31;
} __pbist_fsrf1_bits;

/* Fail Status Count Register 0 (FSRC0) */
typedef struct {
  __REG32 FSRC0                 : 8;
  __REG32                       :24;
} __pbist_fsrc0_bits;

/* Fail Status Count Register 1 (FSRC1) */
typedef struct {
  __REG32 FSRC1                 : 8;
  __REG32                       :24;
} __pbist_fsrc1_bits;

/* Fail Status Address Register (FSRA0) */
typedef struct {
  __REG32 FSRA0                 :16;
  __REG32                       :16;
} __pbist_fsra0_bits;

/* Fail Status Address Register (FSRA1) */
typedef struct {
  __REG32 FSRA1                 :16;
  __REG32                       :16;
} __pbist_fsra1_bits;

/* PBIST ROM Mask Register (ROM) */
typedef struct {
  __REG32 ROM                   : 2;
  __REG32                       :30;
} __pbist_rom_bits;

/* PBIST ROM Algorithm Mask Register (ALGO) */
typedef struct {
  __REG32 ALGO0                 : 8;
  __REG32 ALGO1                 : 8;
  __REG32 ALGO2                 : 8;
  __REG32 ALGO3                 : 8;
} __pbist_algo_bits;

/* PBIST RAM Info Mask Lower Register (RINFOL) */
typedef struct {
  __REG32 RINFOL0               : 8;
  __REG32 RINFOL1               : 8;
  __REG32 RINFOL2               : 8;
  __REG32 RINFOL3               : 8;
} __pbist_rinfol_bits;

/* PBIST RAM Info Mask Upper Register (RINFOU) */
typedef struct {
  __REG32 RINFOU0               : 8;
  __REG32 RINFOU1               : 8;
  __REG32 RINFOU2               : 8;
  __REG32 RINFOU3               : 8;
} __pbist_rinfou_bits;

/* STC global control register0 (STCGCR0) */
typedef struct {
  __REG32 RS_CNT                : 1;
  __REG32                       :15;
  __REG32 INTCOUNT              :16;
} __stcgcr0_bits;

/* STC Global Control Register1 (STCGCR1) */
typedef struct {
  __REG32 STC_ENA               : 4;
  __REG32                       :28;
} __stcgcr1_bits;

/* STC Current Interval Count Register (STCCICR) */
typedef struct {
  __REG32 N                     :16;
  __REG32                       :16;
} __stccicr_bits;

/* SelfTest Global Status Register (STCGSTAT) */
typedef struct {
  __REG32 TEST_DONE             : 1;
  __REG32 TEST_FAIL             : 1;
  __REG32                       :30;
} __stcgstat_bits;

/* SelfTest Fail Status Register (STCFSTAT) */
typedef struct {
  __REG32 CPU1_FAIL             : 1;
  __REG32 CPU2_FAIL             : 1;
  __REG32 TO_ERR                : 1;
  __REG32                       :29;
} __stcfstat_bits;

/* Signature Compare Self Check Register (STCSCSCR) */
typedef struct {
  __REG32 SELF_CHECK_KEY        : 4;
  __REG32 FAULT_INS             : 1;
  __REG32                       :27;
} __stcscscr_bits;

/* TCRAM Wrapper Control Register (RAMCTRL) */
typedef struct {
  __REG32 ECC_DETECT_EN         : 4;
  __REG32                       : 4;
  __REG32 ECC_WR_EN             : 1;
  __REG32                       : 7;
  __REG32 ADDR_PARITY_DISABLE   : 4;
  __REG32                       : 4;
  __REG32 ADDR_PARITY_OVERRIDE  : 4;
  __REG32                       : 2;
  __REG32 EMU_TRACE_DIS         : 1;
  __REG32                       : 1;
} __ramctrl_bits;

/* TCRAM Wrapper Single-Bit Error Correction Threshold Register (RAMTHRESHOLD) */
typedef struct {
  __REG32 THRESHOLD             :16;
  __REG32                       :16;
} __ramthreshold_bits;

/* TCRAM Wrapper Single-Bit Error Occurrences Counter Register (RAMOCCUR) */
typedef struct {
  __REG32 SEO                   :16;
  __REG32                       :16;
} __ramoccur_bits;

/* TCRAM Wrapper Interrupt Control Register (RAMINTCTRL) */
typedef struct {
  __REG32 SERREN                : 1;
  __REG32                       :31;
} __ramintctrl_bits;

/* TCRAM Wrapper Error Status Register (RAMERRSTATUS) */
typedef struct {
  __REG32 SERR                  : 1;
  __REG32                       : 1;
  __REG32 ADDRDECFAIL           : 1;
  __REG32                       : 1;
  __REG32 ADDRCOMPLOGICFAIL     : 1;
  __REG32 DERR                  : 1;
  __REG32                       : 2;
  __REG32 RADDRPARFAIL          : 1;
  __REG32 WADDRPARFAIL          : 1;
  __REG32                       :22;
} __ramerrstatus_bits;

/* TCRAM Wrapper Single-Bit Error Address Register (RAMSERRADDR) */
typedef struct {
  __REG32 SEA                   :18;
  __REG32                       :14;
} __ramserraddr_bits;

/* TCRAM Wrapper Uncorrectable Error Address Register (RAMUERRADDR) */
typedef struct {
  __REG32 UEA                   :23;
  __REG32                       : 9;
} __ramuerraddr_bits;

/* TCRAM Wrapper Test Mode Control Register (RAMTEST) */
typedef struct {
  __REG32 TEST_ENABLE           : 4;
  __REG32                       : 2;
  __REG32 TEST_MODE             : 2;
  __REG32 TRIGGER               : 1;
  __REG32                       :23;
} __ramtest_bits;

/* TCRAM Wrapper Test Mode Vector Register (RAMADDRDECVECT) */
typedef struct {
  __REG32 RAM_CHIP_SELECT       :16;
  __REG32                       :10;
  __REG32 ECCSELECT             : 1;
  __REG32                       : 5;
} __ramaddrdecvect_bits;

/* TCRAM Wrapper Parity Error Address Register (RAMPERRADDR) */
typedef struct {
  __REG32 APEA                  :23;
  __REG32                       : 9;
} __ramperraddr_bits;

/* TCRAM Wrapper Auto-Memory Initialization Enable Register (INIT_DOMAIN) */
typedef struct {
  __REG32 AUTO_MEM_INIT_ENABLE  : 8;
  __REG32                       :24;
} __init_domain_bits;

/* Option Control Register (FRDCNTL) */
typedef struct {
  __REG32 ENPIPE              : 1;
  __REG32                     : 3;
  __REG32 ASWSTEN             : 1;
  __REG32                     : 3;
  __REG32 RWAIT               : 4;
  __REG32                     :20;
} __frdcntl_bits;

/* Error Detection Control Register 1 (FEDACCTRL1) */
typedef struct {
  __REG32 EDACEN              : 4;
  __REG32                     : 4;
  __REG32 EPEN                : 1;
  __REG32 EZFEN               : 1;
  __REG32                     : 6;
  __REG32 EDACMODE            : 4;
  __REG32                     : 4;
  __REG32 SUSP_IGNR           : 1;
  __REG32                     : 7;
} __fedacctrl1_bits;

/* Error Correction Control Register 2 (FEDACCTRL2) */
typedef struct {
  __REG32 SEC_THRESHOLD       :16;
  __REG32                     :16;
} __fedacctrl2_bits;

/* Error Correction Counter Register (FCOR_ERR_CNT) */
typedef struct {
  __REG32 FERRCNT             :16;
  __REG32                     :16;
} __fcor_err_cnt_bits;

/* Flash Correctable Error Address Register (FCOR_ERR_ADD) */
typedef struct {
  __REG32 B_OFF               : 3;
  __REG32 COR_ERR_ADD         :29;
} __fcor_err_add_bits;

/* Flash Correctable Error Position Register (FCOR_ERR_POS) */
typedef struct {
  __REG32 ERR_POS             : 8;
  __REG32 TYPE                : 1;
  __REG32 BUS2                : 1;
  __REG32                     :22;
} __fcor_err_pos_bits;

/* Flash Error Detection and Correction Status Register (FEDACSTATUS) */
typedef struct {
  __REG32 ERR_PRF_FLG         : 1;
  __REG32 ERR_ZERO_FLG        : 1;
  __REG32 ERR_ONE_FLG         : 1;
  __REG32 D_CORR_ERR          : 1;
  __REG32                     : 4;
  __REG32 B1_UNC_ERR          : 1;
  __REG32                     : 1;
  __REG32 ADD_PAR_ERR         : 1;
  __REG32 ADD_TAG_ERR         : 1;
  __REG32 D_UNC_ERR           : 1;
  __REG32                     : 3;
  __REG32 B2_COR_ERR          : 1;
  __REG32 B2_UNC_ERR          : 1;
  __REG32 ECC_B2_MAL_ERR      : 1;
  __REG32 COMB2_MAL_G         : 1;
  __REG32                     : 4;
  __REG32 FSM_DONE            : 1;
  __REG32                     : 7;
} __fedacstatus_bits;

/* Flash Un-Correctable Error Address Register (FUNC_ERR_ADD) */
typedef struct {
  __REG32 B_OFF               : 3;
  __REG32 UNC_ERR_ADD         :29;
} __func_err_add_bits;

/* Flash Error Detection and Correction Sector Disable Register (FEDACSDIS) */
typedef struct {
  __REG32 SectorID0           : 4;
  __REG32                     : 1;
  __REG32 BankID0             : 3;
  __REG32 SectorID0_inverse   : 4;
  __REG32                     : 1;
  __REG32 BankID0_inverse     : 3;
  __REG32 SectorID1           : 4;
  __REG32                     : 1;
  __REG32 BankID1             : 3;
  __REG32 SectorID1_inverse   : 4;
  __REG32                     : 1;
  __REG32 BankID1_inverse     : 3;
} __fedacsdis_bits;

/* Bank Protection Register (FBPROT) */
typedef struct {
  __REG32 PROTL1DIS           : 1;
  __REG32                     :31;
} __fbprot_bits;

/* Bank Sector Enable Register (FBSE) */
typedef struct {
  __REG32 BSE0                : 1;
  __REG32 BSE1                : 1;
  __REG32 BSE2                : 1;
  __REG32 BSE3                : 1;
  __REG32 BSE4                : 1;
  __REG32 BSE5                : 1;
  __REG32 BSE6                : 1;
  __REG32 BSE7                : 1;
  __REG32 BSE8                : 1;
  __REG32 BSE9                : 1;
  __REG32 BSE10               : 1;
  __REG32 BSE11               : 1;
  __REG32 BSE12               : 1;
  __REG32 BSE13               : 1;
  __REG32 BSE14               : 1;
  __REG32 BSE15               : 1;
  __REG32                     :16;
} __fbse_bits;

/* Flash Bank Busy Register (FBBUSY) */
typedef struct {
  __REG32 BUSY0               : 1;
  __REG32 BUSY1               : 1;
  __REG32 BUSY2               : 1;
  __REG32 BUSY3               : 1;
  __REG32 BUSY4               : 1;
  __REG32 BUSY5               : 1;
  __REG32 BUSY6               : 1;
  __REG32 BUSY7               : 1;
  __REG32                     :24;
} __fbbusy_bits;

/* Bank Access Control Register (FBAC) */
typedef struct {
  __REG32 VREADST             : 8;
  __REG32 BAGP                : 8;
  __REG32 OTPPROTDIS0         : 1;
  __REG32 OTPPROTDIS1         : 1;
  __REG32 OTPPROTDIS2         : 1;
  __REG32 OTPPROTDIS3         : 1;
  __REG32 OTPPROTDIS4         : 1;
  __REG32 OTPPROTDIS5         : 1;
  __REG32 OTPPROTDIS6         : 1;
  __REG32 OTPPROTDIS7         : 1;
  __REG32                     : 8;
} __fbac_bits;

/* Bank Fallback Power Register (FBFALLBACK) */
typedef struct {
  __REG32 BANKPWR0            : 2;
  __REG32 BANKPWR1            : 2;
  __REG32                     :10;
  __REG32 BANKPWR7            : 2;
  __REG32                     :16;
} __fbfallback_bits;

/* Bank/Pump Ready Register (FBPRDY) */
typedef struct {
  __REG32 BANKRDY0            : 1;
  __REG32 BANKRDY1            : 1;
  __REG32 BANKRDY2            : 1;
  __REG32 BANKRDY3            : 1;
  __REG32 BANKRDY4            : 1;
  __REG32 BANKRDY5            : 1;
  __REG32 BANKRDY6            : 1;
  __REG32 BANKRDY7            : 1;
  __REG32                     : 7;
  __REG32 PUMPRDY             : 1;
  __REG32 BANKBUSY0           : 1;
  __REG32 BANKBUSY1           : 1;
  __REG32 BANKBUSY2           : 1;
  __REG32 BANKBUSY3           : 1;
  __REG32 BANKBUSY4           : 1;
  __REG32 BANKBUSY5           : 1;
  __REG32 BANKBUSY6           : 1;
  __REG32 BANKBUSY7           : 1;
  __REG32                     : 8;
} __fbprdy_bits;

/* Pump Access Control Register 1 (FPAC1) */
typedef struct {
  __REG32 PUMPPWR             : 1;
  __REG32                     :15;
  __REG32 PSLEEP              :11;
  __REG32                     : 5;
} __fpac1_bits;

/* Pump Access Control Register 2 (FPAC2) */
typedef struct {
  __REG32 PAGP                :16;
  __REG32                     :16;
} __fpac2_bits;

/* Module Access Control Register (FMAC) */
typedef struct {
  __REG32 BANK                : 3;
  __REG32                     :29;
} __fmac_bits;

/* Flash Module Status Register (FMSTAT) */
typedef struct {
  __REG32 SLOCK               : 1;
  __REG32 PSUSP               : 1;
  __REG32 ESUSP               : 1;
  __REG32 VOLTSTAT            : 1;
  __REG32 CSTAT               : 1;
  __REG32 INVDAT              : 1;
  __REG32 PGM                 : 1;
  __REG32 ERS                 : 1;
  __REG32 BUSY                : 1;
  __REG32                     : 1;
  __REG32 EV                  : 1;
  __REG32                     : 1;
  __REG32 PGV                 : 1;
  __REG32                     : 1;
  __REG32 ILA                 : 1;
  __REG32                     :17;
} __fmstat_bits;

/* EEPROM Emulation ECC Register (FEMU_ECC) */
typedef struct {
  __REG32 EMU_ECC             : 8;
  __REG32                     :24;
} __femu_ecc_bits;

/* Diagnostic Control Register (FDIAGCTRL) */
typedef struct {
  __REG32 DIAGMODE            : 3;
  __REG32                     : 5;
  __REG32 DIAG_BUF_SEL        : 2;
  __REG32                     : 2;
  __REG32 DIAG_ECC_SEL        : 3;
  __REG32                     : 1;
  __REG32 DIAG_EN_KEY         : 4;
  __REG32                     : 4;
  __REG32 DIAG_TRIG           : 1;
  __REG32                     : 7;
} __fdiagctrl_bits;

/* Uncorrected Raw ECC Register (FRAW_ECC) */
typedef struct {
  __REG32 RAW_ECC             : 8;
  __REG32 PIPE_BUF            : 1;
  __REG32                     :23;
} __fraw_ecc_bits;

/* Parity Override Register (FPAR_OVR) */
typedef struct {
  __REG32 DAT_INV_PAR         : 8;
  __REG32 ADD_INV_PAR         : 1;
  __REG32 PAR_OVR_KEY         : 3;
  __REG32 BUS_PAR_DIS         : 4;
  __REG32 BNK_INV_PAR         : 1;
  __REG32                     :15;
} __fpar_ovr_bits;

/* Flash Error Detection and Correction Sector Disable Register (FEDACSDIS2) */
typedef struct {
  __REG32 SectorID2           : 4;
  __REG32                     : 1;
  __REG32 BankID2             : 3;
  __REG32 SectorID2_inverse   : 4;
  __REG32                     : 1;
  __REG32 BankID2_inverse     : 3;
  __REG32 SectorID3           : 4;
  __REG32                     : 1;
  __REG32 BankID3             : 3;
  __REG32 SectorID3_inverse   : 4;
  __REG32                     : 1;
  __REG32 BankID3_inverse     : 3;
} __fedacsdis2_bits;

/* FSM Register Write Enable (FSM_WR_ENA) */
typedef struct {
  __REG32 WR_ENA              : 3;
  __REG32                     :29;
} __fsm_wr_ena_bits;

/* FSM Sector Register (FSM_SECTOR) */
typedef struct {
  __REG32                     :16;
  __REG32 SECT_ERASED0        : 1;
  __REG32 SECT_ERASED1        : 1;
  __REG32 SECT_ERASED2        : 1;
  __REG32 SECT_ERASED3        : 1;
  __REG32 SECT_ERASED4        : 1;
  __REG32 SECT_ERASED5        : 1;
  __REG32 SECT_ERASED6        : 1;
  __REG32 SECT_ERASED7        : 1;
  __REG32 SECT_ERASED8        : 1;
  __REG32 SECT_ERASED9        : 1;
  __REG32 SECT_ERASED10       : 1;
  __REG32 SECT_ERASED11       : 1;
  __REG32 SECT_ERASED12       : 1;
  __REG32 SECT_ERASED13       : 1;
  __REG32 SECT_ERASED14       : 1;
  __REG32 SECT_ERASED15       : 1;
} __fsm_sector_bits;

/* EEPROM Emulation configuration Register (EEPROM_CONFIG) */
typedef struct {
  __REG32 AUTOSTART_GRACE     : 8;
  __REG32 AUTOSUSP_EN         : 1;
  __REG32                     : 7;
  __REG32 EWAIT               : 4;
  __REG32                     :12;
} __eeprom_config_bits;

/* EEPROM Emulation Error Detection and Correction Control Register 1 (EE_CTRL1) */
typedef struct {
  __REG32 EE_EDACEN           : 4;
  __REG32 EE_ALL0_OK          : 1;
  __REG32 EE_ALL1_OK          : 1;
  __REG32                     : 2;
  __REG32 EE_EPEN             : 1;
  __REG32 EE_EZFEN            : 1;
  __REG32 EE_EOFEN            : 1;
  __REG32                     : 5;
  __REG32 EE_EDACMODE         : 4;
  __REG32                     :12;
} __ee_ctrl1_bits;

/* EEPROM Emulation Error Correction and Correction Control Register 2 (EE_CTRL2) */
typedef struct {
  __REG32 EE_SEC_THRESHOLD    :16;
  __REG32                     :16;
} __ee_ctrl2_bits;

/* EEPROM Emulation Correctable Error Count Register (EE_COR_ERR_CNT) */
typedef struct {
  __REG32 EE_ERRCNT           :16;
  __REG32                     :16;
} __ee_cor_err_cnt_bits;

/* EEPROM Emulation Correctable Error Position Register (EE_COR_ERR_POS) */
typedef struct {
  __REG32 EE_ERR_POS          : 8;
  __REG32 TYPE                : 1;
  __REG32                     :23;
} __ee_cor_err_pos_bits;

/* EEPROM Emulation Error Status Register (EE_STATUS) */
typedef struct {
  __REG32 EE_ERR_PRF_FLG      : 1;
  __REG32 EE_ERR_ZERO_FLG     : 1;
  __REG32 EE_ERR_ONE_FLG      : 1;
  __REG32 EE_D_COR_ERR        : 1;
  __REG32 EE_CME              : 1;
  __REG32                     : 1;
  __REG32 EE_CMG              : 1;
  __REG32                     : 1;
  __REG32 EE_UNC_ERR          : 1;
  __REG32                     : 3;
  __REG32 EE_D_UNC_ERR        : 1;
  __REG32                     :19;
} __ee_status_bits;

/* Flash Bank Configuration Register (FCFG_BANK) */
typedef struct {
  __REG32                     : 4;
  __REG32 MAIN_BANK_WIDTH     :12;
  __REG32                     : 4;
  __REG32 EE_BANK_WIDTH       :12;
} __fcfg_bank_bits;

/*EMIF Asynchronous Wait Cycle Configuration Register (AWCC) */
typedef struct {
  __REG32 MAX_EXT_WAIT        : 8;
  __REG32                     : 8;
  __REG32 CS2_WAIT            : 2;
  __REG32 CS3_WAIT            : 2;
  __REG32 CS4_WAIT            : 2;
  __REG32 CS5_WAIT            : 2;
  __REG32                     : 4;
  __REG32 WP0                 : 1;
  __REG32 WP1                 : 1;
  __REG32                     : 2;
} __emif_awcc_bits;

/*EMIF SDRAM Configuration Register (SDCR)*/
typedef union {
  /*EMIF_SDCR*/
  struct {
    __REG32 PAGESIZE            : 3;
    __REG32                     : 1;
    __REG32 IBANK               : 3;
    __REG32                     : 1;
    __REG32 BIT11_9LOCK         : 1;
    __REG32 CL                  : 3;
    __REG32                     : 2;
    __REG32 NM                  : 1;
    __REG32                     :14;
    __REG32 PDWR                : 1;
    __REG32 PD                  : 1;
    __REG32 SR                  : 1;
  };
  struct {
    union {
      /*EMIF_SDCR0*/
      struct {
        __REG8  PAGESIZE            : 3;
        __REG8                      : 1;
        __REG8  IBANK               : 3;
        __REG8                      : 1;
      } byte0_bits;
      __REG8  byte0;
    };
    union {
      /*EMIF_SDCR1*/
      struct {
        __REG8  BIT11_9LOCK         : 1;
        __REG8  CL                  : 3;
        __REG8                      : 2;
        __REG8  NM                  : 1;
        __REG8                      : 1;
      } byte1_bits;
      __REG8  byte1;
    };

    __REG8  byte2;

    union {
      /*EMIF_SDCR3*/
      struct {
        __REG8                      : 5;
        __REG8   PDWR               : 1;
        __REG8   PD                 : 1;
        __REG8   SR                 : 1;
      } byte3_bits;
      __REG8  byte3;
    };
  };
} __emif_sdcr_bits;

/*EMIF SDRAM Refresh Control Register (SDRCR)*/
typedef struct {
  __REG32 RR                  :13;
  __REG32                     :19;
} __emif_sdrcr_bits;

/*EMIF Asynchronous n Configuration Registers (CE2CFG-CE5CFG)*/
typedef struct {
  __REG32 ASIZE               : 2;
  __REG32 TA                  : 2;
  __REG32 R_HOLD              : 3;
  __REG32 R_STROBE            : 6;
  __REG32 R_SETUP             : 4;
  __REG32 W_HOLD              : 3;
  __REG32 W_STROBE            : 6;
  __REG32 W_SETUP             : 4;
  __REG32 EW                  : 1;
  __REG32 SS                  : 1;
} __emif_cexcfg_bits;

/*EMIF SDRAM Timing Register (SDTIMR)*/
typedef struct {
  __REG32                     : 4;
  __REG32 T_RRD               : 3;
  __REG32                     : 1;
  __REG32 T_RC                : 4;
  __REG32 T_RAS               : 4;
  __REG32 T_WR                : 3;
  __REG32                     : 1;
  __REG32 T_RCD               : 3;
  __REG32                     : 1;
  __REG32 T_RP                : 3;
  __REG32 T_RFC               : 5;
} __emif_sdtimr_bits;

/*EMIF SDRAM Self Refresh Exit Timing Register (SDSRETR)*/
typedef struct {
  __REG32 T_XS                : 5;
  __REG32                     :27;
} __emif_sdsretr_bits;

/*EMIF Interrupt Raw Register (INTRAW)*/
typedef struct {
  __REG32 AT                  : 1;
  __REG32 LT                  : 1;
  __REG32 WR                  : 1;
  __REG32                     :29;
} __emif_intraw_bits;

/*EMIF Interrupt Masked Register (INTMSK)*/
typedef struct {
  __REG32 AT_MASKED           : 1;
  __REG32 LT_MASKED           : 1;
  __REG32 WR_MASKED           : 1;
  __REG32                     :29;
} __emif_intmsk_bits;

/*EMIF Interrupt Mask Set Register (INTMSKSET)*/
typedef struct {
  __REG32 AT_MASK_SET         : 1;
  __REG32 LT_MASK_SET         : 1;
  __REG32 WR_MASK_SET         : 1;
  __REG32                     :29;
} __emif_intmskset_bits;

/*EMIF Interrupt Mask Clear Register (INTMSKCLR)*/
typedef struct {
  __REG32 AT_MASK_CLR         : 1;
  __REG32 LT_MASK_CLR         : 1;
  __REG32 WR_MASK_CLR         : 1;
  __REG32                     :29;
} __emif_intmskclr_bits;

/*EMIF Page Mode Control Register (PMCR)*/
typedef struct {
  __REG32 CS2_PG_MD_EN        : 1;
  __REG32 CS2_PG_SIZE         : 1;
  __REG32 CS2_PG_DEL          : 6;
  __REG32 CS3_PG_MD_EN        : 1;
  __REG32 CS3_PG_SIZE         : 1;
  __REG32 CS3_PG_DEL          : 6;
  __REG32 CS4_PG_MD_EN        : 1;
  __REG32 CS4_PG_SIZE         : 1;
  __REG32 CS4_PG_DEL          : 6;
  __REG32 CS5_PG_MD_EN        : 1;
  __REG32 CS5_PG_SIZE         : 1;
  __REG32 CS5_PG_DEL          : 6;
} __emif_pmcr_bits;

/* POM Global Control Register (POMGLBCTRL) */
typedef struct {
  __REG32 ON_OFF              : 4;
  __REG32                     : 4;
  __REG32 ETO                 : 4;
  __REG32                     :11;
  __REG32 OTADDR              : 9;
} __pomglbctrl_bits;

/* POM Revision ID (POMREV) */
typedef struct {
  __REG32 MINOR               : 6;
  __REG32 CUSTOM              : 2;
  __REG32 MAJOR               : 3;
  __REG32 RTL                 : 5;
  __REG32 FUNC                :12;
  __REG32                     : 2;
  __REG32 SCHEME              : 2;
} __pomrev_bits;

/* POM Clock Gate Control Register (POMCLKCTRL) */
typedef struct {
  __REG32 CLK_GATE_OFF        : 1;
  __REG32                     :31;
} __pomclkctrl_bits;

/* POM Status Register (POMFLG) */
typedef struct {
  __REG32 TO                  : 1;
  __REG32                     :31;
} __pomflg_bits;

/* POM Program Region Start Address Register x (POMPROGSTARTx) */
typedef struct {
  __REG32 STARTADDRESS        :23;
  __REG32                     : 9;
} __pomprgstartx_bits;

/* POM Overlay Region Start Address Register x (POMOVLSTARTx) */
typedef struct {
  __REG32 STARTADDRESS        :23;
  __REG32                     : 9;
} __pomovlstartx_bits;

/* POM Region Size Register x (POMREGSIZEx) */
typedef struct {
  __REG32 SIZE                : 4;
  __REG32                     :28;
} __pomregsizex_bits;

/* POM Claim Set Register (POMCLAIMSET) */
typedef struct {
  __REG32 SET0                : 1;
  __REG32 SET1                : 1;
  __REG32                     :30;
} __pomclaimset_bits;

/* POM Claim Clear Register (POMCLAIMCLR) */
typedef struct {
  __REG32 CLR0                : 1;
  __REG32 CLR2                : 1;
  __REG32                     :30;
} __pomclaimclr_bits;

/* POM Device Type Register (POMDEVTYPE) */
typedef struct {
  __REG32 MajorType           : 4;
  __REG32 SubType             : 4;
  __REG32                     :24;
} __pomdevtype_bits;

/* POM Peripheral ID 4 Register (POMPERIPHERALID4) */
typedef struct {
  __REG32 JEP106_CC           : 4;
  __REG32 _4K_Count           : 4;
  __REG32                     :24;
} __pomperipheralid4_bits;

/* POM Peripheral ID 0 Register (POMPERIPHERALID0) */
typedef struct {
  __REG32 PartNumber          : 8;
  __REG32                     :24;
} __pomperipheralid0_bits;

/* POM Peripheral ID 1 Register (POMPERIPHERALID1) */
typedef struct {
  __REG32 PartNumber          : 4;
  __REG32 JEP106_ID           : 4;
  __REG32                     :24;
} __pomperipheralid1_bits;

/* POM Peripheral ID 2 Register (POMPERIPHERALID2) */
typedef struct {
  __REG32 JEP106_ID           : 3;
  __REG32 JEDEC               : 1;
  __REG32 Revision            : 4;
  __REG32                     :24;
} __pomperipheralid2_bits;

/* POM Component ID 0 Register (POMCOMPONENTID0) */
typedef struct {
  __REG32 Preamble            : 8;
  __REG32                     :24;
} __pomcomponentid0_bits;

/* POM Component ID 1 Register (POMCOMPONENTID1) */
typedef struct {
  __REG32 Preamble            : 4;
  __REG32 ComponentClass      : 4;
  __REG32                     :24;
} __pomcomponentid1_bits;

/* GIO Global Control Register (GIOGCR0) */
typedef struct {
  __REG32 RESET               : 1;
  __REG32                     :31;
} __giogcr0_bits;

/* GIO Interrupt Detect Register (GIOINTDET) */
typedef struct {
  __REG32 GIOINTDET0_0        : 1;
  __REG32 GIOINTDET0_1        : 1;
  __REG32 GIOINTDET0_2        : 1;
  __REG32 GIOINTDET0_3        : 1;
  __REG32 GIOINTDET0_4        : 1;
  __REG32 GIOINTDET0_5        : 1;
  __REG32 GIOINTDET0_6        : 1;
  __REG32 GIOINTDET0_7        : 1;
  __REG32 GIOINTDET1_0        : 1;
  __REG32 GIOINTDET1_1        : 1;
  __REG32 GIOINTDET1_2        : 1;
  __REG32 GIOINTDET1_3        : 1;
  __REG32 GIOINTDET1_4        : 1;
  __REG32 GIOINTDET1_5        : 1;
  __REG32 GIOINTDET1_6        : 1;
  __REG32 GIOINTDET1_7        : 1;
  __REG32 GIOINTDET2_0        : 1;
  __REG32 GIOINTDET2_1        : 1;
  __REG32 GIOINTDET2_2        : 1;
  __REG32 GIOINTDET2_3        : 1;
  __REG32 GIOINTDET2_4        : 1;
  __REG32 GIOINTDET2_5        : 1;
  __REG32 GIOINTDET2_6        : 1;
  __REG32 GIOINTDET2_7        : 1;
  __REG32 GIOINTDET3_0        : 1;
  __REG32 GIOINTDET3_1        : 1;
  __REG32 GIOINTDET3_2        : 1;
  __REG32 GIOINTDET3_3        : 1;
  __REG32 GIOINTDET3_4        : 1;
  __REG32 GIOINTDET3_5        : 1;
  __REG32 GIOINTDET3_6        : 1;
  __REG32 GIOINTDET3_7        : 1;
} __giointdet_bits;

/* GIO Interrupt Polarity Register (GIOPOL) */
typedef struct {
  __REG32 GIOPOL0_0           : 1;
  __REG32 GIOPOL0_1           : 1;
  __REG32 GIOPOL0_2           : 1;
  __REG32 GIOPOL0_3           : 1;
  __REG32 GIOPOL0_4           : 1;
  __REG32 GIOPOL0_5           : 1;
  __REG32 GIOPOL0_6           : 1;
  __REG32 GIOPOL0_7           : 1;
  __REG32 GIOPOL1_0           : 1;
  __REG32 GIOPOL1_1           : 1;
  __REG32 GIOPOL1_2           : 1;
  __REG32 GIOPOL1_3           : 1;
  __REG32 GIOPOL1_4           : 1;
  __REG32 GIOPOL1_5           : 1;
  __REG32 GIOPOL1_6           : 1;
  __REG32 GIOPOL1_7           : 1;
  __REG32 GIOPOL2_0           : 1;
  __REG32 GIOPOL2_1           : 1;
  __REG32 GIOPOL2_2           : 1;
  __REG32 GIOPOL2_3           : 1;
  __REG32 GIOPOL2_4           : 1;
  __REG32 GIOPOL2_5           : 1;
  __REG32 GIOPOL2_6           : 1;
  __REG32 GIOPOL2_7           : 1;
  __REG32 GIOPOL3_0           : 1;
  __REG32 GIOPOL3_1           : 1;
  __REG32 GIOPOL3_2           : 1;
  __REG32 GIOPOL3_3           : 1;
  __REG32 GIOPOL3_4           : 1;
  __REG32 GIOPOL3_5           : 1;
  __REG32 GIOPOL3_6           : 1;
  __REG32 GIOPOL3_7           : 1;
} __giopol_bits;

/* GIO Interrupt Enable Register (GIOENASET) */
typedef struct {
  __REG32 GIOENASET0_0        : 1;
  __REG32 GIOENASET0_1        : 1;
  __REG32 GIOENASET0_2        : 1;
  __REG32 GIOENASET0_3        : 1;
  __REG32 GIOENASET0_4        : 1;
  __REG32 GIOENASET0_5        : 1;
  __REG32 GIOENASET0_6        : 1;
  __REG32 GIOENASET0_7        : 1;
  __REG32 GIOENASET1_0        : 1;
  __REG32 GIOENASET1_1        : 1;
  __REG32 GIOENASET1_2        : 1;
  __REG32 GIOENASET1_3        : 1;
  __REG32 GIOENASET1_4        : 1;
  __REG32 GIOENASET1_5        : 1;
  __REG32 GIOENASET1_6        : 1;
  __REG32 GIOENASET1_7        : 1;
  __REG32 GIOENASET2_0        : 1;
  __REG32 GIOENASET2_1        : 1;
  __REG32 GIOENASET2_2        : 1;
  __REG32 GIOENASET2_3        : 1;
  __REG32 GIOENASET2_4        : 1;
  __REG32 GIOENASET2_5        : 1;
  __REG32 GIOENASET2_6        : 1;
  __REG32 GIOENASET2_7        : 1;
  __REG32 GIOENASET3_0        : 1;
  __REG32 GIOENASET3_1        : 1;
  __REG32 GIOENASET3_2        : 1;
  __REG32 GIOENASET3_3        : 1;
  __REG32 GIOENASET3_4        : 1;
  __REG32 GIOENASET3_5        : 1;
  __REG32 GIOENASET3_6        : 1;
  __REG32 GIOENASET3_7        : 1;
} __gioenaset_bits;

/* GIO Interrupt Enable Register (GIOENACLR) */
typedef struct {
  __REG32 GIOENACLR0_0        : 1;
  __REG32 GIOENACLR0_1        : 1;
  __REG32 GIOENACLR0_2        : 1;
  __REG32 GIOENACLR0_3        : 1;
  __REG32 GIOENACLR0_4        : 1;
  __REG32 GIOENACLR0_5        : 1;
  __REG32 GIOENACLR0_6        : 1;
  __REG32 GIOENACLR0_7        : 1;
  __REG32 GIOENACLR1_0        : 1;
  __REG32 GIOENACLR1_1        : 1;
  __REG32 GIOENACLR1_2        : 1;
  __REG32 GIOENACLR1_3        : 1;
  __REG32 GIOENACLR1_4        : 1;
  __REG32 GIOENACLR1_5        : 1;
  __REG32 GIOENACLR1_6        : 1;
  __REG32 GIOENACLR1_7        : 1;
  __REG32 GIOENACLR2_0        : 1;
  __REG32 GIOENACLR2_1        : 1;
  __REG32 GIOENACLR2_2        : 1;
  __REG32 GIOENACLR2_3        : 1;
  __REG32 GIOENACLR2_4        : 1;
  __REG32 GIOENACLR2_5        : 1;
  __REG32 GIOENACLR2_6        : 1;
  __REG32 GIOENACLR2_7        : 1;
  __REG32 GIOENACLR3_0        : 1;
  __REG32 GIOENACLR3_1        : 1;
  __REG32 GIOENACLR3_2        : 1;
  __REG32 GIOENACLR3_3        : 1;
  __REG32 GIOENACLR3_4        : 1;
  __REG32 GIOENACLR3_5        : 1;
  __REG32 GIOENACLR3_6        : 1;
  __REG32 GIOENACLR3_7        : 1;
} __gioenaclr_bits;

/* GIO Interrupt Priority Register (GIOLVSLSET) */
typedef struct {
  __REG32 GIOLVLSET0_0        : 1;
  __REG32 GIOLVLSET0_1        : 1;
  __REG32 GIOLVLSET0_2        : 1;
  __REG32 GIOLVLSET0_3        : 1;
  __REG32 GIOLVLSET0_4        : 1;
  __REG32 GIOLVLSET0_5        : 1;
  __REG32 GIOLVLSET0_6        : 1;
  __REG32 GIOLVLSET0_7        : 1;
  __REG32 GIOLVLSET1_0        : 1;
  __REG32 GIOLVLSET1_1        : 1;
  __REG32 GIOLVLSET1_2        : 1;
  __REG32 GIOLVLSET1_3        : 1;
  __REG32 GIOLVLSET1_4        : 1;
  __REG32 GIOLVLSET1_5        : 1;
  __REG32 GIOLVLSET1_6        : 1;
  __REG32 GIOLVLSET1_7        : 1;
  __REG32 GIOLVLSET2_0        : 1;
  __REG32 GIOLVLSET2_1        : 1;
  __REG32 GIOLVLSET2_2        : 1;
  __REG32 GIOLVLSET2_3        : 1;
  __REG32 GIOLVLSET2_4        : 1;
  __REG32 GIOLVLSET2_5        : 1;
  __REG32 GIOLVLSET2_6        : 1;
  __REG32 GIOLVLSET2_7        : 1;
  __REG32 GIOLVLSET3_0        : 1;
  __REG32 GIOLVLSET3_1        : 1;
  __REG32 GIOLVLSET3_2        : 1;
  __REG32 GIOLVLSET3_3        : 1;
  __REG32 GIOLVLSET3_4        : 1;
  __REG32 GIOLVLSET3_5        : 1;
  __REG32 GIOLVLSET3_6        : 1;
  __REG32 GIOLVLSET3_7        : 1;
} __giolvlset_bits;

/* GIO Interrupt Priority Register (GIOLVLCLR) */
typedef struct {
  __REG32 GIOLVLCLR0_0        : 1;
  __REG32 GIOLVLCLR0_1        : 1;
  __REG32 GIOLVLCLR0_2        : 1;
  __REG32 GIOLVLCLR0_3        : 1;
  __REG32 GIOLVLCLR0_4        : 1;
  __REG32 GIOLVLCLR0_5        : 1;
  __REG32 GIOLVLCLR0_6        : 1;
  __REG32 GIOLVLCLR0_7        : 1;
  __REG32 GIOLVLCLR1_0        : 1;
  __REG32 GIOLVLCLR1_1        : 1;
  __REG32 GIOLVLCLR1_2        : 1;
  __REG32 GIOLVLCLR1_3        : 1;
  __REG32 GIOLVLCLR1_4        : 1;
  __REG32 GIOLVLCLR1_5        : 1;
  __REG32 GIOLVLCLR1_6        : 1;
  __REG32 GIOLVLCLR1_7        : 1;
  __REG32 GIOLVLCLR2_0        : 1;
  __REG32 GIOLVLCLR2_1        : 1;
  __REG32 GIOLVLCLR2_2        : 1;
  __REG32 GIOLVLCLR2_3        : 1;
  __REG32 GIOLVLCLR2_4        : 1;
  __REG32 GIOLVLCLR2_5        : 1;
  __REG32 GIOLVLCLR2_6        : 1;
  __REG32 GIOLVLCLR2_7        : 1;
  __REG32 GIOLVLCLR3_0        : 1;
  __REG32 GIOLVLCLR3_1        : 1;
  __REG32 GIOLVLCLR3_2        : 1;
  __REG32 GIOLVLCLR3_3        : 1;
  __REG32 GIOLVLCLR3_4        : 1;
  __REG32 GIOLVLCLR3_5        : 1;
  __REG32 GIOLVLCLR3_6        : 1;
  __REG32 GIOLVLCLR3_7        : 1;
} __giolvlclr_bits;

/* GIO Interrupt Flag Register (GIOFLG) */
typedef struct {
  __REG32 GIOFLG0_0           : 1;
  __REG32 GIOFLG0_1           : 1;
  __REG32 GIOFLG0_2           : 1;
  __REG32 GIOFLG0_3           : 1;
  __REG32 GIOFLG0_4           : 1;
  __REG32 GIOFLG0_5           : 1;
  __REG32 GIOFLG0_6           : 1;
  __REG32 GIOFLG0_7           : 1;
  __REG32 GIOFLG1_0           : 1;
  __REG32 GIOFLG1_1           : 1;
  __REG32 GIOFLG1_2           : 1;
  __REG32 GIOFLG1_3           : 1;
  __REG32 GIOFLG1_4           : 1;
  __REG32 GIOFLG1_5           : 1;
  __REG32 GIOFLG1_6           : 1;
  __REG32 GIOFLG1_7           : 1;
  __REG32 GIOFLG2_0           : 1;
  __REG32 GIOFLG2_1           : 1;
  __REG32 GIOFLG2_2           : 1;
  __REG32 GIOFLG2_3           : 1;
  __REG32 GIOFLG2_4           : 1;
  __REG32 GIOFLG2_5           : 1;
  __REG32 GIOFLG2_6           : 1;
  __REG32 GIOFLG2_7           : 1;
  __REG32 GIOFLG3_0           : 1;
  __REG32 GIOFLG3_1           : 1;
  __REG32 GIOFLG3_2           : 1;
  __REG32 GIOFLG3_3           : 1;
  __REG32 GIOFLG3_4           : 1;
  __REG32 GIOFLG3_5           : 1;
  __REG32 GIOFLG3_6           : 1;
  __REG32 GIOFLG3_7           : 1;
} __gioflg_bits;

/* GIO Offset A Register (GIOOFF1) */
typedef struct {
  __REG32 GIOOFF1             : 6;
  __REG32                     :26;
} __giooff1_bits;

/* GIO Offset B Register (GIOOFF2) */
typedef struct {
  __REG32 GIOOFF2             : 6;
  __REG32                     :26;
} __giooff2_bits;

/* GIO Emulation A Register (GIOEMUA) */
typedef struct {
  __REG32 GIOEMU1             : 6;
  __REG32                     :26;
} __gioemu1_bits;

/* GIO Emulation B Register (GIOEMUB) */
typedef struct {
  __REG32 GIOEMU2             : 6;
  __REG32                     :26;
} __gioemu2_bits;

/* GIO Data Direction Registers [A-B][7:0] (GIODIR[A-B][7:0]) */
typedef struct {
  __REG32 GIODIR0             : 1;
  __REG32 GIODIR1             : 1;
  __REG32 GIODIR2             : 1;
  __REG32 GIODIR3             : 1;
  __REG32 GIODIR4             : 1;
  __REG32 GIODIR5             : 1;
  __REG32 GIODIR6             : 1;
  __REG32 GIODIR7             : 1;
  __REG32                     :24;
} __giodir_bits;

/* GIO Data Input Registers [A-B][7:0] (GIODIN[A-B][7:0]) */
typedef struct {
  __REG32 GIODIN0             : 1;
  __REG32 GIODIN1             : 1;
  __REG32 GIODIN2             : 1;
  __REG32 GIODIN3             : 1;
  __REG32 GIODIN4             : 1;
  __REG32 GIODIN5             : 1;
  __REG32 GIODIN6             : 1;
  __REG32 GIODIN7             : 1;
  __REG32                     :24;
} __giodin_bits;

/* GIO Data Output Registers [A-B][7:0] (GIODOUT[A-B][7:0]) */
typedef struct {
  __REG32 GIODOUT0            : 1;
  __REG32 GIODOUT1            : 1;
  __REG32 GIODOUT2            : 1;
  __REG32 GIODOUT3            : 1;
  __REG32 GIODOUT4            : 1;
  __REG32 GIODOUT5            : 1;
  __REG32 GIODOUT6            : 1;
  __REG32 GIODOUT7            : 1;
  __REG32                     :24;
} __giodout_bits;

/* GIO Data Set Registers [A-B][7:0] (GIODSET[A-B][7:0]) */
typedef struct {
  __REG32 GIODSET0            : 1;
  __REG32 GIODSET1            : 1;
  __REG32 GIODSET2            : 1;
  __REG32 GIODSET3            : 1;
  __REG32 GIODSET4            : 1;
  __REG32 GIODSET5            : 1;
  __REG32 GIODSET6            : 1;
  __REG32 GIODSET7            : 1;
  __REG32                     :24;
} __gioset_bits;

/* GIO Data Clear Registers [A-B][7:0] (GIODCLR[A-B][7:0]) */
typedef struct {
  __REG32 GIODCLR0            : 1;
  __REG32 GIODCLR1            : 1;
  __REG32 GIODCLR2            : 1;
  __REG32 GIODCLR3            : 1;
  __REG32 GIODCLR4            : 1;
  __REG32 GIODCLR5            : 1;
  __REG32 GIODCLR6            : 1;
  __REG32 GIODCLR7            : 1;
  __REG32                     :24;
} __gioclr_bits;

/* GIO Open Drain Register [A-B][7:0] (GIOPDR[A-B][7:0]) */
typedef struct {
  __REG32 GIOPDR0             : 1;
  __REG32 GIOPDR1             : 1;
  __REG32 GIOPDR2             : 1;
  __REG32 GIOPDR3             : 1;
  __REG32 GIOPDR4             : 1;
  __REG32 GIOPDR5             : 1;
  __REG32 GIOPDR6             : 1;
  __REG32 GIOPDR7             : 1;
  __REG32                     :24;
} __giopdr_bits;

/* GIO Pull Disable Registers [A-B][7:0] (GIOPULDIS[A-B][7:0]) */
typedef struct {
  __REG32 GIOPULDIS0          : 1;
  __REG32 GIOPULDIS1          : 1;
  __REG32 GIOPULDIS2          : 1;
  __REG32 GIOPULDIS3          : 1;
  __REG32 GIOPULDIS4          : 1;
  __REG32 GIOPULDIS5          : 1;
  __REG32 GIOPULDIS6          : 1;
  __REG32 GIOPULDIS7          : 1;
  __REG32                     :24;
} __giopuldis_bits;

/* GIO Pull Select Register [A-B][7:0] (GIOPSL[A-B][7:0]) */
typedef struct {
  __REG32 GIOPSL0             : 1;
  __REG32 GIOPSL1             : 1;
  __REG32 GIOPSL2             : 1;
  __REG32 GIOPSL3             : 1;
  __REG32 GIOPSL4             : 1;
  __REG32 GIOPSL5             : 1;
  __REG32 GIOPSL6             : 1;
  __REG32 GIOPSL7             : 1;
  __REG32                     :24;
} __giopsl_bits;

/* SCI Global Control Register 0 (SCIGCR0) */
typedef struct {
  __REG32 RESET               : 1;
  __REG32                     :31;
} __scigcr0_bits;

/* SCI/LIN Global Control Register 1 (SCIGCR1) */
typedef struct {
  __REG32 COMM_MODE           : 1;
  __REG32 TIMING_MODE         : 1;
  __REG32 PARITY_ENA          : 1;
  __REG32 PARITY              : 1;
  __REG32 STOP                : 1;
  __REG32 CLOCK               : 1;
  __REG32 LIN_MODE            : 1;
  __REG32 SW_nRST             : 1;
  __REG32 SLEEP               : 1;
  __REG32 ADAPT               : 1;
  __REG32 MBUF_MODE           : 1;
  __REG32 CTYPE               : 1;
  __REG32 HGEN_CTRL           : 1;
  __REG32 STOP_EXT_FRAME      : 1;
  __REG32                     : 2;
  __REG32 LOOP_BACK           : 1;
  __REG32 CONT                : 1;
  __REG32                     : 6;
  __REG32 RXENA               : 1;
  __REG32 TXENA               : 1;
  __REG32                     : 6;
} __scilingcr1_bits;

/* SCI Global Control Register 1 (SCIGCR1) */
typedef struct {
  __REG32 COMM_MODE           : 1;
  __REG32 TIMING_MODE         : 1;
  __REG32 PARITY_ENA          : 1;
  __REG32 PARITY              : 1;
  __REG32 STOP                : 1;
  __REG32 CLOCK               : 1;
  __REG32                     : 1;
  __REG32 SW_nRST             : 1;
  __REG32 SLEEP               : 1;
  __REG32 POWERDOWN           : 1;
  __REG32                     : 6;
  __REG32 LOOP_BACK           : 1;
  __REG32 CONT                : 1;
  __REG32                     : 6;
  __REG32 RXENA               : 1;
  __REG32 TXENA               : 1;
  __REG32                     : 6;
} __scigcr1_bits;

/* SCI Global Control Register 2 (SCIGCR2) */
typedef struct {
  __REG32 POWER_DOWN          : 1;
  __REG32                     : 7;
  __REG32 GEN_WU              : 1;
  __REG32                     : 7;
  __REG32 SC                  : 1;
  __REG32 CC                  : 1;
  __REG32                     :14;
} __scigcr2_bits;

/* SCI/LIN Set Interrupt Register (SCISETINT) */
typedef struct {
  __REG32 SET_BRKDT_INT       : 1;
  __REG32 SET_WAKEUP_INT      : 1;
  __REG32                     : 2;
  __REG32 SET_TIMEOUT_INT     : 1;
  __REG32                     : 1;
  __REG32 SET_TOAWUS_INT      : 1;
  __REG32 SET_TOA3WUS_INT     : 1;
  __REG32 SET_TX_INT          : 1;
  __REG32 SET_RX_INT          : 1;
  __REG32                     : 3;
  __REG32 SET_ID_INT          : 1;
  __REG32                     : 2;
  __REG32 SET_TX_DMA          : 1;
  __REG32 SET_RX_DMA          : 1;
  __REG32 SET_RX_DMA_ALL      : 1;
  __REG32                     : 5;
  __REG32 SET_PE_INT          : 1;
  __REG32 SET_OE_INT          : 1;
  __REG32 SET_FE_INT          : 1;
  __REG32 SET_NRE_INT         : 1;
  __REG32 SET_ISFE_INT        : 1;
  __REG32 SET_CE_INT          : 1;
  __REG32 SET_PBE_INT         : 1;
  __REG32 SET_BE_INT          : 1;
} __scilinsetint_bits;

/* SCI Set Interrupt Register (SCISETINT) */
typedef struct {
  __REG32 SET_BRKDT_INT       : 1;
  __REG32 SET_WAKEUP_INT      : 1;
  __REG32                     : 6;
  __REG32 SET_TX_INT          : 1;
  __REG32 SET_RX_INT          : 1;
  __REG32                     : 6;
  __REG32 SET_TX_DMA          : 1;
  __REG32 SET_RX_DMA          : 1;
  __REG32 SET_RX_DMA_ALL      : 1;
  __REG32                     : 5;
  __REG32 SET_PE_INT          : 1;
  __REG32 SET_OE_INT          : 1;
  __REG32 SET_FE_INT          : 1;
  __REG32                     : 5;
} __scisetint_bits;

/* SCI/LIN Clear Interrupt Register (SCICLEARINT) */
typedef struct {
  __REG32 CLR_BRKDT_INT       : 1;
  __REG32 CLR_WAKEUP_INT      : 1;
  __REG32                     : 2;
  __REG32 CLR_TIMEOUT_INT     : 1;
  __REG32                     : 1;
  __REG32 CLR_TOAWUS_INT      : 1;
  __REG32 CLR_TOA3WUS_INT     : 1;
  __REG32 CLR_TX_INT          : 1;
  __REG32 CLR_RX_INT          : 1;
  __REG32                     : 3;
  __REG32 CLR_ID_INT          : 1;
  __REG32                     : 2;
  __REG32 CLR_TX_DMA          : 1;
  __REG32 CLR_RX_DMA          : 1;
  __REG32 CLR_RX_DMA_ALL      : 1;
  __REG32                     : 5;
  __REG32 CLR_PE_INT          : 1;
  __REG32 CLR_OE_INT          : 1;
  __REG32 CLR_FE_INT          : 1;
  __REG32 CLR_NRE_INT         : 1;
  __REG32 CLR_ISFE_INT        : 1;
  __REG32 CLR_CE_INT          : 1;
  __REG32 CLR_PBE_INT         : 1;
  __REG32 CLR_BE_INT          : 1;
} __scilinclearint_bits;

/* SCI Clear Interrupt Register (SCICLEARINT) */
typedef struct {
  __REG32 CLR_BRKDT_INT       : 1;
  __REG32 CLR_WAKEUP_INT      : 1;
  __REG32                     : 6;
  __REG32 CLR_TX_INT          : 1;
  __REG32 CLR_RX_INT          : 1;
  __REG32                     : 6;
  __REG32 CLR_TX_DMA          : 1;
  __REG32 CLR_RX_DMA          : 1;
  __REG32 CLR_RX_DMA_ALL      : 1;
  __REG32                     : 5;
  __REG32 CLR_PE_INT          : 1;
  __REG32 CLR_OE_INT          : 1;
  __REG32 CLR_FE_INT          : 1;
  __REG32                     : 5;
} __sciclearint_bits;

/* SCI/LIN Set Interrupt Level Register (SCISETINTLVL) */
typedef struct {
  __REG32 SET_BRKDT_INT_LVL   : 1;
  __REG32 SET_WAKEUP_INT_LVL  : 1;
  __REG32                     : 2;
  __REG32 SET_TIMEOUT_INT_LVL : 1;
  __REG32                     : 1;
  __REG32 SET_TOAWUS_INT_LVL  : 1;
  __REG32 SET_TOA3WUS_INT_LVL : 1;
  __REG32 SET_TX_INT_LVL      : 1;
  __REG32 SET_RX_INT_LVL      : 1;
  __REG32                     : 3;
  __REG32 SET_ID_INT_LVL      : 1;
  __REG32                     : 4;
  __REG32 SET_RX_DMA_ALL_LVL  : 1;
  __REG32                     : 5;
  __REG32 SET_PE_INT_LVL      : 1;
  __REG32 SET_OE_INT_LVL      : 1;
  __REG32 SET_FE_INT_LVL      : 1;
  __REG32 SET_NRE_INT_LVL     : 1;
  __REG32 SET_ISFE_INT_LVL    : 1;
  __REG32 SET_CE_INT_LVL      : 1;
  __REG32 SET_PBE_INT_LVL     : 1;
  __REG32 SET_BE_INT_LVL      : 1;
} __scilinsetintlvl_bits;

/* SCI Set Interrupt Level Register (SCISETINTLVL) */
typedef struct {
  __REG32 SET_BRKDT_INT_LVL   : 1;
  __REG32 SET_WAKEUP_INT_LVL  : 1;
  __REG32                     : 6;
  __REG32 SET_TX_INT_LVL      : 1;
  __REG32 SET_RX_INT_LVL      : 1;
  __REG32                     : 8;
  __REG32 SET_RX_DMA_ALL_LVL  : 1;
  __REG32                     : 5;
  __REG32 SET_PE_INT_LVL      : 1;
  __REG32 SET_OE_INT_LVL      : 1;
  __REG32 SET_FE_INT_LVL      : 1;
  __REG32                     : 5;
} __scisetintlvl_bits;

/* SCI/LIN Clear Interrupt Level Register (SCICLEARINTLVL) */
typedef struct {
  __REG32 CLR_BRKDT_INT_LVL   : 1;
  __REG32 CLR_WAKEUP_INT_LVL  : 1;
  __REG32                     : 2;
  __REG32 CLR_TIMEOUT_INT_LVL : 1;
  __REG32                     : 1;
  __REG32 CLR_TOAWUS_INT_LVL  : 1;
  __REG32 CLR_TOA3WUS_INT_LVL : 1;
  __REG32 CLR_TX_INT_LVL      : 1;
  __REG32 CLR_RX_INT_LVL      : 1;
  __REG32                     : 3;
  __REG32 CLR_ID_INT_LVL      : 1;
  __REG32                     : 4;
  __REG32 CLR_RX_DMA_ALL_LVL  : 1;
  __REG32                     : 5;
  __REG32 CLR_PE_INT_LVL      : 1;
  __REG32 CLR_OE_INT_LVL      : 1;
  __REG32 CLR_FE_INT_LVL      : 1;
  __REG32 CLR_NRE_INT_LVL     : 1;
  __REG32 CLR_ISFE_INT_LVL    : 1;
  __REG32 CLR_CE_INT_LVL      : 1;
  __REG32 CLR_PBE_INT_LVL     : 1;
  __REG32 CLR_BE_INT_LVL      : 1;
} __scilinclearintlvl_bits;

/* SCI Clear Interrupt Level Register (SCICLEARINTLVL) */
typedef struct {
  __REG32 CLR_BRKDT_INT_LVL   : 1;
  __REG32 CLR_WAKEUP_INT_LVL  : 1;
  __REG32                     : 6;
  __REG32 CLR_TX_INT_LVL      : 1;
  __REG32 CLR_RX_INT_LVL      : 1;
  __REG32                     : 8;
  __REG32 CLR_RX_DMA_ALL_LVL  : 1;
  __REG32                     : 5;
  __REG32 CLR_PE_INT_LVL      : 1;
  __REG32 CLR_OE_INT_LVL      : 1;
  __REG32 CLR_FE_INT_LVL      : 1;
  __REG32                     : 5;
} __sciclearintlvl_bits;

/* SCI/LIN Flags Register (SCIFLR) */
typedef struct {
  __REG32 BRKDT               : 1;
  __REG32 WAKEUP              : 1;
  __REG32 IDLE                : 1;
  __REG32 BUSY                : 1;
  __REG32 TIMEOUT             : 1;
  __REG32                     : 1;
  __REG32 TOAWUS              : 1;
  __REG32 TOA3WUS             : 1;
  __REG32 TXRDY               : 1;
  __REG32 RXRDY               : 1;
  __REG32 TXWAKE              : 1;
  __REG32 TX_EMPTY            : 1;
  __REG32 RXWAKE              : 1;
  __REG32 ID_TX_FLAG          : 1;
  __REG32 ID_RX_FLAG          : 1;
  __REG32                     : 9;
  __REG32 PE                  : 1;
  __REG32 OE                  : 1;
  __REG32 FE                  : 1;
  __REG32 NRE                 : 1;
  __REG32 ISFE                : 1;
  __REG32 CE                  : 1;
  __REG32 PBE                 : 1;
  __REG32 BE                  : 1;
} __scilinflr_bits;

/* SCI Flags Register (SCIFLR) */
typedef struct {
  __REG32 BRKDT               : 1;
  __REG32 WAKEUP              : 1;
  __REG32 IDLE                : 1;
  __REG32 BUSY                : 1;
  __REG32                     : 4;
  __REG32 TXRDY               : 1;
  __REG32 RXRDY               : 1;
  __REG32 TXWAKE              : 1;
  __REG32 TX_EMPTY            : 1;
  __REG32 RXWAKE              : 1;
  __REG32                     :11;
  __REG32 PE                  : 1;
  __REG32 OE                  : 1;
  __REG32 FE                  : 1;
  __REG32                     : 5;
} __sciflr_bits;

/* SCI/LIN Interrupt Vector Offset 0 (SCIINTVECT0) */
typedef struct {
  __REG32 INTVECT0            : 5;
  __REG32                     :27;
} __scilinintvect0_bits;

/* SCI Interrupt Vector Offset 0 (SCIINTVECT0) */
typedef struct {
  __REG32 INTVECT0            : 4;
  __REG32                     :28;
} __sciintvect0_bits;

/* SCI/LIN Interrupt Vector Offset 1 (SCIINTVECT1) */
typedef struct {
  __REG32 INTVECT1            : 5;
  __REG32                     :27;
} __scilinintvect1_bits;

/* SCI Interrupt Vector Offset 1 (SCIINTVECT1) */
typedef struct {
  __REG32 INTVECT1            : 4;
  __REG32                     :28;
} __sciintvect1_bits;

/* SCI/LIN Format Control Register (SCIFORMAT) */
typedef struct {
  __REG32 CHAR                : 3;
  __REG32                     :13;
  __REG32 LENGTH              : 3;
  __REG32                     :13;
} __scilinformat_bits;

/* SCI Format Control Register (SCIFORMAT) */
typedef struct {
  __REG32 CHAR                : 3;
  __REG32                     :29;
} __sciformat_bits;

/* SCI/LIN Baud Rate Selection Register (SCIBRS) */
typedef struct {
  __REG32 PRESCALER_P         :24;
  __REG32 M                   : 4;
  __REG32 U                   : 3;
  __REG32                     : 1;
} __scilinbrs_bits;

/* SCI Baud Rate Selection Register (SCIBRS) */
typedef struct {
  __REG32 BAUD                :24;
  __REG32                     : 8;
} __scibrs_bits;

/* Receiver Emulation Data Buffer (SCIED) */
typedef struct {
  __REG32 ED                  : 8;
  __REG32                     :24;
} __scied_bits;

/* Receiver Data Buffer (SCIRD) */
typedef struct {
  __REG32 RD                  : 8;
  __REG32                     :24;
} __scird_bits;

/* Transmit Data Buffer Register (SCITD) */
typedef struct {
  __REG32 TD                  : 8;
  __REG32                     :24;
} __scitd_bits;

/* SCI Pin I/O Control Register 0 (SCIPIO0) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_FUNC             : 1;
  __REG32 TX_FUNC             : 1;
  __REG32                     :29;
} __scipio0_bits;

/* SCI Pin I/O Control Register 1 (SCIPIO1) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_DIR              : 1;
  __REG32 TX_DIR              : 1;
  __REG32                     :29;
} __scipio1_bits;

/* SCI Pin I/O Control Register 2 (SCIPIO2) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_IN               : 1;
  __REG32 TX_IN               : 1;
  __REG32                     :29;
} __scipio2_bits;

/* SCI Pin I/O Control Register 3 (SCIPIO3) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_OUT              : 1;
  __REG32 TX_OUT              : 1;
  __REG32                     :29;
} __scipio3_bits;

/* SCI Pin I/O Control Register 4 (SCIPIO4) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_SET              : 1;
  __REG32 TX_SET              : 1;
  __REG32                     :29;
} __scipio4_bits;

/* SCI Pin I/O Control Register 5 (SCIPIO5) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_CLR              : 1;
  __REG32 TX_CLR              : 1;
  __REG32                     :29;
} __scipio5_bits;

/* SCI Pin I/O Control Register 6 (SCIPIO6) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_PDR              : 1;
  __REG32 TX_PDR              : 1;
  __REG32                     :29;
} __scipio6_bits;

/* SCI Pin I/O Control Register 7 (SCIPIO7) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_PD               : 1;
  __REG32 TX_PD               : 1;
  __REG32                     :29;
} __scipio7_bits;

/* SCI Pin I/O Control Register 8 (SCIPIO8) */
typedef struct {
  __REG32                     : 1;
  __REG32 RX_PSL              : 1;
  __REG32 TX_PSL              : 1;
  __REG32                     :29;
} __scipio8_bits;

/* LIN Compare Register (LINCOMPARE) */
typedef struct {
  __REG32 SBREAK              : 3;
  __REG32                     : 5;
  __REG32 SDEL                : 2;
  __REG32                     :22;
} __lincompare_bits;

/* LIN Receive Buffer 0 Register (LINRD0) */
typedef struct {
  __REG32 RD3                 : 8;
  __REG32 RD2                 : 8;
  __REG32 RD1                 : 8;
  __REG32 RD0                 : 8;
} __linrd0_bits;

/* LIN Receive Buffer 1 Register (LINRD1) */
typedef struct {
  __REG32 RD7                 : 8;
  __REG32 RD6                 : 8;
  __REG32 RD5                 : 8;
  __REG32 RD4                 : 8;
} __linrd1_bits;

/* LIN Mask Register (LINMASK) */
typedef struct {
  __REG32 TX_ID_MASK          : 8;
  __REG32                     : 8;
  __REG32 RX_ID_MASK          : 8;
  __REG32                     : 8;
} __linmask_bits;

/* LIN Identification Register (LINID) */
typedef struct {
  __REG32 ID_BYTE             : 8;
  __REG32 ID_SlaveTask_BYTE   : 8;
  __REG32 RECEIVED_ID         : 8;
  __REG32                     : 8;
} __linid_bits;

/* LIN Transmit Buffer 0 Register (LINTD0) */
typedef struct {
  __REG32 TD3                 : 8;
  __REG32 TD2                 : 8;
  __REG32 TD1                 : 8;
  __REG32 TD0                 : 8;
} __lintd0_bits;

/* LIN Transmit Buffer 1 Register (LINTD1) */
typedef struct {
  __REG32 TD7                 : 8;
  __REG32 TD6                 : 8;
  __REG32 TD5                 : 8;
  __REG32 TD4                 : 8;
} __lintd1_bits;

/* Maximum Baud Rate Selection Register (MBRS) */
typedef struct {
  __REG32 MBR                 :13;
  __REG32                     :19;
} __linmbrs_bits;

/* Input/Output Error Enable Register (IODFTCTRL) */
typedef struct {
  __REG32 RXPENA              : 1;
  __REG32 LPBENA              : 1;
  __REG32                     : 6;
  __REG32 IODFTENA            : 4;
  __REG32                     : 4;
  __REG32 TX_SHIFT            : 3;
  __REG32 PIN_SAMPLE_MASK     : 2;
  __REG32                     : 3;
  __REG32 BRKD_TENA           : 1;
  __REG32 PEN                 : 1;
  __REG32 FEN                 : 1;
  __REG32                     : 1;
  __REG32 ISFE                : 1;
  __REG32 CEN                 : 1;
  __REG32 PBEN                : 1;
  __REG32 BEN                 : 1;
} __scilin_iodftctrl_bits;

/* Input/Output Error Enable Register (IODFTCTRL) */
typedef struct {
  __REG32 RXPENA              : 1;
  __REG32 LPBENA              : 1;
  __REG32                     : 6;
  __REG32 IODFTENA            : 4;
  __REG32                     : 4;
  __REG32 TX_SHIFT            : 3;
  __REG32 PIN_SAMPLE_MASK     : 2;
  __REG32                     : 3;
  __REG32 BRKD_TENA           : 1;
  __REG32 PEN                 : 1;
  __REG32 FEN                 : 1;
  __REG32                     : 5;
} __sci_iodftctrl_bits;

/* SPI Global Control Register 0 (SPIGCR0) */
typedef struct {
  __REG32 nRESET              : 1;
  __REG32                     :31;
} __spigcr0_bits;

/* SPI Global Control Register 1 (SPIGCR1) */
typedef struct {
  __REG32 MASTER              : 1;
  __REG32 CLKMOD              : 1;
  __REG32                     : 6;
  __REG32 POWERDOWN           : 1;
  __REG32                     : 7;
  __REG32 LOOPBACK            : 1;
  __REG32                     : 7;
  __REG32 SPIEN               : 1;
  __REG32                     : 7;
} __spigcr1_bits;

/* SPI Interrupt Register (SPIINT0) */
typedef struct {
  __REG32 DLENERRENA          : 1;
  __REG32 TIMEOUTENA          : 1;
  __REG32 PARERRENA           : 1;
  __REG32 DESYNCENA           : 1;
  __REG32 BITERRENA           : 1;
  __REG32                     : 1;
  __REG32 RXOVRNINTENA        : 1;
  __REG32                     : 1;
  __REG32 RXINTENA            : 1;
  __REG32 TXINTENA            : 1;
  __REG32                     : 6;
  __REG32 DMAREQEN            : 1;
  __REG32                     : 7;
  __REG32 ENABLEHIGHZ         : 1;
  __REG32                     : 7;
} __spiint0_bits;

/* SPI Interrupt Level Register (SPILVL) */
typedef struct {
  __REG32 DLENERRLVL          : 1;
  __REG32 TIMEOUTLVL          : 1;
  __REG32 PARERRLVL           : 1;
  __REG32 DESYNCLVL           : 1;
  __REG32 BITERRLVL           : 1;
  __REG32                     : 1;
  __REG32 RXOVRNINTLVL        : 1;
  __REG32                     : 1;
  __REG32 RXINTLVL            : 1;
  __REG32 TXINTLVL            : 1;
  __REG32                     :22;
} __spilvl_bits;

/* SPI Flag Register (MIBSPIFLG) */
typedef struct {
  __REG32 DLENERRFLG          : 1;
  __REG32 TIMEOUTFLG          : 1;
  __REG32 PARERRFLG           : 1;
  __REG32 DESYNCFLG           : 1;
  __REG32 BITERRFLG           : 1;
  __REG32                     : 1;
  __REG32 RXOVRNINTFLG        : 1;
  __REG32                     : 1;
  __REG32 RXINTFLG            : 1;
  __REG32 TXINTFLG            : 1;
  __REG32                     :14;
  __REG32 BUFINITACTIVE       : 1;
  __REG32                     : 7;
} __mibspiflg_bits;

/* SPI Flag Register (SPIFLG) */
typedef struct {
  __REG32 DLENERRFLG          : 1;
  __REG32 TIMEOUTFLG          : 1;
  __REG32 PARERRFLG           : 1;
  __REG32 DESYNCFLG           : 1;
  __REG32 BITERRFLG           : 1;
  __REG32                     : 1;
  __REG32 RXOVRNINTFLG        : 1;
  __REG32                     : 1;
  __REG32 RXINTFLG            : 1;
  __REG32 TXINTFLG            : 1;
  __REG32                     :22;
} __spiflg_bits;

/* SPIP Pin Control Register 0 (SPIPPC0) */
typedef struct {
  __REG32 SCSFUN0             : 1;
  __REG32 SCSFUN1             : 1;
  __REG32 SCSFUN2             : 1;
  __REG32 SCSFUN3             : 1;
  __REG32 SCSFUN4             : 1;
  __REG32 SCSFUN5             : 1;
  __REG32 SCSFUN6             : 1;
  __REG32 SCSFUN7             : 1;
  __REG32 ENAFUN              : 1;
  __REG32 CLKFUN              : 1;
  __REG32 SIMOFUN0            : 1;
  __REG32 SOMIFUN0            : 1;
  __REG32                     : 4;
  __REG32 _SIMOFUN0           : 1;
  __REG32 SIMOFUN1            : 1;
  __REG32 SIMOFUN2            : 1;
  __REG32 SIMOFUN3            : 1;
  __REG32 SIMOFUN4            : 1;
  __REG32 SIMOFUN5            : 1;
  __REG32 SIMOFUN6            : 1;
  __REG32 SIMOFUN7            : 1;
  __REG32 _SOMIFUN0           : 1;
  __REG32 SOMIFUN1            : 1;
  __REG32 SOMIFUN2            : 1;
  __REG32 SOMIFUN3            : 1;
  __REG32 SOMIFUN4            : 1;
  __REG32 SOMIFUN5            : 1;
  __REG32 SOMIFUN6            : 1;
  __REG32 SOMIFUN7            : 1;
} __spippc0_bits;

/* SPI Pin Control Register 0 (SPIPC0) */
typedef struct {
  __REG32 SCSFUN0             : 1;
  __REG32 SCSFUN1             : 1;
  __REG32 SCSFUN2             : 1;
  __REG32 SCSFUN3             : 1;
  __REG32 SCSFUN4             : 1;
  __REG32 SCSFUN5             : 1;
  __REG32 SCSFUN6             : 1;
  __REG32 SCSFUN7             : 1;
  __REG32 ENAFUN              : 1;
  __REG32 CLKFUN              : 1;
  __REG32 SIMOFUN0            : 1;
  __REG32 SOMIFUN0            : 1;
  __REG32                     : 4;
  __REG32 _SIMOFUN0           : 1;
  __REG32                     : 7;
  __REG32 _SOMIFUN0           : 1;
  __REG32                     : 7;
} __spipc0_bits;

/* SPIP Pin Control Register 1 (SPIPPC1) */
typedef struct {
  __REG32 SCSDIR0             : 1;
  __REG32 SCSDIR1             : 1;
  __REG32 SCSDIR2             : 1;
  __REG32 SCSDIR3             : 1;
  __REG32 SCSDIR4             : 1;
  __REG32 SCSDIR5             : 1;
  __REG32 SCSDIR6             : 1;
  __REG32 SCSDIR7             : 1;
  __REG32 ENADIR              : 1;
  __REG32 CLKDIR              : 1;
  __REG32 SIMODIR0            : 1;
  __REG32 SOMIDIR0            : 1;
  __REG32                     : 4;
  __REG32 _SIMODIR0           : 1;
  __REG32 SIMODIR1            : 1;
  __REG32 SIMODIR2            : 1;
  __REG32 SIMODIR3            : 1;
  __REG32 SIMODIR4            : 1;
  __REG32 SIMODIR5            : 1;
  __REG32 SIMODIR6            : 1;
  __REG32 SIMODIR7            : 1;
  __REG32 _SOMIDIR0           : 1;
  __REG32 SOMIDIR1            : 1;
  __REG32 SOMIDIR2            : 1;
  __REG32 SOMIDIR3            : 1;
  __REG32 SOMIDIR4            : 1;
  __REG32 SOMIDIR5            : 1;
  __REG32 SOMIDIR6            : 1;
  __REG32 SOMIDIR7            : 1;
} __spippc1_bits;

/* SPI Pin Control Register 1 (SPIPC1) */
typedef struct {
  __REG32 SCSDIR0             : 1;
  __REG32 SCSDIR1             : 1;
  __REG32 SCSDIR2             : 1;
  __REG32 SCSDIR3             : 1;
  __REG32 SCSDIR4             : 1;
  __REG32 SCSDIR5             : 1;
  __REG32 SCSDIR6             : 1;
  __REG32 SCSDIR7             : 1;
  __REG32 ENADIR              : 1;
  __REG32 CLKDIR              : 1;
  __REG32 SIMODIR0            : 1;
  __REG32 SOMIDIR0            : 1;
  __REG32                     : 4;
  __REG32 _SIMODIR0           : 1;
  __REG32                     : 7;
  __REG32 _SOMIDIR0           : 1;
  __REG32                     : 7;
} __spipc1_bits;

/* SPIP Pin Control Register 2 (SPIPPC2) */
typedef struct {
  __REG32 SCSDIN0              : 1;
  __REG32 SCSDIN1              : 1;
  __REG32 SCSDIN2              : 1;
  __REG32 SCSDIN3              : 1;
  __REG32 SCSDIN4              : 1;
  __REG32 SCSDIN5              : 1;
  __REG32 SCSDIN6              : 1;
  __REG32 SCSDIN7              : 1;
  __REG32 ENADIN               : 1;
  __REG32 CLKDIN               : 1;
  __REG32 SIMODIN0             : 1;
  __REG32 SOMIDIN0             : 1;
  __REG32                      : 4;
  __REG32 _SIMODIN0            : 1;
  __REG32 SIMODIN1             : 1;
  __REG32 SIMODIN2             : 1;
  __REG32 SIMODIN3             : 1;
  __REG32 SIMODIN4             : 1;
  __REG32 SIMODIN5             : 1;
  __REG32 SIMODIN6             : 1;
  __REG32 SIMODIN7             : 1;
  __REG32 _SOMIDIN0            : 1;
  __REG32 SOMIDIN1             : 1;
  __REG32 SOMIDIN2             : 1;
  __REG32 SOMIDIN3             : 1;
  __REG32 SOMIDIN4             : 1;
  __REG32 SOMIDIN5             : 1;
  __REG32 SOMIDIN6             : 1;
  __REG32 SOMIDIN7             : 1;
} __spippc2_bits;

/* SPI Pin Control Register 2 (SPIPC2) */
typedef struct {
  __REG32 SCSDIN0              : 1;
  __REG32 SCSDIN1              : 1;
  __REG32 SCSDIN2              : 1;
  __REG32 SCSDIN3              : 1;
  __REG32 SCSDIN4              : 1;
  __REG32 SCSDIN5              : 1;
  __REG32 SCSDIN6              : 1;
  __REG32 SCSDIN7              : 1;
  __REG32 ENADIN               : 1;
  __REG32 CLKDIN               : 1;
  __REG32 SIMODIN0             : 1;
  __REG32 SOMIDIN0             : 1;
  __REG32                      : 4;
  __REG32 _SIMODIN0            : 1;
  __REG32                      : 7;
  __REG32 _SOMIDIN0            : 1;
  __REG32                      : 7;
} __spipc2_bits;

/* SPIP Pin Control Register 3 (SPIPPC3) */
typedef struct {
  __REG32 SCSDOUT0             : 1;
  __REG32 SCSDOUT1             : 1;
  __REG32 SCSDOUT2             : 1;
  __REG32 SCSDOUT3             : 1;
  __REG32 SCSDOUT4             : 1;
  __REG32 SCSDOUT5             : 1;
  __REG32 SCSDOUT6             : 1;
  __REG32 SCSDOUT7             : 1;
  __REG32 ENADOUT              : 1;
  __REG32 CLKDOUT              : 1;
  __REG32 SIMODOUT0            : 1;
  __REG32 SOMIDOUT0            : 1;
  __REG32                      : 4;
  __REG32 _SIMODOUT0           : 1;
  __REG32 SIMODOUT1            : 1;
  __REG32 SIMODOUT2            : 1;
  __REG32 SIMODOUT3            : 1;
  __REG32 SIMODOUT4            : 1;
  __REG32 SIMODOUT5            : 1;
  __REG32 SIMODOUT6            : 1;
  __REG32 SIMODOUT7            : 1;
  __REG32 _SOMIDOUT0           : 1;
  __REG32 SOMIDOUT1            : 1;
  __REG32 SOMIDOUT2            : 1;
  __REG32 SOMIDOUT3            : 1;
  __REG32 SOMIDOUT4            : 1;
  __REG32 SOMIDOUT5            : 1;
  __REG32 SOMIDOUT6            : 1;
  __REG32 SOMIDOUT7            : 1;
} __spippc3_bits;

/* SPI Pin Control Register 3 (SPIPC3) */
typedef struct {
  __REG32 SCSDOUT0             : 1;
  __REG32 SCSDOUT1             : 1;
  __REG32 SCSDOUT2             : 1;
  __REG32 SCSDOUT3             : 1;
  __REG32 SCSDOUT4             : 1;
  __REG32 SCSDOUT5             : 1;
  __REG32 SCSDOUT6             : 1;
  __REG32 SCSDOUT7             : 1;
  __REG32 ENADOUT              : 1;
  __REG32 CLKDOUT              : 1;
  __REG32 SIMODOUT0            : 1;
  __REG32 SOMIDOUT0            : 1;
  __REG32                      : 4;
  __REG32 _SIMODOUT0           : 1;
  __REG32                      : 7;
  __REG32 _SOMIDOUT0           : 1;
  __REG32                      : 7;
} __spipc3_bits;

/* SPIP Pin Control Register 4 (SPIPPC4) */
typedef struct {
  __REG32 SCSSET0             : 1;
  __REG32 SCSSET1             : 1;
  __REG32 SCSSET2             : 1;
  __REG32 SCSSET3             : 1;
  __REG32 SCSSET4             : 1;
  __REG32 SCSSET5             : 1;
  __REG32 SCSSET6             : 1;
  __REG32 SCSSET7             : 1;
  __REG32 ENASET              : 1;
  __REG32 CLKSET              : 1;
  __REG32 SIMOSET0            : 1;
  __REG32 SOMISET0            : 1;
  __REG32                     : 4;
  __REG32 _SIMOSET0           : 1;
  __REG32 SIMOSET1            : 1;
  __REG32 SIMOSET2            : 1;
  __REG32 SIMOSET3            : 1;
  __REG32 SIMOSET4            : 1;
  __REG32 SIMOSET5            : 1;
  __REG32 SIMOSET6            : 1;
  __REG32 SIMOSET7            : 1;
  __REG32 _SOMISET0           : 1;
  __REG32 SOMISET1            : 1;
  __REG32 SOMISET2            : 1;
  __REG32 SOMISET3            : 1;
  __REG32 SOMISET4            : 1;
  __REG32 SOMISET5            : 1;
  __REG32 SOMISET6            : 1;
  __REG32 SOMISET7            : 1;
} __spippc4_bits;

/* SPI Pin Control Register 4 (SPIPC4) */
typedef struct {
  __REG32 SCSSET0             : 1;
  __REG32 SCSSET1             : 1;
  __REG32 SCSSET2             : 1;
  __REG32 SCSSET3             : 1;
  __REG32 SCSSET4             : 1;
  __REG32 SCSSET5             : 1;
  __REG32 SCSSET6             : 1;
  __REG32 SCSSET7             : 1;
  __REG32 ENASET              : 1;
  __REG32 CLKSET              : 1;
  __REG32 SIMOSET0            : 1;
  __REG32 SOMISET0            : 1;
  __REG32                     : 4;
  __REG32 _SIMOSET0           : 1;
  __REG32                     : 7;
  __REG32 _SOMISET0           : 1;
  __REG32                     : 7;
} __spipc4_bits;

/* SPIP Pin Control Register 5 (SPIPPC5) */
typedef struct {
  __REG32 SCSCLR0             : 1;
  __REG32 SCSCLR1             : 1;
  __REG32 SCSCLR2             : 1;
  __REG32 SCSCLR3             : 1;
  __REG32 SCSCLR4             : 1;
  __REG32 SCSCLR5             : 1;
  __REG32 SCSCLR6             : 1;
  __REG32 SCSCLR7             : 1;
  __REG32 ENACLR              : 1;
  __REG32 CLKCLR              : 1;
  __REG32 SIMOCLR0            : 1;
  __REG32 SOMICLR0            : 1;
  __REG32                     : 4;
  __REG32 _SIMOCLR0           : 1;
  __REG32 SIMOCLR1            : 1;
  __REG32 SIMOCLR2            : 1;
  __REG32 SIMOCLR3            : 1;
  __REG32 SIMOCLR4            : 1;
  __REG32 SIMOCLR5            : 1;
  __REG32 SIMOCLR6            : 1;
  __REG32 SIMOCLR7            : 1;
  __REG32 _SOMICLR0           : 1;
  __REG32 SOMICLR1            : 1;
  __REG32 SOMICLR2            : 1;
  __REG32 SOMICLR3            : 1;
  __REG32 SOMICLR4            : 1;
  __REG32 SOMICLR5            : 1;
  __REG32 SOMICLR6            : 1;
  __REG32 SOMICLR7            : 1;
} __spippc5_bits;

/* SPI Pin Control Register 5 (SPIPC5) */
typedef struct {
  __REG32 SCSCLR0             : 1;
  __REG32 SCSCLR1             : 1;
  __REG32 SCSCLR2             : 1;
  __REG32 SCSCLR3             : 1;
  __REG32 SCSCLR4             : 1;
  __REG32 SCSCLR5             : 1;
  __REG32 SCSCLR6             : 1;
  __REG32 SCSCLR7             : 1;
  __REG32 ENACLR              : 1;
  __REG32 CLKCLR              : 1;
  __REG32 SIMOCLR0            : 1;
  __REG32 SOMICLR0            : 1;
  __REG32                     : 4;
  __REG32 _SIMOCLR0           : 1;
  __REG32                     : 7;
  __REG32 _SOMICLR0           : 1;
  __REG32                     : 7;
} __spipc5_bits;

/* SPIP Pin Control Register 6 (SPIPPC6) */
typedef struct {
  __REG32 SCSPDR0             : 1;
  __REG32 SCSPDR1             : 1;
  __REG32 SCSPDR2             : 1;
  __REG32 SCSPDR3             : 1;
  __REG32 SCSPDR4             : 1;
  __REG32 SCSPDR5             : 1;
  __REG32 SCSPDR6             : 1;
  __REG32 SCSPDR7             : 1;
  __REG32 ENAPDR              : 1;
  __REG32 CLKPDR              : 1;
  __REG32 SIMOPDR0            : 1;
  __REG32 SOMIPDR0            : 1;
  __REG32                     : 4;
  __REG32 _SIMOPDR0           : 1;
  __REG32 SIMOPDR1            : 1;
  __REG32 SIMOPDR2            : 1;
  __REG32 SIMOPDR3            : 1;
  __REG32 SIMOPDR4            : 1;
  __REG32 SIMOPDR5            : 1;
  __REG32 SIMOPDR6            : 1;
  __REG32 SIMOPDR7            : 1;
  __REG32 _SOMIPDR0           : 1;
  __REG32 SOMIPDR1            : 1;
  __REG32 SOMIPDR2            : 1;
  __REG32 SOMIPDR3            : 1;
  __REG32 SOMIPDR4            : 1;
  __REG32 SOMIPDR5            : 1;
  __REG32 SOMIPDR6            : 1;
  __REG32 SOMIPDR7            : 1;
} __spippc6_bits;

/* SPI Pin Control Register 6 (SPIPC6) */
typedef struct {
  __REG32 SCSPDR0             : 1;
  __REG32 SCSPDR1             : 1;
  __REG32 SCSPDR2             : 1;
  __REG32 SCSPDR3             : 1;
  __REG32 SCSPDR4             : 1;
  __REG32 SCSPDR5             : 1;
  __REG32 SCSPDR6             : 1;
  __REG32 SCSPDR7             : 1;
  __REG32 ENAPDR              : 1;
  __REG32 CLKPDR              : 1;
  __REG32 SIMOPDR0            : 1;
  __REG32 SOMIPDR0            : 1;
  __REG32                     : 4;
  __REG32 _SIMOPDR0           : 1;
  __REG32                     : 7;
  __REG32 _SOMIPDR0           : 1;
  __REG32                     : 7;
} __spipc6_bits;

/* SPIP Pin Control Register 7 (SPIPPC7) */
typedef struct {
  __REG32 SCSPDIS0            : 1;
  __REG32 SCSPDIS1            : 1;
  __REG32 SCSPDIS2            : 1;
  __REG32 SCSPDIS3            : 1;
  __REG32 SCSPDIS4            : 1;
  __REG32 SCSPDIS5            : 1;
  __REG32 SCSPDIS6            : 1;
  __REG32 SCSPDIS7            : 1;
  __REG32 ENAPDIS             : 1;
  __REG32 CLKPDIS             : 1;
  __REG32 SIMOPDIS0           : 1;
  __REG32 SOMIPDIS0           : 1;
  __REG32                     : 4;
  __REG32 _SIMOPDIS0          : 1;
  __REG32 SIMOPDIS1           : 1;
  __REG32 SIMOPDIS2           : 1;
  __REG32 SIMOPDIS3           : 1;
  __REG32 SIMOPDIS4           : 1;
  __REG32 SIMOPDIS5           : 1;
  __REG32 SIMOPDIS6           : 1;
  __REG32 SIMOPDIS7           : 1;
  __REG32 _SOMIPDIS0          : 1;
  __REG32 SOMIPDIS1           : 1;
  __REG32 SOMIPDIS2           : 1;
  __REG32 SOMIPDIS3           : 1;
  __REG32 SOMIPDIS4           : 1;
  __REG32 SOMIPDIS5           : 1;
  __REG32 SOMIPDIS6           : 1;
  __REG32 SOMIPDIS7           : 1;
} __spippc7_bits;

/* SPI Pin Control Register 7 (SPIPC7) */
typedef struct {
  __REG32 SCSPDIS0            : 1;
  __REG32 SCSPDIS1            : 1;
  __REG32 SCSPDIS2            : 1;
  __REG32 SCSPDIS3            : 1;
  __REG32 SCSPDIS4            : 1;
  __REG32 SCSPDIS5            : 1;
  __REG32 SCSPDIS6            : 1;
  __REG32 SCSPDIS7            : 1;
  __REG32 ENAPDIS             : 1;
  __REG32 CLKPDIS             : 1;
  __REG32 SIMOPDIS0           : 1;
  __REG32 SOMIPDIS0           : 1;
  __REG32                     : 4;
  __REG32 _SIMOPDIS0          : 1;
  __REG32                     : 7;
  __REG32 _SOMIPDIS0          : 1;
  __REG32                     : 7;
} __spipc7_bits;

/* SPI Pin Control Register 8 (SPIPPC8) */
typedef struct {
  __REG32 SCSPSEL0            : 1;
  __REG32 SCSPSEL1            : 1;
  __REG32 SCSPSEL2            : 1;
  __REG32 SCSPSEL3            : 1;
  __REG32 SCSPSEL4            : 1;
  __REG32 SCSPSEL5            : 1;
  __REG32 SCSPSEL6            : 1;
  __REG32 SCSPSEL7            : 1;
  __REG32 ENAPSEL             : 1;
  __REG32 CLKPSEL             : 1;
  __REG32 SIMOPSEL0           : 1;
  __REG32 SOMIPSEL0           : 1;
  __REG32                     : 4;
  __REG32 _SIMOPSEL0          : 1;
  __REG32 SIMOPSEL1           : 1;
  __REG32 SIMOPSEL2           : 1;
  __REG32 SIMOPSEL3           : 1;
  __REG32 SIMOPSEL4           : 1;
  __REG32 SIMOPSEL5           : 1;
  __REG32 SIMOPSEL6           : 1;
  __REG32 SIMOPSEL7           : 1;
  __REG32 _SOMIPSEL0          : 1;
  __REG32 SOMIPSEL1           : 1;
  __REG32 SOMIPSEL2           : 1;
  __REG32 SOMIPSEL3           : 1;
  __REG32 SOMIPSEL4           : 1;
  __REG32 SOMIPSEL5           : 1;
  __REG32 SOMIPSEL6           : 1;
  __REG32 SOMIPSEL7           : 1;
} __spippc8_bits;

/* SPI Pin Control Register 8 (SPIPC8) */
typedef struct {
  __REG32 SCSPSEL0            : 1;
  __REG32 SCSPSEL1            : 1;
  __REG32 SCSPSEL2            : 1;
  __REG32 SCSPSEL3            : 1;
  __REG32 SCSPSEL4            : 1;
  __REG32 SCSPSEL5            : 1;
  __REG32 SCSPSEL6            : 1;
  __REG32 SCSPSEL7            : 1;
  __REG32 ENAPSEL             : 1;
  __REG32 CLKPSEL             : 1;
  __REG32 SIMOPSEL0           : 1;
  __REG32 SOMIPSEL0           : 1;
  __REG32                     : 4;
  __REG32 _SIMOPSEL0          : 1;
  __REG32                     : 7;
  __REG32 _SOMIPSEL0          : 1;
  __REG32                     : 7;
} __spipc8_bits;

/* SPI Transmit Data Register 0 (SPIDAT0) */
typedef struct {
  __REG32 TXDATA              :16;
  __REG32                     :16;
} __spidat0_bits;

/* SPI Transmit Data Register 1 (SPIDAT1) */
typedef struct {
  __REG32 TXDATA              :16;
  __REG32 CSNR                : 8;
  __REG32 DFSEL               : 2;
  __REG32 WDEL                : 1;
  __REG32                     : 1;
  __REG32 CSHOLD              : 1;
  __REG32                     : 3;
} __spidat1_bits;

/* SPI Receive Buffer Register (SPIBUF) */
typedef struct {
  __REG32 RXDATA              :16;
  __REG32 LCSNR               : 8;
  __REG32 DLENERR             : 1;
  __REG32 TIMEOUT             : 1;
  __REG32 PARITYERR           : 1;
  __REG32 DESYNC              : 1;
  __REG32 BITERR              : 1;
  __REG32 TXFULL              : 1;
  __REG32 RXOVR               : 1;
  __REG32 RXEMPTY             : 1;
} __spibuf_bits;

/* SPI Emulation Register (SPIEMU) */
typedef struct {
  __REG32 EMU_RXDATA          :16;
  __REG32                     :16;
} __spiemu_bits;

/* SPI Delay Register (SPIDELAY) */
typedef struct {
  __REG32 C2EDELAY            : 8;
  __REG32 T2EDELAY            : 8;
  __REG32 T2CDELAY            : 8;
  __REG32 C2TDELAY            : 8;
} __spidelay_bits;

/* SPI Default Chip Select Register (SPIDEFP) */
typedef struct {
  __REG32 CSDEF0              : 1;
  __REG32 CSDEF1              : 1;
  __REG32 CSDEF2              : 1;
  __REG32 CSDEF3              : 1;
  __REG32 CSDEF4              : 1;
  __REG32 CSDEF5              : 1;
  __REG32 CSDEF6              : 1;
  __REG32 CSDEF7              : 1;
  __REG32                     :24;
} __spidef_bits;

/* SPI Data Format Registers (SPIFMT[3:0]) */
typedef struct {
  __REG32 CHARLEN             : 5;
  __REG32                     : 3;
  __REG32 PRESCALE            : 8;
  __REG32 PHASE               : 1;
  __REG32 POLARITY            : 1;
  __REG32 DIS_CS_TIMERS       : 1;
  __REG32 HDUPLEX_ENA         : 1;
  __REG32 SHIFTDIR            : 1;
  __REG32 WAITENA             : 1;
  __REG32 PARITYENA           : 1;
  __REG32 PARPOL              : 1;
  __REG32 WDELAY              : 8;
} __spifmt_bits;

/* Interrupt Vector 0 (INTVECT0) */
typedef struct {
  __REG32 SUSPEND0            : 1;
  __REG32 INTVECT0            : 5;
  __REG32                     :26;
} __spiintvect0_bits;

/* Interrupt Vector 1 (INTVECT1) */
typedef struct {
  __REG32 SUSPEND1            : 1;
  __REG32 INTVECT1            : 5;
  __REG32                     :26;
} __spiintvect1_bits;

/* SPI Parallel/Modulo Mode Control Register (SPIPMCTRL)  */
typedef struct {
  __REG32 PMODE0              : 2;
  __REG32 MMODE0              : 3;
  __REG32 MODCLKPOL0          : 1;
  __REG32                     : 2;
  __REG32 PMODE1              : 2;
  __REG32 MMODE1              : 3;
  __REG32 MODCLKPOL1          : 1;
  __REG32                     : 2;
  __REG32 PMODE2              : 2;
  __REG32 MMODE2              : 3;
  __REG32 MODCLKPOL2          : 1;
  __REG32                     : 2;
  __REG32 PMODE3              : 2;
  __REG32 MMODE3              : 3;
  __REG32 MODCLKPOL3          : 1;
  __REG32                     : 2;
} __spipmctrl_bits;

/* SPI Multi-buffer Mode Enable Register (MIBSPIE)  */
typedef struct {
  __REG32 MSPIENA             : 1;
  __REG32                     :15;
  __REG32 RXRAMACCESS         : 1;
  __REG32                     :15;
} __spimibspie_bits;

/* TG Interrupt Enable Set Register (TGITENST) */
typedef struct {
  __REG32 SETINTENSUS0        : 1;
  __REG32 SETINTENSUS1        : 1;
  __REG32 SETINTENSUS2        : 1;
  __REG32 SETINTENSUS3        : 1;
  __REG32 SETINTENSUS4        : 1;
  __REG32 SETINTENSUS5        : 1;
  __REG32 SETINTENSUS6        : 1;
  __REG32 SETINTENSUS7        : 1;
  __REG32 SETINTENSUS8        : 1;
  __REG32 SETINTENSUS9        : 1;
  __REG32 SETINTENSUS10       : 1;
  __REG32 SETINTENSUS11       : 1;
  __REG32 SETINTENSUS12       : 1;
  __REG32 SETINTENSUS13       : 1;
  __REG32 SETINTENSUS14       : 1;
  __REG32 SETINTENSUS15       : 1;
  __REG32 SETINTENRDY0        : 1;
  __REG32 SETINTENRDY1        : 1;
  __REG32 SETINTENRDY2        : 1;
  __REG32 SETINTENRDY3        : 1;
  __REG32 SETINTENRDY4        : 1;
  __REG32 SETINTENRDY5        : 1;
  __REG32 SETINTENRDY6        : 1;
  __REG32 SETINTENRDY7        : 1;
  __REG32 SETINTENRDY8        : 1;
  __REG32 SETINTENRDY9        : 1;
  __REG32 SETINTENRDY10       : 1;
  __REG32 SETINTENRDY11       : 1;
  __REG32 SETINTENRDY12       : 1;
  __REG32 SETINTENRDY13       : 1;
  __REG32 SETINTENRDY14       : 1;
  __REG32 SETINTENRDY15       : 1;
} __spitgitenst_bits;

/* TG MibSPI TG Interrupt Enable Clear Register (TGITENCR) */
typedef struct {
  __REG32 CLRINTENSUS0        : 1;
  __REG32 CLRINTENSUS1        : 1;
  __REG32 CLRINTENSUS2        : 1;
  __REG32 CLRINTENSUS3        : 1;
  __REG32 CLRINTENSUS4        : 1;
  __REG32 CLRINTENSUS5        : 1;
  __REG32 CLRINTENSUS6        : 1;
  __REG32 CLRINTENSUS7        : 1;
  __REG32 CLRINTENSUS8        : 1;
  __REG32 CLRINTENSUS9        : 1;
  __REG32 CLRINTENSUS10       : 1;
  __REG32 CLRINTENSUS11       : 1;
  __REG32 CLRINTENSUS12       : 1;
  __REG32 CLRINTENSUS13       : 1;
  __REG32 CLRINTENSUS14       : 1;
  __REG32 CLRINTENSUS15       : 1;
  __REG32 CLRINTENRDY0        : 1;
  __REG32 CLRINTENRDY1        : 1;
  __REG32 CLRINTENRDY2        : 1;
  __REG32 CLRINTENRDY3        : 1;
  __REG32 CLRINTENRDY4        : 1;
  __REG32 CLRINTENRDY5        : 1;
  __REG32 CLRINTENRDY6        : 1;
  __REG32 CLRINTENRDY7        : 1;
  __REG32 CLRINTENRDY8        : 1;
  __REG32 CLRINTENRDY9        : 1;
  __REG32 CLRINTENRDY10       : 1;
  __REG32 CLRINTENRDY11       : 1;
  __REG32 CLRINTENRDY12       : 1;
  __REG32 CLRINTENRDY13       : 1;
  __REG32 CLRINTENRDY14       : 1;
  __REG32 CLRINTENRDY15       : 1;
} __spitgitencr_bits;

/* TG Transfer Group Interrupt Level Set Register (TGITLVST) */
typedef struct {
  __REG32 SETINTLVLSUS0       : 1;
  __REG32 SETINTLVLSUS1       : 1;
  __REG32 SETINTLVLSUS2       : 1;
  __REG32 SETINTLVLSUS3       : 1;
  __REG32 SETINTLVLSUS4       : 1;
  __REG32 SETINTLVLSUS5       : 1;
  __REG32 SETINTLVLSUS6       : 1;
  __REG32 SETINTLVLSUS7       : 1;
  __REG32 SETINTLVLSUS8       : 1;
  __REG32 SETINTLVLSUS9       : 1;
  __REG32 SETINTLVLSUS10      : 1;
  __REG32 SETINTLVLSUS11      : 1;
  __REG32 SETINTLVLSUS12      : 1;
  __REG32 SETINTLVLSUS13      : 1;
  __REG32 SETINTLVLSUS14      : 1;
  __REG32 SETINTLVLSUS15      : 1;
  __REG32 SETINTLVLRDY0       : 1;
  __REG32 SETINTLVLRDY1       : 1;
  __REG32 SETINTLVLRDY2       : 1;
  __REG32 SETINTLVLRDY3       : 1;
  __REG32 SETINTLVLRDY4       : 1;
  __REG32 SETINTLVLRDY5       : 1;
  __REG32 SETINTLVLRDY6       : 1;
  __REG32 SETINTLVLRDY7       : 1;
  __REG32 SETINTLVLRDY8       : 1;
  __REG32 SETINTLVLRDY9       : 1;
  __REG32 SETINTLVLRDY10      : 1;
  __REG32 SETINTLVLRDY11      : 1;
  __REG32 SETINTLVLRDY12      : 1;
  __REG32 SETINTLVLRDY13      : 1;
  __REG32 SETINTLVLRDY14      : 1;
  __REG32 SETINTLVLRDY15      : 1;
} __spitgitlvst_bits;

/* TG Transfer Group Interrupt Level Clear Register (TGITLVCR) */
typedef struct {
  __REG32 CLRINTLVLSUS0       : 1;
  __REG32 CLRINTLVLSUS1       : 1;
  __REG32 CLRINTLVLSUS2       : 1;
  __REG32 CLRINTLVLSUS3       : 1;
  __REG32 CLRINTLVLSUS4       : 1;
  __REG32 CLRINTLVLSUS5       : 1;
  __REG32 CLRINTLVLSUS6       : 1;
  __REG32 CLRINTLVLSUS7       : 1;
  __REG32 CLRINTLVLSUS8       : 1;
  __REG32 CLRINTLVLSUS9       : 1;
  __REG32 CLRINTLVLSUS10      : 1;
  __REG32 CLRINTLVLSUS11      : 1;
  __REG32 CLRINTLVLSUS12      : 1;
  __REG32 CLRINTLVLSUS13      : 1;
  __REG32 CLRINTLVLSUS14      : 1;
  __REG32 CLRINTLVLSUS15      : 1;
  __REG32 CLRINTLVLRDY0       : 1;
  __REG32 CLRINTLVLRDY1       : 1;
  __REG32 CLRINTLVLRDY2       : 1;
  __REG32 CLRINTLVLRDY3       : 1;
  __REG32 CLRINTLVLRDY4       : 1;
  __REG32 CLRINTLVLRDY5       : 1;
  __REG32 CLRINTLVLRDY6       : 1;
  __REG32 CLRINTLVLRDY7       : 1;
  __REG32 CLRINTLVLRDY8       : 1;
  __REG32 CLRINTLVLRDY9       : 1;
  __REG32 CLRINTLVLRDY10      : 1;
  __REG32 CLRINTLVLRDY11      : 1;
  __REG32 CLRINTLVLRDY12      : 1;
  __REG32 CLRINTLVLRDY13      : 1;
  __REG32 CLRINTLVLRDY14      : 1;
  __REG32 CLRINTLVLRDY15      : 1;
} __spitgitlvcr_bits;

/* TG Transfer Group Interrupt Flag Register (TGINTFLAG) */
typedef struct {
  __REG32 INTFLGSUS0          : 1;
  __REG32 INTFLGSUS1          : 1;
  __REG32 INTFLGSUS2          : 1;
  __REG32 INTFLGSUS3          : 1;
  __REG32 INTFLGSUS4          : 1;
  __REG32 INTFLGSUS5          : 1;
  __REG32 INTFLGSUS6          : 1;
  __REG32 INTFLGSUS7          : 1;
  __REG32 INTFLGSUS8          : 1;
  __REG32 INTFLGSUS9          : 1;
  __REG32 INTFLGSUS10         : 1;
  __REG32 INTFLGSUS11         : 1;
  __REG32 INTFLGSUS12         : 1;
  __REG32 INTFLGSUS13         : 1;
  __REG32 INTFLGSUS14         : 1;
  __REG32 INTFLGSUS15         : 1;
  __REG32 INTFLGRDY0          : 1;
  __REG32 INTFLGRDY1          : 1;
  __REG32 INTFLGRDY2          : 1;
  __REG32 INTFLGRDY3          : 1;
  __REG32 INTFLGRDY4          : 1;
  __REG32 INTFLGRDY5          : 1;
  __REG32 INTFLGRDY6          : 1;
  __REG32 INTFLGRDY7          : 1;
  __REG32 INTFLGRDY8          : 1;
  __REG32 INTFLGRDY9          : 1;
  __REG32 INTFLGRDY10         : 1;
  __REG32 INTFLGRDY11         : 1;
  __REG32 INTFLGRDY12         : 1;
  __REG32 INTFLGRDY13         : 1;
  __REG32 INTFLGRDY14         : 1;
  __REG32 INTFLGRDY15         : 1;
} __spitgintflg_bits;

/* Tick Count Register (TICKCNT) */
typedef struct {
  __REG32 TICKVALUE           :16;
  __REG32                     :12;
  __REG32 CLKCTRL             : 2;
  __REG32 RELOAD              : 1;
  __REG32 TICKENA             : 1;
} __spitickcnt_bits;

/* Last TG End Pointer (LTGPEND) */
typedef struct {
  __REG32                     : 8;
  __REG32 LPEND               : 7;
  __REG32                     : 9;
  __REG32 TG_IN_SERVICE       : 5;
  __REG32                     : 3;
} __spiltgpend_bits;

/* TGx Control Registers (TGCTRL) */
typedef struct {
  __REG32 PCURRENT            : 7;
  __REG32                     : 1;
  __REG32 PSTART              : 7;
  __REG32                     : 1;
  __REG32 TRIGSRC             : 4;
  __REG32 TRIGEVT             : 4;
  __REG32                     : 4;
  __REG32 TGTD                : 1;
  __REG32 PRST                : 1;
  __REG32 ONESHOT             : 1;
  __REG32 TGENA               : 1;
} __spitgctrl_bits;

/* SPI DMA Channel Control Register (DMAxCTRL) */
typedef struct {
  __REG32 COUNT               : 6;
  __REG32 COUNT_BIT17         : 1;
  __REG32                     : 1;
  __REG32 ICOUNT              : 5;
  __REG32 NOBRK               : 1;
  __REG32 TXDMAENA            : 1;
  __REG32 RXDMAENA            : 1;
  __REG32 TXDMA_MAP           : 4;
  __REG32 RXDMA_MAP           : 4;
  __REG32 BUFID               : 7;
  __REG32 ONESHOT             : 1;
} __spidmactrl_bits;

/* SPI DMAxCOUNT Register (ICOUNT) */
typedef struct {
  __REG32 COUNT               :16;
  __REG32 ICOUNT              :16;
} __spidmacount_bits;

/* SPI DMA Large Count Register (DMACNTLEN) */
typedef struct {
  __REG32 LARGE_COUNT         : 1;
  __REG32                     :31;
} __spidmacntlen_bits;

/* SPI Multi-buffer RAM Uncorrectable Parity Error Control Register (UERRCTRL) */
typedef struct {
  __REG32 EDEN                : 4;
  __REG32                     : 4;
  __REG32 PTESTEN             : 1;
  __REG32                     :23;
} __spiuerrctrl_bits;

/* SPI Multi-buffer RAM Uncorrectable Parity Error Status Register (UERRSTAT) */
typedef struct {
  __REG32 EDFLG0              : 1;
  __REG32 EDFLG1              : 1;
  __REG32                     :30;
} __spiuerrstat_bits;

/* SPI RXRAM Uncorrectable Parity Error Address Register (UERRADDR1) */
typedef struct {
  __REG32 OVERRADDR1          :10;
  __REG32                     :22;
} __spiuerraddr1_bits;

/* SPI RXRAM Uncorrectable Parity Error Address Register (UERRADDR0) */
typedef struct {
  __REG32 UERRADDR0           : 9;
  __REG32                     :23;
} __spiuerraddr0_bits;

/* SPI RXRAM Overrun Buffer Address Register (RXOVRN_BUF_ADDR) */
typedef struct {
  __REG32 RXOVRN_BUF_ADDR     :10;
  __REG32                     :22;
} __spirxovrn_buf_addr_bits;

/* SPI I/O-Loopback Test Control Register (IOLPBKTSTCR) */
typedef struct {
  __REG32 RXP_ENA             : 1;
  __REG32 LPBK_TYPE           : 1;
  __REG32 CTRL_SCS_PINERR     : 1;
  __REG32 ERR_SCS_PIN         : 3;
  __REG32                     : 2;
  __REG32 IOLPBKTSTENA        : 4;
  __REG32                     : 4;
  __REG32 CTRL_DLENERR        : 1;
  __REG32 CTRL_TIMEOUT        : 1;
  __REG32 CTRL_PARERR         : 1;
  __REG32 CTRL_DESYNC         : 1;
  __REG32 CTRL_BITERR         : 1;
  __REG32                     : 3;
  __REG32 SCS_FAIL_FLG        : 1;
  __REG32                     : 7;
} __spiiolpbktstcr_bits;

/* SPI Extended Prescale Register 1 (EXTENDED_PRESCALE1) */
typedef struct {
  __REG32 EPRESCALE_FMT0      :11;
  __REG32                     : 5;
  __REG32 EPRESCALE_FMT1      :11;
  __REG32                     : 5;
} __spiextendedprescale1_bits;

/* SPI Extended Prescale Register 2 (EXTENDED_PRESCALE2) */
typedef struct {
  __REG32 EPRESCALE_FMT2      :11;
  __REG32                     : 5;
  __REG32 EPRESCALE_FMT3      :11;
  __REG32                     : 5;
} __spiextendedprescale2_bits;

/* ADC Reset Control Register (ADRSTCR) */
typedef struct {
  __REG32 RESET               : 1;
  __REG32                     :31;
} __adrstcr_bits;

/* ADC Operating Mode Control Register (ADOPMODECR) */
typedef struct {
  __REG32 ADC_EN              : 1;
  __REG32                     : 3;
  __REG32 IDLE_PWRDN          : 1;
  __REG32                     : 3;
  __REG32 POWER_DOWN          : 1;
  __REG32                     : 7;
  __REG32 RAM_TEST_EN         : 1;
  __REG32 CHN_TEST_EN         : 4;
  __REG32                     : 3;
  __REG32 COS                 : 1;
  __REG32                     : 6;
  __REG32 _12_BIT             : 1;
} __adopmodecr_bits;

/* ADC Clock Control Register (ADCLOCKCR) */
typedef struct {
  __REG32 PS                  : 5;
  __REG32                     :27;
} __adclockcr_bits;

/* ADC Calibration Mode Control Register (ADCALCR) */
typedef struct {
  __REG32 CAL_EN              : 1;
  __REG32                     : 7;
  __REG32 HILO                : 1;
  __REG32 BRIDGE_EN           : 1;
  __REG32                     : 6;
  __REG32 CAL_ST              : 1;
  __REG32                     : 7;
  __REG32 SELF_TEST           : 1;
  __REG32                     : 7;
} __adcalcr_bits;

/* ADC Event Group Operating Mode Control Register (ADEVMODECR) */
typedef struct {
  __REG32 FRZ_EV              : 1;
  __REG32 EV_MODE             : 1;
  __REG32 EV_8BIT             : 1;
  __REG32                     : 1;
  __REG32 OVR_EV_RAM_IGN      : 1;
  __REG32 EV_CHID             : 1;
  __REG32                     : 2;
  __REG32 EV_DATA_FMT         : 2;
  __REG32                     : 6;
  __REG32 NoResetOnChnSel     : 1;
  __REG32                     :15;
} __adevmodecr_bits;

/* ADC Group1 Operating Mode Control Register (ADG1MODECR) */
typedef struct {
  __REG32 FRZ_G1              : 1;
  __REG32 G1_MODE             : 1;
  __REG32 G1_8BIT             : 1;
  __REG32 G1_HW_TRIG          : 1;
  __REG32 OVR_G1_RAM_IGN      : 1;
  __REG32 G1_CHID             : 1;
  __REG32                     : 2;
  __REG32 G1_DATA_FMT         : 2;
  __REG32                     : 6;
  __REG32 NoResetOnChnSel     : 1;
  __REG32                     :15;
} __adg1modecr_bits;

/* ADC Group2 Operating Mode Control Register (ADG2MODECR) */
typedef struct {
  __REG32 FRZ_G2              : 1;
  __REG32 G2_MODE             : 1;
  __REG32 G2_8BIT             : 1;
  __REG32 G2_HW_TRIG          : 1;
  __REG32 OVR_G2_RAM_IGN      : 1;
  __REG32 G2_CHID             : 1;
  __REG32                     : 2;
  __REG32 G2_DATA_FMT         : 2;
  __REG32                     : 6;
  __REG32 NoResetOnChnSel     : 1;
  __REG32                     :15;
} __adg2modecr_bits;

/* ADC Event Group Trigger Source Select Register (ADEVSRC) */
typedef struct {
  __REG32 EV_SRC              : 3;
  __REG32 EV_EDG_SEL          : 1;
  __REG32 EV_EDG_BOTH         : 1;
  __REG32                     :27;
} __adevsrc_bits;

/* ADC Group1 Trigger Source Select Register (ADG1SRC) */
typedef struct {
  __REG32 G1_SRC              : 3;
  __REG32 G1_EDG_SEL          : 1;
  __REG32 G1_EDG_BOTH         : 1;
  __REG32                     :27;
} __adg1src_bits;

/* ADC Group2 Trigger Source Select Register (ADG2SRC) */
typedef struct {
  __REG32 G2_SRC              : 3;
  __REG32 G2_EDG_SEL          : 1;
  __REG32 G2_EDG_BOTH         : 1;
  __REG32                     :27;
} __adg2src_bits;

/* ADC Event Group Interrupt Enable Control Register (ADEVINTENA) */
typedef struct {
  __REG32 EV_THR_INT_EN       : 1;
  __REG32 EV_OVR_INT_EN       : 1;
  __REG32                     : 1;
  __REG32 EV_END_INT_EN       : 1;
  __REG32                     :28;
} __adevintena_bits;

/* ADC Group1 Interrupt Enable Control Register (ADG1INTENA) */
typedef struct {
  __REG32 G1_THR_INT_EN       : 1;
  __REG32 G1_OVR_INT_EN       : 1;
  __REG32                     : 1;
  __REG32 G1_END_INT_EN       : 1;
  __REG32                     :28;
} __adg1intena_bits;

/* ADC Group2 Interrupt Enable Control Register (ADG2INTENA) */
typedef struct {
  __REG32 G2_THR_INT_EN       : 1;
  __REG32 G2_OVR_INT_EN       : 1;
  __REG32                     : 1;
  __REG32 G2_END_INT_EN       : 1;
  __REG32                     :28;
} __adg2intena_bits;

/* ADC Event Group Interrupt Flag Register (ADEVINTFLG) */
typedef struct {
  __REG32 EV_THR_INT_FLG      : 1;
  __REG32 EV_MEM_OVERRUN      : 1;
  __REG32 EV_MEM_EMPTY        : 1;
  __REG32 EV_END              : 1;
  __REG32                     :28;
} __adevintflg_bits;

/* ADC Group1 Interrupt Flag Register (ADG1INTFLG) */
typedef struct {
  __REG32 G1_THR_INT_FLG      : 1;
  __REG32 G1_MEM_OVERRUN      : 1;
  __REG32 G1_MEM_EMPTY        : 1;
  __REG32 G1_END              : 1;
  __REG32                     :28;
} __adg1intflg_bits;

/* ADC Group2 Interrupt Flag Register (ADG2INTFLG) */
typedef struct {
  __REG32 G2_THR_INT_FLG      : 1;
  __REG32 G2_MEM_OVERRUN      : 1;
  __REG32 G2_MEM_EMPTY        : 1;
  __REG32 G2_END              : 1;
  __REG32                     :28;
} __adg2intflg_bits;

/* ADC Event Group Threshold Interrupt Control Register (ADEVTHRINTCR) */
typedef struct {
  __REG32 EV_THR              : 9;
  __REG32 Sign_Extension      : 7;
  __REG32                     :16;
} __adevthrintcr_bits;

/* ADC Group1 Threshold Interrupt Control Register (ADG1THRINTCR) */
typedef struct {
  __REG32 G1_THR              : 9;
  __REG32 Sign_Extension      : 7;
  __REG32                     :16;
} __adg1thrintcr_bits;

/* ADC Group2 Threshold Interrupt Control Register (ADG2THRINTCR) */
typedef struct {
  __REG32 G2_THR              : 9;
  __REG32 Sign_Extension      : 7;
  __REG32                     :16;
} __adg2thrintcr_bits;

/* ADC Event Group DMA Control Register (ADEVDMACR) */
typedef struct {
  __REG32 EV_DMA_EN           : 1;
  __REG32                     : 1;
  __REG32 EV_BLK_XFER         : 1;
  __REG32 DMA_EV_END          : 1;
  __REG32                     :12;
  __REG32 EV_BLOCKS           : 9;
  __REG32                     : 7;
} __adevdmacr_bits;

/* ADC Group1 DMA Control Register (ADG1DMACR) */
typedef struct {
  __REG32 G1_DMA_EN           : 1;
  __REG32                     : 1;
  __REG32 G1_BLK_XFER         : 1;
  __REG32 DMA_G1_END          : 1;
  __REG32                     :12;
  __REG32 G1_BLOCKS           : 9;
  __REG32                     : 7;
} __adg1dmacr_bits;

/* ADC Group2 DMA Control Register (ADG2DMACR) */
typedef struct {
  __REG32 G2_DMA_EN           : 1;
  __REG32                     : 1;
  __REG32 G2_BLK_XFER         : 1;
  __REG32 DMA_G2_END          : 1;
  __REG32                     :12;
  __REG32 G2_BLOCKS           : 9;
  __REG32                     : 7;
} __adg2dmacr_bits;

/* ADC Results Memory Configuration Register (ADBNDCR) */
typedef struct {
  __REG32 BNDB                : 9;
  __REG32                     : 7;
  __REG32 BNDA                : 9;
  __REG32                     : 7;
} __adbndcr_bits;

/* ADC Results Memory Size Configuration Register (ADBNDEND) */
typedef struct {
  __REG32 BNDEND              : 3;
  __REG32                     :13;
  __REG32 BUF_INIT_ACTIVE     : 1;
  __REG32                     :15;
} __adbndend_bits;

/* ADC Event Group Sampling Time Configuration Register (ADEVSAMP) */
typedef struct {
  __REG32 EV_ACQ              :12;
  __REG32                     :20;
} __adevsamp_bits;

/* ADC Group1 Sampling Time Configuration Register (ADG1SAMP) */
typedef struct {
  __REG32 G1_ACQ              :12;
  __REG32                     :20;
} __adg1samp_bits;

/* ADC Group2 Sampling Time Configuration Register (ADG2SAMP) */
typedef struct {
  __REG32 G2_ACQ              :12;
  __REG32                     :20;
} __adg2samp_bits;

/* ADC Event Group Status Register (ADEVSR) */
typedef struct {
  __REG32 EV_END              : 1;
  __REG32 EV_STOP             : 1;
  __REG32 EV_BUSY             : 1;
  __REG32 EV_MEM_EMPTY        : 1;
  __REG32                     :28;
} __adevsr_bits;

/* ADC Group1 Status Register (ADG1SR) */
typedef struct {
  __REG32 G1_END              : 1;
  __REG32 G1_STOP             : 1;
  __REG32 G1_BUSY             : 1;
  __REG32 G1_MEM_EMPTY        : 1;
  __REG32                     :28;
} __adg1sr_bits;

/* ADC Group2 Status Register (ADG2SR) */
typedef struct {
  __REG32 G2_END              : 1;
  __REG32 G2_STOP             : 1;
  __REG32 G2_BUSY             : 1;
  __REG32 G2_MEM_EMPTY        : 1;
  __REG32                     :28;
} __adg2sr_bits;

/* ADC Event Group Channel Select Register (ADEVSEL) */
typedef struct {
  __REG32 EV_SEL0             : 1;
  __REG32 EV_SEL1             : 1;
  __REG32 EV_SEL2             : 1;
  __REG32 EV_SEL3             : 1;
  __REG32 EV_SEL4             : 1;
  __REG32 EV_SEL5             : 1;
  __REG32 EV_SEL6             : 1;
  __REG32 EV_SEL7             : 1;
  __REG32 EV_SEL8             : 1;
  __REG32 EV_SEL9             : 1;
  __REG32 EV_SEL10            : 1;
  __REG32 EV_SEL11            : 1;
  __REG32 EV_SEL12            : 1;
  __REG32 EV_SEL13            : 1;
  __REG32 EV_SEL14            : 1;
  __REG32 EV_SEL15            : 1;
  __REG32 EV_SEL16            : 1;
  __REG32 EV_SEL17            : 1;
  __REG32 EV_SEL18            : 1;
  __REG32 EV_SEL19            : 1;
  __REG32 EV_SEL20            : 1;
  __REG32 EV_SEL21            : 1;
  __REG32 EV_SEL22            : 1;
  __REG32 EV_SEL23            : 1;
  __REG32                     : 8;
} __adevsel_bits;

/* ADC Group1 Channel Select Register (ADG1SEL) */
typedef struct {
  __REG32 G1_SEL0             : 1;
  __REG32 G1_SEL1             : 1;
  __REG32 G1_SEL2             : 1;
  __REG32 G1_SEL3             : 1;
  __REG32 G1_SEL4             : 1;
  __REG32 G1_SEL5             : 1;
  __REG32 G1_SEL6             : 1;
  __REG32 G1_SEL7             : 1;
  __REG32 G1_SEL8             : 1;
  __REG32 G1_SEL9             : 1;
  __REG32 G1_SEL10            : 1;
  __REG32 G1_SEL11            : 1;
  __REG32 G1_SEL12            : 1;
  __REG32 G1_SEL13            : 1;
  __REG32 G1_SEL14            : 1;
  __REG32 G1_SEL15            : 1;
  __REG32 G1_SEL16            : 1;
  __REG32 G1_SEL17            : 1;
  __REG32 G1_SEL18            : 1;
  __REG32 G1_SEL19            : 1;
  __REG32 G1_SEL20            : 1;
  __REG32 G1_SEL21            : 1;
  __REG32 G1_SEL22            : 1;
  __REG32 G1_SEL23            : 1;
  __REG32                     : 8;
} __adg1sel_bits;

/* ADC Group2 Channel Select Register (ADG2SEL) */
typedef struct {
  __REG32 G2_SEL0             : 1;
  __REG32 G2_SEL1             : 1;
  __REG32 G2_SEL2             : 1;
  __REG32 G2_SEL3             : 1;
  __REG32 G2_SEL4             : 1;
  __REG32 G2_SEL5             : 1;
  __REG32 G2_SEL6             : 1;
  __REG32 G2_SEL7             : 1;
  __REG32 G2_SEL8             : 1;
  __REG32 G2_SEL9             : 1;
  __REG32 G2_SEL10            : 1;
  __REG32 G2_SEL11            : 1;
  __REG32 G2_SEL12            : 1;
  __REG32 G2_SEL13            : 1;
  __REG32 G2_SEL14            : 1;
  __REG32 G2_SEL15            : 1;
  __REG32 G2_SEL16            : 1;
  __REG32 G2_SEL17            : 1;
  __REG32 G2_SEL18            : 1;
  __REG32 G2_SEL19            : 1;
  __REG32 G2_SEL20            : 1;
  __REG32 G2_SEL21            : 1;
  __REG32 G2_SEL22            : 1;
  __REG32 G2_SEL23            : 1;
  __REG32                     : 8;
} __adg2sel_bits;

/* ADC Calibration and Error Offset Correction Register (ADCALR) */
typedef struct {
  __REG32 ADCALR              :12;
  __REG32                     :20;
} __adcalr_bits;

/* ADC State Machine Status Register (ADSMSTATE) */
typedef struct {
  __REG32 SMSTATE             : 4;
  __REG32                     :28;
} __adsmstate_bits;

/* ADC Channel Last Conversion Value Register (ADLASTCONV) */
typedef struct {
  __REG32 LAST_CONV0          : 1;
  __REG32 LAST_CONV1          : 1;
  __REG32 LAST_CONV2          : 1;
  __REG32 LAST_CONV3          : 1;
  __REG32 LAST_CONV4          : 1;
  __REG32 LAST_CONV5          : 1;
  __REG32 LAST_CONV6          : 1;
  __REG32 LAST_CONV7          : 1;
  __REG32 LAST_CONV8          : 1;
  __REG32 LAST_CONV9          : 1;
  __REG32 LAST_CONV10         : 1;
  __REG32 LAST_CONV11         : 1;
  __REG32 LAST_CONV12         : 1;
  __REG32 LAST_CONV13         : 1;
  __REG32 LAST_CONV14         : 1;
  __REG32 LAST_CONV15         : 1;
  __REG32 LAST_CONV16         : 1;
  __REG32 LAST_CONV17         : 1;
  __REG32 LAST_CONV18         : 1;
  __REG32 LAST_CONV19         : 1;
  __REG32 LAST_CONV20         : 1;
  __REG32 LAST_CONV21         : 1;
  __REG32 LAST_CONV22         : 1;
  __REG32 LAST_CONV23         : 1;
  __REG32                     : 8;
} __adlastconv_bits;

/* ADC Event Group Results FIFO (ADEVBUFFER) */
typedef union {
/* AD1EVBUFFERx */
/* AD2EVBUFFERx */
/* AD1EVEMUBUFFER */
/* AD2EVEMUBUFFER */
struct {
  __REG32 EV_DR               :12;
  __REG32                     : 4;
  __REG32 EV_CHID             : 5;
  __REG32                     :10;
  __REG32 EV_EMPTY            : 1;
  };
/* AD1EVBUFFERx_10 */
/* AD2EVBUFFERx_10 */
/* AD1EVEMUBUFFER_10 */
/* AD2EVEMUBUFFER_10 */
struct {
  __REG32 EV_DR_10            :10;
  __REG32 EV_CHID_10          : 5;
  __REG32 EV_EMPTY_10         : 1;
  __REG32                     :16;
  };
} __adevbuffer_bits;

/* ADC Group1 Results FIFO (ADG1BUFFER) */
typedef union {
/* AD1G1BUFFERx */
/* AD2G1BUFFERx */
/* AD1G1EMUBUFFER */
/* AD2G1EMUBUFFER */
struct {
  __REG32 G1_DR               :12;
  __REG32                     : 4;
  __REG32 G1_CHID             : 5;
  __REG32                     :10;
  __REG32 G1_EMPTY            : 1;
  };
/* AD1G1BUFFERx_10 */
/* AD2G1BUFFERx_10 */
/* AD1G1EMUBUFFER_10 */
/* AD2G1EMUBUFFER_10 */
struct {
  __REG32 G1_DR_10            :10;
  __REG32 G1_CHID_10          : 5;
  __REG32 G1_EMPTY_10         : 1;
  __REG32                     :16;
  };
} __adg1buffer_bits;

/* ADC Group2 Results FIFO (ADG2BUFFER) */
typedef union {
/* AD1G2BUFFERx */
/* AD2G2BUFFERx */
/* AD1G2EMUBUFFER */
/* AD2G2EMUBUFFER */
struct {
  __REG32 G2_DR               :12;
  __REG32                     : 4;
  __REG32 G2_CHID             : 5;
  __REG32                     :10;
  __REG32 G2_EMPTY            : 1;
  };
/* AD1G2BUFFERx_10 */
/* AD2G2BUFFERx_10 */
/* AD1G2EMUBUFFER_10 */
/* AD2G2EMUBUFFER_10 */
struct {
  __REG32 G2_DR_10            :10;
  __REG32 G2_CHID_10          : 5;
  __REG32 G2_EMPTY_10         : 1;
  __REG32                     :16;
  };
} __adg2buffer_bits;

/* ADC ADEVT Pin Direction Control Register (ADEVTDIR) */
typedef struct {
  __REG32 ADEVT_DIR           : 1;
  __REG32                     :31;
} __adevtdir_bits;

/* ADC ADEVT Pin Output Value Control Register (ADEVTOUT) */
typedef struct {
  __REG32 ADEVT_OUT           : 1;
  __REG32                     :31;
} __adevtout_bits;

/* ADC ADEVT Pin Input Value Register (ADEVTIN) */
typedef struct {
  __REG32 ADEVT_IN            : 1;
  __REG32                     :31;
} __adevtin_bits;

/* ADC ADEVT Pin Set Register (ADEVTSET) */
typedef struct {
  __REG32 ADEVT_SET           : 1;
  __REG32                     :31;
} __adevtset_bits;

/* ADC ADEVT Pin Clear Register (ADEVTCLR) */
typedef struct {
  __REG32 ADEVT_CLR           : 1;
  __REG32                     :31;
} __adevtclr_bits;

/* ADC ADEVT Pin Open Drain Enable Register (ADEVTPDR) */
typedef struct {
  __REG32 ADEVT_PDR           : 1;
  __REG32                     :31;
} __adevtpdr_bits;

/* ADC ADEVT Pin Pull Control Disable Register (ADEVTPDIS) */
typedef struct {
  __REG32 ADEVT_PDIS          : 1;
  __REG32                     :31;
} __adevtpdis_bits;

/* ADC ADEVT Pin Pull Control Select Register (ADEVTPSEL) */
typedef struct {
  __REG32 ADEVT_PSEL          : 1;
  __REG32                     :31;
} __adevtpsel_bits;

/* ADC Event Group Sample Cap Discharge Control Register (ADEVSAMPDISEN) */
typedef struct {
  __REG32 EV_SAMP_DIS_EN      : 1;
  __REG32                     : 7;
  __REG32 EV_SAMP_DIS_CYC     : 8;
  __REG32                     :16;
} __adevsampdisen_bits;

/* ADC Group1 Sample Cap Discharge Control Register (ADG1SAMPDISEN) */
typedef struct {
  __REG32 G1_SAMP_DIS_EN      : 1;
  __REG32                     : 7;
  __REG32 G1_SAMP_DIS_CYC     : 8;
  __REG32                     :16;
} __adg1sampdisen_bits;

/* ADC Group2 Sample Cap Discharge Control Register (ADG2SAMPDISEN) */
typedef struct {
  __REG32 G2_SAMP_DIS_EN      : 1;
  __REG32                     : 7;
  __REG32 G2_SAMP_DIS_CYC     : 8;
  __REG32                     :16;
} __adg2sampdisen_bits;

/* ADC Magnitude Compare Interruptx Control Registers (ADMAGINTxCR) */
typedef struct {
  __REG32 CMP_GE_LT           : 1;
  __REG32 CHN_THR_COMP        : 1;
  __REG32                     : 6;
  __REG32 COMP_CHID           : 5;
  __REG32                     : 3;
  __REG32 MAG_THR             :10;
  __REG32 MAG_CHID            : 5;
  __REG32                     : 1;
} __admagintcr_bits;

/* ADC Magnitude Compare Interruptx Mask (ADMAGINTxMASK) */
typedef struct {
  __REG32 MAG_INT_MASK0       : 1;
  __REG32 MAG_INT_MASK1       : 1;
  __REG32 MAG_INT_MASK2       : 1;
  __REG32 MAG_INT_MASK3       : 1;
  __REG32 MAG_INT_MASK4       : 1;
  __REG32 MAG_INT_MASK5       : 1;
  __REG32 MAG_INT_MASK6       : 1;
  __REG32 MAG_INT_MASK7       : 1;
  __REG32 MAG_INT_MASK8       : 1;
  __REG32 MAG_INT_MASK9       : 1;
  __REG32                     :22;
} __admagintmask_bits;

/* ADC Magnitude Compare Interrupt Enable Set (ADMAGINTENASET) */
typedef struct {
  __REG32 MAG_INT_ENA_SET0    : 1;
  __REG32 MAG_INT_ENA_SET1    : 1;
  __REG32 MAG_INT_ENA_SET2    : 1;
  __REG32                     :29;
} __admagintenaset_bits;

/* ADC Magnitude Compare Interrupt Enable Clear (ADMAGINTENACLR) */
typedef struct {
  __REG32 MAG_INT_ENA_CLR0    : 1;
  __REG32 MAG_INT_ENA_CLR1    : 1;
  __REG32 MAG_INT_ENA_CLR2    : 1;
  __REG32                     :29;
} __admagintenaclr_bits;

/* ADC Magnitude Compare Interrupt Flag (ADMAGINTFLG) */
typedef struct {
  __REG32 MAG_INT_FLG0        : 1;
  __REG32 MAG_INT_FLG1        : 1;
  __REG32 MAG_INT_FLG2        : 1;
  __REG32                     :29;
} __admagintflg_bits;

/* ADC Magnitude Compare Interrupt Offset (ADMAGINTOFF) */
typedef struct {
  __REG32 MAG_INT_OFF         : 4;
  __REG32                     :28;
} __admagintoff_bits;

/* ADC Event Group FIFO Reset Control Register (ADEVFIFORESETCR) */
typedef struct {
  __REG32 EV_FIFO_RESET       : 1;
  __REG32                     :31;
} __adevfiforesetcr_bits;

/* ADC Group1 FIFO Reset Control Register (ADG1FIFORESETCR) */
typedef struct {
  __REG32 G1_FIFO_RESET       : 1;
  __REG32                     :31;
} __adg1fiforesetcr_bits;

/* ADC Group2 FIFO Reset Control Register (ADG2FIFORESETCR) */
typedef struct {
  __REG32 G2_FIFO_RESET       : 1;
  __REG32                     :31;
} __adg2fiforesetcr_bits;

/* ADC Event Group RAM Write Address (ADEVRAMWRADDR) */
typedef struct {
  __REG32 EV_RAM_ADDR         : 9;
  __REG32                     :23;
} __adevramwraddr_bits;

/* ADC Group1 RAM Write Address (ADG1RAMWRADDR) */
typedef struct {
  __REG32 G1_RAM_ADDR         : 9;
  __REG32                     :23;
} __adg1ramwraddr_bits;

/* ADC Group2 RAM Write Address (ADG2RAMWRADDR) */
typedef struct {
  __REG32 G2_RAM_ADDR         : 9;
  __REG32                     :23;
} __adg2ramwraddr_bits;

/* ADC Parity Control Register (ADPARCR) */
typedef struct {
  __REG32 PARITY_ENA          : 4;
  __REG32                     : 4;
  __REG32 TEST                : 1;
  __REG32                     :23;
} __adparcr_bits;

/* ADC Parity Error Address (ADPARADDR) */
typedef struct {
  __REG32                     : 2;
  __REG32 ERROR_ADDRESS       :10;
  __REG32                     :20;
} __adparaddr_bits;

/* ADC Power-Up Delay Control Register (ADPWRUPDLYCTRL) */
typedef struct {
  __REG32 PWRUP_DLY           :10;
  __REG32                     :22;
} __adpwrupdlyctrl_bits;

/* CAN Control Register (DCAN CTL) */
typedef struct {
  __REG32 Init                : 1;
  __REG32 IE0                 : 1;
  __REG32 SIE                 : 1;
  __REG32 EIE                 : 1;
  __REG32                     : 1;
  __REG32 DAR                 : 1;
  __REG32 CCE                 : 1;
  __REG32 Test                : 1;
  __REG32 IDS                 : 1;
  __REG32 ABO                 : 1;
  __REG32 PMD                 : 4;
  __REG32                     : 1;
  __REG32 SWR                 : 1;
  __REG32 InitDbg             : 1;
  __REG32 IE1                 : 1;
  __REG32 DE1                 : 1;
  __REG32 DE2                 : 1;
  __REG32 DE3                 : 1;
  __REG32                     : 3;
  __REG32 PDR                 : 1;
  __REG32 WUBA                : 1;
  __REG32                     : 6;
} __dcanctl_bits;

/* CAN Error and Status Register (DCAN ES) */
typedef struct {
  __REG32 LEC                 : 3;
  __REG32 TxOK                : 1;
  __REG32 RxOK                : 1;
  __REG32 EPass               : 1;
  __REG32 EWarn               : 1;
  __REG32 BOff                : 1;
  __REG32 PER                 : 1;
  __REG32 WakeUpPnd           : 1;
  __REG32 PDA                 : 1;
  __REG32                     :21;
} __dcanes_bits;

/* CAN Error Counter Register (DCAN ERRC) */
typedef struct {
  __REG32 TEC                 : 8;
  __REG32 REC                 : 7;
  __REG32 RP                  : 1;
  __REG32                     :16;
} __dcanerrc_bits;

/* CAN Bit Timing Register (DCAN BTR) */
typedef struct {
  __REG32 BRP                 : 6;
  __REG32 SJW                 : 2;
  __REG32 TSeg1               : 4;
  __REG32 TSeg2               : 3;
  __REG32                     : 1;
  __REG32 BRPE                : 4;
  __REG32                     :12;
} __dcanbtr_bits;

/* CAN Interrupt Register (DCANINT) */
typedef struct {
  __REG32 Int0ID              :16;
  __REG32 Int1ID              : 8;
  __REG32                     : 8;
} __dcanint_bits;

/* CAN Test Register (DCAN TEST) */
typedef struct {
  __REG32                     : 3;
  __REG32 Silent              : 1;
  __REG32 LBack               : 1;
  __REG32 Tx                  : 2;
  __REG32 Rx                  : 1;
  __REG32 EXL                 : 1;
  __REG32 RDA                 : 1;
  __REG32                     :22;
} __dcantest_bits;

/* CAN Parity Error Code Register (DCAN PERR) */
typedef struct {
  __REG32 MessageNumber       : 8;
  __REG32 WordNumber          : 3;
  __REG32                     :21;
} __dcanperr_bits;

/* CAN Transmission Request X Register (DCAN TXRQ X) */
typedef struct {
  __REG32 TxRqstReg1          : 2;
  __REG32 TxRqstReg2          : 2;
  __REG32 TxRqstReg3          : 2;
  __REG32 TxRqstReg4          : 2;
  __REG32 TxRqstReg5          : 2;
  __REG32 TxRqstReg6          : 2;
  __REG32 TxRqstReg7          : 2;
  __REG32 TxRqstReg8          : 2;
  __REG32                     :16;
} __dcantxrqx_bits;

/* CAN Transmission Request Registers (DCAN TXRQ12) */
typedef struct {
  __REG32 TxRqst1           : 1;
  __REG32 TxRqst2           : 1;
  __REG32 TxRqst3           : 1;
  __REG32 TxRqst4           : 1;
  __REG32 TxRqst5           : 1;
  __REG32 TxRqst6           : 1;
  __REG32 TxRqst7           : 1;
  __REG32 TxRqst8           : 1;
  __REG32 TxRqst9           : 1;
  __REG32 TxRqst10          : 1;
  __REG32 TxRqst11          : 1;
  __REG32 TxRqst12          : 1;
  __REG32 TxRqst13          : 1;
  __REG32 TxRqst14          : 1;
  __REG32 TxRqst15          : 1;
  __REG32 TxRqst16          : 1;
  __REG32 TxRqst17          : 1;
  __REG32 TxRqst18          : 1;
  __REG32 TxRqst19          : 1;
  __REG32 TxRqst20          : 1;
  __REG32 TxRqst21          : 1;
  __REG32 TxRqst22          : 1;
  __REG32 TxRqst23          : 1;
  __REG32 TxRqst24          : 1;
  __REG32 TxRqst25          : 1;
  __REG32 TxRqst26          : 1;
  __REG32 TxRqst27          : 1;
  __REG32 TxRqst28          : 1;
  __REG32 TxRqst29          : 1;
  __REG32 TxRqst30          : 1;
  __REG32 TxRqst31          : 1;
  __REG32 TxRqst32          : 1;
} __dcantxrq12_bits;

/* CAN Transmission Request Registers (DCAN TXRQ34) */
typedef struct {
  __REG32 TxRqst33          : 1;
  __REG32 TxRqst34          : 1;
  __REG32 TxRqst35          : 1;
  __REG32 TxRqst36          : 1;
  __REG32 TxRqst37          : 1;
  __REG32 TxRqst38          : 1;
  __REG32 TxRqst39          : 1;
  __REG32 TxRqst40          : 1;
  __REG32 TxRqst41          : 1;
  __REG32 TxRqst42          : 1;
  __REG32 TxRqst43          : 1;
  __REG32 TxRqst44          : 1;
  __REG32 TxRqst45          : 1;
  __REG32 TxRqst46          : 1;
  __REG32 TxRqst47          : 1;
  __REG32 TxRqst48          : 1;
  __REG32 TxRqst49          : 1;
  __REG32 TxRqst50          : 1;
  __REG32 TxRqst51          : 1;
  __REG32 TxRqst52          : 1;
  __REG32 TxRqst53          : 1;
  __REG32 TxRqst54          : 1;
  __REG32 TxRqst55          : 1;
  __REG32 TxRqst56          : 1;
  __REG32 TxRqst57          : 1;
  __REG32 TxRqst58          : 1;
  __REG32 TxRqst59          : 1;
  __REG32 TxRqst60          : 1;
  __REG32 TxRqst61          : 1;
  __REG32 TxRqst62          : 1;
  __REG32 TxRqst63          : 1;
  __REG32 TxRqst64          : 1;
} __dcantxrq34_bits;

/* CAN Transmission Request Registers (DCAN TXRQ56) */
typedef struct {
  __REG32 TxRqst65          : 1;
  __REG32 TxRqst66          : 1;
  __REG32 TxRqst67          : 1;
  __REG32 TxRqst68          : 1;
  __REG32 TxRqst69          : 1;
  __REG32 TxRqst70          : 1;
  __REG32 TxRqst71          : 1;
  __REG32 TxRqst72          : 1;
  __REG32 TxRqst73          : 1;
  __REG32 TxRqst74          : 1;
  __REG32 TxRqst75          : 1;
  __REG32 TxRqst76          : 1;
  __REG32 TxRqst77          : 1;
  __REG32 TxRqst78          : 1;
  __REG32 TxRqst79          : 1;
  __REG32 TxRqst80          : 1;
  __REG32 TxRqst81          : 1;
  __REG32 TxRqst82          : 1;
  __REG32 TxRqst83          : 1;
  __REG32 TxRqst84          : 1;
  __REG32 TxRqst85          : 1;
  __REG32 TxRqst86          : 1;
  __REG32 TxRqst87          : 1;
  __REG32 TxRqst88          : 1;
  __REG32 TxRqst89          : 1;
  __REG32 TxRqst90          : 1;
  __REG32 TxRqst91          : 1;
  __REG32 TxRqst92          : 1;
  __REG32 TxRqst93          : 1;
  __REG32 TxRqst94          : 1;
  __REG32 TxRqst95          : 1;
  __REG32 TxRqst96          : 1;
} __dcantxrq56_bits;

/* CAN Transmission Request Registers (DCAN TXRQ78) */
typedef struct {
  __REG32 TxRqst97          : 1;
  __REG32 TxRqst98          : 1;
  __REG32 TxRqst99          : 1;
  __REG32 TxRqst100         : 1;
  __REG32 TxRqst101         : 1;
  __REG32 TxRqst102         : 1;
  __REG32 TxRqst103         : 1;
  __REG32 TxRqst104         : 1;
  __REG32 TxRqst105         : 1;
  __REG32 TxRqst106         : 1;
  __REG32 TxRqst107         : 1;
  __REG32 TxRqst108         : 1;
  __REG32 TxRqst109         : 1;
  __REG32 TxRqst110         : 1;
  __REG32 TxRqst111         : 1;
  __REG32 TxRqst112         : 1;
  __REG32 TxRqst113         : 1;
  __REG32 TxRqst114         : 1;
  __REG32 TxRqst115         : 1;
  __REG32 TxRqst116         : 1;
  __REG32 TxRqst117         : 1;
  __REG32 TxRqst118         : 1;
  __REG32 TxRqst119         : 1;
  __REG32 TxRqst120         : 1;
  __REG32 TxRqst121         : 1;
  __REG32 TxRqst122         : 1;
  __REG32 TxRqst123         : 1;
  __REG32 TxRqst124         : 1;
  __REG32 TxRqst125         : 1;
  __REG32 TxRqst126         : 1;
  __REG32 TxRqst127         : 1;
  __REG32 TxRqst128         : 1;
} __dcantxrq78_bits;

/* CAN New Data X Register (DCAN NWDAT X) */
typedef struct {
  __REG32 NewDatReg1          : 2;
  __REG32 NewDatReg2          : 2;
  __REG32 NewDatReg3          : 2;
  __REG32 NewDatReg4          : 2;
  __REG32 NewDatReg5          : 2;
  __REG32 NewDatReg6          : 2;
  __REG32 NewDatReg7          : 2;
  __REG32 NewDatReg8          : 2;
  __REG32                     :16;
} __dcannwdatx_bits;

/* CAN New Data Registers (DCAN NWDAT12) */
typedef struct {
  __REG32 NewDat1           : 1;
  __REG32 NewDat2           : 1;
  __REG32 NewDat3           : 1;
  __REG32 NewDat4           : 1;
  __REG32 NewDat5           : 1;
  __REG32 NewDat6           : 1;
  __REG32 NewDat7           : 1;
  __REG32 NewDat8           : 1;
  __REG32 NewDat9           : 1;
  __REG32 NewDat10          : 1;
  __REG32 NewDat11          : 1;
  __REG32 NewDat12          : 1;
  __REG32 NewDat13          : 1;
  __REG32 NewDat14          : 1;
  __REG32 NewDat15          : 1;
  __REG32 NewDat16          : 1;
  __REG32 NewDat17          : 1;
  __REG32 NewDat18          : 1;
  __REG32 NewDat19          : 1;
  __REG32 NewDat20          : 1;
  __REG32 NewDat21          : 1;
  __REG32 NewDat22          : 1;
  __REG32 NewDat23          : 1;
  __REG32 NewDat24          : 1;
  __REG32 NewDat25          : 1;
  __REG32 NewDat26          : 1;
  __REG32 NewDat27          : 1;
  __REG32 NewDat28          : 1;
  __REG32 NewDat29          : 1;
  __REG32 NewDat30          : 1;
  __REG32 NewDat31          : 1;
  __REG32 NewDat32          : 1;
} __dcannwdat12_bits;

/* CAN New Data Registers (DCAN NWDAT34) */
typedef struct {
  __REG32 NewDat33          : 1;
  __REG32 NewDat34          : 1;
  __REG32 NewDat35          : 1;
  __REG32 NewDat36          : 1;
  __REG32 NewDat37          : 1;
  __REG32 NewDat38          : 1;
  __REG32 NewDat39          : 1;
  __REG32 NewDat40          : 1;
  __REG32 NewDat41          : 1;
  __REG32 NewDat42          : 1;
  __REG32 NewDat43          : 1;
  __REG32 NewDat44          : 1;
  __REG32 NewDat45          : 1;
  __REG32 NewDat46          : 1;
  __REG32 NewDat47          : 1;
  __REG32 NewDat48          : 1;
  __REG32 NewDat49          : 1;
  __REG32 NewDat50          : 1;
  __REG32 NewDat51          : 1;
  __REG32 NewDat52          : 1;
  __REG32 NewDat53          : 1;
  __REG32 NewDat54          : 1;
  __REG32 NewDat55          : 1;
  __REG32 NewDat56          : 1;
  __REG32 NewDat57          : 1;
  __REG32 NewDat58          : 1;
  __REG32 NewDat59          : 1;
  __REG32 NewDat60          : 1;
  __REG32 NewDat61          : 1;
  __REG32 NewDat62          : 1;
  __REG32 NewDat63          : 1;
  __REG32 NewDat64          : 1;
} __dcannwdat34_bits;

/* CAN New Data Registers (DCAN NWDAT56) */
typedef struct {
  __REG32 NewDat65          : 1;
  __REG32 NewDat66          : 1;
  __REG32 NewDat67          : 1;
  __REG32 NewDat68          : 1;
  __REG32 NewDat69          : 1;
  __REG32 NewDat70          : 1;
  __REG32 NewDat71          : 1;
  __REG32 NewDat72          : 1;
  __REG32 NewDat73          : 1;
  __REG32 NewDat74          : 1;
  __REG32 NewDat75          : 1;
  __REG32 NewDat76          : 1;
  __REG32 NewDat77          : 1;
  __REG32 NewDat78          : 1;
  __REG32 NewDat79          : 1;
  __REG32 NewDat80          : 1;
  __REG32 NewDat81          : 1;
  __REG32 NewDat82          : 1;
  __REG32 NewDat83          : 1;
  __REG32 NewDat84          : 1;
  __REG32 NewDat85          : 1;
  __REG32 NewDat86          : 1;
  __REG32 NewDat87          : 1;
  __REG32 NewDat88          : 1;
  __REG32 NewDat89          : 1;
  __REG32 NewDat90          : 1;
  __REG32 NewDat91          : 1;
  __REG32 NewDat92          : 1;
  __REG32 NewDat93          : 1;
  __REG32 NewDat94          : 1;
  __REG32 NewDat95          : 1;
  __REG32 NewDat96          : 1;
} __dcannwdat56_bits;

/* CAN New Data Registers (DCAN NWDAT78) */
typedef struct {
  __REG32 NewDat97          : 1;
  __REG32 NewDat98          : 1;
  __REG32 NewDat99          : 1;
  __REG32 NewDat100         : 1;
  __REG32 NewDat101         : 1;
  __REG32 NewDat102         : 1;
  __REG32 NewDat103         : 1;
  __REG32 NewDat104         : 1;
  __REG32 NewDat105         : 1;
  __REG32 NewDat106         : 1;
  __REG32 NewDat107         : 1;
  __REG32 NewDat108         : 1;
  __REG32 NewDat109         : 1;
  __REG32 NewDat110         : 1;
  __REG32 NewDat111         : 1;
  __REG32 NewDat112         : 1;
  __REG32 NewDat113         : 1;
  __REG32 NewDat114         : 1;
  __REG32 NewDat115         : 1;
  __REG32 NewDat116         : 1;
  __REG32 NewDat117         : 1;
  __REG32 NewDat118         : 1;
  __REG32 NewDat119         : 1;
  __REG32 NewDat120         : 1;
  __REG32 NewDat121         : 1;
  __REG32 NewDat122         : 1;
  __REG32 NewDat123         : 1;
  __REG32 NewDat124         : 1;
  __REG32 NewDat125         : 1;
  __REG32 NewDat126         : 1;
  __REG32 NewDat127         : 1;
  __REG32 NewDat128         : 1;
} __dcannwdat78_bits;

/* CAN Interrupt Pending X Register (DCAN INTPND X) */
typedef struct {
  __REG32 IntPndReg1          : 2;
  __REG32 IntPndReg2          : 2;
  __REG32 IntPndReg3          : 2;
  __REG32 IntPndReg4          : 2;
  __REG32 IntPndReg5          : 2;
  __REG32 IntPndReg6          : 2;
  __REG32 IntPndReg7          : 2;
  __REG32 IntPndReg8          : 2;
  __REG32                     :16;
} __dcanintpndx_bits;

/* CAN Interrupt Pending Registers (DCAN INTPND12) */
typedef struct {
  __REG32 IntPnd1           : 1;
  __REG32 IntPnd2           : 1;
  __REG32 IntPnd3           : 1;
  __REG32 IntPnd4           : 1;
  __REG32 IntPnd5           : 1;
  __REG32 IntPnd6           : 1;
  __REG32 IntPnd7           : 1;
  __REG32 IntPnd8           : 1;
  __REG32 IntPnd9           : 1;
  __REG32 IntPnd10          : 1;
  __REG32 IntPnd11          : 1;
  __REG32 IntPnd12          : 1;
  __REG32 IntPnd13          : 1;
  __REG32 IntPnd14          : 1;
  __REG32 IntPnd15          : 1;
  __REG32 IntPnd16          : 1;
  __REG32 IntPnd17          : 1;
  __REG32 IntPnd18          : 1;
  __REG32 IntPnd19          : 1;
  __REG32 IntPnd20          : 1;
  __REG32 IntPnd21          : 1;
  __REG32 IntPnd22          : 1;
  __REG32 IntPnd23          : 1;
  __REG32 IntPnd24          : 1;
  __REG32 IntPnd25          : 1;
  __REG32 IntPnd26          : 1;
  __REG32 IntPnd27          : 1;
  __REG32 IntPnd28          : 1;
  __REG32 IntPnd29          : 1;
  __REG32 IntPnd30          : 1;
  __REG32 IntPnd31          : 1;
  __REG32 IntPnd32          : 1;
} __dcanintpnd12_bits;

/* CAN Interrupt Pending Registers (DCAN INTPND34) */
typedef struct {
  __REG32 IntPnd33          : 1;
  __REG32 IntPnd34          : 1;
  __REG32 IntPnd35          : 1;
  __REG32 IntPnd36          : 1;
  __REG32 IntPnd37          : 1;
  __REG32 IntPnd38          : 1;
  __REG32 IntPnd39          : 1;
  __REG32 IntPnd40          : 1;
  __REG32 IntPnd41          : 1;
  __REG32 IntPnd42          : 1;
  __REG32 IntPnd43          : 1;
  __REG32 IntPnd44          : 1;
  __REG32 IntPnd45          : 1;
  __REG32 IntPnd46          : 1;
  __REG32 IntPnd47          : 1;
  __REG32 IntPnd48          : 1;
  __REG32 IntPnd49          : 1;
  __REG32 IntPnd50          : 1;
  __REG32 IntPnd51          : 1;
  __REG32 IntPnd52          : 1;
  __REG32 IntPnd53          : 1;
  __REG32 IntPnd54          : 1;
  __REG32 IntPnd55          : 1;
  __REG32 IntPnd56          : 1;
  __REG32 IntPnd57          : 1;
  __REG32 IntPnd58          : 1;
  __REG32 IntPnd59          : 1;
  __REG32 IntPnd60          : 1;
  __REG32 IntPnd61          : 1;
  __REG32 IntPnd62          : 1;
  __REG32 IntPnd63          : 1;
  __REG32 IntPnd64          : 1;
} __dcanintpnd34_bits;

/* CAN Interrupt Pending Registers (DCAN INTPND56) */
typedef struct {
  __REG32 IntPnd65          : 1;
  __REG32 IntPnd66          : 1;
  __REG32 IntPnd67          : 1;
  __REG32 IntPnd68          : 1;
  __REG32 IntPnd69          : 1;
  __REG32 IntPnd70          : 1;
  __REG32 IntPnd71          : 1;
  __REG32 IntPnd72          : 1;
  __REG32 IntPnd73          : 1;
  __REG32 IntPnd74          : 1;
  __REG32 IntPnd75          : 1;
  __REG32 IntPnd76          : 1;
  __REG32 IntPnd77          : 1;
  __REG32 IntPnd78          : 1;
  __REG32 IntPnd79          : 1;
  __REG32 IntPnd80          : 1;
  __REG32 IntPnd81          : 1;
  __REG32 IntPnd82          : 1;
  __REG32 IntPnd83          : 1;
  __REG32 IntPnd84          : 1;
  __REG32 IntPnd85          : 1;
  __REG32 IntPnd86          : 1;
  __REG32 IntPnd87          : 1;
  __REG32 IntPnd88          : 1;
  __REG32 IntPnd89          : 1;
  __REG32 IntPnd90          : 1;
  __REG32 IntPnd91          : 1;
  __REG32 IntPnd92          : 1;
  __REG32 IntPnd93          : 1;
  __REG32 IntPnd94          : 1;
  __REG32 IntPnd95          : 1;
  __REG32 IntPnd96          : 1;
} __dcanintpnd56_bits;

/* CAN Interrupt Pending Registers (DCAN INTPND78) */
typedef struct {
  __REG32 IntPnd97          : 1;
  __REG32 IntPnd98          : 1;
  __REG32 IntPnd99          : 1;
  __REG32 IntPnd100         : 1;
  __REG32 IntPnd101         : 1;
  __REG32 IntPnd102         : 1;
  __REG32 IntPnd103         : 1;
  __REG32 IntPnd104         : 1;
  __REG32 IntPnd105         : 1;
  __REG32 IntPnd106         : 1;
  __REG32 IntPnd107         : 1;
  __REG32 IntPnd108         : 1;
  __REG32 IntPnd109         : 1;
  __REG32 IntPnd110         : 1;
  __REG32 IntPnd111         : 1;
  __REG32 IntPnd112         : 1;
  __REG32 IntPnd113         : 1;
  __REG32 IntPnd114         : 1;
  __REG32 IntPnd115         : 1;
  __REG32 IntPnd116         : 1;
  __REG32 IntPnd117         : 1;
  __REG32 IntPnd118         : 1;
  __REG32 IntPnd119         : 1;
  __REG32 IntPnd120         : 1;
  __REG32 IntPnd121         : 1;
  __REG32 IntPnd122         : 1;
  __REG32 IntPnd123         : 1;
  __REG32 IntPnd124         : 1;
  __REG32 IntPnd125         : 1;
  __REG32 IntPnd126         : 1;
  __REG32 IntPnd127         : 1;
  __REG32 IntPnd128         : 1;
} __dcanintpnd78_bits;

/* CAN Message Valid X Register (DCAN MSGVAL X) */
typedef struct {
  __REG32 MsgValReg1          : 2;
  __REG32 MsgValReg2          : 2;
  __REG32 MsgValReg3          : 2;
  __REG32 MsgValReg4          : 2;
  __REG32 MsgValReg5          : 2;
  __REG32 MsgValReg6          : 2;
  __REG32 MsgValReg7          : 2;
  __REG32 MsgValReg8          : 2;
  __REG32                     :16;
} __dcanmsgvalx_bits;

/* CAN Message Valid Registers (DCAN MSGVAL12) */
typedef struct {
  __REG32 MsgVal1           : 1;
  __REG32 MsgVal2           : 1;
  __REG32 MsgVal3           : 1;
  __REG32 MsgVal4           : 1;
  __REG32 MsgVal5           : 1;
  __REG32 MsgVal6           : 1;
  __REG32 MsgVal7           : 1;
  __REG32 MsgVal8           : 1;
  __REG32 MsgVal9           : 1;
  __REG32 MsgVal10          : 1;
  __REG32 MsgVal11          : 1;
  __REG32 MsgVal12          : 1;
  __REG32 MsgVal13          : 1;
  __REG32 MsgVal14          : 1;
  __REG32 MsgVal15          : 1;
  __REG32 MsgVal16          : 1;
  __REG32 MsgVal17          : 1;
  __REG32 MsgVal18          : 1;
  __REG32 MsgVal19          : 1;
  __REG32 MsgVal20          : 1;
  __REG32 MsgVal21          : 1;
  __REG32 MsgVal22          : 1;
  __REG32 MsgVal23          : 1;
  __REG32 MsgVal24          : 1;
  __REG32 MsgVal25          : 1;
  __REG32 MsgVal26          : 1;
  __REG32 MsgVal27          : 1;
  __REG32 MsgVal28          : 1;
  __REG32 MsgVal29          : 1;
  __REG32 MsgVal30          : 1;
  __REG32 MsgVal31          : 1;
  __REG32 MsgVal32          : 1;
} __dcanmsgval12_bits;

/* CAN Message Valid Registers (DCAN MSGVAL34) */
typedef struct {
  __REG32 MsgVal33          : 1;
  __REG32 MsgVal34          : 1;
  __REG32 MsgVal35          : 1;
  __REG32 MsgVal36          : 1;
  __REG32 MsgVal37          : 1;
  __REG32 MsgVal38          : 1;
  __REG32 MsgVal39          : 1;
  __REG32 MsgVal40          : 1;
  __REG32 MsgVal41          : 1;
  __REG32 MsgVal42          : 1;
  __REG32 MsgVal43          : 1;
  __REG32 MsgVal44          : 1;
  __REG32 MsgVal45          : 1;
  __REG32 MsgVal46          : 1;
  __REG32 MsgVal47          : 1;
  __REG32 MsgVal48          : 1;
  __REG32 MsgVal49          : 1;
  __REG32 MsgVal50          : 1;
  __REG32 MsgVal51          : 1;
  __REG32 MsgVal52          : 1;
  __REG32 MsgVal53          : 1;
  __REG32 MsgVal54          : 1;
  __REG32 MsgVal55          : 1;
  __REG32 MsgVal56          : 1;
  __REG32 MsgVal57          : 1;
  __REG32 MsgVal58          : 1;
  __REG32 MsgVal59          : 1;
  __REG32 MsgVal60          : 1;
  __REG32 MsgVal61          : 1;
  __REG32 MsgVal62          : 1;
  __REG32 MsgVal63          : 1;
  __REG32 MsgVal64          : 1;
} __dcanmsgval34_bits;

/* CAN Message Valid Registers (DCAN MSGVAL56) */
typedef struct {
  __REG32 MsgVal65          : 1;
  __REG32 MsgVal66          : 1;
  __REG32 MsgVal67          : 1;
  __REG32 MsgVal68          : 1;
  __REG32 MsgVal69          : 1;
  __REG32 MsgVal70          : 1;
  __REG32 MsgVal71          : 1;
  __REG32 MsgVal72          : 1;
  __REG32 MsgVal73          : 1;
  __REG32 MsgVal74          : 1;
  __REG32 MsgVal75          : 1;
  __REG32 MsgVal76          : 1;
  __REG32 MsgVal77          : 1;
  __REG32 MsgVal78          : 1;
  __REG32 MsgVal79          : 1;
  __REG32 MsgVal80          : 1;
  __REG32 MsgVal81          : 1;
  __REG32 MsgVal82          : 1;
  __REG32 MsgVal83          : 1;
  __REG32 MsgVal84          : 1;
  __REG32 MsgVal85          : 1;
  __REG32 MsgVal86          : 1;
  __REG32 MsgVal87          : 1;
  __REG32 MsgVal88          : 1;
  __REG32 MsgVal89          : 1;
  __REG32 MsgVal90          : 1;
  __REG32 MsgVal91          : 1;
  __REG32 MsgVal92          : 1;
  __REG32 MsgVal93          : 1;
  __REG32 MsgVal94          : 1;
  __REG32 MsgVal95          : 1;
  __REG32 MsgVal96          : 1;
} __dcanmsgval56_bits;

/* CAN Message Valid Registers (DCAN MSGVAL78) */
typedef struct {
  __REG32 MsgVal97          : 1;
  __REG32 MsgVal98          : 1;
  __REG32 MsgVal99          : 1;
  __REG32 MsgVal100         : 1;
  __REG32 MsgVal101         : 1;
  __REG32 MsgVal102         : 1;
  __REG32 MsgVal103         : 1;
  __REG32 MsgVal104         : 1;
  __REG32 MsgVal105         : 1;
  __REG32 MsgVal106         : 1;
  __REG32 MsgVal107         : 1;
  __REG32 MsgVal108         : 1;
  __REG32 MsgVal109         : 1;
  __REG32 MsgVal110         : 1;
  __REG32 MsgVal111         : 1;
  __REG32 MsgVal112         : 1;
  __REG32 MsgVal113         : 1;
  __REG32 MsgVal114         : 1;
  __REG32 MsgVal115         : 1;
  __REG32 MsgVal116         : 1;
  __REG32 MsgVal117         : 1;
  __REG32 MsgVal118         : 1;
  __REG32 MsgVal119         : 1;
  __REG32 MsgVal120         : 1;
  __REG32 MsgVal121         : 1;
  __REG32 MsgVal122         : 1;
  __REG32 MsgVal123         : 1;
  __REG32 MsgVal124         : 1;
  __REG32 MsgVal125         : 1;
  __REG32 MsgVal126         : 1;
  __REG32 MsgVal127         : 1;
  __REG32 MsgVal128         : 1;
} __dcanmsgval78_bits;

/* CAN Interrupt Multiplexer Registers (DCAN INTMUX12) */
typedef struct {
  __REG32 IntMux1           : 1;
  __REG32 IntMux2           : 1;
  __REG32 IntMux3           : 1;
  __REG32 IntMux4           : 1;
  __REG32 IntMux5           : 1;
  __REG32 IntMux6           : 1;
  __REG32 IntMux7           : 1;
  __REG32 IntMux8           : 1;
  __REG32 IntMux9           : 1;
  __REG32 IntMux10          : 1;
  __REG32 IntMux11          : 1;
  __REG32 IntMux12          : 1;
  __REG32 IntMux13          : 1;
  __REG32 IntMux14          : 1;
  __REG32 IntMux15          : 1;
  __REG32 IntMux16          : 1;
  __REG32 IntMux17          : 1;
  __REG32 IntMux18          : 1;
  __REG32 IntMux19          : 1;
  __REG32 IntMux20          : 1;
  __REG32 IntMux21          : 1;
  __REG32 IntMux22          : 1;
  __REG32 IntMux23          : 1;
  __REG32 IntMux24          : 1;
  __REG32 IntMux25          : 1;
  __REG32 IntMux26          : 1;
  __REG32 IntMux27          : 1;
  __REG32 IntMux28          : 1;
  __REG32 IntMux29          : 1;
  __REG32 IntMux30          : 1;
  __REG32 IntMux31          : 1;
  __REG32 IntMux32          : 1;
} __dcanintmux12_bits;

/* CAN Interrupt Multiplexer Registers (DCAN INTMUX34) */
typedef struct {
  __REG32 IntMux33          : 1;
  __REG32 IntMux34          : 1;
  __REG32 IntMux35          : 1;
  __REG32 IntMux36          : 1;
  __REG32 IntMux37          : 1;
  __REG32 IntMux38          : 1;
  __REG32 IntMux39          : 1;
  __REG32 IntMux40          : 1;
  __REG32 IntMux41          : 1;
  __REG32 IntMux42          : 1;
  __REG32 IntMux43          : 1;
  __REG32 IntMux44          : 1;
  __REG32 IntMux45          : 1;
  __REG32 IntMux46          : 1;
  __REG32 IntMux47          : 1;
  __REG32 IntMux48          : 1;
  __REG32 IntMux49          : 1;
  __REG32 IntMux50          : 1;
  __REG32 IntMux51          : 1;
  __REG32 IntMux52          : 1;
  __REG32 IntMux53          : 1;
  __REG32 IntMux54          : 1;
  __REG32 IntMux55          : 1;
  __REG32 IntMux56          : 1;
  __REG32 IntMux57          : 1;
  __REG32 IntMux58          : 1;
  __REG32 IntMux59          : 1;
  __REG32 IntMux60          : 1;
  __REG32 IntMux61          : 1;
  __REG32 IntMux62          : 1;
  __REG32 IntMux63          : 1;
  __REG32 IntMux64          : 1;
} __dcanintmux34_bits;

/* CAN Interrupt Multiplexer Registers (DCAN INTMUX56) */
typedef struct {
  __REG32 IntMux65          : 1;
  __REG32 IntMux66          : 1;
  __REG32 IntMux67          : 1;
  __REG32 IntMux68          : 1;
  __REG32 IntMux69          : 1;
  __REG32 IntMux70          : 1;
  __REG32 IntMux71          : 1;
  __REG32 IntMux72          : 1;
  __REG32 IntMux73          : 1;
  __REG32 IntMux74          : 1;
  __REG32 IntMux75          : 1;
  __REG32 IntMux76          : 1;
  __REG32 IntMux77          : 1;
  __REG32 IntMux78          : 1;
  __REG32 IntMux79          : 1;
  __REG32 IntMux80          : 1;
  __REG32 IntMux81          : 1;
  __REG32 IntMux82          : 1;
  __REG32 IntMux83          : 1;
  __REG32 IntMux84          : 1;
  __REG32 IntMux85          : 1;
  __REG32 IntMux86          : 1;
  __REG32 IntMux87          : 1;
  __REG32 IntMux88          : 1;
  __REG32 IntMux89          : 1;
  __REG32 IntMux90          : 1;
  __REG32 IntMux91          : 1;
  __REG32 IntMux92          : 1;
  __REG32 IntMux93          : 1;
  __REG32 IntMux94          : 1;
  __REG32 IntMux95          : 1;
  __REG32 IntMux96          : 1;
} __dcanintmux56_bits;

/* CAN Interrupt Multiplexer Registers (DCAN INTMUX78) */
typedef struct {
  __REG32 IntMux97          : 1;
  __REG32 IntMux98          : 1;
  __REG32 IntMux99          : 1;
  __REG32 IntMux100         : 1;
  __REG32 IntMux101         : 1;
  __REG32 IntMux102         : 1;
  __REG32 IntMux103         : 1;
  __REG32 IntMux104         : 1;
  __REG32 IntMux105         : 1;
  __REG32 IntMux106         : 1;
  __REG32 IntMux107         : 1;
  __REG32 IntMux108         : 1;
  __REG32 IntMux109         : 1;
  __REG32 IntMux110         : 1;
  __REG32 IntMux111         : 1;
  __REG32 IntMux112         : 1;
  __REG32 IntMux113         : 1;
  __REG32 IntMux114         : 1;
  __REG32 IntMux115         : 1;
  __REG32 IntMux116         : 1;
  __REG32 IntMux117         : 1;
  __REG32 IntMux118         : 1;
  __REG32 IntMux119         : 1;
  __REG32 IntMux120         : 1;
  __REG32 IntMux121         : 1;
  __REG32 IntMux122         : 1;
  __REG32 IntMux123         : 1;
  __REG32 IntMux124         : 1;
  __REG32 IntMux125         : 1;
  __REG32 IntMux126         : 1;
  __REG32 IntMux127         : 1;
  __REG32 IntMux128         : 1;
} __dcanintmux78_bits;

/* CAN IF1/2 Command Registers (DCAN IF1/2CMD) */
typedef struct {
  __REG32 MessageNumber       : 8;
  __REG32                     : 6;
  __REG32 DMAactive           : 1;
  __REG32 Busy                : 1;
  __REG32 DataB               : 1;
  __REG32 DataA               : 1;
  __REG32 TxRqst_NewDat       : 1;
  __REG32 ClrIntPnd           : 1;
  __REG32 Control             : 1;
  __REG32 Arb                 : 1;
  __REG32 Mask                : 1;
  __REG32 WR_RD               : 1;
  __REG32                     : 8;
} __dcanifcmd_bits;

/* CAN IF1/IF2/IF2 Mask Registers (DCAN IF1MSK, DCAN IF2MSK, DCAN IF3MSK) */
typedef struct {
  __REG32 Msk0                : 1;
  __REG32 Msk1                : 1;
  __REG32 Msk2                : 1;
  __REG32 Msk3                : 1;
  __REG32 Msk4                : 1;
  __REG32 Msk5                : 1;
  __REG32 Msk6                : 1;
  __REG32 Msk7                : 1;
  __REG32 Msk8                : 1;
  __REG32 Msk9                : 1;
  __REG32 Msk10               : 1;
  __REG32 Msk11               : 1;
  __REG32 Msk12               : 1;
  __REG32 Msk13               : 1;
  __REG32 Msk14               : 1;
  __REG32 Msk15               : 1;
  __REG32 Msk16               : 1;
  __REG32 Msk17               : 1;
  __REG32 Msk18               : 1;
  __REG32 Msk19               : 1;
  __REG32 Msk20               : 1;
  __REG32 Msk21               : 1;
  __REG32 Msk22               : 1;
  __REG32 Msk23               : 1;
  __REG32 Msk24               : 1;
  __REG32 Msk25               : 1;
  __REG32 Msk26               : 1;
  __REG32 Msk27               : 1;
  __REG32 Msk28               : 1;
  __REG32                     : 1;
  __REG32 MDir                : 1;
  __REG32 MXtd                : 1;
} __dcanifmsk_bits;

/* CAN IF1/IF2/IF3 Arbitration Registers (DCAN IF1ARB, DCAN IF2ARB, DCAN IF3ARB) */
typedef struct {
  __REG32 ID0                 : 1;
  __REG32 ID1                 : 1;
  __REG32 ID2                 : 1;
  __REG32 ID3                 : 1;
  __REG32 ID4                 : 1;
  __REG32 ID5                 : 1;
  __REG32 ID6                 : 1;
  __REG32 ID7                 : 1;
  __REG32 ID8                 : 1;
  __REG32 ID9                 : 1;
  __REG32 ID10                : 1;
  __REG32 ID11                : 1;
  __REG32 ID12                : 1;
  __REG32 ID13                : 1;
  __REG32 ID14                : 1;
  __REG32 ID15                : 1;
  __REG32 ID16                : 1;
  __REG32 ID17                : 1;
  __REG32 ID18                : 1;
  __REG32 ID19                : 1;
  __REG32 ID20                : 1;
  __REG32 ID21                : 1;
  __REG32 ID22                : 1;
  __REG32 ID23                : 1;
  __REG32 ID24                : 1;
  __REG32 ID25                : 1;
  __REG32 ID26                : 1;
  __REG32 ID27                : 1;
  __REG32 ID28                : 1;
  __REG32 Dir                 : 1;
  __REG32 Xtd                 : 1;
  __REG32 MsgVal              : 1;
} __dcanifarb_bits;

/* CAN IF1/IF2/IF3 Message Control Registers (DCAN IF1MCTL, DCAN IF2MCTL, DCAN IF3MCTL) */
typedef struct {
  __REG32 DLC                 : 4;
  __REG32                     : 3;
  __REG32 EoB                 : 1;
  __REG32 TxRqst              : 1;
  __REG32 RmtEn               : 1;
  __REG32 RxIE                : 1;
  __REG32 TxIE                : 1;
  __REG32 UMask               : 1;
  __REG32 IntPnd              : 1;
  __REG32 MsgLst              : 1;
  __REG32 NewDat              : 1;
  __REG32                     :16;
} __dcanifmctl_bits;

/* CAN IF1/2/3 Data A Register (DCAN IF1/2/3DATA) */
typedef struct {
  __REG32 Data0               : 8;
  __REG32 Data1               : 8;
  __REG32 Data2               : 8;
  __REG32 Data3               : 8;
} __dcanifdata_bits;

/* CAN IF1/2/3 Data B Register (DCAN IF1/2/3DATB) */
typedef struct {
  __REG32 Data4               : 8;
  __REG32 Data5               : 8;
  __REG32 Data6               : 8;
  __REG32 Data7               : 8;
} __dcanifdatb_bits;

/* CAN IF3 Observation Register (DCAN IF3OBS) */
typedef struct {
  __REG32 Mask                : 1;
  __REG32 Arb                 : 1;
  __REG32 Ctrl                : 1;
  __REG32 DataA               : 1;
  __REG32 DataB               : 1;
  __REG32                     : 3;
  __REG32 IF3_SM              : 1;
  __REG32 IF3_SA              : 1;
  __REG32 IF3_SC              : 1;
  __REG32 IF3_SDA             : 1;
  __REG32 IF3_SDB             : 1;
  __REG32                     : 2;
  __REG32 IF3_Upd             : 1;
  __REG32                     :16;
} __dcanif3obs_bits;

/* CAN IF3 Update Enable Registers (DCAN IF3UPD12) */
typedef struct {
  __REG32 IF3UpdEn1           : 1;
  __REG32 IF3UpdEn2           : 1;
  __REG32 IF3UpdEn3           : 1;
  __REG32 IF3UpdEn4           : 1;
  __REG32 IF3UpdEn5           : 1;
  __REG32 IF3UpdEn6           : 1;
  __REG32 IF3UpdEn7           : 1;
  __REG32 IF3UpdEn8           : 1;
  __REG32 IF3UpdEn9           : 1;
  __REG32 IF3UpdEn10          : 1;
  __REG32 IF3UpdEn11          : 1;
  __REG32 IF3UpdEn12          : 1;
  __REG32 IF3UpdEn13          : 1;
  __REG32 IF3UpdEn14          : 1;
  __REG32 IF3UpdEn15          : 1;
  __REG32 IF3UpdEn16          : 1;
  __REG32 IF3UpdEn17          : 1;
  __REG32 IF3UpdEn18          : 1;
  __REG32 IF3UpdEn19          : 1;
  __REG32 IF3UpdEn20          : 1;
  __REG32 IF3UpdEn21          : 1;
  __REG32 IF3UpdEn22          : 1;
  __REG32 IF3UpdEn23          : 1;
  __REG32 IF3UpdEn24          : 1;
  __REG32 IF3UpdEn25          : 1;
  __REG32 IF3UpdEn26          : 1;
  __REG32 IF3UpdEn27          : 1;
  __REG32 IF3UpdEn28          : 1;
  __REG32 IF3UpdEn29          : 1;
  __REG32 IF3UpdEn30          : 1;
  __REG32 IF3UpdEn31          : 1;
  __REG32 IF3UpdEn32          : 1;
} __dcanif3upd12_bits;

/* CAN IF3 Update Enable Registers (DCAN IF3UPD34) */
typedef struct {
  __REG32 IF3UpdEn33          : 1;
  __REG32 IF3UpdEn34          : 1;
  __REG32 IF3UpdEn35          : 1;
  __REG32 IF3UpdEn36          : 1;
  __REG32 IF3UpdEn37          : 1;
  __REG32 IF3UpdEn38          : 1;
  __REG32 IF3UpdEn39          : 1;
  __REG32 IF3UpdEn40          : 1;
  __REG32 IF3UpdEn41          : 1;
  __REG32 IF3UpdEn42          : 1;
  __REG32 IF3UpdEn43          : 1;
  __REG32 IF3UpdEn44          : 1;
  __REG32 IF3UpdEn45          : 1;
  __REG32 IF3UpdEn46          : 1;
  __REG32 IF3UpdEn47          : 1;
  __REG32 IF3UpdEn48          : 1;
  __REG32 IF3UpdEn49          : 1;
  __REG32 IF3UpdEn50          : 1;
  __REG32 IF3UpdEn51          : 1;
  __REG32 IF3UpdEn52          : 1;
  __REG32 IF3UpdEn53          : 1;
  __REG32 IF3UpdEn54          : 1;
  __REG32 IF3UpdEn55          : 1;
  __REG32 IF3UpdEn56          : 1;
  __REG32 IF3UpdEn57          : 1;
  __REG32 IF3UpdEn58          : 1;
  __REG32 IF3UpdEn59          : 1;
  __REG32 IF3UpdEn60          : 1;
  __REG32 IF3UpdEn61          : 1;
  __REG32 IF3UpdEn62          : 1;
  __REG32 IF3UpdEn63          : 1;
  __REG32 IF3UpdEn64          : 1;
} __dcanif3upd34_bits;

/* CAN IF3 Update Enable Registers (DCAN IF3UPD56) */
typedef struct {
  __REG32 IF3UpdEn65          : 1;
  __REG32 IF3UpdEn66          : 1;
  __REG32 IF3UpdEn67          : 1;
  __REG32 IF3UpdEn68          : 1;
  __REG32 IF3UpdEn69          : 1;
  __REG32 IF3UpdEn70          : 1;
  __REG32 IF3UpdEn71          : 1;
  __REG32 IF3UpdEn72          : 1;
  __REG32 IF3UpdEn73          : 1;
  __REG32 IF3UpdEn74          : 1;
  __REG32 IF3UpdEn75          : 1;
  __REG32 IF3UpdEn76          : 1;
  __REG32 IF3UpdEn77          : 1;
  __REG32 IF3UpdEn78          : 1;
  __REG32 IF3UpdEn79          : 1;
  __REG32 IF3UpdEn80          : 1;
  __REG32 IF3UpdEn81          : 1;
  __REG32 IF3UpdEn82          : 1;
  __REG32 IF3UpdEn83          : 1;
  __REG32 IF3UpdEn84          : 1;
  __REG32 IF3UpdEn85          : 1;
  __REG32 IF3UpdEn86          : 1;
  __REG32 IF3UpdEn87          : 1;
  __REG32 IF3UpdEn88          : 1;
  __REG32 IF3UpdEn89          : 1;
  __REG32 IF3UpdEn90          : 1;
  __REG32 IF3UpdEn91          : 1;
  __REG32 IF3UpdEn92          : 1;
  __REG32 IF3UpdEn93          : 1;
  __REG32 IF3UpdEn94          : 1;
  __REG32 IF3UpdEn95          : 1;
  __REG32 IF3UpdEn96          : 1;
} __dcanif3upd56_bits;

/* CAN IF3 Update Enable Registers (DCAN IF3UPD78) */
typedef struct {
  __REG32 IF3UpdEn97          : 1;
  __REG32 IF3UpdEn98          : 1;
  __REG32 IF3UpdEn99          : 1;
  __REG32 IF3UpdEn100         : 1;
  __REG32 IF3UpdEn101         : 1;
  __REG32 IF3UpdEn102         : 1;
  __REG32 IF3UpdEn103         : 1;
  __REG32 IF3UpdEn104         : 1;
  __REG32 IF3UpdEn105         : 1;
  __REG32 IF3UpdEn106         : 1;
  __REG32 IF3UpdEn107         : 1;
  __REG32 IF3UpdEn108         : 1;
  __REG32 IF3UpdEn109         : 1;
  __REG32 IF3UpdEn110         : 1;
  __REG32 IF3UpdEn111         : 1;
  __REG32 IF3UpdEn112         : 1;
  __REG32 IF3UpdEn113         : 1;
  __REG32 IF3UpdEn114         : 1;
  __REG32 IF3UpdEn115         : 1;
  __REG32 IF3UpdEn116         : 1;
  __REG32 IF3UpdEn117         : 1;
  __REG32 IF3UpdEn118         : 1;
  __REG32 IF3UpdEn119         : 1;
  __REG32 IF3UpdEn120         : 1;
  __REG32 IF3UpdEn121         : 1;
  __REG32 IF3UpdEn122         : 1;
  __REG32 IF3UpdEn123         : 1;
  __REG32 IF3UpdEn124         : 1;
  __REG32 IF3UpdEn125         : 1;
  __REG32 IF3UpdEn126         : 1;
  __REG32 IF3UpdEn127         : 1;
  __REG32 IF3UpdEn128         : 1;
} __dcanif3upd78_bits;

/* CAN TX IO Control Register (DCAN TIOC) */
typedef struct {
  __REG32 In                  : 1;
  __REG32 Out                 : 1;
  __REG32 Dir                 : 1;
  __REG32 Func                : 1;
  __REG32                     :12;
  __REG32 OD                  : 1;
  __REG32 PD                  : 1;
  __REG32 PU                  : 1;
  __REG32                     :13;
} __dcantioc_bits;

/* FTU Global Control Set/Reset (GCS/R) */
typedef struct {
  __REG32 TUE                 : 1;
  __REG32 TUH                 : 1;
  __REG32                     : 2;
  __REG32 EILE                : 1;
  __REG32 SILE                : 1;
  __REG32                     : 2;
  __REG32 ETSM                : 1;
  __REG32                     : 3;
  __REG32 CTTSM               : 1;
  __REG32 CTTCC               : 1;
  __REG32 CETESM              : 1;
  __REG32                     : 1;
  __REG32 PEL                 : 4;
  __REG32 PEFT                : 1;
  __REG32 PRIO                : 1;
  __REG32                     : 2;
  __REG32 ENDP                : 2;
  __REG32 ENDH                : 2;
  __REG32 ENDR                : 2;
  __REG32 ENDVBS              : 1;
  __REG32 ENDVBM              : 1;
} __ftugcs_bits;

/* FTU Transfer Status Current Buffer (TSCB) */
typedef struct {
  __REG32 BN                  : 7;
  __REG32                     : 1;
  __REG32 IDLE                : 1;
  __REG32                     : 3;
  __REG32 STUH                : 1;
  __REG32                     : 3;
  __REG32 TSMS                : 5;
  __REG32                     :11;
} __ftutscb_bits;

/* FTU Last Transferred Buffer to Communication Controller (LTBCC) */
typedef struct {
  __REG32 BN                  : 7;
  __REG32                     :25;
} __ftultbcc_bits;

/* FTU Transfer to System Memory Occurred 1(TSMO1) */
typedef struct {
  __REG32 TSMO0              : 1;
  __REG32 TSMO1              : 1;
  __REG32 TSMO2              : 1;
  __REG32 TSMO3              : 1;
  __REG32 TSMO4              : 1;
  __REG32 TSMO5              : 1;
  __REG32 TSMO6              : 1;
  __REG32 TSMO7              : 1;
  __REG32 TSMO8              : 1;
  __REG32 TSMO9              : 1;
  __REG32 TSMO10             : 1;
  __REG32 TSMO11             : 1;
  __REG32 TSMO12             : 1;
  __REG32 TSMO13             : 1;
  __REG32 TSMO14             : 1;
  __REG32 TSMO15             : 1;
  __REG32 TSMO16             : 1;
  __REG32 TSMO17             : 1;
  __REG32 TSMO18             : 1;
  __REG32 TSMO19             : 1;
  __REG32 TSMO20             : 1;
  __REG32 TSMO21             : 1;
  __REG32 TSMO22             : 1;
  __REG32 TSMO23             : 1;
  __REG32 TSMO24             : 1;
  __REG32 TSMO25             : 1;
  __REG32 TSMO26             : 1;
  __REG32 TSMO27             : 1;
  __REG32 TSMO28             : 1;
  __REG32 TSMO29             : 1;
  __REG32 TSMO30             : 1;
  __REG32 TSMO31             : 1;
} __ftutsmo1_bits;

/* FTU Transfer to System Memory Occurred 2(TSMO2) */
typedef struct {
  __REG32 TSMO32             : 1;
  __REG32 TSMO33             : 1;
  __REG32 TSMO34             : 1;
  __REG32 TSMO35             : 1;
  __REG32 TSMO36             : 1;
  __REG32 TSMO37             : 1;
  __REG32 TSMO38             : 1;
  __REG32 TSMO39             : 1;
  __REG32 TSMO40             : 1;
  __REG32 TSMO41             : 1;
  __REG32 TSMO42             : 1;
  __REG32 TSMO43             : 1;
  __REG32 TSMO44             : 1;
  __REG32 TSMO45             : 1;
  __REG32 TSMO46             : 1;
  __REG32 TSMO47             : 1;
  __REG32 TSMO48             : 1;
  __REG32 TSMO49             : 1;
  __REG32 TSMO50             : 1;
  __REG32 TSMO51             : 1;
  __REG32 TSMO52             : 1;
  __REG32 TSMO53             : 1;
  __REG32 TSMO54             : 1;
  __REG32 TSMO55             : 1;
  __REG32 TSMO56             : 1;
  __REG32 TSMO57             : 1;
  __REG32 TSMO58             : 1;
  __REG32 TSMO59             : 1;
  __REG32 TSMO60             : 1;
  __REG32 TSMO61             : 1;
  __REG32 TSMO62             : 1;
  __REG32 TSMO63             : 1;
} __ftutsmo2_bits;

/* FTU Transfer to System Memory Occurred 3(TSMO3) */
typedef struct {
  __REG32 TSMO64             : 1;
  __REG32 TSMO65             : 1;
  __REG32 TSMO66             : 1;
  __REG32 TSMO67             : 1;
  __REG32 TSMO68             : 1;
  __REG32 TSMO69             : 1;
  __REG32 TSMO70             : 1;
  __REG32 TSMO71             : 1;
  __REG32 TSMO72             : 1;
  __REG32 TSMO73             : 1;
  __REG32 TSMO74             : 1;
  __REG32 TSMO75             : 1;
  __REG32 TSMO76             : 1;
  __REG32 TSMO77             : 1;
  __REG32 TSMO78             : 1;
  __REG32 TSMO79             : 1;
  __REG32 TSMO80             : 1;
  __REG32 TSMO81             : 1;
  __REG32 TSMO82             : 1;
  __REG32 TSMO83             : 1;
  __REG32 TSMO84             : 1;
  __REG32 TSMO85             : 1;
  __REG32 TSMO86             : 1;
  __REG32 TSMO87             : 1;
  __REG32 TSMO88             : 1;
  __REG32 TSMO89             : 1;
  __REG32 TSMO90             : 1;
  __REG32 TSMO91             : 1;
  __REG32 TSMO92             : 1;
  __REG32 TSMO93             : 1;
  __REG32 TSMO94             : 1;
  __REG32 TSMO95             : 1;
} __ftutsmo3_bits;

/* FTU Transfer to System Memory Occurred 4(TSMO4) */
typedef struct {
  __REG32 TSMO96             : 1;
  __REG32 TSMO97             : 1;
  __REG32 TSMO98             : 1;
  __REG32 TSMO99             : 1;
  __REG32 TSMO100            : 1;
  __REG32 TSMO101            : 1;
  __REG32 TSMO102            : 1;
  __REG32 TSMO103            : 1;
  __REG32 TSMO104            : 1;
  __REG32 TSMO105            : 1;
  __REG32 TSMO106            : 1;
  __REG32 TSMO107            : 1;
  __REG32 TSMO108            : 1;
  __REG32 TSMO109            : 1;
  __REG32 TSMO110            : 1;
  __REG32 TSMO111            : 1;
  __REG32 TSMO112            : 1;
  __REG32 TSMO113            : 1;
  __REG32 TSMO114            : 1;
  __REG32 TSMO115            : 1;
  __REG32 TSMO116            : 1;
  __REG32 TSMO117            : 1;
  __REG32 TSMO118            : 1;
  __REG32 TSMO119            : 1;
  __REG32 TSMO120            : 1;
  __REG32 TSMO121            : 1;
  __REG32 TSMO122            : 1;
  __REG32 TSMO123            : 1;
  __REG32 TSMO124            : 1;
  __REG32 TSMO125            : 1;
  __REG32 TSMO126            : 1;
  __REG32 TSMO127            : 1;
} __ftutsmo4_bits;

/* FTU Transfer to Communication Controller Occurred 1(TCCO1) */
typedef struct {
  __REG32 TCCO0              : 1;
  __REG32 TCCO1              : 1;
  __REG32 TCCO2              : 1;
  __REG32 TCCO3              : 1;
  __REG32 TCCO4              : 1;
  __REG32 TCCO5              : 1;
  __REG32 TCCO6              : 1;
  __REG32 TCCO7              : 1;
  __REG32 TCCO8              : 1;
  __REG32 TCCO9              : 1;
  __REG32 TCCO10             : 1;
  __REG32 TCCO11             : 1;
  __REG32 TCCO12             : 1;
  __REG32 TCCO13             : 1;
  __REG32 TCCO14             : 1;
  __REG32 TCCO15             : 1;
  __REG32 TCCO16             : 1;
  __REG32 TCCO17             : 1;
  __REG32 TCCO18             : 1;
  __REG32 TCCO19             : 1;
  __REG32 TCCO20             : 1;
  __REG32 TCCO21             : 1;
  __REG32 TCCO22             : 1;
  __REG32 TCCO23             : 1;
  __REG32 TCCO24             : 1;
  __REG32 TCCO25             : 1;
  __REG32 TCCO26             : 1;
  __REG32 TCCO27             : 1;
  __REG32 TCCO28             : 1;
  __REG32 TCCO29             : 1;
  __REG32 TCCO30             : 1;
  __REG32 TCCO31             : 1;
} __ftutcco1_bits;

/* FTU Transfer to Communication Controller Occurred 2(TCCO2) */
typedef struct {
  __REG32 TCCO32             : 1;
  __REG32 TCCO33             : 1;
  __REG32 TCCO34             : 1;
  __REG32 TCCO35             : 1;
  __REG32 TCCO36             : 1;
  __REG32 TCCO37             : 1;
  __REG32 TCCO38             : 1;
  __REG32 TCCO39             : 1;
  __REG32 TCCO40             : 1;
  __REG32 TCCO41             : 1;
  __REG32 TCCO42             : 1;
  __REG32 TCCO43             : 1;
  __REG32 TCCO44             : 1;
  __REG32 TCCO45             : 1;
  __REG32 TCCO46             : 1;
  __REG32 TCCO47             : 1;
  __REG32 TCCO48             : 1;
  __REG32 TCCO49             : 1;
  __REG32 TCCO50             : 1;
  __REG32 TCCO51             : 1;
  __REG32 TCCO52             : 1;
  __REG32 TCCO53             : 1;
  __REG32 TCCO54             : 1;
  __REG32 TCCO55             : 1;
  __REG32 TCCO56             : 1;
  __REG32 TCCO57             : 1;
  __REG32 TCCO58             : 1;
  __REG32 TCCO59             : 1;
  __REG32 TCCO60             : 1;
  __REG32 TCCO61             : 1;
  __REG32 TCCO62             : 1;
  __REG32 TCCO63             : 1;
} __ftutcco2_bits;

/* FTU Transfer to Communication Controller Occurred 3(TCCO3) */
typedef struct {
  __REG32 TCCO64             : 1;
  __REG32 TCCO65             : 1;
  __REG32 TCCO66             : 1;
  __REG32 TCCO67             : 1;
  __REG32 TCCO68             : 1;
  __REG32 TCCO69             : 1;
  __REG32 TCCO70             : 1;
  __REG32 TCCO71             : 1;
  __REG32 TCCO72             : 1;
  __REG32 TCCO73             : 1;
  __REG32 TCCO74             : 1;
  __REG32 TCCO75             : 1;
  __REG32 TCCO76             : 1;
  __REG32 TCCO77             : 1;
  __REG32 TCCO78             : 1;
  __REG32 TCCO79             : 1;
  __REG32 TCCO80             : 1;
  __REG32 TCCO81             : 1;
  __REG32 TCCO82             : 1;
  __REG32 TCCO83             : 1;
  __REG32 TCCO84             : 1;
  __REG32 TCCO85             : 1;
  __REG32 TCCO86             : 1;
  __REG32 TCCO87             : 1;
  __REG32 TCCO88             : 1;
  __REG32 TCCO89             : 1;
  __REG32 TCCO90             : 1;
  __REG32 TCCO91             : 1;
  __REG32 TCCO92             : 1;
  __REG32 TCCO93             : 1;
  __REG32 TCCO94             : 1;
  __REG32 TCCO95             : 1;
} __ftutcco3_bits;

/* FTU Transfer to Communication Controller Occurred 4(TCCO4) */
typedef struct {
  __REG32 TCCO96             : 1;
  __REG32 TCCO97             : 1;
  __REG32 TCCO98             : 1;
  __REG32 TCCO99             : 1;
  __REG32 TCCO100            : 1;
  __REG32 TCCO101            : 1;
  __REG32 TCCO102            : 1;
  __REG32 TCCO103            : 1;
  __REG32 TCCO104            : 1;
  __REG32 TCCO105            : 1;
  __REG32 TCCO106            : 1;
  __REG32 TCCO107            : 1;
  __REG32 TCCO108            : 1;
  __REG32 TCCO109            : 1;
  __REG32 TCCO110            : 1;
  __REG32 TCCO111            : 1;
  __REG32 TCCO112            : 1;
  __REG32 TCCO113            : 1;
  __REG32 TCCO114            : 1;
  __REG32 TCCO115            : 1;
  __REG32 TCCO116            : 1;
  __REG32 TCCO117            : 1;
  __REG32 TCCO118            : 1;
  __REG32 TCCO119            : 1;
  __REG32 TCCO120            : 1;
  __REG32 TCCO121            : 1;
  __REG32 TCCO122            : 1;
  __REG32 TCCO123            : 1;
  __REG32 TCCO124            : 1;
  __REG32 TCCO125            : 1;
  __REG32 TCCO126            : 1;
  __REG32 TCCO127            : 1;
} __ftutcco4_bits;

/* FTU Transfer Occurred Offset (TOOFF) */
typedef struct {
  __REG32 OFF                : 8;
  __REG32 TDIR               : 1;
  __REG32                    :23;
} __ftutooff_bits;

/* FTU Parity Error Address (PEADR) */
typedef struct {
  __REG32 ADR                : 9;
  __REG32                    :23;
} __ftupeadr_bits;

/* FTU Transfer Error InterRupt (TEIF) */
typedef struct {
  __REG32 FAC                : 1;
  __REG32 TNR                : 1;
  __REG32                    : 2;
  __REG32 WSTAT              : 3;
  __REG32                    : 1;
  __REG32 RSTAT              : 3;
  __REG32                    : 5;
  __REG32 PE                 : 1;
  __REG32 MPV                : 1;
  __REG32                    :14;
} __ftuteif_bits;

/* FTU Transfer Error Interrupt Enable Set/Reset (TEIRES/R) */
typedef struct {
  __REG32 FACE               : 1;
  __REG32 TNRE               : 1;
  __REG32                    : 2;
  __REG32 WSTATE             : 3;
  __REG32                    : 1;
  __REG32 RSTATE             : 3;
  __REG32                    :21;
} __ftuteires_bits;

/* FTU Trigger Transfer to System Memory Set 1(TTSMS1) */
typedef struct {
  __REG32 TTSMS0              : 1;
  __REG32 TTSMS1              : 1;
  __REG32 TTSMS2              : 1;
  __REG32 TTSMS3              : 1;
  __REG32 TTSMS4              : 1;
  __REG32 TTSMS5              : 1;
  __REG32 TTSMS6              : 1;
  __REG32 TTSMS7              : 1;
  __REG32 TTSMS8              : 1;
  __REG32 TTSMS9              : 1;
  __REG32 TTSMS10             : 1;
  __REG32 TTSMS11             : 1;
  __REG32 TTSMS12             : 1;
  __REG32 TTSMS13             : 1;
  __REG32 TTSMS14             : 1;
  __REG32 TTSMS15             : 1;
  __REG32 TTSMS16             : 1;
  __REG32 TTSMS17             : 1;
  __REG32 TTSMS18             : 1;
  __REG32 TTSMS19             : 1;
  __REG32 TTSMS20             : 1;
  __REG32 TTSMS21             : 1;
  __REG32 TTSMS22             : 1;
  __REG32 TTSMS23             : 1;
  __REG32 TTSMS24             : 1;
  __REG32 TTSMS25             : 1;
  __REG32 TTSMS26             : 1;
  __REG32 TTSMS27             : 1;
  __REG32 TTSMS28             : 1;
  __REG32 TTSMS29             : 1;
  __REG32 TTSMS30             : 1;
  __REG32 TTSMS31             : 1;
} __ftuttsms1_bits;

/* FTU Trigger Transfer to System Memory Reset 1 (TTSMR1) */
typedef struct {
  __REG32 TTSMR0              : 1;
  __REG32 TTSMR1              : 1;
  __REG32 TTSMR2              : 1;
  __REG32 TTSMR3              : 1;
  __REG32 TTSMR4              : 1;
  __REG32 TTSMR5              : 1;
  __REG32 TTSMR6              : 1;
  __REG32 TTSMR7              : 1;
  __REG32 TTSMR8              : 1;
  __REG32 TTSMR9              : 1;
  __REG32 TTSMR10             : 1;
  __REG32 TTSMR11             : 1;
  __REG32 TTSMR12             : 1;
  __REG32 TTSMR13             : 1;
  __REG32 TTSMR14             : 1;
  __REG32 TTSMR15             : 1;
  __REG32 TTSMR16             : 1;
  __REG32 TTSMR17             : 1;
  __REG32 TTSMR18             : 1;
  __REG32 TTSMR19             : 1;
  __REG32 TTSMR20             : 1;
  __REG32 TTSMR21             : 1;
  __REG32 TTSMR22             : 1;
  __REG32 TTSMR23             : 1;
  __REG32 TTSMR24             : 1;
  __REG32 TTSMR25             : 1;
  __REG32 TTSMR26             : 1;
  __REG32 TTSMR27             : 1;
  __REG32 TTSMR28             : 1;
  __REG32 TTSMR29             : 1;
  __REG32 TTSMR30             : 1;
  __REG32 TTSMR31             : 1;
} __ftuttsmr1_bits;

/* FTU Trigger Transfer to System Memory Set 2(TTSMS2) */
typedef struct {
  __REG32 TTSMS32             : 1;
  __REG32 TTSMS33             : 1;
  __REG32 TTSMS34             : 1;
  __REG32 TTSMS35             : 1;
  __REG32 TTSMS36             : 1;
  __REG32 TTSMS37             : 1;
  __REG32 TTSMS38             : 1;
  __REG32 TTSMS39             : 1;
  __REG32 TTSMS40             : 1;
  __REG32 TTSMS41             : 1;
  __REG32 TTSMS42             : 1;
  __REG32 TTSMS43             : 1;
  __REG32 TTSMS44             : 1;
  __REG32 TTSMS45             : 1;
  __REG32 TTSMS46             : 1;
  __REG32 TTSMS47             : 1;
  __REG32 TTSMS48             : 1;
  __REG32 TTSMS49             : 1;
  __REG32 TTSMS50             : 1;
  __REG32 TTSMS51             : 1;
  __REG32 TTSMS52             : 1;
  __REG32 TTSMS53             : 1;
  __REG32 TTSMS54             : 1;
  __REG32 TTSMS55             : 1;
  __REG32 TTSMS56             : 1;
  __REG32 TTSMS57             : 1;
  __REG32 TTSMS58             : 1;
  __REG32 TTSMS59             : 1;
  __REG32 TTSMS60             : 1;
  __REG32 TTSMS61             : 1;
  __REG32 TTSMS62             : 1;
  __REG32 TTSMS63             : 1;
} __ftuttsms2_bits;

/* FTU Trigger Transfer to System Memory Reset 2 (TTSMR2) */
typedef struct {
  __REG32 TTSMR32             : 1;
  __REG32 TTSMR33             : 1;
  __REG32 TTSMR34             : 1;
  __REG32 TTSMR35             : 1;
  __REG32 TTSMR36             : 1;
  __REG32 TTSMR37             : 1;
  __REG32 TTSMR38             : 1;
  __REG32 TTSMR39             : 1;
  __REG32 TTSMR40             : 1;
  __REG32 TTSMR41             : 1;
  __REG32 TTSMR42             : 1;
  __REG32 TTSMR43             : 1;
  __REG32 TTSMR44             : 1;
  __REG32 TTSMR45             : 1;
  __REG32 TTSMR46             : 1;
  __REG32 TTSMR47             : 1;
  __REG32 TTSMR48             : 1;
  __REG32 TTSMR49             : 1;
  __REG32 TTSMR50             : 1;
  __REG32 TTSMR51             : 1;
  __REG32 TTSMR52             : 1;
  __REG32 TTSMR53             : 1;
  __REG32 TTSMR54             : 1;
  __REG32 TTSMR55             : 1;
  __REG32 TTSMR56             : 1;
  __REG32 TTSMR57             : 1;
  __REG32 TTSMR58             : 1;
  __REG32 TTSMR59             : 1;
  __REG32 TTSMR60             : 1;
  __REG32 TTSMR61             : 1;
  __REG32 TTSMR62             : 1;
  __REG32 TTSMR63             : 1;
} __ftuttsmr2_bits;

/* FTU Trigger Transfer to System Memory Set 3(TTSMS3) */
typedef struct {
  __REG32 TTSMS64             : 1;
  __REG32 TTSMS65             : 1;
  __REG32 TTSMS66             : 1;
  __REG32 TTSMS67             : 1;
  __REG32 TTSMS68             : 1;
  __REG32 TTSMS69             : 1;
  __REG32 TTSMS70             : 1;
  __REG32 TTSMS71             : 1;
  __REG32 TTSMS72             : 1;
  __REG32 TTSMS73             : 1;
  __REG32 TTSMS74             : 1;
  __REG32 TTSMS75             : 1;
  __REG32 TTSMS76             : 1;
  __REG32 TTSMS77             : 1;
  __REG32 TTSMS78             : 1;
  __REG32 TTSMS79             : 1;
  __REG32 TTSMS80             : 1;
  __REG32 TTSMS81             : 1;
  __REG32 TTSMS82             : 1;
  __REG32 TTSMS83             : 1;
  __REG32 TTSMS84             : 1;
  __REG32 TTSMS85             : 1;
  __REG32 TTSMS86             : 1;
  __REG32 TTSMS87             : 1;
  __REG32 TTSMS88             : 1;
  __REG32 TTSMS89             : 1;
  __REG32 TTSMS90             : 1;
  __REG32 TTSMS91             : 1;
  __REG32 TTSMS92             : 1;
  __REG32 TTSMS93             : 1;
  __REG32 TTSMS94             : 1;
  __REG32 TTSMS95             : 1;
} __ftuttsms3_bits;

/* FTU Trigger Transfer to System Memory Reset 3 (TTSMR3) */
typedef struct {
  __REG32 TTSMR64             : 1;
  __REG32 TTSMR65             : 1;
  __REG32 TTSMR66             : 1;
  __REG32 TTSMR67             : 1;
  __REG32 TTSMR68             : 1;
  __REG32 TTSMR69             : 1;
  __REG32 TTSMR70             : 1;
  __REG32 TTSMR71             : 1;
  __REG32 TTSMR72             : 1;
  __REG32 TTSMR73             : 1;
  __REG32 TTSMR74             : 1;
  __REG32 TTSMR75             : 1;
  __REG32 TTSMR76             : 1;
  __REG32 TTSMR77             : 1;
  __REG32 TTSMR78             : 1;
  __REG32 TTSMR79             : 1;
  __REG32 TTSMR80             : 1;
  __REG32 TTSMR81             : 1;
  __REG32 TTSMR82             : 1;
  __REG32 TTSMR83             : 1;
  __REG32 TTSMR84             : 1;
  __REG32 TTSMR85             : 1;
  __REG32 TTSMR86             : 1;
  __REG32 TTSMR87             : 1;
  __REG32 TTSMR88             : 1;
  __REG32 TTSMR89             : 1;
  __REG32 TTSMR90             : 1;
  __REG32 TTSMR91             : 1;
  __REG32 TTSMR92             : 1;
  __REG32 TTSMR93             : 1;
  __REG32 TTSMR94             : 1;
  __REG32 TTSMR95             : 1;
} __ftuttsmr3_bits;

/* FTU Trigger Transfer to System Memory Set 4(TTSMS4) */
typedef struct {
  __REG32 TTSMS96             : 1;
  __REG32 TTSMS97             : 1;
  __REG32 TTSMS98             : 1;
  __REG32 TTSMS99             : 1;
  __REG32 TTSMS100            : 1;
  __REG32 TTSMS101            : 1;
  __REG32 TTSMS102            : 1;
  __REG32 TTSMS103            : 1;
  __REG32 TTSMS104            : 1;
  __REG32 TTSMS105            : 1;
  __REG32 TTSMS106            : 1;
  __REG32 TTSMS107            : 1;
  __REG32 TTSMS108            : 1;
  __REG32 TTSMS109            : 1;
  __REG32 TTSMS110            : 1;
  __REG32 TTSMS111            : 1;
  __REG32 TTSMS112            : 1;
  __REG32 TTSMS113            : 1;
  __REG32 TTSMS114            : 1;
  __REG32 TTSMS115            : 1;
  __REG32 TTSMS116            : 1;
  __REG32 TTSMS117            : 1;
  __REG32 TTSMS118            : 1;
  __REG32 TTSMS119            : 1;
  __REG32 TTSMS120            : 1;
  __REG32 TTSMS121            : 1;
  __REG32 TTSMS122            : 1;
  __REG32 TTSMS123            : 1;
  __REG32 TTSMS124            : 1;
  __REG32 TTSMS125            : 1;
  __REG32 TTSMS126            : 1;
  __REG32 TTSMS127            : 1;
} __ftuttsms4_bits;

/* FTU Trigger Transfer to System Memory Reset 4 (TTSMR4) */
typedef struct {
  __REG32 TTSMR96             : 1;
  __REG32 TTSMR97             : 1;
  __REG32 TTSMR98             : 1;
  __REG32 TTSMR99             : 1;
  __REG32 TTSMR100            : 1;
  __REG32 TTSMR101            : 1;
  __REG32 TTSMR102            : 1;
  __REG32 TTSMR103            : 1;
  __REG32 TTSMR104            : 1;
  __REG32 TTSMR105            : 1;
  __REG32 TTSMR106            : 1;
  __REG32 TTSMR107            : 1;
  __REG32 TTSMR108            : 1;
  __REG32 TTSMR109            : 1;
  __REG32 TTSMR110            : 1;
  __REG32 TTSMR111            : 1;
  __REG32 TTSMR112            : 1;
  __REG32 TTSMR113            : 1;
  __REG32 TTSMR114            : 1;
  __REG32 TTSMR115            : 1;
  __REG32 TTSMR116            : 1;
  __REG32 TTSMR117            : 1;
  __REG32 TTSMR118            : 1;
  __REG32 TTSMR119            : 1;
  __REG32 TTSMR120            : 1;
  __REG32 TTSMR121            : 1;
  __REG32 TTSMR122            : 1;
  __REG32 TTSMR123            : 1;
  __REG32 TTSMR124            : 1;
  __REG32 TTSMR125            : 1;
  __REG32 TTSMR126            : 1;
  __REG32 TTSMR127            : 1;
} __ftuttsmr4_bits;

/* FTU Trigger Transfer to Communication Controller Set 1(TTCCS1) */
typedef struct {
  __REG32 TTCCS0               : 1;
  __REG32 TTCCS1               : 1;
  __REG32 TTCCS2               : 1;
  __REG32 TTCCS3               : 1;
  __REG32 TTCCS4               : 1;
  __REG32 TTCCS5               : 1;
  __REG32 TTCCS6               : 1;
  __REG32 TTCCS7               : 1;
  __REG32 TTCCS8               : 1;
  __REG32 TTCCS9               : 1;
  __REG32 TTCCS10              : 1;
  __REG32 TTCCS11              : 1;
  __REG32 TTCCS12              : 1;
  __REG32 TTCCS13              : 1;
  __REG32 TTCCS14              : 1;
  __REG32 TTCCS15              : 1;
  __REG32 TTCCS16              : 1;
  __REG32 TTCCS17              : 1;
  __REG32 TTCCS18              : 1;
  __REG32 TTCCS19              : 1;
  __REG32 TTCCS20              : 1;
  __REG32 TTCCS21              : 1;
  __REG32 TTCCS22              : 1;
  __REG32 TTCCS23              : 1;
  __REG32 TTCCS24              : 1;
  __REG32 TTCCS25              : 1;
  __REG32 TTCCS26              : 1;
  __REG32 TTCCS27              : 1;
  __REG32 TTCCS28              : 1;
  __REG32 TTCCS29              : 1;
  __REG32 TTCCS30              : 1;
  __REG32 TTCCS31              : 1;
} __ftuttccs1_bits;

/* FTU Trigger Transfer to Communication Controller Reset 1(TTCCR1) */
typedef struct {
  __REG32 TTCCR0              : 1;
  __REG32 TTCCR1              : 1;
  __REG32 TTCCR2              : 1;
  __REG32 TTCCR3              : 1;
  __REG32 TTCCR4              : 1;
  __REG32 TTCCR5              : 1;
  __REG32 TTCCR6              : 1;
  __REG32 TTCCR7              : 1;
  __REG32 TTCCR8              : 1;
  __REG32 TTCCR9              : 1;
  __REG32 TTCCR10             : 1;
  __REG32 TTCCR11             : 1;
  __REG32 TTCCR12             : 1;
  __REG32 TTCCR13             : 1;
  __REG32 TTCCR14             : 1;
  __REG32 TTCCR15             : 1;
  __REG32 TTCCR16             : 1;
  __REG32 TTCCR17             : 1;
  __REG32 TTCCR18             : 1;
  __REG32 TTCCR19             : 1;
  __REG32 TTCCR20             : 1;
  __REG32 TTCCR21             : 1;
  __REG32 TTCCR22             : 1;
  __REG32 TTCCR23             : 1;
  __REG32 TTCCR24             : 1;
  __REG32 TTCCR25             : 1;
  __REG32 TTCCR26             : 1;
  __REG32 TTCCR27             : 1;
  __REG32 TTCCR28             : 1;
  __REG32 TTCCR29             : 1;
  __REG32 TTCCR30             : 1;
  __REG32 TTCCR31             : 1;
} __ftuttccr1_bits;

/* FTU Trigger Transfer to Communication Controller Set 2(TTCCS2) */
typedef struct {
  __REG32 TTCCS32              : 1;
  __REG32 TTCCS33              : 1;
  __REG32 TTCCS34              : 1;
  __REG32 TTCCS35              : 1;
  __REG32 TTCCS36              : 1;
  __REG32 TTCCS37              : 1;
  __REG32 TTCCS38              : 1;
  __REG32 TTCCS39              : 1;
  __REG32 TTCCS40              : 1;
  __REG32 TTCCS41              : 1;
  __REG32 TTCCS42              : 1;
  __REG32 TTCCS43              : 1;
  __REG32 TTCCS44              : 1;
  __REG32 TTCCS45              : 1;
  __REG32 TTCCS46              : 1;
  __REG32 TTCCS47              : 1;
  __REG32 TTCCS48              : 1;
  __REG32 TTCCS49              : 1;
  __REG32 TTCCS50              : 1;
  __REG32 TTCCS51              : 1;
  __REG32 TTCCS52              : 1;
  __REG32 TTCCS53              : 1;
  __REG32 TTCCS54              : 1;
  __REG32 TTCCS55              : 1;
  __REG32 TTCCS56              : 1;
  __REG32 TTCCS57              : 1;
  __REG32 TTCCS58              : 1;
  __REG32 TTCCS59              : 1;
  __REG32 TTCCS60              : 1;
  __REG32 TTCCS61              : 1;
  __REG32 TTCCS62              : 1;
  __REG32 TTCCS63              : 1;
} __ftuttccs2_bits;

/* FTU Trigger Transfer to Communication Controller Reset 2(TTCCR2) */
typedef struct {
  __REG32 TTCCR32             : 1;
  __REG32 TTCCR33             : 1;
  __REG32 TTCCR34             : 1;
  __REG32 TTCCR35             : 1;
  __REG32 TTCCR36             : 1;
  __REG32 TTCCR37             : 1;
  __REG32 TTCCR38             : 1;
  __REG32 TTCCR39             : 1;
  __REG32 TTCCR40             : 1;
  __REG32 TTCCR41             : 1;
  __REG32 TTCCR42             : 1;
  __REG32 TTCCR43             : 1;
  __REG32 TTCCR44             : 1;
  __REG32 TTCCR45             : 1;
  __REG32 TTCCR46             : 1;
  __REG32 TTCCR47             : 1;
  __REG32 TTCCR48             : 1;
  __REG32 TTCCR49             : 1;
  __REG32 TTCCR50             : 1;
  __REG32 TTCCR51             : 1;
  __REG32 TTCCR52             : 1;
  __REG32 TTCCR53             : 1;
  __REG32 TTCCR54             : 1;
  __REG32 TTCCR55             : 1;
  __REG32 TTCCR56             : 1;
  __REG32 TTCCR57             : 1;
  __REG32 TTCCR58             : 1;
  __REG32 TTCCR59             : 1;
  __REG32 TTCCR60             : 1;
  __REG32 TTCCR61             : 1;
  __REG32 TTCCR62             : 1;
  __REG32 TTCCR63             : 1;
} __ftuttccr2_bits;

/* FTU Trigger Transfer to Communication Controller Set 3(TTCCS3) */
typedef struct {
  __REG32 TTCCS64              : 1;
  __REG32 TTCCS65              : 1;
  __REG32 TTCCS66              : 1;
  __REG32 TTCCS67              : 1;
  __REG32 TTCCS68              : 1;
  __REG32 TTCCS69              : 1;
  __REG32 TTCCS70              : 1;
  __REG32 TTCCS71              : 1;
  __REG32 TTCCS72              : 1;
  __REG32 TTCCS73              : 1;
  __REG32 TTCCS74              : 1;
  __REG32 TTCCS75              : 1;
  __REG32 TTCCS76              : 1;
  __REG32 TTCCS77              : 1;
  __REG32 TTCCS78              : 1;
  __REG32 TTCCS79              : 1;
  __REG32 TTCCS80              : 1;
  __REG32 TTCCS81              : 1;
  __REG32 TTCCS82              : 1;
  __REG32 TTCCS83              : 1;
  __REG32 TTCCS84              : 1;
  __REG32 TTCCS85              : 1;
  __REG32 TTCCS86              : 1;
  __REG32 TTCCS87              : 1;
  __REG32 TTCCS88              : 1;
  __REG32 TTCCS89              : 1;
  __REG32 TTCCS90              : 1;
  __REG32 TTCCS91              : 1;
  __REG32 TTCCS92              : 1;
  __REG32 TTCCS93              : 1;
  __REG32 TTCCS94              : 1;
  __REG32 TTCCS95              : 1;
} __ftuttccs3_bits;

/* FTU Trigger Transfer to Communication Controller Reset 3(TTCCR3) */
typedef struct {
  __REG32 TTCCR64             : 1;
  __REG32 TTCCR65             : 1;
  __REG32 TTCCR66             : 1;
  __REG32 TTCCR67             : 1;
  __REG32 TTCCR68             : 1;
  __REG32 TTCCR69             : 1;
  __REG32 TTCCR70             : 1;
  __REG32 TTCCR71             : 1;
  __REG32 TTCCR72             : 1;
  __REG32 TTCCR73             : 1;
  __REG32 TTCCR74             : 1;
  __REG32 TTCCR75             : 1;
  __REG32 TTCCR76             : 1;
  __REG32 TTCCR77             : 1;
  __REG32 TTCCR78             : 1;
  __REG32 TTCCR79             : 1;
  __REG32 TTCCR80             : 1;
  __REG32 TTCCR81             : 1;
  __REG32 TTCCR82             : 1;
  __REG32 TTCCR83             : 1;
  __REG32 TTCCR84             : 1;
  __REG32 TTCCR85             : 1;
  __REG32 TTCCR86             : 1;
  __REG32 TTCCR87             : 1;
  __REG32 TTCCR88             : 1;
  __REG32 TTCCR89             : 1;
  __REG32 TTCCR90             : 1;
  __REG32 TTCCR91             : 1;
  __REG32 TTCCR92             : 1;
  __REG32 TTCCR93             : 1;
  __REG32 TTCCR94             : 1;
  __REG32 TTCCR95             : 1;
} __ftuttccr3_bits;

/* FTU Trigger Transfer to Communication Controller Set 4(TTCCS4) */
typedef struct {
  __REG32 TTCCS96              : 1;
  __REG32 TTCCS97              : 1;
  __REG32 TTCCS98              : 1;
  __REG32 TTCCS99              : 1;
  __REG32 TTCCS100             : 1;
  __REG32 TTCCS101             : 1;
  __REG32 TTCCS102             : 1;
  __REG32 TTCCS103             : 1;
  __REG32 TTCCS104             : 1;
  __REG32 TTCCS105             : 1;
  __REG32 TTCCS106             : 1;
  __REG32 TTCCS107             : 1;
  __REG32 TTCCS108             : 1;
  __REG32 TTCCS109             : 1;
  __REG32 TTCCS110             : 1;
  __REG32 TTCCS111             : 1;
  __REG32 TTCCS112             : 1;
  __REG32 TTCCS113             : 1;
  __REG32 TTCCS114             : 1;
  __REG32 TTCCS115             : 1;
  __REG32 TTCCS116             : 1;
  __REG32 TTCCS117             : 1;
  __REG32 TTCCS118             : 1;
  __REG32 TTCCS119             : 1;
  __REG32 TTCCS120             : 1;
  __REG32 TTCCS121             : 1;
  __REG32 TTCCS122             : 1;
  __REG32 TTCCS123             : 1;
  __REG32 TTCCS124             : 1;
  __REG32 TTCCS125             : 1;
  __REG32 TTCCS126             : 1;
  __REG32 TTCCS127             : 1;
} __ftuttccs4_bits;

/* FTU Trigger Transfer to Communication Controller Reset 4(TTCCR4) */
typedef struct {
  __REG32 TTCCR96             : 1;
  __REG32 TTCCR97             : 1;
  __REG32 TTCCR98             : 1;
  __REG32 TTCCR99             : 1;
  __REG32 TTCCR100            : 1;
  __REG32 TTCCR101            : 1;
  __REG32 TTCCR102            : 1;
  __REG32 TTCCR103            : 1;
  __REG32 TTCCR104            : 1;
  __REG32 TTCCR105            : 1;
  __REG32 TTCCR106            : 1;
  __REG32 TTCCR107            : 1;
  __REG32 TTCCR108            : 1;
  __REG32 TTCCR109            : 1;
  __REG32 TTCCR110            : 1;
  __REG32 TTCCR111            : 1;
  __REG32 TTCCR112            : 1;
  __REG32 TTCCR113            : 1;
  __REG32 TTCCR114            : 1;
  __REG32 TTCCR115            : 1;
  __REG32 TTCCR116            : 1;
  __REG32 TTCCR117            : 1;
  __REG32 TTCCR118            : 1;
  __REG32 TTCCR119            : 1;
  __REG32 TTCCR120            : 1;
  __REG32 TTCCR121            : 1;
  __REG32 TTCCR122            : 1;
  __REG32 TTCCR123            : 1;
  __REG32 TTCCR124            : 1;
  __REG32 TTCCR125            : 1;
  __REG32 TTCCR126            : 1;
  __REG32 TTCCR127            : 1;
} __ftuttccr4_bits;

/* FTU Enable Transfer on Event to System Memory Set 1(ETESMS1) */
typedef struct {
  __REG32 ETESMS0              : 1;
  __REG32 ETESMS1              : 1;
  __REG32 ETESMS2              : 1;
  __REG32 ETESMS3              : 1;
  __REG32 ETESMS4              : 1;
  __REG32 ETESMS5              : 1;
  __REG32 ETESMS6              : 1;
  __REG32 ETESMS7              : 1;
  __REG32 ETESMS8              : 1;
  __REG32 ETESMS9              : 1;
  __REG32 ETESMS10             : 1;
  __REG32 ETESMS11             : 1;
  __REG32 ETESMS12             : 1;
  __REG32 ETESMS13             : 1;
  __REG32 ETESMS14             : 1;
  __REG32 ETESMS15             : 1;
  __REG32 ETESMS16             : 1;
  __REG32 ETESMS17             : 1;
  __REG32 ETESMS18             : 1;
  __REG32 ETESMS19             : 1;
  __REG32 ETESMS20             : 1;
  __REG32 ETESMS21             : 1;
  __REG32 ETESMS22             : 1;
  __REG32 ETESMS23             : 1;
  __REG32 ETESMS24             : 1;
  __REG32 ETESMS25             : 1;
  __REG32 ETESMS26             : 1;
  __REG32 ETESMS27             : 1;
  __REG32 ETESMS28             : 1;
  __REG32 ETESMS29             : 1;
  __REG32 ETESMS30             : 1;
  __REG32 ETESMS31             : 1;
} __ftuetesms1_bits;

/* FTU Enable Transfer on Event to System Memory Reset 1(ETESMR1) */
typedef struct {
  __REG32 ETESMR0              : 1;
  __REG32 ETESMR1              : 1;
  __REG32 ETESMR2              : 1;
  __REG32 ETESMR3              : 1;
  __REG32 ETESMR4              : 1;
  __REG32 ETESMR5              : 1;
  __REG32 ETESMR6              : 1;
  __REG32 ETESMR7              : 1;
  __REG32 ETESMR8              : 1;
  __REG32 ETESMR9              : 1;
  __REG32 ETESMR10             : 1;
  __REG32 ETESMR11             : 1;
  __REG32 ETESMR12             : 1;
  __REG32 ETESMR13             : 1;
  __REG32 ETESMR14             : 1;
  __REG32 ETESMR15             : 1;
  __REG32 ETESMR16             : 1;
  __REG32 ETESMR17             : 1;
  __REG32 ETESMR18             : 1;
  __REG32 ETESMR19             : 1;
  __REG32 ETESMR20             : 1;
  __REG32 ETESMR21             : 1;
  __REG32 ETESMR22             : 1;
  __REG32 ETESMR23             : 1;
  __REG32 ETESMR24             : 1;
  __REG32 ETESMR25             : 1;
  __REG32 ETESMR26             : 1;
  __REG32 ETESMR27             : 1;
  __REG32 ETESMR28             : 1;
  __REG32 ETESMR29             : 1;
  __REG32 ETESMR30             : 1;
  __REG32 ETESMR31             : 1;
} __ftuetesmr1_bits;

/* FTU Enable Transfer on Event to System Memory Set 2(ETESMS2) */
typedef struct {
  __REG32 ETESMS32             : 1;
  __REG32 ETESMS33             : 1;
  __REG32 ETESMS34             : 1;
  __REG32 ETESMS35             : 1;
  __REG32 ETESMS36             : 1;
  __REG32 ETESMS37             : 1;
  __REG32 ETESMS38             : 1;
  __REG32 ETESMS39             : 1;
  __REG32 ETESMS40             : 1;
  __REG32 ETESMS41             : 1;
  __REG32 ETESMS42             : 1;
  __REG32 ETESMS43             : 1;
  __REG32 ETESMS44             : 1;
  __REG32 ETESMS45             : 1;
  __REG32 ETESMS46             : 1;
  __REG32 ETESMS47             : 1;
  __REG32 ETESMS48             : 1;
  __REG32 ETESMS49             : 1;
  __REG32 ETESMS50             : 1;
  __REG32 ETESMS51             : 1;
  __REG32 ETESMS52             : 1;
  __REG32 ETESMS53             : 1;
  __REG32 ETESMS54             : 1;
  __REG32 ETESMS55             : 1;
  __REG32 ETESMS56             : 1;
  __REG32 ETESMS57             : 1;
  __REG32 ETESMS58             : 1;
  __REG32 ETESMS59             : 1;
  __REG32 ETESMS60             : 1;
  __REG32 ETESMS61             : 1;
  __REG32 ETESMS62             : 1;
  __REG32 ETESMS63             : 1;
} __ftuetesms2_bits;

/* FTU Enable Transfer on Event to System Memory Reset 2(ETESMR2) */
typedef struct {
  __REG32 ETESMR32             : 1;
  __REG32 ETESMR33             : 1;
  __REG32 ETESMR34             : 1;
  __REG32 ETESMR35             : 1;
  __REG32 ETESMR36             : 1;
  __REG32 ETESMR37             : 1;
  __REG32 ETESMR38             : 1;
  __REG32 ETESMR39             : 1;
  __REG32 ETESMR40             : 1;
  __REG32 ETESMR41             : 1;
  __REG32 ETESMR42             : 1;
  __REG32 ETESMR43             : 1;
  __REG32 ETESMR44             : 1;
  __REG32 ETESMR45             : 1;
  __REG32 ETESMR46             : 1;
  __REG32 ETESMR47             : 1;
  __REG32 ETESMR48             : 1;
  __REG32 ETESMR49             : 1;
  __REG32 ETESMR50             : 1;
  __REG32 ETESMR51             : 1;
  __REG32 ETESMR52             : 1;
  __REG32 ETESMR53             : 1;
  __REG32 ETESMR54             : 1;
  __REG32 ETESMR55             : 1;
  __REG32 ETESMR56             : 1;
  __REG32 ETESMR57             : 1;
  __REG32 ETESMR58             : 1;
  __REG32 ETESMR59             : 1;
  __REG32 ETESMR60             : 1;
  __REG32 ETESMR61             : 1;
  __REG32 ETESMR62             : 1;
  __REG32 ETESMR63             : 1;
} __ftuetesmr2_bits;

/* FTU Enable Transfer on Event to System Memory Set 3(ETESMS3) */
typedef struct {
  __REG32 ETESMS64             : 1;
  __REG32 ETESMS65             : 1;
  __REG32 ETESMS66             : 1;
  __REG32 ETESMS67             : 1;
  __REG32 ETESMS68             : 1;
  __REG32 ETESMS69             : 1;
  __REG32 ETESMS70             : 1;
  __REG32 ETESMS71             : 1;
  __REG32 ETESMS72             : 1;
  __REG32 ETESMS73             : 1;
  __REG32 ETESMS74             : 1;
  __REG32 ETESMS75             : 1;
  __REG32 ETESMS76             : 1;
  __REG32 ETESMS77             : 1;
  __REG32 ETESMS78             : 1;
  __REG32 ETESMS79             : 1;
  __REG32 ETESMS80             : 1;
  __REG32 ETESMS81             : 1;
  __REG32 ETESMS82             : 1;
  __REG32 ETESMS83             : 1;
  __REG32 ETESMS84             : 1;
  __REG32 ETESMS85             : 1;
  __REG32 ETESMS86             : 1;
  __REG32 ETESMS87             : 1;
  __REG32 ETESMS88             : 1;
  __REG32 ETESMS89             : 1;
  __REG32 ETESMS90             : 1;
  __REG32 ETESMS91             : 1;
  __REG32 ETESMS92             : 1;
  __REG32 ETESMS93             : 1;
  __REG32 ETESMS94             : 1;
  __REG32 ETESMS95             : 1;
} __ftuetesms3_bits;

/* FTU Enable Transfer on Event to System Memory Reset 3(ETESMR3) */
typedef struct {
  __REG32 ETESMR64             : 1;
  __REG32 ETESMR65             : 1;
  __REG32 ETESMR66             : 1;
  __REG32 ETESMR67             : 1;
  __REG32 ETESMR68             : 1;
  __REG32 ETESMR69             : 1;
  __REG32 ETESMR70             : 1;
  __REG32 ETESMR71             : 1;
  __REG32 ETESMR72             : 1;
  __REG32 ETESMR73             : 1;
  __REG32 ETESMR74             : 1;
  __REG32 ETESMR75             : 1;
  __REG32 ETESMR76             : 1;
  __REG32 ETESMR77             : 1;
  __REG32 ETESMR78             : 1;
  __REG32 ETESMR79             : 1;
  __REG32 ETESMR80             : 1;
  __REG32 ETESMR81             : 1;
  __REG32 ETESMR82             : 1;
  __REG32 ETESMR83             : 1;
  __REG32 ETESMR84             : 1;
  __REG32 ETESMR85             : 1;
  __REG32 ETESMR86             : 1;
  __REG32 ETESMR87             : 1;
  __REG32 ETESMR88             : 1;
  __REG32 ETESMR89             : 1;
  __REG32 ETESMR90             : 1;
  __REG32 ETESMR91             : 1;
  __REG32 ETESMR92             : 1;
  __REG32 ETESMR93             : 1;
  __REG32 ETESMR94             : 1;
  __REG32 ETESMR95             : 1;
} __ftuetesmr3_bits;

/* FTU Enable Transfer on Event to System Memory Set 4(ETESMS4) */
typedef struct {
  __REG32 ETESMS96             : 1;
  __REG32 ETESMS97             : 1;
  __REG32 ETESMS98             : 1;
  __REG32 ETESMS99             : 1;
  __REG32 ETESMS100            : 1;
  __REG32 ETESMS101            : 1;
  __REG32 ETESMS102            : 1;
  __REG32 ETESMS103            : 1;
  __REG32 ETESMS104            : 1;
  __REG32 ETESMS105            : 1;
  __REG32 ETESMS106            : 1;
  __REG32 ETESMS107            : 1;
  __REG32 ETESMS108            : 1;
  __REG32 ETESMS109            : 1;
  __REG32 ETESMS110            : 1;
  __REG32 ETESMS111            : 1;
  __REG32 ETESMS112            : 1;
  __REG32 ETESMS113            : 1;
  __REG32 ETESMS114            : 1;
  __REG32 ETESMS115            : 1;
  __REG32 ETESMS116            : 1;
  __REG32 ETESMS117            : 1;
  __REG32 ETESMS118            : 1;
  __REG32 ETESMS119            : 1;
  __REG32 ETESMS120            : 1;
  __REG32 ETESMS121            : 1;
  __REG32 ETESMS122            : 1;
  __REG32 ETESMS123            : 1;
  __REG32 ETESMS124            : 1;
  __REG32 ETESMS125            : 1;
  __REG32 ETESMS126            : 1;
  __REG32 ETESMS127            : 1;
} __ftuetesms4_bits;

/* FTU Enable Transfer on Event to System Memory Reset 4(ETESMR4) */
typedef struct {
  __REG32 ETESMR96             : 1;
  __REG32 ETESMR97             : 1;
  __REG32 ETESMR98             : 1;
  __REG32 ETESMR99             : 1;
  __REG32 ETESMR100            : 1;
  __REG32 ETESMR101            : 1;
  __REG32 ETESMR102            : 1;
  __REG32 ETESMR103            : 1;
  __REG32 ETESMR104            : 1;
  __REG32 ETESMR105            : 1;
  __REG32 ETESMR106            : 1;
  __REG32 ETESMR107            : 1;
  __REG32 ETESMR108            : 1;
  __REG32 ETESMR109            : 1;
  __REG32 ETESMR110            : 1;
  __REG32 ETESMR111            : 1;
  __REG32 ETESMR112            : 1;
  __REG32 ETESMR113            : 1;
  __REG32 ETESMR114            : 1;
  __REG32 ETESMR115            : 1;
  __REG32 ETESMR116            : 1;
  __REG32 ETESMR117            : 1;
  __REG32 ETESMR118            : 1;
  __REG32 ETESMR119            : 1;
  __REG32 ETESMR120            : 1;
  __REG32 ETESMR121            : 1;
  __REG32 ETESMR122            : 1;
  __REG32 ETESMR123            : 1;
  __REG32 ETESMR124            : 1;
  __REG32 ETESMR125            : 1;
  __REG32 ETESMR126            : 1;
  __REG32 ETESMR127            : 1;
} __ftuetesmr4_bits;

/* FTU Clear on Event to System Memory Set 1(CESMS1) */
typedef struct {
  __REG32 CESMS0              : 1;
  __REG32 CESMS1              : 1;
  __REG32 CESMS2              : 1;
  __REG32 CESMS3              : 1;
  __REG32 CESMS4              : 1;
  __REG32 CESMS5              : 1;
  __REG32 CESMS6              : 1;
  __REG32 CESMS7              : 1;
  __REG32 CESMS8              : 1;
  __REG32 CESMS9              : 1;
  __REG32 CESMS10             : 1;
  __REG32 CESMS11             : 1;
  __REG32 CESMS12             : 1;
  __REG32 CESMS13             : 1;
  __REG32 CESMS14             : 1;
  __REG32 CESMS15             : 1;
  __REG32 CESMS16             : 1;
  __REG32 CESMS17             : 1;
  __REG32 CESMS18             : 1;
  __REG32 CESMS19             : 1;
  __REG32 CESMS20             : 1;
  __REG32 CESMS21             : 1;
  __REG32 CESMS22             : 1;
  __REG32 CESMS23             : 1;
  __REG32 CESMS24             : 1;
  __REG32 CESMS25             : 1;
  __REG32 CESMS26             : 1;
  __REG32 CESMS27             : 1;
  __REG32 CESMS28             : 1;
  __REG32 CESMS29             : 1;
  __REG32 CESMS30             : 1;
  __REG32 CESMS31             : 1;
} __ftucesms1_bits;

/* FTU Clear on Event to System Memory Reset 1(CESMR1) */
typedef struct {
  __REG32 CESMR0              : 1;
  __REG32 CESMR1              : 1;
  __REG32 CESMR2              : 1;
  __REG32 CESMR3              : 1;
  __REG32 CESMR4              : 1;
  __REG32 CESMR5              : 1;
  __REG32 CESMR6              : 1;
  __REG32 CESMR7              : 1;
  __REG32 CESMR8              : 1;
  __REG32 CESMR9              : 1;
  __REG32 CESMR10             : 1;
  __REG32 CESMR11             : 1;
  __REG32 CESMR12             : 1;
  __REG32 CESMR13             : 1;
  __REG32 CESMR14             : 1;
  __REG32 CESMR15             : 1;
  __REG32 CESMR16             : 1;
  __REG32 CESMR17             : 1;
  __REG32 CESMR18             : 1;
  __REG32 CESMR19             : 1;
  __REG32 CESMR20             : 1;
  __REG32 CESMR21             : 1;
  __REG32 CESMR22             : 1;
  __REG32 CESMR23             : 1;
  __REG32 CESMR24             : 1;
  __REG32 CESMR25             : 1;
  __REG32 CESMR26             : 1;
  __REG32 CESMR27             : 1;
  __REG32 CESMR28             : 1;
  __REG32 CESMR29             : 1;
  __REG32 CESMR30             : 1;
  __REG32 CESMR31             : 1;
} __ftucesmr1_bits;

/* FTU Clear on Event to System Memory Set 2(CESMS2) */
typedef struct {
  __REG32 CESMS32             : 1;
  __REG32 CESMS33             : 1;
  __REG32 CESMS34             : 1;
  __REG32 CESMS35             : 1;
  __REG32 CESMS36             : 1;
  __REG32 CESMS37             : 1;
  __REG32 CESMS38             : 1;
  __REG32 CESMS39             : 1;
  __REG32 CESMS40             : 1;
  __REG32 CESMS41             : 1;
  __REG32 CESMS42             : 1;
  __REG32 CESMS43             : 1;
  __REG32 CESMS44             : 1;
  __REG32 CESMS45             : 1;
  __REG32 CESMS46             : 1;
  __REG32 CESMS47             : 1;
  __REG32 CESMS48             : 1;
  __REG32 CESMS49             : 1;
  __REG32 CESMS50             : 1;
  __REG32 CESMS51             : 1;
  __REG32 CESMS52             : 1;
  __REG32 CESMS53             : 1;
  __REG32 CESMS54             : 1;
  __REG32 CESMS55             : 1;
  __REG32 CESMS56             : 1;
  __REG32 CESMS57             : 1;
  __REG32 CESMS58             : 1;
  __REG32 CESMS59             : 1;
  __REG32 CESMS60             : 1;
  __REG32 CESMS61             : 1;
  __REG32 CESMS62             : 1;
  __REG32 CESMS63             : 1;
} __ftucesms2_bits;

/* FTU Clear on Event to System Memory Reset 2(CESMR2) */
typedef struct {
  __REG32 CESMR32             : 1;
  __REG32 CESMR33             : 1;
  __REG32 CESMR34             : 1;
  __REG32 CESMR35             : 1;
  __REG32 CESMR36             : 1;
  __REG32 CESMR37             : 1;
  __REG32 CESMR38             : 1;
  __REG32 CESMR39             : 1;
  __REG32 CESMR40             : 1;
  __REG32 CESMR41             : 1;
  __REG32 CESMR42             : 1;
  __REG32 CESMR43             : 1;
  __REG32 CESMR44             : 1;
  __REG32 CESMR45             : 1;
  __REG32 CESMR46             : 1;
  __REG32 CESMR47             : 1;
  __REG32 CESMR48             : 1;
  __REG32 CESMR49             : 1;
  __REG32 CESMR50             : 1;
  __REG32 CESMR51             : 1;
  __REG32 CESMR52             : 1;
  __REG32 CESMR53             : 1;
  __REG32 CESMR54             : 1;
  __REG32 CESMR55             : 1;
  __REG32 CESMR56             : 1;
  __REG32 CESMR57             : 1;
  __REG32 CESMR58             : 1;
  __REG32 CESMR59             : 1;
  __REG32 CESMR60             : 1;
  __REG32 CESMR61             : 1;
  __REG32 CESMR62             : 1;
  __REG32 CESMR63             : 1;
} __ftucesmr2_bits;

/* FTU Clear on Event to System Memory Set 3(CESMS3) */
typedef struct {
  __REG32 CESMS64             : 1;
  __REG32 CESMS65             : 1;
  __REG32 CESMS66             : 1;
  __REG32 CESMS67             : 1;
  __REG32 CESMS68             : 1;
  __REG32 CESMS69             : 1;
  __REG32 CESMS70             : 1;
  __REG32 CESMS71             : 1;
  __REG32 CESMS72             : 1;
  __REG32 CESMS73             : 1;
  __REG32 CESMS74             : 1;
  __REG32 CESMS75             : 1;
  __REG32 CESMS76             : 1;
  __REG32 CESMS77             : 1;
  __REG32 CESMS78             : 1;
  __REG32 CESMS79             : 1;
  __REG32 CESMS80             : 1;
  __REG32 CESMS81             : 1;
  __REG32 CESMS82             : 1;
  __REG32 CESMS83             : 1;
  __REG32 CESMS84             : 1;
  __REG32 CESMS85             : 1;
  __REG32 CESMS86             : 1;
  __REG32 CESMS87             : 1;
  __REG32 CESMS88             : 1;
  __REG32 CESMS89             : 1;
  __REG32 CESMS90             : 1;
  __REG32 CESMS91             : 1;
  __REG32 CESMS92             : 1;
  __REG32 CESMS93             : 1;
  __REG32 CESMS94             : 1;
  __REG32 CESMS95             : 1;
} __ftucesms3_bits;

/* FTU Clear on Event to System Memory Reset 3(CESMR3) */
typedef struct {
  __REG32 CESMR64             : 1;
  __REG32 CESMR65             : 1;
  __REG32 CESMR66             : 1;
  __REG32 CESMR67             : 1;
  __REG32 CESMR68             : 1;
  __REG32 CESMR69             : 1;
  __REG32 CESMR70             : 1;
  __REG32 CESMR71             : 1;
  __REG32 CESMR72             : 1;
  __REG32 CESMR73             : 1;
  __REG32 CESMR74             : 1;
  __REG32 CESMR75             : 1;
  __REG32 CESMR76             : 1;
  __REG32 CESMR77             : 1;
  __REG32 CESMR78             : 1;
  __REG32 CESMR79             : 1;
  __REG32 CESMR80             : 1;
  __REG32 CESMR81             : 1;
  __REG32 CESMR82             : 1;
  __REG32 CESMR83             : 1;
  __REG32 CESMR84             : 1;
  __REG32 CESMR85             : 1;
  __REG32 CESMR86             : 1;
  __REG32 CESMR87             : 1;
  __REG32 CESMR88             : 1;
  __REG32 CESMR89             : 1;
  __REG32 CESMR90             : 1;
  __REG32 CESMR91             : 1;
  __REG32 CESMR92             : 1;
  __REG32 CESMR93             : 1;
  __REG32 CESMR94             : 1;
  __REG32 CESMR95             : 1;
} __ftucesmr3_bits;

/* FTU Clear on Event to System Memory Set 4(CESMS4) */
typedef struct {
  __REG32 CESMS96             : 1;
  __REG32 CESMS97             : 1;
  __REG32 CESMS98             : 1;
  __REG32 CESMS99             : 1;
  __REG32 CESMS100            : 1;
  __REG32 CESMS101            : 1;
  __REG32 CESMS102            : 1;
  __REG32 CESMS103            : 1;
  __REG32 CESMS104            : 1;
  __REG32 CESMS105            : 1;
  __REG32 CESMS106            : 1;
  __REG32 CESMS107            : 1;
  __REG32 CESMS108            : 1;
  __REG32 CESMS109            : 1;
  __REG32 CESMS110            : 1;
  __REG32 CESMS111            : 1;
  __REG32 CESMS112            : 1;
  __REG32 CESMS113            : 1;
  __REG32 CESMS114            : 1;
  __REG32 CESMS115            : 1;
  __REG32 CESMS116            : 1;
  __REG32 CESMS117            : 1;
  __REG32 CESMS118            : 1;
  __REG32 CESMS119            : 1;
  __REG32 CESMS120            : 1;
  __REG32 CESMS121            : 1;
  __REG32 CESMS122            : 1;
  __REG32 CESMS123            : 1;
  __REG32 CESMS124            : 1;
  __REG32 CESMS125            : 1;
  __REG32 CESMS126            : 1;
  __REG32 CESMS127            : 1;
} __ftucesms4_bits;

/* FTU Clear on Event to System Memory Reset 4(CESMR4) */
typedef struct {
  __REG32 CESMR96             : 1;
  __REG32 CESMR97             : 1;
  __REG32 CESMR98             : 1;
  __REG32 CESMR99             : 1;
  __REG32 CESMR100            : 1;
  __REG32 CESMR101            : 1;
  __REG32 CESMR102            : 1;
  __REG32 CESMR103            : 1;
  __REG32 CESMR104            : 1;
  __REG32 CESMR105            : 1;
  __REG32 CESMR106            : 1;
  __REG32 CESMR107            : 1;
  __REG32 CESMR108            : 1;
  __REG32 CESMR109            : 1;
  __REG32 CESMR110            : 1;
  __REG32 CESMR111            : 1;
  __REG32 CESMR112            : 1;
  __REG32 CESMR113            : 1;
  __REG32 CESMR114            : 1;
  __REG32 CESMR115            : 1;
  __REG32 CESMR116            : 1;
  __REG32 CESMR117            : 1;
  __REG32 CESMR118            : 1;
  __REG32 CESMR119            : 1;
  __REG32 CESMR120            : 1;
  __REG32 CESMR121            : 1;
  __REG32 CESMR122            : 1;
  __REG32 CESMR123            : 1;
  __REG32 CESMR124            : 1;
  __REG32 CESMR125            : 1;
  __REG32 CESMR126            : 1;
  __REG32 CESMR127            : 1;
} __ftucesmr4_bits;

/* FTU Transfer to System Memory Interrupt Enable Set 1(TSMIES1) */
typedef struct {
  __REG32 TSMIES0              : 1;
  __REG32 TSMIES1              : 1;
  __REG32 TSMIES2              : 1;
  __REG32 TSMIES3              : 1;
  __REG32 TSMIES4              : 1;
  __REG32 TSMIES5              : 1;
  __REG32 TSMIES6              : 1;
  __REG32 TSMIES7              : 1;
  __REG32 TSMIES8              : 1;
  __REG32 TSMIES9              : 1;
  __REG32 TSMIES10             : 1;
  __REG32 TSMIES11             : 1;
  __REG32 TSMIES12             : 1;
  __REG32 TSMIES13             : 1;
  __REG32 TSMIES14             : 1;
  __REG32 TSMIES15             : 1;
  __REG32 TSMIES16             : 1;
  __REG32 TSMIES17             : 1;
  __REG32 TSMIES18             : 1;
  __REG32 TSMIES19             : 1;
  __REG32 TSMIES20             : 1;
  __REG32 TSMIES21             : 1;
  __REG32 TSMIES22             : 1;
  __REG32 TSMIES23             : 1;
  __REG32 TSMIES24             : 1;
  __REG32 TSMIES25             : 1;
  __REG32 TSMIES26             : 1;
  __REG32 TSMIES27             : 1;
  __REG32 TSMIES28             : 1;
  __REG32 TSMIES29             : 1;
  __REG32 TSMIES30             : 1;
  __REG32 TSMIES31             : 1;
} __ftutsmies1_bits;

/* FTU Transfer to System Memory Interrupt Enable Reset 1(TSMIER1) */
typedef struct {
  __REG32 TSMIER0              : 1;
  __REG32 TSMIER1              : 1;
  __REG32 TSMIER2              : 1;
  __REG32 TSMIER3              : 1;
  __REG32 TSMIER4              : 1;
  __REG32 TSMIER5              : 1;
  __REG32 TSMIER6              : 1;
  __REG32 TSMIER7              : 1;
  __REG32 TSMIER8              : 1;
  __REG32 TSMIER9              : 1;
  __REG32 TSMIER10             : 1;
  __REG32 TSMIER11             : 1;
  __REG32 TSMIER12             : 1;
  __REG32 TSMIER13             : 1;
  __REG32 TSMIER14             : 1;
  __REG32 TSMIER15             : 1;
  __REG32 TSMIER16             : 1;
  __REG32 TSMIER17             : 1;
  __REG32 TSMIER18             : 1;
  __REG32 TSMIER19             : 1;
  __REG32 TSMIER20             : 1;
  __REG32 TSMIER21             : 1;
  __REG32 TSMIER22             : 1;
  __REG32 TSMIER23             : 1;
  __REG32 TSMIER24             : 1;
  __REG32 TSMIER25             : 1;
  __REG32 TSMIER26             : 1;
  __REG32 TSMIER27             : 1;
  __REG32 TSMIER28             : 1;
  __REG32 TSMIER29             : 1;
  __REG32 TSMIER30             : 1;
  __REG32 TSMIER31             : 1;
} __ftutsmier1_bits;

/* FTU Transfer to System Memory Interrupt Enable Set 2(TSMIES2) */
typedef struct {
  __REG32 TSMIES32             : 1;
  __REG32 TSMIES33             : 1;
  __REG32 TSMIES34             : 1;
  __REG32 TSMIES35             : 1;
  __REG32 TSMIES36             : 1;
  __REG32 TSMIES37             : 1;
  __REG32 TSMIES38             : 1;
  __REG32 TSMIES39             : 1;
  __REG32 TSMIES40             : 1;
  __REG32 TSMIES41             : 1;
  __REG32 TSMIES42             : 1;
  __REG32 TSMIES43             : 1;
  __REG32 TSMIES44             : 1;
  __REG32 TSMIES45             : 1;
  __REG32 TSMIES46             : 1;
  __REG32 TSMIES47             : 1;
  __REG32 TSMIES48             : 1;
  __REG32 TSMIES49             : 1;
  __REG32 TSMIES50             : 1;
  __REG32 TSMIES51             : 1;
  __REG32 TSMIES52             : 1;
  __REG32 TSMIES53             : 1;
  __REG32 TSMIES54             : 1;
  __REG32 TSMIES55             : 1;
  __REG32 TSMIES56             : 1;
  __REG32 TSMIES57             : 1;
  __REG32 TSMIES58             : 1;
  __REG32 TSMIES59             : 1;
  __REG32 TSMIES60             : 1;
  __REG32 TSMIES61             : 1;
  __REG32 TSMIES62             : 1;
  __REG32 TSMIES63             : 1;
} __ftutsmies2_bits;

/* FTU Transfer to System Memory Interrupt Enable Reset 2(TSMIER2) */
typedef struct {
  __REG32 TSMIER32             : 1;
  __REG32 TSMIER33             : 1;
  __REG32 TSMIER34             : 1;
  __REG32 TSMIER35             : 1;
  __REG32 TSMIER36             : 1;
  __REG32 TSMIER37             : 1;
  __REG32 TSMIER38             : 1;
  __REG32 TSMIER39             : 1;
  __REG32 TSMIER40             : 1;
  __REG32 TSMIER41             : 1;
  __REG32 TSMIER42             : 1;
  __REG32 TSMIER43             : 1;
  __REG32 TSMIER44             : 1;
  __REG32 TSMIER45             : 1;
  __REG32 TSMIER46             : 1;
  __REG32 TSMIER47             : 1;
  __REG32 TSMIER48             : 1;
  __REG32 TSMIER49             : 1;
  __REG32 TSMIER50             : 1;
  __REG32 TSMIER51             : 1;
  __REG32 TSMIER52             : 1;
  __REG32 TSMIER53             : 1;
  __REG32 TSMIER54             : 1;
  __REG32 TSMIER55             : 1;
  __REG32 TSMIER56             : 1;
  __REG32 TSMIER57             : 1;
  __REG32 TSMIER58             : 1;
  __REG32 TSMIER59             : 1;
  __REG32 TSMIER60             : 1;
  __REG32 TSMIER61             : 1;
  __REG32 TSMIER62             : 1;
  __REG32 TSMIER63             : 1;
} __ftutsmier2_bits;

/* FTU Transfer to System Memory Interrupt Enable Set 3(TSMIES3) */
typedef struct {
  __REG32 TSMIES64             : 1;
  __REG32 TSMIES65             : 1;
  __REG32 TSMIES66             : 1;
  __REG32 TSMIES67             : 1;
  __REG32 TSMIES68             : 1;
  __REG32 TSMIES69             : 1;
  __REG32 TSMIES70             : 1;
  __REG32 TSMIES71             : 1;
  __REG32 TSMIES72             : 1;
  __REG32 TSMIES73             : 1;
  __REG32 TSMIES74             : 1;
  __REG32 TSMIES75             : 1;
  __REG32 TSMIES76             : 1;
  __REG32 TSMIES77             : 1;
  __REG32 TSMIES78             : 1;
  __REG32 TSMIES79             : 1;
  __REG32 TSMIES80             : 1;
  __REG32 TSMIES81             : 1;
  __REG32 TSMIES82             : 1;
  __REG32 TSMIES83             : 1;
  __REG32 TSMIES84             : 1;
  __REG32 TSMIES85             : 1;
  __REG32 TSMIES86             : 1;
  __REG32 TSMIES87             : 1;
  __REG32 TSMIES88             : 1;
  __REG32 TSMIES89             : 1;
  __REG32 TSMIES90             : 1;
  __REG32 TSMIES91             : 1;
  __REG32 TSMIES92             : 1;
  __REG32 TSMIES93             : 1;
  __REG32 TSMIES94             : 1;
  __REG32 TSMIES95             : 1;
} __ftutsmies3_bits;

/* FTU Transfer to System Memory Interrupt Enable Reset 3(TSMIER3) */
typedef struct {
  __REG32 TSMIER64             : 1;
  __REG32 TSMIER65             : 1;
  __REG32 TSMIER66             : 1;
  __REG32 TSMIER67             : 1;
  __REG32 TSMIER68             : 1;
  __REG32 TSMIER69             : 1;
  __REG32 TSMIER70             : 1;
  __REG32 TSMIER71             : 1;
  __REG32 TSMIER72             : 1;
  __REG32 TSMIER73             : 1;
  __REG32 TSMIER74             : 1;
  __REG32 TSMIER75             : 1;
  __REG32 TSMIER76             : 1;
  __REG32 TSMIER77             : 1;
  __REG32 TSMIER78             : 1;
  __REG32 TSMIER79             : 1;
  __REG32 TSMIER80             : 1;
  __REG32 TSMIER81             : 1;
  __REG32 TSMIER82             : 1;
  __REG32 TSMIER83             : 1;
  __REG32 TSMIER84             : 1;
  __REG32 TSMIER85             : 1;
  __REG32 TSMIER86             : 1;
  __REG32 TSMIER87             : 1;
  __REG32 TSMIER88             : 1;
  __REG32 TSMIER89             : 1;
  __REG32 TSMIER90             : 1;
  __REG32 TSMIER91             : 1;
  __REG32 TSMIER92             : 1;
  __REG32 TSMIER93             : 1;
  __REG32 TSMIER94             : 1;
  __REG32 TSMIER95             : 1;
} __ftutsmier3_bits;

/* FTU Transfer to System Memory Interrupt Enable Set 4(TSMIES4) */
typedef struct {
  __REG32 TSMIES96             : 1;
  __REG32 TSMIES97             : 1;
  __REG32 TSMIES98             : 1;
  __REG32 TSMIES99             : 1;
  __REG32 TSMIES100            : 1;
  __REG32 TSMIES101            : 1;
  __REG32 TSMIES102            : 1;
  __REG32 TSMIES103            : 1;
  __REG32 TSMIES104            : 1;
  __REG32 TSMIES105            : 1;
  __REG32 TSMIES106            : 1;
  __REG32 TSMIES107            : 1;
  __REG32 TSMIES108            : 1;
  __REG32 TSMIES109            : 1;
  __REG32 TSMIES110            : 1;
  __REG32 TSMIES111            : 1;
  __REG32 TSMIES112            : 1;
  __REG32 TSMIES113            : 1;
  __REG32 TSMIES114            : 1;
  __REG32 TSMIES115            : 1;
  __REG32 TSMIES116            : 1;
  __REG32 TSMIES117            : 1;
  __REG32 TSMIES118            : 1;
  __REG32 TSMIES119            : 1;
  __REG32 TSMIES120            : 1;
  __REG32 TSMIES121            : 1;
  __REG32 TSMIES122            : 1;
  __REG32 TSMIES123            : 1;
  __REG32 TSMIES124            : 1;
  __REG32 TSMIES125            : 1;
  __REG32 TSMIES126            : 1;
  __REG32 TSMIES127            : 1;
} __ftutsmies4_bits;

/* FTU Transfer to System Memory Interrupt Enable Reset 4(TSMIER4) */
typedef struct {
  __REG32 TSMIER96             : 1;
  __REG32 TSMIER97             : 1;
  __REG32 TSMIER98             : 1;
  __REG32 TSMIER99             : 1;
  __REG32 TSMIER100            : 1;
  __REG32 TSMIER101            : 1;
  __REG32 TSMIER102            : 1;
  __REG32 TSMIER103            : 1;
  __REG32 TSMIER104            : 1;
  __REG32 TSMIER105            : 1;
  __REG32 TSMIER106            : 1;
  __REG32 TSMIER107            : 1;
  __REG32 TSMIER108            : 1;
  __REG32 TSMIER109            : 1;
  __REG32 TSMIER110            : 1;
  __REG32 TSMIER111            : 1;
  __REG32 TSMIER112            : 1;
  __REG32 TSMIER113            : 1;
  __REG32 TSMIER114            : 1;
  __REG32 TSMIER115            : 1;
  __REG32 TSMIER116            : 1;
  __REG32 TSMIER117            : 1;
  __REG32 TSMIER118            : 1;
  __REG32 TSMIER119            : 1;
  __REG32 TSMIER120            : 1;
  __REG32 TSMIER121            : 1;
  __REG32 TSMIER122            : 1;
  __REG32 TSMIER123            : 1;
  __REG32 TSMIER124            : 1;
  __REG32 TSMIER125            : 1;
  __REG32 TSMIER126            : 1;
  __REG32 TSMIER127            : 1;
} __ftutsmier4_bits;

/* FTU Transfer to Communication Controller Interrupt Enable Set 1(TCCIES1) */
typedef struct {
  __REG32 TCCIES0              : 1;
  __REG32 TCCIES1              : 1;
  __REG32 TCCIES2              : 1;
  __REG32 TCCIES3              : 1;
  __REG32 TCCIES4              : 1;
  __REG32 TCCIES5              : 1;
  __REG32 TCCIES6              : 1;
  __REG32 TCCIES7              : 1;
  __REG32 TCCIES8              : 1;
  __REG32 TCCIES9              : 1;
  __REG32 TCCIES10             : 1;
  __REG32 TCCIES11             : 1;
  __REG32 TCCIES12             : 1;
  __REG32 TCCIES13             : 1;
  __REG32 TCCIES14             : 1;
  __REG32 TCCIES15             : 1;
  __REG32 TCCIES16             : 1;
  __REG32 TCCIES17             : 1;
  __REG32 TCCIES18             : 1;
  __REG32 TCCIES19             : 1;
  __REG32 TCCIES20             : 1;
  __REG32 TCCIES21             : 1;
  __REG32 TCCIES22             : 1;
  __REG32 TCCIES23             : 1;
  __REG32 TCCIES24             : 1;
  __REG32 TCCIES25             : 1;
  __REG32 TCCIES26             : 1;
  __REG32 TCCIES27             : 1;
  __REG32 TCCIES28             : 1;
  __REG32 TCCIES29             : 1;
  __REG32 TCCIES30             : 1;
  __REG32 TCCIES31             : 1;
} __ftutccies1_bits;

/* FTU Transfer to Communication Controller Interrupt Enable Reset 1(TCCIER1) */
typedef struct {
  __REG32 TCCIER0              : 1;
  __REG32 TCCIER1              : 1;
  __REG32 TCCIER2              : 1;
  __REG32 TCCIER3              : 1;
  __REG32 TCCIER4              : 1;
  __REG32 TCCIER5              : 1;
  __REG32 TCCIER6              : 1;
  __REG32 TCCIER7              : 1;
  __REG32 TCCIER8              : 1;
  __REG32 TCCIER9              : 1;
  __REG32 TCCIER10             : 1;
  __REG32 TCCIER11             : 1;
  __REG32 TCCIER12             : 1;
  __REG32 TCCIER13             : 1;
  __REG32 TCCIER14             : 1;
  __REG32 TCCIER15             : 1;
  __REG32 TCCIER16             : 1;
  __REG32 TCCIER17             : 1;
  __REG32 TCCIER18             : 1;
  __REG32 TCCIER19             : 1;
  __REG32 TCCIER20             : 1;
  __REG32 TCCIER21             : 1;
  __REG32 TCCIER22             : 1;
  __REG32 TCCIER23             : 1;
  __REG32 TCCIER24             : 1;
  __REG32 TCCIER25             : 1;
  __REG32 TCCIER26             : 1;
  __REG32 TCCIER27             : 1;
  __REG32 TCCIER28             : 1;
  __REG32 TCCIER29             : 1;
  __REG32 TCCIER30             : 1;
  __REG32 TCCIER31             : 1;
} __ftutccier1_bits;

/* FTU Transfer to Communication Controller Interrupt Enable Set 2(TCCIES2) */
typedef struct {
  __REG32 TCCIES32             : 1;
  __REG32 TCCIES33             : 1;
  __REG32 TCCIES34             : 1;
  __REG32 TCCIES35             : 1;
  __REG32 TCCIES36             : 1;
  __REG32 TCCIES37             : 1;
  __REG32 TCCIES38             : 1;
  __REG32 TCCIES39             : 1;
  __REG32 TCCIES40             : 1;
  __REG32 TCCIES41             : 1;
  __REG32 TCCIES42             : 1;
  __REG32 TCCIES43             : 1;
  __REG32 TCCIES44             : 1;
  __REG32 TCCIES45             : 1;
  __REG32 TCCIES46             : 1;
  __REG32 TCCIES47             : 1;
  __REG32 TCCIES48             : 1;
  __REG32 TCCIES49             : 1;
  __REG32 TCCIES50             : 1;
  __REG32 TCCIES51             : 1;
  __REG32 TCCIES52             : 1;
  __REG32 TCCIES53             : 1;
  __REG32 TCCIES54             : 1;
  __REG32 TCCIES55             : 1;
  __REG32 TCCIES56             : 1;
  __REG32 TCCIES57             : 1;
  __REG32 TCCIES58             : 1;
  __REG32 TCCIES59             : 1;
  __REG32 TCCIES60             : 1;
  __REG32 TCCIES61             : 1;
  __REG32 TCCIES62             : 1;
  __REG32 TCCIES63             : 1;
} __ftutccies2_bits;

/* FTU Transfer to Communication Controller Interrupt Enable Reset 2(TCCIER2) */
typedef struct {
  __REG32 TCCIER32             : 1;
  __REG32 TCCIER33             : 1;
  __REG32 TCCIER34             : 1;
  __REG32 TCCIER35             : 1;
  __REG32 TCCIER36             : 1;
  __REG32 TCCIER37             : 1;
  __REG32 TCCIER38             : 1;
  __REG32 TCCIER39             : 1;
  __REG32 TCCIER40             : 1;
  __REG32 TCCIER41             : 1;
  __REG32 TCCIER42             : 1;
  __REG32 TCCIER43             : 1;
  __REG32 TCCIER44             : 1;
  __REG32 TCCIER45             : 1;
  __REG32 TCCIER46             : 1;
  __REG32 TCCIER47             : 1;
  __REG32 TCCIER48             : 1;
  __REG32 TCCIER49             : 1;
  __REG32 TCCIER50             : 1;
  __REG32 TCCIER51             : 1;
  __REG32 TCCIER52             : 1;
  __REG32 TCCIER53             : 1;
  __REG32 TCCIER54             : 1;
  __REG32 TCCIER55             : 1;
  __REG32 TCCIER56             : 1;
  __REG32 TCCIER57             : 1;
  __REG32 TCCIER58             : 1;
  __REG32 TCCIER59             : 1;
  __REG32 TCCIER60             : 1;
  __REG32 TCCIER61             : 1;
  __REG32 TCCIER62             : 1;
  __REG32 TCCIER63             : 1;
} __ftutccier2_bits;

/* FTU Transfer to Communication Controller Interrupt Enable Set 3(TCCIES3) */
typedef struct {
  __REG32 TCCIES64             : 1;
  __REG32 TCCIES65             : 1;
  __REG32 TCCIES66             : 1;
  __REG32 TCCIES67             : 1;
  __REG32 TCCIES68             : 1;
  __REG32 TCCIES69             : 1;
  __REG32 TCCIES70             : 1;
  __REG32 TCCIES71             : 1;
  __REG32 TCCIES72             : 1;
  __REG32 TCCIES73             : 1;
  __REG32 TCCIES74             : 1;
  __REG32 TCCIES75             : 1;
  __REG32 TCCIES76             : 1;
  __REG32 TCCIES77             : 1;
  __REG32 TCCIES78             : 1;
  __REG32 TCCIES79             : 1;
  __REG32 TCCIES80             : 1;
  __REG32 TCCIES81             : 1;
  __REG32 TCCIES82             : 1;
  __REG32 TCCIES83             : 1;
  __REG32 TCCIES84             : 1;
  __REG32 TCCIES85             : 1;
  __REG32 TCCIES86             : 1;
  __REG32 TCCIES87             : 1;
  __REG32 TCCIES88             : 1;
  __REG32 TCCIES89             : 1;
  __REG32 TCCIES90             : 1;
  __REG32 TCCIES91             : 1;
  __REG32 TCCIES92             : 1;
  __REG32 TCCIES93             : 1;
  __REG32 TCCIES94             : 1;
  __REG32 TCCIES95             : 1;
} __ftutccies3_bits;

/* FTU Transfer to Communication Controller Interrupt Enable Reset 3(TCCIER3) */
typedef struct {
  __REG32 TCCIER64             : 1;
  __REG32 TCCIER65             : 1;
  __REG32 TCCIER66             : 1;
  __REG32 TCCIER67             : 1;
  __REG32 TCCIER68             : 1;
  __REG32 TCCIER69             : 1;
  __REG32 TCCIER70             : 1;
  __REG32 TCCIER71             : 1;
  __REG32 TCCIER72             : 1;
  __REG32 TCCIER73             : 1;
  __REG32 TCCIER74             : 1;
  __REG32 TCCIER75             : 1;
  __REG32 TCCIER76             : 1;
  __REG32 TCCIER77             : 1;
  __REG32 TCCIER78             : 1;
  __REG32 TCCIER79             : 1;
  __REG32 TCCIER80             : 1;
  __REG32 TCCIER81             : 1;
  __REG32 TCCIER82             : 1;
  __REG32 TCCIER83             : 1;
  __REG32 TCCIER84             : 1;
  __REG32 TCCIER85             : 1;
  __REG32 TCCIER86             : 1;
  __REG32 TCCIER87             : 1;
  __REG32 TCCIER88             : 1;
  __REG32 TCCIER89             : 1;
  __REG32 TCCIER90             : 1;
  __REG32 TCCIER91             : 1;
  __REG32 TCCIER92             : 1;
  __REG32 TCCIER93             : 1;
  __REG32 TCCIER94             : 1;
  __REG32 TCCIER95             : 1;
} __ftutccier3_bits;

/* FTU Transfer to Communication Controller Interrupt Enable Set 4(TCCIES4) */
typedef struct {
  __REG32 TCCIES96             : 1;
  __REG32 TCCIES97             : 1;
  __REG32 TCCIES98             : 1;
  __REG32 TCCIES99             : 1;
  __REG32 TCCIES100            : 1;
  __REG32 TCCIES101            : 1;
  __REG32 TCCIES102            : 1;
  __REG32 TCCIES103            : 1;
  __REG32 TCCIES104            : 1;
  __REG32 TCCIES105            : 1;
  __REG32 TCCIES106            : 1;
  __REG32 TCCIES107            : 1;
  __REG32 TCCIES108            : 1;
  __REG32 TCCIES109            : 1;
  __REG32 TCCIES110            : 1;
  __REG32 TCCIES111            : 1;
  __REG32 TCCIES112            : 1;
  __REG32 TCCIES113            : 1;
  __REG32 TCCIES114            : 1;
  __REG32 TCCIES115            : 1;
  __REG32 TCCIES116            : 1;
  __REG32 TCCIES117            : 1;
  __REG32 TCCIES118            : 1;
  __REG32 TCCIES119            : 1;
  __REG32 TCCIES120            : 1;
  __REG32 TCCIES121            : 1;
  __REG32 TCCIES122            : 1;
  __REG32 TCCIES123            : 1;
  __REG32 TCCIES124            : 1;
  __REG32 TCCIES125            : 1;
  __REG32 TCCIES126            : 1;
  __REG32 TCCIES127            : 1;
} __ftutccies4_bits;

/* FTU Transfer to Communication Controller Interrupt Enable Reset 4(TCCIER4) */
typedef struct {
  __REG32 TCCIER96             : 1;
  __REG32 TCCIER97             : 1;
  __REG32 TCCIER98             : 1;
  __REG32 TCCIER99             : 1;
  __REG32 TCCIER100            : 1;
  __REG32 TCCIER101            : 1;
  __REG32 TCCIER102            : 1;
  __REG32 TCCIER103            : 1;
  __REG32 TCCIER104            : 1;
  __REG32 TCCIER105            : 1;
  __REG32 TCCIER106            : 1;
  __REG32 TCCIER107            : 1;
  __REG32 TCCIER108            : 1;
  __REG32 TCCIER109            : 1;
  __REG32 TCCIER110            : 1;
  __REG32 TCCIER111            : 1;
  __REG32 TCCIER112            : 1;
  __REG32 TCCIER113            : 1;
  __REG32 TCCIER114            : 1;
  __REG32 TCCIER115            : 1;
  __REG32 TCCIER116            : 1;
  __REG32 TCCIER117            : 1;
  __REG32 TCCIER118            : 1;
  __REG32 TCCIER119            : 1;
  __REG32 TCCIER120            : 1;
  __REG32 TCCIER121            : 1;
  __REG32 TCCIER122            : 1;
  __REG32 TCCIER123            : 1;
  __REG32 TCCIER124            : 1;
  __REG32 TCCIER125            : 1;
  __REG32 TCCIER126            : 1;
  __REG32 TCCIER127            : 1;
} __ftutccier4_bits;

/* FlexRay Test Register1 (TEST1) */
typedef struct {
  __REG32 WRTEN               : 1;
  __REG32 ELBE                : 1;
  __REG32                     : 2;
  __REG32 TMC                 : 2;
  __REG32                     : 2;
  __REG32 AOA                 : 1;
  __REG32 AOB                 : 1;
  __REG32                     : 6;
  __REG32 RXA                 : 1;
  __REG32 RXB                 : 1;
  __REG32 TXA                 : 1;
  __REG32 TXB                 : 1;
  __REG32 TXENA               : 1;
  __REG32 TXENB               : 1;
  __REG32                     : 2;
  __REG32 CERA                : 4;
  __REG32 CERB                : 4;
} __ftest1_bits;

/* FlexRay Test Register1 (TEST2) */
typedef struct {
  __REG32 RS                  : 3;
  __REG32                     : 1;
  __REG32 SSEL                : 3;
  __REG32                     : 7;
  __REG32 WRPB                : 1;
  __REG32 RDPB                : 1;
  __REG32                     :16;
} __ftest2_bits;

/* Lock Register (LCK) */
typedef struct {
  __REG32 CLK                 : 8;
  __REG32 TMK                 : 8;
  __REG32                     :16;
} __flck_bits;

/* Error Interrupt Register (EIR) */
typedef struct {
  __REG32 PEMC                : 1;
  __REG32 CNA                 : 1;
  __REG32 SFBM                : 1;
  __REG32 SFO                 : 1;
  __REG32 CCF                 : 1;
  __REG32 CCL                 : 1;
  __REG32 PERR                : 1;
  __REG32 RFO                 : 1;
  __REG32 EFA                 : 1;
  __REG32 IIBA                : 1;
  __REG32 IOBA                : 1;
  __REG32 MHF                 : 1;
  __REG32                     : 4;
  __REG32 EDA                 : 1;
  __REG32 LTVA                : 1;
  __REG32 TABA                : 1;
  __REG32                     : 5;
  __REG32 EDB                 : 1;
  __REG32 LTVB                : 1;
  __REG32 TABB                : 1;
  __REG32                     : 5;
} __feir_bits;

/* Status Interrupt Register (SIR) */
typedef struct {
  __REG32 WST                 : 1;
  __REG32 CAS                 : 1;
  __REG32 CYCS                : 1;
  __REG32 TXI                 : 1;
  __REG32 RXI                 : 1;
  __REG32 RFNE                : 1;
  __REG32 RFCL                : 1;
  __REG32 NMVC                : 1;
  __REG32 TI0                 : 1;
  __REG32 TI1                 : 1;
  __REG32 TIBC                : 1;
  __REG32 TOBC                : 1;
  __REG32 SWE                 : 1;
  __REG32 SUCS                : 1;
  __REG32 MBSI                : 1;
  __REG32 SDS                 : 1;
  __REG32 WUPA                : 1;
  __REG32 MTSA                : 1;
  __REG32                     : 6;
  __REG32 WUPB                : 1;
  __REG32 MTSB                : 1;
  __REG32                     : 6;
} __fsir_bits;

/* Error Interrupt Line Select Register (EILS) */
typedef struct {
  __REG32 PEMCL               : 1;
  __REG32 CNAL                : 1;
  __REG32 SFBML               : 1;
  __REG32 SFOL                : 1;
  __REG32 CCFL                : 1;
  __REG32 CCLL                : 1;
  __REG32 PERRL               : 1;
  __REG32 RFOL                : 1;
  __REG32 EFAL                : 1;
  __REG32 IIBAL               : 1;
  __REG32 IOBAL               : 1;
  __REG32 MHFL                : 1;
  __REG32                     : 4;
  __REG32 EDAL                : 1;
  __REG32 LTVAL               : 1;
  __REG32 TABAL               : 1;
  __REG32                     : 5;
  __REG32 EDBL                : 1;
  __REG32 LTVBL               : 1;
  __REG32 TABBL               : 1;
  __REG32                     : 5;
} __feils_bits;

/* Status Interrupt Line Select Register (SILS) */
typedef struct {
  __REG32 WSTL                : 1;
  __REG32 CASL                : 1;
  __REG32 CYCSL               : 1;
  __REG32 TXIL                : 1;
  __REG32 RXIL                : 1;
  __REG32 RFNEL               : 1;
  __REG32 RFCLL               : 1;
  __REG32 NMVCL               : 1;
  __REG32 TI0L                : 1;
  __REG32 TI1L                : 1;
  __REG32 TIBCL               : 1;
  __REG32 TOBCL               : 1;
  __REG32 SWEL                : 1;
  __REG32 SUCSL               : 1;
  __REG32 MBSIL               : 1;
  __REG32 SDSL                : 1;
  __REG32 WUPAL               : 1;
  __REG32 MTSAL               : 1;
  __REG32                     : 6;
  __REG32 WUPBL               : 1;
  __REG32 MTSBL               : 1;
  __REG32                     : 6;
} __fsils_bits;

/* Error Interrupt Enable Set/Reset Register (EIES, EIER) */
typedef struct {
  __REG32 PEMCE               : 1;
  __REG32 CNAE                : 1;
  __REG32 SFBME               : 1;
  __REG32 SFOE                : 1;
  __REG32 CCFE                : 1;
  __REG32 CCLE                : 1;
  __REG32 PERRE               : 1;
  __REG32 RFOE                : 1;
  __REG32 EFAE                : 1;
  __REG32 IIBAE               : 1;
  __REG32 IOBAE               : 1;
  __REG32 MHFE                : 1;
  __REG32                     : 4;
  __REG32 EDAE                : 1;
  __REG32 LTVAE               : 1;
  __REG32 TABAE               : 1;
  __REG32                     : 5;
  __REG32 EDBE                : 1;
  __REG32 LTVBE               : 1;
  __REG32 TABBE               : 1;
  __REG32                     : 5;
} __feies_bits;

/* Status Interrupt Enable Set/Reset Register (SIES, SIER) */
typedef struct {
  __REG32 WSTE                : 1;
  __REG32 CASE                : 1;
  __REG32 CYCSE               : 1;
  __REG32 TXIE                : 1;
  __REG32 RXIE                : 1;
  __REG32 RFNEE               : 1;
  __REG32 RFCLE               : 1;
  __REG32 NMVCE               : 1;
  __REG32 TI0E                : 1;
  __REG32 TI1E                : 1;
  __REG32 TIBCE               : 1;
  __REG32 TOBCE               : 1;
  __REG32 SWEE                : 1;
  __REG32 SUCSE               : 1;
  __REG32 MBSIE               : 1;
  __REG32 SDSE                : 1;
  __REG32 WUPAE               : 1;
  __REG32 MTSAE               : 1;
  __REG32                     : 6;
  __REG32 WUPBE               : 1;
  __REG32 MTSBE               : 1;
  __REG32                     : 6;
} __fsies_bits;

/* Interrupt Line Enable Register (ILE) */
typedef struct {
  __REG32 EINT                : 2;
  __REG32                     :30;
} __file_bits;

/* Timer 0 Configuration Register (T0C) */
typedef struct {
  __REG32 T0RC                : 1;
  __REG32 T0MS                : 1;
  __REG32                     : 6;
  __REG32 T0CC                : 7;
  __REG32                     : 1;
  __REG32 T0MO                :14;
  __REG32                     : 2;
} __ft0c_bits;

/* Timer 1 Configuration Register (T1C) */
typedef struct {
  __REG32 T1RC                : 1;
  __REG32 T1MS                : 1;
  __REG32                     :14;
  __REG32 T1MC                :14;
  __REG32                     : 2;
} __ft1c_bits;

/* Stop Watch Register 1 (STPW1) */
typedef struct {
  __REG32 ESWT                : 1;
  __REG32 SWMS                : 1;
  __REG32 EDGE                : 1;
  __REG32 SSWT                : 1;
  __REG32 EETP                : 1;
  __REG32 EINT0               : 1;
  __REG32 EINT1               : 1;
  __REG32                     : 1;
  __REG32 SCCV                : 6;
  __REG32                     : 2;
  __REG32 SMTV                :14;
  __REG32                     : 2;
} __fstpw1_bits;

/* Stop Watch Register 2 (STPW2) */
typedef struct {
  __REG32 SSCVA               :11;
  __REG32                     : 5;
  __REG32 SSCVB               :11;
  __REG32                     : 5;
} __fstpw2_bits;

/* SUC Configuration Register 1 (SUCC1) */
typedef struct {
  __REG32 CMD                 : 4;
  __REG32                     : 3;
  __REG32 PBSY                : 1;
  __REG32 TXST                : 1;
  __REG32 TXSY                : 1;
  __REG32                     : 1;
  __REG32 CSA                 : 5;
  __REG32 PTA                 : 5;
  __REG32 WUCS                : 1;
  __REG32 TSM                 : 1;
  __REG32 HCSE                : 1;
  __REG32 MTSA                : 1;
  __REG32 MTSB                : 1;
  __REG32 CCHA                : 1;
  __REG32 CCHB                : 1;
  __REG32                     : 4;
} __fsucc1_bits;

/* SUC Configuration Register 2 (SUCC2) */
typedef struct {
  __REG32 LT                  :21;
  __REG32                     : 3;
  __REG32 LTN                 : 4;
  __REG32                     : 4;
} __fsucc2_bits;

/* SUC Configuration Register 3 (SUCC3) */
typedef struct {
  __REG32 WCP                 : 4;
  __REG32 WCF                 : 4;
  __REG32                     :24;
} __fsucc3_bits;

/* NEM Configuration Register (NEMC) */
typedef struct {
  __REG32 NML                 : 4;
  __REG32                     :28;
} __fnemc_bits;

/* PRT Configuration Register 1 (PRTC1) */
typedef struct {
  __REG32 TSST                : 4;
  __REG32 CASM                : 7;
  __REG32                     : 1;
  __REG32 SPP                 : 2;
  __REG32 BRP                 : 2;
  __REG32 RXW                 : 9;
  __REG32                     : 1;
  __REG32 RWP                 : 6;
} __fprtc1_bits;

/* PRT Configuration Register 2 (PRTC2) */
typedef struct {
  __REG32 RXI                 : 6;
  __REG32                     : 2;
  __REG32 RXL                 : 6;
  __REG32                     : 2;
  __REG32 TXI                 : 8;
  __REG32 TXL                 : 6;
  __REG32                     : 2;
} __fprtc2_bits;

/* MHD Configuration Register (MHDC) */
typedef struct {
  __REG32 SFDL                : 7;
  __REG32                     : 9;
  __REG32 SLT                 :13;
  __REG32                     : 3;
} __fmhdc_bits;

/* GTU Configuration Register 1 (GTUC1) */
typedef struct {
  __REG32 UT                  :20;
  __REG32                     :12;
} __fgtuc1_bits;

/* GTU Configuration Register 2 (GTUC2) */
typedef struct {
  __REG32 MPC                 :14;
  __REG32                     : 2;
  __REG32 SNM                 : 4;
  __REG32                     :12;
} __fgtuc2_bits;

/* GTU Configuration Register 3 (GTUC3) */
typedef struct {
  __REG32 UIOA                : 8;
  __REG32 UIOB                : 8;
  __REG32 MIOA                : 7;
  __REG32                     : 1;
  __REG32 MIOB                : 7;
  __REG32                     : 1;
} __fgtuc3_bits;

/* GTU Configuration Register 4 (GTUC4) */
typedef struct {
  __REG32 NIT                 :14;
  __REG32                     : 2;
  __REG32 OCS                 :14;
  __REG32                     : 2;
} __fgtuc4_bits;

/* GTU Configuration Register 5 (GTUC5) */
typedef struct {
  __REG32 DCA                 : 8;
  __REG32 DCB                 : 8;
  __REG32 CDD                 : 5;
  __REG32                     : 3;
  __REG32 DEC                 : 8;
} __fgtuc5_bits;

/* GTU Configuration Register 6 (GTUC6) */
typedef struct {
  __REG32 ASR                 :11;
  __REG32                     : 5;
  __REG32 MOD                 :11;
  __REG32                     : 5;
} __fgtuc6_bits;

/* GTU Configuration Register 7 (GTUC7) */
typedef struct {
  __REG32 SSL                 :10;
  __REG32                     : 6;
  __REG32 NSS                 :10;
  __REG32                     : 6;
} __fgtuc7_bits;

/* GTU Configuration Register 8 (GTUC8) */
typedef struct {
  __REG32 MSL                 : 6;
  __REG32                     :10;
  __REG32 NMS                 :13;
  __REG32                     : 3;
} __fgtuc8_bits;

/* GTU Configuration Register 9 (GTUC9) */
typedef struct {
  __REG32 APO                 : 6;
  __REG32                     : 2;
  __REG32 MAPO                : 5;
  __REG32                     : 3;
  __REG32 DSI                 : 2;
  __REG32                     :14;
} __fgtuc9_bits;

/* GTU Configuration Register 10 (GTUC10) */
typedef struct {
  __REG32 MOC                 :14;
  __REG32                     : 2;
  __REG32 MRC                 :11;
  __REG32                     : 5;
} __fgtuc10_bits;

/* GTU Configuration Register 11 (GTUC11) */
typedef struct {
  __REG32 EOCC                : 2;
  __REG32                     : 6;
  __REG32 ERCC                : 2;
  __REG32                     : 6;
  __REG32 EOC                 : 3;
  __REG32                     : 5;
  __REG32 ERC                 : 3;
  __REG32                     : 5;
} __fgtuc11_bits;

/* Communication Controller Status Vector Register (CCSV) */
typedef struct {
  __REG32 POCS                : 6;
  __REG32 FSI                 : 1;
  __REG32 HRQ                 : 1;
  __REG32 SLM                 : 2;
  __REG32                     : 2;
  __REG32 CSNI                : 1;
  __REG32 CSAI                : 1;
  __REG32 CSI                 : 1;
  __REG32                     : 1;
  __REG32 WSV                 : 3;
  __REG32 RCA                 : 5;
  __REG32 PSL                 : 6;
  __REG32                     : 2;
} __fccsv_bits;

/* Communication Controller Error Vector (CCEV) */
typedef struct {
  __REG32 CCFC                : 4;
  __REG32                     : 2;
  __REG32 ERRM                : 2;
  __REG32 PTAC                : 5;
  __REG32                     :19;
} __fccev_bits;

/* Slot Counter Vector Register (SCV) */
typedef struct {
  __REG32 SCCA                :11;
  __REG32                     : 5;
  __REG32 SCCB                :11;
  __REG32                     : 5;
} __fscv_bits;

/* Macrotick and Cycle Counter Register (MTCCV) */
typedef struct {
  __REG32 MTV                 :14;
  __REG32                     : 2;
  __REG32 CCV                 : 6;
  __REG32                     :10;
} __fmtccv_bits;

/* Rate Correction Value Register (RCV) */
typedef struct {
  __REG32 RCV                 :12;
  __REG32                     :20;
} __frcv_bits;

/* Offset Correction Value Register (OCV) */
typedef struct {
  __REG32 OCV                 :20;
  __REG32                     :12;
} __focv_bits;

/* Sync Frame Status Register (SFS) */
typedef struct {
  __REG32 VSAE                : 4;
  __REG32 VSAO                : 4;
  __REG32 VSBE                : 4;
  __REG32 VSBO                : 4;
  __REG32 MOCS                : 1;
  __REG32 OCLR                : 1;
  __REG32 MRCS                : 1;
  __REG32 RCLR                : 1;
  __REG32                     :12;
} __fsfs_bits;

/* Symbol Window and NIT Status Register (SWNIT) */
typedef struct {
  __REG32 SESA                : 1;
  __REG32 SBSA                : 1;
  __REG32 TCSA                : 1;
  __REG32 SESB                : 1;
  __REG32 SBSB                : 1;
  __REG32 TCSB                : 1;
  __REG32 MTSA                : 1;
  __REG32 MTSB                : 1;
  __REG32 SENA                : 1;
  __REG32 SBNA                : 1;
  __REG32 SENB                : 1;
  __REG32 SBNB                : 1;
  __REG32                     :20;
} __fswnit_bits;

/* Aggregated Channel Status Register (ACS) */
typedef struct {
  __REG32 VFRA                : 1;
  __REG32 SEDA                : 1;
  __REG32 CEDA                : 1;
  __REG32 CIA                 : 1;
  __REG32 SBVA                : 1;
  __REG32                     : 3;
  __REG32 VFRB                : 1;
  __REG32 SEDB                : 1;
  __REG32 CEDB                : 1;
  __REG32 CIB                 : 1;
  __REG32 SBVB                : 1;
  __REG32                     :19;
} __facs_bits;

/* Even Sync ID Register [1. . .15] (ESIDn) */
typedef struct {
  __REG32 EID                 :10;
  __REG32                     : 4;
  __REG32 RXEA                : 1;
  __REG32 RXEB                : 1;
  __REG32                     :16;
} __fesid_bits;

/* Odd Sync ID Register [1. . .15] (OSIDn) */
typedef struct {
  __REG32 OID                 :10;
  __REG32                     : 4;
  __REG32 RXOA                : 1;
  __REG32 RXOB                : 1;
  __REG32                     :16;
} __fosid_bits;

/* Network Management Register 1 (NMV1) */
typedef struct {
  __REG32 Data0               : 8;
  __REG32 Data1               : 8;
  __REG32 Data2               : 8;
  __REG32 Data3               : 8;
} __fnmv1_bits;

/* Network Management Register 2 (NMV2) */
typedef struct {
  __REG32 Data4               : 8;
  __REG32 Data5               : 8;
  __REG32 Data6               : 8;
  __REG32 Data7               : 8;
} __fnmv2_bits;

/* Network Management Register 3 (NMV3) */
typedef struct {
  __REG32 Data8               : 8;
  __REG32 Data9               : 8;
  __REG32 Data10              : 8;
  __REG32 Data11              : 8;
} __fnmv3_bits;

/* Message RAM Configuration Register (MRC) */
typedef struct {
  __REG32 FDB                 : 8;
  __REG32 FFB                 : 8;
  __REG32 LCB                 : 8;
  __REG32 SEC                 : 2;
  __REG32 SPLM                : 1;
  __REG32                     : 5;
} __fmrc_bits;

/* Message RAM Configuration Register (MRC) */
typedef struct {
  __REG32 CH                  : 2;
  __REG32 FID                 :11;
  __REG32                     : 3;
  __REG32 CYF                 : 7;
  __REG32 RSS                 : 1;
  __REG32 RNF                 : 1;
  __REG32                     : 7;
} __ffrf_bits;

/* FIFO Rejection Filter Mask Register (FRFM) */
typedef struct {
  __REG32                     : 2;
  __REG32 MFID                :11;
  __REG32                     :19;
} __ffrfm_bits;

/* FIFO Critical Level Register (FCL) */
typedef struct {
  __REG32 CL                  : 8;
  __REG32                     :24;
} __ffcl_bits;

/* Message Handler Status (MHDS) */
typedef struct {
  __REG32 PIBF                : 1;
  __REG32 POBF                : 1;
  __REG32 PMR                 : 1;
  __REG32 PTFB1               : 1;
  __REG32 PTFB2               : 1;
  __REG32 FMBD                : 1;
  __REG32 MFMB                : 1;
  __REG32 CRAM                : 1;
  __REG32 FMB                 : 7;
  __REG32                     : 1;
  __REG32 MBT                 : 7;
  __REG32                     : 1;
  __REG32 MBU                 : 7;
  __REG32                     : 1;
} __fmhds_bits;

/* Last Dynamic Transmit Slot (LDTS) */
typedef struct {
  __REG32 LDTA                :11;
  __REG32                     : 5;
  __REG32 LDTB                :11;
  __REG32                     : 5;
} __fldts_bits;

/* FIFO Status Register (FSR) */
typedef struct {
  __REG32 RFNE                : 1;
  __REG32 RFCL                : 1;
  __REG32 RFO                 : 1;
  __REG32                     : 5;
  __REG32 RFFL                : 8;
  __REG32                     :16;
} __ffsr_bits;

/* Message Handler Constraints Flags (MHDF) */
typedef struct {
  __REG32 SNUA                : 1;
  __REG32 SNUB                : 1;
  __REG32 FNFA                : 1;
  __REG32 FNFB                : 1;
  __REG32 TBFA                : 1;
  __REG32 TBFB                : 1;
  __REG32 TNSB                : 1;
  __REG32 TNSA                : 1;
  __REG32 WAHP                : 1;
  __REG32                     :23;
} __fmhdf_bits;

/* Transmission Request Register 1 (TXRQ1) */
typedef struct {
  __REG32 TXR0                : 1;
  __REG32 TXR1                : 1;
  __REG32 TXR2                : 1;
  __REG32 TXR3                : 1;
  __REG32 TXR4                : 1;
  __REG32 TXR5                : 1;
  __REG32 TXR6                : 1;
  __REG32 TXR7                : 1;
  __REG32 TXR8                : 1;
  __REG32 TXR9                : 1;
  __REG32 TXR10               : 1;
  __REG32 TXR11               : 1;
  __REG32 TXR12               : 1;
  __REG32 TXR13               : 1;
  __REG32 TXR14               : 1;
  __REG32 TXR15               : 1;
  __REG32 TXR16               : 1;
  __REG32 TXR17               : 1;
  __REG32 TXR18               : 1;
  __REG32 TXR19               : 1;
  __REG32 TXR20               : 1;
  __REG32 TXR21               : 1;
  __REG32 TXR22               : 1;
  __REG32 TXR23               : 1;
  __REG32 TXR24               : 1;
  __REG32 TXR25               : 1;
  __REG32 TXR26               : 1;
  __REG32 TXR27               : 1;
  __REG32 TXR28               : 1;
  __REG32 TXR29               : 1;
  __REG32 TXR30               : 1;
  __REG32 TXR31               : 1;
} __ftxrq1_bits;

/* Transmission Request Register 2 (TXRQ2) */
typedef struct {
  __REG32 TXR32               : 1;
  __REG32 TXR33               : 1;
  __REG32 TXR34               : 1;
  __REG32 TXR35               : 1;
  __REG32 TXR36               : 1;
  __REG32 TXR37               : 1;
  __REG32 TXR38               : 1;
  __REG32 TXR39               : 1;
  __REG32 TXR40               : 1;
  __REG32 TXR41               : 1;
  __REG32 TXR42               : 1;
  __REG32 TXR43               : 1;
  __REG32 TXR44               : 1;
  __REG32 TXR45               : 1;
  __REG32 TXR46               : 1;
  __REG32 TXR47               : 1;
  __REG32 TXR48               : 1;
  __REG32 TXR49               : 1;
  __REG32 TXR50               : 1;
  __REG32 TXR51               : 1;
  __REG32 TXR52               : 1;
  __REG32 TXR53               : 1;
  __REG32 TXR54               : 1;
  __REG32 TXR55               : 1;
  __REG32 TXR56               : 1;
  __REG32 TXR57               : 1;
  __REG32 TXR58               : 1;
  __REG32 TXR59               : 1;
  __REG32 TXR60               : 1;
  __REG32 TXR61               : 1;
  __REG32 TXR62               : 1;
  __REG32 TXR63               : 1;
} __ftxrq2_bits;

/* Transmission Request Register 3 (TXRQ3) */
typedef struct {
  __REG32 TXR64               : 1;
  __REG32 TXR65               : 1;
  __REG32 TXR66               : 1;
  __REG32 TXR67               : 1;
  __REG32 TXR68               : 1;
  __REG32 TXR69               : 1;
  __REG32 TXR70               : 1;
  __REG32 TXR71               : 1;
  __REG32 TXR72               : 1;
  __REG32 TXR73               : 1;
  __REG32 TXR74               : 1;
  __REG32 TXR75               : 1;
  __REG32 TXR76               : 1;
  __REG32 TXR77               : 1;
  __REG32 TXR78               : 1;
  __REG32 TXR79               : 1;
  __REG32 TXR80               : 1;
  __REG32 TXR81               : 1;
  __REG32 TXR82               : 1;
  __REG32 TXR83               : 1;
  __REG32 TXR84               : 1;
  __REG32 TXR85               : 1;
  __REG32 TXR86               : 1;
  __REG32 TXR87               : 1;
  __REG32 TXR88               : 1;
  __REG32 TXR89               : 1;
  __REG32 TXR90               : 1;
  __REG32 TXR91               : 1;
  __REG32 TXR92               : 1;
  __REG32 TXR93               : 1;
  __REG32 TXR94               : 1;
  __REG32 TXR95               : 1;
} __ftxrq3_bits;

/* Transmission Request Register 4 (TXRQ4) */
typedef struct {
  __REG32 TXR96               : 1;
  __REG32 TXR97               : 1;
  __REG32 TXR98               : 1;
  __REG32 TXR99               : 1;
  __REG32 TXR100              : 1;
  __REG32 TXR101              : 1;
  __REG32 TXR102              : 1;
  __REG32 TXR103              : 1;
  __REG32 TXR104              : 1;
  __REG32 TXR105              : 1;
  __REG32 TXR106              : 1;
  __REG32 TXR107              : 1;
  __REG32 TXR108              : 1;
  __REG32 TXR109              : 1;
  __REG32 TXR110              : 1;
  __REG32 TXR111              : 1;
  __REG32 TXR112              : 1;
  __REG32 TXR113              : 1;
  __REG32 TXR114              : 1;
  __REG32 TXR115              : 1;
  __REG32 TXR116              : 1;
  __REG32 TXR117              : 1;
  __REG32 TXR118              : 1;
  __REG32 TXR119              : 1;
  __REG32 TXR120              : 1;
  __REG32 TXR121              : 1;
  __REG32 TXR122              : 1;
  __REG32 TXR123              : 1;
  __REG32 TXR124              : 1;
  __REG32 TXR125              : 1;
  __REG32 TXR126              : 1;
  __REG32 TXR127              : 1;
} __ftxrq4_bits;

/* New Data Register 1 (NDAT1) */
typedef struct {
  __REG32 ND0                : 1;
  __REG32 ND1                : 1;
  __REG32 ND2                : 1;
  __REG32 ND3                : 1;
  __REG32 ND4                : 1;
  __REG32 ND5                : 1;
  __REG32 ND6                : 1;
  __REG32 ND7                : 1;
  __REG32 ND8                : 1;
  __REG32 ND9                : 1;
  __REG32 ND10               : 1;
  __REG32 ND11               : 1;
  __REG32 ND12               : 1;
  __REG32 ND13               : 1;
  __REG32 ND14               : 1;
  __REG32 ND15               : 1;
  __REG32 ND16               : 1;
  __REG32 ND17               : 1;
  __REG32 ND18               : 1;
  __REG32 ND19               : 1;
  __REG32 ND20               : 1;
  __REG32 ND21               : 1;
  __REG32 ND22               : 1;
  __REG32 ND23               : 1;
  __REG32 ND24               : 1;
  __REG32 ND25               : 1;
  __REG32 ND26               : 1;
  __REG32 ND27               : 1;
  __REG32 ND28               : 1;
  __REG32 ND29               : 1;
  __REG32 ND30               : 1;
  __REG32 ND31               : 1;
} __fndat1_bits;

/* New Data Register 2 (NDAT2) */
typedef struct {
  __REG32 ND32               : 1;
  __REG32 ND33               : 1;
  __REG32 ND34               : 1;
  __REG32 ND35               : 1;
  __REG32 ND36               : 1;
  __REG32 ND37               : 1;
  __REG32 ND38               : 1;
  __REG32 ND39               : 1;
  __REG32 ND40               : 1;
  __REG32 ND41               : 1;
  __REG32 ND42               : 1;
  __REG32 ND43               : 1;
  __REG32 ND44               : 1;
  __REG32 ND45               : 1;
  __REG32 ND46               : 1;
  __REG32 ND47               : 1;
  __REG32 ND48               : 1;
  __REG32 ND49               : 1;
  __REG32 ND50               : 1;
  __REG32 ND51               : 1;
  __REG32 ND52               : 1;
  __REG32 ND53               : 1;
  __REG32 ND54               : 1;
  __REG32 ND55               : 1;
  __REG32 ND56               : 1;
  __REG32 ND57               : 1;
  __REG32 ND58               : 1;
  __REG32 ND59               : 1;
  __REG32 ND60               : 1;
  __REG32 ND61               : 1;
  __REG32 ND62               : 1;
  __REG32 ND63               : 1;
} __fndat2_bits;

/* New Data Register 3 (NDAT3) */
typedef struct {
  __REG32 ND64               : 1;
  __REG32 ND65               : 1;
  __REG32 ND66               : 1;
  __REG32 ND67               : 1;
  __REG32 ND68               : 1;
  __REG32 ND69               : 1;
  __REG32 ND70               : 1;
  __REG32 ND71               : 1;
  __REG32 ND72               : 1;
  __REG32 ND73               : 1;
  __REG32 ND74               : 1;
  __REG32 ND75               : 1;
  __REG32 ND76               : 1;
  __REG32 ND77               : 1;
  __REG32 ND78               : 1;
  __REG32 ND79               : 1;
  __REG32 ND80               : 1;
  __REG32 ND81               : 1;
  __REG32 ND82               : 1;
  __REG32 ND83               : 1;
  __REG32 ND84               : 1;
  __REG32 ND85               : 1;
  __REG32 ND86               : 1;
  __REG32 ND87               : 1;
  __REG32 ND88               : 1;
  __REG32 ND89               : 1;
  __REG32 ND90               : 1;
  __REG32 ND91               : 1;
  __REG32 ND92               : 1;
  __REG32 ND93               : 1;
  __REG32 ND94               : 1;
  __REG32 ND95               : 1;
} __fndat3_bits;

/* New Data Register 4 (NDAT4) */
typedef struct {
  __REG32 ND96               : 1;
  __REG32 ND97               : 1;
  __REG32 ND98               : 1;
  __REG32 ND99               : 1;
  __REG32 ND100              : 1;
  __REG32 ND101              : 1;
  __REG32 ND102              : 1;
  __REG32 ND103              : 1;
  __REG32 ND104              : 1;
  __REG32 ND105              : 1;
  __REG32 ND106              : 1;
  __REG32 ND107              : 1;
  __REG32 ND108              : 1;
  __REG32 ND109              : 1;
  __REG32 ND110              : 1;
  __REG32 ND111              : 1;
  __REG32 ND112              : 1;
  __REG32 ND113              : 1;
  __REG32 ND114              : 1;
  __REG32 ND115              : 1;
  __REG32 ND116              : 1;
  __REG32 ND117              : 1;
  __REG32 ND118              : 1;
  __REG32 ND119              : 1;
  __REG32 ND120              : 1;
  __REG32 ND121              : 1;
  __REG32 ND122              : 1;
  __REG32 ND123              : 1;
  __REG32 ND124              : 1;
  __REG32 ND125              : 1;
  __REG32 ND126              : 1;
  __REG32 ND127              : 1;
} __fndat4_bits;

/* Message Buffer Status Changed Register 1 (MBSC1) */
typedef struct {
  __REG32 MBS0                : 1;
  __REG32 MBS1                : 1;
  __REG32 MBS2                : 1;
  __REG32 MBS3                : 1;
  __REG32 MBS4                : 1;
  __REG32 MBS5                : 1;
  __REG32 MBS6                : 1;
  __REG32 MBS7                : 1;
  __REG32 MBS8                : 1;
  __REG32 MBS9                : 1;
  __REG32 MBS10               : 1;
  __REG32 MBS11               : 1;
  __REG32 MBS12               : 1;
  __REG32 MBS13               : 1;
  __REG32 MBS14               : 1;
  __REG32 MBS15               : 1;
  __REG32 MBS16               : 1;
  __REG32 MBS17               : 1;
  __REG32 MBS18               : 1;
  __REG32 MBS19               : 1;
  __REG32 MBS20               : 1;
  __REG32 MBS21               : 1;
  __REG32 MBS22               : 1;
  __REG32 MBS23               : 1;
  __REG32 MBS24               : 1;
  __REG32 MBS25               : 1;
  __REG32 MBS26               : 1;
  __REG32 MBS27               : 1;
  __REG32 MBS28               : 1;
  __REG32 MBS29               : 1;
  __REG32 MBS30               : 1;
  __REG32 MBS31               : 1;
} __fmbsc1_bits;

/* Message Buffer Status Changed Register 2 (MBSC2) */
typedef struct {
  __REG32 MBS32               : 1;
  __REG32 MBS33               : 1;
  __REG32 MBS34               : 1;
  __REG32 MBS35               : 1;
  __REG32 MBS36               : 1;
  __REG32 MBS37               : 1;
  __REG32 MBS38               : 1;
  __REG32 MBS39               : 1;
  __REG32 MBS40               : 1;
  __REG32 MBS41               : 1;
  __REG32 MBS42               : 1;
  __REG32 MBS43               : 1;
  __REG32 MBS44               : 1;
  __REG32 MBS45               : 1;
  __REG32 MBS46               : 1;
  __REG32 MBS47               : 1;
  __REG32 MBS48               : 1;
  __REG32 MBS49               : 1;
  __REG32 MBS50               : 1;
  __REG32 MBS51               : 1;
  __REG32 MBS52               : 1;
  __REG32 MBS53               : 1;
  __REG32 MBS54               : 1;
  __REG32 MBS55               : 1;
  __REG32 MBS56               : 1;
  __REG32 MBS57               : 1;
  __REG32 MBS58               : 1;
  __REG32 MBS59               : 1;
  __REG32 MBS60               : 1;
  __REG32 MBS61               : 1;
  __REG32 MBS62               : 1;
  __REG32 MBS63               : 1;
} __fmbsc2_bits;

/* Message Buffer Status Changed Register 2 (MBSC2) */
typedef struct {
  __REG32 MBS64               : 1;
  __REG32 MBS65               : 1;
  __REG32 MBS66               : 1;
  __REG32 MBS67               : 1;
  __REG32 MBS68               : 1;
  __REG32 MBS69               : 1;
  __REG32 MBS70               : 1;
  __REG32 MBS71               : 1;
  __REG32 MBS72               : 1;
  __REG32 MBS73               : 1;
  __REG32 MBS74               : 1;
  __REG32 MBS75               : 1;
  __REG32 MBS76               : 1;
  __REG32 MBS77               : 1;
  __REG32 MBS78               : 1;
  __REG32 MBS79               : 1;
  __REG32 MBS80               : 1;
  __REG32 MBS81               : 1;
  __REG32 MBS82               : 1;
  __REG32 MBS83               : 1;
  __REG32 MBS84               : 1;
  __REG32 MBS85               : 1;
  __REG32 MBS86               : 1;
  __REG32 MBS87               : 1;
  __REG32 MBS88               : 1;
  __REG32 MBS89               : 1;
  __REG32 MBS90               : 1;
  __REG32 MBS91               : 1;
  __REG32 MBS92               : 1;
  __REG32 MBS93               : 1;
  __REG32 MBS94               : 1;
  __REG32 MBS95               : 1;
} __fmbsc3_bits;

/* Message Buffer Status Changed Register 4 (MBSC4) */
typedef struct {
  __REG32 MBS96               : 1;
  __REG32 MBS97               : 1;
  __REG32 MBS98               : 1;
  __REG32 MBS99               : 1;
  __REG32 MBS100              : 1;
  __REG32 MBS101              : 1;
  __REG32 MBS102              : 1;
  __REG32 MBS103              : 1;
  __REG32 MBS104              : 1;
  __REG32 MBS105              : 1;
  __REG32 MBS106              : 1;
  __REG32 MBS107              : 1;
  __REG32 MBS108              : 1;
  __REG32 MBS109              : 1;
  __REG32 MBS110              : 1;
  __REG32 MBS111              : 1;
  __REG32 MBS112              : 1;
  __REG32 MBS113              : 1;
  __REG32 MBS114              : 1;
  __REG32 MBS115              : 1;
  __REG32 MBS116              : 1;
  __REG32 MBS117              : 1;
  __REG32 MBS118              : 1;
  __REG32 MBS119              : 1;
  __REG32 MBS120              : 1;
  __REG32 MBS121              : 1;
  __REG32 MBS122              : 1;
  __REG32 MBS123              : 1;
  __REG32 MBS124              : 1;
  __REG32 MBS125              : 1;
  __REG32 MBS126              : 1;
  __REG32 MBS127              : 1;
} __fmbsc4_bits;

/* Core Release Register (CREL) */
typedef struct {
  __REG32 DAY                 : 8;
  __REG32 MON                 : 8;
  __REG32 YEAR                : 4;
  __REG32 STEP                : 8;
  __REG32 REL                 : 4;
} __fcrel_bits;

/* Write Header Section Register 1 (WRHS1) */
typedef struct {
  __REG32 FID                 :11;
  __REG32                     : 5;
  __REG32 CYC                 : 7;
  __REG32                     : 1;
  __REG32 CHA                 : 1;
  __REG32 CHB                 : 1;
  __REG32 CFG                 : 1;
  __REG32 PPIT                : 1;
  __REG32 TXM                 : 1;
  __REG32 MBI                 : 1;
  __REG32                     : 2;
} __fwrhs1_bits;

/* Write Header Section Register 2 (WRHS2) */
typedef struct {
  __REG32 CRC                 :11;
  __REG32                     : 5;
  __REG32 PLC                 : 7;
  __REG32                     : 9;
} __fwrhs2_bits;

/* Write Header Section Register 3 (WRHS3) */
typedef struct {
  __REG32 DP                  :11;
  __REG32                     :21;
} __fwrhs3_bits;

/* Input Buffer Command Mask (IBCM) */
typedef struct {
  __REG32 LHSH                : 1;
  __REG32 LDSH                : 1;
  __REG32 STXRH               : 1;
  __REG32                     :13;
  __REG32 LHSS                : 1;
  __REG32 LDSS                : 1;
  __REG32 STXRS               : 1;
  __REG32                     :13;
} __fibcm_bits;

/* Input Buffer Command Request Register (IBCR) */
typedef struct {
  __REG32 IBRH                : 7;
  __REG32                     : 8;
  __REG32 IBSYH               : 1;
  __REG32 IBRS                : 7;
  __REG32                     : 8;
  __REG32 IBSYS               : 1;
} __fibcr_bits;

/* Read Header Section Register 1 (RDHS1) */
typedef struct {
  __REG32 FID                 :11;
  __REG32                     : 5;
  __REG32 CYC                 : 7;
  __REG32                     : 1;
  __REG32 CHA                 : 1;
  __REG32 CHB                 : 1;
  __REG32 CFG                 : 1;
  __REG32 PPIT                : 1;
  __REG32 TXM                 : 1;
  __REG32 MBI                 : 1;
  __REG32                     : 2;
} __frdhs1_bits;

/* Read Header Section 2 (RDHS2) */
typedef struct {
  __REG32 CRC                 :11;
  __REG32                     : 5;
  __REG32 PLC                 : 7;
  __REG32                     : 1;
  __REG32 PLR                 : 7;
  __REG32                     : 1;
} __frdhs2_bits;

/* Read Header Section 3 (RDHS3) */
typedef struct {
  __REG32 DP                  :11;
  __REG32                     : 5;
  __REG32 RCC                 : 6;
  __REG32                     : 2;
  __REG32 RCI                 : 1;
  __REG32 SFI                 : 1;
  __REG32 SYN                 : 1;
  __REG32 NFI                 : 1;
  __REG32 PPI                 : 1;
  __REG32 RES                 : 1;
  __REG32                     : 2;
} __frdhs3_bits;

/* Message Buffer Status Register (MBS) */
typedef struct {
  __REG32 VFRA                : 1;
  __REG32 VFRB                : 1;
  __REG32 SEOA                : 1;
  __REG32 SEOB                : 1;
  __REG32 CEOA                : 1;
  __REG32 CEOB                : 1;
  __REG32 SVOA                : 1;
  __REG32 SVOB                : 1;
  __REG32 TCIA                : 1;
  __REG32 TCIB                : 1;
  __REG32 ESA                 : 1;
  __REG32 ESB                 : 1;
  __REG32 MLST                : 1;
  __REG32                     : 1;
  __REG32 FTA                 : 1;
  __REG32 FTB                 : 1;
  __REG32 CCS                 : 6;
  __REG32                     : 2;
  __REG32 RCIS                : 1;
  __REG32 SFIS                : 1;
  __REG32 SYNS                : 1;
  __REG32 NFIS                : 1;
  __REG32 PPIS                : 1;
  __REG32 RESS                : 1;
  __REG32                     : 2;
} __fmbs_bits;

/* Output Buffer Command Mask (OBCM) */
typedef struct {
  __REG32 RHSS                : 1;
  __REG32 RDSS                : 1;
  __REG32                     :14;
  __REG32 RHSH                : 1;
  __REG32 RDSH                : 1;
  __REG32                     :14;
} __fobcm_bits;

/* Output Buffer Command Mask Register (OBCR) */
typedef struct {
  __REG32 OBRS                : 7;
  __REG32                     : 1;
  __REG32 VIEW                : 1;
  __REG32 REQ                 : 1;
  __REG32                     : 5;
  __REG32 OBSYS               : 1;
  __REG32 OBRH                : 7;
  __REG32                     : 9;
} __fobcr_bits;

/* Global Configuration Register (HETGCR) */
typedef struct {
  __REG32 TO                  : 1;
  __REG32                     :15;
  __REG32 CMS                 : 1;
  __REG32 IS                  : 1;
  __REG32 PPF                 : 1;
  __REG32                     : 2;
  __REG32 MP                  : 2;
  __REG32                     : 1;
  __REG32 HET_PIN_ENA         : 1;
  __REG32                     : 7;
} __hetgcr_bits;

/* Prescale Factor Register (HETPFR) */
typedef struct {
  __REG32 HRPFC               : 6;
  __REG32                     : 2;
  __REG32 LRPFC               : 3;
  __REG32                     :21;
} __hetpfr_bits;

/* NHET Current Address Register (HETADDR) */
typedef struct {
  __REG32 HETADDR             : 9;
  __REG32                     :23;
} __hetaddr_bits;

/* NHET Offset Index Priority Level 1 Register (HETOFF1) */
typedef struct {
  __REG32 OFFSET1             : 6;
  __REG32                     :26;
} __hetoff1_bits;

/* NHET Offset Index Priority Level 2 Register (HETOFF2) */
typedef struct {
  __REG32 OFFSET2             : 6;
  __REG32                     :26;
} __hetoff2_bits;

/* NHET Interrupt Enable Set Register (HETINTENAS) */
typedef struct {
  __REG32 HETINTENAS0         : 1;
  __REG32 HETINTENAS1         : 1;
  __REG32 HETINTENAS2         : 1;
  __REG32 HETINTENAS3         : 1;
  __REG32 HETINTENAS4         : 1;
  __REG32 HETINTENAS5         : 1;
  __REG32 HETINTENAS6         : 1;
  __REG32 HETINTENAS7         : 1;
  __REG32 HETINTENAS8         : 1;
  __REG32 HETINTENAS9         : 1;
  __REG32 HETINTENAS10        : 1;
  __REG32 HETINTENAS11        : 1;
  __REG32 HETINTENAS12        : 1;
  __REG32 HETINTENAS13        : 1;
  __REG32 HETINTENAS14        : 1;
  __REG32 HETINTENAS15        : 1;
  __REG32 HETINTENAS16        : 1;
  __REG32 HETINTENAS17        : 1;
  __REG32 HETINTENAS18        : 1;
  __REG32 HETINTENAS19        : 1;
  __REG32 HETINTENAS20        : 1;
  __REG32 HETINTENAS21        : 1;
  __REG32 HETINTENAS22        : 1;
  __REG32 HETINTENAS23        : 1;
  __REG32 HETINTENAS24        : 1;
  __REG32 HETINTENAS25        : 1;
  __REG32 HETINTENAS26        : 1;
  __REG32 HETINTENAS27        : 1;
  __REG32 HETINTENAS28        : 1;
  __REG32 HETINTENAS29        : 1;
  __REG32 HETINTENAS30        : 1;
  __REG32 HETINTENAS31        : 1;
} __hetintenas_bits;

/* Interrupt Enable Clear Register (HETINTENAC) */
typedef struct {
  __REG32 HETINTENAC0         : 1;
  __REG32 HETINTENAC1         : 1;
  __REG32 HETINTENAC2         : 1;
  __REG32 HETINTENAC3         : 1;
  __REG32 HETINTENAC4         : 1;
  __REG32 HETINTENAC5         : 1;
  __REG32 HETINTENAC6         : 1;
  __REG32 HETINTENAC7         : 1;
  __REG32 HETINTENAC8         : 1;
  __REG32 HETINTENAC9         : 1;
  __REG32 HETINTENAC10        : 1;
  __REG32 HETINTENAC11        : 1;
  __REG32 HETINTENAC12        : 1;
  __REG32 HETINTENAC13        : 1;
  __REG32 HETINTENAC14        : 1;
  __REG32 HETINTENAC15        : 1;
  __REG32 HETINTENAC16        : 1;
  __REG32 HETINTENAC17        : 1;
  __REG32 HETINTENAC18        : 1;
  __REG32 HETINTENAC19        : 1;
  __REG32 HETINTENAC20        : 1;
  __REG32 HETINTENAC21        : 1;
  __REG32 HETINTENAC22        : 1;
  __REG32 HETINTENAC23        : 1;
  __REG32 HETINTENAC24        : 1;
  __REG32 HETINTENAC25        : 1;
  __REG32 HETINTENAC26        : 1;
  __REG32 HETINTENAC27        : 1;
  __REG32 HETINTENAC28        : 1;
  __REG32 HETINTENAC29        : 1;
  __REG32 HETINTENAC30        : 1;
  __REG32 HETINTENAC31        : 1;
} __hetintenac_bits;

/* Exception Control Register 1 (HETEXC1) */
typedef struct {
  __REG32 PRGM_OVRFL_PRY      : 1;
  __REG32 APCNT_UNRFL_PRY     : 1;
  __REG32 APCNT_OVRFL_PRY     : 1;
  __REG32                     : 5;
  __REG32 PRGM_OVRFL_ENA      : 1;
  __REG32                     : 7;
  __REG32 APCNT_UNRFL_ENA     : 1;
  __REG32                     : 7;
  __REG32 APCNT_OVRFL_ENA     : 1;
  __REG32                     : 7;
} __hetexc1_bits;

/* Exception Control Register 2 (HETEXC2) */
typedef struct {
  __REG32 PRGM_OVRFL_FLAG     : 1;
  __REG32 APCNT_UNRFL_FLAG    : 1;
  __REG32 APCNT_OVRFL_FLAG    : 1;
  __REG32                     : 5;
  __REG32 DEBUG_STATUS_FLAG   : 1;
  __REG32                     :23;
} __hetexc2_bits;

/* Interrupt Priority Register (HETPRY) */
typedef struct {
  __REG32 HETPRY0             : 1;
  __REG32 HETPRY1             : 1;
  __REG32 HETPRY2             : 1;
  __REG32 HETPRY3             : 1;
  __REG32 HETPRY4             : 1;
  __REG32 HETPRY5             : 1;
  __REG32 HETPRY6             : 1;
  __REG32 HETPRY7             : 1;
  __REG32 HETPRY8             : 1;
  __REG32 HETPRY9             : 1;
  __REG32 HETPRY10            : 1;
  __REG32 HETPRY11            : 1;
  __REG32 HETPRY12            : 1;
  __REG32 HETPRY13            : 1;
  __REG32 HETPRY14            : 1;
  __REG32 HETPRY15            : 1;
  __REG32 HETPRY16            : 1;
  __REG32 HETPRY17            : 1;
  __REG32 HETPRY18            : 1;
  __REG32 HETPRY19            : 1;
  __REG32 HETPRY20            : 1;
  __REG32 HETPRY21            : 1;
  __REG32 HETPRY22            : 1;
  __REG32 HETPRY23            : 1;
  __REG32 HETPRY24            : 1;
  __REG32 HETPRY25            : 1;
  __REG32 HETPRY26            : 1;
  __REG32 HETPRY27            : 1;
  __REG32 HETPRY28            : 1;
  __REG32 HETPRY29            : 1;
  __REG32 HETPRY30            : 1;
  __REG32 HETPRY31            : 1;
} __hetpry_bits;

/* Interrupt Flag Register (HETFLG) */
typedef struct {
  __REG32 HETFLAG0             : 1;
  __REG32 HETFLAG1             : 1;
  __REG32 HETFLAG2             : 1;
  __REG32 HETFLAG3             : 1;
  __REG32 HETFLAG4             : 1;
  __REG32 HETFLAG5             : 1;
  __REG32 HETFLAG6             : 1;
  __REG32 HETFLAG7             : 1;
  __REG32 HETFLAG8             : 1;
  __REG32 HETFLAG9             : 1;
  __REG32 HETFLAG10            : 1;
  __REG32 HETFLAG11            : 1;
  __REG32 HETFLAG12            : 1;
  __REG32 HETFLAG13            : 1;
  __REG32 HETFLAG14            : 1;
  __REG32 HETFLAG15            : 1;
  __REG32 HETFLAG16            : 1;
  __REG32 HETFLAG17            : 1;
  __REG32 HETFLAG18            : 1;
  __REG32 HETFLAG19            : 1;
  __REG32 HETFLAG20            : 1;
  __REG32 HETFLAG21            : 1;
  __REG32 HETFLAG22            : 1;
  __REG32 HETFLAG23            : 1;
  __REG32 HETFLAG24            : 1;
  __REG32 HETFLAG25            : 1;
  __REG32 HETFLAG26            : 1;
  __REG32 HETFLAG27            : 1;
  __REG32 HETFLAG28            : 1;
  __REG32 HETFLAG29            : 1;
  __REG32 HETFLAG30            : 1;
  __REG32 HETFLAG31            : 1;
} __hetflg_bits;

/* AND Share Control Register (HETAND) */
typedef struct {
  __REG32 AND_SHARE_1_0        : 1;
  __REG32 AND_SHARE_3_2        : 1;
  __REG32 AND_SHARE_5_4        : 1;
  __REG32 AND_SHARE_7_6        : 1;
  __REG32 AND_SHARE_9_8        : 1;
  __REG32 AND_SHARE_11_10      : 1;
  __REG32 AND_SHARE_13_12      : 1;
  __REG32 AND_SHARE_15_14      : 1;
  __REG32 AND_SHARE_17_16      : 1;
  __REG32 AND_SHARE_19_18      : 1;
  __REG32 AND_SHARE_21_20      : 1;
  __REG32 AND_SHARE_23_22      : 1;
  __REG32 AND_SHARE_25_24      : 1;
  __REG32 AND_SHARE_27_26      : 1;
  __REG32 AND_SHARE_29_28      : 1;
  __REG32 AND_SHARE_31_30      : 1;
  __REG32                      :16;
} __hetand_bits;

/* HR Share Control Register (HETHRSH) */
typedef struct {
  __REG32 HR_SHARE_1_0         : 1;
  __REG32 HR_SHARE_3_2         : 1;
  __REG32 HR_SHARE_5_4         : 1;
  __REG32 HR_SHARE_7_6         : 1;
  __REG32 HR_SHARE_9_8         : 1;
  __REG32 HR_SHARE_11_10       : 1;
  __REG32 HR_SHARE_13_12       : 1;
  __REG32 HR_SHARE_15_14       : 1;
  __REG32 HR_SHARE_17_16       : 1;
  __REG32 HR_SHARE_19_18       : 1;
  __REG32 HR_SHARE_21_20       : 1;
  __REG32 HR_SHARE_23_22       : 1;
  __REG32 HR_SHARE_25_24       : 1;
  __REG32 HR_SHARE_27_26       : 1;
  __REG32 HR_SHARE_29_28       : 1;
  __REG32 HR_SHARE_31_30       : 1;
  __REG32                      :16;
} __hethrsh_bits;

/* HR XOR-share Control Register (HETXOR) */
typedef struct {
  __REG32 XOR_SHARE_1_0        : 1;
  __REG32 XOR_SHARE_3_2        : 1;
  __REG32 XOR_SHARE_5_4        : 1;
  __REG32 XOR_SHARE_7_6        : 1;
  __REG32 XOR_SHARE_9_8        : 1;
  __REG32 XOR_SHARE_11_10      : 1;
  __REG32 XOR_SHARE_13_12      : 1;
  __REG32 XOR_SHARE_15_14      : 1;
  __REG32 XOR_SHARE_17_16      : 1;
  __REG32 XOR_SHARE_19_18      : 1;
  __REG32 XOR_SHARE_21_20      : 1;
  __REG32 XOR_SHARE_23_22      : 1;
  __REG32 XOR_SHARE_25_24      : 1;
  __REG32 XOR_SHARE_27_26      : 1;
  __REG32 XOR_SHARE_29_28      : 1;
  __REG32 XOR_SHARE_31_30      : 1;
  __REG32                      :16;
} __hetxor_bits;

/* Request Enable Set Register (HETREQENS) */
typedef struct {
  __REG32 REQ_ENA_0            : 1;
  __REG32 REQ_ENA_1            : 1;
  __REG32 REQ_ENA_2            : 1;
  __REG32 REQ_ENA_3            : 1;
  __REG32 REQ_ENA_4            : 1;
  __REG32 REQ_ENA_5            : 1;
  __REG32 REQ_ENA_6            : 1;
  __REG32 REQ_ENA_7            : 1;
  __REG32                      :24;
} __hetreqens_bits;

/* Request Enable Clear Register (HETREQENC) */
typedef struct {
  __REG32 REQ_DIS_0            : 1;
  __REG32 REQ_DIS_1            : 1;
  __REG32 REQ_DIS_2            : 1;
  __REG32 REQ_DIS_3            : 1;
  __REG32 REQ_DIS_4            : 1;
  __REG32 REQ_DIS_5            : 1;
  __REG32 REQ_DIS_6            : 1;
  __REG32 REQ_DIS_7            : 1;
  __REG32                      :24;
} __hetreqenc_bits;

/* Request Destination Select Register (HETREQDS) */
typedef struct {
  __REG32 TDS_0                : 1;
  __REG32 TDS_1                : 1;
  __REG32 TDS_2                : 1;
  __REG32 TDS_3                : 1;
  __REG32 TDS_4                : 1;
  __REG32 TDS_5                : 1;
  __REG32 TDS_6                : 1;
  __REG32 TDS_7                : 1;
  __REG32                      : 8;
  __REG32 TDBS_0               : 1;
  __REG32 TDBS_1               : 1;
  __REG32 TDBS_2               : 1;
  __REG32 TDBS_3               : 1;
  __REG32 TDBS_4               : 1;
  __REG32 TDBS_5               : 1;
  __REG32 TDBS_6               : 1;
  __REG32 TDBS_7               : 1;
  __REG32                      : 8;
} __hetreqds_bits;

/* NHET Direction Register (HETDIR) */
typedef struct {
  __REG32 HETDIR0              : 1;
  __REG32 HETDIR1              : 1;
  __REG32 HETDIR2              : 1;
  __REG32 HETDIR3              : 1;
  __REG32 HETDIR4              : 1;
  __REG32 HETDIR5              : 1;
  __REG32 HETDIR6              : 1;
  __REG32 HETDIR7              : 1;
  __REG32 HETDIR8              : 1;
  __REG32 HETDIR9              : 1;
  __REG32 HETDIR10             : 1;
  __REG32 HETDIR11             : 1;
  __REG32 HETDIR12             : 1;
  __REG32 HETDIR13             : 1;
  __REG32 HETDIR14             : 1;
  __REG32 HETDIR15             : 1;
  __REG32 HETDIR16             : 1;
  __REG32 HETDIR17             : 1;
  __REG32 HETDIR18             : 1;
  __REG32 HETDIR19             : 1;
  __REG32 HETDIR20             : 1;
  __REG32 HETDIR21             : 1;
  __REG32 HETDIR22             : 1;
  __REG32 HETDIR23             : 1;
  __REG32 HETDIR24             : 1;
  __REG32 HETDIR25             : 1;
  __REG32 HETDIR26             : 1;
  __REG32 HETDIR27             : 1;
  __REG32 HETDIR28             : 1;
  __REG32 HETDIR29             : 1;
  __REG32 HETDIR30             : 1;
  __REG32 HETDIR31             : 1;
} __hetdir_bits;

/* NHET Data Input Register (HETDIN) */
typedef struct {
  __REG32 HETDIN0              : 1;
  __REG32 HETDIN1              : 1;
  __REG32 HETDIN2              : 1;
  __REG32 HETDIN3              : 1;
  __REG32 HETDIN4              : 1;
  __REG32 HETDIN5              : 1;
  __REG32 HETDIN6              : 1;
  __REG32 HETDIN7              : 1;
  __REG32 HETDIN8              : 1;
  __REG32 HETDIN9              : 1;
  __REG32 HETDIN10             : 1;
  __REG32 HETDIN11             : 1;
  __REG32 HETDIN12             : 1;
  __REG32 HETDIN13             : 1;
  __REG32 HETDIN14             : 1;
  __REG32 HETDIN15             : 1;
  __REG32 HETDIN16             : 1;
  __REG32 HETDIN17             : 1;
  __REG32 HETDIN18             : 1;
  __REG32 HETDIN19             : 1;
  __REG32 HETDIN20             : 1;
  __REG32 HETDIN21             : 1;
  __REG32 HETDIN22             : 1;
  __REG32 HETDIN23             : 1;
  __REG32 HETDIN24             : 1;
  __REG32 HETDIN25             : 1;
  __REG32 HETDIN26             : 1;
  __REG32 HETDIN27             : 1;
  __REG32 HETDIN28             : 1;
  __REG32 HETDIN29             : 1;
  __REG32 HETDIN30             : 1;
  __REG32 HETDIN31             : 1;
} __hetdin_bits;

/* NHET Data Output Register (HETDOUT) */
typedef struct {
  __REG32 HETDOUT0              : 1;
  __REG32 HETDOUT1              : 1;
  __REG32 HETDOUT2              : 1;
  __REG32 HETDOUT3              : 1;
  __REG32 HETDOUT4              : 1;
  __REG32 HETDOUT5              : 1;
  __REG32 HETDOUT6              : 1;
  __REG32 HETDOUT7              : 1;
  __REG32 HETDOUT8              : 1;
  __REG32 HETDOUT9              : 1;
  __REG32 HETDOUT10             : 1;
  __REG32 HETDOUT11             : 1;
  __REG32 HETDOUT12             : 1;
  __REG32 HETDOUT13             : 1;
  __REG32 HETDOUT14             : 1;
  __REG32 HETDOUT15             : 1;
  __REG32 HETDOUT16             : 1;
  __REG32 HETDOUT17             : 1;
  __REG32 HETDOUT18             : 1;
  __REG32 HETDOUT19             : 1;
  __REG32 HETDOUT20             : 1;
  __REG32 HETDOUT21             : 1;
  __REG32 HETDOUT22             : 1;
  __REG32 HETDOUT23             : 1;
  __REG32 HETDOUT24             : 1;
  __REG32 HETDOUT25             : 1;
  __REG32 HETDOUT26             : 1;
  __REG32 HETDOUT27             : 1;
  __REG32 HETDOUT28             : 1;
  __REG32 HETDOUT29             : 1;
  __REG32 HETDOUT30             : 1;
  __REG32 HETDOUT31             : 1;
} __hetdout_bits;

/* NHET Data Set Register (HETDSET) */
typedef struct {
  __REG32 HETDSET0              : 1;
  __REG32 HETDSET1              : 1;
  __REG32 HETDSET2              : 1;
  __REG32 HETDSET3              : 1;
  __REG32 HETDSET4              : 1;
  __REG32 HETDSET5              : 1;
  __REG32 HETDSET6              : 1;
  __REG32 HETDSET7              : 1;
  __REG32 HETDSET8              : 1;
  __REG32 HETDSET9              : 1;
  __REG32 HETDSET10             : 1;
  __REG32 HETDSET11             : 1;
  __REG32 HETDSET12             : 1;
  __REG32 HETDSET13             : 1;
  __REG32 HETDSET14             : 1;
  __REG32 HETDSET15             : 1;
  __REG32 HETDSET16             : 1;
  __REG32 HETDSET17             : 1;
  __REG32 HETDSET18             : 1;
  __REG32 HETDSET19             : 1;
  __REG32 HETDSET20             : 1;
  __REG32 HETDSET21             : 1;
  __REG32 HETDSET22             : 1;
  __REG32 HETDSET23             : 1;
  __REG32 HETDSET24             : 1;
  __REG32 HETDSET25             : 1;
  __REG32 HETDSET26             : 1;
  __REG32 HETDSET27             : 1;
  __REG32 HETDSET28             : 1;
  __REG32 HETDSET29             : 1;
  __REG32 HETDSET30             : 1;
  __REG32 HETDSET31             : 1;
} __hetdset_bits;

/* NHET Data Clear Register (HETDCLR) */
typedef struct {
  __REG32 HETDCLR0              : 1;
  __REG32 HETDCLR1              : 1;
  __REG32 HETDCLR2              : 1;
  __REG32 HETDCLR3              : 1;
  __REG32 HETDCLR4              : 1;
  __REG32 HETDCLR5              : 1;
  __REG32 HETDCLR6              : 1;
  __REG32 HETDCLR7              : 1;
  __REG32 HETDCLR8              : 1;
  __REG32 HETDCLR9              : 1;
  __REG32 HETDCLR10             : 1;
  __REG32 HETDCLR11             : 1;
  __REG32 HETDCLR12             : 1;
  __REG32 HETDCLR13             : 1;
  __REG32 HETDCLR14             : 1;
  __REG32 HETDCLR15             : 1;
  __REG32 HETDCLR16             : 1;
  __REG32 HETDCLR17             : 1;
  __REG32 HETDCLR18             : 1;
  __REG32 HETDCLR19             : 1;
  __REG32 HETDCLR20             : 1;
  __REG32 HETDCLR21             : 1;
  __REG32 HETDCLR22             : 1;
  __REG32 HETDCLR23             : 1;
  __REG32 HETDCLR24             : 1;
  __REG32 HETDCLR25             : 1;
  __REG32 HETDCLR26             : 1;
  __REG32 HETDCLR27             : 1;
  __REG32 HETDCLR28             : 1;
  __REG32 HETDCLR29             : 1;
  __REG32 HETDCLR30             : 1;
  __REG32 HETDCLR31             : 1;
} __hetdclr_bits;

/* NHET Open Drain Register (HETPDR) */
typedef struct {
  __REG32 HETPDR0              : 1;
  __REG32 HETPDR1              : 1;
  __REG32 HETPDR2              : 1;
  __REG32 HETPDR3              : 1;
  __REG32 HETPDR4              : 1;
  __REG32 HETPDR5              : 1;
  __REG32 HETPDR6              : 1;
  __REG32 HETPDR7              : 1;
  __REG32 HETPDR8              : 1;
  __REG32 HETPDR9              : 1;
  __REG32 HETPDR10             : 1;
  __REG32 HETPDR11             : 1;
  __REG32 HETPDR12             : 1;
  __REG32 HETPDR13             : 1;
  __REG32 HETPDR14             : 1;
  __REG32 HETPDR15             : 1;
  __REG32 HETPDR16             : 1;
  __REG32 HETPDR17             : 1;
  __REG32 HETPDR18             : 1;
  __REG32 HETPDR19             : 1;
  __REG32 HETPDR20             : 1;
  __REG32 HETPDR21             : 1;
  __REG32 HETPDR22             : 1;
  __REG32 HETPDR23             : 1;
  __REG32 HETPDR24             : 1;
  __REG32 HETPDR25             : 1;
  __REG32 HETPDR26             : 1;
  __REG32 HETPDR27             : 1;
  __REG32 HETPDR28             : 1;
  __REG32 HETPDR29             : 1;
  __REG32 HETPDR30             : 1;
  __REG32 HETPDR31             : 1;
} __hetpdr_bits;

/* NHET Pull Disable Register (HETPULDIS) */
typedef struct {
  __REG32 HETPULDIS0              : 1;
  __REG32 HETPULDIS1              : 1;
  __REG32 HETPULDIS2              : 1;
  __REG32 HETPULDIS3              : 1;
  __REG32 HETPULDIS4              : 1;
  __REG32 HETPULDIS5              : 1;
  __REG32 HETPULDIS6              : 1;
  __REG32 HETPULDIS7              : 1;
  __REG32 HETPULDIS8              : 1;
  __REG32 HETPULDIS9              : 1;
  __REG32 HETPULDIS10             : 1;
  __REG32 HETPULDIS11             : 1;
  __REG32 HETPULDIS12             : 1;
  __REG32 HETPULDIS13             : 1;
  __REG32 HETPULDIS14             : 1;
  __REG32 HETPULDIS15             : 1;
  __REG32 HETPULDIS16             : 1;
  __REG32 HETPULDIS17             : 1;
  __REG32 HETPULDIS18             : 1;
  __REG32 HETPULDIS19             : 1;
  __REG32 HETPULDIS20             : 1;
  __REG32 HETPULDIS21             : 1;
  __REG32 HETPULDIS22             : 1;
  __REG32 HETPULDIS23             : 1;
  __REG32 HETPULDIS24             : 1;
  __REG32 HETPULDIS25             : 1;
  __REG32 HETPULDIS26             : 1;
  __REG32 HETPULDIS27             : 1;
  __REG32 HETPULDIS28             : 1;
  __REG32 HETPULDIS29             : 1;
  __REG32 HETPULDIS30             : 1;
  __REG32 HETPULDIS31             : 1;
} __hetpuldis_bits;

/* NHET Pull Select Register (HETPSL) */
typedef struct {
  __REG32 HETPSL0              : 1;
  __REG32 HETPSL1              : 1;
  __REG32 HETPSL2              : 1;
  __REG32 HETPSL3              : 1;
  __REG32 HETPSL4              : 1;
  __REG32 HETPSL5              : 1;
  __REG32 HETPSL6              : 1;
  __REG32 HETPSL7              : 1;
  __REG32 HETPSL8              : 1;
  __REG32 HETPSL9              : 1;
  __REG32 HETPSL10             : 1;
  __REG32 HETPSL11             : 1;
  __REG32 HETPSL12             : 1;
  __REG32 HETPSL13             : 1;
  __REG32 HETPSL14             : 1;
  __REG32 HETPSL15             : 1;
  __REG32 HETPSL16             : 1;
  __REG32 HETPSL17             : 1;
  __REG32 HETPSL18             : 1;
  __REG32 HETPSL19             : 1;
  __REG32 HETPSL20             : 1;
  __REG32 HETPSL21             : 1;
  __REG32 HETPSL22             : 1;
  __REG32 HETPSL23             : 1;
  __REG32 HETPSL24             : 1;
  __REG32 HETPSL25             : 1;
  __REG32 HETPSL26             : 1;
  __REG32 HETPSL27             : 1;
  __REG32 HETPSL28             : 1;
  __REG32 HETPSL29             : 1;
  __REG32 HETPSL30             : 1;
  __REG32 HETPSL31             : 1;
} __hetpsl_bits;

/* Parity Control Register (HETPCR) */
typedef struct {
  __REG32 PARITY_ENA           : 4;
  __REG32                      : 4;
  __REG32 TEST                 : 1;
  __REG32                      :23;
} __hetpcr_bits;

/* Parity Address Register (HETPAR) */
typedef struct {
  __REG32 PAOFF                :13;
  __REG32                      :19;
} __hetpar_bits;

/* NHET Parity Pin Register (HETPPR) */
typedef struct {
  __REG32 HETPPR0              : 1;
  __REG32 HETPPR1              : 1;
  __REG32 HETPPR2              : 1;
  __REG32 HETPPR3              : 1;
  __REG32 HETPPR4              : 1;
  __REG32 HETPPR5              : 1;
  __REG32 HETPPR6              : 1;
  __REG32 HETPPR7              : 1;
  __REG32 HETPPR8              : 1;
  __REG32 HETPPR9              : 1;
  __REG32 HETPPR10             : 1;
  __REG32 HETPPR11             : 1;
  __REG32 HETPPR12             : 1;
  __REG32 HETPPR13             : 1;
  __REG32 HETPPR14             : 1;
  __REG32 HETPPR15             : 1;
  __REG32 HETPPR16             : 1;
  __REG32 HETPPR17             : 1;
  __REG32 HETPPR18             : 1;
  __REG32 HETPPR19             : 1;
  __REG32 HETPPR20             : 1;
  __REG32 HETPPR21             : 1;
  __REG32 HETPPR22             : 1;
  __REG32 HETPPR23             : 1;
  __REG32 HETPPR24             : 1;
  __REG32 HETPPR25             : 1;
  __REG32 HETPPR26             : 1;
  __REG32 HETPPR27             : 1;
  __REG32 HETPPR28             : 1;
  __REG32 HETPPR29             : 1;
  __REG32 HETPPR30             : 1;
  __REG32 HETPPR31             : 1;
} __hetppr_bits;

/* NHET Suppression Filter Preload Register (HETSFPRLD) */
typedef struct {
  __REG32 CPRLD                :10;
  __REG32                      : 6;
  __REG32 CCDIV                : 2;
  __REG32                      :14;
} __hetsfprld_bits;

/* NHET Suppression Filter Enable Register (HETSFENA) */
typedef struct {
  __REG32 HETSFENA0              : 1;
  __REG32 HETSFENA1              : 1;
  __REG32 HETSFENA2              : 1;
  __REG32 HETSFENA3              : 1;
  __REG32 HETSFENA4              : 1;
  __REG32 HETSFENA5              : 1;
  __REG32 HETSFENA6              : 1;
  __REG32 HETSFENA7              : 1;
  __REG32 HETSFENA8              : 1;
  __REG32 HETSFENA9              : 1;
  __REG32 HETSFENA10             : 1;
  __REG32 HETSFENA11             : 1;
  __REG32 HETSFENA12             : 1;
  __REG32 HETSFENA13             : 1;
  __REG32 HETSFENA14             : 1;
  __REG32 HETSFENA15             : 1;
  __REG32 HETSFENA16             : 1;
  __REG32 HETSFENA17             : 1;
  __REG32 HETSFENA18             : 1;
  __REG32 HETSFENA19             : 1;
  __REG32 HETSFENA20             : 1;
  __REG32 HETSFENA21             : 1;
  __REG32 HETSFENA22             : 1;
  __REG32 HETSFENA23             : 1;
  __REG32 HETSFENA24             : 1;
  __REG32 HETSFENA25             : 1;
  __REG32 HETSFENA26             : 1;
  __REG32 HETSFENA27             : 1;
  __REG32 HETSFENA28             : 1;
  __REG32 HETSFENA29             : 1;
  __REG32 HETSFENA30             : 1;
  __REG32 HETSFENA31             : 1;
} __hetsfena_bits;

/* NHET Loop Back Pair Select Register (HETLBPSEL) */
typedef struct {
  __REG32 LBPSEL_1_0             : 1;
  __REG32 LBPSEL_3_2             : 1;
  __REG32 LBPSEL_5_4             : 1;
  __REG32 LBPSEL_7_6             : 1;
  __REG32 LBPSEL_9_8             : 1;
  __REG32 LBPSEL_11_10           : 1;
  __REG32 LBPSEL_13_12           : 1;
  __REG32 LBPSEL_15_14           : 1;
  __REG32 LBPSEL_17_16           : 1;
  __REG32 LBBPEL_19_18           : 1;
  __REG32 LBPSEL_21_20           : 1;
  __REG32 LBPSEL_23_22           : 1;
  __REG32 LBPSEL_25_24           : 1;
  __REG32 LBPSEL_27_26           : 1;
  __REG32 LBPSEL_29_28           : 1;
  __REG32 LBPSEL_31_30           : 1;
  __REG32 LBPTYPE_1_0            : 1;
  __REG32 LBPTYPE_3_2            : 1;
  __REG32 LBPTYPE_5_4            : 1;
  __REG32 LBPTYPE_7_6            : 1;
  __REG32 LBPTYPE_9_8            : 1;
  __REG32 LBPTYPE_11_10          : 1;
  __REG32 LBPTYPE_13_12          : 1;
  __REG32 LBPTYPE_15_14          : 1;
  __REG32 LBPTYPE_17_16          : 1;
  __REG32 LBPTYPE_19_18          : 1;
  __REG32 LBPTYPE_21_20          : 1;
  __REG32 LBPTYPE_23_22          : 1;
  __REG32 LBPTYPE_25_24          : 1;
  __REG32 LBPTYPE_27_26          : 1;
  __REG32 LBPTYPE_29_28          : 1;
  __REG32 LBPTYPE_31_30          : 1;
} __hetlbpsel_bits;

/* NHET Loop Back Pair Direction Register (HETLBPDIR) */
typedef struct {
  __REG32 LBPDIR_1_0              : 1;
  __REG32 LBPDIR_3_2              : 1;
  __REG32 LBPDIR_5_4              : 1;
  __REG32 LBPDIR_7_6              : 1;
  __REG32 LBPDIR_9_8              : 1;
  __REG32 LBPDIR_11_10            : 1;
  __REG32 LBPDIR_13_12            : 1;
  __REG32 LBPDIR_15_14            : 1;
  __REG32 LBPDIR_17_16            : 1;
  __REG32 LBPDIR_19_18            : 1;
  __REG32 LBPDIR_21_20            : 1;
  __REG32 LBPDIR_23_22            : 1;
  __REG32 LBPDIR_25_24            : 1;
  __REG32 LBPDIR_27_26            : 1;
  __REG32 LBPDIR_29_28            : 1;
  __REG32 LBPDIR_31_30            : 1;
  __REG32 LBPTSTENA               : 4;
  __REG32                         :12;
} __hetlbpdir_bits;

/* NHET Pin Disable Register (HETPINDIS) */
typedef struct {
  __REG32 HETPINDIS0              : 1;
  __REG32 HETPINDIS1              : 1;
  __REG32 HETPINDIS2              : 1;
  __REG32 HETPINDIS3              : 1;
  __REG32 HETPINDIS4              : 1;
  __REG32 HETPINDIS5              : 1;
  __REG32 HETPINDIS6              : 1;
  __REG32 HETPINDIS7              : 1;
  __REG32 HETPINDIS8              : 1;
  __REG32 HETPINDIS9              : 1;
  __REG32 HETPINDIS10             : 1;
  __REG32 HETPINDIS11             : 1;
  __REG32 HETPINDIS12             : 1;
  __REG32 HETPINDIS13             : 1;
  __REG32 HETPINDIS14             : 1;
  __REG32 HETPINDIS15             : 1;
  __REG32 HETPINDIS16             : 1;
  __REG32 HETPINDIS17             : 1;
  __REG32 HETPINDIS18             : 1;
  __REG32 HETPINDIS19             : 1;
  __REG32 HETPINDIS20             : 1;
  __REG32 HETPINDIS21             : 1;
  __REG32 HETPINDIS22             : 1;
  __REG32 HETPINDIS23             : 1;
  __REG32 HETPINDIS24             : 1;
  __REG32 HETPINDIS25             : 1;
  __REG32 HETPINDIS26             : 1;
  __REG32 HETPINDIS27             : 1;
  __REG32 HETPINDIS28             : 1;
  __REG32 HETPINDIS29             : 1;
  __REG32 HETPINDIS30             : 1;
  __REG32 HETPINDIS31             : 1;
} __hetpindis_bits;

/* Global Control Register (HTU GC) */
typedef struct {
  __REG32 HTURES               : 1;
  __REG32                      : 7;
  __REG32 DEBM                 : 1;
  __REG32                      : 7;
  __REG32 HTUEN                : 1;
  __REG32                      : 7;
  __REG32 VBUSHOLD             : 1;
  __REG32                      : 7;
} __htugc_bits;

/* Control Packet Enable Register (HTU CPENA) */
typedef struct {
  __REG32 CPENA0               : 2;
  __REG32 CPENA1               : 2;
  __REG32 CPENA2               : 2;
  __REG32 CPENA3               : 2;
  __REG32 CPENA4               : 2;
  __REG32 CPENA5               : 2;
  __REG32 CPENA6               : 2;
  __REG32 CPENA7               : 2;
  __REG32                      :16;
} __htcpena_bits;

/* Control Packet (CP) Busy Register 0 (HTU BUSY0) */
typedef struct {
  __REG32 BUSY1B               : 1;
  __REG32                      : 7;
  __REG32 BUSY1A               : 1;
  __REG32                      : 7;
  __REG32 BUSY0B               : 1;
  __REG32                      : 7;
  __REG32 BUSY0A               : 1;
  __REG32                      : 7;
} __htubusy0_bits;

/* Control Packet (CP) Busy Register 1 (HTU BUSY1) */
typedef struct {
  __REG32 BUSY3B               : 1;
  __REG32                      : 7;
  __REG32 BUSY3A               : 1;
  __REG32                      : 7;
  __REG32 BUSY2B               : 1;
  __REG32                      : 7;
  __REG32 BUSY2A               : 1;
  __REG32                      : 7;
} __htubusy1_bits;

/* Control Packet (CP) Busy Register 2 (HTU BUSY2) */
typedef struct {
  __REG32 BUSY5B               : 1;
  __REG32                      : 7;
  __REG32 BUSY5A               : 1;
  __REG32                      : 7;
  __REG32 BUSY4B               : 1;
  __REG32                      : 7;
  __REG32 BUSY4A               : 1;
  __REG32                      : 7;
} __htubusy2_bits;

/* Control Packet (CP) Busy Register 3 (HTU BUSY3) */
typedef struct {
  __REG32 BUSY7B               : 1;
  __REG32                      : 7;
  __REG32 BUSY7A               : 1;
  __REG32                      : 7;
  __REG32 BUSY6B               : 1;
  __REG32                      : 7;
  __REG32 BUSY6A               : 1;
  __REG32                      : 7;
} __htubusy3_bits;

/* Active Control Packet and Error Register (HTU ACPE) */
typedef struct {
  __REG32 NACP                 : 4;
  __REG32                      : 4;
  __REG32 CETCOUNT             : 5;
  __REG32                      : 1;
  __REG32 BUSBUSY              : 1;
  __REG32 TIPF                 : 1;
  __REG32 ERRCPN               : 4;
  __REG32                      : 4;
  __REG32 ERRETC               : 5;
  __REG32                      : 2;
  __REG32 ERRF                 : 1;
} __htuacpe_bits;

/* Request Lost and Bus Error Control Register (HTU RLBECTRL) */
typedef struct {
  __REG32 RLINTENA             : 1;
  __REG32                      : 7;
  __REG32 CORL                 : 1;
  __REG32                      : 7;
  __REG32 BERINTENA            : 1;
  __REG32                      :15;
} __hturlbectrl_bits;

/* Buffer Full Interrupt Enable Set Register (HTU BFINTS) */
typedef struct {
  __REG32 BFINTENA0            : 1;
  __REG32 BFINTENA1            : 1;
  __REG32 BFINTENA2            : 1;
  __REG32 BFINTENA3            : 1;
  __REG32 BFINTENA4            : 1;
  __REG32 BFINTENA5            : 1;
  __REG32 BFINTENA6            : 1;
  __REG32 BFINTENA7            : 1;
  __REG32 BFINTENA8            : 1;
  __REG32 BFINTENA9            : 1;
  __REG32 BFINTENA10           : 1;
  __REG32 BFINTENA11           : 1;
  __REG32 BFINTENA12           : 1;
  __REG32 BFINTENA13           : 1;
  __REG32 BFINTENA14           : 1;
  __REG32 BFINTENA15           : 1;
  __REG32                      :16;
} __htubfints_bits;

/* Buffer Full Interrupt Enable Clear Register (HTU BFINTC) */
typedef struct {
  __REG32 BFINTDIS0            : 1;
  __REG32 BFINTDIS1            : 1;
  __REG32 BFINTDIS2            : 1;
  __REG32 BFINTDIS3            : 1;
  __REG32 BFINTDIS4            : 1;
  __REG32 BFINTDIS5            : 1;
  __REG32 BFINTDIS6            : 1;
  __REG32 BFINTDIS7            : 1;
  __REG32 BFINTDIS8            : 1;
  __REG32 BFINTDIS9            : 1;
  __REG32 BFINTDIS10           : 1;
  __REG32 BFINTDIS11           : 1;
  __REG32 BFINTDIS12           : 1;
  __REG32 BFINTDIS13           : 1;
  __REG32 BFINTDIS14           : 1;
  __REG32 BFINTDIS15           : 1;
  __REG32                      :16;
} __htubfintc_bits;

/* Interrupt Mapping Register (HTU INTMAP) */
typedef struct {
  __REG32 CPINTMAP0            : 1;
  __REG32 CPINTMAP1            : 1;
  __REG32 CPINTMAP2            : 1;
  __REG32 CPINTMAP3            : 1;
  __REG32 CPINTMAP4            : 1;
  __REG32 CPINTMAP5            : 1;
  __REG32 CPINTMAP6            : 1;
  __REG32 CPINTMAP7            : 1;
  __REG32 CPINTMAP8            : 1;
  __REG32 CPINTMAP9            : 1;
  __REG32 CPINTMAP10           : 1;
  __REG32 CPINTMAP11           : 1;
  __REG32 CPINTMAP12           : 1;
  __REG32 CPINTMAP13           : 1;
  __REG32 CPINTMAP14           : 1;
  __REG32 CPINTMAP15           : 1;
  __REG32 MAPSEL               : 1;
  __REG32                      :15;
} __htuintmap_bits;

/* Interrupt Offset Register 0 (HTU INTOFF0) */
typedef struct {
  __REG32 CPOFF0               : 4;
  __REG32                      : 4;
  __REG32 INTTYPE0             : 2;
  __REG32                      :22;
} __htuintoff0_bits;

/* Interrupt Offset Register 1 (HTU INTOFF1) */
typedef struct {
  __REG32 CPOFF1               : 4;
  __REG32                      : 4;
  __REG32 INTTYPE1             : 2;
  __REG32                      :22;
} __htuintoff1_bits;

/* Buffer Initialization Mode Register (HTU BIM) */
typedef struct {
  __REG32 BIM0                 : 1;
  __REG32 BIM1                 : 1;
  __REG32 BIM2                 : 1;
  __REG32 BIM3                 : 1;
  __REG32 BIM4                 : 1;
  __REG32 BIM5                 : 1;
  __REG32 BIM6                 : 1;
  __REG32 BIM7                 : 1;
  __REG32                      :24;
} __htubim_bits;

/* Request Lost Flag Register (HTU RLOSTFL) */
typedef struct {
  __REG32 CPRLFL0              : 1;
  __REG32 CPRLFL1              : 1;
  __REG32 CPRLFL2              : 1;
  __REG32 CPRLFL3              : 1;
  __REG32 CPRLFL4              : 1;
  __REG32 CPRLFL5              : 1;
  __REG32 CPRLFL6              : 1;
  __REG32 CPRLFL7              : 1;
  __REG32 CPRLFL8              : 1;
  __REG32 CPRLFL9              : 1;
  __REG32 CPRLFL10             : 1;
  __REG32 CPRLFL11             : 1;
  __REG32 CPRLFL12             : 1;
  __REG32 CPRLFL13             : 1;
  __REG32 CPRLFL14             : 1;
  __REG32 CPRLFL15             : 1;
  __REG32                      :16;
} __hturlostfl_bits;

/* Buffer Full Interrupt Flag Register (HTU BFINTFL) */
typedef struct {
  __REG32 BFINTFL0             : 1;
  __REG32 BFINTFL1             : 1;
  __REG32 BFINTFL2             : 1;
  __REG32 BFINTFL3             : 1;
  __REG32 BFINTFL4             : 1;
  __REG32 BFINTFL5             : 1;
  __REG32 BFINTFL6             : 1;
  __REG32 BFINTFL7             : 1;
  __REG32 BFINTFL8             : 1;
  __REG32 BFINTFL9             : 1;
  __REG32 BFINTFL10            : 1;
  __REG32 BFINTFL11            : 1;
  __REG32 BFINTFL12            : 1;
  __REG32 BFINTFL13            : 1;
  __REG32 BFINTFL14            : 1;
  __REG32 BFINTFL15            : 1;
  __REG32                      :16;
} __htubfintfl_bits;

/* BER Interrupt Flag Register (HTU BERINTFL) */
typedef struct {
  __REG32 BERINTFL0            : 1;
  __REG32 BERINTFL1            : 1;
  __REG32 BERINTFL2            : 1;
  __REG32 BERINTFL3            : 1;
  __REG32 BERINTFL4            : 1;
  __REG32 BERINTFL5            : 1;
  __REG32 BERINTFL6            : 1;
  __REG32 BERINTFL7            : 1;
  __REG32 BERINTFL8            : 1;
  __REG32 BERINTFL9            : 1;
  __REG32 BERINTFL10           : 1;
  __REG32 BERINTFL11           : 1;
  __REG32 BERINTFL12           : 1;
  __REG32 BERINTFL13           : 1;
  __REG32 BERINTFL14           : 1;
  __REG32 BERINTFL15           : 1;
  __REG32                      :16;
} __htuberintfl_bits;

/* Debug Control Register (HTU DCTRL) */
typedef struct {
  __REG32 DBREN                : 1;
  __REG32                      :15;
  __REG32 HTUDBGS              : 1;
  __REG32                      : 7;
  __REG32 CPNUM                : 4;
  __REG32                      : 4;
} __htudctrl_bits;

/* Module Identification Register (HTU ID) */
typedef struct {
  __REG32 REV                  : 8;
  __REG32 TYPE                 : 8;
  __REG32 CLASS                : 8;
  __REG32                      : 8;
} __htuid_bits;

/* Parity Control Register (HTU PCR) */
typedef struct {
  __REG32 PARITY_ENA           : 4;
  __REG32                      : 4;
  __REG32 TEST                 : 1;
  __REG32                      : 7;
  __REG32 COPE                 : 1;
  __REG32                      :15;
} __htupcr_bits;

/* Parity Address Register (HTU PAR) */
typedef struct {
  __REG32 PAOFF                : 9;
  __REG32                      : 7;
  __REG32 PEFT                 : 1;
  __REG32                      :15;
} __htupar_bits;

/* Memory Protection Control and Status Register (HTU MPCS) */
typedef struct {
  __REG32 REG0ENA              : 1;
  __REG32 ACCR0                : 1;
  __REG32 INTENA0              : 1;
  __REG32 REG01ENA             : 1;
  __REG32 ACCR01               : 1;
  __REG32 INTENA01             : 1;
  __REG32                      : 2;
  __REG32 CPNUM1               : 4;
  __REG32                      : 4;
  __REG32 MPEFT0               : 1;
  __REG32 MPEFT1               : 1;
  __REG32                      : 6;
  __REG32 CPNUM0               : 4;
  __REG32                      : 4;
} __htumpcs_bits;

/* Initial NHET Address and Control Register (HTU IHADDRCT) */
typedef struct {
  __REG32 IHADDR                :13;
  __REG32                       : 3;
  __REG32 TMBB                  : 2;
  __REG32 TMBA                  : 2;
  __REG32 ADDMF                 : 1;
  __REG32 ADDMH                 : 1;
  __REG32 SIZE                  : 1;
  __REG32 DIR                   : 1;
  __REG32                       : 8;
} __htudcpihaddrct_bits;

/* Initial Transfer Count Register (HTU ITCOUNT) */
typedef struct {
  __REG32 IFTCOUNT              : 8;
  __REG32                       : 8;
  __REG32 IETCOUNT              : 5;
  __REG32                       :11;
} __htudcpitcount_bits;

/* Current Frame Count Register (HTU CFCOUNT) */
typedef struct {
  __REG32 CFTCTB                : 8;
  __REG32                       : 8;
  __REG32 CFTCTA                : 8;
  __REG32                       : 8;
} __htudcpcfcount_bits;

/* DMA Global Control Register (GCTRL) */
typedef struct {
  __REG32 DMA_RES               : 1;
  __REG32                       : 7;
  __REG32 DEBUG_MODE            : 2;
  __REG32                       : 4;
  __REG32 BUS_BUSY              : 1;
  __REG32                       : 1;
  __REG32 DMA_EN                : 1;
  __REG32                       :15;
} __dmagctrl_bits;

/* DMA Channel Pending Register (PEND) */
typedef struct {
  __REG32 PEND0                 : 1;
  __REG32 PEND1                 : 1;
  __REG32 PEND2                 : 1;
  __REG32 PEND3                 : 1;
  __REG32 PEND4                 : 1;
  __REG32 PEND5                 : 1;
  __REG32 PEND6                 : 1;
  __REG32 PEND7                 : 1;
  __REG32 PEND8                 : 1;
  __REG32 PEND9                 : 1;
  __REG32 PEND10                : 1;
  __REG32 PEND11                : 1;
  __REG32 PEND12                : 1;
  __REG32 PEND13                : 1;
  __REG32 PEND14                : 1;
  __REG32 PEND15                : 1;
  __REG32                       :16;
} __dmapend_bits;

/* DMA Status Register (DMASTAT) */
typedef struct {
  __REG32 STCH0              : 1;
  __REG32 STCH1              : 1;
  __REG32 STCH2              : 1;
  __REG32 STCH3              : 1;
  __REG32 STCH4              : 1;
  __REG32 STCH5              : 1;
  __REG32 STCH6              : 1;
  __REG32 STCH7              : 1;
  __REG32 STCH8              : 1;
  __REG32 STCH9              : 1;
  __REG32 STCH10             : 1;
  __REG32 STCH11             : 1;
  __REG32 STCH12             : 1;
  __REG32 STCH13             : 1;
  __REG32 STCH14             : 1;
  __REG32 STCH15             : 1;
  __REG32                    :16;
} __dmastat_bits;

/* DMA HW Channel Enable Set and Status Register (HWCHENAS) */
typedef struct {
  __REG32 HWCHENA0              : 1;
  __REG32 HWCHENA1              : 1;
  __REG32 HWCHENA2              : 1;
  __REG32 HWCHENA3              : 1;
  __REG32 HWCHENA4              : 1;
  __REG32 HWCHENA5              : 1;
  __REG32 HWCHENA6              : 1;
  __REG32 HWCHENA7              : 1;
  __REG32 HWCHENA8              : 1;
  __REG32 HWCHENA9              : 1;
  __REG32 HWCHENA10             : 1;
  __REG32 HWCHENA11             : 1;
  __REG32 HWCHENA12             : 1;
  __REG32 HWCHENA13             : 1;
  __REG32 HWCHENA14             : 1;
  __REG32 HWCHENA15             : 1;
  __REG32                       :16;
} __dmahwchenas_bits;

/* DMA HW Channel Enable Reset and Status Register (HWCHENAR) */
typedef struct {
  __REG32 HWCHDIS0              : 1;
  __REG32 HWCHDIS1              : 1;
  __REG32 HWCHDIS2              : 1;
  __REG32 HWCHDIS3              : 1;
  __REG32 HWCHDIS4              : 1;
  __REG32 HWCHDIS5              : 1;
  __REG32 HWCHDIS6              : 1;
  __REG32 HWCHDIS7              : 1;
  __REG32 HWCHDIS8              : 1;
  __REG32 HWCHDIS9              : 1;
  __REG32 HWCHDIS10             : 1;
  __REG32 HWCHDIS11             : 1;
  __REG32 HWCHDIS12             : 1;
  __REG32 HWCHDIS13             : 1;
  __REG32 HWCHDIS14             : 1;
  __REG32 HWCHDIS15             : 1;
  __REG32                       :16;
} __dmahwchenar_bits;

/* DMA SW Channel Enable Set and Status Register (SWCHENAS) */
typedef struct {
  __REG32 SWCHENA0              : 1;
  __REG32 SWCHENA1              : 1;
  __REG32 SWCHENA2              : 1;
  __REG32 SWCHENA3              : 1;
  __REG32 SWCHENA4              : 1;
  __REG32 SWCHENA5              : 1;
  __REG32 SWCHENA6              : 1;
  __REG32 SWCHENA7              : 1;
  __REG32 SWCHENA8              : 1;
  __REG32 SWCHENA9              : 1;
  __REG32 SWCHENA10             : 1;
  __REG32 SWCHENA11             : 1;
  __REG32 SWCHENA12             : 1;
  __REG32 SWCHENA13             : 1;
  __REG32 SWCHENA14             : 1;
  __REG32 SWCHENA15             : 1;
  __REG32                       :16;
} __dmaswchenas_bits;

/* DMA SW Channel Enable Reset and Status Register (SWCHENAR) */
typedef struct {
  __REG32 SWCHDIS0              : 1;
  __REG32 SWCHDIS1              : 1;
  __REG32 SWCHDIS2              : 1;
  __REG32 SWCHDIS3              : 1;
  __REG32 SWCHDIS4              : 1;
  __REG32 SWCHDIS5              : 1;
  __REG32 SWCHDIS6              : 1;
  __REG32 SWCHDIS7              : 1;
  __REG32 SWCHDIS8              : 1;
  __REG32 SWCHDIS9              : 1;
  __REG32 SWCHDIS10             : 1;
  __REG32 SWCHDIS11             : 1;
  __REG32 SWCHDIS12             : 1;
  __REG32 SWCHDIS13             : 1;
  __REG32 SWCHDIS14             : 1;
  __REG32 SWCHDIS15             : 1;
  __REG32                       :16;
} __dmaswchenar_bits;

/* DMA Channel Priority Set Register (CHPRIOS) */
typedef struct {
  __REG32 CPS0              : 1;
  __REG32 CPS1              : 1;
  __REG32 CPS2              : 1;
  __REG32 CPS3              : 1;
  __REG32 CPS4              : 1;
  __REG32 CPS5              : 1;
  __REG32 CPS6              : 1;
  __REG32 CPS7              : 1;
  __REG32 CPS8              : 1;
  __REG32 CPS9              : 1;
  __REG32 CPS10             : 1;
  __REG32 CPS11             : 1;
  __REG32 CPS12             : 1;
  __REG32 CPS13             : 1;
  __REG32 CPS14             : 1;
  __REG32 CPS15             : 1;
  __REG32                   :16;
} __dmachprios_bits;

/* DMA Channel Priority Reset Register (CHPRIOR) */
typedef struct {
  __REG32 CPR0              : 1;
  __REG32 CPR1              : 1;
  __REG32 CPR2              : 1;
  __REG32 CPR3              : 1;
  __REG32 CPR4              : 1;
  __REG32 CPR5              : 1;
  __REG32 CPR6              : 1;
  __REG32 CPR7              : 1;
  __REG32 CPR8              : 1;
  __REG32 CPR9              : 1;
  __REG32 CPR10             : 1;
  __REG32 CPR11             : 1;
  __REG32 CPR12             : 1;
  __REG32 CPR13             : 1;
  __REG32 CPR14             : 1;
  __REG32 CPR15             : 1;
  __REG32                   :16;
} __dmachprior_bits;

/* DMA Global Channel Interrupt Enable Set Register (GCHIENAS) */
typedef struct {
  __REG32 GCHIE0              : 1;
  __REG32 GCHIE1              : 1;
  __REG32 GCHIE2              : 1;
  __REG32 GCHIE3              : 1;
  __REG32 GCHIE4              : 1;
  __REG32 GCHIE5              : 1;
  __REG32 GCHIE6              : 1;
  __REG32 GCHIE7              : 1;
  __REG32 GCHIE8              : 1;
  __REG32 GCHIE9              : 1;
  __REG32 GCHIE10             : 1;
  __REG32 GCHIE11             : 1;
  __REG32 GCHIE12             : 1;
  __REG32 GCHIE13             : 1;
  __REG32 GCHIE14             : 1;
  __REG32 GCHIE15             : 1;
  __REG32                     :16;
} __dmagchienas_bits;

/* DMA Global Channel Interrupt Enable Reset Register (GCHIENAR) */
typedef struct {
  __REG32 GCHID0              : 1;
  __REG32 GCHID1              : 1;
  __REG32 GCHID2              : 1;
  __REG32 GCHID3              : 1;
  __REG32 GCHID4              : 1;
  __REG32 GCHID5              : 1;
  __REG32 GCHID6              : 1;
  __REG32 GCHID7              : 1;
  __REG32 GCHID8              : 1;
  __REG32 GCHID9              : 1;
  __REG32 GCHID10             : 1;
  __REG32 GCHID11             : 1;
  __REG32 GCHID12             : 1;
  __REG32 GCHID13             : 1;
  __REG32 GCHID14             : 1;
  __REG32 GCHID15             : 1;
  __REG32                     :16;
} __dmagchienar_bits;

/* DMA Request Assignment Register 0 (DREQASI0) */
typedef struct {
  __REG32 CH3ASI              : 6;
  __REG32                     : 2;
  __REG32 CH2ASI              : 6;
  __REG32                     : 2;
  __REG32 CH1ASI              : 6;
  __REG32                     : 2;
  __REG32 CH0ASI              : 6;
  __REG32                     : 2;
} __dmadreqasi0_bits;

/* DMA Request Assignment Register 1 (DREQASI1) */
typedef struct {
  __REG32 CH7ASI              : 6;
  __REG32                     : 2;
  __REG32 CH6ASI              : 6;
  __REG32                     : 2;
  __REG32 CH5ASI              : 6;
  __REG32                     : 2;
  __REG32 CH4ASI              : 6;
  __REG32                     : 2;
} __dmadreqasi1_bits;

/* DMA Request Assignment Register 2 (DREQASI2) */
typedef struct {
  __REG32 CH11ASI             : 6;
  __REG32                     : 2;
  __REG32 CH10ASI             : 6;
  __REG32                     : 2;
  __REG32 CH9ASI              : 6;
  __REG32                     : 2;
  __REG32 CH8ASI              : 6;
  __REG32                     : 2;
} __dmadreqasi2_bits;

/* DMA Request Assignment Register 3 (DREQASI3) */
typedef struct {
  __REG32 CH15ASI             : 6;
  __REG32                     : 2;
  __REG32 CH14ASI             : 6;
  __REG32                     : 2;
  __REG32 CH13ASI             : 6;
  __REG32                     : 2;
  __REG32 CH12ASI             : 6;
  __REG32                     : 2;
} __dmadreqasi3_bits;

/* Port Assignment Register 0 (PAR0) */
typedef struct {
  __REG32 CH7PA               : 3;
  __REG32                     : 1;
  __REG32 CH6PA               : 3;
  __REG32                     : 1;
  __REG32 CH5PA               : 3;
  __REG32                     : 1;
  __REG32 CH4PA               : 3;
  __REG32                     : 1;
  __REG32 CH3PA               : 3;
  __REG32                     : 1;
  __REG32 CH2PA               : 3;
  __REG32                     : 1;
  __REG32 CH1PA               : 3;
  __REG32                     : 1;
  __REG32 CH0PA               : 3;
  __REG32                     : 1;
} __dmapar0_bits;

/* Port Assignment Register 1 (PAR1) */
typedef struct {
  __REG32 CH15PA              : 3;
  __REG32                     : 1;
  __REG32 CH14PA              : 3;
  __REG32                     : 1;
  __REG32 CH13PA              : 3;
  __REG32                     : 1;
  __REG32 CH12PA              : 3;
  __REG32                     : 1;
  __REG32 CH11PA              : 3;
  __REG32                     : 1;
  __REG32 CH10PA              : 3;
  __REG32                     : 1;
  __REG32 CH9PA               : 3;
  __REG32                     : 1;
  __REG32 CH8PA               : 3;
  __REG32                     : 1;
} __dmapar1_bits;

/* DMA FTC Interrupt Mapping Register (FTCMAP) */
typedef struct {
  __REG32 FTCAB0              : 1;
  __REG32 FTCAB1              : 1;
  __REG32 FTCAB2              : 1;
  __REG32 FTCAB3              : 1;
  __REG32 FTCAB4              : 1;
  __REG32 FTCAB5              : 1;
  __REG32 FTCAB6              : 1;
  __REG32 FTCAB7              : 1;
  __REG32 FTCAB8              : 1;
  __REG32 FTCAB9              : 1;
  __REG32 FTCAB10             : 1;
  __REG32 FTCAB11             : 1;
  __REG32 FTCAB12             : 1;
  __REG32 FTCAB13             : 1;
  __REG32 FTCAB14             : 1;
  __REG32 FTCAB15             : 1;
  __REG32                     :16;
} __dmaftcmap_bits;

/* DMA LFS Interrupt Mapping Register (LFSMAP) */
typedef struct {
  __REG32 LFSAB0              : 1;
  __REG32 LFSAB1              : 1;
  __REG32 LFSAB2              : 1;
  __REG32 LFSAB3              : 1;
  __REG32 LFSAB4              : 1;
  __REG32 LFSAB5              : 1;
  __REG32 LFSAB6              : 1;
  __REG32 LFSAB7              : 1;
  __REG32 LFSAB8              : 1;
  __REG32 LFSAB9              : 1;
  __REG32 LFSAB10             : 1;
  __REG32 LFSAB11             : 1;
  __REG32 LFSAB12             : 1;
  __REG32 LFSAB13             : 1;
  __REG32 LFSAB14             : 1;
  __REG32 LFSAB15             : 1;
  __REG32                     :16;
} __dmalfsmap_bits;

/* DMA HBC Interrupt Mapping Register (HBCMAP) */
typedef struct {
  __REG32 HBCAB0              : 1;
  __REG32 HBCAB1              : 1;
  __REG32 HBCAB2              : 1;
  __REG32 HBCAB3              : 1;
  __REG32 HBCAB4              : 1;
  __REG32 HBCAB5              : 1;
  __REG32 HBCAB6              : 1;
  __REG32 HBCAB7              : 1;
  __REG32 HBCAB8              : 1;
  __REG32 HBCAB9              : 1;
  __REG32 HBCAB10             : 1;
  __REG32 HBCAB11             : 1;
  __REG32 HBCAB12             : 1;
  __REG32 HBCAB13             : 1;
  __REG32 HBCAB14             : 1;
  __REG32 HBCAB15             : 1;
  __REG32                     :16;
} __dmahbcmap_bits;

/* DMA BTC Interrupt Mapping Register (BTCMAP) */
typedef struct {
  __REG32 BTCAB0              : 1;
  __REG32 BTCAB1              : 1;
  __REG32 BTCAB2              : 1;
  __REG32 BTCAB3              : 1;
  __REG32 BTCAB4              : 1;
  __REG32 BTCAB5              : 1;
  __REG32 BTCAB6              : 1;
  __REG32 BTCAB7              : 1;
  __REG32 BTCAB8              : 1;
  __REG32 BTCAB9              : 1;
  __REG32 BTCAB10             : 1;
  __REG32 BTCAB11             : 1;
  __REG32 BTCAB12             : 1;
  __REG32 BTCAB13             : 1;
  __REG32 BTCAB14             : 1;
  __REG32 BTCAB15             : 1;
  __REG32                     :16;
} __dmabtcmap_bits;

/* DMA BER Interrupt Mapping Register (BERMAP) */
typedef struct {
  __REG32 BERAB0              : 1;
  __REG32 BERAB1              : 1;
  __REG32 BERAB2              : 1;
  __REG32 BERAB3              : 1;
  __REG32 BERAB4              : 1;
  __REG32 BERAB5              : 1;
  __REG32 BERAB6              : 1;
  __REG32 BERAB7              : 1;
  __REG32 BERAB8              : 1;
  __REG32 BERAB9              : 1;
  __REG32 BERAB10             : 1;
  __REG32 BERAB11             : 1;
  __REG32 BERAB12             : 1;
  __REG32 BERAB13             : 1;
  __REG32 BERAB14             : 1;
  __REG32 BERAB15             : 1;
  __REG32                     :16;
} __dmabermap_bits;

/* DMA FTC Interrupt Enable Set (FTCINTENAS) */
typedef struct {
  __REG32 FTCINTENA0              : 1;
  __REG32 FTCINTENA1              : 1;
  __REG32 FTCINTENA2              : 1;
  __REG32 FTCINTENA3              : 1;
  __REG32 FTCINTENA4              : 1;
  __REG32 FTCINTENA5              : 1;
  __REG32 FTCINTENA6              : 1;
  __REG32 FTCINTENA7              : 1;
  __REG32 FTCINTENA8              : 1;
  __REG32 FTCINTENA9              : 1;
  __REG32 FTCINTENA10             : 1;
  __REG32 FTCINTENA11             : 1;
  __REG32 FTCINTENA12             : 1;
  __REG32 FTCINTENA13             : 1;
  __REG32 FTCINTENA14             : 1;
  __REG32 FTCINTENA15             : 1;
  __REG32                         :16;
} __dmaftcintenas_bits;

/* DMA FTC Interrupt Enable Reset (FTCINTENAR) */
typedef struct {
  __REG32 FTCINTDIS0              : 1;
  __REG32 FTCINTDIS1              : 1;
  __REG32 FTCINTDIS2              : 1;
  __REG32 FTCINTDIS3              : 1;
  __REG32 FTCINTDIS4              : 1;
  __REG32 FTCINTDIS5              : 1;
  __REG32 FTCINTDIS6              : 1;
  __REG32 FTCINTDIS7              : 1;
  __REG32 FTCINTDIS8              : 1;
  __REG32 FTCINTDIS9              : 1;
  __REG32 FTCINTDIS10             : 1;
  __REG32 FTCINTDIS11             : 1;
  __REG32 FTCINTDIS12             : 1;
  __REG32 FTCINTDIS13             : 1;
  __REG32 FTCINTDIS14             : 1;
  __REG32 FTCINTDIS15             : 1;
  __REG32                         :16;
} __dmaftcintenar_bits;

/* DMA LFS Interrupt Enable Set (LFSINTENAS) */
typedef struct {
  __REG32 LFSINTENA0              : 1;
  __REG32 LFSINTENA1              : 1;
  __REG32 LFSINTENA2              : 1;
  __REG32 LFSINTENA3              : 1;
  __REG32 LFSINTENA4              : 1;
  __REG32 LFSINTENA5              : 1;
  __REG32 LFSINTENA6              : 1;
  __REG32 LFSINTENA7              : 1;
  __REG32 LFSINTENA8              : 1;
  __REG32 LFSINTENA9              : 1;
  __REG32 LFSINTENA10             : 1;
  __REG32 LFSINTENA11             : 1;
  __REG32 LFSINTENA12             : 1;
  __REG32 LFSINTENA13             : 1;
  __REG32 LFSINTENA14             : 1;
  __REG32 LFSINTENA15             : 1;
  __REG32                         :16;
} __dmalfsintenas_bits;

/* DMA LFS Interrupt Enable Reset (LFSINTENAR) */
typedef struct {
  __REG32 LFSINTDIS0              : 1;
  __REG32 LFSINTDIS1              : 1;
  __REG32 LFSINTDIS2              : 1;
  __REG32 LFSINTDIS3              : 1;
  __REG32 LFSINTDIS4              : 1;
  __REG32 LFSINTDIS5              : 1;
  __REG32 LFSINTDIS6              : 1;
  __REG32 LFSINTDIS7              : 1;
  __REG32 LFSINTDIS8              : 1;
  __REG32 LFSINTDIS9              : 1;
  __REG32 LFSINTDIS10             : 1;
  __REG32 LFSINTDIS11             : 1;
  __REG32 LFSINTDIS12             : 1;
  __REG32 LFSINTDIS13             : 1;
  __REG32 LFSINTDIS14             : 1;
  __REG32 LFSINTDIS15             : 1;
  __REG32                         :16;
} __dmalfsintenar_bits;

/* DMA HBC Interrupt Enable Reset (HBCINTENAS) */
typedef struct {
  __REG32 HBCINTENA0              : 1;
  __REG32 HBCINTENA1              : 1;
  __REG32 HBCINTENA2              : 1;
  __REG32 HBCINTENA3              : 1;
  __REG32 HBCINTENA4              : 1;
  __REG32 HBCINTENA5              : 1;
  __REG32 HBCINTENA6              : 1;
  __REG32 HBCINTENA7              : 1;
  __REG32 HBCINTENA8              : 1;
  __REG32 HBCINTENA9              : 1;
  __REG32 HBCINTENA10             : 1;
  __REG32 HBCINTENA11             : 1;
  __REG32 HBCINTENA12             : 1;
  __REG32 HBCINTENA13             : 1;
  __REG32 HBCINTENA14             : 1;
  __REG32 HBCINTENA15             : 1;
  __REG32                         :16;
} __dmahbcintenas_bits;

/* DMA HBC Interrupt Enable Reset (HBCINTENAR) */
typedef struct {
  __REG32 HBCINTDIS0              : 1;
  __REG32 HBCINTDIS1              : 1;
  __REG32 HBCINTDIS2              : 1;
  __REG32 HBCINTDIS3              : 1;
  __REG32 HBCINTDIS4              : 1;
  __REG32 HBCINTDIS5              : 1;
  __REG32 HBCINTDIS6              : 1;
  __REG32 HBCINTDIS7              : 1;
  __REG32 HBCINTDIS8              : 1;
  __REG32 HBCINTDIS9              : 1;
  __REG32 HBCINTDIS10             : 1;
  __REG32 HBCINTDIS11             : 1;
  __REG32 HBCINTDIS12             : 1;
  __REG32 HBCINTDIS13             : 1;
  __REG32 HBCINTDIS14             : 1;
  __REG32 HBCINTDIS15             : 1;
  __REG32                         :16;
} __dmahbcintenar_bits;

/* DMA BTC Interrupt Enable Set (BTCINTENAS) */
typedef struct {
  __REG32 BTCINTENA0              : 1;
  __REG32 BTCINTENA1              : 1;
  __REG32 BTCINTENA2              : 1;
  __REG32 BTCINTENA3              : 1;
  __REG32 BTCINTENA4              : 1;
  __REG32 BTCINTENA5              : 1;
  __REG32 BTCINTENA6              : 1;
  __REG32 BTCINTENA7              : 1;
  __REG32 BTCINTENA8              : 1;
  __REG32 BTCINTENA9              : 1;
  __REG32 BTCINTENA10             : 1;
  __REG32 BTCINTENA11             : 1;
  __REG32 BTCINTENA12             : 1;
  __REG32 BTCINTENA13             : 1;
  __REG32 BTCINTENA14             : 1;
  __REG32 BTCINTENA15             : 1;
  __REG32                         :16;
} __dmabtcintenas_bits;

/* DMA BTC Interrupt Enable Reset (BTCINTENAR) */
typedef struct {
  __REG32 BTCINTDIS0              : 1;
  __REG32 BTCINTDIS1              : 1;
  __REG32 BTCINTDIS2              : 1;
  __REG32 BTCINTDIS3              : 1;
  __REG32 BTCINTDIS4              : 1;
  __REG32 BTCINTDIS5              : 1;
  __REG32 BTCINTDIS6              : 1;
  __REG32 BTCINTDIS7              : 1;
  __REG32 BTCINTDIS8              : 1;
  __REG32 BTCINTDIS9              : 1;
  __REG32 BTCINTDIS10             : 1;
  __REG32 BTCINTDIS11             : 1;
  __REG32 BTCINTDIS12             : 1;
  __REG32 BTCINTDIS13             : 1;
  __REG32 BTCINTDIS14             : 1;
  __REG32 BTCINTDIS15             : 1;
  __REG32                         :16;
} __dmabtcintenar_bits;

/* DMA Global Interrupt Flag Register (GINTFLAG) */
typedef struct {
  __REG32 GINT0              : 1;
  __REG32 GINT1              : 1;
  __REG32 GINT2              : 1;
  __REG32 GINT3              : 1;
  __REG32 GINT4              : 1;
  __REG32 GINT5              : 1;
  __REG32 GINT6              : 1;
  __REG32 GINT7              : 1;
  __REG32 GINT8              : 1;
  __REG32 GINT9              : 1;
  __REG32 GINT10             : 1;
  __REG32 GINT11             : 1;
  __REG32 GINT12             : 1;
  __REG32 GINT13             : 1;
  __REG32 GINT14             : 1;
  __REG32 GINT15             : 1;
  __REG32                    :16;
} __dmagintflag_bits;

/* DMA FTC Interrupt Flag Register (FTCFLAG) */
typedef struct {
  __REG32 FTCI0              : 1;
  __REG32 FTCI1              : 1;
  __REG32 FTCI2              : 1;
  __REG32 FTCI3              : 1;
  __REG32 FTCI4              : 1;
  __REG32 FTCI5              : 1;
  __REG32 FTCI6              : 1;
  __REG32 FTCI7              : 1;
  __REG32 FTCI8              : 1;
  __REG32 FTCI9              : 1;
  __REG32 FTCI10             : 1;
  __REG32 FTCI11             : 1;
  __REG32 FTCI12             : 1;
  __REG32 FTCI13             : 1;
  __REG32 FTCI14             : 1;
  __REG32 FTCI15             : 1;
  __REG32                    :16;
} __dmaftcflag_bits;

/* DMA LFS Interrupt Flag Register (LFSFLAG) */
typedef struct {
  __REG32 LFSI0              : 1;
  __REG32 LFSI1              : 1;
  __REG32 LFSI2              : 1;
  __REG32 LFSI3              : 1;
  __REG32 LFSI4              : 1;
  __REG32 LFSI5              : 1;
  __REG32 LFSI6              : 1;
  __REG32 LFSI7              : 1;
  __REG32 LFSI8              : 1;
  __REG32 LFSI9              : 1;
  __REG32 LFSI10             : 1;
  __REG32 LFSI11             : 1;
  __REG32 LFSI12             : 1;
  __REG32 LFSI13             : 1;
  __REG32 LFSI14             : 1;
  __REG32 LFSI15             : 1;
  __REG32                    :16;
} __dmalfsflag_bits;

/* DMA HBC Interrupt Flag Register (HBCFLAG) */
typedef struct {
  __REG32 HBCI0              : 1;
  __REG32 HBCI1              : 1;
  __REG32 HBCI2              : 1;
  __REG32 HBCI3              : 1;
  __REG32 HBCI4              : 1;
  __REG32 HBCI5              : 1;
  __REG32 HBCI6              : 1;
  __REG32 HBCI7              : 1;
  __REG32 HBCI8              : 1;
  __REG32 HBCI9              : 1;
  __REG32 HBCI10             : 1;
  __REG32 HBCI11             : 1;
  __REG32 HBCI12             : 1;
  __REG32 HBCI13             : 1;
  __REG32 HBCI14             : 1;
  __REG32 HBCI15             : 1;
  __REG32                    :16;
} __dmahbcflag_bits;

/* DMA BTC Interrupt Flag Register (BTCFLAG) */
typedef struct {
  __REG32 BTCI0              : 1;
  __REG32 BTCI1              : 1;
  __REG32 BTCI2              : 1;
  __REG32 BTCI3              : 1;
  __REG32 BTCI4              : 1;
  __REG32 BTCI5              : 1;
  __REG32 BTCI6              : 1;
  __REG32 BTCI7              : 1;
  __REG32 BTCI8              : 1;
  __REG32 BTCI9              : 1;
  __REG32 BTCI10             : 1;
  __REG32 BTCI11             : 1;
  __REG32 BTCI12             : 1;
  __REG32 BTCI13             : 1;
  __REG32 BTCI14             : 1;
  __REG32 BTCI15             : 1;
  __REG32                    :16;
} __dmabtcflag_bits;

/* DMA BER Interrupt Flag Register (BERFLAG) */
typedef struct {
  __REG32 BERI0              : 1;
  __REG32 BERI1              : 1;
  __REG32 BERI2              : 1;
  __REG32 BERI3              : 1;
  __REG32 BERI4              : 1;
  __REG32 BERI5              : 1;
  __REG32 BERI6              : 1;
  __REG32 BERI7              : 1;
  __REG32 BERI8              : 1;
  __REG32 BERI9              : 1;
  __REG32 BERI10             : 1;
  __REG32 BERI11             : 1;
  __REG32 BERI12             : 1;
  __REG32 BERI13             : 1;
  __REG32 BERI14             : 1;
  __REG32 BERI15             : 1;
  __REG32                    :16;
} __dmaberflag_bits;

/* DMA FTCA Interrupt Channel Offset Register (FTCAOFFSET) */
typedef struct {
  __REG32 FTCA               : 6;
  __REG32                    :26;
} __dmaftcaoffset_bits;

/* DMA LFSA Interrupt Channel Offset Register (LFSAOFFSET) */
typedef struct {
  __REG32 LFSA               : 6;
  __REG32                    :26;
} __dmalfsaoffset_bits;

/* DMA HBCA Interrupt Channel Offset Register (HBCAOFFSET) */
typedef struct {
  __REG32 HBCA               : 6;
  __REG32                    :26;
} __dmahbcaoffset_bits;

/* DMA BTCA Interrupt Channel Offset Register (BTCAOFFSET) */
typedef struct {
  __REG32 BTCA               : 6;
  __REG32                    :26;
} __dmabtcaoffset_bits;

/* DMA BERA Interrupt Channel Offset Register (BERAOFFSET) */
typedef struct {
  __REG32 BERA               : 6;
  __REG32                    :26;
} __dmaberaoffset_bits;

/* DMA FTCB Interrupt Channel Offset Register (FTCBOFFSET) */
typedef struct {
  __REG32 FTCB               : 6;
  __REG32                    :26;
} __dmaftcboffset_bits;

/* DMA FTCB Interrupt Channel Offset Register (FTCBOFFSET) */
typedef struct {
  __REG32 LFSB               : 6;
  __REG32                    :26;
} __dmalfsboffset_bits;

/* DMA HBCB Interrupt Channel Offset Register (HBCBOFFSET) */
typedef struct {
  __REG32 HBCB               : 6;
  __REG32                    :26;
} __dmahbcboffset_bits;

/* DMA BTCB Interrupt Channel Offset Register (BTCBOFFSET) */
typedef struct {
  __REG32 BTCB               : 6;
  __REG32                    :26;
} __dmabtcboffset_bits;

/* DMA BERB Interrupt Channel Offset Register (BERBOFFSET) */
typedef struct {
  __REG32 BERB               : 6;
  __REG32                    :26;
} __dmaberboffset_bits;

/* DMA Port Control Register (PTCRL) */
typedef struct {
  __REG32                    :16;
  __REG32 PSFRLQPB           : 1;
  __REG32 PSFRHQPB           : 1;
  __REG32 BYB                : 1;
  __REG32                    : 5;
  __REG32 PENDB              : 1;
  __REG32                    : 7;
} __dmaptcrl_bits;

/* DMA RAM Test Control (RTCTRL) */
typedef struct {
  __REG32 RTC                : 1;
  __REG32                    :31;
} __dmartctrl_bits;

/* DMA RAM Test Control (RTCTRL) */
typedef struct {
  __REG32 DBGEN              : 1;
  __REG32                    :15;
  __REG32 DMADBGS            : 1;
  __REG32                    : 7;
  __REG32 CHNUM              : 5;
  __REG32                    : 3;
} __dmadctrl_bits;

/* DMA Port B Active Channel Transfer Count Register (PBACTC) */
typedef struct {
  __REG32 PBETCOUNT          :13;
  __REG32                    : 3;
  __REG32 PBFTCOUNT          :13;
  __REG32                    : 3;
} __dmapbactc_bits;

/* DMA Parity Control Register (DMAPCR) */
typedef struct {
  __REG32 PARITY_ENA         : 4;
  __REG32                    : 4;
  __REG32 TEST               : 1;
  __REG32                    : 7;
  __REG32 ERRA               : 1;
  __REG32                    :15;
} __dmapcr_bits;

/* DMA Parity Error Address Register (DMAPAR) */
typedef struct {
  __REG32 ERRORADDRESS       :12;
  __REG32                    :12;
  __REG32 EDFLAG             : 1;
  __REG32                    : 7;
} __dmapar_bits;

/* DMA Memory Protection Control Register (DMAMPCTRL) */
typedef struct {
  __REG32 REG0ENA            : 1;
  __REG32 REG0AP             : 2;
  __REG32 INT0ENA            : 1;
  __REG32 INT0AB             : 1;
  __REG32                    : 3;
  __REG32 REG1ENA            : 1;
  __REG32 REG1AP             : 2;
  __REG32 INT1ENA            : 1;
  __REG32 INT1AB             : 1;
  __REG32                    : 3;
  __REG32 REG2ENA            : 1;
  __REG32 REG2AP             : 2;
  __REG32 INT2ENA            : 1;
  __REG32 INT2AB             : 1;
  __REG32                    : 3;
  __REG32 REG3ENA            : 1;
  __REG32 REG3AP             : 2;
  __REG32 INT3ENA            : 1;
  __REG32 INT3AB             : 1;
  __REG32                    : 3;
} __dmampctrl_bits;

/* DMA Memory Protection Status Register (DMAMPST) */
typedef struct {
  __REG32 REG0FT             : 1;
  __REG32                    : 7;
  __REG32 REG1FT             : 1;
  __REG32                    : 7;
  __REG32 REG2FT             : 1;
  __REG32                    : 7;
  __REG32 REG3FT             : 1;
  __REG32                    : 7;
} __dmampst_bits;

/* DMA Initial Transfer Count Register (ITCOUNT) */
typedef struct {
  __REG32 IETCOUNT           :13;
  __REG32                    : 3;
  __REG32 IFTCOUNT           :13;
  __REG32                    : 3;
} __dmacpitcount_bits;

/* DMA Channel Control Register (CHCTRL) */
typedef struct {
  __REG32 AIM                : 1;
  __REG32 ADDMW              : 2;
  __REG32 ADDMR              : 2;
  __REG32                    : 3;
  __REG32 TTYPE              : 1;
  __REG32                    : 3;
  __REG32 WES                : 2;
  __REG32 RES                : 2;
  __REG32 CHAIN              : 6;
  __REG32                    :10;
} __dmachctrl_bits;

/* DMA Element Index Offset Register (EIOFF) */
typedef struct {
  __REG32 EIDXS              :13;
  __REG32                    : 3;
  __REG32 EIDXD              :13;
  __REG32                    : 3;
} __dmacpeioff_bits;

/* DMA Frame Index Offset Register (FIOFF) */
typedef struct {
  __REG32 FIDXS              :13;
  __REG32                    : 3;
  __REG32 FIDXD              :13;
  __REG32                    : 3;
} __dmacpfioff_bits;

/* DMA Current Transfer Count Register (CTCOUNT) */
typedef struct {
  __REG32 CETCOUNT           :13;
  __REG32                    : 3;
  __REG32 CFTCOUNT           :13;
  __REG32                    : 3;
} __dmacpctcount_bits;

/* RTI Global Control Register (RTIGCTRL) */
typedef struct {
  __REG32 CNT0EN             : 1;
  __REG32 CNT1EN             : 1;
  __REG32                    :13;
  __REG32 COS                : 1;
  __REG32 NTUSEL             : 4;
  __REG32                    :12;
} __rtigctrl_bits;

/* RTI Timebase Control Register (RTITBCTRL) */
typedef struct {
  __REG32 TBEXT               : 1;
  __REG32 INC                 : 1;
  __REG32                     :30;
} __rtitbctrl_bits;

/* RTI Capture Control Register (RTICAPCTRL) */
typedef struct {
  __REG32 CAPCNTR0            : 1;
  __REG32 CAPCNTR1            : 1;
  __REG32                     :30;
} __rticapctrl_bits;

/* RTI Compare Control Register (RTICOMPCTRL) */
typedef struct {
  __REG32 COMPSEL0            : 1;
  __REG32                     : 3;
  __REG32 COMPSEL1            : 1;
  __REG32                     : 3;
  __REG32 COMPSEL2            : 1;
  __REG32                     : 3;
  __REG32 COMPSEL3            : 1;
  __REG32                     :19;
} __rticompctrl_bits;

/* RTI Set Interrupt Enable Register (RTISETINTENA) */
typedef struct {
  __REG32 SETINT0             : 1;
  __REG32 SETINT1             : 1;
  __REG32 SETINT2             : 1;
  __REG32 SETINT3             : 1;
  __REG32                     : 4;
  __REG32 SETDMA0             : 1;
  __REG32 SETDMA1             : 1;
  __REG32 SETDMA2             : 1;
  __REG32 SETDMA3             : 1;
  __REG32                     : 4;
  __REG32 SETTBINT            : 1;
  __REG32 SETOVL0INT          : 1;
  __REG32 SETOVL1INT          : 1;
  __REG32                     :13;
} __rtisetintena_bits;

/* RTI Clear Interrupt Enable Register (RTICLEARINTENA) */
typedef struct {
  __REG32 CLEARINT0           : 1;
  __REG32 CLEARINT1           : 1;
  __REG32 CLEARINT2           : 1;
  __REG32 CLEARINT3           : 1;
  __REG32                     : 4;
  __REG32 CLEARDMA0           : 1;
  __REG32 CLEARDMA1           : 1;
  __REG32 CLEARDMA2           : 1;
  __REG32 CLEARDMA3           : 1;
  __REG32                     : 4;
  __REG32 CLEARTBINT          : 1;
  __REG32 CLEAROVL0INT        : 1;
  __REG32 CLEAROVL1INT        : 1;
  __REG32                     :13;
} __rticlearintena_bits;

/* RTI Interrupt Flag Register (RTIINTFLAG) */
typedef struct {
  __REG32 INT0                : 1;
  __REG32 INT1                : 1;
  __REG32 INT2                : 1;
  __REG32 INT3                : 1;
  __REG32                     :12;
  __REG32 TBINT               : 1;
  __REG32 OVL0INT             : 1;
  __REG32 OVL1INT             : 1;
  __REG32                     :13;
} __rtiintflag_bits;

/* Digital Watchdog Preload Register (RTIDWDPRLD) */
typedef struct {
  __REG32 DWDPRLD             :12;
  __REG32                     :20;
} __rtidwdprld_bits;

/* Watchdog Status Register (RTIWDSTATUS) */
typedef struct {
  __REG32                     : 1;
  __REG32 DWD_ST              : 1;
  __REG32 KEY_ST              : 1;
  __REG32 START_TIME_VIOL     : 1;
  __REG32 END_TIME_VIOL       : 1;
  __REG32 DWWD_ST             : 1;
  __REG32                     :26;
} __rtiwdstatus_bits;

/* RTI Watchdog Key Register (RTIWDKEY) */
typedef struct {
  __REG32 WDKEY               :16;
  __REG32                     :16;
} __rtiwdkey_bits;

/* RTI Digital Watchdog Down Counter (RTIDWDCNTR) */
typedef struct {
  __REG32 DWDCNTR             :25;
  __REG32                     : 7;
} __rtidwdcntr_bits;

/* Digital Windowed Watchdog Reaction Control (RTIWWDRXNCTRL) */
typedef struct {
  __REG32 WWDRXN              : 4;
  __REG32                     :28;
} __rtiwwdrxnctrl_bits;

/* RTI Compare Interrupt Clear Enable Register (RTIINTCLRENABLE) */
typedef struct {
  __REG32 INTCLRENABLE0       : 4;
  __REG32                     : 4;
  __REG32 INTCLRENABLE1       : 4;
  __REG32                     : 4;
  __REG32 INTCLRENABLE2       : 4;
  __REG32                     : 4;
  __REG32 INTCLRENABLE3       : 4;
  __REG32                     : 4;
} __rtiintclrenable_bits;

/* CRC_CTRL0: CRC Global Control Register 0 */
typedef struct {
  __REG32 CH1_PSA_SWREST      : 1;
  __REG32                     : 7;
  __REG32 CH2_PSA_SWREST      : 1;
  __REG32                     :23;
} __crc_ctrl0_bits;

/* CRC_CTRL1: CRC Global Control Register 1 */
typedef struct {
  __REG32 PWDN                : 1;
  __REG32                     :31;
} __crc_ctrl1_bits;

/* CRC_CTRL2: CRC Global Control Register 2 */
typedef struct {
  __REG32 CH1_MODE            : 2;
  __REG32                     : 2;
  __REG32 CH1_TRACEEN         : 1;
  __REG32                     : 3;
  __REG32 CH2_MODE            : 2;
  __REG32                     :22;
} __crc_ctrl2_bits;

/* CRC_INTS: CRC Interrupt Enable Set Register */
typedef struct {
  __REG32 CH1_CCITENS         : 1;
  __REG32 CH1_CRCFAILENS      : 1;
  __REG32 CH1_OVERENS         : 1;
  __REG32 CH1_UNDERENS        : 1;
  __REG32 CH1_TIMEOUTENS      : 1;
  __REG32                     : 3;
  __REG32 CH2_CCITENS         : 1;
  __REG32 CH2_CRCFAILENS      : 1;
  __REG32 CH2_OVERENS         : 1;
  __REG32 CH2_UNDERENS        : 1;
  __REG32 CH2_TIMEOUTENS      : 1;
  __REG32                     :19;
} __crc_ints_bits;

/* CRC_INTR: CRC Interrupt Enable Reset Register */
typedef struct {
  __REG32 CH1_CCITENR         : 1;
  __REG32 CH1_CRCFAILENR      : 1;
  __REG32 CH1_OVERENR         : 1;
  __REG32 CH1_UNDERENR        : 1;
  __REG32 CH1_TIMEOUTENR      : 1;
  __REG32                     : 3;
  __REG32 CH2_CCITENR         : 1;
  __REG32 CH2_CRCFAILENR      : 1;
  __REG32 CH2_OVERENR         : 1;
  __REG32 CH2_UNDERENR        : 1;
  __REG32 CH2_TIMEOUTENR      : 1;
  __REG32                     :19;
} __crc_intr_bits;

/* CRC_STATUS_REG: CRC Interrupt Status Register */
typedef struct {
  __REG32 CH1_CCIT            : 1;
  __REG32 CH1_CRCFAIL         : 1;
  __REG32 CH1_OVER            : 1;
  __REG32 CH1_UNDER           : 1;
  __REG32 CH1_TIMEOUT         : 1;
  __REG32                     : 3;
  __REG32 CH2_CCIT            : 1;
  __REG32 CH2_CRCFAIL         : 1;
  __REG32 CH2_OVER            : 1;
  __REG32 CH2_UNDER           : 1;
  __REG32 CH2_TIMEOUT         : 1;
  __REG32                     :19;
} __crc_status_bits;

/* CRC_INT_OFFSET_REG: CRC Interrupt Offset Register */
typedef struct {
  __REG32 OFSTREG             : 8;
  __REG32                     :24;
} __crc_int_offset_reg_bits;

/* CRC_BUSY: CRC Busy Register */
typedef struct {
  __REG32 CH1_BUSY            : 1;
  __REG32                     : 7;
  __REG32 CH2_BUSY            : 1;
  __REG32                     :23;
} __crc_busy_bits;

/* CRC_PCOUNT_REGx: CRC Pattern Counter Preload Register x */
typedef struct {
  __REG32 CRC_PAT_COUNT       :20;
  __REG32                     :12;
} __crc_pcount_reg_bits;

/* CRC_SCOUNT_REGx: CRC Sector Counter Preload Register x */
typedef struct {
  __REG32 CRC_SEC_COUNT       :16;
  __REG32                     :16;
} __crc_scount_reg_bits;

/* CRC_CURSEC_REGx: CRC Current Sector Register x */
typedef struct {
  __REG32 CRC_CURSEC          :16;
  __REG32                     :16;
} __crc_cursec_reg_bits;

/* CRC_WDTOPLDx: CRC Channel x Watchdog Timeout Preload Register */
typedef struct {
  __REG32 CRC_WDTOPLD         :24;
  __REG32                     : 8;
} __crc_wdtopld_bits;

/* CRC_BCTOPLDx: CRC Channel x Block Complete Timeout Preload Register */
typedef struct {
  __REG32 CRC_BCTOPLD         :24;
  __REG32                     : 8;
} __crc_bctopld_bits;

/* Data Bus Selection Register(CRC_TRACE_BUS_SEL) */
typedef struct {
  __REG32 ITCMEn              : 1;
  __REG32 DTCMEn              : 1;
  __REG32 MEn                 : 1;
  __REG32                     :29;
} __crc_trace_bus_sel_bits;

/* CCM-R4F Status Register (CCMSR) */
typedef struct {
  __REG32 STE                 : 1;
  __REG32 STET                : 1;
  __REG32                     : 6;
  __REG32 STC                 : 1;
  __REG32                     : 7;
  __REG32 CMPE                : 1;
  __REG32                     :15;
} __ccmsr_bits;

/* CCM-R4F Key Register (CCMKEYR) */
typedef struct {
  __REG32 MKEY                : 4;
  __REG32                     :28;
} __ccmkeyr_bits;

/* Parity Flag Register (PARFLG) */
typedef struct {
  __REG32 PARFLG              : 1;
  __REG32                     :31;
} __parflg_bits;

/* Parity Control Register (PARCTL) */
typedef struct {
  __REG32 PARENA              : 4;
  __REG32                     : 4;
  __REG32 TEST                : 1;
  __REG32                     :23;
} __parctl_bits;

/* IRQ Index Offset Vector Register (IRQINDEX) */
typedef struct {
  __REG32 IRQINDEX            : 8;
  __REG32                     :24;
} __irqindex_bits;

/* FIQ Index Offset Vector Registers (FIQINDEX) */
typedef struct {
  __REG32 FIQINDEX            : 8;
  __REG32                     :24;
} __fiqindex_bits;

/* FIQ/IRQ Program Control Register 0 (FIRQPR0) */
typedef struct {
  __REG32                     : 2;
  __REG32 FIRQPR2             : 1;
  __REG32 FIRQPR3             : 1;
  __REG32 FIRQPR4             : 1;
  __REG32 FIRQPR5             : 1;
  __REG32 FIRQPR6             : 1;
  __REG32 FIRQPR7             : 1;
  __REG32 FIRQPR8             : 1;
  __REG32 FIRQPR9             : 1;
  __REG32 FIRQPR10            : 1;
  __REG32 FIRQPR11            : 1;
  __REG32 FIRQPR12            : 1;
  __REG32 FIRQPR13            : 1;
  __REG32 FIRQPR14            : 1;
  __REG32 FIRQPR15            : 1;
  __REG32 FIRQPR16            : 1;
  __REG32 FIRQPR17            : 1;
  __REG32 FIRQPR18            : 1;
  __REG32 FIRQPR19            : 1;
  __REG32 FIRQPR20            : 1;
  __REG32 FIRQPR21            : 1;
  __REG32 FIRQPR22            : 1;
  __REG32 FIRQPR23            : 1;
  __REG32 FIRQPR24            : 1;
  __REG32 FIRQPR25            : 1;
  __REG32 FIRQPR26            : 1;
  __REG32 FIRQPR27            : 1;
  __REG32 FIRQPR28            : 1;
  __REG32 FIRQPR29            : 1;
  __REG32 FIRQPR30            : 1;
  __REG32 FIRQPR31            : 1;
} __firqpr0_bits;

/* FIQ/IRQ Program Control Register 1 (FIRQPR1) */
typedef struct {
  __REG32 FIRQPR32            : 1;
  __REG32 FIRQPR33            : 1;
  __REG32 FIRQPR34            : 1;
  __REG32 FIRQPR35            : 1;
  __REG32 FIRQPR36            : 1;
  __REG32 FIRQPR37            : 1;
  __REG32 FIRQPR38            : 1;
  __REG32 FIRQPR39            : 1;
  __REG32 FIRQPR40            : 1;
  __REG32 FIRQPR41            : 1;
  __REG32 FIRQPR42            : 1;
  __REG32 FIRQPR43            : 1;
  __REG32 FIRQPR44            : 1;
  __REG32 FIRQPR45            : 1;
  __REG32 FIRQPR46            : 1;
  __REG32 FIRQPR47            : 1;
  __REG32 FIRQPR48            : 1;
  __REG32 FIRQPR49            : 1;
  __REG32 FIRQPR50            : 1;
  __REG32 FIRQPR51            : 1;
  __REG32 FIRQPR52            : 1;
  __REG32 FIRQPR53            : 1;
  __REG32 FIRQPR54            : 1;
  __REG32 FIRQPR55            : 1;
  __REG32 FIRQPR56            : 1;
  __REG32 FIRQPR57            : 1;
  __REG32 FIRQPR58            : 1;
  __REG32 FIRQPR59            : 1;
  __REG32 FIRQPR60            : 1;
  __REG32 FIRQPR61            : 1;
  __REG32 FIRQPR62            : 1;
  __REG32 FIRQPR63            : 1;
} __firqpr1_bits;

/* FIQ/IRQ Program Control Register 2 (FIRQPR2) */
typedef struct {
  __REG32 FIRQPR64            : 1;
  __REG32 FIRQPR65            : 1;
  __REG32 FIRQPR66            : 1;
  __REG32 FIRQPR67            : 1;
  __REG32 FIRQPR68            : 1;
  __REG32 FIRQPR69            : 1;
  __REG32 FIRQPR70            : 1;
  __REG32 FIRQPR71            : 1;
  __REG32 FIRQPR72            : 1;
  __REG32 FIRQPR73            : 1;
  __REG32 FIRQPR74            : 1;
  __REG32 FIRQPR75            : 1;
  __REG32 FIRQPR76            : 1;
  __REG32 FIRQPR77            : 1;
  __REG32 FIRQPR78            : 1;
  __REG32 FIRQPR79            : 1;
  __REG32 FIRQPR80            : 1;
  __REG32 FIRQPR81            : 1;
  __REG32 FIRQPR82            : 1;
  __REG32 FIRQPR83            : 1;
  __REG32 FIRQPR84            : 1;
  __REG32 FIRQPR85            : 1;
  __REG32 FIRQPR86            : 1;
  __REG32 FIRQPR87            : 1;
  __REG32 FIRQPR88            : 1;
  __REG32 FIRQPR89            : 1;
  __REG32 FIRQPR90            : 1;
  __REG32 FIRQPR91            : 1;
  __REG32 FIRQPR92            : 1;
  __REG32 FIRQPR93            : 1;
  __REG32 FIRQPR94            : 1;
  __REG32 FIRQPR95            : 1;
} __firqpr2_bits;

/* Pending Interrupt Read Location Register 0 (INTREQ0) */
typedef struct {
  __REG32 INTREQ0           : 1;
  __REG32 INTREQ1           : 1;
  __REG32 INTREQ2           : 1;
  __REG32 INTREQ3           : 1;
  __REG32 INTREQ4           : 1;
  __REG32 INTREQ5           : 1;
  __REG32 INTREQ6           : 1;
  __REG32 INTREQ7           : 1;
  __REG32 INTREQ8           : 1;
  __REG32 INTREQ9           : 1;
  __REG32 INTREQ10          : 1;
  __REG32 INTREQ11          : 1;
  __REG32 INTREQ12          : 1;
  __REG32 INTREQ13          : 1;
  __REG32 INTREQ14          : 1;
  __REG32 INTREQ15          : 1;
  __REG32 INTREQ16          : 1;
  __REG32 INTREQ17          : 1;
  __REG32 INTREQ18          : 1;
  __REG32 INTREQ19          : 1;
  __REG32 INTREQ20          : 1;
  __REG32 INTREQ21          : 1;
  __REG32 INTREQ22          : 1;
  __REG32 INTREQ23          : 1;
  __REG32 INTREQ24          : 1;
  __REG32 INTREQ25          : 1;
  __REG32 INTREQ26          : 1;
  __REG32 INTREQ27          : 1;
  __REG32 INTREQ28          : 1;
  __REG32 INTREQ29          : 1;
  __REG32 INTREQ30          : 1;
  __REG32 INTREQ31          : 1;
} __intreq0_bits;

/* Pending Interrupt Read Location Register 1 (INTREQ1) */
typedef struct {
  __REG32 INTREQ32          : 1;
  __REG32 INTREQ33          : 1;
  __REG32 INTREQ34          : 1;
  __REG32 INTREQ35          : 1;
  __REG32 INTREQ36          : 1;
  __REG32 INTREQ37          : 1;
  __REG32 INTREQ38          : 1;
  __REG32 INTREQ39          : 1;
  __REG32 INTREQ40          : 1;
  __REG32 INTREQ41          : 1;
  __REG32 INTREQ42          : 1;
  __REG32 INTREQ43          : 1;
  __REG32 INTREQ44          : 1;
  __REG32 INTREQ45          : 1;
  __REG32 INTREQ46          : 1;
  __REG32 INTREQ47          : 1;
  __REG32 INTREQ48          : 1;
  __REG32 INTREQ49          : 1;
  __REG32 INTREQ50          : 1;
  __REG32 INTREQ51          : 1;
  __REG32 INTREQ52          : 1;
  __REG32 INTREQ53          : 1;
  __REG32 INTREQ54          : 1;
  __REG32 INTREQ55          : 1;
  __REG32 INTREQ56          : 1;
  __REG32 INTREQ57          : 1;
  __REG32 INTREQ58          : 1;
  __REG32 INTREQ59          : 1;
  __REG32 INTREQ60          : 1;
  __REG32 INTREQ61          : 1;
  __REG32 INTREQ62          : 1;
  __REG32 INTREQ63          : 1;
} __intreq1_bits;

/* Pending Interrupt Read Location Register 2 (INTREQ2) */
typedef struct {
  __REG32 INTREQ64          : 1;
  __REG32 INTREQ65          : 1;
  __REG32 INTREQ66          : 1;
  __REG32 INTREQ67          : 1;
  __REG32 INTREQ68          : 1;
  __REG32 INTREQ69          : 1;
  __REG32 INTREQ70          : 1;
  __REG32 INTREQ71          : 1;
  __REG32 INTREQ72          : 1;
  __REG32 INTREQ73          : 1;
  __REG32 INTREQ74          : 1;
  __REG32 INTREQ75          : 1;
  __REG32 INTREQ76          : 1;
  __REG32 INTREQ77          : 1;
  __REG32 INTREQ78          : 1;
  __REG32 INTREQ79          : 1;
  __REG32 INTREQ80          : 1;
  __REG32 INTREQ81          : 1;
  __REG32 INTREQ82          : 1;
  __REG32 INTREQ83          : 1;
  __REG32 INTREQ84          : 1;
  __REG32 INTREQ85          : 1;
  __REG32 INTREQ86          : 1;
  __REG32 INTREQ87          : 1;
  __REG32 INTREQ88          : 1;
  __REG32 INTREQ89          : 1;
  __REG32 INTREQ90          : 1;
  __REG32 INTREQ91          : 1;
  __REG32 INTREQ92          : 1;
  __REG32 INTREQ93          : 1;
  __REG32 INTREQ94          : 1;
  __REG32 INTREQ95          : 1;
} __intreq2_bits;

/* Interrupt Enable Set Register 0 (REQENASET0) */
typedef struct {
  __REG32                      : 2;
  __REG32 REQENASET2           : 1;
  __REG32 REQENASET3           : 1;
  __REG32 REQENASET4           : 1;
  __REG32 REQENASET5           : 1;
  __REG32 REQENASET6           : 1;
  __REG32 REQENASET7           : 1;
  __REG32 REQENASET8           : 1;
  __REG32 REQENASET9           : 1;
  __REG32 REQENASET10          : 1;
  __REG32 REQENASET11          : 1;
  __REG32 REQENASET12          : 1;
  __REG32 REQENASET13          : 1;
  __REG32 REQENASET14          : 1;
  __REG32 REQENASET15          : 1;
  __REG32 REQENASET16          : 1;
  __REG32 REQENASET17          : 1;
  __REG32 REQENASET18          : 1;
  __REG32 REQENASET19          : 1;
  __REG32 REQENASET20          : 1;
  __REG32 REQENASET21          : 1;
  __REG32 REQENASET22          : 1;
  __REG32 REQENASET23          : 1;
  __REG32 REQENASET24          : 1;
  __REG32 REQENASET25          : 1;
  __REG32 REQENASET26          : 1;
  __REG32 REQENASET27          : 1;
  __REG32 REQENASET28          : 1;
  __REG32 REQENASET29          : 1;
  __REG32 REQENASET30          : 1;
  __REG32 REQENASET31          : 1;
} __reqenaset0_bits;

/* Interrupt Enable Set Register 1 (REQENASET1) */
typedef struct {
  __REG32 REQENASET32          : 1;
  __REG32 REQENASET33          : 1;
  __REG32 REQENASET34          : 1;
  __REG32 REQENASET35          : 1;
  __REG32 REQENASET36          : 1;
  __REG32 REQENASET37          : 1;
  __REG32 REQENASET38          : 1;
  __REG32 REQENASET39          : 1;
  __REG32 REQENASET40          : 1;
  __REG32 REQENASET41          : 1;
  __REG32 REQENASET42          : 1;
  __REG32 REQENASET43          : 1;
  __REG32 REQENASET44          : 1;
  __REG32 REQENASET45          : 1;
  __REG32 REQENASET46          : 1;
  __REG32 REQENASET47          : 1;
  __REG32 REQENASET48          : 1;
  __REG32 REQENASET49          : 1;
  __REG32 REQENASET50          : 1;
  __REG32 REQENASET51          : 1;
  __REG32 REQENASET52          : 1;
  __REG32 REQENASET53          : 1;
  __REG32 REQENASET54          : 1;
  __REG32 REQENASET55          : 1;
  __REG32 REQENASET56          : 1;
  __REG32 REQENASET57          : 1;
  __REG32 REQENASET58          : 1;
  __REG32 REQENASET59          : 1;
  __REG32 REQENASET60          : 1;
  __REG32 REQENASET61          : 1;
  __REG32 REQENASET62          : 1;
  __REG32 REQENASET63          : 1;
} __reqenaset1_bits;

/* Interrupt Enable Set Register 2 (REQENASET2) */
typedef struct {
  __REG32 REQENASET64          : 1;
  __REG32 REQENASET65          : 1;
  __REG32 REQENASET66          : 1;
  __REG32 REQENASET67          : 1;
  __REG32 REQENASET68          : 1;
  __REG32 REQENASET69          : 1;
  __REG32 REQENASET70          : 1;
  __REG32 REQENASET71          : 1;
  __REG32 REQENASET72          : 1;
  __REG32 REQENASET73          : 1;
  __REG32 REQENASET74          : 1;
  __REG32 REQENASET75          : 1;
  __REG32 REQENASET76          : 1;
  __REG32 REQENASET77          : 1;
  __REG32 REQENASET78          : 1;
  __REG32 REQENASET79          : 1;
  __REG32 REQENASET80          : 1;
  __REG32 REQENASET81          : 1;
  __REG32 REQENASET82          : 1;
  __REG32 REQENASET83          : 1;
  __REG32 REQENASET84          : 1;
  __REG32 REQENASET85          : 1;
  __REG32 REQENASET86          : 1;
  __REG32 REQENASET87          : 1;
  __REG32 REQENASET88          : 1;
  __REG32 REQENASET89          : 1;
  __REG32 REQENASET90          : 1;
  __REG32 REQENASET91          : 1;
  __REG32 REQENASET92          : 1;
  __REG32 REQENASET93          : 1;
  __REG32 REQENASET94          : 1;
  __REG32 REQENASET95          : 1;
} __reqenaset2_bits;

/* Interrupt Enable Clear Register 0 (REQENACLR0) */
typedef struct {
  __REG32                      : 2;
  __REG32 REQENACLR2           : 1;
  __REG32 REQENACLR3           : 1;
  __REG32 REQENACLR4           : 1;
  __REG32 REQENACLR5           : 1;
  __REG32 REQENACLR6           : 1;
  __REG32 REQENACLR7           : 1;
  __REG32 REQENACLR8           : 1;
  __REG32 REQENACLR9           : 1;
  __REG32 REQENACLR10          : 1;
  __REG32 REQENACLR11          : 1;
  __REG32 REQENACLR12          : 1;
  __REG32 REQENACLR13          : 1;
  __REG32 REQENACLR14          : 1;
  __REG32 REQENACLR15          : 1;
  __REG32 REQENACLR16          : 1;
  __REG32 REQENACLR17          : 1;
  __REG32 REQENACLR18          : 1;
  __REG32 REQENACLR19          : 1;
  __REG32 REQENACLR20          : 1;
  __REG32 REQENACLR21          : 1;
  __REG32 REQENACLR22          : 1;
  __REG32 REQENACLR23          : 1;
  __REG32 REQENACLR24          : 1;
  __REG32 REQENACLR25          : 1;
  __REG32 REQENACLR26          : 1;
  __REG32 REQENACLR27          : 1;
  __REG32 REQENACLR28          : 1;
  __REG32 REQENACLR29          : 1;
  __REG32 REQENACLR30          : 1;
  __REG32 REQENACLR31          : 1;
} __reqenaclr0_bits;

/* Interrupt Enable Clear Register 1 (REQENACLR1) */
typedef struct {
  __REG32 REQENACLR32          : 1;
  __REG32 REQENACLR33          : 1;
  __REG32 REQENACLR34          : 1;
  __REG32 REQENACLR35          : 1;
  __REG32 REQENACLR36          : 1;
  __REG32 REQENACLR37          : 1;
  __REG32 REQENACLR38          : 1;
  __REG32 REQENACLR39          : 1;
  __REG32 REQENACLR40          : 1;
  __REG32 REQENACLR41          : 1;
  __REG32 REQENACLR42          : 1;
  __REG32 REQENACLR43          : 1;
  __REG32 REQENACLR44          : 1;
  __REG32 REQENACLR45          : 1;
  __REG32 REQENACLR46          : 1;
  __REG32 REQENACLR47          : 1;
  __REG32 REQENACLR48          : 1;
  __REG32 REQENACLR49          : 1;
  __REG32 REQENACLR50          : 1;
  __REG32 REQENACLR51          : 1;
  __REG32 REQENACLR52          : 1;
  __REG32 REQENACLR53          : 1;
  __REG32 REQENACLR54          : 1;
  __REG32 REQENACLR55          : 1;
  __REG32 REQENACLR56          : 1;
  __REG32 REQENACLR57          : 1;
  __REG32 REQENACLR58          : 1;
  __REG32 REQENACLR59          : 1;
  __REG32 REQENACLR60          : 1;
  __REG32 REQENACLR61          : 1;
  __REG32 REQENACLR62          : 1;
  __REG32 REQENACLR63          : 1;
} __reqenaclr1_bits;

/* Interrupt Enable Clear Register 2 (REQENACLR2) */
typedef struct {
  __REG32 REQENACLR64          : 1;
  __REG32 REQENACLR65          : 1;
  __REG32 REQENACLR66          : 1;
  __REG32 REQENACLR67          : 1;
  __REG32 REQENACLR68          : 1;
  __REG32 REQENACLR69          : 1;
  __REG32 REQENACLR70          : 1;
  __REG32 REQENACLR71          : 1;
  __REG32 REQENACLR72          : 1;
  __REG32 REQENACLR73          : 1;
  __REG32 REQENACLR74          : 1;
  __REG32 REQENACLR75          : 1;
  __REG32 REQENACLR76          : 1;
  __REG32 REQENACLR77          : 1;
  __REG32 REQENACLR78          : 1;
  __REG32 REQENACLR79          : 1;
  __REG32 REQENACLR80          : 1;
  __REG32 REQENACLR81          : 1;
  __REG32 REQENACLR82          : 1;
  __REG32 REQENACLR83          : 1;
  __REG32 REQENACLR84          : 1;
  __REG32 REQENACLR85          : 1;
  __REG32 REQENACLR86          : 1;
  __REG32 REQENACLR87          : 1;
  __REG32 REQENACLR88          : 1;
  __REG32 REQENACLR89          : 1;
  __REG32 REQENACLR90          : 1;
  __REG32 REQENACLR91          : 1;
  __REG32 REQENACLR92          : 1;
  __REG32 REQENACLR93          : 1;
  __REG32 REQENACLR94          : 1;
  __REG32 REQENACLR95          : 1;
} __reqenaclr2_bits;

/* Wake-Up Enable Set Register 0 (WAKEENASET0) */
typedef struct {
  __REG32 WAKEENASET0           : 1;
  __REG32 WAKEENASET1           : 1;
  __REG32 WAKEENASET2           : 1;
  __REG32 WAKEENASET3           : 1;
  __REG32 WAKEENASET4           : 1;
  __REG32 WAKEENASET5           : 1;
  __REG32 WAKEENASET6           : 1;
  __REG32 WAKEENASET7           : 1;
  __REG32 WAKEENASET8           : 1;
  __REG32 WAKEENASET9           : 1;
  __REG32 WAKEENASET10          : 1;
  __REG32 WAKEENASET11          : 1;
  __REG32 WAKEENASET12          : 1;
  __REG32 WAKEENASET13          : 1;
  __REG32 WAKEENASET14          : 1;
  __REG32 WAKEENASET15          : 1;
  __REG32 WAKEENASET16          : 1;
  __REG32 WAKEENASET17          : 1;
  __REG32 WAKEENASET18          : 1;
  __REG32 WAKEENASET19          : 1;
  __REG32 WAKEENASET20          : 1;
  __REG32 WAKEENASET21          : 1;
  __REG32 WAKEENASET22          : 1;
  __REG32 WAKEENASET23          : 1;
  __REG32 WAKEENASET24          : 1;
  __REG32 WAKEENASET25          : 1;
  __REG32 WAKEENASET26          : 1;
  __REG32 WAKEENASET27          : 1;
  __REG32 WAKEENASET28          : 1;
  __REG32 WAKEENASET29          : 1;
  __REG32 WAKEENASET30          : 1;
  __REG32 WAKEENASET31          : 1;
} __wakeenaset0_bits;

/* Wake-Up Enable Set Register 1 (WAKEENASET1) */
typedef struct {
  __REG32 WAKEENASET32          : 1;
  __REG32 WAKEENASET33          : 1;
  __REG32 WAKEENASET34          : 1;
  __REG32 WAKEENASET35          : 1;
  __REG32 WAKEENASET36          : 1;
  __REG32 WAKEENASET37          : 1;
  __REG32 WAKEENASET38          : 1;
  __REG32 WAKEENASET39          : 1;
  __REG32 WAKEENASET40          : 1;
  __REG32 WAKEENASET41          : 1;
  __REG32 WAKEENASET42          : 1;
  __REG32 WAKEENASET43          : 1;
  __REG32 WAKEENASET44          : 1;
  __REG32 WAKEENASET45          : 1;
  __REG32 WAKEENASET46          : 1;
  __REG32 WAKEENASET47          : 1;
  __REG32 WAKEENASET48          : 1;
  __REG32 WAKEENASET49          : 1;
  __REG32 WAKEENASET50          : 1;
  __REG32 WAKEENASET51          : 1;
  __REG32 WAKEENASET52          : 1;
  __REG32 WAKEENASET53          : 1;
  __REG32 WAKEENASET54          : 1;
  __REG32 WAKEENASET55          : 1;
  __REG32 WAKEENASET56          : 1;
  __REG32 WAKEENASET57          : 1;
  __REG32 WAKEENASET58          : 1;
  __REG32 WAKEENASET59          : 1;
  __REG32 WAKEENASET60          : 1;
  __REG32 WAKEENASET61          : 1;
  __REG32 WAKEENASET62          : 1;
  __REG32 WAKEENASET63          : 1;
} __wakeenaset1_bits;

/* Wake-Up Enable Set Register 2 (WAKEENASET2) */
typedef struct {
  __REG32 WAKEENASET64          : 1;
  __REG32 WAKEENASET65          : 1;
  __REG32 WAKEENASET66          : 1;
  __REG32 WAKEENASET67          : 1;
  __REG32 WAKEENASET68          : 1;
  __REG32 WAKEENASET69          : 1;
  __REG32 WAKEENASET70          : 1;
  __REG32 WAKEENASET71          : 1;
  __REG32 WAKEENASET72          : 1;
  __REG32 WAKEENASET73          : 1;
  __REG32 WAKEENASET74          : 1;
  __REG32 WAKEENASET75          : 1;
  __REG32 WAKEENASET76          : 1;
  __REG32 WAKEENASET77          : 1;
  __REG32 WAKEENASET78          : 1;
  __REG32 WAKEENASET79          : 1;
  __REG32 WAKEENASET80          : 1;
  __REG32 WAKEENASET81          : 1;
  __REG32 WAKEENASET82          : 1;
  __REG32 WAKEENASET83          : 1;
  __REG32 WAKEENASET84          : 1;
  __REG32 WAKEENASET85          : 1;
  __REG32 WAKEENASET86          : 1;
  __REG32 WAKEENASET87          : 1;
  __REG32 WAKEENASET88          : 1;
  __REG32 WAKEENASET89          : 1;
  __REG32 WAKEENASET90          : 1;
  __REG32 WAKEENASET91          : 1;
  __REG32 WAKEENASET92          : 1;
  __REG32 WAKEENASET93          : 1;
  __REG32 WAKEENASET94          : 1;
  __REG32 WAKEENASET95          : 1;
} __wakeenaset2_bits;

/* Wake-Up Enable Clear Register 0 (WAKEENACLR0) */
typedef struct {
  __REG32 WAKEENACLR0           : 1;
  __REG32 WAKEENACLR1           : 1;
  __REG32 WAKEENACLR2           : 1;
  __REG32 WAKEENACLR3           : 1;
  __REG32 WAKEENACLR4           : 1;
  __REG32 WAKEENACLR5           : 1;
  __REG32 WAKEENACLR6           : 1;
  __REG32 WAKEENACLR7           : 1;
  __REG32 WAKEENACLR8           : 1;
  __REG32 WAKEENACLR9           : 1;
  __REG32 WAKEENACLR10          : 1;
  __REG32 WAKEENACLR11          : 1;
  __REG32 WAKEENACLR12          : 1;
  __REG32 WAKEENACLR13          : 1;
  __REG32 WAKEENACLR14          : 1;
  __REG32 WAKEENACLR15          : 1;
  __REG32 WAKEENACLR16          : 1;
  __REG32 WAKEENACLR17          : 1;
  __REG32 WAKEENACLR18          : 1;
  __REG32 WAKEENACLR19          : 1;
  __REG32 WAKEENACLR20          : 1;
  __REG32 WAKEENACLR21          : 1;
  __REG32 WAKEENACLR22          : 1;
  __REG32 WAKEENACLR23          : 1;
  __REG32 WAKEENACLR24          : 1;
  __REG32 WAKEENACLR25          : 1;
  __REG32 WAKEENACLR26          : 1;
  __REG32 WAKEENACLR27          : 1;
  __REG32 WAKEENACLR28          : 1;
  __REG32 WAKEENACLR29          : 1;
  __REG32 WAKEENACLR30          : 1;
  __REG32 WAKEENACLR31          : 1;
} __wakeenaclr0_bits;

/* Wake-Up Enable Clear Register 1 (WAKEENACLR1) */
typedef struct {
  __REG32 WAKEENACLR32          : 1;
  __REG32 WAKEENACLR33          : 1;
  __REG32 WAKEENACLR34          : 1;
  __REG32 WAKEENACLR35          : 1;
  __REG32 WAKEENACLR36          : 1;
  __REG32 WAKEENACLR37          : 1;
  __REG32 WAKEENACLR38          : 1;
  __REG32 WAKEENACLR39          : 1;
  __REG32 WAKEENACLR40          : 1;
  __REG32 WAKEENACLR41          : 1;
  __REG32 WAKEENACLR42          : 1;
  __REG32 WAKEENACLR43          : 1;
  __REG32 WAKEENACLR44          : 1;
  __REG32 WAKEENACLR45          : 1;
  __REG32 WAKEENACLR46          : 1;
  __REG32 WAKEENACLR47          : 1;
  __REG32 WAKEENACLR48          : 1;
  __REG32 WAKEENACLR49          : 1;
  __REG32 WAKEENACLR50          : 1;
  __REG32 WAKEENACLR51          : 1;
  __REG32 WAKEENACLR52          : 1;
  __REG32 WAKEENACLR53          : 1;
  __REG32 WAKEENACLR54          : 1;
  __REG32 WAKEENACLR55          : 1;
  __REG32 WAKEENACLR56          : 1;
  __REG32 WAKEENACLR57          : 1;
  __REG32 WAKEENACLR58          : 1;
  __REG32 WAKEENACLR59          : 1;
  __REG32 WAKEENACLR60          : 1;
  __REG32 WAKEENACLR61          : 1;
  __REG32 WAKEENACLR62          : 1;
  __REG32 WAKEENACLR63          : 1;
} __wakeenaclr1_bits;

/* Wake-Up Enable Clear Register 2 (WAKEENACLR2) */
typedef struct {
  __REG32 WAKEENACLR64          : 1;
  __REG32 WAKEENACLR65          : 1;
  __REG32 WAKEENACLR66          : 1;
  __REG32 WAKEENACLR67          : 1;
  __REG32 WAKEENACLR68          : 1;
  __REG32 WAKEENACLR69          : 1;
  __REG32 WAKEENACLR70          : 1;
  __REG32 WAKEENACLR71          : 1;
  __REG32 WAKEENACLR72          : 1;
  __REG32 WAKEENACLR73          : 1;
  __REG32 WAKEENACLR74          : 1;
  __REG32 WAKEENACLR75          : 1;
  __REG32 WAKEENACLR76          : 1;
  __REG32 WAKEENACLR77          : 1;
  __REG32 WAKEENACLR78          : 1;
  __REG32 WAKEENACLR79          : 1;
  __REG32 WAKEENACLR80          : 1;
  __REG32 WAKEENACLR81          : 1;
  __REG32 WAKEENACLR82          : 1;
  __REG32 WAKEENACLR83          : 1;
  __REG32 WAKEENACLR84          : 1;
  __REG32 WAKEENACLR85          : 1;
  __REG32 WAKEENACLR86          : 1;
  __REG32 WAKEENACLR87          : 1;
  __REG32 WAKEENACLR88          : 1;
  __REG32 WAKEENACLR89          : 1;
  __REG32 WAKEENACLR90          : 1;
  __REG32 WAKEENACLR91          : 1;
  __REG32 WAKEENACLR92          : 1;
  __REG32 WAKEENACLR93          : 1;
  __REG32 WAKEENACLR94          : 1;
  __REG32 WAKEENACLR95          : 1;
} __wakeenaclr2_bits;

/* Capture Event Register (CAPEVT) */
typedef struct {
  __REG32 CAPEVTSRC0            : 7;
  __REG32                       : 9;
  __REG32 CAPEVTSRC1            : 7;
  __REG32                       : 9;
} __capevt_bits;

/* VIM Interrupt Control Register (CHANCTRL0) */
typedef struct {
  __REG32 CHANMAP3              : 7;
  __REG32                       : 1;
  __REG32 CHANMAP2              : 7;
  __REG32                       : 1;
  __REG32 CHANMAP1              : 7;
  __REG32                       : 1;
  __REG32 CHANMAP0              : 7;
  __REG32                       : 1;
} __chanctrl0_bits;

/* VIM Interrupt Control Register (CHANCTRL1) */
typedef struct {
  __REG32 CHANMAP7              : 7;
  __REG32                       : 1;
  __REG32 CHANMAP6              : 7;
  __REG32                       : 1;
  __REG32 CHANMAP5              : 7;
  __REG32                       : 1;
  __REG32 CHANMAP4              : 7;
  __REG32                       : 1;
} __chanctrl1_bits;

/* VIM Interrupt Control Register (CHANCTRL2) */
typedef struct {
  __REG32 CHANMAP11             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP10             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP9              : 7;
  __REG32                       : 1;
  __REG32 CHANMAP8              : 7;
  __REG32                       : 1;
} __chanctrl2_bits;

/* VIM Interrupt Control Register (CHANCTRL3) */
typedef struct {
  __REG32 CHANMAP15             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP14             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP13             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP12             : 7;
  __REG32                       : 1;
} __chanctrl3_bits;

/* VIM Interrupt Control Register (CHANCTRL4) */
typedef struct {
  __REG32 CHANMAP19             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP18             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP17             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP16             : 7;
  __REG32                       : 1;
} __chanctrl4_bits;

/* VIM Interrupt Control Register (CHANCTRL5) */
typedef struct {
  __REG32 CHANMAP23             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP22             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP21             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP20             : 7;
  __REG32                       : 1;
} __chanctrl5_bits;

/* VIM Interrupt Control Register (CHANCTRL6) */
typedef struct {
  __REG32 CHANMAP27             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP26             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP25             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP24             : 7;
  __REG32                       : 1;
} __chanctrl6_bits;

/* VIM Interrupt Control Register (CHANCTRL7) */
typedef struct {
  __REG32 CHANMAP31             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP30             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP29             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP28             : 7;
  __REG32                       : 1;
} __chanctrl7_bits;

/* VIM Interrupt Control Register (CHANCTRL8) */
typedef struct {
  __REG32 CHANMAP35             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP34             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP33             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP32             : 7;
  __REG32                       : 1;
} __chanctrl8_bits;

/* VIM Interrupt Control Register (CHANCTRL9) */
typedef struct {
  __REG32 CHANMAP39             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP38             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP37             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP36             : 7;
  __REG32                       : 1;
} __chanctrl9_bits;

/* VIM Interrupt Control Register (CHANCTRL10) */
typedef struct {
  __REG32 CHANMAP43             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP42             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP41             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP40             : 7;
  __REG32                       : 1;
} __chanctrl10_bits;

/* VIM Interrupt Control Register (CHANCTRL11) */
typedef struct {
  __REG32 CHANMAP47             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP46             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP45             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP44             : 7;
  __REG32                       : 1;
} __chanctrl11_bits;

/* VIM Interrupt Control Register (CHANCTRL12) */
typedef struct {
  __REG32 CHANMAP51             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP50             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP49             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP48             : 7;
  __REG32                       : 1;
} __chanctrl12_bits;

/* VIM Interrupt Control Register (CHANCTRL13) */
typedef struct {
  __REG32 CHANMAP55             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP54             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP53             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP52             : 7;
  __REG32                       : 1;
} __chanctrl13_bits;

/* VIM Interrupt Control Register (CHANCTRL14) */
typedef struct {
  __REG32 CHANMAP59             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP58             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP57             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP56             : 7;
  __REG32                       : 1;
} __chanctrl14_bits;

/* VIM Interrupt Control Register (CHANCTRL15) */
typedef struct {
  __REG32 CHANMAP63             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP62             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP61             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP60             : 7;
  __REG32                       : 1;
} __chanctrl15_bits;

/* VIM Interrupt Control Register (CHANCTRL16) */
typedef struct {
  __REG32 CHANMAP67             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP66             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP65             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP64             : 7;
  __REG32                       : 1;
} __chanctrl16_bits;

/* VIM Interrupt Control Register (CHANCTRL17) */
typedef struct {
  __REG32 CHANMAP71             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP70             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP69             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP68             : 7;
  __REG32                       : 1;
} __chanctrl17_bits;

/* VIM Interrupt Control Register (CHANCTRL18) */
typedef struct {
  __REG32 CHANMAP75             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP74             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP73             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP72             : 7;
  __REG32                       : 1;
} __chanctrl18_bits;

/* VIM Interrupt Control Register (CHANCTRL19) */
typedef struct {
  __REG32 CHANMAP79             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP78             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP77             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP76             : 7;
  __REG32                       : 1;
} __chanctrl19_bits;

/* VIM Interrupt Control Register (CHANCTRL20) */
typedef struct {
  __REG32 CHANMAP83             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP82             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP81             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP80             : 7;
  __REG32                       : 1;
} __chanctrl20_bits;

/* VIM Interrupt Control Register (CHANCTRL21) */
typedef struct {
  __REG32 CHANMAP87             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP86             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP85             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP84             : 7;
  __REG32                       : 1;
} __chanctrl21_bits;

/* VIM Interrupt Control Register (CHANCTRL22) */
typedef struct {
  __REG32 CHANMAP91             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP90             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP89             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP88             : 7;
  __REG32                       : 1;
} __chanctrl22_bits;

/* VIM Interrupt Control Register (CHANCTRL23) */
typedef struct {
  __REG32 CHANMAP95             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP94             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP93             : 7;
  __REG32                       : 1;
  __REG32 CHANMAP92             : 7;
  __REG32                       : 1;
} __chanctrl23_bits;

/* ESM Enable ERROR Pin Action/Response Register 1 (ESMEEPAPR1) */
typedef struct {
  __REG32 IEPSET0               : 1;
  __REG32 IEPSET1               : 1;
  __REG32 IEPSET2               : 1;
  __REG32 IEPSET3               : 1;
  __REG32 IEPSET4               : 1;
  __REG32 IEPSET5               : 1;
  __REG32 IEPSET6               : 1;
  __REG32 IEPSET7               : 1;
  __REG32 IEPSET8               : 1;
  __REG32 IEPSET9               : 1;
  __REG32 IEPSET10              : 1;
  __REG32 IEPSET11              : 1;
  __REG32 IEPSET12              : 1;
  __REG32 IEPSET13              : 1;
  __REG32 IEPSET14              : 1;
  __REG32 IEPSET15              : 1;
  __REG32 IEPSET16              : 1;
  __REG32 IEPSET17              : 1;
  __REG32 IEPSET18              : 1;
  __REG32 IEPSET19              : 1;
  __REG32 IEPSET20              : 1;
  __REG32 IEPSET21              : 1;
  __REG32 IEPSET22              : 1;
  __REG32 IEPSET23              : 1;
  __REG32 IEPSET24              : 1;
  __REG32 IEPSET25              : 1;
  __REG32 IEPSET26              : 1;
  __REG32 IEPSET27              : 1;
  __REG32 IEPSET28              : 1;
  __REG32 IEPSET29              : 1;
  __REG32 IEPSET30              : 1;
  __REG32 IEPSET31              : 1;
} __esmeepapr1_bits;

/* ESM Disable ERROR Pin Action/Response Register 1 (ESMDEPAPR1) */
typedef struct {
  __REG32 IEPCLR0               : 1;
  __REG32 IEPCLR1               : 1;
  __REG32 IEPCLR2               : 1;
  __REG32 IEPCLR3               : 1;
  __REG32 IEPCLR4               : 1;
  __REG32 IEPCLR5               : 1;
  __REG32 IEPCLR6               : 1;
  __REG32 IEPCLR7               : 1;
  __REG32 IEPCLR8               : 1;
  __REG32 IEPCLR9               : 1;
  __REG32 IEPCLR10              : 1;
  __REG32 IEPCLR11              : 1;
  __REG32 IEPCLR12              : 1;
  __REG32 IEPCLR13              : 1;
  __REG32 IEPCLR14              : 1;
  __REG32 IEPCLR15              : 1;
  __REG32 IEPCLR16              : 1;
  __REG32 IEPCLR17              : 1;
  __REG32 IEPCLR18              : 1;
  __REG32 IEPCLR19              : 1;
  __REG32 IEPCLR20              : 1;
  __REG32 IEPCLR21              : 1;
  __REG32 IEPCLR22              : 1;
  __REG32 IEPCLR23              : 1;
  __REG32 IEPCLR24              : 1;
  __REG32 IEPCLR25              : 1;
  __REG32 IEPCLR26              : 1;
  __REG32 IEPCLR27              : 1;
  __REG32 IEPCLR28              : 1;
  __REG32 IEPCLR29              : 1;
  __REG32 IEPCLR30              : 1;
  __REG32 IEPCLR31              : 1;
} __esmdepapr1_bits;

/* ESM Interrupt Enable Set/Status Register 1 (ESMIESR1) */
typedef struct {
  __REG32 INTENSET0               : 1;
  __REG32 INTENSET1               : 1;
  __REG32 INTENSET2               : 1;
  __REG32 INTENSET3               : 1;
  __REG32 INTENSET4               : 1;
  __REG32 INTENSET5               : 1;
  __REG32 INTENSET6               : 1;
  __REG32 INTENSET7               : 1;
  __REG32 INTENSET8               : 1;
  __REG32 INTENSET9               : 1;
  __REG32 INTENSET10              : 1;
  __REG32 INTENSET11              : 1;
  __REG32 INTENSET12              : 1;
  __REG32 INTENSET13              : 1;
  __REG32 INTENSET14              : 1;
  __REG32 INTENSET15              : 1;
  __REG32 INTENSET16              : 1;
  __REG32 INTENSET17              : 1;
  __REG32 INTENSET18              : 1;
  __REG32 INTENSET19              : 1;
  __REG32 INTENSET20              : 1;
  __REG32 INTENSET21              : 1;
  __REG32 INTENSET22              : 1;
  __REG32 INTENSET23              : 1;
  __REG32 INTENSET24              : 1;
  __REG32 INTENSET25              : 1;
  __REG32 INTENSET26              : 1;
  __REG32 INTENSET27              : 1;
  __REG32 INTENSET28              : 1;
  __REG32 INTENSET29              : 1;
  __REG32 INTENSET30              : 1;
  __REG32 INTENSET31              : 1;
} __esmiesr1_bits;

/* ESM Interrupt Enable Clear/Status Register 1 (ESMIECR1) */
typedef struct {
  __REG32 INTENCLR0               : 1;
  __REG32 INTENCLR1               : 1;
  __REG32 INTENCLR2               : 1;
  __REG32 INTENCLR3               : 1;
  __REG32 INTENCLR4               : 1;
  __REG32 INTENCLR5               : 1;
  __REG32 INTENCLR6               : 1;
  __REG32 INTENCLR7               : 1;
  __REG32 INTENCLR8               : 1;
  __REG32 INTENCLR9               : 1;
  __REG32 INTENCLR10              : 1;
  __REG32 INTENCLR11              : 1;
  __REG32 INTENCLR12              : 1;
  __REG32 INTENCLR13              : 1;
  __REG32 INTENCLR14              : 1;
  __REG32 INTENCLR15              : 1;
  __REG32 INTENCLR16              : 1;
  __REG32 INTENCLR17              : 1;
  __REG32 INTENCLR18              : 1;
  __REG32 INTENCLR19              : 1;
  __REG32 INTENCLR20              : 1;
  __REG32 INTENCLR21              : 1;
  __REG32 INTENCLR22              : 1;
  __REG32 INTENCLR23              : 1;
  __REG32 INTENCLR24              : 1;
  __REG32 INTENCLR25              : 1;
  __REG32 INTENCLR26              : 1;
  __REG32 INTENCLR27              : 1;
  __REG32 INTENCLR28              : 1;
  __REG32 INTENCLR29              : 1;
  __REG32 INTENCLR30              : 1;
  __REG32 INTENCLR31              : 1;
} __esmiecr1_bits;

/* ESM Interrupt Level Set/Status Register 1 (ESMILSR1) */
typedef struct {
  __REG32 INTLVLSET0               : 1;
  __REG32 INTLVLSET1               : 1;
  __REG32 INTLVLSET2               : 1;
  __REG32 INTLVLSET3               : 1;
  __REG32 INTLVLSET4               : 1;
  __REG32 INTLVLSET5               : 1;
  __REG32 INTLVLSET6               : 1;
  __REG32 INTLVLSET7               : 1;
  __REG32 INTLVLSET8               : 1;
  __REG32 INTLVLSET9               : 1;
  __REG32 INTLVLSET10              : 1;
  __REG32 INTLVLSET11              : 1;
  __REG32 INTLVLSET12              : 1;
  __REG32 INTLVLSET13              : 1;
  __REG32 INTLVLSET14              : 1;
  __REG32 INTLVLSET15              : 1;
  __REG32 INTLVLSET16              : 1;
  __REG32 INTLVLSET17              : 1;
  __REG32 INTLVLSET18              : 1;
  __REG32 INTLVLSET19              : 1;
  __REG32 INTLVLSET20              : 1;
  __REG32 INTLVLSET21              : 1;
  __REG32 INTLVLSET22              : 1;
  __REG32 INTLVLSET23              : 1;
  __REG32 INTLVLSET24              : 1;
  __REG32 INTLVLSET25              : 1;
  __REG32 INTLVLSET26              : 1;
  __REG32 INTLVLSET27              : 1;
  __REG32 INTLVLSET28              : 1;
  __REG32 INTLVLSET29              : 1;
  __REG32 INTLVLSET30              : 1;
  __REG32 INTLVLSET31              : 1;
} __esmilsr1_bits;

/* ESM Interrupt Level Clear/Status Register 1 (ESMILCR1) */
typedef struct {
  __REG32 INTLVLCLR0               : 1;
  __REG32 INTLVLCLR1               : 1;
  __REG32 INTLVLCLR2               : 1;
  __REG32 INTLVLCLR3               : 1;
  __REG32 INTLVLCLR4               : 1;
  __REG32 INTLVLCLR5               : 1;
  __REG32 INTLVLCLR6               : 1;
  __REG32 INTLVLCLR7               : 1;
  __REG32 INTLVLCLR8               : 1;
  __REG32 INTLVLCLR9               : 1;
  __REG32 INTLVLCLR10              : 1;
  __REG32 INTLVLCLR11              : 1;
  __REG32 INTLVLCLR12              : 1;
  __REG32 INTLVLCLR13              : 1;
  __REG32 INTLVLCLR14              : 1;
  __REG32 INTLVLCLR15              : 1;
  __REG32 INTLVLCLR16              : 1;
  __REG32 INTLVLCLR17              : 1;
  __REG32 INTLVLCLR18              : 1;
  __REG32 INTLVLCLR19              : 1;
  __REG32 INTLVLCLR20              : 1;
  __REG32 INTLVLCLR21              : 1;
  __REG32 INTLVLCLR22              : 1;
  __REG32 INTLVLCLR23              : 1;
  __REG32 INTLVLCLR24              : 1;
  __REG32 INTLVLCLR25              : 1;
  __REG32 INTLVLCLR26              : 1;
  __REG32 INTLVLCLR27              : 1;
  __REG32 INTLVLCLR28              : 1;
  __REG32 INTLVLCLR29              : 1;
  __REG32 INTLVLCLR30              : 1;
  __REG32 INTLVLCLR31              : 1;
} __esmilcr1_bits;

/* ESM Status Register 1 (ESMSR1) */
typedef struct {
  __REG32 ESF0               : 1;
  __REG32 ESF1               : 1;
  __REG32 ESF2               : 1;
  __REG32 ESF3               : 1;
  __REG32 ESF4               : 1;
  __REG32 ESF5               : 1;
  __REG32 ESF6               : 1;
  __REG32 ESF7               : 1;
  __REG32 ESF8               : 1;
  __REG32 ESF9               : 1;
  __REG32 ESF10              : 1;
  __REG32 ESF11              : 1;
  __REG32 ESF12              : 1;
  __REG32 ESF13              : 1;
  __REG32 ESF14              : 1;
  __REG32 ESF15              : 1;
  __REG32 ESF16              : 1;
  __REG32 ESF17              : 1;
  __REG32 ESF18              : 1;
  __REG32 ESF19              : 1;
  __REG32 ESF20              : 1;
  __REG32 ESF21              : 1;
  __REG32 ESF22              : 1;
  __REG32 ESF23              : 1;
  __REG32 ESF24              : 1;
  __REG32 ESF25              : 1;
  __REG32 ESF26              : 1;
  __REG32 ESF27              : 1;
  __REG32 ESF28              : 1;
  __REG32 ESF29              : 1;
  __REG32 ESF30              : 1;
  __REG32 ESF31              : 1;
} __esmsr_bits;

/* ESM Error Pin Status Register (ESMEPSR) */
typedef struct {
  __REG32 EPSF               : 1;
  __REG32                    :31;
} __esmepsr_bits;

/* ESM Interrupt Offset High Register (ESMIOFFHR) */
typedef struct {
  __REG32 INTOFFH            : 7;
  __REG32                    :25;
} __esmioffhr_bits;

/* ESM Interrupt Offset Low Register (ESMIOFFLR) */
typedef struct {
  __REG32 INTOFFL            : 7;
  __REG32                    :25;
} __esmiofflr_bits;

/* ESM Low-Time Counter Register (ESMLTCR) */
typedef struct {
  __REG32 LTC                :16;
  __REG32                    :16;
} __esmltcr_bits;

/* ESM Low-Time Counter Preload Register (ESMLTCPR) */
typedef struct {
  __REG32 LTCP               :16;
  __REG32                    :16;
} __esmltcpr_bits;

/* ESM Error Key Register (ESMEKR) */
typedef struct {
  __REG32 EKEY               : 4;
  __REG32                    :28;
} __esmekr_bits;

/* ESM Influence ERROR Pin Set/Status Register 4 (ESMIEPSR4) */
typedef struct {
  __REG32 IEPSET32              : 1;
  __REG32 IEPSET33              : 1;
  __REG32 IEPSET34              : 1;
  __REG32 IEPSET35              : 1;
  __REG32 IEPSET36              : 1;
  __REG32 IEPSET37              : 1;
  __REG32 IEPSET38              : 1;
  __REG32 IEPSET39              : 1;
  __REG32 IEPSET40              : 1;
  __REG32 IEPSET41              : 1;
  __REG32 IEPSET42              : 1;
  __REG32 IEPSET43              : 1;
  __REG32 IEPSET44              : 1;
  __REG32 IEPSET45              : 1;
  __REG32 IEPSET46              : 1;
  __REG32 IEPSET47              : 1;
  __REG32 IEPSET48              : 1;
  __REG32 IEPSET49              : 1;
  __REG32 IEPSET50              : 1;
  __REG32 IEPSET51              : 1;
  __REG32 IEPSET52              : 1;
  __REG32 IEPSET53              : 1;
  __REG32 IEPSET54              : 1;
  __REG32 IEPSET55              : 1;
  __REG32 IEPSET56              : 1;
  __REG32 IEPSET57              : 1;
  __REG32 IEPSET58              : 1;
  __REG32 IEPSET59              : 1;
  __REG32 IEPSET60              : 1;
  __REG32 IEPSET61              : 1;
  __REG32 IEPSET62              : 1;
  __REG32 IEPSET63              : 1;
} __esmiepsr4_bits;

/* ESM Influence ERROR Pin Clear/Status Register 4 (ESMIEPCR4) */
typedef struct {
  __REG32 IEPCLR32              : 1;
  __REG32 IEPCLR33              : 1;
  __REG32 IEPCLR34              : 1;
  __REG32 IEPCLR35              : 1;
  __REG32 IEPCLR36              : 1;
  __REG32 IEPCLR37              : 1;
  __REG32 IEPCLR38              : 1;
  __REG32 IEPCLR39              : 1;
  __REG32 IEPCLR40              : 1;
  __REG32 IEPCLR41              : 1;
  __REG32 IEPCLR42              : 1;
  __REG32 IEPCLR43              : 1;
  __REG32 IEPCLR44              : 1;
  __REG32 IEPCLR45              : 1;
  __REG32 IEPCLR46              : 1;
  __REG32 IEPCLR47              : 1;
  __REG32 IEPCLR48              : 1;
  __REG32 IEPCLR49              : 1;
  __REG32 IEPCLR50              : 1;
  __REG32 IEPCLR51              : 1;
  __REG32 IEPCLR52              : 1;
  __REG32 IEPCLR53              : 1;
  __REG32 IEPCLR54              : 1;
  __REG32 IEPCLR55              : 1;
  __REG32 IEPCLR56              : 1;
  __REG32 IEPCLR57              : 1;
  __REG32 IEPCLR58              : 1;
  __REG32 IEPCLR59              : 1;
  __REG32 IEPCLR60              : 1;
  __REG32 IEPCLR61              : 1;
  __REG32 IEPCLR62              : 1;
  __REG32 IEPCLR63              : 1;
} __esmiepcr4_bits;

/* ESM Interrupt Enable Set/Status Register 4 (ESMIESR4) */
typedef struct {
  __REG32 INTENSET32              : 1;
  __REG32 INTENSET33              : 1;
  __REG32 INTENSET34              : 1;
  __REG32 INTENSET35              : 1;
  __REG32 INTENSET36              : 1;
  __REG32 INTENSET37              : 1;
  __REG32 INTENSET38              : 1;
  __REG32 INTENSET39              : 1;
  __REG32 INTENSET40              : 1;
  __REG32 INTENSET41              : 1;
  __REG32 INTENSET42              : 1;
  __REG32 INTENSET43              : 1;
  __REG32 INTENSET44              : 1;
  __REG32 INTENSET45              : 1;
  __REG32 INTENSET46              : 1;
  __REG32 INTENSET47              : 1;
  __REG32 INTENSET48              : 1;
  __REG32 INTENSET49              : 1;
  __REG32 INTENSET50              : 1;
  __REG32 INTENSET51              : 1;
  __REG32 INTENSET52              : 1;
  __REG32 INTENSET53              : 1;
  __REG32 INTENSET54              : 1;
  __REG32 INTENSET55              : 1;
  __REG32 INTENSET56              : 1;
  __REG32 INTENSET57              : 1;
  __REG32 INTENSET58              : 1;
  __REG32 INTENSET59              : 1;
  __REG32 INTENSET60              : 1;
  __REG32 INTENSET61              : 1;
  __REG32 INTENSET62              : 1;
  __REG32 INTENSET63              : 1;
} __esmiesr4_bits;

/* ESM Interrupt Enable Clear/Status Register 4 (ESMIECR4) */
typedef struct {
  __REG32 INTENCLR32              : 1;
  __REG32 INTENCLR33              : 1;
  __REG32 INTENCLR34              : 1;
  __REG32 INTENCLR35              : 1;
  __REG32 INTENCLR36              : 1;
  __REG32 INTENCLR37              : 1;
  __REG32 INTENCLR38              : 1;
  __REG32 INTENCLR39              : 1;
  __REG32 INTENCLR40              : 1;
  __REG32 INTENCLR41              : 1;
  __REG32 INTENCLR42              : 1;
  __REG32 INTENCLR43              : 1;
  __REG32 INTENCLR44              : 1;
  __REG32 INTENCLR45              : 1;
  __REG32 INTENCLR46              : 1;
  __REG32 INTENCLR47              : 1;
  __REG32 INTENCLR48              : 1;
  __REG32 INTENCLR49              : 1;
  __REG32 INTENCLR50              : 1;
  __REG32 INTENCLR51              : 1;
  __REG32 INTENCLR52              : 1;
  __REG32 INTENCLR53              : 1;
  __REG32 INTENCLR54              : 1;
  __REG32 INTENCLR55              : 1;
  __REG32 INTENCLR56              : 1;
  __REG32 INTENCLR57              : 1;
  __REG32 INTENCLR58              : 1;
  __REG32 INTENCLR59              : 1;
  __REG32 INTENCLR60              : 1;
  __REG32 INTENCLR61              : 1;
  __REG32 INTENCLR62              : 1;
  __REG32 INTENCLR63              : 1;
} __esmiecr4_bits;

/* ESM Interrupt Level Set/Status Register 4 (ESMILSR4) */
typedef struct {
  __REG32 INTLVLSET32              : 1;
  __REG32 INTLVLSET33              : 1;
  __REG32 INTLVLSET34              : 1;
  __REG32 INTLVLSET35              : 1;
  __REG32 INTLVLSET36              : 1;
  __REG32 INTLVLSET37              : 1;
  __REG32 INTLVLSET38              : 1;
  __REG32 INTLVLSET39              : 1;
  __REG32 INTLVLSET40              : 1;
  __REG32 INTLVLSET41              : 1;
  __REG32 INTLVLSET42              : 1;
  __REG32 INTLVLSET43              : 1;
  __REG32 INTLVLSET44              : 1;
  __REG32 INTLVLSET45              : 1;
  __REG32 INTLVLSET46              : 1;
  __REG32 INTLVLSET47              : 1;
  __REG32 INTLVLSET48              : 1;
  __REG32 INTLVLSET49              : 1;
  __REG32 INTLVLSET50              : 1;
  __REG32 INTLVLSET51              : 1;
  __REG32 INTLVLSET52              : 1;
  __REG32 INTLVLSET53              : 1;
  __REG32 INTLVLSET54              : 1;
  __REG32 INTLVLSET55              : 1;
  __REG32 INTLVLSET56              : 1;
  __REG32 INTLVLSET57              : 1;
  __REG32 INTLVLSET58              : 1;
  __REG32 INTLVLSET59              : 1;
  __REG32 INTLVLSET60              : 1;
  __REG32 INTLVLSET61              : 1;
  __REG32 INTLVLSET62              : 1;
  __REG32 INTLVLSET63              : 1;
} __esmilsr4_bits;

/* ESM Interrupt Level Set/Status Register 4 (ESMILSR4) */
typedef struct {
  __REG32 INTLVLCLR32              : 1;
  __REG32 INTLVLCLR33              : 1;
  __REG32 INTLVLCLR34              : 1;
  __REG32 INTLVLCLR35              : 1;
  __REG32 INTLVLCLR36              : 1;
  __REG32 INTLVLCLR37              : 1;
  __REG32 INTLVLCLR38              : 1;
  __REG32 INTLVLCLR39              : 1;
  __REG32 INTLVLCLR40              : 1;
  __REG32 INTLVLCLR41              : 1;
  __REG32 INTLVLCLR42              : 1;
  __REG32 INTLVLCLR43              : 1;
  __REG32 INTLVLCLR44              : 1;
  __REG32 INTLVLCLR45              : 1;
  __REG32 INTLVLCLR46              : 1;
  __REG32 INTLVLCLR47              : 1;
  __REG32 INTLVLCLR48              : 1;
  __REG32 INTLVLCLR49              : 1;
  __REG32 INTLVLCLR50              : 1;
  __REG32 INTLVLCLR51              : 1;
  __REG32 INTLVLCLR52              : 1;
  __REG32 INTLVLCLR53              : 1;
  __REG32 INTLVLCLR54              : 1;
  __REG32 INTLVLCLR55              : 1;
  __REG32 INTLVLCLR56              : 1;
  __REG32 INTLVLCLR57              : 1;
  __REG32 INTLVLCLR58              : 1;
  __REG32 INTLVLCLR59              : 1;
  __REG32 INTLVLCLR60              : 1;
  __REG32 INTLVLCLR61              : 1;
  __REG32 INTLVLCLR62              : 1;
  __REG32 INTLVLCLR63              : 1;
} __esmilcr4_bits;

/* ESM Status Register 4 (ESMSR4) */
typedef struct {
  __REG32 ESF32              : 1;
  __REG32 ESF33              : 1;
  __REG32 ESF34              : 1;
  __REG32 ESF35              : 1;
  __REG32 ESF36              : 1;
  __REG32 ESF37              : 1;
  __REG32 ESF38              : 1;
  __REG32 ESF39              : 1;
  __REG32 ESF40              : 1;
  __REG32 ESF41              : 1;
  __REG32 ESF42              : 1;
  __REG32 ESF43              : 1;
  __REG32 ESF44              : 1;
  __REG32 ESF45              : 1;
  __REG32 ESF46              : 1;
  __REG32 ESF47              : 1;
  __REG32 ESF48              : 1;
  __REG32 ESF49              : 1;
  __REG32 ESF50              : 1;
  __REG32 ESF51              : 1;
  __REG32 ESF52              : 1;
  __REG32 ESF53              : 1;
  __REG32 ESF54              : 1;
  __REG32 ESF55              : 1;
  __REG32 ESF56              : 1;
  __REG32 ESF57              : 1;
  __REG32 ESF58              : 1;
  __REG32 ESF59              : 1;
  __REG32 ESF60              : 1;
  __REG32 ESF61              : 1;
  __REG32 ESF62              : 1;
  __REG32 ESF63              : 1;
} __esmsr4_bits;

/* DMM Global Control Register (DMMGLBCTRL) */
typedef struct {
  __REG32 ON_OFF             : 4;
  __REG32                    : 4;
  __REG32 TM_DDM             : 1;
  __REG32 DDM_WIDTH          : 2;
  __REG32                    : 5;
  __REG32 RESET              : 1;
  __REG32 COS                : 1;
  __REG32 CONTCLK            : 1;
  __REG32                    : 5;
  __REG32 BUSY               : 1;
  __REG32                    : 7;
} __dmmglbctrl_bits;

/* DMM Interrupt Set Register (DMMINTSET) */
typedef struct {
  __REG32 PACKET_ERR_INT      : 1;
  __REG32 DEST0_ERR           : 1;
  __REG32 DEST1_ERR           : 1;
  __REG32 DEST2_ERR           : 1;
  __REG32 DEST3_ERR           : 1;
  __REG32 SRC_OVF             : 1;
  __REG32 BUFF_OVF            : 1;
  __REG32 BUSERROR            : 1;
  __REG32 DEST0REG1           : 1;
  __REG32 DEST0REG2           : 1;
  __REG32 DEST1REG1           : 1;
  __REG32 DEST1REG2           : 1;
  __REG32 DEST2REG1           : 1;
  __REG32 DEST2REG2           : 1;
  __REG32 DEST3REG1           : 1;
  __REG32 DEST3REG2           : 1;
  __REG32 EO_BUFF             : 1;
  __REG32 PROG_BUFF           : 1;
  __REG32                     :14;
} __dmmintset_bits;

/* DMM Interrupt Offset 1 Register (DMMOFF1) */
typedef struct {
  __REG32 OFFSET              : 5;
  __REG32                     :27;
} __dmmoff_bits;

/* DMM Direct Data Mode Blocksize Register (DMMDDMBL) */
typedef struct {
  __REG32 BLOCKSIZE           : 4;
  __REG32                     :28;
} __dmmddmbl_bits;

/* DMM Direct Data Mode Pointer Register (DMMDDMPT) */
typedef struct {
  __REG32 POINTER             :15;
  __REG32                     :17;
} __dmmddmpt_bits;

/* DMM Direct Data Mode Interrupt Pointer Register (DMMINTPT) */
typedef struct {
  __REG32 INTPT               :15;
  __REG32                     :17;
} __dmmintpt_bits;

/* DMM Destination x Region n (DMMDESTxREGn) */
typedef struct {
  __REG32 BLOCKADDR           :18;
  __REG32 BASEADDR            :14;
} __dmmdestreg_bits;

/* DMM Destination x Blocksize n (DMMDESTxBLn) */
typedef struct {
  __REG32 BLOCKSIZE           : 4;
  __REG32                     :28;
} __dmmdestbl_bits;

/* DMM Pin Control 0 (DMMPC0) */
typedef struct {
  __REG32 SYNCFUNC            : 1;
  __REG32 CLKFUNC             : 1;
  __REG32 DATA0FUNC           : 1;
  __REG32 DATA1FUNC           : 1;
  __REG32 DATA2FUNC           : 1;
  __REG32 DATA3FUNC           : 1;
  __REG32 DATA4FUNC           : 1;
  __REG32 DATA5FUNC           : 1;
  __REG32 DATA6FUNC           : 1;
  __REG32 DATA7FUNC           : 1;
  __REG32 DATA8FUNC           : 1;
  __REG32 DATA9FUNC           : 1;
  __REG32 DATA10FUNC          : 1;
  __REG32 DATA11FUNC          : 1;
  __REG32 DATA12FUNC          : 1;
  __REG32 DATA13FUNC          : 1;
  __REG32 DATA14FUNC          : 1;
  __REG32 DATA15FUNC          : 1;
  __REG32 ENAFUNC             : 1;
  __REG32                     :13;
} __dmmpc0_bits;

/* DMM Pin Control 1 (DMMPC1) */
typedef struct {
  __REG32 SYNCDIR             : 1;
  __REG32 CLKDIR              : 1;
  __REG32 DATA0DIR            : 1;
  __REG32 DATA1DIR            : 1;
  __REG32 DATA2DIR            : 1;
  __REG32 DATA3DIR            : 1;
  __REG32 DATA4DIR            : 1;
  __REG32 DATA5DIR            : 1;
  __REG32 DATA6DIR            : 1;
  __REG32 DATA7DIR            : 1;
  __REG32 DATA8DIR            : 1;
  __REG32 DATA9DIR            : 1;
  __REG32 DATA10DIR           : 1;
  __REG32 DATA11DIR           : 1;
  __REG32 DATA12DIR           : 1;
  __REG32 DATA13DIR           : 1;
  __REG32 DATA14DIR           : 1;
  __REG32 DATA15DIR           : 1;
  __REG32 ENADIR              : 1;
  __REG32                     :13;
} __dmmpc1_bits;

/* DMM Pin Control 2 (DMMPC2) */
typedef struct {
  __REG32 SYNCIN             : 1;
  __REG32 CLKIN              : 1;
  __REG32 DATA0IN            : 1;
  __REG32 DATA1IN            : 1;
  __REG32 DATA2IN            : 1;
  __REG32 DATA3IN            : 1;
  __REG32 DATA4IN            : 1;
  __REG32 DATA5IN            : 1;
  __REG32 DATA6IN            : 1;
  __REG32 DATA7IN            : 1;
  __REG32 DATA8IN            : 1;
  __REG32 DATA9IN            : 1;
  __REG32 DATA10IN           : 1;
  __REG32 DATA11IN           : 1;
  __REG32 DATA12IN           : 1;
  __REG32 DATA13IN           : 1;
  __REG32 DATA14IN           : 1;
  __REG32 DATA15IN           : 1;
  __REG32 ENAIN              : 1;
  __REG32                    :13;
} __dmmpc2_bits;

/* DMM Pin Control 3 (DMMPC3) */
typedef struct {
  __REG32 SYNCOUT             : 1;
  __REG32 CLKOUT              : 1;
  __REG32 DATA0OUT            : 1;
  __REG32 DATA1OUT            : 1;
  __REG32 DATA2OUT            : 1;
  __REG32 DATA3OUT            : 1;
  __REG32 DATA4OUT            : 1;
  __REG32 DATA5OUT            : 1;
  __REG32 DATA6OUT            : 1;
  __REG32 DATA7OUT            : 1;
  __REG32 DATA8OUT            : 1;
  __REG32 DATA9OUT            : 1;
  __REG32 DATA10OUT           : 1;
  __REG32 DATA11OUT           : 1;
  __REG32 DATA12OUT           : 1;
  __REG32 DATA13OUT           : 1;
  __REG32 DATA14OUT           : 1;
  __REG32 DATA15OUT           : 1;
  __REG32 ENAOUT              : 1;
  __REG32                     :13;
} __dmmpc3_bits;

/* DMM Pin Control 4 (DMMPC5) */
typedef struct {
  __REG32 SYNCSET             : 1;
  __REG32 CLKSET              : 1;
  __REG32 DATA0SET            : 1;
  __REG32 DATA1SET            : 1;
  __REG32 DATA2SET            : 1;
  __REG32 DATA3SET            : 1;
  __REG32 DATA4SET            : 1;
  __REG32 DATA5SET            : 1;
  __REG32 DATA6SET            : 1;
  __REG32 DATA7SET            : 1;
  __REG32 DATA8SET            : 1;
  __REG32 DATA9SET            : 1;
  __REG32 DATA10SET           : 1;
  __REG32 DATA11SET           : 1;
  __REG32 DATA12SET           : 1;
  __REG32 DATA13SET           : 1;
  __REG32 DATA14SET           : 1;
  __REG32 DATA15SET           : 1;
  __REG32 ENASET              : 1;
  __REG32                     :13;
} __dmmpc4_bits;

/* DMM Pin Control 5 (DMMPC5) */
typedef struct {
  __REG32 SYNCCLR             : 1;
  __REG32 CLKCLR              : 1;
  __REG32 DATA0CLR            : 1;
  __REG32 DATA1CLR            : 1;
  __REG32 DATA2CLR            : 1;
  __REG32 DATA3CLR            : 1;
  __REG32 DATA4CLR            : 1;
  __REG32 DATA5CLR            : 1;
  __REG32 DATA6CLR            : 1;
  __REG32 DATA7CLR            : 1;
  __REG32 DATA8CLR            : 1;
  __REG32 DATA9CLR            : 1;
  __REG32 DATA10CLR           : 1;
  __REG32 DATA11CLR           : 1;
  __REG32 DATA12CLR           : 1;
  __REG32 DATA13CLR           : 1;
  __REG32 DATA14CLR           : 1;
  __REG32 DATA15CLR           : 1;
  __REG32 ENACLR              : 1;
  __REG32                     :13;
} __dmmpc5_bits;

/* DMM Pin Control 6 (DMMPC6) */
typedef struct {
  __REG32 SYNCPDR             : 1;
  __REG32 CLKPDR              : 1;
  __REG32 DATA0PDR            : 1;
  __REG32 DATA1PDR            : 1;
  __REG32 DATA2PDR            : 1;
  __REG32 DATA3PDR            : 1;
  __REG32 DATA4PDR            : 1;
  __REG32 DATA5PDR            : 1;
  __REG32 DATA6PDR            : 1;
  __REG32 DATA7PDR            : 1;
  __REG32 DATA8PDR            : 1;
  __REG32 DATA9PDR            : 1;
  __REG32 DATA10PDR           : 1;
  __REG32 DATA11PDR           : 1;
  __REG32 DATA12PDR           : 1;
  __REG32 DATA13PDR           : 1;
  __REG32 DATA14PDR           : 1;
  __REG32 DATA15PDR           : 1;
  __REG32 ENAPDR              : 1;
  __REG32                     :13;
} __dmmpc6_bits;

/* DMM Pin Control 7 (DMMPC7) */
typedef struct {
  __REG32 SYNCPDIS            : 1;
  __REG32 CLKPDIS             : 1;
  __REG32 DATA0PDIS           : 1;
  __REG32 DATA1PDIS           : 1;
  __REG32 DATA2PDIS           : 1;
  __REG32 DATA3PDIS           : 1;
  __REG32 DATA4PDIS           : 1;
  __REG32 DATA5PDIS           : 1;
  __REG32 DATA6PDIS           : 1;
  __REG32 DATA7PDIS           : 1;
  __REG32 DATA8PDIS           : 1;
  __REG32 DATA9PDIS           : 1;
  __REG32 DATA10PDIS          : 1;
  __REG32 DATA11PDIS          : 1;
  __REG32 DATA12PDIS          : 1;
  __REG32 DATA13PDIS          : 1;
  __REG32 DATA14PDIS          : 1;
  __REG32 DATA15PDIS          : 1;
  __REG32 ENAPDIS             : 1;
  __REG32                     :13;
} __dmmpc7_bits;

/* DMM Pin Control 8 (DMMPC8) */
typedef struct {
  __REG32 SYNCPSEL            : 1;
  __REG32 CLKPSEL             : 1;
  __REG32 DATA0PSEL           : 1;
  __REG32 DATA1PSEL           : 1;
  __REG32 DATA2PSEL           : 1;
  __REG32 DATA3PSEL           : 1;
  __REG32 DATA4PSEL           : 1;
  __REG32 DATA5PSEL           : 1;
  __REG32 DATA6PSEL           : 1;
  __REG32 DATA7PSEL           : 1;
  __REG32 DATA8PSEL           : 1;
  __REG32 DATA9PSEL           : 1;
  __REG32 DATA10PSEL          : 1;
  __REG32 DATA11PSEL          : 1;
  __REG32 DATA12PSEL          : 1;
  __REG32 DATA13PSEL          : 1;
  __REG32 DATA14PSEL          : 1;
  __REG32 DATA15PSEL          : 1;
  __REG32 ENAPSEL             : 1;
  __REG32                     :13;
} __dmmpc8_bits;

/* RTP Global Control Register (RTPGLBCTRL) */
typedef struct {
  __REG32 ON_OFF              : 4;
  __REG32 INV_RGN             : 1;
  __REG32 HOVF                : 1;
  __REG32 CONTCLK             : 1;
  __REG32 RESET               : 1;
  __REG32 PW                  : 2;
  __REG32 TM_DDM              : 1;
  __REG32 DDM_RW              : 1;
  __REG32 DDM_WIDTH           : 2;
  __REG32                     : 2;
  __REG32 PRESCALER           : 3;
  __REG32                     : 5;
  __REG32 TEST                : 1;
  __REG32                     : 7;
} __rtpglbctrl_bits;

/* RTP Trace Enable Register (RTPTRENA) */
typedef struct {
  __REG32 ENA1                : 1;
  __REG32                     : 7;
  __REG32 ENA2                : 1;
  __REG32                     :15;
  __REG32 ENA4                : 1;
  __REG32                     : 7;
} __rtptrena_bits;

/* RTP Global Status Register (RTPGSR) */
typedef struct {
  __REG32 OVF1                : 1;
  __REG32 OVF2                : 1;
  __REG32                     : 1;
  __REG32 OVFPER              : 1;
  __REG32                     : 4;
  __REG32 EMPTY1              : 1;
  __REG32 EMPTY2              : 1;
  __REG32                     : 1;
  __REG32 EMPTYPER            : 1;
  __REG32 EMPTYSER            : 1;
  __REG32                     :19;
} __rtpgsr_bits;

/* RTP RAM 1/2 Trace Region x Register  */
typedef struct {
  __REG32 STARTADDR           :18;
  __REG32                     : 6;
  __REG32 BLOCKSIZE           : 4;
  __REG32 RW                  : 1;
  __REG32 CPU_DMA             : 2;
  __REG32                     : 1;
} __rtpramreg_bits;

/* RTP Peripheral Trace Region [1:2] Registers (RTPPERREG[1:2]) */
typedef struct {
  __REG32 STARTADDR           :24;
  __REG32 BLOCKSIZE           : 4;
  __REG32 RW                  : 1;
  __REG32 CPU_DMA             : 2;
  __REG32                     : 1;
} __rtpperreg_bits;

/* RTP Pin Control 0 Register (RTPPC0) */
typedef struct {
  __REG32 DATA0FUNC           : 1;
  __REG32 DATA1FUNC           : 1;
  __REG32 DATA2FUNC           : 1;
  __REG32 DATA3FUNC           : 1;
  __REG32 DATA4FUNC           : 1;
  __REG32 DATA5FUNC           : 1;
  __REG32 DATA6FUNC           : 1;
  __REG32 DATA7FUNC           : 1;
  __REG32 DATA8FUNC           : 1;
  __REG32 DATA9FUNC           : 1;
  __REG32 DATA10FUNC          : 1;
  __REG32 DATA11FUNC          : 1;
  __REG32 DATA12FUNC          : 1;
  __REG32 DATA13FUNC          : 1;
  __REG32 DATA14FUNC          : 1;
  __REG32 DATA15FUNC          : 1;
  __REG32 SYNCFUNC            : 1;
  __REG32 CLKFUNC             : 1;
  __REG32 ENAFUNC             : 1;
  __REG32                     :13;
} __rtppc0_bits;

/* RTP Pin Control 1 Register (RTPPC1) */
typedef struct {
  __REG32 DATA0DIR           : 1;
  __REG32 DATA1DIR           : 1;
  __REG32 DATA2DIR           : 1;
  __REG32 DATA3DIR           : 1;
  __REG32 DATA4DIR           : 1;
  __REG32 DATA5DIR           : 1;
  __REG32 DATA6DIR           : 1;
  __REG32 DATA7DIR           : 1;
  __REG32 DATA8DIR           : 1;
  __REG32 DATA9DIR           : 1;
  __REG32 DATA10DIR          : 1;
  __REG32 DATA11DIR          : 1;
  __REG32 DATA12DIR          : 1;
  __REG32 DATA13DIR          : 1;
  __REG32 DATA14DIR          : 1;
  __REG32 DATA15DIR          : 1;
  __REG32 SYNCDIR            : 1;
  __REG32 CLKDIR             : 1;
  __REG32 ENADIR             : 1;
  __REG32                    :13;
} __rtppc1_bits;

/* RTP Pin Control 2 Register (RTPPC2) */
typedef struct {
  __REG32 DATA0IN           : 1;
  __REG32 DATA1IN           : 1;
  __REG32 DATA2IN           : 1;
  __REG32 DATA3IN           : 1;
  __REG32 DATA4IN           : 1;
  __REG32 DATA5IN           : 1;
  __REG32 DATA6IN           : 1;
  __REG32 DATA7IN           : 1;
  __REG32 DATA8IN           : 1;
  __REG32 DATA9IN           : 1;
  __REG32 DATA10IN          : 1;
  __REG32 DATA11IN          : 1;
  __REG32 DATA12IN          : 1;
  __REG32 DATA13IN          : 1;
  __REG32 DATA14IN          : 1;
  __REG32 DATA15IN          : 1;
  __REG32 SYNCIN            : 1;
  __REG32 CLKIN             : 1;
  __REG32 ENAIN             : 1;
  __REG32                   :13;
} __rtppc2_bits;

/* RTP Pin Control 3 Register (RTPPC3) */
typedef struct {
  __REG32 DATA0OUT           : 1;
  __REG32 DATA1OUT           : 1;
  __REG32 DATA2OUT           : 1;
  __REG32 DATA3OUT           : 1;
  __REG32 DATA4OUT           : 1;
  __REG32 DATA5OUT           : 1;
  __REG32 DATA6OUT           : 1;
  __REG32 DATA7OUT           : 1;
  __REG32 DATA8OUT           : 1;
  __REG32 DATA9OUT           : 1;
  __REG32 DATA10OUT          : 1;
  __REG32 DATA11OUT          : 1;
  __REG32 DATA12OUT          : 1;
  __REG32 DATA13OUT          : 1;
  __REG32 DATA14OUT          : 1;
  __REG32 DATA15OUT          : 1;
  __REG32 SYNCOUT            : 1;
  __REG32 CLKOUT             : 1;
  __REG32 ENAOUT             : 1;
  __REG32                    :13;
} __rtppc3_bits;

/* RTP Pin Control 4 Register (RTPPC4) */
typedef struct {
  __REG32 DATA0SET           : 1;
  __REG32 DATA1SET           : 1;
  __REG32 DATA2SET           : 1;
  __REG32 DATA3SET           : 1;
  __REG32 DATA4SET           : 1;
  __REG32 DATA5SET           : 1;
  __REG32 DATA6SET           : 1;
  __REG32 DATA7SET           : 1;
  __REG32 DATA8SET           : 1;
  __REG32 DATA9SET           : 1;
  __REG32 DATA10SET          : 1;
  __REG32 DATA11SET          : 1;
  __REG32 DATA12SET          : 1;
  __REG32 DATA13SET          : 1;
  __REG32 DATA14SET          : 1;
  __REG32 DATA15SET          : 1;
  __REG32 SYNCSET            : 1;
  __REG32 CLKSET             : 1;
  __REG32 ENASET             : 1;
  __REG32                    :13;
} __rtppc4_bits;

/* RTP Pin Control 5 Register (RTPPC5) */
typedef struct {
  __REG32 DATA0CLR           : 1;
  __REG32 DATA1CLR           : 1;
  __REG32 DATA2CLR           : 1;
  __REG32 DATA3CLR           : 1;
  __REG32 DATA4CLR           : 1;
  __REG32 DATA5CLR           : 1;
  __REG32 DATA6CLR           : 1;
  __REG32 DATA7CLR           : 1;
  __REG32 DATA8CLR           : 1;
  __REG32 DATA9CLR           : 1;
  __REG32 DATA10CLR          : 1;
  __REG32 DATA11CLR          : 1;
  __REG32 DATA12CLR          : 1;
  __REG32 DATA13CLR          : 1;
  __REG32 DATA14CLR          : 1;
  __REG32 DATA15CLR          : 1;
  __REG32 SYNCCLR            : 1;
  __REG32 CLKCLR             : 1;
  __REG32 ENACLR             : 1;
  __REG32                    :13;
} __rtppc5_bits;

/* RTP Pin Control 6 Register (RTPPC6) */
typedef struct {
  __REG32 DATA0PDR           : 1;
  __REG32 DATA1PDR           : 1;
  __REG32 DATA2PDR           : 1;
  __REG32 DATA3PDR           : 1;
  __REG32 DATA4PDR           : 1;
  __REG32 DATA5PDR           : 1;
  __REG32 DATA6PDR           : 1;
  __REG32 DATA7PDR           : 1;
  __REG32 DATA8PDR           : 1;
  __REG32 DATA9PDR           : 1;
  __REG32 DATA10PDR          : 1;
  __REG32 DATA11PDR          : 1;
  __REG32 DATA12PDR          : 1;
  __REG32 DATA13PDR          : 1;
  __REG32 DATA14PDR          : 1;
  __REG32 DATA15PDR          : 1;
  __REG32 SYNCPDR            : 1;
  __REG32 CLKPDR             : 1;
  __REG32 ENAPDR             : 1;
  __REG32                    :13;
} __rtppc6_bits;

/* RTP Pin Control 7 Register (RTPPC7) */
typedef struct {
  __REG32 DATA0PDIS          : 1;
  __REG32 DATA1PDIS          : 1;
  __REG32 DATA2PDIS          : 1;
  __REG32 DATA3PDIS          : 1;
  __REG32 DATA4PDIS          : 1;
  __REG32 DATA5PDIS          : 1;
  __REG32 DATA6PDIS          : 1;
  __REG32 DATA7PDIS          : 1;
  __REG32 DATA8PDIS          : 1;
  __REG32 DATA9PDIS          : 1;
  __REG32 DATA10PDIS         : 1;
  __REG32 DATA11PDIS         : 1;
  __REG32 DATA12PDIS         : 1;
  __REG32 DATA13PDIS         : 1;
  __REG32 DATA14PDIS         : 1;
  __REG32 DATA15PDIS         : 1;
  __REG32 SYNCPDIS           : 1;
  __REG32 CLKPDIS            : 1;
  __REG32 ENAPDIS            : 1;
  __REG32                    :13;
} __rtppc7_bits;

/* RTP Pin Control 8 Register (RTPPC8) */
typedef struct {
  __REG32 DATA0PSEL          : 1;
  __REG32 DATA1PSEL          : 1;
  __REG32 DATA2PSEL          : 1;
  __REG32 DATA3PSEL          : 1;
  __REG32 DATA4PSEL          : 1;
  __REG32 DATA5PSEL          : 1;
  __REG32 DATA6PSEL          : 1;
  __REG32 DATA7PSEL          : 1;
  __REG32 DATA8PSEL          : 1;
  __REG32 DATA9PSEL          : 1;
  __REG32 DATA10PSEL         : 1;
  __REG32 DATA11PSEL         : 1;
  __REG32 DATA12PSEL         : 1;
  __REG32 DATA13PSEL         : 1;
  __REG32 DATA14PSEL         : 1;
  __REG32 DATA15PSEL         : 1;
  __REG32 SYNCPSEL           : 1;
  __REG32 CLKPSEL            : 1;
  __REG32 ENAPSEL            : 1;
  __REG32                    :13;
} __rtppc8_bits;

/* I2C Own Address Manager (I2COAR) */
typedef struct {
  __REG16 OA                 :10;
  __REG16                    : 6;
} __i2coar_bits;

/* I2C Interrupt Mask Register (I2CIMR) */
typedef struct {
  __REG16 ALEN               : 1;
  __REG16 NACKEN             : 1;
  __REG16 ARDYEN             : 1;
  __REG16 RXRDYEN            : 1;
  __REG16 TXRDYEN            : 1;
  __REG16 SCDEN              : 1;
  __REG16 AASEN              : 1;
  __REG16                    : 9;
} __i2cimr_bits;

/* I2C Status Register (I2CSTR) */
typedef struct {
  __REG16 AL                 : 1;
  __REG16 NACK               : 1;
  __REG16 ARDY               : 1;
  __REG16 RXRDY              : 1;
  __REG16 TXRDY              : 1;
  __REG16 SCD                : 1;
  __REG16                    : 2;
  __REG16 AD0                : 1;
  __REG16 AAS                : 1;
  __REG16 XSMT               : 1;
  __REG16 RSFULL             : 1;
  __REG16 BB                 : 1;
  __REG16 NACKSNT            : 1;
  __REG16 SDIR               : 1;
  __REG16                    : 1;
} __i2cstr_bits;

/* I2C Data Receive Register (I2CDRR) */
typedef struct {
  __REG16 DATARX             : 8;
  __REG16                    : 8;
} __i2cdrr_bits;

/* I2C Slave Address Register (I2CSAR) */
typedef struct {
  __REG16 SA                 :10;
  __REG16                    : 6;
} __i2csar_bits;

/* I2C Data Transmit Register (I2CDXR) */
typedef struct {
  __REG16 DATATX             : 8;
  __REG16                    : 8;
} __i2cdxr_bits;

/* I2C Mode Register (I2CMDR) */
typedef struct {
  __REG16 BC                 : 3;
  __REG16 FDF                : 1;
  __REG16 STB                : 1;
  __REG16 nIRS               : 1;
  __REG16 DLB                : 1;
  __REG16 RM                 : 1;
  __REG16 XA                 : 1;
  __REG16 TRX                : 1;
  __REG16 MST                : 1;
  __REG16 STP                : 1;
  __REG16                    : 1;
  __REG16 STT                : 1;
  __REG16 FREE               : 1;
  __REG16 NACKMOD            : 1;
} __i2cmdr_bits;

/* I2C Interrupt Vector Register (I2CIVR) */
typedef struct {
  __REG16 INTCODE            : 3;
  __REG16                    : 5;
  __REG16 TESTMD             : 4;
  __REG16                    : 4;
} __i2civr_bits;

/* I2C Extended Mode Register (I2CEMDR) */
typedef struct {
  __REG16 BCM                : 1;
  __REG16 IGNACK             : 1;
  __REG16                    :14;
} __i2cemdr_bits;

/* I2C Prescale Register (I2CPSC) */
typedef struct {
  __REG16 PSC                : 8;
  __REG16                    : 8;
} __i2cpsc_bits;

/* I2C Peripheral ID Register 1 (I2CPID1) */
typedef struct {
  __REG16 REVISION           : 8;
  __REG16 CLASS              : 8;
} __i2cpid1_bits;

/* I2C Peripheral ID Register 2 (I2CPID2) */
typedef struct {
  __REG16 TYPE               : 8;
  __REG16                    : 8;
} __i2cpid2_bits;

/* I2C DMA Control Register (I2CDMACR) */
typedef struct {
  __REG16 RXDMAEN            : 1;
  __REG16 TXDMAEN            : 1;
  __REG16                    :14;
} __i2cdmacr_bits;

/* I2C Pin Function Register (I2CPFNC) */
typedef struct {
  __REG16 PINFUNC            : 1;
  __REG16                    :15;
} __i2cpfnc_bits;

/* I2C Pin Direction Register (I2CPDIR) */
typedef struct {
  __REG16 SCLDIR             : 1;
  __REG16 SDADIR             : 1;
  __REG16                    :14;
} __i2cpdir_bits;

/* I2C Data Input Register (I2CDIN) */
typedef struct {
  __REG16 SCLIN              : 1;
  __REG16 SDAIN              : 1;
  __REG16                    :14;
} __i2cdin_bits;

/* I2C Data Output Register (I2CDOUT) */
typedef struct {
  __REG16 SCLOUT             : 1;
  __REG16 SDAOUT             : 1;
  __REG16                    :14;
} __i2cdout_bits;

/* I2C Data Set Register (I2CDSET) */
typedef struct {
  __REG16 SCLSET             : 1;
  __REG16 SDASET             : 1;
  __REG16                    :14;
} __i2cdset_bits;

/* I2C Data Clear Register (I2CDCLR) */
typedef struct {
  __REG16 SCLCLR             : 1;
  __REG16 SDACLR             : 1;
  __REG16                    :14;
} __i2cdclr_bits;

/* I2C Pin Open Drain Register (I2CPDR) */
typedef struct {
  __REG16 SCLPDR             : 1;
  __REG16 SDAPDR             : 1;
  __REG16                    :14;
} __i2cpdr_bits;

/* I2C Pull Disable Register (I2CPDIS) */
typedef struct {
  __REG16 SCLPDIS            : 1;
  __REG16 SDAPDIS            : 1;
  __REG16                    :14;
} __i2cpdis_bits;

/* I2C Pull Select Register (I2CPSEL) */
typedef struct {
  __REG16 SCLPSEL            : 1;
  __REG16 SDAPSEL            : 1;
  __REG16                    :14;
} __i2cpsel_bits;

/* I2C Pins Slew Rate Select Register (I2CSRS) */
typedef struct {
  __REG16 SCLSRS             : 1;
  __REG16 SDASRS             : 1;
  __REG16                    :14;
} __i2csrs_bits;

/* LOGICPDPWRCTRL0: Logic Power Domain Control Register 0 */
typedef struct {
  __REG32 LOGICPDON3         : 4;
  __REG32                    : 4;
  __REG32 LOGICPDON2         : 4;
  __REG32                    : 4;
  __REG32 LOGICPDON1         : 4;
  __REG32                    : 4;
  __REG32 LOGICPDON0         : 4;
  __REG32                    : 4;
} __logicpdpwrctrl0_bits;

/* MEMPDPWRCTRL0: Memory Power Domain Control Register 0 */
typedef struct {
  __REG32                    : 8;
  __REG32 MEMPDON2           : 4;
  __REG32                    : 4;
  __REG32 MEMPDON1           : 4;
  __REG32                    : 4;
  __REG32 MEMPDON0           : 4;
  __REG32                    : 4;
} __mempdpwrctrl0_bits;

/* PDCLKDISREG: Power Domain Clock Disable Register */
typedef struct {
  __REG32 PDCLK_DIS0         : 1;
  __REG32 PDCLK_DIS1         : 1;
  __REG32 PDCLK_DIS2         : 1;
  __REG32 PDCLK_DIS3         : 1;
  __REG32                    :28;
} __pdclkdis_bits;

/* PDCLKDISSETREG: Power Domain Clock Disable Set Register */
typedef struct {
  __REG32 PDCLK_DISSET0      : 1;
  __REG32 PDCLK_DISSET1      : 1;
  __REG32 PDCLK_DISSET2      : 1;
  __REG32 PDCLK_DISSET3      : 1;
  __REG32                    :28;
} __pdclkdisset_bits;

/* PDCLKDISCLRREG: Power Domain Clock Disable Clear Register */
typedef struct {
  __REG32 PDCLK_DISCLR0      : 1;
  __REG32 PDCLK_DISCLR1      : 1;
  __REG32 PDCLK_DISCLR2      : 1;
  __REG32 PDCLK_DISCLR3      : 1;
  __REG32                    :28;
} __pdclkdisclr_bits;

/* LOGICPDPWRSTAT0: Logic Power Domain PD2 Power Status */
typedef struct {
  __REG32 LOGICPDPWRSTAT0    : 2;
  __REG32                    : 6;
  __REG32 DOMAIN_ON0         : 1;
  __REG32                    : 7;
  __REG32 MEM_IN_TRANS0      : 1;
  __REG32                    : 7;
  __REG32 LOGIC_IN_TRANS0    : 1;
  __REG32                    : 7;
} __logicpdpwrstat0_bits;

/* LOGICPDPWRSTAT1: Logic Power Domain PD3 Power Status */
typedef struct {
  __REG32 LOGICPDPWRSTAT1    : 2;
  __REG32                    : 6;
  __REG32 DOMAIN_ON1         : 1;
  __REG32                    : 7;
  __REG32 MEM_IN_TRANS1      : 1;
  __REG32                    : 7;
  __REG32 LOGIC_IN_TRANS1    : 1;
  __REG32                    : 7;
} __logicpdpwrstat1_bits;

/* LOGICPDPWRSTAT2: Logic Power Domain PD4 Power Status */
typedef struct {
  __REG32 LOGICPDPWRSTAT2    : 2;
  __REG32                    : 6;
  __REG32 DOMAIN_ON2         : 1;
  __REG32                    : 7;
  __REG32 MEM_IN_TRANS2      : 1;
  __REG32                    : 7;
  __REG32 LOGIC_IN_TRANS2    : 1;
  __REG32                    : 7;
} __logicpdpwrstat2_bits;

/* LOGICPDPWRSTAT3: Logic Power Domain PD5 Power Status */
typedef struct {
  __REG32 LOGICPDPWRSTAT3    : 2;
  __REG32                    : 6;
  __REG32 DOMAIN_ON3         : 1;
  __REG32                    : 7;
  __REG32 MEM_IN_TRANS3      : 1;
  __REG32                    : 7;
  __REG32 LOGIC_IN_TRANS3    : 1;
  __REG32                    : 7;
} __logicpdpwrstat3_bits;

/* MEMPDPWRSTAT0: Memory Power Domain RAM_PD1 Power Status */
typedef struct {
  __REG32 MEMPDPWRSTAT0      : 2;
  __REG32                    : 6;
  __REG32 DOMAIN_ON0         : 1;
  __REG32                    : 7;
  __REG32 MEM_IN_TRANS0      : 1;
  __REG32                    : 7;
  __REG32 LOGIC_IN_TRANS0    : 1;
  __REG32                    : 7;
} __mempdpwrstat0_bits;

/* MEMPDPWRSTAT1: Memory Power Domain RAM_PD2 Power Status */
typedef struct {
  __REG32 MEMPDPWRSTAT1      : 2;
  __REG32                    : 6;
  __REG32 DOMAIN_ON1         : 1;
  __REG32                    : 7;
  __REG32 MEM_IN_TRANS1      : 1;
  __REG32                    : 7;
  __REG32 LOGIC_IN_TRANS1    : 1;
  __REG32                    : 7;
} __mempdpwrstat1_bits;

/* MEMPDPWRSTAT2: Memory Power Domain RAM_PD3 Power Status */
typedef struct {
  __REG32 MEMPDPWRSTAT2      : 2;
  __REG32                    : 6;
  __REG32 DOMAIN_ON2         : 1;
  __REG32                    : 7;
  __REG32 MEM_IN_TRANS2      : 1;
  __REG32                    : 7;
  __REG32 LOGIC_IN_TRANS2    : 1;
  __REG32                    : 7;
} __mempdpwrstat2_bits;

/* GLOBALCTRL1: Global Control Register 1 */
typedef struct {
  __REG32 AUTO_CLK_WAKE_ENA  : 1;
  __REG32                    : 7;
  __REG32 PMCTRL_PWRDN       : 1;
  __REG32                    :23;
} __globalctrl1_bits;

/*Global Status Register (GLOBALSTAT) */
typedef struct {
  __REG32 PMCTRL_IDLE        : 1;
  __REG32                    :31;
} __globalstat_bits;

/* PRCKEYREG: PSCON Diagnostic Compare Key Register */
typedef struct {
  __REG32 MKEY               : 4;
  __REG32                    :28;
} __prckeyreg_bits;

/* LPDDCSTAT1: LogicPD PSCON Diagnostic Compare Status Register 1 */
typedef struct {
  __REG32 LSTC0              : 1;
  __REG32 LSTC1              : 1;
  __REG32 LSTC2              : 1;
  __REG32 LSTC3              : 1;
  __REG32                    :12;
  __REG32 LCMPE0             : 1;
  __REG32 LCMPE1             : 1;
  __REG32 LCMPE2             : 1;
  __REG32 LCMPE3             : 1;
  __REG32                    :12;
} __lpddcstat1_bits;

/* LPDDCSTAT2: LogicPD PSCON Diagnostic Compare Status Register 2 */
typedef struct {
  __REG32 LSTE0              : 1;
  __REG32 LSTE1              : 1;
  __REG32 LSTE2              : 1;
  __REG32 LSTE3              : 1;
  __REG32                    :12;
  __REG32 LSTET0             : 1;
  __REG32 LSTET1             : 1;
  __REG32 LSTET2             : 1;
  __REG32 LSTET3             : 1;
  __REG32                    :12;
} __lpddcstat2_bits;

/* MPDDCSTAT1: Memory PD PSCON Diagnostic Compare Status Register 1 */
typedef struct {
  __REG32 MSTC0              : 1;
  __REG32 MSTC1              : 1;
  __REG32 MSTC2              : 1;
  __REG32                    :13;
  __REG32 MCPME0             : 1;
  __REG32 MCPME1             : 1;
  __REG32 MCPME2             : 1;
  __REG32                    :13;
} __mpddcstat1_bits;

/* MPDDCSTAT2: Memory PD PSCON Diagnostic Compare Status Register 2 */
typedef struct {
  __REG32 MSTE0              : 1;
  __REG32 MSTE1              : 1;
  __REG32 MSTE2              : 1;
  __REG32                    :13;
  __REG32 MSTET0             : 1;
  __REG32 MSTET1             : 1;
  __REG32 MSTET2             : 1;
  __REG32                    :13;
} __mpddcstat2_bits;

/* ISODIAGSTAT: Isolation Diagnostic Status */
typedef struct {
  __REG32 ISO_DIAG0          : 1;
  __REG32 ISO_DIAG1          : 1;
  __REG32 ISO_DIAG2          : 1;
  __REG32 ISO_DIAG3          : 1;
  __REG32                    :28;
} __isodiagstat_bits;

/* REVISION_REG: Revision Register */
typedef struct {
  __REG32 REV_MINOR          : 6;
  __REG32 REV_CUSTOM         : 2;
  __REG32 REV_MAJOR          : 3;
  __REG32 REV_RTL            : 5;
  __REG32 REV_MODULE         :12;
  __REG32                    : 2;
  __REG32 REV_SCHEME         : 2;
} __iomm_revision_reg_bits;

/* BOOT_REG: Boot Mode Register */
typedef struct {
  __REG32 ENDIAN             : 1;
  __REG32                    :31;
} __iomm_endian_reg_bits;

/* ERR_RAW_STATUS_REG: Error Raw Status / Set Registe */
typedef struct {
  __REG32 PROT_ERR           : 1;
  __REG32 ADDR_ERR           : 1;
  __REG32                    :30;
} __iomm_err_raw_status_reg_bits;

/* ERR_ENABLED_STATUS_REG: Error Enabled Status / Clear Register */
typedef struct {
  __REG32 ENABLED_PROT_ERR   : 1;
  __REG32 ENABLED_ADDR_ERR   : 1;
  __REG32                    :30;
} __iomm_err_enabled_status_reg_bits;

/* ERR_ENABLE_REG: Error Signaling Enable Register */
typedef struct {
  __REG32 PROT_ERR_EN        : 1;
  __REG32 ADDR_ERR_EN        : 1;
  __REG32                    :30;
} __iomm_err_enable_reg_bits;

/* ERR_ENABLE_CLR_REG: Error Signaling Enable Clear Register */
typedef struct {
  __REG32 PROT_ERR_EN_CLR    : 1;
  __REG32 ADDR_ERR_EN_CLR    : 1;
  __REG32                    :30;
} __iomm_err_enable_clr_reg_bits;

/* FAULT_STATUS_REG: Fault Status Register */
typedef struct {
  __REG32 FAULT_TYPE         : 6;
  __REG32                    : 3;
  __REG32 FAULT_PRIVID       : 4;
  __REG32                    : 3;
  __REG32 FAULT_MSTID        : 8;
  __REG32 FAULT_ID           : 4;
  __REG32                    : 4;
} __iomm_fault_status_reg_bits;

/* FAULT_CLEAR_REG: Fault Clear Register */
typedef struct {
  __REG32 FAULT_CLEAR        : 1;
  __REG32                    :31;
} __iomm_fault_clear_reg_bits;

/* PINMMRxx: Pin Multiplexing Control Registers */
typedef struct {
  __REG32 PINMMR0            : 1;
  __REG32 PINMMR1            : 1;
  __REG32 PINMMR2            : 1;
  __REG32 PINMMR3            : 1;
  __REG32 PINMMR4            : 1;
  __REG32 PINMMR5            : 1;
  __REG32 PINMMR6            : 1;
  __REG32 PINMMR7            : 1;
  __REG32 PINMMR8            : 1;
  __REG32 PINMMR9            : 1;
  __REG32 PINMMR10           : 1;
  __REG32 PINMMR11           : 1;
  __REG32 PINMMR12           : 1;
  __REG32 PINMMR13           : 1;
  __REG32 PINMMR14           : 1;
  __REG32 PINMMR15           : 1;
  __REG32 PINMMR16           : 1;
  __REG32 PINMMR17           : 1;
  __REG32 PINMMR18           : 1;
  __REG32 PINMMR19           : 1;
  __REG32 PINMMR20           : 1;
  __REG32 PINMMR21           : 1;
  __REG32 PINMMR22           : 1;
  __REG32 PINMMR23           : 1;
  __REG32 PINMMR24           : 1;
  __REG32 PINMMR25           : 1;
  __REG32 PINMMR26           : 1;
  __REG32 PINMMR27           : 1;
  __REG32 PINMMR28           : 1;
  __REG32 PINMMR29           : 1;
  __REG32 PINMMR30           : 1;
  __REG32 PINMMR31           : 1;
} __iomm_pinmmr_bits;

/* EMAC Control Module Software Reset Register (SOFTRESET) */
typedef struct {
  __REG32 RESET                   : 1;
  __REG32                         :31;
} __emac_softreset_bits;

/* EMAC Control Module Interrupt Control Register (INTCONTROL) */
typedef struct {
  __REG32 INTPRESCALE             :12;
  __REG32                         : 4;
  __REG32 C0RXPACEEN              : 1;
  __REG32 C0TXPACEEN              : 1;
  __REG32                         :14;
} __emac_intcontrol_bits;

/* EMAC Control Module Receive Threshold Interrupt Enable Registers (C0RXTHRESHEN)*/
typedef struct {
  __REG32 RXCH0THRESHEN           : 1;
  __REG32 RXCH1THRESHEN           : 1;
  __REG32 RXCH2THRESHEN           : 1;
  __REG32 RXCH3THRESHEN           : 1;
  __REG32 RXCH4THRESHEN           : 1;
  __REG32 RXCH5THRESHEN           : 1;
  __REG32 RXCH6THRESHEN           : 1;
  __REG32 RXCH7THRESHEN           : 1;
  __REG32                         :24;
} __emac_crxthreshen_bits;

/* EMAC Control Module Receive Interrupt Enable Register (C0RXEN) */
typedef struct {
  __REG32 RXCH0EN                 : 1;
  __REG32 RXCH1EN                 : 1;
  __REG32 RXCH2EN                 : 1;
  __REG32 RXCH3EN                 : 1;
  __REG32 RXCH4EN                 : 1;
  __REG32 RXCH5EN                 : 1;
  __REG32 RXCH6EN                 : 1;
  __REG32 RXCH7EN                 : 1;
  __REG32                         :24;
} __emac_crxen_bits;

/* EMAC Control Module Transmit Interrupt Enable Registers (C0TXEN) */
typedef struct {
  __REG32 TXCH0EN                 : 1;
  __REG32 TXCH1EN                 : 1;
  __REG32 TXCH2EN                 : 1;
  __REG32 TXCH3EN                 : 1;
  __REG32 TXCH4EN                 : 1;
  __REG32 TXCH5EN                 : 1;
  __REG32 TXCH6EN                 : 1;
  __REG32 TXCH7EN                 : 1;
  __REG32                         :24;
} __emac_ctxen_bits;

/* EMAC Control Module Miscellaneous Interrupt Enable Registers (C0MISCEN) */
typedef struct {
  __REG32 USERINT0EN              : 1;
  __REG32 LINKINT0EN              : 1;
  __REG32 HOSTPENDEN              : 1;
  __REG32 STATPENDEN              : 1;
  __REG32                         :28;
} __emac_cmiscen_bits;

/* EMAC Control Module Receive Threshold Interrupt Status Registers (C0RXTHRESHSTAT) */
typedef struct {
  __REG32 RXCH0THRESHSTAT         : 1;
  __REG32 RXCH1THRESHSTAT         : 1;
  __REG32 RXCH2THRESHSTAT         : 1;
  __REG32 RXCH3THRESHSTAT         : 1;
  __REG32 RXCH4THRESHSTAT         : 1;
  __REG32 RXCH5THRESHSTAT         : 1;
  __REG32 RXCH6THRESHSTAT         : 1;
  __REG32 RXCH7THRESHSTAT         : 1;
  __REG32                         :24;
} __emac_crxthreshstat_bits;

/* EMAC Control Module Receive Interrupt Status Registers (C0RXSTAT) */
typedef struct {
  __REG32 RXCH0STAT               : 1;
  __REG32 RXCH1STAT               : 1;
  __REG32 RXCH2STAT               : 1;
  __REG32 RXCH3STAT               : 1;
  __REG32 RXCH4STAT               : 1;
  __REG32 RXCH5STAT               : 1;
  __REG32 RXCH6STAT               : 1;
  __REG32 RXCH7STAT               : 1;
  __REG32                         :24;
} __emac_crxstat_bits;

/* EMAC Control Module Transmit Interrupt Status Registers (C0TXSTAT) */
typedef struct {
  __REG32 TXCH0STAT               : 1;
  __REG32 TXCH1STAT               : 1;
  __REG32 TXCH2STAT               : 1;
  __REG32 TXCH3STAT               : 1;
  __REG32 TXCH4STAT               : 1;
  __REG32 TXCH5STAT               : 1;
  __REG32 TXCH6STAT               : 1;
  __REG32 TXCH7STAT               : 1;
  __REG32                         :24;
} __emac_ctxstat_bits;

/* EMAC Control Module Miscellaneous Interrupt Status Registers (C0MISCSTAT) */
typedef struct {
  __REG32 USERINT0STAT            : 1;
  __REG32 LINKINT0STAT            : 1;
  __REG32 HOSTPENDSTAT            : 1;
  __REG32 STATPENDSTAT            : 1;
  __REG32                         :28;
} __emac_cmiscstat_bits;

/* EMAC Control Module Receive Interrupts Per Millisecond Registers (C0RXIMAX) */
typedef struct {
  __REG32 RXIMAX                  : 6;
  __REG32                         :26;
} __emac_crximax_bits;

/* EMAC Control Module Transmit Interrupts Per Millisecond Register (C0TXIMAX) */
typedef struct {
  __REG32 TXIMAX                  : 6;
  __REG32                         :26;
} __emac_ctximax_bits;

/* EMAC MDIO Control Register (CONTROL) */
typedef struct {
  __REG32 CLKDIV                  :16;
  __REG32                         : 2;
  __REG32 FAULTENB                : 1;
  __REG32 FAULT                   : 1;
  __REG32 PREAMBLE                : 1;
  __REG32                         : 3;
  __REG32 HIGHEST_USER_CHANNEL    : 5;
  __REG32                         : 1;
  __REG32 ENABLE                  : 1;
  __REG32 IDLE                    : 1;
} __mdio_control_bits;

/* EMAC MDIO PHY Acknowledge Status Register (ALIVE)*/
typedef struct {
  __REG32 ALIVE0                  : 1;
  __REG32 ALIVE1                  : 1;
  __REG32 ALIVE2                  : 1;
  __REG32 ALIVE3                  : 1;
  __REG32 ALIVE4                  : 1;
  __REG32 ALIVE5                  : 1;
  __REG32 ALIVE6                  : 1;
  __REG32 ALIVE7                  : 1;
  __REG32 ALIVE8                  : 1;
  __REG32 ALIVE9                  : 1;
  __REG32 ALIVE10                 : 1;
  __REG32 ALIVE11                 : 1;
  __REG32 ALIVE12                 : 1;
  __REG32 ALIVE13                 : 1;
  __REG32 ALIVE14                 : 1;
  __REG32 ALIVE15                 : 1;
  __REG32 ALIVE16                 : 1;
  __REG32 ALIVE17                 : 1;
  __REG32 ALIVE18                 : 1;
  __REG32 ALIVE19                 : 1;
  __REG32 ALIVE20                 : 1;
  __REG32 ALIVE21                 : 1;
  __REG32 ALIVE22                 : 1;
  __REG32 ALIVE23                 : 1;
  __REG32 ALIVE24                 : 1;
  __REG32 ALIVE25                 : 1;
  __REG32 ALIVE26                 : 1;
  __REG32 ALIVE27                 : 1;
  __REG32 ALIVE28                 : 1;
  __REG32 ALIVE29                 : 1;
  __REG32 ALIVE30                 : 1;
  __REG32 ALIVE31                 : 1;
} __mdio_alive_bits;

/* EMAC PHY Link Status Register (LINK) */
typedef struct {
  __REG32 LINKE0                  : 1;
  __REG32 LINKE1                  : 1;
  __REG32 LINKE2                  : 1;
  __REG32 LINKE3                  : 1;
  __REG32 LINKE4                  : 1;
  __REG32 LINKE5                  : 1;
  __REG32 LINKE6                  : 1;
  __REG32 LINKE7                  : 1;
  __REG32 LINKE8                  : 1;
  __REG32 LINKE9                  : 1;
  __REG32 LINKE10                 : 1;
  __REG32 LINKE11                 : 1;
  __REG32 LINKE12                 : 1;
  __REG32 LINKE13                 : 1;
  __REG32 LINKE14                 : 1;
  __REG32 LINKE15                 : 1;
  __REG32 LINKE16                 : 1;
  __REG32 LINKE17                 : 1;
  __REG32 LINKE18                 : 1;
  __REG32 LINKE19                 : 1;
  __REG32 LINKE20                 : 1;
  __REG32 LINKE21                 : 1;
  __REG32 LINKE22                 : 1;
  __REG32 LINKE23                 : 1;
  __REG32 LINKE24                 : 1;
  __REG32 LINKE25                 : 1;
  __REG32 LINKE26                 : 1;
  __REG32 LINKE27                 : 1;
  __REG32 LINKE28                 : 1;
  __REG32 LINKE29                 : 1;
  __REG32 LINKE30                 : 1;
  __REG32 LINKE31                 : 1;
} __mdio_link_bits;

/* EMAC MDIO Link Status Change Interrupt (Unmasked) Register (LINKINTRAW) */
/* EMAC MDIO Link Status Change Interrupt (Masked) Register (LINKINTMASKED) */
typedef struct {
  __REG32 USERPHY0                : 1;
  __REG32 USERPHY1                : 1;
  __REG32                         :30;
} __mdio_linkintraw_bits;

/* EMAC MDIO User Command Complete Interrupt (Unmasked) Register (USERINTRAW) */
/* EMAC MDIO User Command Complete Interrupt (Masked) Register (USERINTMASKED) */
/* EMAC MDIO User Command Complete Interrupt Mask Set Register (USERINTMASKSET) */
/* EMAC MDIO User Command Complete Interrupt Mask Clear Register (USERINTMASKCLEAR) */
typedef struct {
  __REG32 USERACCESS0             : 1;
  __REG32 USERACCESS1             : 1;
  __REG32                         :30;
} __mdio_userintraw_bits;

/* EMAC MDIO User Access Register 0/1 (USERACCESS0/1) */
typedef struct {
  __REG32 DATA                    :16;
  __REG32 PHYADR                  : 5;
  __REG32 REGADR                  : 5;
  __REG32                         : 3;
  __REG32 ACK                     : 1;
  __REG32 WRITE                   : 1;
  __REG32 GO                      : 1;
} __mdio_useraccess_bits;

/* EMAC MDIO User PHY Select Register 0/1 (USERPHYSEL0/1) */
typedef struct {
  __REG32 PHYADRMON               : 5;
  __REG32                         : 1;
  __REG32 LINKINTENB              : 1;
  __REG32 LINKSEL                 : 1;
  __REG32                         :24;
} __mdio_userphysel_bits;

/* EMAC Transmit Control Register (TXCONTROL) */
typedef struct {
  __REG32 TXEN                    : 1;
  __REG32                         :31;
} __emac_txcontrol_bits;

/* EMAC Transmit Teardown Register (TXTEARDOWN) */
typedef struct {
  __REG32 TXTDNCH                 : 3;
  __REG32                         :29;
} __emac_txteardown_bits;

/* EMAC Receive Control Register (RXCONTROL) */
typedef struct {
  __REG32 RXEN                    : 1;
  __REG32                         :31;
} __emac_rxcontrol_bits;

/* EMAC Receive Teardown Register (RXTEARDOWN) */
typedef struct {
  __REG32 RXTDNCH                 : 3;
  __REG32                         :29;
} __emac_rxteardown_bits;

/* EMAC Transmit Interrupt Status (Unmasked) Register (TXINTSTATRAW) */
/* EMAC Transmit Interrupt Status (Masked) Register (TXINTSTATMASKED) */
typedef struct {
  __REG32 TX0PEND                 : 1;
  __REG32 TX1PEND                 : 1;
  __REG32 TX2PEND                 : 1;
  __REG32 TX3PEND                 : 1;
  __REG32 TX4PEND                 : 1;
  __REG32 TX5PEND                 : 1;
  __REG32 TX6PEND                 : 1;
  __REG32 TX7PEND                 : 1;
  __REG32                         :24;
} __emac_txintstatraw_bits;

/* EMAC Transmit Interrupt Mask Set Register (TXINTMASKSET) */
/* EMAC Transmit Interrupt Mask Clear Register (TXINTMASKCLEAR) */
typedef struct {
  __REG32 TX0MASK                 : 1;
  __REG32 TX1MASK                 : 1;
  __REG32 TX2MASK                 : 1;
  __REG32 TX3MASK                 : 1;
  __REG32 TX4MASK                 : 1;
  __REG32 TX5MASK                 : 1;
  __REG32 TX6MASK                 : 1;
  __REG32 TX7MASK                 : 1;
  __REG32                         :24;
} __emac_txintmaskset_bits;

/* EMAC MAC Input Vector Register (MACINVECTOR) */
typedef struct {
  __REG32 RXPEND                  : 8;
  __REG32 RXTHRESHPEND            : 8;
  __REG32 TXPEND                  : 8;
  __REG32 USERINT0                : 1;
  __REG32 LINKINT0                : 1;
  __REG32 HOSTPEND                : 1;
  __REG32 STATPEND                : 1;
  __REG32                         : 4;
} __emac_macinvector_bits;

/* EMAC MAC End Of Interrupt Vector Register (MACEOIVECTOR) */
typedef struct {
  __REG32 INTVECT                 : 5;
  __REG32                         :27;
} __emac_maceoivector_bits;

/* EMAC Receive Interrupt Status (Unmasked) Register (RXINTSTATRAW) */
/* EMAC Receive Interrupt Status (Masked) Register (RXINTSTATMASKED) */
typedef struct {
  __REG32 RX0PEND                 : 1;
  __REG32 RX1PEND                 : 1;
  __REG32 RX2PEND                 : 1;
  __REG32 RX3PEND                 : 1;
  __REG32 RX4PEND                 : 1;
  __REG32 RX5PEND                 : 1;
  __REG32 RX6PEND                 : 1;
  __REG32 RX7PEND                 : 1;
  __REG32 RX0THRESHPEND           : 1;
  __REG32 RX1THRESHPEND           : 1;
  __REG32 RX2THRESHPEND           : 1;
  __REG32 RX3THRESHPEND           : 1;
  __REG32 RX4THRESHPEND           : 1;
  __REG32 RX5THRESHPEND           : 1;
  __REG32 RX6THRESHPEND           : 1;
  __REG32 RX7THRESHPEND           : 1;
  __REG32                         :16;
} __emac_rxintstatraw_bits;

/* EMAC Receive Interrupt Mask Set Register (RXINTMASKSET) */
/* EMAC Receive Interrupt Mask Clear Register (RXINTMASKCLEAR) */
typedef struct {
  __REG32 RX0MASK                 : 1;
  __REG32 RX1MASK                 : 1;
  __REG32 RX2MASK                 : 1;
  __REG32 RX3MASK                 : 1;
  __REG32 RX4MASK                 : 1;
  __REG32 RX5MASK                 : 1;
  __REG32 RX6MASK                 : 1;
  __REG32 RX7MASK                 : 1;
  __REG32 RX0THRESHMASK           : 1;
  __REG32 RX1THRESHMASK           : 1;
  __REG32 RX2THRESHMASK           : 1;
  __REG32 RX3THRESHMASK           : 1;
  __REG32 RX4THRESHMASK           : 1;
  __REG32 RX5THRESHMASK           : 1;
  __REG32 RX6THRESHMASK           : 1;
  __REG32 RX7THRESHMASK           : 1;
  __REG32                         :16;
} __emac_rxintmaskset_bits;

/* EMAC MAC Interrupt Status (Unmasked) Register (MACINTSTATRAW) */
/* EMAC MAC Interrupt Status (Masked) Register (MACINTSTATMASKED) */
typedef struct {
  __REG32 STATPEND                : 1;
  __REG32 HOSTPEND                : 1;
  __REG32                         :30;
} __emac_macintstatraw_bits;

/* EMAC MAC Interrupt Mask Set Register (MACINTMASKSET) */
/* EMAC MAC Interrupt Mask Clear Register (MACINTMASKCLEAR) */
typedef struct {
  __REG32 STATMASK                : 1;
  __REG32 HOSTMASK                : 1;
  __REG32                         :30;
} __emac_macintmaskset_bits;

/* EMAC Receive Multicast/Broadcast/Promiscuous Channel Enable Register (RXMBPENABLE) */
typedef struct {
  __REG32 RXMULTCH                : 3;
  __REG32                         : 2;
  __REG32 RXMULTEN                : 1;
  __REG32                         : 2;
  __REG32 RXBROADCH               : 3;
  __REG32                         : 2;
  __REG32 RXBROADEN               : 1;
  __REG32                         : 2;
  __REG32 RXPROMCH                : 3;
  __REG32                         : 2;
  __REG32 RXCAFEN                 : 1;
  __REG32 RXCEFEN                 : 1;
  __REG32 RXCSFEN                 : 1;
  __REG32 RXCMFEN                 : 1;
  __REG32                         : 3;
  __REG32 RXNOCHAIN               : 1;
  __REG32 RXQOSEN                 : 1;
  __REG32 RXPASSCRC               : 1;
  __REG32                         : 1;
} __emac_rxmbpenable_bits;

/* EMAC Receive Unicast Enable Set Register (RXUNICASTSET) */
/* EMAC Receive Unicast Clear Register (RXUNICASTCLEAR) */
typedef struct {
  __REG32 RXCH0EN                 : 1;
  __REG32 RXCH1EN                 : 1;
  __REG32 RXCH2EN                 : 1;
  __REG32 RXCH3EN                 : 1;
  __REG32 RXCH4EN                 : 1;
  __REG32 RXCH5EN                 : 1;
  __REG32 RXCH6EN                 : 1;
  __REG32 RXCH7EN                 : 1;
  __REG32                         :24;
} __emac_rxunicastset_bits;

/* EMAC Receive Maximum Length Register (RXMAXLEN) */
typedef struct {
  __REG32 RXMAXLEN                :16;
  __REG32                         :16;
} __emac_rxmaxlen_bits;

/* EMAC Receive Buffer Offset Register (RXBUFFEROFFSET) */
typedef struct {
  __REG32 RXBUFFEROFFSET          :16;
  __REG32                         :16;
} __emac_rxbufferoffset_bits;

/* EMAC Receive Filter Low Priority Frame Threshold Register (RXFILTERLOWTHRESH) */
typedef struct {
  __REG32 RXFILTERTHRESH          : 8;
  __REG32                         :24;
} __emac_rxfilterlowthresh_bits;

/* EMAC Receive Channel Flow Control Threshold Registers (RX0FLOWTHRESH-RX7FLOWTHRESH) */
typedef struct {
  __REG32 RXFLOWTHRESH            : 8;
  __REG32                         :24;
} __emac_rxflowthresh_bits;

/* EMAC Receive Channel Free Buffer Count Registers (RX0FREEBUFFER-RX7FREEBUFFER) */
typedef struct {
  __REG32 RXFREEBUF               :16;
  __REG32                         :16;
} __emac_rxfreebuffer_bits;

/* EMAC MAC Control Register (MACCONTROL) */
typedef struct {
  __REG32 FULLDUPLEX              : 1;
  __REG32 LOOPBACK                : 1;
  __REG32                         : 1;
  __REG32 RXBUFFERFLOWEN          : 1;
  __REG32 TXFLOWEN                : 1;
  __REG32 GMIIEN                  : 1;
  __REG32 TXPACE                  : 1;
  __REG32                         : 2;
  __REG32 TXPTYPE                 : 1;
  __REG32 TXSHORTGAPEN            : 1;
  __REG32 CMDIDLE                 : 1;
  __REG32                         : 1;
  __REG32 RXOWNERSHIP             : 1;
  __REG32 RXOFFLENBLOCK           : 1;
  __REG32 RMIISPEED               : 1;
  __REG32                         :16;
} __emac_maccontrol_bits;

/* EMAC MAC Status Register (MACSTATUS) */
typedef struct {
  __REG32 TXFLOWACT               : 1;
  __REG32 RXFLOWACT               : 1;
  __REG32 RXQOSACT                : 1;
  __REG32                         : 5;
  __REG32 RXERRCH                 : 3;
  __REG32                         : 1;
  __REG32 RXERRCODE               : 4;
  __REG32 TXERRCH                 : 3;
  __REG32                         : 1;
  __REG32 TXERRCODE               : 4;
  __REG32                         : 7;
  __REG32 IDLE                    : 1;
} __emac_macstatus_bits;

/* EMAC Emulation Control Register (EMCONTROL) */
typedef struct {
  __REG32 FREE                    : 1;
  __REG32 SOFT                    : 1;
  __REG32                         :30;
} __emac_emcontrol_bits;

/* EMAC FIFO Control Register (FIFOCONTROL) */
typedef struct {
  __REG32 TXCELLTHRESH            : 2;
  __REG32                         :30;
} __emac_fifocontrol_bits;

/* EMAC MAC Configuration Register (MACCONFIG) */
typedef struct {
  __REG32 MACCFIG                 : 8;
  __REG32 ADDRESSTYPE             : 8;
  __REG32 RXCELLDEPTH             : 8;
  __REG32 TXCELLDEPTH             : 8;
} __emac_macconfig_bits;

/* EMAC MAC Source Address Low Bytes Register (MACSRCADDRLO) */
typedef struct {
  __REG32 MACSRCADDR1             : 8;
  __REG32 MACSRCADDR0             : 8;
  __REG32                         :16;
} __emac_macsrcaddrlo_bits;

/* EMAC MAC Source Address High Bytes Register (MACSRCADDRHI) */
typedef struct {
  __REG32 MACSRCADDR5             : 8;
  __REG32 MACSRCADDR4             : 8;
  __REG32 MACSRCADDR3             : 8;
  __REG32 MACSRCADDR2             : 8;
} __emac_macsrcaddrhi_bits;

/* EMAC Back Off Test Register (BOFFTEST) */
typedef struct {
  __REG32 TXBACKOFF               :10;
  __REG32                         : 2;
  __REG32 COLLCOUNT               : 4;
  __REG32 RNDNUM                  :10;
  __REG32                         : 6;
} __emac_bofftest_bits;

/* EMAC Transmit Pacing Algorithm Test Register (TPACETEST) */
typedef struct {
  __REG32 PACEVAL                 : 5;
  __REG32                         :27;
} __emac_tpacetest_bits;

/* EMAC Receive Pause Timer Register (RXPAUSE) */
/* EMAC Transmit Pause Timer Register (TXPAUSE) */
typedef struct {
  __REG32 PAUSETIMER              :16;
  __REG32                         :16;
} __emac_rxpause_bits;

/* EMAC MAC Address Low Bytes Register (MACADDRLO) */
typedef struct {
  __REG32 MACADDR1                : 8;
  __REG32 MACADDR0                : 8;
  __REG32 CHANNEL                 : 3;
  __REG32 MATCHFILT               : 1;
  __REG32 VALID                   : 1;
  __REG32                         :11;
} __emac_macaddrlo_bits;

/* EMAC MAC Address High Bytes Register (MACADDRHI) */
typedef struct {
  __REG32 MACADDR5                : 8;
  __REG32 MACADDR4                : 8;
  __REG32 MACADDR3                : 8;
  __REG32 MACADDR2                : 8;
} __emac_macaddrhi_bits;

/* EMAC MAC Index Register (MACINDEX) */
typedef struct {
  __REG32 MACINDEX                : 3;
  __REG32                         :29;
} __emac_macindex_bits;

/* DCC Global Control Register (DCCGCTRL) */
typedef struct {
  __REG32 DCC_ENA                 : 4;
  __REG32 ERR_ENA                 : 4;
  __REG32 SINGLE_SHOT             : 4;
  __REG32 DONE_INT_ENA            : 4;
  __REG32                         :16;
} __dccgctrl_bits;

/* DCC Global Control Register (DCCGCTRL) */
typedef struct {
  __REG32 MINOR                   : 6;
  __REG32 CUSTOM                  : 2;
  __REG32 MAJOR                   : 3;
  __REG32 RTL                     : 5;
  __REG32 FUNC                    :12;
  __REG32                         : 2;
  __REG32 SCHEME                  : 2;
} __dccrev_bits;

/* DCC Counter0 Seed Register (DCCCNT0SEED) */
typedef struct {
  __REG32 COUNT0_SEED             :20;
  __REG32                         :12;
} __dcccnt0seed_bits;

/* DCC Valid0 Seed Register (DCCVALID0SEED) */
typedef struct {
  __REG32 VALID0_SEED             :16;
  __REG32                         :16;
} __dccvalid0seed_bits;

/* DCC Counter1 Seed Register (DCCCNT1SEED) */
typedef struct {
  __REG32 COUNT1_SEED             :20;
  __REG32                         :12;
} __dcccnt1seed_bits;

/* DCC Status Register (DCCSTAT) */
typedef struct {
  __REG32 ERR                     : 1;
  __REG32 DONE                    : 1;
  __REG32                         :30;
} __dccstat_bits;

/* DCC Counter0 Value Register (DCCCNT0) */
typedef struct {
  __REG32 COUNT0                  :20;
  __REG32                         :12;
} __dcccnt0_bits;

/* DCC Valid0 Value Register (DCCVALID0) */
typedef struct {
  __REG32 VALID0                  :16;
  __REG32                         :16;
} __dccvalid0_bits;

/* DCC Counter1 Value Register (DCCCNT1) */
typedef struct {
  __REG32 COUNT1                  :20;
  __REG32                         :12;
} __dcccnt1_bits;

/* DCC Counter1 Clock Source Selection Register (DCCCNT1CLKSRC) */
typedef struct {
  __REG32 CNT1_CLKSRC             : 4;
  __REG32                         : 8;
  __REG32 KEY                     : 4;
  __REG32                         :16;
} __dcccnt1clksrc_bits;

/* DCC Counter0 Clock Source Selection Register (DCCCNT0CLKSRC) */
typedef struct {
  __REG32 CNT0_CLKSRC             : 4;
  __REG32                         :28;
} __dcccnt0clksrc_bits;

/* EFC Boundary Control Register (EFCBOUND) */
typedef struct {
  __REG32 INPUT_ENABLE            : 4;
  __REG32                         : 9;
  __REG32 EFC_ECC_SELFTEST_ENABLE : 1;
  __REG32 AUTOLOAD_ERROR_OE       : 1;
  __REG32 INSTRUCTION_ERROR_OE    : 1;
  __REG32 SINGLE_BIT_ERROR_OE     : 1;
  __REG32 SELF_TEST_ERROR_OE      : 1;
  __REG32 EFC_AUTOLOAD_ERROR      : 1;
  __REG32 EFC_INSTRUCTION_ERROR   : 1;
  __REG32 EFC_SINGLE_BIT_ERROR    : 1;
  __REG32 EFC_SELF_TEST_ERROR     : 1;
  __REG32                         :10;
} __efcbound_bits;

/* EFC Pins Register (EFCPINS) */
typedef struct {
  __REG32                         :10;
  __REG32 EFC_AUTOLOAD_ERROR      : 1;
  __REG32 EFC_INSTRUCTION_ERROR   : 1;
  __REG32 EFC_SINGLE_BIT_ERROR    : 1;
  __REG32                         : 1;
  __REG32 EFC_SELFTEST_ERROR      : 1;
  __REG32 EFC_SELFTEST_DONE       : 1;
  __REG32                         :16;
} __efcpins_bits;

/* EFC Error Status Register (EFCERRSTAT) */
typedef struct {
  __REG32 ERROR_CODE              : 5;
  __REG32 INSTRUC_DONE            : 1;
  __REG32                         :26;
} __efcerrstat_bits;

#endif    /* __IAR_SYSTEMS_ICC__ */

/* Declarations common to compiler and assembler *********************************/

/***************************************************************************
 **
 ** VIM (Vectored Interrupt Manager)
 **
 ***************************************************************************/
__IO_REG32_BIT(IRQINDEX,          0xFFFFFE00,__READ       ,__irqindex_bits);
__IO_REG32_BIT(FIQINDEX,          0xFFFFFE04,__READ       ,__fiqindex_bits);
__IO_REG32_BIT(FIRQPR0,           0xFFFFFE10,__READ_WRITE ,__firqpr0_bits);
__IO_REG32_BIT(FIRQPR1,           0xFFFFFE14,__READ_WRITE ,__firqpr1_bits);
__IO_REG32_BIT(FIRQPR2,           0xFFFFFE18,__READ_WRITE ,__firqpr2_bits);
__IO_REG32_BIT(INTREQ0,           0xFFFFFE20,__READ       ,__intreq0_bits);
__IO_REG32_BIT(INTREQ1,           0xFFFFFE24,__READ       ,__intreq1_bits);
__IO_REG32_BIT(INTREQ2,           0xFFFFFE28,__READ       ,__intreq2_bits);
__IO_REG32_BIT(REQENASET0,        0xFFFFFE30,__READ_WRITE ,__reqenaset0_bits);
__IO_REG32_BIT(REQENASET1,        0xFFFFFE34,__READ_WRITE ,__reqenaset1_bits);
__IO_REG32_BIT(REQENASET2,        0xFFFFFE38,__READ_WRITE ,__reqenaset2_bits);
__IO_REG32_BIT(REQENACLR0,        0xFFFFFE40,__READ_WRITE ,__reqenaclr0_bits);
__IO_REG32_BIT(REQENACLR1,        0xFFFFFE44,__READ_WRITE ,__reqenaclr1_bits);
__IO_REG32_BIT(REQENACLR2,        0xFFFFFE48,__READ_WRITE ,__reqenaclr2_bits);
__IO_REG32_BIT(WAKEENASET0,       0xFFFFFE50,__READ_WRITE ,__wakeenaset0_bits);
__IO_REG32_BIT(WAKEENASET1,       0xFFFFFE54,__READ_WRITE ,__wakeenaset1_bits);
__IO_REG32_BIT(WAKEENASET2,       0xFFFFFE58,__READ_WRITE ,__wakeenaset2_bits);
__IO_REG32_BIT(WAKEENACLR0,       0xFFFFFE60,__READ_WRITE ,__wakeenaclr0_bits);
__IO_REG32_BIT(WAKEENACLR1,       0xFFFFFE64,__READ_WRITE ,__wakeenaclr1_bits);
__IO_REG32_BIT(WAKEENACLR2,       0xFFFFFE68,__READ_WRITE ,__wakeenaclr2_bits);
__IO_REG32(    IRQVECREG,         0xFFFFFE70,__READ       );
__IO_REG32(    FIQVECREG,         0xFFFFFE74,__READ       );
__IO_REG32_BIT(CAPEVT,            0xFFFFFE78,__READ_WRITE ,__capevt_bits);
__IO_REG32_BIT(CHANCTRL0,         0xFFFFFE80,__READ_WRITE ,__chanctrl0_bits);
__IO_REG32_BIT(CHANCTRL1,         0xFFFFFE84,__READ_WRITE ,__chanctrl1_bits);
__IO_REG32_BIT(CHANCTRL2,         0xFFFFFE88,__READ_WRITE ,__chanctrl2_bits);
__IO_REG32_BIT(CHANCTRL3,         0xFFFFFE8C,__READ_WRITE ,__chanctrl3_bits);
__IO_REG32_BIT(CHANCTRL4,         0xFFFFFE90,__READ_WRITE ,__chanctrl4_bits);
__IO_REG32_BIT(CHANCTRL5,         0xFFFFFE94,__READ_WRITE ,__chanctrl5_bits);
__IO_REG32_BIT(CHANCTRL6,         0xFFFFFE98,__READ_WRITE ,__chanctrl6_bits);
__IO_REG32_BIT(CHANCTRL7,         0xFFFFFE9C,__READ_WRITE ,__chanctrl7_bits);
__IO_REG32_BIT(CHANCTRL8,         0xFFFFFEA0,__READ_WRITE ,__chanctrl8_bits);
__IO_REG32_BIT(CHANCTRL9,         0xFFFFFEA4,__READ_WRITE ,__chanctrl9_bits);
__IO_REG32_BIT(CHANCTRL10,        0xFFFFFEA8,__READ_WRITE ,__chanctrl10_bits);
__IO_REG32_BIT(CHANCTRL11,        0xFFFFFEAC,__READ_WRITE ,__chanctrl11_bits);
__IO_REG32_BIT(CHANCTRL12,        0xFFFFFEB0,__READ_WRITE ,__chanctrl12_bits);
__IO_REG32_BIT(CHANCTRL13,        0xFFFFFEB4,__READ_WRITE ,__chanctrl13_bits);
__IO_REG32_BIT(CHANCTRL14,        0xFFFFFEB8,__READ_WRITE ,__chanctrl14_bits);
__IO_REG32_BIT(CHANCTRL15,        0xFFFFFEBC,__READ_WRITE ,__chanctrl15_bits);
__IO_REG32_BIT(CHANCTRL16,        0xFFFFFEC0,__READ_WRITE ,__chanctrl16_bits);
__IO_REG32_BIT(CHANCTRL17,        0xFFFFFEC4,__READ_WRITE ,__chanctrl17_bits);
__IO_REG32_BIT(CHANCTRL18,        0xFFFFFEC8,__READ_WRITE ,__chanctrl18_bits);
__IO_REG32_BIT(CHANCTRL19,        0xFFFFFECC,__READ_WRITE ,__chanctrl19_bits);
__IO_REG32_BIT(CHANCTRL20,        0xFFFFFED0,__READ_WRITE ,__chanctrl20_bits);
__IO_REG32_BIT(CHANCTRL21,        0xFFFFFED4,__READ_WRITE ,__chanctrl21_bits);
__IO_REG32_BIT(CHANCTRL22,        0xFFFFFED8,__READ_WRITE ,__chanctrl22_bits);
__IO_REG32_BIT(CHANCTRL23,        0xFFFFFEDC,__READ_WRITE ,__chanctrl23_bits);
__IO_REG32_BIT(PARFLG,            0xFFFFFDEC,__READ_WRITE ,__parflg_bits);
__IO_REG32_BIT(PARCTL,            0xFFFFFDF0,__READ_WRITE ,__parctl_bits);
__IO_REG32(    ADDERR,            0xFFFFFDF4,__READ       );
__IO_REG32(    FBPARERR,          0xFFFFFDF8,__READ_WRITE );
__IO_REG32(    VIM_RAM_BASE,      0xFFF82000,__READ_WRITE );

/***************************************************************************
 **
 ** SYS1 (Primary System Control)
 **
 ***************************************************************************/
__IO_REG32_BIT(SYSPC1,            0xFFFFFF00,__READ_WRITE ,__syspc1_bits);
__IO_REG32_BIT(SYSPC2,            0xFFFFFF04,__READ_WRITE ,__syspc2_bits);
__IO_REG32_BIT(SYSPC3,            0xFFFFFF08,__READ       ,__syspc3_bits);
__IO_REG32_BIT(SYSPC4,            0xFFFFFF0C,__READ_WRITE ,__syspc4_bits);
__IO_REG32_BIT(SYSPC5,            0xFFFFFF10,__READ_WRITE ,__syspc5_bits);
__IO_REG32_BIT(SYSPC6,            0xFFFFFF14,__READ_WRITE ,__syspc6_bits);
__IO_REG32_BIT(SYSPC7,            0xFFFFFF18,__READ_WRITE ,__syspc7_bits);
__IO_REG32_BIT(SYSPC8,            0xFFFFFF1C,__READ_WRITE ,__syspc8_bits);
__IO_REG32_BIT(SYSPC9,            0xFFFFFF20,__READ_WRITE ,__syspc9_bits);
__IO_REG32_BIT(SSWPLL1,           0xFFFFFF24,__READ_WRITE ,__sswpll1_bits);
__IO_REG32(    SSWPLL2,           0xFFFFFF28,__READ_WRITE );
__IO_REG32(    SSWPLL3,           0xFFFFFF2C,__READ_WRITE );
__IO_REG32_BIT(CSDIS,             0xFFFFFF30,__READ_WRITE ,__csdis_bits);
__IO_REG32_BIT(CSDISSET,          0xFFFFFF34,__READ_WRITE ,__csdisset_bits);
__IO_REG32_BIT(CSDISCLR,          0xFFFFFF38,__READ_WRITE ,__csdisclr_bits);
__IO_REG32_BIT(CDDIS,             0xFFFFFF3C,__READ_WRITE ,__cddis_bits);
__IO_REG32_BIT(CDDISSET,          0xFFFFFF40,__READ_WRITE ,__cddisset_bits);
__IO_REG32_BIT(CDDISCLR,          0xFFFFFF44,__READ_WRITE ,__cddisclr_bits);
__IO_REG32_BIT(GHVSRC,            0xFFFFFF48,__READ_WRITE ,__ghvsrc_bits);
__IO_REG32_BIT(VCLKASRC,          0xFFFFFF4C,__READ_WRITE ,__vclkasrc_bits);
__IO_REG32_BIT(RCLKSRC,           0xFFFFFF50,__READ_WRITE ,__rclksrc_bits);
__IO_REG32_BIT(CSVSTAT,           0xFFFFFF54,__READ       ,__csvstat_bits);
__IO_REG32_BIT(MSTGCR,            0xFFFFFF58,__READ_WRITE ,__mstgcr_bits);
__IO_REG32_BIT(MINITGCR,          0xFFFFFF5C,__READ_WRITE ,__minitgcr_bits);
__IO_REG32_BIT(MSIENA,            0xFFFFFF60,__READ_WRITE ,__msiena_bits);
__IO_REG32_BIT(MSTCGSTAT,         0xFFFFFF68,__READ_WRITE ,__mstcgstat_bits);
__IO_REG32_BIT(MINISTAT,          0xFFFFFF6C,__READ_WRITE ,__ministat_bits);
__IO_REG32_BIT(PLLCTL1,           0xFFFFFF70,__READ_WRITE ,__pllctl1_bits);
__IO_REG32_BIT(PLLCTL2,           0xFFFFFF74,__READ_WRITE ,__pllctl2_bits);
__IO_REG32_BIT(SYSPC10,           0xFFFFFF78,__READ_WRITE ,__syspc10_bits);
__IO_REG32_BIT(DIEIDL,            0xFFFFFF7C,__READ       ,__dieidl_bits);
__IO_REG32_BIT(DIEIDH,            0xFFFFFF80,__READ       ,__dieidh_bits);
__IO_REG32_BIT(LPOMONCTL,         0xFFFFFF88,__READ_WRITE ,__lpomonctl_bits);
__IO_REG32_BIT(CLKTEST,           0xFFFFFF8C,__READ_WRITE ,__clktest_bits);
__IO_REG32_BIT(DFTCTRLREG,        0xFFFFFF90,__READ_WRITE ,__dftctrlreg_bits);
__IO_REG32_BIT(DFTCTRLREG2,       0xFFFFFF94,__READ_WRITE ,__dftctrlreg2_bits);
__IO_REG32_BIT(GPREG1,            0xFFFFFFA0,__READ_WRITE ,__gpreg1_bits);
__IO_REG32_BIT(IMPFASTS,          0xFFFFFFA8,__READ       ,__impfasts_bits);
__IO_REG32(    IMPFTADD,          0xFFFFFFAC,__READ       );
__IO_REG32_BIT(SSIR1,             0xFFFFFFB0,__READ_WRITE ,__ssir1_bits);
__IO_REG32_BIT(SSIR2,             0xFFFFFFB4,__READ_WRITE ,__ssir2_bits);
__IO_REG32_BIT(SSIR3,             0xFFFFFFB8,__READ_WRITE ,__ssir3_bits);
__IO_REG32_BIT(SSIR4,             0xFFFFFFBC,__READ_WRITE ,__ssir4_bits);
__IO_REG32_BIT(RAMGCR,            0xFFFFFFC0,__READ_WRITE ,__ramgcr_bits);
__IO_REG32_BIT(BMMCR1,            0xFFFFFFC4,__READ_WRITE ,__bmmcr_bits);
__IO_REG32_BIT(CPURSTCR,          0xFFFFFFCC,__READ_WRITE ,__cpurstcr_bits);
__IO_REG32_BIT(CLKCNTL,           0xFFFFFFD0,__READ_WRITE ,__clkcntl_bits);
__IO_REG32_BIT(ECPCNTL,           0xFFFFFFD4,__READ_WRITE ,__ecpcntl_bits);
__IO_REG32_BIT(DEVCR1,            0xFFFFFFDC,__READ_WRITE ,__devcr1_bits);
__IO_REG32_BIT(SYSECR,            0xFFFFFFE0,__READ_WRITE ,__sysecr_bits);
__IO_REG32_BIT(SYSESR,            0xFFFFFFE4,__READ_WRITE ,__sysesr_bits);
__IO_REG32_BIT(SYSTASR,           0xFFFFFFE8,__READ_WRITE ,__systasr_bits);
__IO_REG32_BIT(GLBSTAT,           0xFFFFFFEC,__READ_WRITE ,__glbstat_bits);
__IO_REG32_BIT(DEVID,             0xFFFFFFF0,__READ       ,__devid_bits);
__IO_REG32_BIT(SSIVEC,            0xFFFFFFF4,__READ       ,__ssivec_bits);
__IO_REG32_BIT(SSIF,              0xFFFFFFF8,__READ_WRITE ,__ssif_bits);
__IO_REG32_BIT(SSIR1_MIRROR,      0xFFFFFFFC,__READ_WRITE ,__ssir1_bits);

/***************************************************************************
 **
 ** SYS2 (Secondary System Control)
 **
 ***************************************************************************/
__IO_REG32_BIT(PLLCTL3,           0xFFFFE100,__READ_WRITE ,__pllctl3_bits);
__IO_REG32_BIT(STCCLKDIV,         0xFFFFE108,__READ_WRITE ,__stcclkdiv_bits);
__IO_REG32_BIT(SYS2_ECPCNTL,      0xFFFFE124,__READ_WRITE ,__ecpcntl_bits);
__IO_REG32_BIT(CLK2CNTL,          0xFFFFE13C,__READ_WRITE ,__clk2cntl_bits);
__IO_REG32_BIT(VCLKACON1,         0xFFFFE140,__READ_WRITE ,__vclkacon1_bits);
__IO_REG32_BIT(CLKSLIP,           0xFFFFE170,__READ_WRITE ,__clkslip_bits);
__IO_REG32_BIT(EFC_CTLREG,        0xFFFFE1EC,__READ_WRITE ,__efc_ctlreg_bits);
__IO_REG32(    DIEID_REG0,        0xFFFFE1F0,__READ       );
__IO_REG32(    DIEID_REG1,        0xFFFFE1F4,__READ       );
__IO_REG32(    DIEID_REG2,        0xFFFFE1F8,__READ       );
__IO_REG32(    DIEID_REG3,        0xFFFFE1FC,__READ       );

/***************************************************************************
 **
 ** PCR (Peripheral Central Resource)
 **
 ***************************************************************************/
__IO_REG32_BIT(PMPROTSET0,        0xFFFFE000,__READ_WRITE ,__pmprotset0_bits);
__IO_REG32_BIT(PMPROTSET1,        0xFFFFE004,__READ_WRITE ,__pmprotset1_bits);
__IO_REG32_BIT(PMPROTCLR0,        0xFFFFE010,__READ_WRITE ,__pmprotclr0_bits);
__IO_REG32_BIT(PMPROTCLR1,        0xFFFFE014,__READ_WRITE ,__pmprotclr1_bits);
__IO_REG32_BIT(PPROTSET0,         0xFFFFE020,__READ_WRITE ,__pprotset0_bits);
__IO_REG32_BIT(PPROTSET1,         0xFFFFE024,__READ_WRITE ,__pprotset1_bits);
__IO_REG32_BIT(PPROTSET2,         0xFFFFE028,__READ_WRITE ,__pprotset2_bits);
__IO_REG32_BIT(PPROTSET3,         0xFFFFE02C,__READ_WRITE ,__pprotset3_bits);
__IO_REG32_BIT(PPROTCLR0,         0xFFFFE040,__READ_WRITE ,__pprotclr0_bits);
__IO_REG32_BIT(PPROTCLR1,         0xFFFFE044,__READ_WRITE ,__pprotclr1_bits);
__IO_REG32_BIT(PPROTCLR2,         0xFFFFE048,__READ_WRITE ,__pprotclr2_bits);
__IO_REG32_BIT(PPROTCLR3,         0xFFFFE04C,__READ_WRITE ,__pprotclr3_bits);
__IO_REG32_BIT(PCSPWRDWNSET0,     0xFFFFE060,__READ_WRITE ,__pcspwrdwnset0_bits);
__IO_REG32_BIT(PCSPWRDWNSET1,     0xFFFFE064,__READ_WRITE ,__pcspwrdwnset1_bits);
__IO_REG32_BIT(PCSPWRDWNCLR0,     0xFFFFE070,__READ_WRITE ,__pcspwrdwnclr0_bits);
__IO_REG32_BIT(PCSPWRDWNCLR1,     0xFFFFE074,__READ_WRITE ,__pcspwrdwnclr1_bits);
__IO_REG32_BIT(PSPWRDWNSET0,      0xFFFFE080,__READ_WRITE ,__pspwrdwnset0_bits);
__IO_REG32_BIT(PSPWRDWNSET1,      0xFFFFE084,__READ_WRITE ,__pspwrdwnset1_bits);
__IO_REG32_BIT(PSPWRDWNSET2,      0xFFFFE088,__READ_WRITE ,__pspwrdwnset2_bits);
__IO_REG32_BIT(PSPWRDWNSET3,      0xFFFFE08C,__READ_WRITE ,__pspwrdwnset3_bits);
__IO_REG32_BIT(PSPWRDWNCLR0,      0xFFFFE0A0,__READ_WRITE ,__pspwrdwnclr0_bits);
__IO_REG32_BIT(PSPWRDWNCLR1,      0xFFFFE0A4,__READ_WRITE ,__pspwrdwnclr1_bits);
__IO_REG32_BIT(PSPWRDWNCLR2,      0xFFFFE0A8,__READ_WRITE ,__pspwrdwnclr2_bits);
__IO_REG32_BIT(PSPWRDWNCLR3,      0xFFFFE0AC,__READ_WRITE ,__pspwrdwnclr3_bits);

/***************************************************************************
 **
 ** PBIST (Programmable Built-In Self Test)
 **
 ***************************************************************************/
__IO_REG32_BIT(PBIST_RAMT,        0xFFFFE560,__READ_WRITE ,__pbist_ramt_bits);
__IO_REG32_BIT(PBIST_DLR,         0xFFFFE564,__READ_WRITE ,__pbist_dlr_bits);
__IO_REG32_BIT(PBIST_PACT,        0xFFFFE580,__READ_WRITE ,__pbist_pact_bits);
__IO_REG32_BIT(PBIST_ID,          0xFFFFE584,__READ_WRITE ,__pbist_id_bits);
__IO_REG32_BIT(PBIST_OVER,        0xFFFFE588,__READ_WRITE ,__pbist_over_bits);
__IO_REG32_BIT(PBIST_FSRF0,       0xFFFFE590,__READ_WRITE ,__pbist_fsrf0_bits);
//__IO_REG32_BIT(PBIST_FSRF1,       0xFFFFE594,__READ_WRITE ,__pbist_fsrf1_bits);
__IO_REG32_BIT(PBIST_FSRC0,       0xFFFFE598,__READ       ,__pbist_fsrc0_bits);
__IO_REG32_BIT(PBIST_FSRC1,       0xFFFFE59C,__READ       ,__pbist_fsrc1_bits);
__IO_REG32_BIT(PBIST_FSRA0,       0xFFFFE5A0,__READ       ,__pbist_fsra0_bits);
__IO_REG32_BIT(PBIST_FSRA1,       0xFFFFE5A4,__READ       ,__pbist_fsra1_bits);
__IO_REG32(    PBIST_FSRDL0,      0xFFFFE5A8,__READ       );
__IO_REG32(    PBIST_FSRDL1,      0xFFFFE5B0,__READ       );
__IO_REG32_BIT(PBIST_ROM,         0xFFFFE5C0,__READ_WRITE ,__pbist_rom_bits);
__IO_REG32_BIT(PBIST_ALGO,        0xFFFFE5C4,__READ_WRITE ,__pbist_algo_bits);
__IO_REG32_BIT(PBIST_RINFOL,      0xFFFFE5C8,__READ_WRITE ,__pbist_rinfol_bits);
__IO_REG32_BIT(PBIST_RINFOU,      0xFFFFE5CC,__READ_WRITE ,__pbist_rinfou_bits);

/***************************************************************************
 **
 ** STC (CPU Self Test Controller)
 **
 ***************************************************************************/
__IO_REG32_BIT(STCGCR0,           0xFFFFE600,__READ_WRITE ,__stcgcr0_bits);
__IO_REG32_BIT(STCGCR1,           0xFFFFE604,__READ_WRITE ,__stcgcr1_bits);
__IO_REG32(    STCTPR,            0xFFFFE608,__READ_WRITE );
__IO_REG32(    STC_CADDR,         0xFFFFE60C,__READ       );
__IO_REG32_BIT(STCCICR,           0xFFFFE610,__READ       ,__stccicr_bits);
__IO_REG32_BIT(STCGSTAT,          0xFFFFE614,__READ_WRITE ,__stcgstat_bits);
__IO_REG32_BIT(STCFSTAT,          0xFFFFE618,__READ_WRITE ,__stcfstat_bits);
__IO_REG32(    CPU1_CURMISR3,     0xFFFFE61C,__READ       );
__IO_REG32(    CPU1_CURMISR2,     0xFFFFE620,__READ       );
__IO_REG32(    CPU1_CURMISR1,     0xFFFFE624,__READ       );
__IO_REG32(    CPU1_CURMISR0,     0xFFFFE628,__READ       );
__IO_REG32(    CPU2_CURMISR3,     0xFFFFE62C,__READ       );
__IO_REG32(    CPU2_CURMISR2,     0xFFFFE630,__READ       );
__IO_REG32(    CPU2_CURMISR1,     0xFFFFE634,__READ       );
__IO_REG32(    CPU2_CURMISR0,     0xFFFFE638,__READ       );
__IO_REG32_BIT(STCSCSCR,          0xFFFFE63C,__READ_WRITE ,__stcscscr_bits);

/***************************************************************************
 **
 ** TCRAM (Tightly-Coupled RAM)
 **
 ***************************************************************************/
__IO_REG32_BIT(RAMCTRL1,          0xFFFFF800,__READ_WRITE ,__ramctrl_bits);
__IO_REG32_BIT(RAMTHRESHOLD1,     0xFFFFF804,__READ_WRITE ,__ramthreshold_bits);
__IO_REG32_BIT(RAMOCCUR1,         0xFFFFF808,__READ_WRITE ,__ramoccur_bits);
__IO_REG32_BIT(RAMINTCTRL1,       0xFFFFF80C,__READ_WRITE ,__ramintctrl_bits);
__IO_REG32_BIT(RAMERRSTATUS1,     0xFFFFF810,__READ_WRITE ,__ramerrstatus_bits);
__IO_REG32_BIT(RAMSERRADDR1,      0xFFFFF814,__READ       ,__ramserraddr_bits);
__IO_REG32_BIT(RAMUERRADDR1,      0xFFFFF81C,__READ       ,__ramuerraddr_bits);
__IO_REG32_BIT(RAMTEST1,          0xFFFFF830,__READ_WRITE ,__ramtest_bits);
__IO_REG32_BIT(RAMADDRDECVECT1,   0xFFFFF838,__READ_WRITE ,__ramaddrdecvect_bits);
__IO_REG32_BIT(RAMPERRADDR1,      0xFFFFF83C,__READ       ,__ramperraddr_bits);
__IO_REG32_BIT(INIT_DOMAIN1,      0xFFFFF840,__READ_WRITE ,__init_domain_bits);
__IO_REG32_BIT(RAMCTRL2,          0xFFFFF900,__READ_WRITE ,__ramctrl_bits);
__IO_REG32_BIT(RAMTHRESHOLD2,     0xFFFFF904,__READ_WRITE ,__ramthreshold_bits);
__IO_REG32_BIT(RAMOCCUR2,         0xFFFFF908,__READ_WRITE ,__ramoccur_bits);
__IO_REG32_BIT(RAMINTCTRL2,       0xFFFFF90C,__READ_WRITE ,__ramintctrl_bits);
__IO_REG32_BIT(RAMERRSTATUS2,     0xFFFFF910,__READ_WRITE ,__ramerrstatus_bits);
__IO_REG32_BIT(RAMSERRADDR2,      0xFFFFF914,__READ       ,__ramserraddr_bits);
__IO_REG32_BIT(RAMUERRADDR2,      0xFFFFF91C,__READ       ,__ramuerraddr_bits);
__IO_REG32_BIT(RAMTEST2,          0xFFFFF930,__READ_WRITE ,__ramtest_bits);
__IO_REG32_BIT(RAMADDRDECVECT2,   0xFFFFF938,__READ_WRITE ,__ramaddrdecvect_bits);
__IO_REG32_BIT(RAMPERRADDR2,      0xFFFFF93C,__READ       ,__ramperraddr_bits);
__IO_REG32_BIT(INIT_DOMAIN2,      0xFFFFF940,__READ_WRITE ,__init_domain_bits);

/***************************************************************************
 **
 ** Flash memory
 **
 ***************************************************************************/
__IO_REG32_BIT(FRDCNTL,           0xFFF87000,__READ_WRITE ,__frdcntl_bits);
__IO_REG32_BIT(FEDACCTRL1,        0xFFF87008,__READ_WRITE ,__fedacctrl1_bits);
__IO_REG32_BIT(FEDACCTRL2,        0xFFF8700C,__READ_WRITE ,__fedacctrl2_bits);
__IO_REG32_BIT(FCOR_ERR_CNT,      0xFFF87010,__READ_WRITE ,__fcor_err_cnt_bits);
__IO_REG32_BIT(FCOR_ERR_ADD,      0xFFF87014,__READ       ,__fcor_err_add_bits);
__IO_REG32_BIT(FCOR_ERR_POS,      0xFFF87018,__READ       ,__fcor_err_pos_bits);
__IO_REG32_BIT(FEDACSTATUS,       0xFFF8701C,__READ_WRITE ,__fedacstatus_bits);
__IO_REG32_BIT(FUNC_ERR_ADD,      0xFFF87020,__READ       ,__func_err_add_bits);
__IO_REG32_BIT(FEDACSDIS,         0xFFF87024,__READ_WRITE ,__fedacsdis_bits);
__IO_REG32(    FPRIM_ADD_TAG,     0xFFF87028,__READ_WRITE );
__IO_REG32(    FDUP_ADD_TAG,      0xFFF8702C,__READ_WRITE );
__IO_REG32_BIT(FBPROT,            0xFFF87030,__READ_WRITE ,__fbprot_bits);
__IO_REG32_BIT(FBSE,              0xFFF87034,__READ_WRITE ,__fbse_bits);
__IO_REG32_BIT(FBBUSY,            0xFFF87038,__READ_WRITE ,__fbbusy_bits);
__IO_REG32_BIT(FBAC,              0xFFF8703C,__READ_WRITE ,__fbac_bits);
__IO_REG32_BIT(FBFALLBACK,        0xFFF87040,__READ_WRITE ,__fbfallback_bits);
__IO_REG32_BIT(FBPRDY,            0xFFF87044,__READ       ,__fbprdy_bits);
__IO_REG32_BIT(FPAC1,             0xFFF87048,__READ_WRITE ,__fpac1_bits);
__IO_REG32_BIT(FPAC2,             0xFFF8704C,__READ_WRITE ,__fpac2_bits);
__IO_REG32_BIT(FMAC,              0xFFF87050,__READ_WRITE ,__fmac_bits);
__IO_REG32_BIT(FMSTAT,            0xFFF87054,__READ       ,__fmstat_bits);
__IO_REG32(    FEMU_DMSW,         0xFFF87058,__READ_WRITE );
__IO_REG32(    FEMU_DLSW,         0xFFF8705C,__READ_WRITE );
__IO_REG32_BIT(FEMU_ECC,          0xFFF87060,__READ_WRITE ,__femu_ecc_bits);
__IO_REG32(    FEMU_ADDR,         0xFFF87068,__READ_WRITE );
__IO_REG32_BIT(FDIAGCTRL,         0xFFF8706C,__READ_WRITE ,__fdiagctrl_bits);
__IO_REG32(    FRAW_DATAH,        0xFFF87070,__READ_WRITE );
__IO_REG32(    FRAW_DATAL,        0xFFF87074,__READ_WRITE );
__IO_REG32_BIT(FRAW_ECC,          0xFFF87078,__READ_WRITE ,__fraw_ecc_bits);
__IO_REG32_BIT(FPAR_OVR,          0xFFF8707C,__READ_WRITE ,__fpar_ovr_bits);
__IO_REG32_BIT(FEDACSDIS2,        0xFFF870C0,__READ_WRITE ,__fedacsdis2_bits);
__IO_REG32_BIT(FSM_WR_ENA,        0xFFF87288,__READ_WRITE ,__fsm_wr_ena_bits);
__IO_REG32_BIT(FSM_SECTOR,        0xFFF872A4,__READ_WRITE ,__fsm_sector_bits);
__IO_REG32_BIT(EEPROM_CONFIG,     0xFFF872B8,__READ_WRITE ,__eeprom_config_bits);
__IO_REG32_BIT(EE_CTRL1,          0xFFF87308,__READ_WRITE ,__ee_ctrl1_bits);
__IO_REG32_BIT(EE_CTRL2,          0xFFF8730C,__READ_WRITE ,__ee_ctrl2_bits);
__IO_REG32_BIT(EE_COR_ERR_CNT,    0xFFF87310,__READ_WRITE ,__ee_cor_err_cnt_bits);
__IO_REG32_BIT(EE_COR_ERR_ADD,    0xFFF87314,__READ       ,__fcor_err_add_bits);
__IO_REG32_BIT(EE_COR_ERR_POS,    0xFFF87318,__READ_WRITE ,__ee_cor_err_pos_bits);
__IO_REG32_BIT(EE_STATUS,         0xFFF8731C,__READ_WRITE ,__ee_status_bits);
__IO_REG32_BIT(EE_UNC_ERR_ADD,    0xFFF87320,__READ       ,__func_err_add_bits);
__IO_REG32_BIT(FCFG_BANK,         0xFFF87400,__READ       ,__fcfg_bank_bits);

/***************************************************************************
 **
 ** EMIF (External Memory Interface)
 **
 ***************************************************************************/
__IO_REG32(    EMIF_MIDR,         0xFCFFE800,__READ       );
__IO_REG32_BIT(EMIF_AWCC,         0xFCFFE804,__READ_WRITE ,__emif_awcc_bits);
__IO_REG32_BIT(EMIF_SDCR,         0xFCFFE808,__READ_WRITE ,__emif_sdcr_bits);
#define EMIF_SDCR0      EMIF_SDCR_bit.byte0
#define EMIF_SDCR0_bit  EMIF_SDCR_bit.byte0_bits
#define EMIF_SDCR1      EMIF_SDCR_bit.byte1
#define EMIF_SDCR1_bit  EMIF_SDCR_bit.byte1_bits
#define EMIF_SDCR3      EMIF_SDCR_bit.byte3
#define EMIF_SDCR3_bit  EMIF_SDCR_bit.byte3_bits
__IO_REG32_BIT(EMIF_SDRCR,        0xFCFFE80C,__READ_WRITE ,__emif_sdrcr_bits);
__IO_REG32_BIT(EMIF_CE2CFG,       0xFCFFE810,__READ_WRITE ,__emif_cexcfg_bits);
__IO_REG32_BIT(EMIF_CE3CFG,       0xFCFFE814,__READ_WRITE ,__emif_cexcfg_bits);
__IO_REG32_BIT(EMIF_CE4CFG,       0xFCFFE818,__READ_WRITE ,__emif_cexcfg_bits);
__IO_REG32_BIT(EMIF_CE5CFG,       0xFCFFE81C,__READ_WRITE ,__emif_cexcfg_bits);
__IO_REG32_BIT(EMIF_SDTIMR,       0xFCFFE820,__READ_WRITE ,__emif_sdtimr_bits);
__IO_REG32_BIT(EMIF_SDSRETR,      0xFCFFE83C,__READ_WRITE ,__emif_sdsretr_bits);
__IO_REG32_BIT(EMIF_INTRAW,       0xFCFFE840,__READ_WRITE ,__emif_intraw_bits);
__IO_REG32_BIT(EMIF_INTMSK,       0xFCFFE844,__READ_WRITE ,__emif_intmsk_bits);
__IO_REG32_BIT(EMIF_INTMSKSET,    0xFCFFE848,__READ_WRITE ,__emif_intmskset_bits);
__IO_REG32_BIT(EMIF_INTMSKCLR,    0xFCFFE84C,__READ_WRITE ,__emif_intmskclr_bits);
__IO_REG32_BIT(EMIF_PMCR,         0xFCFFE868,__READ_WRITE ,__emif_pmcr_bits);

/***************************************************************************
 **
 ** POM (Parameter Overlay Module)
 **
 ***************************************************************************/
__IO_REG32_BIT(POMGLBCTRL,        0xFFA04000,__READ_WRITE ,__pomglbctrl_bits);
__IO_REG32_BIT(POMREV,            0xFFA04004,__READ       ,__pomrev_bits);
__IO_REG32_BIT(POMCLKCTRL,        0xFFA04008,__READ_WRITE ,__pomclkctrl_bits);
__IO_REG32_BIT(POMFLG,            0xFFA0400C,__READ_WRITE ,__pomflg_bits);
__IO_REG32_BIT(POMPRGSTART0,      0xFFA04200,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART0,      0xFFA04204,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE0,       0xFFA04208,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART1,      0xFFA04210,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART1,      0xFFA04214,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE1,       0xFFA04218,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART2,      0xFFA04220,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART2,      0xFFA04224,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE2,       0xFFA04228,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART3,      0xFFA04230,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART3,      0xFFA04234,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE3,       0xFFA04238,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART4,      0xFFA04240,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART4,      0xFFA04244,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE4,       0xFFA04248,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART5,      0xFFA04250,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART5,      0xFFA04254,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE5,       0xFFA04258,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART6,      0xFFA04260,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART6,      0xFFA04264,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE6,       0xFFA04268,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART7,      0xFFA04270,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART7,      0xFFA04274,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE7,       0xFFA04278,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART8,      0xFFA04280,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART8,      0xFFA04284,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE8,       0xFFA04288,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART9,      0xFFA04290,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART9,      0xFFA04294,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE9,       0xFFA04298,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART10,     0xFFA042A0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART10,     0xFFA042A4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE10,      0xFFA042A8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART11,     0xFFA042B0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART11,     0xFFA042B4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE11,      0xFFA042B8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART12,     0xFFA042C0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART12,     0xFFA042C4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE12,      0xFFA042C8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART13,     0xFFA042D0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART13,     0xFFA042D4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE13,      0xFFA042D8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART14,     0xFFA042E0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART14,     0xFFA042E4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE14,      0xFFA042E8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART15,     0xFFA042F0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART15,     0xFFA042F4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE15,      0xFFA042F8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART16,     0xFFA04300,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART16,     0xFFA04304,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE16,      0xFFA04308,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART17,     0xFFA04310,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART17,     0xFFA04314,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE17,      0xFFA04318,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART18,     0xFFA04320,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART18,     0xFFA04324,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE18,      0xFFA04328,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART19,     0xFFA04330,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART19,     0xFFA04334,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE19,      0xFFA04338,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART20,     0xFFA04340,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART20,     0xFFA04344,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE20,      0xFFA04348,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART21,     0xFFA04350,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART21,     0xFFA04354,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE21,      0xFFA04358,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART22,     0xFFA04360,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART22,     0xFFA04364,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE22,      0xFFA04368,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART23,     0xFFA04370,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART23,     0xFFA04374,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE23,      0xFFA04378,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART24,     0xFFA04380,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART24,     0xFFA04384,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE24,      0xFFA04388,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART25,     0xFFA04390,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART25,     0xFFA04394,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE25,      0xFFA04398,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART26,     0xFFA043A0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART26,     0xFFA043A4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE26,      0xFFA043A8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART27,     0xFFA043B0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART27,     0xFFA043B4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE27,      0xFFA043B8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART28,     0xFFA043C0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART28,     0xFFA043C4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE28,      0xFFA043C8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART29,     0xFFA043D0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART29,     0xFFA043D4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE29,      0xFFA043D8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART30,     0xFFA043E0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART30,     0xFFA043E4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE30,      0xFFA043E8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMPRGSTART31,     0xFFA043F0,__READ_WRITE ,__pomprgstartx_bits);
__IO_REG32_BIT(POMOVLSTART31,     0xFFA043F4,__READ_WRITE ,__pomovlstartx_bits);
__IO_REG32_BIT(POMREGSIZE31,      0xFFA043F8,__READ_WRITE ,__pomregsizex_bits);
__IO_REG32_BIT(POMCLAIMSET,       0xFFA04FA0,__READ_WRITE ,__pomclaimset_bits);
__IO_REG32_BIT(POMCLAIMCLR,       0xFFA04FA4,__READ_WRITE ,__pomclaimclr_bits);
__IO_REG32_BIT(POMDEVTYPE,        0xFFA04FCC,__READ       ,__pomdevtype_bits);
__IO_REG32_BIT(POMPERIPHERALID4,  0xFFA04FD0,__READ       ,__pomperipheralid4_bits);
__IO_REG32_BIT(POMPERIPHERALID0,  0xFFA04FE0,__READ       ,__pomperipheralid0_bits);
__IO_REG32_BIT(POMPERIPHERALID1,  0xFFA04FE4,__READ       ,__pomperipheralid1_bits);
__IO_REG32_BIT(POMPERIPHERALID2,  0xFFA04FE8,__READ       ,__pomperipheralid2_bits);
__IO_REG32_BIT(POMCOMPONENTID0,   0xFFA04FF0,__READ       ,__pomcomponentid0_bits);
__IO_REG32_BIT(POMCOMPONENTID1,   0xFFA04FF4,__READ       ,__pomcomponentid1_bits);
__IO_REG32_BIT(POMCOMPONENTID2,   0xFFA04FF8,__READ       ,__pomcomponentid0_bits);
__IO_REG32_BIT(POMCOMPONENTID3,   0xFFA04FFC,__READ       ,__pomcomponentid0_bits);

/***************************************************************************
 **
 ** GIO (General-Purpose Input/Output)
 **
 ***************************************************************************/
__IO_REG32_BIT(GIOGCR0,           0xFFF7BC00,__READ_WRITE ,__giogcr0_bits);
__IO_REG32_BIT(GIOINTDET,         0xFFF7BC08,__READ_WRITE ,__giointdet_bits);
__IO_REG32_BIT(GIOPOL,            0xFFF7BC0C,__READ_WRITE ,__giopol_bits);
__IO_REG32_BIT(GIOENASET,         0xFFF7BC10,__READ_WRITE ,__gioenaset_bits);
__IO_REG32_BIT(GIOENACLR,         0xFFF7BC14,__READ_WRITE ,__gioenaclr_bits);
__IO_REG32_BIT(GIOLVLSET,         0xFFF7BC18,__READ_WRITE ,__giolvlset_bits);
__IO_REG32_BIT(GIOLVLCLR,         0xFFF7BC1C,__READ_WRITE ,__giolvlclr_bits);
__IO_REG32_BIT(GIOFLG,            0xFFF7BC20,__READ_WRITE ,__gioflg_bits);
__IO_REG32_BIT(GIOOFF1,           0xFFF7BC24,__READ       ,__giooff1_bits);
__IO_REG32_BIT(GIOOFF2,           0xFFF7BC28,__READ       ,__giooff2_bits);
__IO_REG32_BIT(GIOEMU1,           0xFFF7BC2C,__READ       ,__gioemu1_bits);
__IO_REG32_BIT(GIOEMU2,           0xFFF7BC30,__READ       ,__gioemu2_bits);
__IO_REG32_BIT(GIODIRA,           0xFFF7BC34,__READ_WRITE ,__giodir_bits);
__IO_REG32_BIT(GIODINA,           0xFFF7BC38,__READ       ,__giodin_bits);
__IO_REG32_BIT(GIODOUTA,          0xFFF7BC3C,__READ_WRITE ,__giodout_bits);
__IO_REG32_BIT(GIOSETA,           0xFFF7BC40,__READ_WRITE ,__gioset_bits);
__IO_REG32_BIT(GIOCLRA,           0xFFF7BC44,__READ_WRITE ,__gioclr_bits);
__IO_REG32_BIT(GIOPDRA,           0xFFF7BC48,__READ_WRITE ,__giopdr_bits);
__IO_REG32_BIT(GIOPULDISA,        0xFFF7BC4C,__READ_WRITE ,__giopuldis_bits);
__IO_REG32_BIT(GIOPSLA,           0xFFF7BC50,__READ_WRITE ,__giopsl_bits);
__IO_REG32_BIT(GIODIRB,           0xFFF7BC54,__READ_WRITE ,__giodir_bits);
__IO_REG32_BIT(GIODINB,           0xFFF7BC58,__READ_WRITE ,__giodin_bits);
__IO_REG32_BIT(GIODOUTB,          0xFFF7BC5C,__READ_WRITE ,__giodout_bits);
__IO_REG32_BIT(GIOSETB,           0xFFF7BC60,__READ_WRITE ,__gioset_bits);
__IO_REG32_BIT(GIOCLRB,           0xFFF7BC64,__READ_WRITE ,__gioclr_bits);
__IO_REG32_BIT(GIOPDRB,           0xFFF7BC68,__READ_WRITE ,__giopdr_bits);
__IO_REG32_BIT(GIOPULDISB,        0xFFF7BC6C,__READ_WRITE ,__giopuldis_bits);
__IO_REG32_BIT(GIOPSLB,           0xFFF7BC70,__READ_WRITE ,__giopsl_bits);

/***************************************************************************
 **
 ** SCI1/LIN1 (Serial Communication Interface/Local InterconnectNetwork)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCI1GCR0,          0xFFF7E400,__READ_WRITE ,__scigcr0_bits);
__IO_REG32_BIT(SCI1GCR1,          0xFFF7E404,__READ_WRITE ,__scilingcr1_bits);
__IO_REG32_BIT(SCI1GCR2,          0xFFF7E408,__READ_WRITE ,__scigcr2_bits);
__IO_REG32_BIT(SCI1SETINT,        0xFFF7E40C,__READ_WRITE ,__scilinsetint_bits);
__IO_REG32_BIT(SCI1CLEARINT,      0xFFF7E410,__READ_WRITE ,__scilinclearint_bits);
__IO_REG32_BIT(SCI1SETINTLVL,     0xFFF7E414,__READ_WRITE ,__scilinsetintlvl_bits);
__IO_REG32_BIT(SCI1CLEARINTLVL,   0xFFF7E418,__READ_WRITE ,__scilinclearintlvl_bits);
__IO_REG32_BIT(SCI1FLR,           0xFFF7E41C,__READ_WRITE ,__scilinflr_bits);
__IO_REG32_BIT(SCI1INTVECT0,      0xFFF7E420,__READ       ,__scilinintvect0_bits);
__IO_REG32_BIT(SCI1INTVECT1,      0xFFF7E424,__READ       ,__scilinintvect1_bits);
__IO_REG32_BIT(SCI1FORMAT,        0xFFF7E428,__READ_WRITE ,__scilinformat_bits);
__IO_REG32_BIT(SCI1BRS,           0xFFF7E42C,__READ_WRITE ,__scilinbrs_bits);
__IO_REG32_BIT(SCI1ED,            0xFFF7E430,__READ       ,__scied_bits);
__IO_REG32_BIT(SCI1RD,            0xFFF7E434,__READ       ,__scird_bits);
__IO_REG32_BIT(SCI1TD,            0xFFF7E438,__READ_WRITE ,__scitd_bits);
__IO_REG32_BIT(SCI1PIO0,          0xFFF7E43C,__READ_WRITE ,__scipio0_bits);
__IO_REG32_BIT(SCI1PIO1,          0xFFF7E440,__READ_WRITE ,__scipio1_bits);
__IO_REG32_BIT(SCI1PIO2,          0xFFF7E444,__READ       ,__scipio2_bits);
__IO_REG32_BIT(SCI1PIO3,          0xFFF7E448,__READ_WRITE ,__scipio3_bits);
__IO_REG32_BIT(SCI1PIO4,          0xFFF7E44C,__READ_WRITE ,__scipio4_bits);
__IO_REG32_BIT(SCI1PIO5,          0xFFF7E450,__READ_WRITE ,__scipio5_bits);
__IO_REG32_BIT(SCI1PIO6,          0xFFF7E454,__READ_WRITE ,__scipio6_bits);
__IO_REG32_BIT(SCI1PIO7,          0xFFF7E458,__READ_WRITE ,__scipio7_bits);
__IO_REG32_BIT(SCI1PIO8,          0xFFF7E45C,__READ_WRITE ,__scipio8_bits);
__IO_REG32_BIT(LIN1COMPARE,       0xFFF7E460,__READ_WRITE ,__lincompare_bits);
__IO_REG32_BIT(LIN1RD0,           0xFFF7E464,__READ       ,__linrd0_bits);
__IO_REG32_BIT(LIN1RD1,           0xFFF7E468,__READ       ,__linrd1_bits);
__IO_REG32_BIT(LIN1MASK,          0xFFF7E46C,__READ_WRITE ,__linmask_bits);
__IO_REG32_BIT(LIN1ID,            0xFFF7E470,__READ_WRITE ,__linid_bits);
__IO_REG32_BIT(LIN1TD0,           0xFFF7E474,__READ_WRITE ,__lintd0_bits);
__IO_REG32_BIT(LIN1TD1,           0xFFF7E478,__READ_WRITE ,__lintd1_bits);
__IO_REG32_BIT(LIN1MBRS,          0xFFF7E47C,__READ_WRITE ,__linmbrs_bits);
__IO_REG32_BIT(IO1DFTCTRL,        0xFFF7E490,__READ_WRITE ,__scilin_iodftctrl_bits);

/***************************************************************************
 **
 ** SCI2 (Serial Communication Interface)
 **
 ***************************************************************************/
__IO_REG32_BIT(SCI2GCR0,          0xFFF7E500,__READ_WRITE ,__scigcr0_bits);
__IO_REG32_BIT(SCI2GCR1,          0xFFF7E504,__READ_WRITE ,__scigcr1_bits);
__IO_REG32_BIT(SCI2SETINT,        0xFFF7E50C,__READ_WRITE ,__scisetint_bits);
__IO_REG32_BIT(SCI2CLEARINT,      0xFFF7E510,__READ_WRITE ,__sciclearint_bits);
__IO_REG32_BIT(SCI2SETINTLVL,     0xFFF7E514,__READ_WRITE ,__scisetintlvl_bits);
__IO_REG32_BIT(SCI2CLEARINTLVL,   0xFFF7E518,__READ_WRITE ,__sciclearintlvl_bits);
__IO_REG32_BIT(SCI2FLR,           0xFFF7E51C,__READ_WRITE ,__sciflr_bits);
__IO_REG32_BIT(SCI2INTVECT0,      0xFFF7E520,__READ       ,__sciintvect0_bits);
__IO_REG32_BIT(SCI2INTVECT1,      0xFFF7E524,__READ       ,__sciintvect1_bits);
__IO_REG32_BIT(SCI2FORMAT,        0xFFF7E528,__READ_WRITE ,__sciformat_bits);
__IO_REG32_BIT(SCI2BRS,           0xFFF7E52C,__READ_WRITE ,__scibrs_bits);
__IO_REG32_BIT(SCI2ED,            0xFFF7E530,__READ       ,__scied_bits);
__IO_REG32_BIT(SCI2RD,            0xFFF7E534,__READ       ,__scird_bits);
__IO_REG32_BIT(SCI2TD,            0xFFF7E538,__READ_WRITE ,__scitd_bits);
__IO_REG32_BIT(SCI2PIO0,          0xFFF7E53C,__READ_WRITE ,__scipio0_bits);
__IO_REG32_BIT(SCI2PIO1,          0xFFF7E540,__READ_WRITE ,__scipio1_bits);
__IO_REG32_BIT(SCI2PIO2,          0xFFF7E544,__READ       ,__scipio2_bits);
__IO_REG32_BIT(SCI2PIO3,          0xFFF7E548,__READ_WRITE ,__scipio3_bits);
__IO_REG32_BIT(SCI2PIO4,          0xFFF7E54C,__READ_WRITE ,__scipio4_bits);
__IO_REG32_BIT(SCI2PIO5,          0xFFF7E550,__READ_WRITE ,__scipio5_bits);
__IO_REG32_BIT(SCI2PIO6,          0xFFF7E554,__READ_WRITE ,__scipio6_bits);
__IO_REG32_BIT(SCI2PIO7,          0xFFF7E558,__READ_WRITE ,__scipio7_bits);
__IO_REG32_BIT(SCI2PIO8,          0xFFF7E55C,__READ_WRITE ,__scipio8_bits);
__IO_REG32_BIT(IO2DFTCTRL,        0xFFF7E590,__READ_WRITE ,__sci_iodftctrl_bits);

/***************************************************************************
 **
 ** MibSPIP5 (Multi-Buffered Serial Peripheral Interface with Parallel Pin)
 **
 ***************************************************************************/
__IO_REG32_BIT(MIBSPI5GCR0,          0xFFF7FC00,__READ_WRITE ,__spigcr0_bits);
__IO_REG32_BIT(MIBSPI5GCR1,          0xFFF7FC04,__READ_WRITE ,__spigcr1_bits);
__IO_REG32_BIT(MIBSPI5INT0,          0xFFF7FC08,__READ_WRITE ,__spiint0_bits);
__IO_REG32_BIT(MIBSPI5LVL,           0xFFF7FC0C,__READ_WRITE ,__spilvl_bits);
__IO_REG32_BIT(MIBSPI5FLG,           0xFFF7FC10,__READ_WRITE ,__mibspiflg_bits);
__IO_REG32_BIT(MIBSPI5PC0,           0xFFF7FC14,__READ_WRITE ,__spippc0_bits);
__IO_REG32_BIT(MIBSPI5PC1,           0xFFF7FC18,__READ_WRITE ,__spippc1_bits);
__IO_REG32_BIT(MIBSPI5PC2,           0xFFF7FC1C,__READ       ,__spippc2_bits);
__IO_REG32_BIT(MIBSPI5PC3,           0xFFF7FC20,__READ_WRITE ,__spippc3_bits);
__IO_REG32_BIT(MIBSPI5PC4,           0xFFF7FC24,__READ_WRITE ,__spippc4_bits);
__IO_REG32_BIT(MIBSPI5PC5,           0xFFF7FC28,__READ_WRITE ,__spippc5_bits);
__IO_REG32_BIT(MIBSPI5PC6,           0xFFF7FC2C,__READ_WRITE ,__spippc6_bits);
__IO_REG32_BIT(MIBSPI5PC7,           0xFFF7FC30,__READ_WRITE ,__spippc7_bits);
__IO_REG32_BIT(MIBSPI5PC8,           0xFFF7FC34,__READ_WRITE ,__spippc8_bits);
__IO_REG32_BIT(MIBSPI5DAT0,          0xFFF7FC38,__READ_WRITE ,__spidat0_bits);
__IO_REG32_BIT(MIBSPI5DAT1,          0xFFF7FC3C,__READ_WRITE ,__spidat1_bits);
__IO_REG32_BIT(MIBSPI5BUF,           0xFFF7FC40,__READ       ,__spibuf_bits);
__IO_REG32_BIT(MIBSPI5EMU,           0xFFF7FC44,__READ       ,__spiemu_bits);
__IO_REG32_BIT(MIBSPI5DELAY,         0xFFF7FC48,__READ_WRITE ,__spidelay_bits);
__IO_REG32_BIT(MIBSPI5DEF,           0xFFF7FC4C,__READ_WRITE ,__spidef_bits);
__IO_REG32_BIT(MIBSPI5FMT0,          0xFFF7FC50,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI5FMT1,          0xFFF7FC54,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI5FMT2,          0xFFF7FC58,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI5FMT3,          0xFFF7FC5C,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI5INTVECT0,      0xFFF7FC60,__READ       ,__spiintvect0_bits);
__IO_REG32_BIT(MIBSPI5INTVECT1,      0xFFF7FC64,__READ       ,__spiintvect1_bits);
__IO_REG32_BIT(MIBSPI5PMCTRL,        0xFFF7FC6C,__READ_WRITE ,__spipmctrl_bits);
__IO_REG32_BIT(MIBSPI5MIBSPIE,       0xFFF7FC70,__READ_WRITE ,__spimibspie_bits);
__IO_REG32_BIT(MIBSPI5TGITENST,      0xFFF7FC74,__READ_WRITE ,__spitgitenst_bits);
__IO_REG32_BIT(MIBSPI5TGITENCR,      0xFFF7FC78,__READ_WRITE ,__spitgitencr_bits);
__IO_REG32_BIT(MIBSPI5TGITLVST,      0xFFF7FC7C,__READ_WRITE ,__spitgitlvst_bits);
__IO_REG32_BIT(MIBSPI5TGITLVCR,      0xFFF7FC80,__READ_WRITE ,__spitgitlvcr_bits);
__IO_REG32_BIT(MIBSPI5TGINTFLG,      0xFFF7FC84,__READ_WRITE ,__spitgintflg_bits);
__IO_REG32_BIT(MIBSPI5TICKCNT,       0xFFF7FC90,__READ_WRITE ,__spitickcnt_bits);
__IO_REG32_BIT(MIBSPI5LTGPEND,       0xFFF7FC94,__READ_WRITE ,__spiltgpend_bits);
__IO_REG32_BIT(MIBSPI5TG0CTRL,       0xFFF7FC98,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG1CTRL,       0xFFF7FC9C,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG2CTRL,       0xFFF7FCA0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG3CTRL,       0xFFF7FCA4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG4CTRL,       0xFFF7FCA8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG5CTRL,       0xFFF7FCAC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG6CTRL,       0xFFF7FCB0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG7CTRL,       0xFFF7FCB4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG8CTRL,       0xFFF7FCB8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG9CTRL,       0xFFF7FCBC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG10CTRL,      0xFFF7FCC0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG11CTRL,      0xFFF7FCC4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG12CTRL,      0xFFF7FCC8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG13CTRL,      0xFFF7FCCC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG14CTRL,      0xFFF7FCD0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5TG15CTRL,      0xFFF7FCD4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI5DMA0CTRL,      0xFFF7FCD8,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI5DMA1CTRL,      0xFFF7FCDC,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI5DMA2CTRL,      0xFFF7FCE0,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI5DMA3CTRL,      0xFFF7FCE4,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI5DMA4CTRL,      0xFFF7FCE8,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI5DMA5CTRL,      0xFFF7FCEC,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI5DMA6CTRL,      0xFFF7FCF0,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI5DMA7CTRL,      0xFFF7FCF4,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI5DMA0COUNT,     0xFFF7FCF8,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI5DMA1COUNT,     0xFFF7FCFC,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI5DMA2COUNT,     0xFFF7FD00,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI5DMA3COUNT,     0xFFF7FD04,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI5DMA4COUNT,     0xFFF7FD08,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI5DMA5COUNT,     0xFFF7FD0C,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI5DMA6COUNT,     0xFFF7FD10,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI5DMA7COUNT,     0xFFF7FD14,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI5DMACNTLEN,     0xFFF7FD18,__READ_WRITE ,__spidmacntlen_bits);
__IO_REG32_BIT(MIBSPI5UERRCTRL,      0xFFF7FD20,__READ_WRITE ,__spiuerrctrl_bits);
__IO_REG32_BIT(MIBSPI5UERRSTAT,      0xFFF7FD24,__READ_WRITE ,__spiuerrstat_bits);
__IO_REG32_BIT(MIBSPI5UERRADDR1,     0xFFF7FD28,__READ_WRITE ,__spiuerraddr1_bits);
__IO_REG32_BIT(MIBSPI5UERRADDR0,     0xFFF7FD2C,__READ_WRITE ,__spiuerraddr0_bits);
__IO_REG32_BIT(MIBSPI5RXOVRN_BUF_ADDR,0xFFF7FD30,__READ      ,__spirxovrn_buf_addr_bits);
__IO_REG32_BIT(MIBSPI5IOLPBKTSTCR,   0xFFF7FD34,__READ_WRITE ,__spiiolpbktstcr_bits);
__IO_REG32_BIT(MIBSPI5EXTENDED_PRESCALE1,  0xFFF7FD38,__READ_WRITE ,__spiextendedprescale1_bits);
__IO_REG32_BIT(MIBSPI5EXTENDED_PRESCALE2,  0xFFF7FD3C,__READ_WRITE ,__spiextendedprescale2_bits);
__IO_REG32(    MIBSPI5_TXBUF_BASE,   0xFF0A0000,__READ_WRITE );
__IO_REG32(    MIBSPI5_RXBUF_BASE,   0xFF0A0200,__READ_WRITE );

/***************************************************************************
 **
 ** MibSPI1 (Multi-Buffered Serial Peripheral Interface)
 **
 ***************************************************************************/
__IO_REG32_BIT(MIBSPI1GCR0,          0xFFF7F400,__READ_WRITE ,__spigcr0_bits);
__IO_REG32_BIT(MIBSPI1GCR1,          0xFFF7F404,__READ_WRITE ,__spigcr1_bits);
__IO_REG32_BIT(MIBSPI1INT0,          0xFFF7F408,__READ_WRITE ,__spiint0_bits);
__IO_REG32_BIT(MIBSPI1LVL,           0xFFF7F40C,__READ_WRITE ,__spilvl_bits);
__IO_REG32_BIT(MIBSPI1FLG,           0xFFF7F410,__READ_WRITE ,__mibspiflg_bits);
__IO_REG32_BIT(MIBSPI1PC0,           0xFFF7F414,__READ_WRITE ,__spipc0_bits);
__IO_REG32_BIT(MIBSPI1PC1,           0xFFF7F418,__READ_WRITE ,__spipc1_bits);
__IO_REG32_BIT(MIBSPI1PC2,           0xFFF7F41C,__READ       ,__spipc2_bits);
__IO_REG32_BIT(MIBSPI1PC3,           0xFFF7F420,__READ_WRITE ,__spipc3_bits);
__IO_REG32_BIT(MIBSPI1PC4,           0xFFF7F424,__READ_WRITE ,__spipc4_bits);
__IO_REG32_BIT(MIBSPI1PC5,           0xFFF7F428,__READ_WRITE ,__spipc5_bits);
__IO_REG32_BIT(MIBSPI1PC6,           0xFFF7F42C,__READ_WRITE ,__spipc6_bits);
__IO_REG32_BIT(MIBSPI1PC7,           0xFFF7F430,__READ_WRITE ,__spipc7_bits);
__IO_REG32_BIT(MIBSPI1PC8,           0xFFF7F434,__READ_WRITE ,__spipc8_bits);
__IO_REG32_BIT(MIBSPI1DAT0,          0xFFF7F438,__READ_WRITE ,__spidat0_bits);
__IO_REG32_BIT(MIBSPI1DAT1,          0xFFF7F43C,__READ_WRITE ,__spidat1_bits);
__IO_REG32_BIT(MIBSPI1BUF,           0xFFF7F440,__READ       ,__spibuf_bits);
__IO_REG32_BIT(MIBSPI1EMU,           0xFFF7F444,__READ       ,__spiemu_bits);
__IO_REG32_BIT(MIBSPI1DELAY,         0xFFF7F448,__READ_WRITE ,__spidelay_bits);
__IO_REG32_BIT(MIBSPI1DEF,           0xFFF7F44C,__READ_WRITE ,__spidef_bits);
__IO_REG32_BIT(MIBSPI1FMT0,          0xFFF7F450,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI1FMT1,          0xFFF7F454,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI1FMT2,          0xFFF7F458,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI1FMT3,          0xFFF7F45C,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI1INTVECT0,      0xFFF7F460,__READ       ,__spiintvect0_bits);
__IO_REG32_BIT(MIBSPI1INTVECT1,      0xFFF7F464,__READ       ,__spiintvect1_bits);
__IO_REG32_BIT(MIBSPI1MIBSPIE,       0xFFF7F470,__READ_WRITE ,__spimibspie_bits);
__IO_REG32_BIT(MIBSPI1TGITENST,      0xFFF7F474,__READ_WRITE ,__spitgitenst_bits);
__IO_REG32_BIT(MIBSPI1TGITENCR,      0xFFF7F478,__READ_WRITE ,__spitgitencr_bits);
__IO_REG32_BIT(MIBSPI1TGITLVST,      0xFFF7F47C,__READ_WRITE ,__spitgitlvst_bits);
__IO_REG32_BIT(MIBSPI1TGITLVCR,      0xFFF7F480,__READ_WRITE ,__spitgitlvcr_bits);
__IO_REG32_BIT(MIBSPI1TGINTFLG,      0xFFF7F484,__READ_WRITE ,__spitgintflg_bits);
__IO_REG32_BIT(MIBSPI1TICKCNT,       0xFFF7F490,__READ_WRITE ,__spitickcnt_bits);
__IO_REG32_BIT(MIBSPI1LTGPEND,       0xFFF7F494,__READ_WRITE ,__spiltgpend_bits);
__IO_REG32_BIT(MIBSPI1TG0CTRL,       0xFFF7F498,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG1CTRL,       0xFFF7F49C,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG2CTRL,       0xFFF7F4A0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG3CTRL,       0xFFF7F4A4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG4CTRL,       0xFFF7F4A8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG5CTRL,       0xFFF7F4AC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG6CTRL,       0xFFF7F4B0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG7CTRL,       0xFFF7F4B4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG8CTRL,       0xFFF7F4B8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG9CTRL,       0xFFF7F4BC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG10CTRL,      0xFFF7F4C0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG11CTRL,      0xFFF7F4C4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG12CTRL,      0xFFF7F4C8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG13CTRL,      0xFFF7F4CC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG14CTRL,      0xFFF7F4D0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1TG15CTRL,      0xFFF7F4D4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI1DMA0CTRL,      0xFFF7F4D8,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI1DMA1CTRL,      0xFFF7F4DC,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI1DMA2CTRL,      0xFFF7F4E0,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI1DMA3CTRL,      0xFFF7F4E4,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI1DMA4CTRL,      0xFFF7F4E8,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI1DMA5CTRL,      0xFFF7F4EC,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI1DMA6CTRL,      0xFFF7F4F0,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI1DMA7CTRL,      0xFFF7F4F4,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI1DMA0COUNT,     0xFFF7F4F8,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI1DMA1COUNT,     0xFFF7F4FC,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI1DMA2COUNT,     0xFFF7F500,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI1DMA3COUNT,     0xFFF7F504,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI1DMA4COUNT,     0xFFF7F508,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI1DMA5COUNT,     0xFFF7F50C,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI1DMA6COUNT,     0xFFF7F510,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI1DMA7COUNT,     0xFFF7F514,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI1DMACNTLEN,     0xFFF7F518,__READ_WRITE ,__spidmacntlen_bits);
__IO_REG32_BIT(MIBSPI1UERRCTRL,      0xFFF7F520,__READ_WRITE ,__spiuerrctrl_bits);
__IO_REG32_BIT(MIBSPI1UERRSTAT,      0xFFF7F524,__READ_WRITE ,__spiuerrstat_bits);
__IO_REG32_BIT(MIBSPI1UERRADDR1,     0xFFF7F528,__READ_WRITE ,__spiuerraddr1_bits);
__IO_REG32_BIT(MIBSPI1UERRADDR0,     0xFFF7F52C,__READ_WRITE ,__spiuerraddr0_bits);
__IO_REG32_BIT(MIBSPI1RXOVRN_BUF_ADDR,0xFFF7F530,__READ      ,__spirxovrn_buf_addr_bits);
__IO_REG32_BIT(MIBSPI1IOLPBKTSTCR,   0xFFF7F534,__READ_WRITE ,__spiiolpbktstcr_bits);
__IO_REG32_BIT(MIBSPI1EXTENDED_PRESCALE1,  0xFFF7F538,__READ_WRITE ,__spiextendedprescale1_bits);
__IO_REG32_BIT(MIBSPI1EXTENDED_PRESCALE2,  0xFFF7F53C,__READ_WRITE ,__spiextendedprescale2_bits);
__IO_REG32(    MIBSPI1_TXBUF_BASE,   0xFF0E0000,__READ_WRITE );
__IO_REG32(    MIBSPI1_RXBUF_BASE,   0xFF0E0200,__READ_WRITE );

/***************************************************************************
 **
 ** MibSPI3 (Multi-Buffered Serial Peripheral Interface)
 **
 ***************************************************************************/
__IO_REG32_BIT(MIBSPI3GCR0,          0xFFF7F800,__READ_WRITE ,__spigcr0_bits);
__IO_REG32_BIT(MIBSPI3GCR1,          0xFFF7F804,__READ_WRITE ,__spigcr1_bits);
__IO_REG32_BIT(MIBSPI3INT0,          0xFFF7F808,__READ_WRITE ,__spiint0_bits);
__IO_REG32_BIT(MIBSPI3LVL,           0xFFF7F80C,__READ_WRITE ,__spilvl_bits);
__IO_REG32_BIT(MIBSPI3FLG,           0xFFF7F810,__READ_WRITE ,__mibspiflg_bits);
__IO_REG32_BIT(MIBSPI3PC0,           0xFFF7F814,__READ_WRITE ,__spipc0_bits);
__IO_REG32_BIT(MIBSPI3PC1,           0xFFF7F818,__READ_WRITE ,__spipc1_bits);
__IO_REG32_BIT(MIBSPI3PC2,           0xFFF7F81C,__READ       ,__spipc2_bits);
__IO_REG32_BIT(MIBSPI3PC3,           0xFFF7F820,__READ_WRITE ,__spipc3_bits);
__IO_REG32_BIT(MIBSPI3PC4,           0xFFF7F824,__READ_WRITE ,__spipc4_bits);
__IO_REG32_BIT(MIBSPI3PC5,           0xFFF7F828,__READ_WRITE ,__spipc5_bits);
__IO_REG32_BIT(MIBSPI3PC6,           0xFFF7F82C,__READ_WRITE ,__spipc6_bits);
__IO_REG32_BIT(MIBSPI3PC7,           0xFFF7F830,__READ_WRITE ,__spipc7_bits);
__IO_REG32_BIT(MIBSPI3PC8,           0xFFF7F834,__READ_WRITE ,__spipc8_bits);
__IO_REG32_BIT(MIBSPI3DAT0,          0xFFF7F838,__READ_WRITE ,__spidat0_bits);
__IO_REG32_BIT(MIBSPI3DAT1,          0xFFF7F83C,__READ_WRITE ,__spidat1_bits);
__IO_REG32_BIT(MIBSPI3BUF,           0xFFF7F840,__READ       ,__spibuf_bits);
__IO_REG32_BIT(MIBSPI3EMU,           0xFFF7F844,__READ       ,__spiemu_bits);
__IO_REG32_BIT(MIBSPI3DELAY,         0xFFF7F848,__READ_WRITE ,__spidelay_bits);
__IO_REG32_BIT(MIBSPI3DEF,           0xFFF7F84C,__READ_WRITE ,__spidef_bits);
__IO_REG32_BIT(MIBSPI3FMT0,          0xFFF7F850,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI3FMT1,          0xFFF7F854,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI3FMT2,          0xFFF7F858,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI3FMT3,          0xFFF7F85C,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(MIBSPI3INTVECT0,      0xFFF7F860,__READ       ,__spiintvect0_bits);
__IO_REG32_BIT(MIBSPI3INTVECT1,      0xFFF7F864,__READ       ,__spiintvect1_bits);
__IO_REG32_BIT(MIBSPI3MIBSPIE,       0xFFF7F870,__READ_WRITE ,__spimibspie_bits);
__IO_REG32_BIT(MIBSPI3TGITENST,      0xFFF7F874,__READ_WRITE ,__spitgitenst_bits);
__IO_REG32_BIT(MIBSPI3TGITENCR,      0xFFF7F878,__READ_WRITE ,__spitgitencr_bits);
__IO_REG32_BIT(MIBSPI3TGITLVST,      0xFFF7F87C,__READ_WRITE ,__spitgitlvst_bits);
__IO_REG32_BIT(MIBSPI3TGITLVCR,      0xFFF7F880,__READ_WRITE ,__spitgitlvcr_bits);
__IO_REG32_BIT(MIBSPI3TGINTFLG,      0xFFF7F884,__READ_WRITE ,__spitgintflg_bits);
__IO_REG32_BIT(MIBSPI3TICKCNT,       0xFFF7F890,__READ_WRITE ,__spitickcnt_bits);
__IO_REG32_BIT(MIBSPI3LTGPEND,       0xFFF7F894,__READ_WRITE ,__spiltgpend_bits);
__IO_REG32_BIT(MIBSPI3TG0CTRL,       0xFFF7F898,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG1CTRL,       0xFFF7F89C,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG2CTRL,       0xFFF7F8A0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG3CTRL,       0xFFF7F8A4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG4CTRL,       0xFFF7F8A8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG5CTRL,       0xFFF7F8AC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG6CTRL,       0xFFF7F8B0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG7CTRL,       0xFFF7F8B4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG8CTRL,       0xFFF7F8B8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG9CTRL,       0xFFF7F8BC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG10CTRL,      0xFFF7F8C0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG11CTRL,      0xFFF7F8C4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG12CTRL,      0xFFF7F8C8,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG13CTRL,      0xFFF7F8CC,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG14CTRL,      0xFFF7F8D0,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3TG15CTRL,      0xFFF7F8D4,__READ_WRITE ,__spitgctrl_bits);
__IO_REG32_BIT(MIBSPI3DMA0CTRL,      0xFFF7F8D8,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI3DMA1CTRL,      0xFFF7F8DC,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI3DMA2CTRL,      0xFFF7F8E0,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI3DMA3CTRL,      0xFFF7F8E4,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI3DMA4CTRL,      0xFFF7F8E8,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI3DMA5CTRL,      0xFFF7F8EC,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI3DMA6CTRL,      0xFFF7F8F0,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI3DMA7CTRL,      0xFFF7F8F4,__READ_WRITE ,__spidmactrl_bits);
__IO_REG32_BIT(MIBSPI3DMA0COUNT,     0xFFF7F8F8,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI3DMA1COUNT,     0xFFF7F8FC,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI3DMA2COUNT,     0xFFF7F900,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI3DMA3COUNT,     0xFFF7F904,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI3DMA4COUNT,     0xFFF7F908,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI3DMA5COUNT,     0xFFF7F90C,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI3DMA6COUNT,     0xFFF7F910,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI3DMA7COUNT,     0xFFF7F914,__READ_WRITE ,__spidmacount_bits);
__IO_REG32_BIT(MIBSPI3DMACNTLEN,     0xFFF7F918,__READ_WRITE ,__spidmacntlen_bits);
__IO_REG32_BIT(MIBSPI3UERRCTRL,      0xFFF7F920,__READ_WRITE ,__spiuerrctrl_bits);
__IO_REG32_BIT(MIBSPI3UERRSTAT,      0xFFF7F924,__READ_WRITE ,__spiuerrstat_bits);
__IO_REG32_BIT(MIBSPI3UERRADDR1,     0xFFF7F928,__READ_WRITE ,__spiuerraddr1_bits);
__IO_REG32_BIT(MIBSPI3UERRADDR0,     0xFFF7F92C,__READ_WRITE ,__spiuerraddr0_bits);
__IO_REG32_BIT(MIBSPI3RXOVRN_BUF_ADDR,0xFFF7F930,__READ      ,__spirxovrn_buf_addr_bits);
__IO_REG32_BIT(MIBSPI3IOLPBKTSTCR,   0xFFF7F934,__READ_WRITE ,__spiiolpbktstcr_bits);
__IO_REG32_BIT(MIBSPI3EXTENDED_PRESCALE1,  0xFFF7F938,__READ_WRITE ,__spiextendedprescale1_bits);
__IO_REG32_BIT(MIBSPI3EXTENDED_PRESCALE2,  0xFFF7F93C,__READ_WRITE ,__spiextendedprescale2_bits);
__IO_REG32(    MIBSPI3_TXBUF_BASE,   0xFF0C0000,__READ_WRITE );
__IO_REG32(    MIBSPI3_RXBUF_BASE,   0xFF0C0200,__READ_WRITE );

/***************************************************************************
 **
 ** SPI2
 **
 ***************************************************************************/
__IO_REG32_BIT(SPI2GCR0,          0xFFF7F600,__READ_WRITE ,__spigcr0_bits);
__IO_REG32_BIT(SPI2GCR1,          0xFFF7F604,__READ_WRITE ,__spigcr1_bits);
__IO_REG32_BIT(SPI2INT0,          0xFFF7F608,__READ_WRITE ,__spiint0_bits);
__IO_REG32_BIT(SPI2LVL,           0xFFF7F60C,__READ_WRITE ,__spilvl_bits);
__IO_REG32_BIT(SPI2FLG,           0xFFF7F610,__READ_WRITE ,__spiflg_bits);
__IO_REG32_BIT(SPI2PC0,           0xFFF7F614,__READ_WRITE ,__spipc0_bits);
__IO_REG32_BIT(SPI2PC1,           0xFFF7F618,__READ_WRITE ,__spipc1_bits);
__IO_REG32_BIT(SPI2PC2,           0xFFF7F61C,__READ       ,__spipc2_bits);
__IO_REG32_BIT(SPI2PC3,           0xFFF7F620,__READ_WRITE ,__spipc3_bits);
__IO_REG32_BIT(SPI2PC4,           0xFFF7F624,__READ_WRITE ,__spipc4_bits);
__IO_REG32_BIT(SPI2PC5,           0xFFF7F628,__READ_WRITE ,__spipc5_bits);
__IO_REG32_BIT(SPI2PC6,           0xFFF7F62C,__READ_WRITE ,__spipc6_bits);
__IO_REG32_BIT(SPI2PC7,           0xFFF7F630,__READ_WRITE ,__spipc7_bits);
__IO_REG32_BIT(SPI2PC8,           0xFFF7F634,__READ_WRITE ,__spipc8_bits);
__IO_REG32_BIT(SPI2DAT0,          0xFFF7F638,__READ_WRITE ,__spidat0_bits);
__IO_REG32_BIT(SPI2DAT1,          0xFFF7F63C,__READ_WRITE ,__spidat1_bits);
__IO_REG32_BIT(SPI2BUF,           0xFFF7F640,__READ       ,__spibuf_bits);
__IO_REG32_BIT(SPI2EMU,           0xFFF7F644,__READ       ,__spiemu_bits);
__IO_REG32_BIT(SPI2DELAY,         0xFFF7F648,__READ_WRITE ,__spidelay_bits);
__IO_REG32_BIT(SPI2DEF,           0xFFF7F64C,__READ_WRITE ,__spidef_bits);
__IO_REG32_BIT(SPI2FMT0,          0xFFF7F650,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(SPI2FMT1,          0xFFF7F654,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(SPI2FMT2,          0xFFF7F658,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(SPI2FMT3,          0xFFF7F65C,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(SPI2IOLPBKTSTCR,   0xFFF7F734,__READ_WRITE ,__spiiolpbktstcr_bits);
__IO_REG32_BIT(SPI2EXTENDED_PRESCALE1,  0xFFF7F738,__READ_WRITE ,__spiextendedprescale1_bits);
__IO_REG32_BIT(SPI2EXTENDED_PRESCALE2,  0xFFF7F73C,__READ_WRITE ,__spiextendedprescale2_bits);

/***************************************************************************
 **
 ** SPI4
 **
 ***************************************************************************/
__IO_REG32_BIT(SPI4GCR0,          0xFFF7FA00,__READ_WRITE ,__spigcr0_bits);
__IO_REG32_BIT(SPI4GCR1,          0xFFF7FA04,__READ_WRITE ,__spigcr1_bits);
__IO_REG32_BIT(SPI4INT0,          0xFFF7FA08,__READ_WRITE ,__spiint0_bits);
__IO_REG32_BIT(SPI4LVL,           0xFFF7FA0C,__READ_WRITE ,__spilvl_bits);
__IO_REG32_BIT(SPI4FLG,           0xFFF7FA10,__READ_WRITE ,__spiflg_bits);
__IO_REG32_BIT(SPI4PC0,           0xFFF7FA14,__READ_WRITE ,__spipc0_bits);
__IO_REG32_BIT(SPI4PC1,           0xFFF7FA18,__READ_WRITE ,__spipc1_bits);
__IO_REG32_BIT(SPI4PC2,           0xFFF7FA1C,__READ       ,__spipc2_bits);
__IO_REG32_BIT(SPI4PC3,           0xFFF7FA20,__READ_WRITE ,__spipc3_bits);
__IO_REG32_BIT(SPI4PC4,           0xFFF7FA24,__READ_WRITE ,__spipc4_bits);
__IO_REG32_BIT(SPI4PC5,           0xFFF7FA28,__READ_WRITE ,__spipc5_bits);
__IO_REG32_BIT(SPI4PC6,           0xFFF7FA2C,__READ_WRITE ,__spipc6_bits);
__IO_REG32_BIT(SPI4PC7,           0xFFF7FA30,__READ_WRITE ,__spipc7_bits);
__IO_REG32_BIT(SPI4PC8,           0xFFF7FA34,__READ_WRITE ,__spipc8_bits);
__IO_REG32_BIT(SPI4DAT0,          0xFFF7FA38,__READ_WRITE ,__spidat0_bits);
__IO_REG32_BIT(SPI4DAT1,          0xFFF7FA3C,__READ_WRITE ,__spidat1_bits);
__IO_REG32_BIT(SPI4BUF,           0xFFF7FA40,__READ       ,__spibuf_bits);
__IO_REG32_BIT(SPI4EMU,           0xFFF7FA44,__READ       ,__spiemu_bits);
__IO_REG32_BIT(SPI4DELAY,         0xFFF7FA48,__READ_WRITE ,__spidelay_bits);
__IO_REG32_BIT(SPI4DEF,           0xFFF7FA4C,__READ_WRITE ,__spidef_bits);
__IO_REG32_BIT(SPI4FMT0,          0xFFF7FA50,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(SPI4FMT1,          0xFFF7FA54,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(SPI4FMT2,          0xFFF7FA58,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(SPI4FMT3,          0xFFF7FA5C,__READ_WRITE ,__spifmt_bits);
__IO_REG32_BIT(SPI4IOLPBKTSTCR,   0xFFF7FB34,__READ_WRITE ,__spiiolpbktstcr_bits);
__IO_REG32_BIT(SPI4EXTENDED_PRESCALE1,  0xFFF7FB38,__READ_WRITE ,__spiextendedprescale1_bits);
__IO_REG32_BIT(SPI4EXTENDED_PRESCALE2,  0xFFF7FB3C,__READ_WRITE ,__spiextendedprescale2_bits);

/***************************************************************************
 **
 ** MIBADC1 (Analog To Digital Converter)
 **
 ***************************************************************************/
__IO_REG32_BIT(AD1RSTCR,          0xFFF7C000,__READ_WRITE ,__adrstcr_bits);
__IO_REG32_BIT(AD1OPMODECR,       0xFFF7C004,__READ_WRITE ,__adopmodecr_bits);
__IO_REG32_BIT(AD1CLOCKCR,        0xFFF7C008,__READ_WRITE ,__adclockcr_bits);
__IO_REG32_BIT(AD1CALCR,          0xFFF7C00C,__READ_WRITE ,__adcalcr_bits);
__IO_REG32_BIT(AD1EVMODECR,       0xFFF7C010,__READ_WRITE ,__adevmodecr_bits);
__IO_REG32_BIT(AD1G1MODECR,       0xFFF7C014,__READ_WRITE ,__adg1modecr_bits);
__IO_REG32_BIT(AD1G2MODECR,       0xFFF7C018,__READ_WRITE ,__adg2modecr_bits);
__IO_REG32_BIT(AD1EVSRC,          0xFFF7C01C,__READ_WRITE ,__adevsrc_bits);
__IO_REG32_BIT(AD1G1SRC,          0xFFF7C020,__READ_WRITE ,__adg1src_bits);
__IO_REG32_BIT(AD1G2SRC,          0xFFF7C024,__READ_WRITE ,__adg2src_bits);
__IO_REG32_BIT(AD1EVINTENA,       0xFFF7C028,__READ_WRITE ,__adevintena_bits);
__IO_REG32_BIT(AD1G1INTENA,       0xFFF7C02C,__READ_WRITE ,__adg1intena_bits);
__IO_REG32_BIT(AD1G2INTENA,       0xFFF7C030,__READ_WRITE ,__adg2intena_bits);
__IO_REG32_BIT(AD1EVINTFLG,       0xFFF7C034,__READ       ,__adevintflg_bits);
__IO_REG32_BIT(AD1G1INTFLG,       0xFFF7C038,__READ       ,__adg1intflg_bits);
__IO_REG32_BIT(AD1G2INTFLG,       0xFFF7C03C,__READ       ,__adg2intflg_bits);
__IO_REG32_BIT(AD1EVTHRINTCR,     0xFFF7C040,__READ_WRITE ,__adevthrintcr_bits);
__IO_REG32_BIT(AD1G1THRINTCR,     0xFFF7C044,__READ_WRITE ,__adg1thrintcr_bits);
__IO_REG32_BIT(AD1G2THRINTCR,     0xFFF7C048,__READ_WRITE ,__adg2thrintcr_bits);
__IO_REG32_BIT(AD1EVDMACR,        0xFFF7C04C,__READ_WRITE ,__adevdmacr_bits);
__IO_REG32_BIT(AD1G1DMACR,        0xFFF7C050,__READ_WRITE ,__adg1dmacr_bits);
__IO_REG32_BIT(AD1G2DMACR,        0xFFF7C054,__READ_WRITE ,__adg2dmacr_bits);
__IO_REG32_BIT(AD1BNDCR,          0xFFF7C058,__READ_WRITE ,__adbndcr_bits);
__IO_REG32_BIT(AD1BNDEND,         0xFFF7C05C,__READ_WRITE ,__adbndend_bits);
__IO_REG32_BIT(AD1EVSAMP,         0xFFF7C060,__READ_WRITE ,__adevsamp_bits);
__IO_REG32_BIT(AD1G1SAMP,         0xFFF7C064,__READ_WRITE ,__adg1samp_bits);
__IO_REG32_BIT(AD1G2SAMP,         0xFFF7C068,__READ_WRITE ,__adg2samp_bits);
__IO_REG32_BIT(AD1EVSR,           0xFFF7C06C,__READ       ,__adevsr_bits);
__IO_REG32_BIT(AD1G1SR,           0xFFF7C070,__READ       ,__adg1sr_bits);
__IO_REG32_BIT(AD1G2SR,           0xFFF7C074,__READ       ,__adg2sr_bits);
__IO_REG32_BIT(AD1EVSEL,          0xFFF7C078,__READ_WRITE ,__adevsel_bits);
__IO_REG32_BIT(AD1G1SEL,          0xFFF7C07C,__READ_WRITE ,__adg1sel_bits);
__IO_REG32_BIT(AD1G2SEL,          0xFFF7C080,__READ_WRITE ,__adg2sel_bits);
__IO_REG32_BIT(AD1CALR,           0xFFF7C084,__READ_WRITE ,__adcalr_bits);
__IO_REG32_BIT(AD1SMSTATE,        0xFFF7C088,__READ       ,__adsmstate_bits);
__IO_REG32_BIT(AD1LASTCONV,       0xFFF7C08C,__READ       ,__adlastconv_bits);
__IO_REG32_BIT(AD1EVBUFFER0,      0xFFF7C090,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVBUFFER0_10       AD1EVBUFFER0
#define AD1EVBUFFER0_10_bit   AD1EVBUFFER0_bit
__IO_REG32_BIT(AD1EVBUFFER1,      0xFFF7C094,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVBUFFER1_10       AD1EVBUFFER1
#define AD1EVBUFFER1_10_bit   AD1EVBUFFER1_bit
__IO_REG32_BIT(AD1EVBUFFER2,      0xFFF7C098,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVBUFFER2_10       AD1EVBUFFER2
#define AD1EVBUFFER2_10_bit   AD1EVBUFFER2_bit
__IO_REG32_BIT(AD1EVBUFFER3,      0xFFF7C09C,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVBUFFER3_10       AD1EVBUFFER3
#define AD1EVBUFFER3_10_bit   AD1EVBUFFER3_bit
__IO_REG32_BIT(AD1EVBUFFER4,      0xFFF7C0A0,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVBUFFER4_10       AD1EVBUFFER4
#define AD1EVBUFFER4_10_bit   AD1EVBUFFER4_bit
__IO_REG32_BIT(AD1EVBUFFER5,      0xFFF7C0A4,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVBUFFER5_10       AD1EVBUFFER5
#define AD1EVBUFFER5_10_bit   AD1EVBUFFER5_bit
__IO_REG32_BIT(AD1EVBUFFER6,      0xFFF7C0A8,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVBUFFER6_10       AD1EVBUFFER6
#define AD1EVBUFFER6_10_bit   AD1EVBUFFER6_bit
__IO_REG32_BIT(AD1EVBUFFER7,      0xFFF7C0AC,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVBUFFER7_10       AD1EVBUFFER7
#define AD1EVBUFFER7_10_bit   AD1EVBUFFER7_bit
__IO_REG32_BIT(AD1G1BUFFER0,      0xFFF7C0B0,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1BUFFER0_10       AD1G1BUFFER0
#define AD1G1BUFFER0_10_bit   AD1G1BUFFER0_bit
__IO_REG32_BIT(AD1G1BUFFER1,      0xFFF7C0B4,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1BUFFER1_10       AD1G1BUFFER1
#define AD1G1BUFFER1_10_bit   AD1G1BUFFER1_bit
__IO_REG32_BIT(AD1G1BUFFER2,      0xFFF7C0B8,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1BUFFER2_10       AD1G1BUFFER2
#define AD1G1BUFFER2_10_bit   AD1G1BUFFER2_bit
__IO_REG32_BIT(AD1G1BUFFER3,      0xFFF7C0BC,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1BUFFER3_10       AD1G1BUFFER3
#define AD1G1BUFFER3_10_bit   AD1G1BUFFER3_bit
__IO_REG32_BIT(AD1G1BUFFER4,      0xFFF7C0C0,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1BUFFER4_10       AD1G1BUFFER4
#define AD1G1BUFFER4_10_bit   AD1G1BUFFER4_bit
__IO_REG32_BIT(AD1G1BUFFER5,      0xFFF7C0C4,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1BUFFER5_10       AD1G1BUFFER5
#define AD1G1BUFFER5_10_bit   AD1G1BUFFER5_bit
__IO_REG32_BIT(AD1G1BUFFER6,      0xFFF7C0C8,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1BUFFER6_10       AD1G1BUFFER6
#define AD1G1BUFFER6_10_bit   AD1G1BUFFER6_bit
__IO_REG32_BIT(AD1G1BUFFER7,      0xFFF7C0CC,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1BUFFER7_10       AD1G1BUFFER7
#define AD1G1BUFFER7_10_bit   AD1G1BUFFER7_bit
__IO_REG32_BIT(AD1G2BUFFER0,      0xFFF7C0D0,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2BUFFER0_10       AD1G2BUFFER0
#define AD1G2BUFFER0_10_bit   AD1G2BUFFER0_bit
__IO_REG32_BIT(AD1G2BUFFER1,      0xFFF7C0D4,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2BUFFER1_10       AD1G2BUFFER1
#define AD1G2BUFFER1_10_bit   AD1G2BUFFER1_bit
__IO_REG32_BIT(AD1G2BUFFER2,      0xFFF7C0D8,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2BUFFER2_10       AD1G2BUFFER2
#define AD1G2BUFFER2_10_bit   AD1G2BUFFER2_bit
__IO_REG32_BIT(AD1G2BUFFER3,      0xFFF7C0DC,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2BUFFER3_10       AD1G2BUFFER3
#define AD1G2BUFFER3_10_bit   AD1G2BUFFER3_bit
__IO_REG32_BIT(AD1G2BUFFER4,      0xFFF7C0E0,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2BUFFER4_10       AD1G2BUFFER4
#define AD1G2BUFFER4_10_bit   AD1G2BUFFER4_bit
__IO_REG32_BIT(AD1G2BUFFER5,      0xFFF7C0E4,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2BUFFER5_10       AD1G2BUFFER5
#define AD1G2BUFFER5_10_bit   AD1G2BUFFER5_bit
__IO_REG32_BIT(AD1G2BUFFER6,      0xFFF7C0E8,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2BUFFER6_10       AD1G2BUFFER6
#define AD1G2BUFFER6_10_bit   AD1G2BUFFER6_bit
__IO_REG32_BIT(AD1G2BUFFER7,      0xFFF7C0EC,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2BUFFER7_10       AD1G2BUFFER7
#define AD1G2BUFFER7_10_bit   AD1G2BUFFER7_bit
__IO_REG32_BIT(AD1EVEMUBUFFER,    0xFFF7C0F0,__READ_WRITE ,__adevbuffer_bits);
#define AD1EVEMUBUFFER_10       AD1EVEMUBUFFER
#define AD1EVEMUBUFFER_10_bit   AD1EVEMUBUFFER_bit
__IO_REG32_BIT(AD1G1EMUBUFFER,    0xFFF7C0F4,__READ_WRITE ,__adg1buffer_bits);
#define AD1G1EMUBUFFER_10       AD1G1EMUBUFFER
#define AD1G1EMUBUFFER_10_bit   AD1G1EMUBUFFER_bit
__IO_REG32_BIT(AD1G2EMUBUFFER,    0xFFF7C0F8,__READ_WRITE ,__adg2buffer_bits);
#define AD1G2EMUBUFFER_10       AD1G2EMUBUFFER
#define AD1G2EMUBUFFER_10_bit   AD1G2EMUBUFFER_bit
__IO_REG32_BIT(AD1EVTDIR,         0xFFF7C0FC,__READ_WRITE ,__adevtdir_bits);
__IO_REG32_BIT(AD1EVTOUT,         0xFFF7C100,__READ_WRITE ,__adevtout_bits);
__IO_REG32_BIT(AD1EVTIN,          0xFFF7C104,__READ       ,__adevtin_bits);
__IO_REG32_BIT(AD1EVTSET,         0xFFF7C108,__READ_WRITE ,__adevtset_bits);
__IO_REG32_BIT(AD1EVTCLR,         0xFFF7C10C,__READ_WRITE ,__adevtclr_bits);
__IO_REG32_BIT(AD1EVTPDR,         0xFFF7C110,__READ_WRITE ,__adevtpdr_bits);
__IO_REG32_BIT(AD1EVTPDIS,        0xFFF7C114,__READ_WRITE ,__adevtpdis_bits);
__IO_REG32_BIT(AD1EVTPSEL,        0xFFF7C118,__READ_WRITE ,__adevtpsel_bits);
__IO_REG32_BIT(AD1EVSAMPDISEN,    0xFFF7C11C,__READ_WRITE ,__adevsampdisen_bits);
__IO_REG32_BIT(AD1G1SAMPDISEN,    0xFFF7C120,__READ_WRITE ,__adg1sampdisen_bits);
__IO_REG32_BIT(AD1G2SAMPDISEN,    0xFFF7C124,__READ_WRITE ,__adg2sampdisen_bits);
__IO_REG32_BIT(AD1MAGINT1CR,      0xFFF7C128,__READ_WRITE ,__admagintcr_bits);
__IO_REG32_BIT(AD1MAGINT1MASK,    0xFFF7C12C,__READ_WRITE ,__admagintmask_bits);
__IO_REG32_BIT(AD1MAGINT2CR,      0xFFF7C130,__READ_WRITE ,__admagintcr_bits);
__IO_REG32_BIT(AD1MAGINT2MASK,    0xFFF7C134,__READ_WRITE ,__admagintmask_bits);
__IO_REG32_BIT(AD1MAGINT3CR,      0xFFF7C138,__READ_WRITE ,__admagintcr_bits);
__IO_REG32_BIT(AD1MAGINT3MASK,    0xFFF7C13C,__READ_WRITE ,__admagintmask_bits);
__IO_REG32_BIT(AD1MAGINTENASET,   0xFFF7C158,__READ_WRITE ,__admagintenaset_bits);
__IO_REG32_BIT(AD1MAGINTENACLR,   0xFFF7C15C,__READ_WRITE ,__admagintenaclr_bits);
__IO_REG32_BIT(AD1MAGINTFLG,      0xFFF7C160,__READ_WRITE ,__admagintflg_bits);
__IO_REG32_BIT(AD1MAGINTOFF,      0xFFF7C164,__READ       ,__admagintoff_bits);
__IO_REG32_BIT(AD1EVFIFORESETCR,  0xFFF7C168,__READ_WRITE ,__adevfiforesetcr_bits);
__IO_REG32_BIT(AD1G1FIFORESETCR,  0xFFF7C16C,__READ_WRITE ,__adg1fiforesetcr_bits);
__IO_REG32_BIT(AD1G2FIFORESETCR,  0xFFF7C170,__READ_WRITE ,__adg2fiforesetcr_bits);
__IO_REG32_BIT(AD1EVRAMWRADDR,    0xFFF7C174,__READ       ,__adevramwraddr_bits);
__IO_REG32_BIT(AD1G1RAMWRADDR,    0xFFF7C178,__READ       ,__adg1ramwraddr_bits);
__IO_REG32_BIT(AD1G2RAMWRADDR,    0xFFF7C17C,__READ       ,__adg2ramwraddr_bits);
__IO_REG32_BIT(AD1PARCR,          0xFFF7C180,__READ_WRITE ,__adparcr_bits);
__IO_REG32_BIT(AD1PARADDR,        0xFFF7C184,__READ       ,__adparaddr_bits);
__IO_REG32_BIT(AD1PWRUPDLYCTRL,   0xFFF7C188,__READ_WRITE ,__adpwrupdlyctrl_bits);
__IO_REG32(    AD1BUFER_BASE,     0xFF3E0000,__READ_WRITE );

/***************************************************************************
 **
 ** MIBADC2 (Analog To Digital Converter)
 **
 ***************************************************************************/
__IO_REG32_BIT(AD2RSTCR,          0xFFF7C200,__READ_WRITE ,__adrstcr_bits);
__IO_REG32_BIT(AD2OPMODECR,       0xFFF7C204,__READ_WRITE ,__adopmodecr_bits);
__IO_REG32_BIT(AD2CLOCKCR,        0xFFF7C208,__READ_WRITE ,__adclockcr_bits);
__IO_REG32_BIT(AD2CALCR,          0xFFF7C20C,__READ_WRITE ,__adcalcr_bits);
__IO_REG32_BIT(AD2EVMODECR,       0xFFF7C210,__READ_WRITE ,__adevmodecr_bits);
__IO_REG32_BIT(AD2G1MODECR,       0xFFF7C214,__READ_WRITE ,__adg1modecr_bits);
__IO_REG32_BIT(AD2G2MODECR,       0xFFF7C218,__READ_WRITE ,__adg2modecr_bits);
__IO_REG32_BIT(AD2EVSRC,          0xFFF7C21C,__READ_WRITE ,__adevsrc_bits);
__IO_REG32_BIT(AD2G1SRC,          0xFFF7C220,__READ_WRITE ,__adg1src_bits);
__IO_REG32_BIT(AD2G2SRC,          0xFFF7C224,__READ_WRITE ,__adg2src_bits);
__IO_REG32_BIT(AD2EVINTENA,       0xFFF7C228,__READ_WRITE ,__adevintena_bits);
__IO_REG32_BIT(AD2G1INTENA,       0xFFF7C22C,__READ_WRITE ,__adg1intena_bits);
__IO_REG32_BIT(AD2G2INTENA,       0xFFF7C230,__READ_WRITE ,__adg2intena_bits);
__IO_REG32_BIT(AD2EVINTFLG,       0xFFF7C234,__READ       ,__adevintflg_bits);
__IO_REG32_BIT(AD2G1INTFLG,       0xFFF7C238,__READ       ,__adg1intflg_bits);
__IO_REG32_BIT(AD2G2INTFLG,       0xFFF7C23C,__READ       ,__adg2intflg_bits);
__IO_REG32_BIT(AD2EVTHRINTCR,     0xFFF7C240,__READ_WRITE ,__adevthrintcr_bits);
__IO_REG32_BIT(AD2G1THRINTCR,     0xFFF7C244,__READ_WRITE ,__adg1thrintcr_bits);
__IO_REG32_BIT(AD2G2THRINTCR,     0xFFF7C248,__READ_WRITE ,__adg2thrintcr_bits);
__IO_REG32_BIT(AD2EVDMACR,        0xFFF7C24C,__READ_WRITE ,__adevdmacr_bits);
__IO_REG32_BIT(AD2G1DMACR,        0xFFF7C250,__READ_WRITE ,__adg1dmacr_bits);
__IO_REG32_BIT(AD2G2DMACR,        0xFFF7C254,__READ_WRITE ,__adg2dmacr_bits);
__IO_REG32_BIT(AD2BNDCR,          0xFFF7C258,__READ_WRITE ,__adbndcr_bits);
__IO_REG32_BIT(AD2BNDEND,         0xFFF7C25C,__READ_WRITE ,__adbndend_bits);
__IO_REG32_BIT(AD2EVSAMP,         0xFFF7C260,__READ_WRITE ,__adevsamp_bits);
__IO_REG32_BIT(AD2G1SAMP,         0xFFF7C264,__READ_WRITE ,__adg1samp_bits);
__IO_REG32_BIT(AD2G2SAMP,         0xFFF7C268,__READ_WRITE ,__adg2samp_bits);
__IO_REG32_BIT(AD2EVSR,           0xFFF7C26C,__READ       ,__adevsr_bits);
__IO_REG32_BIT(AD2G1SR,           0xFFF7C270,__READ       ,__adg1sr_bits);
__IO_REG32_BIT(AD2G2SR,           0xFFF7C274,__READ       ,__adg2sr_bits);
__IO_REG32_BIT(AD2EVSEL,          0xFFF7C278,__READ_WRITE ,__adevsel_bits);
__IO_REG32_BIT(AD2G1SEL,          0xFFF7C27C,__READ_WRITE ,__adg1sel_bits);
__IO_REG32_BIT(AD2G2SEL,          0xFFF7C280,__READ_WRITE ,__adg2sel_bits);
__IO_REG32_BIT(AD2CALR,           0xFFF7C284,__READ_WRITE ,__adcalr_bits);
__IO_REG32_BIT(AD2SMSTATE,        0xFFF7C288,__READ       ,__adsmstate_bits);
__IO_REG32_BIT(AD2LASTCONV,       0xFFF7C28C,__READ       ,__adlastconv_bits);
__IO_REG32_BIT(AD2EVBUFFER0,      0xFFF7C290,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVBUFFER0_10       AD2EVBUFFER0
#define AD2EVBUFFER0_10_bit   AD2EVBUFFER0_bit
__IO_REG32_BIT(AD2EVBUFFER1,      0xFFF7C294,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVBUFFER1_10       AD2EVBUFFER1
#define AD2EVBUFFER1_10_bit   AD2EVBUFFER1_bit
__IO_REG32_BIT(AD2EVBUFFER2,      0xFFF7C298,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVBUFFER2_10       AD2EVBUFFER2
#define AD2EVBUFFER2_10_bit   AD2EVBUFFER2_bit
__IO_REG32_BIT(AD2EVBUFFER3,      0xFFF7C29C,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVBUFFER3_10       AD2EVBUFFER3
#define AD2EVBUFFER3_10_bit   AD2EVBUFFER3_bit
__IO_REG32_BIT(AD2EVBUFFER4,      0xFFF7C2A0,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVBUFFER4_10       AD2EVBUFFER4
#define AD2EVBUFFER4_10_bit   AD2EVBUFFER4_bit
__IO_REG32_BIT(AD2EVBUFFER5,      0xFFF7C2A4,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVBUFFER5_10       AD2EVBUFFER5
#define AD2EVBUFFER5_10_bit   AD2EVBUFFER5_bit
__IO_REG32_BIT(AD2EVBUFFER6,      0xFFF7C2A8,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVBUFFER6_10       AD2EVBUFFER6
#define AD2EVBUFFER6_10_bit   AD2EVBUFFER6_bit
__IO_REG32_BIT(AD2EVBUFFER7,      0xFFF7C2AC,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVBUFFER7_10       AD2EVBUFFER7
#define AD2EVBUFFER7_10_bit   AD2EVBUFFER7_bit
__IO_REG32_BIT(AD2G1BUFFER0,      0xFFF7C2B0,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1BUFFER0_10       AD2G1BUFFER0
#define AD2G1BUFFER0_10_bit   AD2G1BUFFER0_bit
__IO_REG32_BIT(AD2G1BUFFER1,      0xFFF7C2B4,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1BUFFER1_10       AD2G1BUFFER1
#define AD2G1BUFFER1_10_bit   AD2G1BUFFER1_bit
__IO_REG32_BIT(AD2G1BUFFER2,      0xFFF7C2B8,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1BUFFER2_10       AD2G1BUFFER2
#define AD2G1BUFFER2_10_bit   AD2G1BUFFER2_bit
__IO_REG32_BIT(AD2G1BUFFER3,      0xFFF7C2BC,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1BUFFER3_10       AD2G1BUFFER3
#define AD2G1BUFFER3_10_bit   AD2G1BUFFER3_bit
__IO_REG32_BIT(AD2G1BUFFER4,      0xFFF7C2C0,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1BUFFER4_10       AD2G1BUFFER4
#define AD2G1BUFFER4_10_bit   AD2G1BUFFER4_bit
__IO_REG32_BIT(AD2G1BUFFER5,      0xFFF7C2C4,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1BUFFER5_10       AD2G1BUFFER5
#define AD2G1BUFFER5_10_bit   AD2G1BUFFER5_bit
__IO_REG32_BIT(AD2G1BUFFER6,      0xFFF7C2C8,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1BUFFER6_10       AD2G1BUFFER6
#define AD2G1BUFFER6_10_bit   AD2G1BUFFER6_bit
__IO_REG32_BIT(AD2G1BUFFER7,      0xFFF7C2CC,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1BUFFER7_10       AD2G1BUFFER7
#define AD2G1BUFFER7_10_bit   AD2G1BUFFER7_bit
__IO_REG32_BIT(AD2G2BUFFER0,      0xFFF7C2D0,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2BUFFER0_10       AD2G2BUFFER0
#define AD2G2BUFFER0_10_bit   AD2G2BUFFER0_bit
__IO_REG32_BIT(AD2G2BUFFER1,      0xFFF7C2D4,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2BUFFER1_10       AD2G2BUFFER1
#define AD2G2BUFFER1_10_bit   AD2G2BUFFER1_bit
__IO_REG32_BIT(AD2G2BUFFER2,      0xFFF7C2D8,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2BUFFER2_10       AD2G2BUFFER2
#define AD2G2BUFFER2_10_bit   AD2G2BUFFER2_bit
__IO_REG32_BIT(AD2G2BUFFER3,      0xFFF7C2DC,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2BUFFER3_10       AD2G2BUFFER3
#define AD2G2BUFFER3_10_bit   AD2G2BUFFER3_bit
__IO_REG32_BIT(AD2G2BUFFER4,      0xFFF7C2E0,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2BUFFER4_10       AD2G2BUFFER4
#define AD2G2BUFFER4_10_bit   AD2G2BUFFER4_bit
__IO_REG32_BIT(AD2G2BUFFER5,      0xFFF7C2E4,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2BUFFER5_10       AD2G2BUFFER5
#define AD2G2BUFFER5_10_bit   AD2G2BUFFER5_bit
__IO_REG32_BIT(AD2G2BUFFER6,      0xFFF7C2E8,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2BUFFER6_10       AD2G2BUFFER6
#define AD2G2BUFFER6_10_bit   AD2G2BUFFER6_bit
__IO_REG32_BIT(AD2G2BUFFER7,      0xFFF7C2EC,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2BUFFER7_10       AD2G2BUFFER7
#define AD2G2BUFFER7_10_bit   AD2G2BUFFER7_bit
__IO_REG32_BIT(AD2EVEMUBUFFER,    0xFFF7C2F0,__READ_WRITE ,__adevbuffer_bits);
#define AD2EVEMUBUFFER_10       AD2EVEMUBUFFER
#define AD2EVEMUBUFFER_10_bit   AD2EVEMUBUFFER_bit
__IO_REG32_BIT(AD2G1EMUBUFFER,    0xFFF7C2F4,__READ_WRITE ,__adg1buffer_bits);
#define AD2G1EMUBUFFER_10       AD2G1EMUBUFFER
#define AD2G1EMUBUFFER_10_bit   AD2G1EMUBUFFER_bit
__IO_REG32_BIT(AD2G2EMUBUFFER,    0xFFF7C2F8,__READ_WRITE ,__adg2buffer_bits);
#define AD2G2EMUBUFFER_10       AD2G2EMUBUFFER
#define AD2G2EMUBUFFER_10_bit   AD2G2EMUBUFFER_bit
__IO_REG32_BIT(AD2EVTDIR,         0xFFF7C2FC,__READ_WRITE ,__adevtdir_bits);
__IO_REG32_BIT(AD2EVTOUT,         0xFFF7C300,__READ_WRITE ,__adevtout_bits);
__IO_REG32_BIT(AD2EVTIN,          0xFFF7C304,__READ       ,__adevtin_bits);
__IO_REG32_BIT(AD2EVTSET,         0xFFF7C308,__READ_WRITE ,__adevtset_bits);
__IO_REG32_BIT(AD2EVTCLR,         0xFFF7C30C,__READ_WRITE ,__adevtclr_bits);
__IO_REG32_BIT(AD2EVTPDR,         0xFFF7C310,__READ_WRITE ,__adevtpdr_bits);
__IO_REG32_BIT(AD2EVTPDIS,        0xFFF7C314,__READ_WRITE ,__adevtpdis_bits);
__IO_REG32_BIT(AD2EVTPSEL,        0xFFF7C318,__READ_WRITE ,__adevtpsel_bits);
__IO_REG32_BIT(AD2EVSAMPDISEN,    0xFFF7C31C,__READ_WRITE ,__adevsampdisen_bits);
__IO_REG32_BIT(AD2G1SAMPDISEN,    0xFFF7C320,__READ_WRITE ,__adg1sampdisen_bits);
__IO_REG32_BIT(AD2G2SAMPDISEN,    0xFFF7C324,__READ_WRITE ,__adg2sampdisen_bits);
__IO_REG32_BIT(AD2MAGINT1CR,      0xFFF7C328,__READ_WRITE ,__admagintcr_bits);
__IO_REG32_BIT(AD2MAGINT1MASK,    0xFFF7C32C,__READ_WRITE ,__admagintmask_bits);
__IO_REG32_BIT(AD2MAGINT2CR,      0xFFF7C330,__READ_WRITE ,__admagintcr_bits);
__IO_REG32_BIT(AD2MAGINT2MASK,    0xFFF7C334,__READ_WRITE ,__admagintmask_bits);
__IO_REG32_BIT(AD2MAGINT3CR,      0xFFF7C338,__READ_WRITE ,__admagintcr_bits);
__IO_REG32_BIT(AD2MAGINT3MASK,    0xFFF7C33C,__READ_WRITE ,__admagintmask_bits);
__IO_REG32_BIT(AD2MAGINTENASET,   0xFFF7C358,__READ_WRITE ,__admagintenaset_bits);
__IO_REG32_BIT(AD2MAGINTENACLR,   0xFFF7C35C,__READ_WRITE ,__admagintenaclr_bits);
__IO_REG32_BIT(AD2MAGINTFLG,      0xFFF7C360,__READ_WRITE ,__admagintflg_bits);
__IO_REG32_BIT(AD2MAGINTOFF,      0xFFF7C364,__READ       ,__admagintoff_bits);
__IO_REG32_BIT(AD2EVFIFORESETCR,  0xFFF7C368,__READ_WRITE ,__adevfiforesetcr_bits);
__IO_REG32_BIT(AD2G1FIFORESETCR,  0xFFF7C36C,__READ_WRITE ,__adg1fiforesetcr_bits);
__IO_REG32_BIT(AD2G2FIFORESETCR,  0xFFF7C370,__READ_WRITE ,__adg2fiforesetcr_bits);
__IO_REG32_BIT(AD2EVRAMWRADDR,    0xFFF7C374,__READ       ,__adevramwraddr_bits);
__IO_REG32_BIT(AD2G1RAMWRADDR,    0xFFF7C378,__READ       ,__adg1ramwraddr_bits);
__IO_REG32_BIT(AD2G2RAMWRADDR,    0xFFF7C37C,__READ       ,__adg2ramwraddr_bits);
__IO_REG32_BIT(AD2PARCR,          0xFFF7C380,__READ_WRITE ,__adparcr_bits);
__IO_REG32_BIT(AD2PARADDR,        0xFFF7C384,__READ       ,__adparaddr_bits);
__IO_REG32_BIT(AD2PWRUPDLYCTRL,   0xFFF7C388,__READ_WRITE ,__adpwrupdlyctrl_bits);
__IO_REG32(    AD2BUFER_BASE,     0xFF3A0000,__READ_WRITE );

/***************************************************************************
 **
 ** DCAN1 (Controller Area Network)
 **
 ***************************************************************************/
__IO_REG32_BIT(DCAN1CTL,          0xFFF7DC00,__READ_WRITE ,__dcanctl_bits);
__IO_REG32_BIT(DCAN1ES,           0xFFF7DC04,__READ       ,__dcanes_bits);
__IO_REG32_BIT(DCAN1ERRC,         0xFFF7DC08,__READ       ,__dcanerrc_bits);
__IO_REG32_BIT(DCAN1BTR,          0xFFF7DC0C,__READ_WRITE ,__dcanbtr_bits);
__IO_REG32_BIT(DCAN1INT,          0xFFF7DC10,__READ       ,__dcanint_bits);
__IO_REG32_BIT(DCAN1TEST,         0xFFF7DC14,__READ_WRITE ,__dcantest_bits);
__IO_REG32_BIT(DCAN1PERR,         0xFFF7DC1C,__READ       ,__dcanperr_bits);
__IO_REG32(    DCAN1ABOTR,        0xFFF7DC80,__READ_WRITE );
__IO_REG32_BIT(DCAN1TXRQX,        0xFFF7DC84,__READ       ,__dcantxrqx_bits);
__IO_REG32_BIT(DCAN1TXRQ12,       0xFFF7DC88,__READ       ,__dcantxrq12_bits);
__IO_REG32_BIT(DCAN1TXRQ34,       0xFFF7DC8C,__READ       ,__dcantxrq34_bits);
__IO_REG32_BIT(DCAN1TXRQ56,       0xFFF7DC90,__READ       ,__dcantxrq56_bits);
__IO_REG32_BIT(DCAN1TXRQ78,       0xFFF7DC94,__READ       ,__dcantxrq78_bits);
__IO_REG32_BIT(DCAN1NWDATX,       0xFFF7DC98,__READ       ,__dcannwdatx_bits);
__IO_REG32_BIT(DCAN1NWDAT12,      0xFFF7DC9C,__READ       ,__dcannwdat12_bits);
__IO_REG32_BIT(DCAN1NWDAT34,      0xFFF7DCA0,__READ       ,__dcannwdat34_bits);
__IO_REG32_BIT(DCAN1NWDAT56,      0xFFF7DCA4,__READ       ,__dcannwdat56_bits);
__IO_REG32_BIT(DCAN1NWDAT78,      0xFFF7DCA8,__READ       ,__dcannwdat78_bits);
__IO_REG32_BIT(DCAN1INTPNDX,      0xFFF7DCAC,__READ       ,__dcanintpndx_bits);
__IO_REG32_BIT(DCAN1INTPND12,     0xFFF7DCB0,__READ       ,__dcanintpnd12_bits);
__IO_REG32_BIT(DCAN1INTPND34,     0xFFF7DCB4,__READ       ,__dcanintpnd34_bits);
__IO_REG32_BIT(DCAN1INTPND56,     0xFFF7DCB8,__READ       ,__dcanintpnd56_bits);
__IO_REG32_BIT(DCAN1INTPND78,     0xFFF7DCBC,__READ       ,__dcanintpnd78_bits);
__IO_REG32_BIT(DCAN1MSGVALX,      0xFFF7DCC0,__READ       ,__dcanmsgvalx_bits);
__IO_REG32_BIT(DCAN1MSGVAL12,     0xFFF7DCC4,__READ       ,__dcanmsgval12_bits);
__IO_REG32_BIT(DCAN1MSGVAL34,     0xFFF7DCC8,__READ       ,__dcanmsgval34_bits);
__IO_REG32_BIT(DCAN1MSGVAL56,     0xFFF7DCCC,__READ       ,__dcanmsgval56_bits);
__IO_REG32_BIT(DCAN1MSGVAL78,     0xFFF7DCD0,__READ       ,__dcanmsgval78_bits);
__IO_REG32_BIT(DCAN1INTMUX12,     0xFFF7DCD8,__READ_WRITE ,__dcanintmux12_bits);
__IO_REG32_BIT(DCAN1INTMUX34,     0xFFF7DCDC,__READ_WRITE ,__dcanintmux34_bits);
__IO_REG32_BIT(DCAN1INTMUX56,     0xFFF7DCE0,__READ_WRITE ,__dcanintmux56_bits);
__IO_REG32_BIT(DCAN1INTMUX78,     0xFFF7DCE4,__READ_WRITE ,__dcanintmux78_bits);
__IO_REG32_BIT(DCAN1IF1CMD,       0xFFF7DD00,__READ_WRITE ,__dcanifcmd_bits);
__IO_REG32_BIT(DCAN1IF1MSK,       0xFFF7DD04,__READ_WRITE ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN1IF1ARB,       0xFFF7DD08,__READ_WRITE ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN1IF1MCTL,      0xFFF7DD0C,__READ_WRITE ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN1IF1DATA,      0xFFF7DD10,__READ_WRITE ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN1IF1DATB,      0xFFF7DD14,__READ_WRITE ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN1IF2CMD,       0xFFF7DD20,__READ_WRITE ,__dcanifcmd_bits);
__IO_REG32_BIT(DCAN1IF2MSK,       0xFFF7DD24,__READ_WRITE ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN1IF2ARB,       0xFFF7DD28,__READ_WRITE ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN1IF2MCTL,      0xFFF7DD2C,__READ_WRITE ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN1IF2DATA,      0xFFF7DD30,__READ_WRITE ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN1IF2DATB,      0xFFF7DD34,__READ_WRITE ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN1IF3OBS,       0xFFF7DD40,__READ_WRITE ,__dcanif3obs_bits);
__IO_REG32_BIT(DCAN1IF3MSK,       0xFFF7DD44,__READ       ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN1IF3ARB,       0xFFF7DD48,__READ       ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN1IF3MCTL,      0xFFF7DD4C,__READ       ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN1IF3DATA,      0xFFF7DD50,__READ       ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN1IF3DATB,      0xFFF7DD54,__READ       ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN1IF3UPD12,     0xFFF7DD60,__READ_WRITE ,__dcanif3upd12_bits);
__IO_REG32_BIT(DCAN1IF3UPD34,     0xFFF7DD64,__READ_WRITE ,__dcanif3upd34_bits);
__IO_REG32_BIT(DCAN1IF3UPD56,     0xFFF7DD68,__READ_WRITE ,__dcanif3upd56_bits);
__IO_REG32_BIT(DCAN1IF3UPD78,     0xFFF7DD6C,__READ_WRITE ,__dcanif3upd78_bits);
__IO_REG32_BIT(DCAN1TIOC,         0xFFF7DDE0,__READ_WRITE ,__dcantioc_bits);
__IO_REG32_BIT(DCAN1RIOC,         0xFFF7DDE4,__READ_WRITE ,__dcantioc_bits);
__IO_REG32(    DCAN1RAM_BASE,     0xFF1E0000,__READ_WRITE );

/***************************************************************************
 **
 ** DCAN2 (Controller Area Network)
 **
 ***************************************************************************/
__IO_REG32_BIT(DCAN2CTL,          0xFFF7DE00,__READ_WRITE ,__dcanctl_bits);
__IO_REG32_BIT(DCAN2ES,           0xFFF7DE04,__READ       ,__dcanes_bits);
__IO_REG32_BIT(DCAN2ERRC,         0xFFF7DE08,__READ       ,__dcanerrc_bits);
__IO_REG32_BIT(DCAN2BTR,          0xFFF7DE0C,__READ_WRITE ,__dcanbtr_bits);
__IO_REG32_BIT(DCAN2INT,          0xFFF7DE10,__READ       ,__dcanint_bits);
__IO_REG32_BIT(DCAN2TEST,         0xFFF7DE14,__READ_WRITE ,__dcantest_bits);
__IO_REG32_BIT(DCAN2PERR,         0xFFF7DE1C,__READ       ,__dcanperr_bits);
__IO_REG32(    DCAN2ABOTR,        0xFFF7DE80,__READ_WRITE );
__IO_REG32_BIT(DCAN2TXRQX,        0xFFF7DE84,__READ       ,__dcantxrqx_bits);
__IO_REG32_BIT(DCAN2TXRQ12,       0xFFF7DE88,__READ       ,__dcantxrq12_bits);
__IO_REG32_BIT(DCAN2TXRQ34,       0xFFF7DE8C,__READ       ,__dcantxrq34_bits);
__IO_REG32_BIT(DCAN2TXRQ56,       0xFFF7DE90,__READ       ,__dcantxrq56_bits);
__IO_REG32_BIT(DCAN2TXRQ78,       0xFFF7DE94,__READ       ,__dcantxrq78_bits);
__IO_REG32_BIT(DCAN2NWDATX,       0xFFF7DE98,__READ       ,__dcannwdatx_bits);
__IO_REG32_BIT(DCAN2NWDAT12,      0xFFF7DE9C,__READ       ,__dcannwdat12_bits);
__IO_REG32_BIT(DCAN2NWDAT34,      0xFFF7DEA0,__READ       ,__dcannwdat34_bits);
__IO_REG32_BIT(DCAN2NWDAT56,      0xFFF7DEA4,__READ       ,__dcannwdat56_bits);
__IO_REG32_BIT(DCAN2NWDAT78,      0xFFF7DEA8,__READ       ,__dcannwdat78_bits);
__IO_REG32_BIT(DCAN2INTPNDX,      0xFFF7DEAC,__READ       ,__dcanintpndx_bits);
__IO_REG32_BIT(DCAN2INTPND12,     0xFFF7DEB0,__READ       ,__dcanintpnd12_bits);
__IO_REG32_BIT(DCAN2INTPND34,     0xFFF7DEB4,__READ       ,__dcanintpnd34_bits);
__IO_REG32_BIT(DCAN2INTPND56,     0xFFF7DEB8,__READ       ,__dcanintpnd56_bits);
__IO_REG32_BIT(DCAN2INTPND78,     0xFFF7DEBC,__READ       ,__dcanintpnd78_bits);
__IO_REG32_BIT(DCAN2MSGVALX,      0xFFF7DEC0,__READ       ,__dcanmsgvalx_bits);
__IO_REG32_BIT(DCAN2MSGVAL12,     0xFFF7DEC4,__READ       ,__dcanmsgval12_bits);
__IO_REG32_BIT(DCAN2MSGVAL34,     0xFFF7DEC8,__READ       ,__dcanmsgval34_bits);
__IO_REG32_BIT(DCAN2MSGVAL56,     0xFFF7DECC,__READ       ,__dcanmsgval56_bits);
__IO_REG32_BIT(DCAN2MSGVAL78,     0xFFF7DED0,__READ       ,__dcanmsgval78_bits);
__IO_REG32_BIT(DCAN2INTMUX12,     0xFFF7DED8,__READ_WRITE ,__dcanintmux12_bits);
__IO_REG32_BIT(DCAN2INTMUX34,     0xFFF7DEDC,__READ_WRITE ,__dcanintmux34_bits);
__IO_REG32_BIT(DCAN2INTMUX56,     0xFFF7DEE0,__READ_WRITE ,__dcanintmux56_bits);
__IO_REG32_BIT(DCAN2INTMUX78,     0xFFF7DEE4,__READ_WRITE ,__dcanintmux78_bits);
__IO_REG32_BIT(DCAN2IF1CMD,       0xFFF7DF00,__READ_WRITE ,__dcanifcmd_bits);
__IO_REG32_BIT(DCAN2IF1MSK,       0xFFF7DF04,__READ_WRITE ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN2IF1ARB,       0xFFF7DF08,__READ_WRITE ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN2IF1MCTL,      0xFFF7DF0C,__READ_WRITE ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN2IF1DATA,      0xFFF7DF10,__READ_WRITE ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN2IF1DATB,      0xFFF7DF14,__READ_WRITE ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN2IF2CMD,       0xFFF7DF20,__READ_WRITE ,__dcanifcmd_bits);
__IO_REG32_BIT(DCAN2IF2MSK,       0xFFF7DF24,__READ_WRITE ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN2IF2ARB,       0xFFF7DF28,__READ_WRITE ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN2IF2MCTL,      0xFFF7DF2C,__READ_WRITE ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN2IF2DATA,      0xFFF7DF30,__READ_WRITE ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN2IF2DATB,      0xFFF7DF34,__READ_WRITE ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN2IF3OBS,       0xFFF7DF40,__READ_WRITE ,__dcanif3obs_bits);
__IO_REG32_BIT(DCAN2IF3MSK,       0xFFF7DF44,__READ       ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN2IF3ARB,       0xFFF7DF48,__READ       ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN2IF3MCTL,      0xFFF7DF4C,__READ       ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN2IF3DATA,      0xFFF7DF50,__READ       ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN2IF3DATB,      0xFFF7DF54,__READ       ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN2IF3UPD12,     0xFFF7DF60,__READ_WRITE ,__dcanif3upd12_bits);
__IO_REG32_BIT(DCAN2IF3UPD34,     0xFFF7DF64,__READ_WRITE ,__dcanif3upd34_bits);
__IO_REG32_BIT(DCAN2IF3UPD56,     0xFFF7DF68,__READ_WRITE ,__dcanif3upd56_bits);
__IO_REG32_BIT(DCAN2IF3UPD78,     0xFFF7DF6C,__READ_WRITE ,__dcanif3upd78_bits);
__IO_REG32_BIT(DCAN2TIOC,         0xFFF7DFE0,__READ_WRITE ,__dcantioc_bits);
__IO_REG32_BIT(DCAN2RIOC,         0xFFF7DFE4,__READ_WRITE ,__dcantioc_bits);
__IO_REG32(    DCAN2RAM_BASE,     0xFF1C0000,__READ_WRITE );

/***************************************************************************
 **
 ** DCAN3 (Controller Area Network)
 **
 ***************************************************************************/
__IO_REG32_BIT(DCAN3CTL,          0xFFF7E000,__READ_WRITE ,__dcanctl_bits);
__IO_REG32_BIT(DCAN3ES,           0xFFF7E004,__READ       ,__dcanes_bits);
__IO_REG32_BIT(DCAN3ERRC,         0xFFF7E008,__READ       ,__dcanerrc_bits);
__IO_REG32_BIT(DCAN3BTR,          0xFFF7E00C,__READ_WRITE ,__dcanbtr_bits);
__IO_REG32_BIT(DCAN3INT,          0xFFF7E010,__READ       ,__dcanint_bits);
__IO_REG32_BIT(DCAN3TEST,         0xFFF7E014,__READ_WRITE ,__dcantest_bits);
__IO_REG32_BIT(DCAN3PERR,         0xFFF7E01C,__READ       ,__dcanperr_bits);
__IO_REG32(    DCAN3ABOTR,        0xFFF7E080,__READ_WRITE );
__IO_REG32_BIT(DCAN3TXRQX,        0xFFF7E084,__READ       ,__dcantxrqx_bits);
__IO_REG32_BIT(DCAN3TXRQ12,       0xFFF7E088,__READ       ,__dcantxrq12_bits);
__IO_REG32_BIT(DCAN3TXRQ34,       0xFFF7E08C,__READ       ,__dcantxrq34_bits);
__IO_REG32_BIT(DCAN3TXRQ56,       0xFFF7E090,__READ       ,__dcantxrq56_bits);
__IO_REG32_BIT(DCAN3TXRQ78,       0xFFF7E094,__READ       ,__dcantxrq78_bits);
__IO_REG32_BIT(DCAN3NWDATX,       0xFFF7E098,__READ       ,__dcannwdatx_bits);
__IO_REG32_BIT(DCAN3NWDAT12,      0xFFF7E09C,__READ       ,__dcannwdat12_bits);
__IO_REG32_BIT(DCAN3NWDAT34,      0xFFF7E0A0,__READ       ,__dcannwdat34_bits);
__IO_REG32_BIT(DCAN3NWDAT56,      0xFFF7E0A4,__READ       ,__dcannwdat56_bits);
__IO_REG32_BIT(DCAN3NWDAT78,      0xFFF7E0A8,__READ       ,__dcannwdat78_bits);
__IO_REG32_BIT(DCAN3INTPNDX,      0xFFF7E0AC,__READ       ,__dcanintpndx_bits);
__IO_REG32_BIT(DCAN3INTPND12,     0xFFF7E0B0,__READ       ,__dcanintpnd12_bits);
__IO_REG32_BIT(DCAN3INTPND34,     0xFFF7E0B4,__READ       ,__dcanintpnd34_bits);
__IO_REG32_BIT(DCAN3INTPND56,     0xFFF7E0B8,__READ       ,__dcanintpnd56_bits);
__IO_REG32_BIT(DCAN3INTPND78,     0xFFF7E0BC,__READ       ,__dcanintpnd78_bits);
__IO_REG32_BIT(DCAN3MSGVALX,      0xFFF7E0C0,__READ       ,__dcanmsgvalx_bits);
__IO_REG32_BIT(DCAN3MSGVAL12,     0xFFF7E0C4,__READ       ,__dcanmsgval12_bits);
__IO_REG32_BIT(DCAN3MSGVAL34,     0xFFF7E0C8,__READ       ,__dcanmsgval34_bits);
__IO_REG32_BIT(DCAN3MSGVAL56,     0xFFF7E0CC,__READ       ,__dcanmsgval56_bits);
__IO_REG32_BIT(DCAN3MSGVAL78,     0xFFF7E0D0,__READ       ,__dcanmsgval78_bits);
__IO_REG32_BIT(DCAN3INTMUX12,     0xFFF7E0D8,__READ_WRITE ,__dcanintmux12_bits);
__IO_REG32_BIT(DCAN3INTMUX34,     0xFFF7E0DC,__READ_WRITE ,__dcanintmux34_bits);
__IO_REG32_BIT(DCAN3INTMUX56,     0xFFF7E0E0,__READ_WRITE ,__dcanintmux56_bits);
__IO_REG32_BIT(DCAN3INTMUX78,     0xFFF7E0E4,__READ_WRITE ,__dcanintmux78_bits);
__IO_REG32_BIT(DCAN3IF1CMD,       0xFFF7E100,__READ_WRITE ,__dcanifcmd_bits);
__IO_REG32_BIT(DCAN3IF1MSK,       0xFFF7E104,__READ_WRITE ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN3IF1ARB,       0xFFF7E108,__READ_WRITE ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN3IF1MCTL,      0xFFF7E10C,__READ_WRITE ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN3IF1DATA,      0xFFF7E110,__READ_WRITE ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN3IF1DATB,      0xFFF7E114,__READ_WRITE ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN3IF2CMD,       0xFFF7E120,__READ_WRITE ,__dcanifcmd_bits);
__IO_REG32_BIT(DCAN3IF2MSK,       0xFFF7E124,__READ_WRITE ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN3IF2ARB,       0xFFF7E128,__READ_WRITE ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN3IF2MCTL,      0xFFF7E12C,__READ_WRITE ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN3IF2DATA,      0xFFF7E130,__READ_WRITE ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN3IF2DATB,      0xFFF7E134,__READ_WRITE ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN3IF3OBS,       0xFFF7E140,__READ_WRITE ,__dcanif3obs_bits);
__IO_REG32_BIT(DCAN3IF3MSK,       0xFFF7E144,__READ       ,__dcanifmsk_bits);
__IO_REG32_BIT(DCAN3IF3ARB,       0xFFF7E148,__READ       ,__dcanifarb_bits);
__IO_REG32_BIT(DCAN3IF3MCTL,      0xFFF7E14C,__READ       ,__dcanifmctl_bits);
__IO_REG32_BIT(DCAN3IF3DATA,      0xFFF7E150,__READ       ,__dcanifdata_bits);
__IO_REG32_BIT(DCAN3IF3DATB,      0xFFF7E154,__READ       ,__dcanifdatb_bits);
__IO_REG32_BIT(DCAN3IF3UPD12,     0xFFF7E160,__READ_WRITE ,__dcanif3upd12_bits);
__IO_REG32_BIT(DCAN3IF3UPD34,     0xFFF7E164,__READ_WRITE ,__dcanif3upd34_bits);
__IO_REG32_BIT(DCAN3IF3UPD56,     0xFFF7E168,__READ_WRITE ,__dcanif3upd56_bits);
__IO_REG32_BIT(DCAN3IF3UPD78,     0xFFF7E16C,__READ_WRITE ,__dcanif3upd78_bits);
__IO_REG32_BIT(DCAN3TIOC,         0xFFF7E1E0,__READ_WRITE ,__dcantioc_bits);
__IO_REG32_BIT(DCAN3RIOC,         0xFFF7E1E4,__READ_WRITE ,__dcantioc_bits);
__IO_REG32(    DCAN3RAM_BASE,     0xFF1A0000,__READ_WRITE );

/***************************************************************************
 **
 ** FTU (FlexRay Transfer Unit)
 **
 ***************************************************************************/
__IO_REG32(    FTUGSN0,           0xFFF7A000,__READ       );
__IO_REG32(    FTUGSN1,           0xFFF7A004,__READ       );
__IO_REG32_BIT(FTUGCS,            0xFFF7A010,__READ_WRITE ,__ftugcs_bits);
__IO_REG32_BIT(FTUGCR,            0xFFF7A014,__READ_WRITE ,__ftugcs_bits);
__IO_REG32_BIT(FTUTSCB,           0xFFF7A018,__READ       ,__ftutscb_bits);
__IO_REG32_BIT(FTULTBCC,          0xFFF7A01C,__READ       ,__ftultbcc_bits);
__IO_REG32_BIT(FTULTBSM,          0xFFF7A020,__READ       ,__ftultbcc_bits);
__IO_REG32(    FTUTBA,            0xFFF7A024,__READ_WRITE );
__IO_REG32(    FTUNTBA,           0xFFF7A028,__READ_WRITE );
__IO_REG32(    FTUBAMS,           0xFFF7A02C,__READ_WRITE );
__IO_REG32(    FTUSAMP,           0xFFF7A030,__READ_WRITE );
__IO_REG32(    FTUEAMP,           0xFFF7A034,__READ_WRITE );
__IO_REG32_BIT(FTUTSMO1,          0xFFF7A040,__READ_WRITE ,__ftutsmo1_bits);
__IO_REG32_BIT(FTUTSMO2,          0xFFF7A044,__READ_WRITE ,__ftutsmo2_bits);
__IO_REG32_BIT(FTUTSMO3,          0xFFF7A048,__READ_WRITE ,__ftutsmo3_bits);
__IO_REG32_BIT(FTUTSMO4,          0xFFF7A04C,__READ_WRITE ,__ftutsmo4_bits);
__IO_REG32_BIT(FTUTCCO1,          0xFFF7A050,__READ_WRITE ,__ftutcco1_bits);
__IO_REG32_BIT(FTUTCCO2,          0xFFF7A054,__READ_WRITE ,__ftutcco2_bits);
__IO_REG32_BIT(FTUTCCO3,          0xFFF7A058,__READ_WRITE ,__ftutcco3_bits);
__IO_REG32_BIT(FTUTCCO4,          0xFFF7A05C,__READ_WRITE ,__ftutcco4_bits);
__IO_REG32_BIT(FTUTOOFF,          0xFFF7A060,__READ       ,__ftutooff_bits);
__IO_REG32_BIT(FTUPEADR,          0xFFF7A070,__READ       ,__ftupeadr_bits);
__IO_REG32_BIT(FTUTEIF,           0xFFF7A074,__READ_WRITE ,__ftuteif_bits);
__IO_REG32_BIT(FTUTEIRES,         0xFFF7A078,__READ_WRITE ,__ftuteires_bits);
__IO_REG32_BIT(FTUTEIRER,         0xFFF7A07C,__READ_WRITE ,__ftuteires_bits);
__IO_REG32_BIT(FTUTTSMS1,         0xFFF7A080,__READ_WRITE ,__ftuttsms1_bits);
__IO_REG32_BIT(FTUTTSMR1,         0xFFF7A084,__READ_WRITE ,__ftuttsmr1_bits);
__IO_REG32_BIT(FTUTTSMS2,         0xFFF7A088,__READ_WRITE ,__ftuttsms2_bits);
__IO_REG32_BIT(FTUTTSMR2,         0xFFF7A08C,__READ_WRITE ,__ftuttsmr2_bits);
__IO_REG32_BIT(FTUTTSMS3,         0xFFF7A090,__READ_WRITE ,__ftuttsms3_bits);
__IO_REG32_BIT(FTUTTSMR3,         0xFFF7A094,__READ_WRITE ,__ftuttsmr3_bits);
__IO_REG32_BIT(FTUTTSMS4,         0xFFF7A098,__READ_WRITE ,__ftuttsms4_bits);
__IO_REG32_BIT(FTUTTSMR4,         0xFFF7A09C,__READ_WRITE ,__ftuttsmr4_bits);
__IO_REG32_BIT(FTUTTCCS1,         0xFFF7A0A0,__READ_WRITE ,__ftuttccs1_bits);
__IO_REG32_BIT(FTUTTCCR1,         0xFFF7A0A4,__READ_WRITE ,__ftuttccr1_bits);
__IO_REG32_BIT(FTUTTCCS2,         0xFFF7A0A8,__READ_WRITE ,__ftuttccs2_bits);
__IO_REG32_BIT(FTUTTCCR2,         0xFFF7A0AC,__READ_WRITE ,__ftuttccr2_bits);
__IO_REG32_BIT(FTUTTCCS3,         0xFFF7A0B0,__READ_WRITE ,__ftuttccs3_bits);
__IO_REG32_BIT(FTUTTCCR3,         0xFFF7A0B4,__READ_WRITE ,__ftuttccr3_bits);
__IO_REG32_BIT(FTUTTCCS4,         0xFFF7A0B8,__READ_WRITE ,__ftuttccs4_bits);
__IO_REG32_BIT(FTUTTCCR4,         0xFFF7A0BC,__READ_WRITE ,__ftuttccr4_bits);
__IO_REG32_BIT(FTUETESMS1,        0xFFF7A0C0,__READ_WRITE ,__ftuetesms1_bits);
__IO_REG32_BIT(FTUETESMR1,        0xFFF7A0C4,__READ_WRITE ,__ftuetesmr1_bits);
__IO_REG32_BIT(FTUETESMS2,        0xFFF7A0C8,__READ_WRITE ,__ftuetesms2_bits);
__IO_REG32_BIT(FTUETESMR2,        0xFFF7A0CC,__READ_WRITE ,__ftuetesmr2_bits);
__IO_REG32_BIT(FTUETESMS3,        0xFFF7A0D0,__READ_WRITE ,__ftuetesms3_bits);
__IO_REG32_BIT(FTUETESMR3,        0xFFF7A0D4,__READ_WRITE ,__ftuetesmr3_bits);
__IO_REG32_BIT(FTUETESMS4,        0xFFF7A0D8,__READ_WRITE ,__ftuetesms4_bits);
__IO_REG32_BIT(FTUETESMR4,        0xFFF7A0DC,__READ_WRITE ,__ftuetesmr4_bits);
__IO_REG32_BIT(FTUCESMS1,         0xFFF7A0E0,__READ_WRITE ,__ftucesms1_bits);
__IO_REG32_BIT(FTUCESMR1,         0xFFF7A0E4,__READ_WRITE ,__ftucesmr1_bits);
__IO_REG32_BIT(FTUCESMS2,         0xFFF7A0E8,__READ_WRITE ,__ftucesms2_bits);
__IO_REG32_BIT(FTUCESMR2,         0xFFF7A0EC,__READ_WRITE ,__ftucesmr2_bits);
__IO_REG32_BIT(FTUCESMS3,         0xFFF7A0F0,__READ_WRITE ,__ftucesms3_bits);
__IO_REG32_BIT(FTUCESMR3,         0xFFF7A0F4,__READ_WRITE ,__ftucesmr3_bits);
__IO_REG32_BIT(FTUCESMS4,         0xFFF7A0F8,__READ_WRITE ,__ftucesms4_bits);
__IO_REG32_BIT(FTUCESMR4,         0xFFF7A0FC,__READ_WRITE ,__ftucesmr4_bits);
__IO_REG32_BIT(FTUTSMIES1,        0xFFF7A100,__READ_WRITE ,__ftutsmies1_bits);
__IO_REG32_BIT(FTUTSMIER1,        0xFFF7A104,__READ_WRITE ,__ftutsmier1_bits);
__IO_REG32_BIT(FTUTSMIES2,        0xFFF7A108,__READ_WRITE ,__ftutsmies2_bits);
__IO_REG32_BIT(FTUTSMIER2,        0xFFF7A10C,__READ_WRITE ,__ftutsmier2_bits);
__IO_REG32_BIT(FTUTSMIES3,        0xFFF7A110,__READ_WRITE ,__ftutsmies3_bits);
__IO_REG32_BIT(FTUTSMIER3,        0xFFF7A114,__READ_WRITE ,__ftutsmier3_bits);
__IO_REG32_BIT(FTUTSMIES4,        0xFFF7A118,__READ_WRITE ,__ftutsmies4_bits);
__IO_REG32_BIT(FTUTSMIER4,        0xFFF7A11C,__READ_WRITE ,__ftutsmier4_bits);
__IO_REG32_BIT(FTUTCCIES1,        0xFFF7A120,__READ_WRITE ,__ftutccies1_bits);
__IO_REG32_BIT(FTUTCCIER1,        0xFFF7A124,__READ_WRITE ,__ftutccier1_bits);
__IO_REG32_BIT(FTUTCCIES2,        0xFFF7A128,__READ_WRITE ,__ftutccies2_bits);
__IO_REG32_BIT(FTUTCCIER2,        0xFFF7A12C,__READ_WRITE ,__ftutccier2_bits);
__IO_REG32_BIT(FTUTCCIES3,        0xFFF7A130,__READ_WRITE ,__ftutccies3_bits);
__IO_REG32_BIT(FTUTCCIER3,        0xFFF7A134,__READ_WRITE ,__ftutccier3_bits);
__IO_REG32_BIT(FTUTCCIES4,        0xFFF7A138,__READ_WRITE ,__ftutccies4_bits);
__IO_REG32_BIT(FTUTCCIER4,        0xFFF7A13C,__READ_WRITE ,__ftutccier4_bits);

/***************************************************************************
 **
 ** FlexRay
 **
 ***************************************************************************/
__IO_REG32_BIT(FRTEST1,           0xFFF7C810,__READ_WRITE ,__ftest1_bits);
__IO_REG32_BIT(FRTEST2,           0xFFF7C814,__READ_WRITE ,__ftest2_bits);
__IO_REG32_BIT(FRLCK,             0xFFF7C81C,__READ_WRITE ,__flck_bits);
__IO_REG32_BIT(FREIR,             0xFFF7C820,__WRITE      ,__feir_bits);
__IO_REG32_BIT(FRSIR,             0xFFF7C824,__READ_WRITE ,__fsir_bits);
__IO_REG32_BIT(FREILS,            0xFFF7C828,__READ_WRITE ,__feils_bits);
__IO_REG32_BIT(FRSILS,            0xFFF7C82C,__READ_WRITE ,__fsils_bits);
__IO_REG32_BIT(FREIES,            0xFFF7C830,__READ_WRITE ,__feies_bits);
__IO_REG32_BIT(FREIER,            0xFFF7C834,__READ_WRITE ,__feies_bits);
__IO_REG32_BIT(FRSIES,            0xFFF7C838,__READ_WRITE ,__fsies_bits);
__IO_REG32_BIT(FRSIER,            0xFFF7C83C,__READ_WRITE ,__fsies_bits);
__IO_REG32_BIT(FRILE,             0xFFF7C840,__READ_WRITE ,__file_bits);
__IO_REG32_BIT(FRT0C,             0xFFF7C844,__READ_WRITE ,__ft0c_bits);
__IO_REG32_BIT(FRT1C,             0xFFF7C848,__READ_WRITE ,__ft1c_bits);
__IO_REG32_BIT(FRSTPW1,           0xFFF7C84C,__READ_WRITE ,__fstpw1_bits);
__IO_REG32_BIT(FRSTPW2,           0xFFF7C850,__READ       ,__fstpw2_bits);
__IO_REG32_BIT(FRSUCC1,           0xFFF7C880,__READ_WRITE ,__fsucc1_bits);
__IO_REG32_BIT(FRSUCC2,           0xFFF7C884,__READ_WRITE ,__fsucc2_bits);
__IO_REG32_BIT(FRSUCC3,           0xFFF7C888,__READ_WRITE ,__fsucc3_bits);
__IO_REG32_BIT(FRNEMC,            0xFFF7C88C,__READ_WRITE ,__fnemc_bits);
__IO_REG32_BIT(FRPRTC1,           0xFFF7C890,__READ_WRITE ,__fprtc1_bits);
__IO_REG32_BIT(FRPRTC2,           0xFFF7C894,__READ_WRITE ,__fprtc2_bits);
__IO_REG32_BIT(FRMHDC,            0xFFF7C898,__READ_WRITE ,__fmhdc_bits);
__IO_REG32_BIT(FRGTUC1,           0xFFF7C8A0,__READ_WRITE ,__fgtuc1_bits);
__IO_REG32_BIT(FRGTUC2,           0xFFF7C8A4,__READ_WRITE ,__fgtuc2_bits);
__IO_REG32_BIT(FRGTUC3,           0xFFF7C8A8,__READ_WRITE ,__fgtuc3_bits);
__IO_REG32_BIT(FRGTUC4,           0xFFF7C8AC,__READ_WRITE ,__fgtuc4_bits);
__IO_REG32_BIT(FRGTUC5,           0xFFF7C8B0,__READ_WRITE ,__fgtuc5_bits);
__IO_REG32_BIT(FRGTUC6,           0xFFF7C8B4,__READ_WRITE ,__fgtuc6_bits);
__IO_REG32_BIT(FRGTUC7,           0xFFF7C8B8,__READ_WRITE ,__fgtuc7_bits);
__IO_REG32_BIT(FRGTUC8,           0xFFF7C8BC,__READ_WRITE ,__fgtuc8_bits);
__IO_REG32_BIT(FRGTUC9,           0xFFF7C8C0,__READ_WRITE ,__fgtuc9_bits);
__IO_REG32_BIT(FRGTUC10,          0xFFF7C8C4,__READ_WRITE ,__fgtuc10_bits);
__IO_REG32_BIT(FRGTUC11,          0xFFF7C8C8,__READ_WRITE ,__fgtuc11_bits);
__IO_REG32_BIT(FRCCSV,            0xFFF7C900,__READ       ,__fccsv_bits);
__IO_REG32_BIT(FRCCEV,            0xFFF7C904,__READ       ,__fccev_bits);
__IO_REG32_BIT(FRSCV,             0xFFF7C910,__READ       ,__fscv_bits);
__IO_REG32_BIT(FRMTCCV,           0xFFF7C914,__READ       ,__fmtccv_bits);
__IO_REG32_BIT(FRRCV,             0xFFF7C918,__READ       ,__frcv_bits);
__IO_REG32_BIT(FROCV,             0xFFF7C91C,__READ       ,__focv_bits);
__IO_REG32_BIT(FRSFS,             0xFFF7C920,__READ       ,__fsfs_bits);
__IO_REG32_BIT(FRSWNIT,           0xFFF7C924,__READ       ,__fswnit_bits);
__IO_REG32_BIT(FRACS,             0xFFF7C928,__READ_WRITE ,__facs_bits);
__IO_REG32_BIT(FRESID1,           0xFFF7C930,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID2,           0xFFF7C934,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID3,           0xFFF7C938,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID4,           0xFFF7C93C,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID5,           0xFFF7C940,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID6,           0xFFF7C944,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID7,           0xFFF7C948,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID8,           0xFFF7C94C,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID9,           0xFFF7C950,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID10,          0xFFF7C954,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID11,          0xFFF7C958,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID12,          0xFFF7C95C,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID13,          0xFFF7C960,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID14,          0xFFF7C964,__READ       ,__fesid_bits);
__IO_REG32_BIT(FRESID15,          0xFFF7C968,__READ       ,__fesid_bits);
__IO_REG32_BIT(FROSID1,           0xFFF7C970,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID2,           0xFFF7C974,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID3,           0xFFF7C978,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID4,           0xFFF7C97C,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID5,           0xFFF7C980,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID6,           0xFFF7C984,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID7,           0xFFF7C988,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID8,           0xFFF7C98C,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID9,           0xFFF7C990,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID10,          0xFFF7C994,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID11,          0xFFF7C998,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID12,          0xFFF7C99C,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID13,          0xFFF7C9A0,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID14,          0xFFF7C9A4,__READ       ,__fosid_bits);
__IO_REG32_BIT(FROSID15,          0xFFF7C9A8,__READ       ,__fosid_bits);
__IO_REG32_BIT(FRNMV1,            0xFFF7C9B0,__READ       ,__fnmv1_bits);
__IO_REG32_BIT(FRNMV2,            0xFFF7C9B4,__READ       ,__fnmv2_bits);
__IO_REG32_BIT(FRNMV3,            0xFFF7C9B8,__READ       ,__fnmv3_bits);
__IO_REG32_BIT(FRMRC,             0xFFF7CB00,__READ_WRITE ,__fmrc_bits);
__IO_REG32_BIT(FRFRF,             0xFFF7CB04,__READ_WRITE ,__ffrf_bits);
__IO_REG32_BIT(FRFRFM,            0xFFF7CB08,__READ_WRITE ,__ffrfm_bits);
__IO_REG32_BIT(FRFCL,             0xFFF7CB0C,__READ_WRITE ,__ffcl_bits);
__IO_REG32_BIT(FRMHDS,            0xFFF7CB10,__READ_WRITE ,__fmhds_bits);
__IO_REG32_BIT(FRLDTS,            0xFFF7CB14,__READ       ,__fldts_bits);
__IO_REG32_BIT(FRFSR,             0xFFF7CB18,__READ       ,__ffsr_bits);
__IO_REG32_BIT(FRMHDF,            0xFFF7CB1C,__READ_WRITE ,__fmhdf_bits);
__IO_REG32_BIT(FRTXRQ1,           0xFFF7CB20,__READ       ,__ftxrq1_bits);
__IO_REG32_BIT(FRTXRQ2,           0xFFF7CB24,__READ       ,__ftxrq2_bits);
__IO_REG32_BIT(FRTXRQ3,           0xFFF7CB28,__READ       ,__ftxrq3_bits);
__IO_REG32_BIT(FRTXRQ4,           0xFFF7CB2C,__READ       ,__ftxrq4_bits);
__IO_REG32_BIT(FRNDAT1,           0xFFF7CB30,__READ       ,__fndat1_bits);
__IO_REG32_BIT(FRNDAT2,           0xFFF7CB34,__READ       ,__fndat2_bits);
__IO_REG32_BIT(FRNDAT3,           0xFFF7CB38,__READ       ,__fndat3_bits);
__IO_REG32_BIT(FRNDAT4,           0xFFF7CB3C,__READ       ,__fndat4_bits);
__IO_REG32_BIT(FRMBSC1,           0xFFF7CB40,__READ       ,__fmbsc1_bits);
__IO_REG32_BIT(FRMBSC2,           0xFFF7CB44,__READ       ,__fmbsc2_bits);
__IO_REG32_BIT(FRMBSC3,           0xFFF7CB48,__READ       ,__fmbsc3_bits);
__IO_REG32_BIT(FRMBSC4,           0xFFF7CB4C,__READ       ,__fmbsc4_bits);
__IO_REG32_BIT(FRCREL,            0xFFF7CBF0,__READ       ,__fcrel_bits);
__IO_REG32(    FRENDN,            0xFFF7CBF4,__READ       );
__IO_REG32(    FRWRDS1,           0xFFF7CC00,__READ_WRITE );
__IO_REG32(    FRWRDS2,           0xFFF7CC04,__READ_WRITE );
__IO_REG32(    FRWRDS3,           0xFFF7CC08,__READ_WRITE );
__IO_REG32(    FRWRDS4,           0xFFF7CC0C,__READ_WRITE );
__IO_REG32(    FRWRDS5,           0xFFF7CC10,__READ_WRITE );
__IO_REG32(    FRWRDS6,           0xFFF7CC14,__READ_WRITE );
__IO_REG32(    FRWRDS7,           0xFFF7CC18,__READ_WRITE );
__IO_REG32(    FRWRDS8,           0xFFF7CC1C,__READ_WRITE );
__IO_REG32(    FRWRDS9,           0xFFF7CC20,__READ_WRITE );
__IO_REG32(    FRWRDS10,          0xFFF7CC24,__READ_WRITE );
__IO_REG32(    FRWRDS11,          0xFFF7CC28,__READ_WRITE );
__IO_REG32(    FRWRDS12,          0xFFF7CC2C,__READ_WRITE );
__IO_REG32(    FRWRDS13,          0xFFF7CC30,__READ_WRITE );
__IO_REG32(    FRWRDS14,          0xFFF7CC34,__READ_WRITE );
__IO_REG32(    FRWRDS15,          0xFFF7CC38,__READ_WRITE );
__IO_REG32(    FRWRDS16,          0xFFF7CC3C,__READ_WRITE );
__IO_REG32(    FRWRDS17,          0xFFF7CC40,__READ_WRITE );
__IO_REG32(    FRWRDS18,          0xFFF7CC44,__READ_WRITE );
__IO_REG32(    FRWRDS19,          0xFFF7CC48,__READ_WRITE );
__IO_REG32(    FRWRDS20,          0xFFF7CC4C,__READ_WRITE );
__IO_REG32(    FRWRDS21,          0xFFF7CC50,__READ_WRITE );
__IO_REG32(    FRWRDS22,          0xFFF7CC54,__READ_WRITE );
__IO_REG32(    FRWRDS23,          0xFFF7CC58,__READ_WRITE );
__IO_REG32(    FRWRDS24,          0xFFF7CC5C,__READ_WRITE );
__IO_REG32(    FRWRDS25,          0xFFF7CC60,__READ_WRITE );
__IO_REG32(    FRWRDS26,          0xFFF7CC64,__READ_WRITE );
__IO_REG32(    FRWRDS27,          0xFFF7CC68,__READ_WRITE );
__IO_REG32(    FRWRDS28,          0xFFF7CC6C,__READ_WRITE );
__IO_REG32(    FRWRDS29,          0xFFF7CC70,__READ_WRITE );
__IO_REG32(    FRWRDS30,          0xFFF7CC74,__READ_WRITE );
__IO_REG32(    FRWRDS31,          0xFFF7CC78,__READ_WRITE );
__IO_REG32(    FRWRDS32,          0xFFF7CC7C,__READ_WRITE );
__IO_REG32(    FRWRDS33,          0xFFF7CC80,__READ_WRITE );
__IO_REG32(    FRWRDS34,          0xFFF7CC84,__READ_WRITE );
__IO_REG32(    FRWRDS35,          0xFFF7CC88,__READ_WRITE );
__IO_REG32(    FRWRDS36,          0xFFF7CC8C,__READ_WRITE );
__IO_REG32(    FRWRDS37,          0xFFF7CC90,__READ_WRITE );
__IO_REG32(    FRWRDS38,          0xFFF7CC94,__READ_WRITE );
__IO_REG32(    FRWRDS39,          0xFFF7CC98,__READ_WRITE );
__IO_REG32(    FRWRDS40,          0xFFF7CC9C,__READ_WRITE );
__IO_REG32(    FRWRDS41,          0xFFF7CCA0,__READ_WRITE );
__IO_REG32(    FRWRDS42,          0xFFF7CCA4,__READ_WRITE );
__IO_REG32(    FRWRDS43,          0xFFF7CCA8,__READ_WRITE );
__IO_REG32(    FRWRDS44,          0xFFF7CCAC,__READ_WRITE );
__IO_REG32(    FRWRDS45,          0xFFF7CCB0,__READ_WRITE );
__IO_REG32(    FRWRDS46,          0xFFF7CCB4,__READ_WRITE );
__IO_REG32(    FRWRDS47,          0xFFF7CCB8,__READ_WRITE );
__IO_REG32(    FRWRDS48,          0xFFF7CCBC,__READ_WRITE );
__IO_REG32(    FRWRDS49,          0xFFF7CCC0,__READ_WRITE );
__IO_REG32(    FRWRDS50,          0xFFF7CCC4,__READ_WRITE );
__IO_REG32(    FRWRDS51,          0xFFF7CCC8,__READ_WRITE );
__IO_REG32(    FRWRDS52,          0xFFF7CCCC,__READ_WRITE );
__IO_REG32(    FRWRDS53,          0xFFF7CCD0,__READ_WRITE );
__IO_REG32(    FRWRDS54,          0xFFF7CCD4,__READ_WRITE );
__IO_REG32(    FRWRDS55,          0xFFF7CCD8,__READ_WRITE );
__IO_REG32(    FRWRDS56,          0xFFF7CCDC,__READ_WRITE );
__IO_REG32(    FRWRDS57,          0xFFF7CCE0,__READ_WRITE );
__IO_REG32(    FRWRDS58,          0xFFF7CCE4,__READ_WRITE );
__IO_REG32(    FRWRDS59,          0xFFF7CCE8,__READ_WRITE );
__IO_REG32(    FRWRDS60,          0xFFF7CCEC,__READ_WRITE );
__IO_REG32(    FRWRDS61,          0xFFF7CCF0,__READ_WRITE );
__IO_REG32(    FRWRDS62,          0xFFF7CCF4,__READ_WRITE );
__IO_REG32(    FRWRDS63,          0xFFF7CCF8,__READ_WRITE );
__IO_REG32(    FRWRDS64,          0xFFF7CCFC,__READ_WRITE );
__IO_REG32_BIT(FRWRHS1,           0xFFF7CD00,__READ_WRITE ,__fwrhs1_bits);
__IO_REG32_BIT(FRWRHS2,           0xFFF7CD04,__READ_WRITE ,__fwrhs2_bits);
__IO_REG32_BIT(FRWRHS3,           0xFFF7CD08,__READ_WRITE ,__fwrhs3_bits);
__IO_REG32_BIT(FRIBCM,            0xFFF7CD10,__READ_WRITE ,__fibcm_bits);
__IO_REG32_BIT(FRIBCR,            0xFFF7CD14,__READ_WRITE ,__fibcr_bits);
__IO_REG32(    FRRDDS1,           0xFFF7CE00,__READ_WRITE );
__IO_REG32(    FRRDDS2,           0xFFF7CE04,__READ_WRITE );
__IO_REG32(    FRRDDS3,           0xFFF7CE08,__READ_WRITE );
__IO_REG32(    FRRDDS4,           0xFFF7CE0C,__READ_WRITE );
__IO_REG32(    FRRDDS5,           0xFFF7CE10,__READ_WRITE );
__IO_REG32(    FRRDDS6,           0xFFF7CE14,__READ_WRITE );
__IO_REG32(    FRRDDS7,           0xFFF7CE18,__READ_WRITE );
__IO_REG32(    FRRDDS8,           0xFFF7CE1C,__READ_WRITE );
__IO_REG32(    FRRDDS9,           0xFFF7CE20,__READ_WRITE );
__IO_REG32(    FRRDDS10,          0xFFF7CE24,__READ_WRITE );
__IO_REG32(    FRRDDS11,          0xFFF7CE28,__READ_WRITE );
__IO_REG32(    FRRDDS12,          0xFFF7CE2C,__READ_WRITE );
__IO_REG32(    FRRDDS13,          0xFFF7CE30,__READ_WRITE );
__IO_REG32(    FRRDDS14,          0xFFF7CE34,__READ_WRITE );
__IO_REG32(    FRRDDS15,          0xFFF7CE38,__READ_WRITE );
__IO_REG32(    FRRDDS16,          0xFFF7CE3C,__READ_WRITE );
__IO_REG32(    FRRDDS17,          0xFFF7CE40,__READ_WRITE );
__IO_REG32(    FRRDDS18,          0xFFF7CE44,__READ_WRITE );
__IO_REG32(    FRRDDS19,          0xFFF7CE48,__READ_WRITE );
__IO_REG32(    FRRDDS20,          0xFFF7CE4C,__READ_WRITE );
__IO_REG32(    FRRDDS21,          0xFFF7CE50,__READ_WRITE );
__IO_REG32(    FRRDDS22,          0xFFF7CE54,__READ_WRITE );
__IO_REG32(    FRRDDS23,          0xFFF7CE58,__READ_WRITE );
__IO_REG32(    FRRDDS24,          0xFFF7CE5C,__READ_WRITE );
__IO_REG32(    FRRDDS25,          0xFFF7CE60,__READ_WRITE );
__IO_REG32(    FRRDDS26,          0xFFF7CE64,__READ_WRITE );
__IO_REG32(    FRRDDS27,          0xFFF7CE68,__READ_WRITE );
__IO_REG32(    FRRDDS28,          0xFFF7CE6C,__READ_WRITE );
__IO_REG32(    FRRDDS29,          0xFFF7CE70,__READ_WRITE );
__IO_REG32(    FRRDDS30,          0xFFF7CE74,__READ_WRITE );
__IO_REG32(    FRRDDS31,          0xFFF7CE78,__READ_WRITE );
__IO_REG32(    FRRDDS32,          0xFFF7CE7C,__READ_WRITE );
__IO_REG32(    FRRDDS33,          0xFFF7CE80,__READ_WRITE );
__IO_REG32(    FRRDDS34,          0xFFF7CE84,__READ_WRITE );
__IO_REG32(    FRRDDS35,          0xFFF7CE88,__READ_WRITE );
__IO_REG32(    FRRDDS36,          0xFFF7CE8C,__READ_WRITE );
__IO_REG32(    FRRDDS37,          0xFFF7CE90,__READ_WRITE );
__IO_REG32(    FRRDDS38,          0xFFF7CE94,__READ_WRITE );
__IO_REG32(    FRRDDS39,          0xFFF7CE98,__READ_WRITE );
__IO_REG32(    FRRDDS40,          0xFFF7CE9C,__READ_WRITE );
__IO_REG32(    FRRDDS41,          0xFFF7CEA0,__READ_WRITE );
__IO_REG32(    FRRDDS42,          0xFFF7CEA4,__READ_WRITE );
__IO_REG32(    FRRDDS43,          0xFFF7CEA8,__READ_WRITE );
__IO_REG32(    FRRDDS44,          0xFFF7CEAC,__READ_WRITE );
__IO_REG32(    FRRDDS45,          0xFFF7CEB0,__READ_WRITE );
__IO_REG32(    FRRDDS46,          0xFFF7CEB4,__READ_WRITE );
__IO_REG32(    FRRDDS47,          0xFFF7CEB8,__READ_WRITE );
__IO_REG32(    FRRDDS48,          0xFFF7CEBC,__READ_WRITE );
__IO_REG32(    FRRDDS49,          0xFFF7CEC0,__READ_WRITE );
__IO_REG32(    FRRDDS50,          0xFFF7CEC4,__READ_WRITE );
__IO_REG32(    FRRDDS51,          0xFFF7CEC8,__READ_WRITE );
__IO_REG32(    FRRDDS52,          0xFFF7CECC,__READ_WRITE );
__IO_REG32(    FRRDDS53,          0xFFF7CED0,__READ_WRITE );
__IO_REG32(    FRRDDS54,          0xFFF7CED4,__READ_WRITE );
__IO_REG32(    FRRDDS55,          0xFFF7CED8,__READ_WRITE );
__IO_REG32(    FRRDDS56,          0xFFF7CEDC,__READ_WRITE );
__IO_REG32(    FRRDDS57,          0xFFF7CEE0,__READ_WRITE );
__IO_REG32(    FRRDDS58,          0xFFF7CEE4,__READ_WRITE );
__IO_REG32(    FRRDDS59,          0xFFF7CEE8,__READ_WRITE );
__IO_REG32(    FRRDDS60,          0xFFF7CEEC,__READ_WRITE );
__IO_REG32(    FRRDDS61,          0xFFF7CEF0,__READ_WRITE );
__IO_REG32(    FRRDDS62,          0xFFF7CEF4,__READ_WRITE );
__IO_REG32(    FRRDDS63,          0xFFF7CEF8,__READ_WRITE );
__IO_REG32(    FRRDDS64,          0xFFF7CEFC,__READ_WRITE );
__IO_REG32_BIT(FRRDHS1,           0xFFF7CF00,__READ_WRITE ,__frdhs1_bits);
__IO_REG32_BIT(FRRDHS2,           0xFFF7CF04,__READ       ,__frdhs2_bits);
__IO_REG32_BIT(FRRDHS3,           0xFFF7CF08,__READ_WRITE ,__frdhs3_bits);
__IO_REG32_BIT(FRMBS,             0xFFF7CF0C,__READ       ,__fmbs_bits);
__IO_REG32_BIT(FROBCM,            0xFFF7CF10,__READ_WRITE ,__fobcm_bits);
__IO_REG32_BIT(FROBCR,            0xFFF7CF14,__READ_WRITE ,__fobcr_bits);
__IO_REG32(    FTURAM_TCRx_BASE,  0xFF500000,__READ_WRITE );
__IO_REG32(    FTURAM_TCRPx_BASE, 0xFF500200,__READ_WRITE );

/***************************************************************************
 **
 ** NHET1 (High-End Timer)
 **
 ***************************************************************************/
__IO_REG32_BIT(HET1GCR,           0xFFF7B800,__READ_WRITE ,__hetgcr_bits);
__IO_REG32_BIT(HET1PFR,           0xFFF7B804,__READ_WRITE ,__hetpfr_bits);
__IO_REG32_BIT(HET1ADDR,          0xFFF7B808,__READ       ,__hetaddr_bits);
__IO_REG32_BIT(HET1OFF1,          0xFFF7B80C,__READ       ,__hetoff1_bits);
__IO_REG32_BIT(HET1OFF2,          0xFFF7B810,__READ       ,__hetoff2_bits);
__IO_REG32_BIT(HET1INTENAS,       0xFFF7B814,__READ_WRITE ,__hetintenas_bits);
__IO_REG32_BIT(HET1INTENAC,       0xFFF7B818,__READ_WRITE ,__hetintenac_bits);
__IO_REG32_BIT(HET1EXC1,          0xFFF7B81C,__READ_WRITE ,__hetexc1_bits);
__IO_REG32_BIT(HET1EXC2,          0xFFF7B820,__READ_WRITE ,__hetexc2_bits);
__IO_REG32_BIT(HET1PRY,           0xFFF7B824,__READ_WRITE ,__hetpry_bits);
__IO_REG32_BIT(HET1FLG,           0xFFF7B828,__READ_WRITE ,__hetflg_bits);
__IO_REG32_BIT(HET1AND,           0xFFF7B82C,__READ_WRITE ,__hetand_bits);
__IO_REG32_BIT(HET1HRSH,          0xFFF7B834,__READ_WRITE ,__hethrsh_bits);
__IO_REG32_BIT(HET1XOR,           0xFFF7B838,__READ_WRITE ,__hetxor_bits);
__IO_REG32_BIT(HET1REQENS,        0xFFF7B83C,__READ_WRITE ,__hetreqens_bits);
__IO_REG32_BIT(HET1REQENC,        0xFFF7B840,__READ_WRITE ,__hetreqenc_bits);
__IO_REG32_BIT(HET1REQDS,         0xFFF7B844,__READ_WRITE ,__hetreqds_bits);
__IO_REG32_BIT(HET1DIR,           0xFFF7B84C,__READ_WRITE ,__hetdir_bits);
__IO_REG32_BIT(HET1DIN,           0xFFF7B850,__READ       ,__hetdin_bits);
__IO_REG32_BIT(HET1DOUT,          0xFFF7B854,__READ_WRITE ,__hetdout_bits);
__IO_REG32_BIT(HET1DSET,          0xFFF7B858,__READ_WRITE ,__hetdset_bits);
__IO_REG32_BIT(HET1DCLR,          0xFFF7B85C,__READ_WRITE ,__hetdclr_bits);
__IO_REG32_BIT(HET1PDR,           0xFFF7B860,__READ_WRITE ,__hetpdr_bits);
__IO_REG32_BIT(HET1PULDIS,        0xFFF7B864,__READ_WRITE ,__hetpuldis_bits);
__IO_REG32_BIT(HET1PSL,           0xFFF7B868,__READ_WRITE ,__hetpsl_bits);
__IO_REG32_BIT(HET1PCR,           0xFFF7B874,__READ_WRITE ,__hetpcr_bits);
__IO_REG32_BIT(HET1PAR,           0xFFF7B878,__READ       ,__hetpar_bits);
__IO_REG32_BIT(HET1PPR,           0xFFF7B87C,__READ_WRITE ,__hetppr_bits);
__IO_REG32_BIT(HET1SFPRLD,        0xFFF7B880,__READ_WRITE ,__hetsfprld_bits);
__IO_REG32_BIT(HET1SFENA,         0xFFF7B884,__READ_WRITE ,__hetsfena_bits);
__IO_REG32_BIT(HET1LBPSEL,        0xFFF7B88C,__READ_WRITE ,__hetlbpsel_bits);
__IO_REG32_BIT(HET1LBPDIR,        0xFFF7B890,__READ_WRITE ,__hetlbpdir_bits);
__IO_REG32_BIT(HET1PINDIS,        0xFFF7B894,__READ_WRITE ,__hetpindis_bits);
__IO_REG32(    HET1P_RAM_BASE,    0xFF460000,__READ_WRITE );

/***************************************************************************
 **
 ** NHET2 (High-End Timer)
 **
 ***************************************************************************/
__IO_REG32_BIT(HET2GCR,           0xFFF7B900,__READ_WRITE ,__hetgcr_bits);
__IO_REG32_BIT(HET2PFR,           0xFFF7B904,__READ_WRITE ,__hetpfr_bits);
__IO_REG32_BIT(HET2ADDR,          0xFFF7B908,__READ       ,__hetaddr_bits);
__IO_REG32_BIT(HET2OFF1,          0xFFF7B90C,__READ       ,__hetoff1_bits);
__IO_REG32_BIT(HET2OFF2,          0xFFF7B910,__READ       ,__hetoff2_bits);
__IO_REG32_BIT(HET2INTENAS,       0xFFF7B914,__READ_WRITE ,__hetintenas_bits);
__IO_REG32_BIT(HET2INTENAC,       0xFFF7B918,__READ_WRITE ,__hetintenac_bits);
__IO_REG32_BIT(HET2EXC1,          0xFFF7B91C,__READ_WRITE ,__hetexc1_bits);
__IO_REG32_BIT(HET2EXC2,          0xFFF7B920,__READ_WRITE ,__hetexc2_bits);
__IO_REG32_BIT(HET2PRY,           0xFFF7B924,__READ_WRITE ,__hetpry_bits);
__IO_REG32_BIT(HET2FLG,           0xFFF7B928,__READ_WRITE ,__hetflg_bits);
__IO_REG32_BIT(HET2AND,           0xFFF7B92C,__READ_WRITE ,__hetand_bits);
__IO_REG32_BIT(HET2HRSH,          0xFFF7B934,__READ_WRITE ,__hethrsh_bits);
__IO_REG32_BIT(HET2XOR,           0xFFF7B938,__READ_WRITE ,__hetxor_bits);
__IO_REG32_BIT(HET2REQENS,        0xFFF7B93C,__READ_WRITE ,__hetreqens_bits);
__IO_REG32_BIT(HET2REQENC,        0xFFF7B940,__READ_WRITE ,__hetreqenc_bits);
__IO_REG32_BIT(HET2REQDS,         0xFFF7B944,__READ_WRITE ,__hetreqds_bits);
__IO_REG32_BIT(HET2DIR,           0xFFF7B94C,__READ_WRITE ,__hetdir_bits);
__IO_REG32_BIT(HET2DIN,           0xFFF7B950,__READ       ,__hetdin_bits);
__IO_REG32_BIT(HET2DOUT,          0xFFF7B954,__READ_WRITE ,__hetdout_bits);
__IO_REG32_BIT(HET2DSET,          0xFFF7B958,__READ_WRITE ,__hetdset_bits);
__IO_REG32_BIT(HET2DCLR,          0xFFF7B95C,__READ_WRITE ,__hetdclr_bits);
__IO_REG32_BIT(HET2PDR,           0xFFF7B960,__READ_WRITE ,__hetpdr_bits);
__IO_REG32_BIT(HET2PULDIS,        0xFFF7B964,__READ_WRITE ,__hetpuldis_bits);
__IO_REG32_BIT(HET2PSL,           0xFFF7B968,__READ_WRITE ,__hetpsl_bits);
__IO_REG32_BIT(HET2PCR,           0xFFF7B974,__READ_WRITE ,__hetpcr_bits);
__IO_REG32_BIT(HET2PAR,           0xFFF7B978,__READ       ,__hetpar_bits);
__IO_REG32_BIT(HET2PPR,           0xFFF7B97C,__READ_WRITE ,__hetppr_bits);
__IO_REG32_BIT(HET2SFPRLD,        0xFFF7B980,__READ_WRITE ,__hetsfprld_bits);
__IO_REG32_BIT(HET2SFENA,         0xFFF7B984,__READ_WRITE ,__hetsfena_bits);
__IO_REG32_BIT(HET2LBPSEL,        0xFFF7B98C,__READ_WRITE ,__hetlbpsel_bits);
__IO_REG32_BIT(HET2LBPDIR,        0xFFF7B990,__READ_WRITE ,__hetlbpdir_bits);
__IO_REG32_BIT(HET2PINDIS,        0xFFF7B994,__READ_WRITE ,__hetpindis_bits);
__IO_REG32(    HET2P_RAM_BASE,    0xFF440000,__READ_WRITE );

/***************************************************************************
 **
 ** HTU1 (High End Timer Transfer Unit)
 **
 ***************************************************************************/
__IO_REG32_BIT(HTU1GC,            0xFFF7A400,__READ_WRITE ,__htugc_bits);
__IO_REG32_BIT(HTU1CPENA,         0xFFF7A404,__READ_WRITE ,__htcpena_bits);
__IO_REG32_BIT(HTU1BUSY0,         0xFFF7A408,__READ_WRITE ,__htubusy0_bits);
__IO_REG32_BIT(HTU1BUSY1,         0xFFF7A40C,__READ_WRITE ,__htubusy1_bits);
__IO_REG32_BIT(HTU1BUSY2,         0xFFF7A410,__READ_WRITE ,__htubusy2_bits);
__IO_REG32_BIT(HTU1BUSY3,         0xFFF7A414,__READ_WRITE ,__htubusy3_bits);
__IO_REG32_BIT(HTU1ACPE,          0xFFF7A418,__READ_WRITE ,__htuacpe_bits);
__IO_REG32_BIT(HTU1RLBECTRL,      0xFFF7A420,__READ_WRITE ,__hturlbectrl_bits);
__IO_REG32_BIT(HTU1BFINTS,        0xFFF7A424,__READ_WRITE ,__htubfints_bits);
__IO_REG32_BIT(HTU1BFINTC,        0xFFF7A428,__READ_WRITE ,__htubfintc_bits);
__IO_REG32_BIT(HTU1INTMAP,        0xFFF7A42C,__READ_WRITE ,__htuintmap_bits);
__IO_REG32_BIT(HTU1INTOFF0,       0xFFF7A434,__READ       ,__htuintoff0_bits);
__IO_REG32_BIT(HTU1INTOFF1,       0xFFF7A438,__READ       ,__htuintoff1_bits);
__IO_REG32_BIT(HTU1BIM,           0xFFF7A43C,__READ_WRITE ,__htubim_bits);
__IO_REG32_BIT(HTU1RLOSTFL,       0xFFF7A440,__READ_WRITE ,__hturlostfl_bits);
__IO_REG32_BIT(HTU1BFINTFL,       0xFFF7A444,__READ_WRITE ,__htubfintfl_bits);
__IO_REG32_BIT(HTU1BERINTFL,      0xFFF7A448,__READ_WRITE ,__htuberintfl_bits);
__IO_REG32(    HTU1MP1S,          0xFFF7A44C,__READ_WRITE );
__IO_REG32(    HTU1MP1E,          0xFFF7A450,__READ_WRITE );
__IO_REG32_BIT(HTU1DCTRL,         0xFFF7A454,__READ_WRITE ,__htudctrl_bits);
__IO_REG32(    HTU1WPR,           0xFFF7A458,__READ_WRITE );
__IO_REG32(    HTU1WMR,           0xFFF7A45C,__READ_WRITE );
__IO_REG32_BIT(HTU1ID,            0xFFF7A460,__READ       ,__htuid_bits);
__IO_REG32_BIT(HTU1PCR,           0xFFF7A464,__READ_WRITE ,__htupcr_bits);
__IO_REG32_BIT(HTU1PAR,           0xFFF7A468,__READ_WRITE ,__htupar_bits);
__IO_REG32_BIT(HTU1MPCS,          0xFFF7A470,__READ_WRITE ,__htumpcs_bits);
__IO_REG32(    HTU1MP0S,          0xFFF7A474,__READ_WRITE );
__IO_REG32(    HTU1MP0E,          0xFFF7A478,__READ_WRITE );
__IO_REG32(    HTU1DCP0IFADDRA,   0xFF4E0000,__READ_WRITE );
__IO_REG32(    HTU1DCP0IFADDRB,   0xFF4E0004,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP0IHADDRCT,  0xFF4E0008,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU1DCP0ITCOUNT,   0xFF4E000C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU1DCP1IFADDRA,   0xFF4E0010,__READ_WRITE );
__IO_REG32(    HTU1DCP1IFADDRB,   0xFF4E0014,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP1IHADDRCT,  0xFF4E0018,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU1DCP1ITCOUNT,   0xFF4E001C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU1DCP2IFADDRA,   0xFF4E0020,__READ_WRITE );
__IO_REG32(    HTU1DCP2IFADDRB,   0xFF4E0024,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP2IHADDRCT,  0xFF4E0028,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU1DCP2ITCOUNT,   0xFF4E002C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU1DCP3IFADDRA,   0xFF4E0030,__READ_WRITE );
__IO_REG32(    HTU1DCP3IFADDRB,   0xFF4E0034,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP3IHADDRCT,  0xFF4E0038,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU1DCP3ITCOUNT,   0xFF4E003C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU1DCP4IFADDRA,   0xFF4E0040,__READ_WRITE );
__IO_REG32(    HTU1DCP4IFADDRB,   0xFF4E0044,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP4IHADDRCT,  0xFF4E0048,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU1DCP4ITCOUNT,   0xFF4E004C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU1DCP5IFADDRA,   0xFF4E0050,__READ_WRITE );
__IO_REG32(    HTU1DCP5IFADDRB,   0xFF4E0054,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP5IHADDRCT,  0xFF4E0058,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU1DCP5ITCOUNT,   0xFF4E005C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU1DCP6IFADDRA,   0xFF4E0060,__READ_WRITE );
__IO_REG32(    HTU1DCP6IFADDRB,   0xFF4E0064,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP6IHADDRCT,  0xFF4E0068,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU1DCP6ITCOUNT,   0xFF4E006C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU1DCP7IFADDRA,   0xFF4E0070,__READ_WRITE );
__IO_REG32(    HTU1DCP7IFADDRB,   0xFF4E0074,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP7IHADDRCT,  0xFF4E0078,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU1DCP7ITCOUNT,   0xFF4E007C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU1DCP0CFADDRA,   0xFF4E0100,__READ_WRITE );
__IO_REG32(    HTU1DCP0CFADDRB,   0xFF4E0104,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP0CFCOUNT,   0xFF4E0108,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU1DCP1CFADDRA,   0xFF4E0110,__READ_WRITE );
__IO_REG32(    HTU1DCP1CFADDRB,   0xFF4E0114,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP1CFCOUNT,   0xFF4E0118,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU1DCP2CFADDRA,   0xFF4E0120,__READ_WRITE );
__IO_REG32(    HTU1DCP2CFADDRB,   0xFF4E0124,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP2CFCOUNT,   0xFF4E0128,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU1DCP3CFADDRA,   0xFF4E0130,__READ_WRITE );
__IO_REG32(    HTU1DCP3CFADDRB,   0xFF4E0134,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP3CFCOUNT,   0xFF4E0138,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU1DCP4CFADDRA,   0xFF4E0140,__READ_WRITE );
__IO_REG32(    HTU1DCP4CFADDRB,   0xFF4E0144,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP4CFCOUNT,   0xFF4E0148,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU1DCP5CFADDRA,   0xFF4E0150,__READ_WRITE );
__IO_REG32(    HTU1DCP5CFADDRB,   0xFF4E0154,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP5CFCOUNT,   0xFF4E0158,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU1DCP6CFADDRA,   0xFF4E0160,__READ_WRITE );
__IO_REG32(    HTU1DCP6CFADDRB,   0xFF4E0164,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP6CFCOUNT,   0xFF4E0168,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU1DCP7CFADDRA,   0xFF4E0170,__READ_WRITE );
__IO_REG32(    HTU1DCP7CFADDRB,   0xFF4E0174,__READ_WRITE );
__IO_REG32_BIT(HTU1DCP7CFCOUNT,   0xFF4E0178,__READ_WRITE ,__htudcpcfcount_bits);

/***************************************************************************
 **
 ** HTU2 (High End Timer Transfer Unit)
 **
 ***************************************************************************/
__IO_REG32_BIT(HTU2GC,            0xFFF7A500,__READ_WRITE ,__htugc_bits);
__IO_REG32_BIT(HTU2CPENA,         0xFFF7A504,__READ_WRITE ,__htcpena_bits);
__IO_REG32_BIT(HTU2BUSY0,         0xFFF7A508,__READ_WRITE ,__htubusy0_bits);
__IO_REG32_BIT(HTU2BUSY1,         0xFFF7A50C,__READ_WRITE ,__htubusy1_bits);
__IO_REG32_BIT(HTU2BUSY2,         0xFFF7A510,__READ_WRITE ,__htubusy2_bits);
__IO_REG32_BIT(HTU2BUSY3,         0xFFF7A514,__READ_WRITE ,__htubusy3_bits);
__IO_REG32_BIT(HTU2ACPE,          0xFFF7A518,__READ_WRITE ,__htuacpe_bits);
__IO_REG32_BIT(HTU2RLBECTRL,      0xFFF7A520,__READ_WRITE ,__hturlbectrl_bits);
__IO_REG32_BIT(HTU2BFINTS,        0xFFF7A524,__READ_WRITE ,__htubfints_bits);
__IO_REG32_BIT(HTU2BFINTC,        0xFFF7A528,__READ_WRITE ,__htubfintc_bits);
__IO_REG32_BIT(HTU2INTMAP,        0xFFF7A52C,__READ_WRITE ,__htuintmap_bits);
__IO_REG32_BIT(HTU2INTOFF0,       0xFFF7A534,__READ       ,__htuintoff0_bits);
__IO_REG32_BIT(HTU2INTOFF1,       0xFFF7A538,__READ       ,__htuintoff1_bits);
__IO_REG32_BIT(HTU2BIM,           0xFFF7A53C,__READ_WRITE ,__htubim_bits);
__IO_REG32_BIT(HTU2RLOSTFL,       0xFFF7A540,__READ_WRITE ,__hturlostfl_bits);
__IO_REG32_BIT(HTU2BFINTFL,       0xFFF7A544,__READ_WRITE ,__htubfintfl_bits);
__IO_REG32_BIT(HTU2BERINTFL,      0xFFF7A548,__READ_WRITE ,__htuberintfl_bits);
__IO_REG32(    HTU2MP1S,          0xFFF7A54C,__READ_WRITE );
__IO_REG32(    HTU2MP1E,          0xFFF7A550,__READ_WRITE );
__IO_REG32_BIT(HTU2DCTRL,         0xFFF7A554,__READ_WRITE ,__htudctrl_bits);
__IO_REG32(    HTU2WPR,           0xFFF7A558,__READ_WRITE );
__IO_REG32(    HTU2WMR,           0xFFF7A55C,__READ_WRITE );
__IO_REG32_BIT(HTU2ID,            0xFFF7A560,__READ       ,__htuid_bits);
__IO_REG32_BIT(HTU2PCR,           0xFFF7A564,__READ_WRITE ,__htupcr_bits);
__IO_REG32_BIT(HTU2PAR,           0xFFF7A568,__READ_WRITE ,__htupar_bits);
__IO_REG32_BIT(HTU2MPCS,          0xFFF7A570,__READ_WRITE ,__htumpcs_bits);
__IO_REG32(    HTU2MP0S,          0xFFF7A574,__READ_WRITE );
__IO_REG32(    HTU2MP0E,          0xFFF7A578,__READ_WRITE );
__IO_REG32(    HTU2DCP0IFADDRA,   0xFF4C0000,__READ_WRITE );
__IO_REG32(    HTU2DCP0IFADDRB,   0xFF4C0004,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP0IHADDRCT,  0xFF4C0008,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU2DCP0ITCOUNT,   0xFF4C000C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU2DCP1IFADDRA,   0xFF4C0010,__READ_WRITE );
__IO_REG32(    HTU2DCP1IFADDRB,   0xFF4C0014,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP1IHADDRCT,  0xFF4C0018,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU2DCP1ITCOUNT,   0xFF4C001C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU2DCP2IFADDRA,   0xFF4C0020,__READ_WRITE );
__IO_REG32(    HTU2DCP2IFADDRB,   0xFF4C0024,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP2IHADDRCT,  0xFF4C0028,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU2DCP2ITCOUNT,   0xFF4C002C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU2DCP3IFADDRA,   0xFF4C0030,__READ_WRITE );
__IO_REG32(    HTU2DCP3IFADDRB,   0xFF4C0034,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP3IHADDRCT,  0xFF4C0038,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU2DCP3ITCOUNT,   0xFF4C003C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU2DCP4IFADDRA,   0xFF4C0040,__READ_WRITE );
__IO_REG32(    HTU2DCP4IFADDRB,   0xFF4C0044,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP4IHADDRCT,  0xFF4C0048,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU2DCP4ITCOUNT,   0xFF4C004C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU2DCP5IFADDRA,   0xFF4C0050,__READ_WRITE );
__IO_REG32(    HTU2DCP5IFADDRB,   0xFF4C0054,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP5IHADDRCT,  0xFF4C0058,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU2DCP5ITCOUNT,   0xFF4C005C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU2DCP6IFADDRA,   0xFF4C0060,__READ_WRITE );
__IO_REG32(    HTU2DCP6IFADDRB,   0xFF4C0064,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP6IHADDRCT,  0xFF4C0068,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU2DCP6ITCOUNT,   0xFF4C006C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU2DCP7IFADDRA,   0xFF4C0070,__READ_WRITE );
__IO_REG32(    HTU2DCP7IFADDRB,   0xFF4C0074,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP7IHADDRCT,  0xFF4C0078,__READ_WRITE ,__htudcpihaddrct_bits);
__IO_REG32_BIT(HTU2DCP7ITCOUNT,   0xFF4C007C,__READ_WRITE ,__htudcpitcount_bits);
__IO_REG32(    HTU2DCP0CFADDRA,   0xFF4C0100,__READ_WRITE );
__IO_REG32(    HTU2DCP0CFADDRB,   0xFF4C0104,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP0CFCOUNT,   0xFF4C0108,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU2DCP1CFADDRA,   0xFF4C0110,__READ_WRITE );
__IO_REG32(    HTU2DCP1CFADDRB,   0xFF4C0114,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP1CFCOUNT,   0xFF4C0118,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU2DCP2CFADDRA,   0xFF4C0120,__READ_WRITE );
__IO_REG32(    HTU2DCP2CFADDRB,   0xFF4C0124,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP2CFCOUNT,   0xFF4C0128,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU2DCP3CFADDRA,   0xFF4C0130,__READ_WRITE );
__IO_REG32(    HTU2DCP3CFADDRB,   0xFF4C0134,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP3CFCOUNT,   0xFF4C0138,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU2DCP4CFADDRA,   0xFF4C0140,__READ_WRITE );
__IO_REG32(    HTU2DCP4CFADDRB,   0xFF4C0144,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP4CFCOUNT,   0xFF4C0148,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU2DCP5CFADDRA,   0xFF4C0150,__READ_WRITE );
__IO_REG32(    HTU2DCP5CFADDRB,   0xFF4C0154,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP5CFCOUNT,   0xFF4C0158,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU2DCP6CFADDRA,   0xFF4C0160,__READ_WRITE );
__IO_REG32(    HTU2DCP6CFADDRB,   0xFF4C0164,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP6CFCOUNT,   0xFF4C0168,__READ_WRITE ,__htudcpcfcount_bits);
__IO_REG32(    HTU2DCP7CFADDRA,   0xFF4C0170,__READ_WRITE );
__IO_REG32(    HTU2DCP7CFADDRB,   0xFF4C0174,__READ_WRITE );
__IO_REG32_BIT(HTU2DCP7CFCOUNT,   0xFF4C0178,__READ_WRITE ,__htudcpcfcount_bits);

/***************************************************************************
 **
 ** DMA (Direct Memory Access Controller)
 **
 ***************************************************************************/
__IO_REG32_BIT(DMAGCTRL,          0xFFFFF000,__READ_WRITE ,__dmagctrl_bits);
__IO_REG32_BIT(DMAPEND,           0xFFFFF004,__READ       ,__dmapend_bits);
__IO_REG32_BIT(DMASTAT,           0xFFFFF00C,__READ       ,__dmastat_bits);
__IO_REG32_BIT(DMAHWCHENAS,       0xFFFFF014,__READ_WRITE ,__dmahwchenas_bits);
__IO_REG32_BIT(DMAHWCHENAR,       0xFFFFF01C,__READ_WRITE ,__dmahwchenar_bits);
__IO_REG32_BIT(DMASWCHENAS,       0xFFFFF024,__READ_WRITE ,__dmaswchenas_bits);
__IO_REG32_BIT(DMASWCHENAR,       0xFFFFF02C,__READ_WRITE ,__dmaswchenar_bits);
__IO_REG32_BIT(DMACHPRIOS,        0xFFFFF034,__READ_WRITE ,__dmachprios_bits);
__IO_REG32_BIT(DMACHPRIOR,        0xFFFFF03C,__READ_WRITE ,__dmachprior_bits);
__IO_REG32_BIT(DMAGCHIENAS,       0xFFFFF044,__READ_WRITE ,__dmagchienas_bits);
__IO_REG32_BIT(DMAGCHIENAR,       0xFFFFF04C,__READ_WRITE ,__dmagchienar_bits);
__IO_REG32_BIT(DMADREQASI0,       0xFFFFF054,__READ_WRITE ,__dmadreqasi0_bits);
__IO_REG32_BIT(DMADREQASI1,       0xFFFFF058,__READ_WRITE ,__dmadreqasi1_bits);
__IO_REG32_BIT(DMADREQASI2,       0xFFFFF05C,__READ_WRITE ,__dmadreqasi2_bits);
__IO_REG32_BIT(DMADREQASI3,       0xFFFFF060,__READ_WRITE ,__dmadreqasi3_bits);
__IO_REG32_BIT(DMAPAR0,           0xFFFFF094,__READ_WRITE ,__dmapar0_bits);
__IO_REG32_BIT(DMAPAR1,           0xFFFFF098,__READ_WRITE ,__dmapar1_bits);
__IO_REG32_BIT(DMAFTCMAP,         0xFFFFF0B4,__READ_WRITE ,__dmaftcmap_bits);
__IO_REG32_BIT(DMALFSMAP,         0xFFFFF0BC,__READ_WRITE ,__dmalfsmap_bits);
__IO_REG32_BIT(DMAHBCMAP,         0xFFFFF0C4,__READ_WRITE ,__dmahbcmap_bits);
__IO_REG32_BIT(DMABTCMAP,         0xFFFFF0CC,__READ_WRITE ,__dmabtcmap_bits);
__IO_REG32_BIT(DMABERMAP,         0xFFFFF0D4,__READ_WRITE ,__dmabermap_bits);
__IO_REG32_BIT(DMAFTCINTENAS,     0xFFFFF0DC,__READ_WRITE ,__dmaftcintenas_bits);
__IO_REG32_BIT(DMAFTCINTENAR,     0xFFFFF0E4,__READ_WRITE ,__dmaftcintenar_bits);
__IO_REG32_BIT(DMALFSINTENAS,     0xFFFFF0EC,__READ_WRITE ,__dmalfsintenas_bits);
__IO_REG32_BIT(DMALFSINTENAR,     0xFFFFF0F4,__READ_WRITE ,__dmalfsintenar_bits);
__IO_REG32_BIT(DMAHBCINTENAS,     0xFFFFF0FC,__READ       ,__dmahbcintenas_bits);
__IO_REG32_BIT(DMAHBCINTENAR,     0xFFFFF104,__READ_WRITE ,__dmahbcintenar_bits);
__IO_REG32_BIT(DMABTCINTENAS,     0xFFFFF10C,__READ       ,__dmabtcintenas_bits);
__IO_REG32_BIT(DMABTCINTENAR,     0xFFFFF114,__READ_WRITE ,__dmabtcintenar_bits);
__IO_REG32_BIT(DMAGINTFLAG,       0xFFFFF11C,__READ       ,__dmagintflag_bits);
__IO_REG32_BIT(DMAFTCFLAG,        0xFFFFF124,__READ_WRITE ,__dmaftcflag_bits);
__IO_REG32_BIT(DMALFSFLAG,        0xFFFFF12C,__READ_WRITE ,__dmalfsflag_bits);
__IO_REG32_BIT(DMAHBCFLAG,        0xFFFFF134,__READ_WRITE ,__dmahbcflag_bits);
__IO_REG32_BIT(DMABTCFLAG,        0xFFFFF13C,__READ_WRITE ,__dmabtcflag_bits);
__IO_REG32_BIT(DMABERFLAG,        0xFFFFF144,__READ       ,__dmaberflag_bits);
__IO_REG32_BIT(DMAFTCAOFFSET,     0xFFFFF14C,__READ       ,__dmaftcaoffset_bits);
__IO_REG32_BIT(DMALFSAOFFSET,     0xFFFFF150,__READ       ,__dmalfsaoffset_bits);
__IO_REG32_BIT(DMAHBCAOFFSET,     0xFFFFF154,__READ       ,__dmahbcaoffset_bits);
__IO_REG32_BIT(DMABTCAOFFSET,     0xFFFFF158,__READ       ,__dmabtcaoffset_bits);
__IO_REG32_BIT(DMABERAOFFSET,     0xFFFFF15C,__READ       ,__dmaberaoffset_bits);
__IO_REG32_BIT(DMAFTCBOFFSET,     0xFFFFF160,__READ       ,__dmaftcboffset_bits);
__IO_REG32_BIT(DMALFSBOFFSET,     0xFFFFF164,__READ       ,__dmalfsboffset_bits);
__IO_REG32_BIT(DMAHBCBOFFSET,     0xFFFFF168,__READ       ,__dmahbcboffset_bits);
__IO_REG32_BIT(DMABTCBOFFSET,     0xFFFFF16C,__READ       ,__dmabtcboffset_bits);
__IO_REG32_BIT(DMABERBOFFSET,     0xFFFFF170,__READ       ,__dmaberboffset_bits);
__IO_REG32_BIT(DMAPTCRL,          0xFFFFF178,__READ_WRITE ,__dmaptcrl_bits);
__IO_REG32_BIT(DMARTCTRL,         0xFFFFF17C,__READ_WRITE ,__dmartctrl_bits);
__IO_REG32_BIT(DMADCTRL,          0xFFFFF180,__READ_WRITE ,__dmadctrl_bits);
__IO_REG32(    DMAWPR,            0xFFFFF184,__READ_WRITE );
__IO_REG32(    DMAWMR,            0xFFFFF188,__READ_WRITE );
__IO_REG32(    DMAPBACSADDR,      0xFFFFF198,__READ       );
__IO_REG32(    DMAPBACDADDR,      0xFFFFF19C,__READ       );
__IO_REG32_BIT(DMAPBACTC,         0xFFFFF1A0,__READ       ,__dmapbactc_bits);
__IO_REG32_BIT(DMAPCR,            0xFFFFF1A8,__READ_WRITE ,__dmapcr_bits);
__IO_REG32_BIT(DMAPAR,            0xFFFFF1AC,__READ       ,__dmapar_bits);
__IO_REG32_BIT(DMAMPCTRL,         0xFFFFF1B0,__READ_WRITE ,__dmampctrl_bits);
__IO_REG32_BIT(DMAMPST,           0xFFFFF1B4,__READ_WRITE ,__dmampst_bits);
__IO_REG32(    DMAMPR0S,          0xFFFFF1B8,__READ_WRITE );
__IO_REG32(    DMAMPR0E,          0xFFFFF1BC,__READ_WRITE );
__IO_REG32(    DMAMPR1S,          0xFFFFF1C0,__READ_WRITE );
__IO_REG32(    DMAMPR1E,          0xFFFFF1C4,__READ_WRITE );
__IO_REG32(    DMAMPR2S,          0xFFFFF1C8,__READ_WRITE );
__IO_REG32(    DMAMPR2E,          0xFFFFF1CC,__READ_WRITE );
__IO_REG32(    DMAMPR3S,          0xFFFFF1D0,__READ_WRITE );
__IO_REG32(    DMAMPR3E,          0xFFFFF1D4,__READ_WRITE );
__IO_REG32(    DMACP0ISADDR,      0xFFF80000,__READ_WRITE );
__IO_REG32(    DMACP0IDADDR,      0xFFF80004,__READ_WRITE );
__IO_REG32_BIT(DMACP0ITCOUNT,     0xFFF80008,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP0CHCTRL,      0xFFF80010,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP0EIOFF,       0xFFF80014,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP0FIOFF,       0xFFF80018,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP1ISADDR,      0xFFF80020,__READ_WRITE );
__IO_REG32(    DMACP1IDADDR,      0xFFF80024,__READ_WRITE );
__IO_REG32_BIT(DMACP1ITCOUNT,     0xFFF80028,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP1CHCTRL,      0xFFF80030,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP1EIOFF,       0xFFF80034,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP1FIOFF,       0xFFF80038,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP2ISADDR,      0xFFF80040,__READ_WRITE );
__IO_REG32(    DMACP2IDADDR,      0xFFF80044,__READ_WRITE );
__IO_REG32_BIT(DMACP2ITCOUNT,     0xFFF80048,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP2CHCTRL,      0xFFF80050,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP2EIOFF,       0xFFF80054,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP2FIOFF,       0xFFF80058,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP3ISADDR,      0xFFF80060,__READ_WRITE );
__IO_REG32(    DMACP3IDADDR,      0xFFF80064,__READ_WRITE );
__IO_REG32_BIT(DMACP3ITCOUNT,     0xFFF80068,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP3CHCTRL,      0xFFF80070,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP3EIOFF,       0xFFF80074,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP3FIOFF,       0xFFF80078,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP4ISADDR,      0xFFF80080,__READ_WRITE );
__IO_REG32(    DMACP4IDADDR,      0xFFF80084,__READ_WRITE );
__IO_REG32_BIT(DMACP4ITCOUNT,     0xFFF80088,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP4CHCTRL,      0xFFF80090,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP4EIOFF,       0xFFF80094,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP4FIOFF,       0xFFF80098,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP5ISADDR,      0xFFF800A0,__READ_WRITE );
__IO_REG32(    DMACP5IDADDR,      0xFFF800A4,__READ_WRITE );
__IO_REG32_BIT(DMACP5ITCOUNT,     0xFFF800A8,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP5CHCTRL,      0xFFF800B0,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP5EIOFF,       0xFFF800B4,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP5FIOFF,       0xFFF800B8,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP6ISADDR,      0xFFF800C0,__READ_WRITE );
__IO_REG32(    DMACP6IDADDR,      0xFFF800C4,__READ_WRITE );
__IO_REG32_BIT(DMACP6ITCOUNT,     0xFFF800C8,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP6CHCTRL,      0xFFF800D0,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP6EIOFF,       0xFFF800D4,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP6FIOFF,       0xFFF800D8,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP7ISADDR,      0xFFF800E0,__READ_WRITE );
__IO_REG32(    DMACP7IDADDR,      0xFFF800E4,__READ_WRITE );
__IO_REG32_BIT(DMACP7ITCOUNT,     0xFFF800E8,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP7CHCTRL,      0xFFF800F0,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP7EIOFF,       0xFFF800F4,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP7FIOFF,       0xFFF800F8,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP8ISADDR,      0xFFF80100,__READ_WRITE );
__IO_REG32(    DMACP8IDADDR,      0xFFF80104,__READ_WRITE );
__IO_REG32_BIT(DMACP8ITCOUNT,     0xFFF80108,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP8CHCTRL,      0xFFF80110,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP8EIOFF,       0xFFF80114,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP8FIOFF,       0xFFF80118,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP9ISADDR,      0xFFF80120,__READ_WRITE );
__IO_REG32(    DMACP9IDADDR,      0xFFF80124,__READ_WRITE );
__IO_REG32_BIT(DMACP9ITCOUNT,     0xFFF80128,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP9CHCTRL,      0xFFF80130,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP9EIOFF,       0xFFF80134,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP9FIOFF,       0xFFF80138,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP10ISADDR,     0xFFF80140,__READ_WRITE );
__IO_REG32(    DMACP10IDADDR,     0xFFF80144,__READ_WRITE );
__IO_REG32_BIT(DMACP10ITCOUNT,    0xFFF80148,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP10CHCTRL,     0xFFF80150,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP10EIOFF,      0xFFF80154,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP10FIOFF,      0xFFF80158,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP11ISADDR,     0xFFF80160,__READ_WRITE );
__IO_REG32(    DMACP11IDADDR,     0xFFF80164,__READ_WRITE );
__IO_REG32_BIT(DMACP11ITCOUNT,    0xFFF80168,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP11CHCTRL,     0xFFF80170,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP11EIOFF,      0xFFF80174,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP11FIOFF,      0xFFF80178,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP12ISADDR,     0xFFF80180,__READ_WRITE );
__IO_REG32(    DMACP12IDADDR,     0xFFF80184,__READ_WRITE );
__IO_REG32_BIT(DMACP12ITCOUNT,    0xFFF80188,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP12CHCTRL,     0xFFF80190,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP12EIOFF,      0xFFF80194,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP12FIOFF,      0xFFF80198,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP13ISADDR,     0xFFF801A0,__READ_WRITE );
__IO_REG32(    DMACP13IDADDR,     0xFFF801A4,__READ_WRITE );
__IO_REG32_BIT(DMACP13ITCOUNT,    0xFFF801A8,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP13CHCTRL,     0xFFF801B0,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP13EIOFF,      0xFFF801B4,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP13FIOFF,      0xFFF801B8,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP14ISADDR,     0xFFF801C0,__READ_WRITE );
__IO_REG32(    DMACP14IDADDR,     0xFFF801C4,__READ_WRITE );
__IO_REG32_BIT(DMACP14ITCOUNT,    0xFFF801C8,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP14CHCTRL,     0xFFF801D0,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP14EIOFF,      0xFFF801D4,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP14FIOFF,      0xFFF801D8,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP15ISADDR,     0xFFF801E0,__READ_WRITE );
__IO_REG32(    DMACP15IDADDR,     0xFFF801E4,__READ_WRITE );
__IO_REG32_BIT(DMACP15ITCOUNT,    0xFFF801E8,__READ_WRITE ,__dmacpitcount_bits);
__IO_REG32_BIT(DMACP15CHCTRL,     0xFFF801F0,__READ_WRITE ,__dmachctrl_bits);
__IO_REG32_BIT(DMACP15EIOFF,      0xFFF801F4,__READ_WRITE ,__dmacpeioff_bits);
__IO_REG32_BIT(DMACP15FIOFF,      0xFFF801F8,__READ_WRITE ,__dmacpfioff_bits);
__IO_REG32(    DMACP0CSADDR,      0xFFF80800,__READ       );
__IO_REG32(    DMACP0CDADDR,      0xFFF80804,__READ       );
__IO_REG32_BIT(DMACP0CTCOUNT,     0xFFF80808,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP1CSADDR,      0xFFF80810,__READ       );
__IO_REG32(    DMACP1CDADDR,      0xFFF80814,__READ       );
__IO_REG32_BIT(DMACP1CTCOUNT,     0xFFF80818,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP2CSADDR,      0xFFF80820,__READ       );
__IO_REG32(    DMACP2CDADDR,      0xFFF80824,__READ       );
__IO_REG32_BIT(DMACP2CTCOUNT,     0xFFF80828,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP3CSADDR,      0xFFF80830,__READ       );
__IO_REG32(    DMACP3CDADDR,      0xFFF80834,__READ       );
__IO_REG32_BIT(DMACP3CTCOUNT,     0xFFF80838,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP4CSADDR,      0xFFF80840,__READ       );
__IO_REG32(    DMACP4CDADDR,      0xFFF80844,__READ       );
__IO_REG32_BIT(DMACP4CTCOUNT,     0xFFF80848,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP5CSADDR,      0xFFF80850,__READ       );
__IO_REG32(    DMACP5CDADDR,      0xFFF80854,__READ       );
__IO_REG32_BIT(DMACP5CTCOUNT,     0xFFF80858,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP6CSADDR,      0xFFF80860,__READ       );
__IO_REG32(    DMACP6CDADDR,      0xFFF80864,__READ       );
__IO_REG32_BIT(DMACP6CTCOUNT,     0xFFF80868,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP7CSADDR,      0xFFF80870,__READ       );
__IO_REG32(    DMACP7CDADDR,      0xFFF80874,__READ       );
__IO_REG32_BIT(DMACP7CTCOUNT,     0xFFF80878,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP8CSADDR,      0xFFF80880,__READ       );
__IO_REG32(    DMACP8CDADDR,      0xFFF80884,__READ       );
__IO_REG32_BIT(DMACP8CTCOUNT,     0xFFF80888,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP9CSADDR,      0xFFF80890,__READ       );
__IO_REG32(    DMACP9CDADDR,      0xFFF80894,__READ       );
__IO_REG32_BIT(DMACP9CTCOUNT,     0xFFF80898,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP10CSADDR,     0xFFF808A0,__READ       );
__IO_REG32(    DMACP10CDADDR,     0xFFF808A4,__READ       );
__IO_REG32_BIT(DMACP10CTCOUNT,    0xFFF808A8,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP11CSADDR,     0xFFF808B0,__READ       );
__IO_REG32(    DMACP11CDADDR,     0xFFF808B4,__READ       );
__IO_REG32_BIT(DMACP11CTCOUNT,    0xFFF808B8,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP12CSADDR,     0xFFF808C0,__READ       );
__IO_REG32(    DMACP12CDADDR,     0xFFF808C4,__READ       );
__IO_REG32_BIT(DMACP12CTCOUNT,    0xFFF808C8,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP13CSADDR,     0xFFF808D0,__READ       );
__IO_REG32(    DMACP13CDADDR,     0xFFF808D4,__READ       );
__IO_REG32_BIT(DMACP13CTCOUNT,    0xFFF808D8,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP14CSADDR,     0xFFF808E0,__READ       );
__IO_REG32(    DMACP14CDADDR,     0xFFF808E4,__READ       );
__IO_REG32_BIT(DMACP14CTCOUNT,    0xFFF808E8,__READ       ,__dmacpctcount_bits);
__IO_REG32(    DMACP15CSADDR,     0xFFF808F0,__READ       );
__IO_REG32(    DMACP15CDADDR,     0xFFF808F4,__READ       );
__IO_REG32_BIT(DMACP15CTCOUNT,    0xFFF808F8,__READ       ,__dmacpctcount_bits);

/***************************************************************************
 **
 ** RTI/DWWD
 **
 ***************************************************************************/
__IO_REG32_BIT(RTIGCTRL,          0xFFFFFC00,__READ_WRITE ,__rtigctrl_bits);
__IO_REG32_BIT(RTITBCTRL,         0xFFFFFC04,__READ_WRITE ,__rtitbctrl_bits);
__IO_REG32_BIT(RTICAPCTRL,        0xFFFFFC08,__READ_WRITE ,__rticapctrl_bits);
__IO_REG32_BIT(RTICOMPCTRL,       0xFFFFFC0C,__READ_WRITE ,__rticompctrl_bits);
__IO_REG32(    RTIFRC0,           0xFFFFFC10,__READ_WRITE );
__IO_REG32(    RTIUC0,            0xFFFFFC14,__READ_WRITE );
__IO_REG32(    RTICPUC0,          0xFFFFFC18,__READ_WRITE );
__IO_REG32(    RTICAFRC0,         0xFFFFFC20,__READ       );
__IO_REG32(    RTICAUC0,          0xFFFFFC24,__READ       );
__IO_REG32(    RTIFRC1,           0xFFFFFC30,__READ_WRITE );
__IO_REG32(    RTIUC1,            0xFFFFFC34,__READ_WRITE );
__IO_REG32(    RTICPUC1,          0xFFFFFC38,__READ_WRITE );
__IO_REG32(    RTICAFRC1,         0xFFFFFC40,__READ       );
__IO_REG32(    RTICAUC1,          0xFFFFFC44,__READ       );
__IO_REG32(    RTICOMP0,          0xFFFFFC50,__READ_WRITE );
__IO_REG32(    RTIUDCP0,          0xFFFFFC54,__READ_WRITE );
__IO_REG32(    RTICOMP1,          0xFFFFFC58,__READ_WRITE );
__IO_REG32(    RTIUDCP1,          0xFFFFFC5C,__READ_WRITE );
__IO_REG32(    RTICOMP2,          0xFFFFFC60,__READ_WRITE );
__IO_REG32(    RTIUDCP2,          0xFFFFFC64,__READ_WRITE );
__IO_REG32(    RTICOMP3,          0xFFFFFC68,__READ_WRITE );
__IO_REG32(    RTIUDCP3,          0xFFFFFC6C,__READ_WRITE );
__IO_REG32(    RTITBLCOMP,        0xFFFFFC70,__READ_WRITE );
__IO_REG32(    RTITBHCOMP,        0xFFFFFC74,__READ_WRITE );
__IO_REG32_BIT(RTISETINTENA,      0xFFFFFC80,__READ_WRITE ,__rtisetintena_bits);
__IO_REG32_BIT(RTICLEARINTENA,    0xFFFFFC84,__READ_WRITE ,__rticlearintena_bits);
__IO_REG32_BIT(RTIINTFLAG,        0xFFFFFC88,__READ_WRITE ,__rtiintflag_bits);
__IO_REG32(    RTIDWDCTRL,        0xFFFFFC90,__READ_WRITE );
__IO_REG32_BIT(RTIDWDPRLD,        0xFFFFFC94,__READ_WRITE ,__rtidwdprld_bits);
__IO_REG32_BIT(RTIWDSTATUS,       0xFFFFFC98,__READ_WRITE ,__rtiwdstatus_bits);
__IO_REG32_BIT(RTIWDKEY,          0xFFFFFC9C,__READ_WRITE ,__rtiwdkey_bits);
__IO_REG32_BIT(RTIDWDCNTR,        0xFFFFFCA0,__READ       ,__rtidwdcntr_bits);
__IO_REG32_BIT(RTIWWDRXNCTRL,     0xFFFFFCA4,__READ_WRITE ,__rtiwwdrxnctrl_bits);
__IO_REG32(    RTIWWDSIZECTRL,    0xFFFFFCA8,__READ_WRITE );
__IO_REG32_BIT(RTIINTCLRENABLE,   0xFFFFFCAC,__READ_WRITE ,__rtiintclrenable_bits);
__IO_REG32(    RTICOMP0CLR,       0xFFFFFCB0,__READ_WRITE );
__IO_REG32(    RTICOMP1CLR,       0xFFFFFCB4,__READ_WRITE );
__IO_REG32(    RTICOMP2CLR,       0xFFFFFCB8,__READ_WRITE );
__IO_REG32(    RTICOMP3CLR,       0xFFFFFCBC,__READ_WRITE );

/***************************************************************************
 **
 ** CRC (Cyclic Redundancy Check Controller)
 **
 ***************************************************************************/
__IO_REG32_BIT(CRC_CTRL0,         0xFE000000,__READ_WRITE ,__crc_ctrl0_bits);
__IO_REG32_BIT(CRC_CTRL1,         0xFE000008,__READ_WRITE ,__crc_ctrl1_bits);
__IO_REG32_BIT(CRC_CTRL2,         0xFE000010,__READ_WRITE ,__crc_ctrl2_bits);
__IO_REG32_BIT(CRC_INTS,          0xFE000018,__READ_WRITE ,__crc_ints_bits);
__IO_REG32_BIT(CRC_INTR,          0xFE000020,__READ_WRITE ,__crc_intr_bits);
__IO_REG32_BIT(CRC_STATUS,        0xFE000028,__READ_WRITE ,__crc_status_bits);
__IO_REG32_BIT(CRC_INT_OFFSET_REG,0xFE000030,__READ       ,__crc_int_offset_reg_bits);
__IO_REG32_BIT(CRC_BUSY,          0xFE000038,__READ       ,__crc_busy_bits);
__IO_REG32_BIT(CRC_PCOUNT_REG1,   0xFE000040,__READ_WRITE ,__crc_pcount_reg_bits);
__IO_REG32_BIT(CRC_SCOUNT_REG1,   0xFE000044,__READ_WRITE ,__crc_scount_reg_bits);
__IO_REG32_BIT(CRC_CURSEC_REG1,   0xFE000048,__READ       ,__crc_cursec_reg_bits);
__IO_REG32_BIT(CRC_WDTOPLD1,      0xFE00004C,__READ_WRITE ,__crc_wdtopld_bits);
__IO_REG32_BIT(CRC_BCTOPLD1,      0xFE000050,__READ_WRITE ,__crc_bctopld_bits);
__IO_REG32(    PSA_SIGREGL1,      0xFE000060,__READ_WRITE );
__IO_REG32(    PSA_SIGREGH1,      0xFE000064,__READ_WRITE );
__IO_REG32(    CRC_REGL1,         0xFE000068,__READ_WRITE );
__IO_REG32(    CRC_REGH1,         0xFE00006C,__READ_WRITE );
__IO_REG32(    PSA_SECSIGREGL1,   0xFE000070,__READ       );
__IO_REG32(    PSA_SECSIGREGH1,   0xFE000074,__READ       );
__IO_REG32(    RAW_DATAREGL1,     0xFE000078,__READ       );
__IO_REG32(    RAW_DATAREGH1,     0xFE00007C,__READ       );
__IO_REG32_BIT(CRC_PCOUNT_REG2,   0xFE000080,__READ_WRITE ,__crc_pcount_reg_bits);
__IO_REG32_BIT(CRC_SCOUNT_REG2,   0xFE000084,__READ_WRITE ,__crc_scount_reg_bits);
__IO_REG32_BIT(CRC_CURSEC_REG2,   0xFE000088,__READ       ,__crc_cursec_reg_bits);
__IO_REG32_BIT(CRC_WDTOPLD2,      0xFE00008C,__READ_WRITE ,__crc_wdtopld_bits);
__IO_REG32_BIT(CRC_BCTOPLD2,      0xFE000090,__READ_WRITE ,__crc_bctopld_bits);
__IO_REG32(    PSA_SIGREGL2,      0xFE0000A0,__READ_WRITE );
__IO_REG32(    PSA_SIGREGH2,      0xFE0000A4,__READ_WRITE );
__IO_REG32(    CRC_REGL2,         0xFE0000A8,__READ_WRITE );
__IO_REG32(    CRC_REGH2,         0xFE0000AC,__READ_WRITE );
__IO_REG32(    PSA_SECSIGREGL2,   0xFE0000B0,__READ       );
__IO_REG32(    PSA_SECSIGREGH2,   0xFE0000B4,__READ       );
__IO_REG32(    RAW_DATAREGL2,     0xFE0000B8,__READ       );
__IO_REG32(    RAW_DATAREGH2,     0xFE0000BC,__READ       );
__IO_REG32_BIT(CRC_TRACE_BUS_SEL, 0xFE000140,__READ_WRITE ,__crc_trace_bus_sel_bits);

/***************************************************************************
 **
 ** CCM-R4F (CPU Compare R4F)
 **
 ***************************************************************************/
__IO_REG32_BIT(CCMSR,             0xFFFFF600,__READ_WRITE ,__ccmsr_bits);
__IO_REG32_BIT(CCMKEYR,           0xFFFFF604,__READ_WRITE ,__ccmkeyr_bits);

/***************************************************************************
 **
 ** ESM (Error Signaling Module)
 **
 ***************************************************************************/
__IO_REG32_BIT(ESMEEPAPR1,        0xFFFFF500,__READ_WRITE ,__esmeepapr1_bits);
__IO_REG32_BIT(ESMDEPAPR1,        0xFFFFF504,__READ_WRITE ,__esmdepapr1_bits);
__IO_REG32_BIT(ESMIESR1,          0xFFFFF508,__READ_WRITE ,__esmiesr1_bits);
__IO_REG32_BIT(ESMIECR1,          0xFFFFF50C,__READ_WRITE ,__esmiecr1_bits);
__IO_REG32_BIT(ESMILSR1,          0xFFFFF510,__READ_WRITE ,__esmilsr1_bits);
__IO_REG32_BIT(ESMILCR1,          0xFFFFF514,__READ_WRITE ,__esmilcr1_bits);
__IO_REG32_BIT(ESMSR1,            0xFFFFF518,__READ_WRITE ,__esmsr_bits);
__IO_REG32_BIT(ESMSR2,            0xFFFFF51C,__READ_WRITE ,__esmsr_bits);
__IO_REG32_BIT(ESMSR3,            0xFFFFF520,__READ_WRITE ,__esmsr_bits);
__IO_REG32_BIT(ESMEPSR,           0xFFFFF524,__READ       ,__esmepsr_bits);
__IO_REG32_BIT(ESMIOFFHR,         0xFFFFF528,__READ       ,__esmioffhr_bits);
__IO_REG32_BIT(ESMIOFFLR,         0xFFFFF52C,__READ       ,__esmiofflr_bits);
__IO_REG32_BIT(ESMLTCR,           0xFFFFF530,__READ       ,__esmltcr_bits);
__IO_REG32_BIT(ESMLTCPR,          0xFFFFF534,__READ_WRITE ,__esmltcpr_bits);
__IO_REG32_BIT(ESMEKR,            0xFFFFF538,__READ_WRITE ,__esmekr_bits);
__IO_REG32_BIT(ESMSSR2,           0xFFFFF53C,__READ_WRITE ,__esmsr_bits);
__IO_REG32_BIT(ESMIEPSR4,         0xFFFFF540,__READ_WRITE ,__esmiepsr4_bits);
__IO_REG32_BIT(ESMIEPCR4,         0xFFFFF544,__READ_WRITE ,__esmiepcr4_bits);
__IO_REG32_BIT(ESMIESR4,          0xFFFFF548,__READ_WRITE ,__esmiesr4_bits);
__IO_REG32_BIT(ESMIECR4,          0xFFFFF54C,__READ_WRITE ,__esmiecr4_bits);
__IO_REG32_BIT(ESMILSR4,          0xFFFFF550,__READ_WRITE ,__esmilsr4_bits);
__IO_REG32_BIT(ESMILCR4,          0xFFFFF554,__READ_WRITE ,__esmilcr4_bits);
__IO_REG32_BIT(ESMSR4,            0xFFFFF558,__READ_WRITE ,__esmsr4_bits);

/***************************************************************************
 **
 ** DMM (Data Modification Module)
 **
 ***************************************************************************/
__IO_REG32_BIT(DMMGLBCTRL,        0xFFFFF700,__READ_WRITE ,__dmmglbctrl_bits);
__IO_REG32_BIT(DMMINTSET,         0xFFFFF704,__READ_WRITE ,__dmmintset_bits);
__IO_REG32_BIT(DMMINTCLR,         0xFFFFF708,__READ_WRITE ,__dmmintset_bits);
__IO_REG32_BIT(DMMINTLVL,         0xFFFFF70C,__READ_WRITE ,__dmmintset_bits);
__IO_REG32_BIT(DMMINTFLG,         0xFFFFF710,__READ_WRITE ,__dmmintset_bits);
__IO_REG32_BIT(DMMOFF1,           0xFFFFF714,__READ       ,__dmmoff_bits);
__IO_REG32_BIT(DMMOFF2,           0xFFFFF718,__READ       ,__dmmoff_bits);
__IO_REG32(    DMMDDMDEST,        0xFFFFF71C,__READ_WRITE );
__IO_REG32_BIT(DMMDDMBL,          0xFFFFF720,__READ_WRITE ,__dmmddmbl_bits);
__IO_REG32_BIT(DMMDDMPT,          0xFFFFF724,__READ       ,__dmmddmpt_bits);
__IO_REG32_BIT(DMMINTPT,          0xFFFFF728,__READ_WRITE ,__dmmintpt_bits);
__IO_REG32_BIT(DMMDEST0REG1,      0xFFFFF72C,__READ_WRITE ,__dmmdestreg_bits);
__IO_REG32_BIT(DMMDEST0BL1,       0xFFFFF730,__READ_WRITE ,__dmmdestbl_bits);
__IO_REG32_BIT(DMMDEST0REG2,      0xFFFFF734,__READ_WRITE ,__dmmdestreg_bits);
__IO_REG32_BIT(DMMDEST0BL2,       0xFFFFF738,__READ_WRITE ,__dmmdestbl_bits);
__IO_REG32_BIT(DMMDEST1REG1,      0xFFFFF73C,__READ_WRITE ,__dmmdestreg_bits);
__IO_REG32_BIT(DMMDEST1BL1,       0xFFFFF740,__READ_WRITE ,__dmmdestbl_bits);
__IO_REG32_BIT(DMMDEST1REG2,      0xFFFFF744,__READ_WRITE ,__dmmdestreg_bits);
__IO_REG32_BIT(DMMDEST1BL2,       0xFFFFF748,__READ_WRITE ,__dmmdestbl_bits);
__IO_REG32_BIT(DMMDEST2REG1,      0xFFFFF74C,__READ_WRITE ,__dmmdestreg_bits);
__IO_REG32_BIT(DMMDEST2BL1,       0xFFFFF750,__READ_WRITE ,__dmmdestbl_bits);
__IO_REG32_BIT(DMMDEST2REG2,      0xFFFFF754,__READ_WRITE ,__dmmdestreg_bits);
__IO_REG32_BIT(DMMDEST2BL2,       0xFFFFF758,__READ_WRITE ,__dmmdestbl_bits);
__IO_REG32_BIT(DMMDEST3REG1,      0xFFFFF75C,__READ_WRITE ,__dmmdestreg_bits);
__IO_REG32_BIT(DMMDEST3BL1,       0xFFFFF760,__READ_WRITE ,__dmmdestbl_bits);
__IO_REG32_BIT(DMMDEST3REG2,      0xFFFFF764,__READ_WRITE ,__dmmdestreg_bits);
__IO_REG32_BIT(DMMDEST3BL2,       0xFFFFF768,__READ_WRITE ,__dmmdestbl_bits);
__IO_REG32_BIT(DMMPC0,            0xFFFFF76C,__READ_WRITE ,__dmmpc0_bits);
__IO_REG32_BIT(DMMPC1,            0xFFFFF770,__READ_WRITE ,__dmmpc1_bits);
__IO_REG32_BIT(DMMPC2,            0xFFFFF774,__READ_WRITE ,__dmmpc2_bits);
__IO_REG32_BIT(DMMPC3,            0xFFFFF778,__READ_WRITE ,__dmmpc3_bits);
__IO_REG32_BIT(DMMPC4,            0xFFFFF77C,__READ_WRITE ,__dmmpc4_bits);
__IO_REG32_BIT(DMMPC5,            0xFFFFF780,__READ_WRITE ,__dmmpc5_bits);
__IO_REG32_BIT(DMMPC6,            0xFFFFF784,__READ_WRITE ,__dmmpc6_bits);
__IO_REG32_BIT(DMMPC7,            0xFFFFF788,__READ_WRITE ,__dmmpc7_bits);
__IO_REG32_BIT(DMMPC8,            0xFFFFF78C,__READ_WRITE ,__dmmpc8_bits);

/***************************************************************************
 **
 ** RTP (RAM Trace Port Module)
 **
 ***************************************************************************/
__IO_REG32_BIT(RTPGLBCTRL,        0xFFFFFA00,__READ_WRITE ,__rtpglbctrl_bits);
__IO_REG32_BIT(RTPTRENA,          0xFFFFFA04,__READ       ,__rtptrena_bits);
__IO_REG32_BIT(RTPGSR,            0xFFFFFA08,__READ_WRITE ,__rtpgsr_bits);
__IO_REG32_BIT(RTPRAM1REG1,       0xFFFFFA0C,__READ_WRITE ,__rtpramreg_bits);
__IO_REG32_BIT(RTPRAM1REG2,       0xFFFFFA10,__READ_WRITE ,__rtpramreg_bits);
__IO_REG32_BIT(RTPRAM2REG1,       0xFFFFFA14,__READ_WRITE ,__rtpramreg_bits);
__IO_REG32_BIT(RTPRAM2REG2,       0xFFFFFA18,__READ_WRITE ,__rtpramreg_bits);
__IO_REG32_BIT(RTPPERREG1,        0xFFFFFA24,__READ_WRITE ,__rtpperreg_bits);
__IO_REG32_BIT(RTPPERREG2,        0xFFFFFA28,__READ_WRITE ,__rtpperreg_bits);
__IO_REG32(    RTPDDMW,           0xFFFFFA2C,__READ_WRITE );
__IO_REG32_BIT(RTPPC0,            0xFFFFFA34,__READ_WRITE ,__rtppc0_bits);
__IO_REG32_BIT(RTPPC1,            0xFFFFFA38,__READ_WRITE ,__rtppc1_bits);
__IO_REG32_BIT(RTPPC2,            0xFFFFFA3C,__READ       ,__rtppc2_bits);
__IO_REG32_BIT(RTPPC3,            0xFFFFFA40,__READ_WRITE ,__rtppc3_bits);
__IO_REG32_BIT(RTPPC4,            0xFFFFFA44,__READ_WRITE ,__rtppc4_bits);
__IO_REG32_BIT(RTPPC5,            0xFFFFFA48,__READ_WRITE ,__rtppc5_bits);
__IO_REG32_BIT(RTPPC6,            0xFFFFFA4C,__READ_WRITE ,__rtppc6_bits);
__IO_REG32_BIT(RTPPC7,            0xFFFFFA50,__READ_WRITE ,__rtppc7_bits);
__IO_REG32_BIT(RTPPC8,            0xFFFFFA54,__READ_WRITE ,__rtppc8_bits);
__IO_REG32(    RTP_RAM_BASE,      0xFFF83000,__READ_WRITE );

/***************************************************************************
 **
 ** I2C
 **
 ***************************************************************************/
__IO_REG16_BIT(I2COAR,            0xFFF7D402,__READ_WRITE ,__i2coar_bits);
__IO_REG16_BIT(I2CIMR,            0xFFF7D406,__READ_WRITE ,__i2cimr_bits);
__IO_REG16_BIT(I2CSTR,            0xFFF7D40A,__READ_WRITE ,__i2cstr_bits);
__IO_REG16(    I2CCKL,            0xFFF7D40E,__READ_WRITE );
__IO_REG16(    I2CCKH,            0xFFF7D412,__READ_WRITE );
__IO_REG16(    I2CCNT,            0xFFF7D416,__READ_WRITE );
__IO_REG16_BIT(I2CDRR,            0xFFF7D41A,__READ_WRITE ,__i2cdrr_bits);
__IO_REG16_BIT(I2CSAR,            0xFFF7D41E,__READ_WRITE ,__i2csar_bits);
__IO_REG16_BIT(I2CDXR,            0xFFF7D422,__READ_WRITE ,__i2cdxr_bits);
__IO_REG16_BIT(I2CMDR,            0xFFF7D426,__READ_WRITE ,__i2cmdr_bits);
__IO_REG16_BIT(I2CIVR,            0xFFF7D42A,__READ_WRITE ,__i2civr_bits);
__IO_REG16_BIT(I2CEMDR,           0xFFF7D42E,__READ_WRITE ,__i2cemdr_bits);
__IO_REG16_BIT(I2CPSC,            0xFFF7D432,__READ_WRITE ,__i2cpsc_bits);
__IO_REG16_BIT(I2CPID1,           0xFFF7D436,__READ       ,__i2cpid1_bits);
__IO_REG16_BIT(I2CPID2,           0xFFF7D43A,__READ_WRITE ,__i2cpid2_bits);
__IO_REG16_BIT(I2CDMACR,          0xFFF7D43E,__READ_WRITE ,__i2cdmacr_bits);
__IO_REG16_BIT(I2CPFNC,           0xFFF7D44A,__READ_WRITE ,__i2cpfnc_bits);
__IO_REG16_BIT(I2CPDIR,           0xFFF7D44E,__READ_WRITE ,__i2cpdir_bits);
__IO_REG16_BIT(I2CDIN,            0xFFF7D452,__READ       ,__i2cdin_bits);
__IO_REG16_BIT(I2CDOUT,           0xFFF7D456,__READ_WRITE ,__i2cdout_bits);
__IO_REG16_BIT(I2CDSET,           0xFFF7D45A,__READ_WRITE ,__i2cdset_bits);
__IO_REG16_BIT(I2CDCLR,           0xFFF7D45E,__READ_WRITE ,__i2cdclr_bits);
__IO_REG16_BIT(I2CPDR,            0xFFF7D462,__READ_WRITE ,__i2cpdr_bits);
__IO_REG16_BIT(I2CPDIS,           0xFFF7D466,__READ_WRITE ,__i2cpdis_bits);
__IO_REG16_BIT(I2CPSEL,           0xFFF7D46A,__READ_WRITE ,__i2cpsel_bits);
__IO_REG16_BIT(I2CSRS,            0xFFF7D46E,__READ_WRITE ,__i2csrs_bits);

/***************************************************************************
 **
 ** PMM (Power Management Module)
 **
 ***************************************************************************/
__IO_REG32_BIT(LOGICPDPWRCTRL0,   0xFFFF0000,__READ_WRITE ,__logicpdpwrctrl0_bits);
__IO_REG32_BIT(MEMPDPWRCTRL0,     0xFFFF0010,__READ_WRITE ,__mempdpwrctrl0_bits);
__IO_REG32_BIT(PDCLKDIS,          0xFFFF0020,__READ_WRITE ,__pdclkdis_bits);
__IO_REG32_BIT(PDCLKDISSET,       0xFFFF0024,__READ_WRITE ,__pdclkdisset_bits);
__IO_REG32_BIT(PDCLKDISCLR,       0xFFFF0028,__READ_WRITE ,__pdclkdisclr_bits);
__IO_REG32_BIT(LOGICPDPWRSTAT0,   0xFFFF0040,__READ_WRITE ,__logicpdpwrstat0_bits);
__IO_REG32_BIT(LOGICPDPWRSTAT1,   0xFFFF0044,__READ_WRITE ,__logicpdpwrstat1_bits);
__IO_REG32_BIT(LOGICPDPWRSTAT2,   0xFFFF0048,__READ_WRITE ,__logicpdpwrstat2_bits);
__IO_REG32_BIT(LOGICPDPWRSTAT3,   0xFFFF004C,__READ_WRITE ,__logicpdpwrstat3_bits);
__IO_REG32_BIT(MEMPDPWRSTAT0,     0xFFFF0080,__READ_WRITE ,__mempdpwrstat0_bits);
__IO_REG32_BIT(MEMPDPWRSTAT1,     0xFFFF0084,__READ_WRITE ,__mempdpwrstat1_bits);
__IO_REG32_BIT(MEMPDPWRSTAT2,     0xFFFF0088,__READ_WRITE ,__mempdpwrstat2_bits);
__IO_REG32_BIT(GLOBALCTRL1,       0xFFFF00A0,__READ_WRITE ,__globalctrl1_bits);
__IO_REG32_BIT(GLOBALSTAT,        0xFFFF00A8,__READ       ,__globalstat_bits);
__IO_REG32_BIT(PRCKEYREG,         0xFFFF00AC,__READ_WRITE ,__prckeyreg_bits);
__IO_REG32_BIT(LPDDCSTAT1,        0xFFFF00B0,__READ       ,__lpddcstat1_bits);
__IO_REG32_BIT(LPDDCSTAT2,        0xFFFF00B4,__READ       ,__lpddcstat2_bits);
__IO_REG32_BIT(MPDDCSTAT1,        0xFFFF00B8,__READ       ,__mpddcstat1_bits);
__IO_REG32_BIT(MPDDCSTAT2,        0xFFFF00BC,__READ       ,__mpddcstat2_bits);
__IO_REG32_BIT(ISODIAGSTAT,       0xFFFF00C0,__READ       ,__isodiagstat_bits);

/***************************************************************************
 **
 ** IOMM (I/O Multiplexing and Control Module)
 **
 ***************************************************************************/
__IO_REG32_BIT(IOMM_REVISION_REG,           0xFFFFEA00,__READ       ,__iomm_revision_reg_bits);
__IO_REG32_BIT(IOMM_ENDIAN_REG,             0xFFFFEA20,__READ       ,__iomm_endian_reg_bits);
__IO_REG32(    IOMM_KICK_REG0,              0xFFFFEA38,__READ_WRITE );
__IO_REG32(    IOMM_KICK_REG1,              0xFFFFEA3C,__READ_WRITE );
__IO_REG32_BIT(IOMM_ERR_RAW_STATUS_REG,     0xFFFFEAE0,__READ_WRITE ,__iomm_err_raw_status_reg_bits);
__IO_REG32_BIT(IOMM_ERR_ENABLED_STATUS_REG, 0xFFFFEAE4,__READ_WRITE ,__iomm_err_enabled_status_reg_bits);
__IO_REG32_BIT(IOMM_ERR_ENABLE_REG,         0xFFFFEAE8,__READ_WRITE ,__iomm_err_enable_reg_bits);
__IO_REG32_BIT(IOMM_ERR_ENABLE_CLR_REG,     0xFFFFEAEC,__READ_WRITE ,__iomm_err_enable_clr_reg_bits);
__IO_REG32(    IOMM_FAULT_ADDRESS_REG,      0xFFFFEAF4,__READ_WRITE );
__IO_REG32_BIT(IOMM_FAULT_STATUS_REG,       0xFFFFEAF8,__READ       ,__iomm_fault_status_reg_bits);
__IO_REG32_BIT(IOMM_FAULT_CLEAR_REG,        0xFFFFEAFC,__READ_WRITE ,__iomm_fault_clear_reg_bits);
__IO_REG32_BIT(IOMM_PINMMR00,               0xFFFFEB10,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR01,               0xFFFFEB14,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR02,               0xFFFFEB18,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR03,               0xFFFFEB1C,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR04,               0xFFFFEB20,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR05,               0xFFFFEB24,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR06,               0xFFFFEB28,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR07,               0xFFFFEB2C,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR08,               0xFFFFEB30,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR09,               0xFFFFEB34,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR10,               0xFFFFEB38,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR11,               0xFFFFEB3C,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR12,               0xFFFFEB40,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR13,               0xFFFFEB44,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR14,               0xFFFFEB48,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR15,               0xFFFFEB4C,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR16,               0xFFFFEB50,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR17,               0xFFFFEB54,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR18,               0xFFFFEB58,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR19,               0xFFFFEB5C,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR20,               0xFFFFEB60,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR21,               0xFFFFEB64,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR22,               0xFFFFEB68,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR23,               0xFFFFEB6C,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR24,               0xFFFFEB70,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR25,               0xFFFFEB74,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR26,               0xFFFFEB78,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR27,               0xFFFFEB7C,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR28,               0xFFFFEB80,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR29,               0xFFFFEB84,__READ_WRITE ,__iomm_pinmmr_bits);
__IO_REG32_BIT(IOMM_PINMMR30,               0xFFFFEB88,__READ_WRITE ,__iomm_pinmmr_bits);

/***************************************************************************
 **
 ** EMAC
 **
 ***************************************************************************/
__IO_REG32(    EMAC_REVID,            0xFCF78800,__READ       );
__IO_REG32_BIT(EMAC_SOFTRESET,        0xFCF78804,__READ_WRITE ,__emac_softreset_bits);
__IO_REG32_BIT(EMAC_INTCONTROL,       0xFCF7880C,__READ_WRITE ,__emac_intcontrol_bits);
__IO_REG32_BIT(EMAC_C0RXTHRESHEN,     0xFCF78810,__READ_WRITE ,__emac_crxthreshen_bits);
__IO_REG32_BIT(EMAC_C0RXEN,           0xFCF78814,__READ_WRITE ,__emac_crxen_bits);
__IO_REG32_BIT(EMAC_C0TXEN,           0xFCF78818,__READ_WRITE ,__emac_ctxen_bits);
__IO_REG32_BIT(EMAC_C0MISCEN,         0xFCF7881C,__READ_WRITE ,__emac_cmiscen_bits);
__IO_REG32_BIT(EMAC_C0RXTHRESHSTAT,   0xFCF78840,__READ       ,__emac_crxthreshstat_bits);
__IO_REG32_BIT(EMAC_C0RXSTAT,         0xFCF78844,__READ       ,__emac_crxstat_bits);
__IO_REG32_BIT(EMAC_C0TXSTAT,         0xFCF78848,__READ       ,__emac_ctxstat_bits);
__IO_REG32_BIT(EMAC_C0MISCSTAT,       0xFCF7884C,__READ       ,__emac_cmiscstat_bits);
__IO_REG32_BIT(EMAC_C0RXIMAX,         0xFCF78870,__READ_WRITE ,__emac_crximax_bits);
__IO_REG32_BIT(EMAC_C0TXIMAX,         0xFCF78874,__READ_WRITE ,__emac_ctximax_bits);
__IO_REG32(    EMAC_TXREVID,          0xFCF78000,__READ       );
__IO_REG32_BIT(EMAC_TXCONTROL,        0xFCF78004,__READ_WRITE ,__emac_txcontrol_bits);
__IO_REG32_BIT(EMAC_TXTEARDOWN,       0xFCF78008,__READ_WRITE ,__emac_txteardown_bits);
__IO_REG32(    EMAC_RXREVID,          0xFCF78010,__READ       );
__IO_REG32_BIT(EMAC_RXCONTROL,        0xFCF78014,__READ_WRITE ,__emac_rxcontrol_bits);
__IO_REG32_BIT(EMAC_RXTEARDOWN,       0xFCF78018,__READ_WRITE ,__emac_rxteardown_bits);
__IO_REG32_BIT(EMAC_TXINTSTATRAW,     0xFCF78080,__READ       ,__emac_txintstatraw_bits);
__IO_REG32_BIT(EMAC_TXINTSTATMASKED,  0xFCF78084,__READ       ,__emac_txintstatraw_bits);
__IO_REG32_BIT(EMAC_TXINTMASKSET,     0xFCF78088,__READ_WRITE ,__emac_txintmaskset_bits);
__IO_REG32_BIT(EMAC_TXINTMASKCLEAR,   0xFCF7808C,__READ_WRITE ,__emac_txintmaskset_bits);
__IO_REG32_BIT(EMAC_MACINVECTOR,      0xFCF78090,__READ       ,__emac_macinvector_bits);
__IO_REG32_BIT(EMAC_MACEOIVECTOR,     0xFCF78094,__READ_WRITE ,__emac_maceoivector_bits);
__IO_REG32_BIT(EMAC_RXINTSTATRAW,     0xFCF780A0,__READ       ,__emac_rxintstatraw_bits);
__IO_REG32_BIT(EMAC_RXINTSTATMASKED,  0xFCF780A4,__READ       ,__emac_rxintstatraw_bits);
__IO_REG32_BIT(EMAC_RXINTMASKSET,     0xFCF780A8,__READ_WRITE ,__emac_rxintmaskset_bits);
__IO_REG32_BIT(EMAC_RXINTMASKCLEAR,   0xFCF780AC,__READ_WRITE ,__emac_rxintmaskset_bits);
__IO_REG32_BIT(EMAC_MACINTSTATRAW,    0xFCF780B0,__READ       ,__emac_macintstatraw_bits);
__IO_REG32_BIT(EMAC_MACINTSTATMASKED, 0xFCF780B4,__READ       ,__emac_macintstatraw_bits);
__IO_REG32_BIT(EMAC_MACINTMASKSET,    0xFCF780B8,__READ_WRITE ,__emac_macintmaskset_bits);
__IO_REG32_BIT(EMAC_MACINTMASKCLEAR,  0xFCF780BC,__READ_WRITE ,__emac_macintmaskset_bits);
__IO_REG32_BIT(EMAC_RXMBPENABLE,      0xFCF78100,__READ_WRITE ,__emac_rxmbpenable_bits);
__IO_REG32_BIT(EMAC_RXUNICASTSET,     0xFCF78104,__READ_WRITE ,__emac_rxunicastset_bits);
__IO_REG32_BIT(EMAC_RXUNICASTCLEAR,   0xFCF78108,__READ_WRITE ,__emac_rxunicastset_bits);
__IO_REG32_BIT(EMAC_RXMAXLEN,         0xFCF7810C,__READ_WRITE ,__emac_rxmaxlen_bits);
__IO_REG32_BIT(EMAC_RXBUFFEROFFSET,   0xFCF78110,__READ_WRITE ,__emac_rxbufferoffset_bits);
__IO_REG32_BIT(EMAC_RXFILTERLOWTHRESH,0xFCF78114,__READ_WRITE ,__emac_rxfilterlowthresh_bits);
__IO_REG32_BIT(EMAC_RX0FLOWTHRESH,    0xFCF78120,__READ_WRITE ,__emac_rxflowthresh_bits);
__IO_REG32_BIT(EMAC_RX1FLOWTHRESH,    0xFCF78124,__READ_WRITE ,__emac_rxflowthresh_bits);
__IO_REG32_BIT(EMAC_RX2FLOWTHRESH,    0xFCF78128,__READ_WRITE ,__emac_rxflowthresh_bits);
__IO_REG32_BIT(EMAC_RX3FLOWTHRESH,    0xFCF7812C,__READ_WRITE ,__emac_rxflowthresh_bits);
__IO_REG32_BIT(EMAC_RX4FLOWTHRESH,    0xFCF78130,__READ_WRITE ,__emac_rxflowthresh_bits);
__IO_REG32_BIT(EMAC_RX5FLOWTHRESH,    0xFCF78134,__READ_WRITE ,__emac_rxflowthresh_bits);
__IO_REG32_BIT(EMAC_RX6FLOWTHRESH,    0xFCF78138,__READ_WRITE ,__emac_rxflowthresh_bits);
__IO_REG32_BIT(EMAC_RX7FLOWTHRESH,    0xFCF7813C,__READ_WRITE ,__emac_rxflowthresh_bits);
__IO_REG32_BIT(EMAC_RX0FREEBUFFER,    0xFCF78140,__READ_WRITE ,__emac_rxfreebuffer_bits);
__IO_REG32_BIT(EMAC_RX1FREEBUFFER,    0xFCF78144,__READ_WRITE ,__emac_rxfreebuffer_bits);
__IO_REG32_BIT(EMAC_RX2FREEBUFFER,    0xFCF78148,__READ_WRITE ,__emac_rxfreebuffer_bits);
__IO_REG32_BIT(EMAC_RX3FREEBUFFER,    0xFCF7814C,__READ_WRITE ,__emac_rxfreebuffer_bits);
__IO_REG32_BIT(EMAC_RX4FREEBUFFER,    0xFCF78150,__READ_WRITE ,__emac_rxfreebuffer_bits);
__IO_REG32_BIT(EMAC_RX5FREEBUFFER,    0xFCF78154,__READ_WRITE ,__emac_rxfreebuffer_bits);
__IO_REG32_BIT(EMAC_RX6FREEBUFFER,    0xFCF78158,__READ_WRITE ,__emac_rxfreebuffer_bits);
__IO_REG32_BIT(EMAC_RX7FREEBUFFER,    0xFCF7815C,__READ_WRITE ,__emac_rxfreebuffer_bits);
__IO_REG32_BIT(EMAC_MACCONTROL,       0xFCF78160,__READ_WRITE ,__emac_maccontrol_bits);
__IO_REG32_BIT(EMAC_MACSTATUS,        0xFCF78164,__READ       ,__emac_macstatus_bits);
__IO_REG32_BIT(EMAC_EMCONTROL,        0xFCF78168,__READ_WRITE ,__emac_emcontrol_bits);
__IO_REG32_BIT(EMAC_FIFOCONTROL,      0xFCF7816C,__READ_WRITE ,__emac_fifocontrol_bits);
__IO_REG32_BIT(EMAC_MACCONFIG,        0xFCF78170,__READ       ,__emac_macconfig_bits);
__IO_REG32_BIT(EMAC_MSOFTRESET,       0xFCF78174,__READ_WRITE ,__emac_softreset_bits);
__IO_REG32_BIT(EMAC_MACSRCADDRLO,     0xFCF781D0,__READ_WRITE ,__emac_macsrcaddrlo_bits);
__IO_REG32_BIT(EMAC_MACSRCADDRHI,     0xFCF781D4,__READ_WRITE ,__emac_macsrcaddrhi_bits);
__IO_REG32(    EMAC_MACHASH1,         0xFCF781D8,__READ_WRITE );
__IO_REG32(    EMAC_MACHASH2,         0xFCF781DC,__READ_WRITE );
__IO_REG32_BIT(EMAC_BOFFTEST,         0xFCF781E0,__READ       ,__emac_bofftest_bits);
__IO_REG32_BIT(EMAC_TPACETEST,        0xFCF781E4,__READ       ,__emac_tpacetest_bits);
__IO_REG32_BIT(EMAC_RXPAUSE,          0xFCF781E8,__READ       ,__emac_rxpause_bits);
__IO_REG32_BIT(EMAC_TXPAUSE,          0xFCF781EC,__READ       ,__emac_rxpause_bits);
__IO_REG32_BIT(EMAC_MACADDRLO,        0xFCF78500,__READ_WRITE ,__emac_macaddrlo_bits);
__IO_REG32_BIT(EMAC_MACADDRHI,        0xFCF78504,__READ_WRITE ,__emac_macaddrhi_bits);
__IO_REG32_BIT(EMAC_MACINDEX,         0xFCF78508,__READ_WRITE ,__emac_macindex_bits);
__IO_REG32(    EMAC_TX0HDP,           0xFCF78600,__READ_WRITE );
__IO_REG32(    EMAC_TX1HDP,           0xFCF78604,__READ_WRITE );
__IO_REG32(    EMAC_TX2HDP,           0xFCF78608,__READ_WRITE );
__IO_REG32(    EMAC_TX3HDP,           0xFCF7860C,__READ_WRITE );
__IO_REG32(    EMAC_TX4HDP,           0xFCF78610,__READ_WRITE );
__IO_REG32(    EMAC_TX5HDP,           0xFCF78614,__READ_WRITE );
__IO_REG32(    EMAC_TX6HDP,           0xFCF78618,__READ_WRITE );
__IO_REG32(    EMAC_TX7HDP,           0xFCF7861C,__READ_WRITE );
__IO_REG32(    EMAC_RX0HDP,           0xFCF78620,__READ_WRITE );
__IO_REG32(    EMAC_RX1HDP,           0xFCF78624,__READ_WRITE );
__IO_REG32(    EMAC_RX2HDP,           0xFCF78628,__READ_WRITE );
__IO_REG32(    EMAC_RX3HDP,           0xFCF7862C,__READ_WRITE );
__IO_REG32(    EMAC_RX4HDP,           0xFCF78630,__READ_WRITE );
__IO_REG32(    EMAC_RX5HDP,           0xFCF78634,__READ_WRITE );
__IO_REG32(    EMAC_RX6HDP,           0xFCF78638,__READ_WRITE );
__IO_REG32(    EMAC_RX7HDP,           0xFCF7863C,__READ_WRITE );
__IO_REG32(    EMAC_TX0CP,            0xFCF78640,__READ_WRITE );
__IO_REG32(    EMAC_TX1CP,            0xFCF78644,__READ_WRITE );
__IO_REG32(    EMAC_TX2CP,            0xFCF78648,__READ_WRITE );
__IO_REG32(    EMAC_TX3CP,            0xFCF7864C,__READ_WRITE );
__IO_REG32(    EMAC_TX4CP,            0xFCF78650,__READ_WRITE );
__IO_REG32(    EMAC_TX5CP,            0xFCF78654,__READ_WRITE );
__IO_REG32(    EMAC_TX6CP,            0xFCF78658,__READ_WRITE );
__IO_REG32(    EMAC_TX7CP,            0xFCF7865C,__READ_WRITE );
__IO_REG32(    EMAC_RX0CP,            0xFCF78660,__READ_WRITE );
__IO_REG32(    EMAC_RX1CP,            0xFCF78664,__READ_WRITE );
__IO_REG32(    EMAC_RX2CP,            0xFCF78668,__READ_WRITE );
__IO_REG32(    EMAC_RX3CP,            0xFCF7866C,__READ_WRITE );
__IO_REG32(    EMAC_RX4CP,            0xFCF78670,__READ_WRITE );
__IO_REG32(    EMAC_RX5CP,            0xFCF78674,__READ_WRITE );
__IO_REG32(    EMAC_RX6CP,            0xFCF78678,__READ_WRITE );
__IO_REG32(    EMAC_RX7CP,            0xFCF7867C,__READ_WRITE );
__IO_REG32(    EMAC_RXGOODFRAMES,     0xFCF78200,__READ_WRITE );
__IO_REG32(    EMAC_RXBCASTFRAMES,    0xFCF78204,__READ_WRITE );
__IO_REG32(    EMAC_RXMCASTFRAMES,    0xFCF78208,__READ_WRITE );
__IO_REG32(    EMAC_RXPAUSEFRAMES,    0xFCF7820C,__READ_WRITE );
__IO_REG32(    EMAC_RXCRCERRORS,      0xFCF78210,__READ_WRITE );
__IO_REG32(    EMAC_RXALIGNCODEERRORS,0xFCF78214,__READ_WRITE );
__IO_REG32(    EMAC_RXOVERSIZED,      0xFCF78218,__READ_WRITE );
__IO_REG32(    EMAC_RXJABBER,         0xFCF7821C,__READ_WRITE );
__IO_REG32(    EMAC_RXUNDERSIZED,     0xFCF78220,__READ_WRITE );
__IO_REG32(    EMAC_RXFRAGMENTS,      0xFCF78224,__READ_WRITE );
__IO_REG32(    EMAC_RXFILTERED,       0xFCF78228,__READ_WRITE );
__IO_REG32(    EMAC_RXQOSFILTERED,    0xFCF7822C,__READ_WRITE );
__IO_REG32(    EMAC_RXOCTETS,         0xFCF78230,__READ_WRITE );
__IO_REG32(    EMAC_TXGOODFRAMES,     0xFCF78234,__READ_WRITE );
__IO_REG32(    EMAC_TXBCASTFRAMES,    0xFCF78238,__READ_WRITE );
__IO_REG32(    EMAC_TXMCASTFRAMES,    0xFCF7823C,__READ_WRITE );
__IO_REG32(    EMAC_TXPAUSEFRAMES,    0xFCF78240,__READ_WRITE );
__IO_REG32(    EMAC_TXDEFERRED,       0xFCF78244,__READ_WRITE );
__IO_REG32(    EMAC_TXCOLLISION,      0xFCF78248,__READ_WRITE );
__IO_REG32(    EMAC_TXSINGLECOLL,     0xFCF7824C,__READ_WRITE );
__IO_REG32(    EMAC_TXMULTICOLL,      0xFCF78250,__READ_WRITE );
__IO_REG32(    EMAC_TXEXCESSIVECOLL,  0xFCF78254,__READ_WRITE );
__IO_REG32(    EMAC_TXLATECOLL,       0xFCF78258,__READ_WRITE );
__IO_REG32(    EMAC_TXUNDERRUN,       0xFCF7825C,__READ_WRITE );
__IO_REG32(    EMAC_TXCARRIERSENSE,   0xFCF78260,__READ_WRITE );
__IO_REG32(    EMAC_TXOCTETS,         0xFCF78264,__READ_WRITE );
__IO_REG32(    EMAC_FRAME64,          0xFCF78268,__READ_WRITE );
__IO_REG32(    EMAC_FRAME65T127,      0xFCF7826C,__READ_WRITE );
__IO_REG32(    EMAC_FRAME128T255,     0xFCF78270,__READ_WRITE );
__IO_REG32(    EMAC_FRAME256T511,     0xFCF78274,__READ_WRITE );
__IO_REG32(    EMAC_FRAME512T1023,    0xFCF78278,__READ_WRITE );
__IO_REG32(    EMAC_FRAME1024TUP,     0xFCF7827C,__READ_WRITE );
__IO_REG32(    EMAC_NETOCTETS,        0xFCF78280,__READ_WRITE );
__IO_REG32(    EMAC_RXSOFOVERRUNS,    0xFCF78284,__READ_WRITE );
__IO_REG32(    EMAC_RXMOFOVERRUNS,    0xFCF78288,__READ_WRITE );
__IO_REG32(    EMAC_RXDMAOVERRUNS,    0xFCF7828C,__READ_WRITE );

/***************************************************************************
 **
 ** MDIO
 **
 ***************************************************************************/
__IO_REG32(    MDIO_REVID,            0xFCF78900,__READ       );
__IO_REG32_BIT(MDIO_CONTROL,          0xFCF78904,__READ_WRITE ,__mdio_control_bits);
__IO_REG32_BIT(MDIO_ALIVE,            0xFCF78908,__READ_WRITE ,__mdio_alive_bits);
__IO_REG32_BIT(MDIO_LINK,             0xFCF7890C,__READ_WRITE ,__mdio_link_bits);
__IO_REG32_BIT(MDIO_LINKINTRAW,       0xFCF78910,__READ_WRITE ,__mdio_linkintraw_bits);
__IO_REG32_BIT(MDIO_LINKINTMASKED,    0xFCF78914,__READ_WRITE ,__mdio_linkintraw_bits);
__IO_REG32_BIT(MDIO_USERINTRAW,       0xFCF78920,__READ_WRITE ,__mdio_userintraw_bits);
__IO_REG32_BIT(MDIO_USERINTMASKED,    0xFCF78924,__READ_WRITE ,__mdio_userintraw_bits);
__IO_REG32_BIT(MDIO_USERINTMASKSET,   0xFCF78928,__READ_WRITE ,__mdio_userintraw_bits);
__IO_REG32_BIT(MDIO_USERINTMASKCLEAR, 0xFCF7892C,__READ_WRITE ,__mdio_userintraw_bits);
__IO_REG32_BIT(MDIO_USERACCESS0,      0xFCF78980,__READ_WRITE ,__mdio_useraccess_bits);
__IO_REG32_BIT(MDIO_USERPHYSEL0,      0xFCF78984,__READ_WRITE ,__mdio_userphysel_bits);
__IO_REG32_BIT(MDIO_USERACCESS1,      0xFCF78988,__READ_WRITE ,__mdio_useraccess_bits);
__IO_REG32_BIT(MDIO_USERPHYSEL1,      0xFCF7898C,__READ_WRITE ,__mdio_userphysel_bits);

/***************************************************************************
 **
 ** DCC1 (Dual-Clock Comparator)
 **
 ***************************************************************************/
__IO_REG32_BIT(DCC1GCTRL,             0xFFFFEC00,__READ_WRITE ,__dccgctrl_bits);
__IO_REG32_BIT(DCC1REV,               0xFFFFEC04,__READ       ,__dccrev_bits);
__IO_REG32_BIT(DCC1CNT0SEED,          0xFFFFEC08,__READ_WRITE ,__dcccnt0seed_bits);
__IO_REG32_BIT(DCC1VALID0SEED,        0xFFFFEC0C,__READ_WRITE ,__dccvalid0seed_bits);
__IO_REG32_BIT(DCC1CNT1SEED,          0xFFFFEC10,__READ_WRITE ,__dcccnt1seed_bits);
__IO_REG32_BIT(DCC1STAT,              0xFFFFEC14,__READ       ,__dccstat_bits);
__IO_REG32_BIT(DCC1CNT0,              0xFFFFEC18,__READ       ,__dcccnt0_bits);
__IO_REG32_BIT(DCC1VALID0,            0xFFFFEC1C,__READ       ,__dccvalid0_bits);
__IO_REG32_BIT(DCC1CNT1,              0xFFFFEC20,__READ       ,__dcccnt1_bits);
__IO_REG32_BIT(DCC1CNT1CLKSRC,        0xFFFFEC24,__READ       ,__dcccnt1clksrc_bits);
__IO_REG32_BIT(DCC1CNT0CLKSRC,        0xFFFFEC28,__READ_WRITE ,__dcccnt0clksrc_bits);

/***************************************************************************
 **
 ** DCC2 (Dual-Clock Comparator)
 **
 ***************************************************************************/
__IO_REG32_BIT(DCC2GCTRL,             0xFFFFF400,__READ_WRITE ,__dccgctrl_bits);
__IO_REG32_BIT(DCC2REV,               0xFFFFF404,__READ       ,__dccrev_bits);
__IO_REG32_BIT(DCC2CNT0SEED,          0xFFFFF408,__READ_WRITE ,__dcccnt0seed_bits);
__IO_REG32_BIT(DCC2VALID0SEED,        0xFFFFF40C,__READ_WRITE ,__dccvalid0seed_bits);
__IO_REG32_BIT(DCC2CNT1SEED,          0xFFFFF410,__READ_WRITE ,__dcccnt1seed_bits);
__IO_REG32_BIT(DCC2STAT,              0xFFFFF414,__READ       ,__dccstat_bits);
__IO_REG32_BIT(DCC2CNT0,              0xFFFFF418,__READ       ,__dcccnt0_bits);
__IO_REG32_BIT(DCC2VALID0,            0xFFFFF41C,__READ       ,__dccvalid0_bits);
__IO_REG32_BIT(DCC2CNT1,              0xFFFFF420,__READ       ,__dcccnt1_bits);
__IO_REG32_BIT(DCC2CNT1CLKSRC,        0xFFFFF424,__READ       ,__dcccnt1clksrc_bits);
__IO_REG32_BIT(DCC2CNT0CLKSRC,        0xFFFFF428,__READ_WRITE ,__dcccnt0clksrc_bits);

/***************************************************************************
 **
 ** eFuse
 **
 ***************************************************************************/
__IO_REG32_BIT(EFCBOUND,          0xFFF8C01C,__READ_WRITE ,__efcbound_bits);
__IO_REG32_BIT(EFCPINS,           0xFFF8C02C,__READ       ,__efcpins_bits);
__IO_REG32_BIT(EFCERRSTAT,        0xFFF8C03C,__READ_WRITE ,__efcerrstat_bits);
__IO_REG32(    EFCSTCY,           0xFFF8C048,__READ_WRITE );
__IO_REG32(    EFCSTSIG,          0xFFF8C04C,__READ_WRITE );

/* Assembler-specific declarations **********************************************/

#ifdef __IAR_SYSTEMS_ASM__


#endif    /* __IAR_SYSTEMS_ASM__ */

/***************************************************************************
 **
 **    TMS570LS3137ZWT INTERRUPT VALUES
 **
***************************************************************************/
/***************************************************************************
 **
 **  Interrupt vector table
 **
 ***************************************************************************/
#define RESETV  0x00  /* Reset                           */
#define UNDEFV  0x04  /* Undefined instruction           */
#define SWIV    0x08  /* Software interrupt              */
#define PABORTV 0x0c  /* Prefetch abort                  */
#define DABORTV 0x10  /* Data abort                      */
#define IRQV    0x18  /* Normal interrupt                */
#define FIQV    0x1c  /* Fast interrupt                  */

/***************************************************************************
 **
 **  VIM interrupt channels
 **
 ***************************************************************************/
#define VIM_ESMHL             0
#define VIM_RTIC0             2
#define VIM_RTIC1             3
#define VIM_RTIC2             4
#define VIM_RTIC3             5
#define VIM_RTIOF0            6
#define VIM_RTIOF1            7
#define VIM_RTITB             8
#define VIM_GIOA              9
#define VIM_N2HET1L0          10
#define VIM_HETTU1L0          11
#define VIM_MIBSPI1L0         12
#define VIM_LINL0             13
#define VIM_MIBADC1EG         14
#define VIM_MIBADC1SG1        15
#define VIM_DCAN1L0           16
#define VIM_SPI2L0            17
#define VIM_FLEXRAYL0         18
#define VIM_CRC               19
#define VIM_ESMLL             20
#define VIM_SYSTEM            21
#define VIM_CPU               22
#define VIM_GIOB              23
#define VIM_N2HET1L1          24
#define VIM_HETTU1L1          25
#define VIM_MIBSPI1L1         26
#define VIM_LINL1             27
#define VIM_MIBADC1SG2        28
#define VIM_DCAN1L1           29
#define VIM_SPI2L1            30
#define VIM_MIBADC1           31
#define VIM_FLEXRAYL1         32
#define VIM_DMAFTCA           33
#define VIM_DMALFSA           34
#define VIM_DCAN2L0           35
#define VIM_DMML0             36
#define VIM_MIBSPI3L0         37
#define VIM_MIBSPI3L1         38
#define VIM_DMAHBCA           39
#define VIM_DMABTCA           40
#define VIM_AEMIFINT3         41
#define VIM_DCAN2L1           42
#define VIM_DMML1             43
#define VIM_DCAN1IF3          44
#define VIM_DCAN3L0           45
#define VIM_DCAN2IF3          46
#define VIM_FPU               47
#define VIM_FLEXRAYTU         48
#define VIM_SPI4L0            49
#define VIM_MIBADC2EG         50
#define VIM_MIBADC2SG1        51
#define VIM_FLEXRAYT0C        52
#define VIM_MIBSPI5L0         53
#define VIM_SPI4L1            54
#define VIM_DCAN3L1           55
#define VIM_MIBSPI5L1         56
#define VIM_MIBADC2SG2        57
#define VIM_FLEXRAYTUERR      58
#define VIM_MIBADC2MC         59
#define VIM_DCAN3IF           60
#define VIM_FMC               61
#define VIM_FLEXRAYT1C        62
#define VIM_N2HET2L0          63
#define VIM_SCIL0             64
#define VIM_HETTU2L0          65
#define VIM_I2C0              66
#define VIM_HETTU2L1          73
#define VIM_SCIL1             74
#define VIM_HETTU2L1          75
#define VIM_ETH_MISC_PULSE    76
#define VIM_ETH_TX_PULSE      77
#define VIM_ETH_THRESH_PULSE  78
#define VIM_ETH_RX_PULSE      79
#define VIM_HWAG1H            80
#define VIM_HWAG2H            81
#define VIM_DCC1              82
#define VIM_DCC2              83
#define VIM_PBIST             85
#define VIM_HWAG1L            88
#define VIM_HWAG2L            89

#endif    /* __IOTMS570LS3137ZWT_H */
