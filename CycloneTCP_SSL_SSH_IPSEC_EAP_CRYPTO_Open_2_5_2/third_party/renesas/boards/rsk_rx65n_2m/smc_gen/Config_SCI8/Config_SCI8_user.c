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
* File Name    : Config_SCI8_user.c
* Version      : 1.1.0
* Device(s)    : R5F565NEDxFC
* Description  : This file implements device driver for Config_SCI8.
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
#include "Config_SCI8.h"
/* Start user code for include. Do not edit comment generated here */

#include "Config_CMT2.h"
#include "rskrx65n2mbdef.h"

/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint8_t * gp_sci8_tx_address;                /* SCI8 transmit buffer address */
extern volatile uint16_t  g_sci8_tx_count;                   /* SCI8 transmit data number */
extern volatile uint8_t * gp_sci8_rx_address;                /* SCI8 receive buffer address */
extern volatile uint16_t  g_sci8_rx_count;                   /* SCI8 receive data number */
extern volatile uint16_t  g_sci8_rx_length;                  /* SCI8 receive data length */
/* Start user code for global. Do not edit comment generated here */

/* Global used to receive a character from the PC terminal */
uint8_t g_rx_char;

/* Flag used to control transmission to PC terminal */
volatile uint8_t g_tx_flag = FALSE;

/* Flag used locally to detect transmission complete */
static volatile uint8_t sci8_txdone;

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_SCI8_Create_UserInit
* Description  : This function adds user code after initializing the SCI8 channel
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void R_Config_SCI8_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI8_transmit_interrupt
* Description  : This function is TXI8 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#pragma vector = VECT_SCI8_TXI8
#if FAST_INTERRUPT_VECTOR == VECT_SCI8_TXI8
__fast_interrupt static void r_Config_SCI8_transmit_interrupt(void)
#else
__interrupt static void r_Config_SCI8_transmit_interrupt(void)
#endif
{
    if (0U < g_sci8_tx_count)
    {
        SCI8.TDR = *gp_sci8_tx_address;
        gp_sci8_tx_address++;
        g_sci8_tx_count--;
    }
    else
    {
        SCI8.SCR.BIT.TIE = 0U;
        SCI8.SCR.BIT.TEIE = 1U;
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI8_transmitend_interrupt
* Description  : This function is TEI8 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_Config_SCI8_transmitend_interrupt(void)
{
    PORTJ.PMR.BYTE &= 0xFBU;
    SCI8.SCR.BIT.TIE = 0U;
    SCI8.SCR.BIT.TE = 0U;
    SCI8.SCR.BIT.TEIE = 0U;
    
    r_Config_SCI8_callback_transmitend();
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI8_receive_interrupt
* Description  : This function is RXI8 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

#pragma vector = VECT_SCI8_RXI8
#if FAST_INTERRUPT_VECTOR == VECT_SCI8_RXI8
__fast_interrupt static void r_Config_SCI8_receive_interrupt(void)
#else
__interrupt static void r_Config_SCI8_receive_interrupt(void)
#endif
{
    if (g_sci8_rx_length > g_sci8_rx_count)
    {
        *gp_sci8_rx_address = SCI8.RDR;
        gp_sci8_rx_address++;
        g_sci8_rx_count++;
    }
    
    if (g_sci8_rx_length <= g_sci8_rx_count)
    {
        /* All data received */
        SCI8.SCR.BIT.RIE = 0U;
        SCI8.SCR.BIT.RE = 0U;
        r_Config_SCI8_callback_receiveend();
    }
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI8_receiveerror_interrupt
* Description  : This function is ERI8 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

void r_Config_SCI8_receiveerror_interrupt(void)
{
    uint8_t err_type;
    
    r_Config_SCI8_callback_receiveerror();
    
    /* Clear overrun, framing and parity error flags */
    err_type = SCI8.SSR.BYTE;
    err_type &= 0xC7U;
    err_type |= 0xC0U;
    SCI8.SSR.BYTE = err_type;
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI8_callback_transmitend
* Description  : This function is a callback function when SCI8 finishes transmission
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI8_callback_transmitend(void)
{
    /* Start user code for r_Config_SCI8_callback_transmitend. Do not edit comment generated here */

    sci8_txdone = TRUE;

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI8_callback_receiveend
* Description  : This function is a callback function when SCI8 finishes reception
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI8_callback_receiveend(void)
{
    /* Start user code for r_Config_SCI8_callback_receiveend. Do not edit comment generated here */

    /* Check the contents of g_rx_char */
    if ('z' == g_rx_char)
    {
        /* Stop the timer used to control transmission to PC terminal*/
        R_Config_CMT2_Stop();

        /* Turn off LED0 and turn on LED1 to indicate serial transmission
           inactive */
        LED0 = LED_OFF;
        LED1 = LED_ON;
    }
    else
    {
        /* Start the timer used to control transmission to PC terminal*/
        R_Config_CMT2_Start();

        /* Turn on LED0 and turn off LED1 to indicate serial transmission
           active */
        LED0 = LED_ON;
        LED1 = LED_OFF;
    }

    /* Set up SCI1 receive buffer again */
    R_Config_SCI8_Serial_Receive((uint8_t *)&g_rx_char, 1);

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_SCI8_callback_receiveerror
* Description  : This function is a callback function when SCI8 reception encounters error
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/

static void r_Config_SCI8_callback_receiveerror(void)
{
    /* Start user code for r_Config_SCI8_callback_receiveerror. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SCI8_AsyncTransmit
* Description  : This function sends SCI8 data and waits for the transmit end flag.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_SCI8_AsyncTransmit(uint8_t * const tx_buf, const uint16_t tx_num)
{
    MD_STATUS status = MD_OK;
    
    /* clear the flag before initiating a new transmission */
    sci8_txdone = FALSE;

    /* Send the data using the API */
    status = R_Config_SCI8_Serial_Send(tx_buf, tx_num);

    /* Wait for the transmit end flag */
    while (FALSE == sci8_txdone)
    {
        /* Wait */
    }
    return (status);
}

/***********************************************************************************************************************
* End of function R_SCI8_AsyncTransmit
***********************************************************************************************************************/

/* End user code. Do not edit comment generated here */

