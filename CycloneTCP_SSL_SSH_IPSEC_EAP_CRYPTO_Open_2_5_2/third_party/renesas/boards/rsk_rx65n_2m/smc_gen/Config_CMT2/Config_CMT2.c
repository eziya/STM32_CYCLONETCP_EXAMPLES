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
* File Name    : Config_CMT2.c
* Version      : 1.3.0
* Device(s)    : R5F565NEDxFC
* Description  : This file implements device driver for Config_CMT2.
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
#include "Config_CMT2.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_CMT2_Create
* Description  : This function initializes the CMT2 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_CMT2_Create(void)
{
    /* Disable CMI2 interrupt */
    IEN(PERIB,INTB128) = 0U;
    
    /* Cancel CMT stop state in LPC */
    MSTP(CMT2) = 0U;
    
    /* Set control registers */  
    CMT2.CMCR.WORD = _0003_CMT_CMCR_CLOCK_PCLK512 | _0040_CMT_CMCR_CMIE_ENABLE | _0080_CMT_CMCR_DEFAULT;
    
    /* Set compare match register */
    CMT2.CMCOR = _5B8D_CMT2_CMCOR_VALUE;
    ICU.SLIBXR128.BYTE = 0x01U;
    
    /* Set CMI2 priority level */
    IPR(PERIB,INTB128) = _0A_CMT_PRIORITY_LEVEL10;
    
    R_Config_CMT2_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_CMT2_Start
* Description  : This function starts the CMT2 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_CMT2_Start(void)
{
    /* Enable CMI2 interrupt in ICU */
    IEN(PERIB,INTB128) = 1U;
    
    /* Start CMT2 count */
    CMT.CMSTR1.BIT.STR2 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_Config_CMT2_Stop
* Description  : This function stop the CMT2 channel counter
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_CMT2_Stop(void)
{
    /* Stop CMT2 count */
    CMT.CMSTR1.BIT.STR2 = 0U;
    
    /* Disable CMI2 interrupt in ICU */
    IEN(PERIB,INTB128) = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

