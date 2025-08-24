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
* File Name    : Config_SCI6_user.c
* Version      : 1.1.0
* Device(s)    : R5F565NEDxFC
* Description  : This file implements device driver for Config_SCI6.
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
#include "Config_SCI6.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t * gp_sci6_tx_address;              /* SCI6 transmit buffer address */
extern volatile uint16_t  g_sci6_tx_count;                 /* SCI6 transmit data number */
/* Start user code for global. Do not edit comment generated here */

/* Flag used locally to detect transmission complete */
static volatile uint8_t sci6_txdone;

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_SCI6_Create_UserInit
* Description  : This function adds user code after initializing the SCI6 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_SCI6_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI6_transmit_interrupt
* Description  : This function is TXI6 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#pragma vector = VECT_SCI6_TXI6
#if FAST_INTERRUPT_VECTOR == VECT_SCI6_TXI6
__fast_interrupt static void r_Config_SCI6_transmit_interrupt(void)
#else
__interrupt static void r_Config_SCI6_transmit_interrupt(void)
#endif
{
    if (0U < g_sci6_tx_count)
    {
        SCI6.TDR = *gp_sci6_tx_address;
        gp_sci6_tx_address++;
        g_sci6_tx_count--;
    }
    else
    {
        SCI6.SCR.BIT.TIE = 0U;
        SCI6.SCR.BIT.TEIE = 1U;
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI6_transmitend_interrupt
* Description  : This function is TEI6 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_Config_SCI6_transmitend_interrupt(void)
{
    SCI6.SCR.BIT.TIE = 0U;
    SCI6.SCR.BIT.TEIE = 0U;

    /* Clear TE and RE bits */
    if(0U == SCI6.SCR.BIT.RIE)
    {
        SCI6.SCR.BYTE &= 0xCFU;
    }

    r_Config_SCI6_callback_transmitend();
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI6_callback_transmitend
* Description  : This function is a callback function when SCI6 finishes transmission
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI6_callback_transmitend(void)
{
    /* Start user code for r_Config_SCI6_callback_transmitend. Do not edit comment generated here */

    sci6_txdone = TRUE;

    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SCI6_SPIMasterTransmit
* Description  : This function sends SPI6 data to slave device.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_SCI6_SPIMasterTransmit (uint8_t * const tx_buf,
                                      const uint16_t tx_num)
{
    MD_STATUS status = MD_OK;
    
    /* Clear the flag before initiating a new transmission */
    sci6_txdone = FALSE;

    /* Send the data using the API */
    status = R_Config_SCI6_SPI_Master_Send(tx_buf, tx_num);

    /* Wait for the transmit end flag */
    while (FALSE == sci6_txdone)
    {
        /* Wait */
    }

    return (status);
}

/***********************************************************************************************************************
* End of function R_SCI6_SPIMasterTransmit
***********************************************************************************************************************/

/* End user code. Do not edit comment generated here */

