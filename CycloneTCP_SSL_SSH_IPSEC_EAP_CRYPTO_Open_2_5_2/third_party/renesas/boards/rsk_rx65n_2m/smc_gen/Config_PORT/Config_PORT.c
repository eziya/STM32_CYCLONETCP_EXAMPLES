/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_PORT.c
* Version      : 1.3.0
* Device(s)    : R5F565NEDxFC
* Description  : This file implements device driver for Config_PORT.
* Creation Date: 2018-02-22
***********************************************************************************************************************/

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create
* Description  : This function initializes the PORT
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_PORT_Create(void)
{
    /* Set PORT7 registers */
    PORT7.PODR.BYTE = _08_Pm3_OUTPUT_1;
    PORT7.ODR0.BYTE = _00_Pm3_CMOS_OUTPUT;
    PORT7.DSCR2.BYTE = _00_Pm3_HISPEED_OFF;
    PORT7.PMR.BYTE = _00_Pm3_PIN_GPIO;
    PORT7.PDR.BYTE = _08_Pm3_MODE_OUTPUT;

    /* Set PORTF registers */
    PORTF.PODR.BYTE = _20_Pm5_OUTPUT_1;
    PORTF.ODR1.BYTE = _00_Pm5_CMOS_OUTPUT;
    PORTF.PMR.BYTE = _00_Pm5_PIN_GPIO;
    PORTF.PDR.BYTE = _20_Pm5_MODE_OUTPUT | _C0_PDRF_DEFAULT;

    /* Set PORTG registers */
    PORTG.PODR.BYTE = _00_Pm3_OUTPUT_0 | _10_Pm4_OUTPUT_1 | _20_Pm5_OUTPUT_1 | _40_Pm6_OUTPUT_1 | _80_Pm7_OUTPUT_1;
    PORTG.ODR0.BYTE = _00_Pm3_CMOS_OUTPUT;
    PORTG.ODR1.BYTE = _00_Pm4_CMOS_OUTPUT | _00_Pm5_CMOS_OUTPUT | _00_Pm6_CMOS_OUTPUT | _00_Pm7_CMOS_OUTPUT;
    PORTG.DSCR2.BYTE = _00_Pm3_HISPEED_OFF | _00_Pm4_HISPEED_OFF | _00_Pm5_HISPEED_OFF | _00_Pm6_HISPEED_OFF | 
                       _00_Pm7_HISPEED_OFF;
    PORTG.PMR.BYTE = _00_Pm3_PIN_GPIO | _00_Pm4_PIN_GPIO | _00_Pm5_PIN_GPIO | _00_Pm6_PIN_GPIO | _00_Pm7_PIN_GPIO;
    PORTG.PDR.BYTE = _08_Pm3_MODE_OUTPUT | _10_Pm4_MODE_OUTPUT | _20_Pm5_MODE_OUTPUT | _40_Pm6_MODE_OUTPUT | 
                     _80_Pm7_MODE_OUTPUT;

    /* Set PORTJ registers */
    PORTJ.PODR.BYTE = _08_Pm3_OUTPUT_1;
    PORTJ.ODR0.BYTE = _00_Pm3_CMOS_OUTPUT;
    PORTJ.PMR.BYTE = _00_Pm3_PIN_GPIO;
    PORTJ.PDR.BYTE = _08_Pm3_MODE_OUTPUT | _D0_PDRJ_DEFAULT;

    R_Config_PORT_Create_UserInit();
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
