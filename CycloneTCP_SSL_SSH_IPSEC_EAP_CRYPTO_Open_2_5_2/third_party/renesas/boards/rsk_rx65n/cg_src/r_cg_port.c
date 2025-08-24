/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
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
* Copyright (C) 2015, 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_port.c
* Version      : Applilet4 for RX65N V1.00.00.08 [25 Aug 2016]
* Device(s)    : R5F565N9AxFB
* Tool-Chain   : IAR Systems ICCRX
* Description  : This file implements device driver for Port module.
* Creation Date: 2016-10-11
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
#include "r_cg_port.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_PORT_Create
* Description  : This function initializes the Port I/O.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PORT_Create(void)
{
    PORT0.PODR.BYTE = _04_Pm2_OUTPUT_1 | _08_Pm3_OUTPUT_1 | _20_Pm5_OUTPUT_1;
    PORT5.PODR.BYTE = _40_Pm6_OUTPUT_1;
    PORT7.PODR.BYTE = _08_Pm3_OUTPUT_1;
    PORT9.PODR.BYTE = _08_Pm3_OUTPUT_1;
    PORTJ.PODR.BYTE = _20_Pm5_OUTPUT_1;
    PORT0.DSCR.BYTE = _00_Pm2_HIDRV_OFF;
    PORT0.DSCR2.BYTE = _00_Pm2_HISPEED_OFF;
    PORT5.DSCR.BYTE = _20_Pm5_HIDRV_ON | _00_Pm6_HIDRV_OFF;
    PORT5.DSCR2.BYTE = _00_Pm5_HISPEED_OFF | _00_Pm6_HISPEED_OFF;
    PORT7.DSCR2.BYTE = _00_Pm3_HISPEED_OFF;
    PORT9.DSCR.BYTE = _00_Pm3_HIDRV_OFF;
    PORT9.DSCR2.BYTE = _00_Pm3_HISPEED_OFF;
    PORT0.PMR.BYTE = 0x00U;
    PORT0.PDR.BYTE = _04_Pm2_MODE_OUTPUT | _08_Pm3_MODE_OUTPUT | _20_Pm5_MODE_OUTPUT | _50_PDR0_DEFAULT;
    PORT5.PMR.BYTE = 0x00U;
    PORT5.PDR.BYTE = _20_Pm5_MODE_OUTPUT | _40_Pm6_MODE_OUTPUT | _80_PDR5_DEFAULT;
    PORT7.PMR.BYTE = 0x00U;
    PORT7.PDR.BYTE = _08_Pm3_MODE_OUTPUT;
    PORT9.PMR.BYTE = 0x00U;
    PORT9.PDR.BYTE = _08_Pm3_MODE_OUTPUT | _F0_PDR9_DEFAULT;
    PORTJ.PMR.BYTE = 0x00U;
    PORTJ.PDR.BYTE = _20_Pm5_MODE_OUTPUT | _D7_PDRJ_DEFAULT;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
