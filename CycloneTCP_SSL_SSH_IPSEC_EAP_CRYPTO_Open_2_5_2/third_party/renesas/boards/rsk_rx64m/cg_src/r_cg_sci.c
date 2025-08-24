/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only 
* intended for use with Renesas products. No other uses are authorized. This 
* software is owned by Renesas Electronics Corporation and is protected under 
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING 
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT 
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS 
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE 
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR 
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE 
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software 
* and to discontinue the availability of this software.  By using this software, 
* you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2013, 2014 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_sci.c
* Version      : Code Generator for RX64M V1.00.01.01 [09 May 2014]
* Device(s)    : R5F564MLCxFC
* Tool-Chain   : CCRX
* Description  : This file implements device driver for SCI module.
* Creation Date: 30/06/2014
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
#include "r_cg_sci.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
uint8_t * gp_sci6_tx_address;               /* SCI6 transmit buffer address */
uint16_t  g_sci6_tx_count;                  /* SCI6 transmit data number */
uint8_t * gp_sci7_tx_address;               /* SCI7 transmit buffer address */
uint16_t  g_sci7_tx_count;                  /* SCI7 transmit data number */
uint8_t * gp_sci7_rx_address;               /* SCI7 receive buffer address */
uint16_t  g_sci7_rx_count;                  /* SCI7 receive data number */
uint16_t  g_sci7_rx_length;                 /* SCI7 receive data length */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SCI6_Create
* Description  : This function initializes SCI6.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SCI6_Create(void)
{
    /* Cancel SCI6 module stop state */
    MSTP(SCI6) = 0U;

    /* Set interrupt priority */
    IPR(SCI6, TXI6) = _0F_SCI_PRIORITY_LEVEL15;

    /* Clear the control register */
    SCI6.SCR.BYTE = 0x00U;

    /* Set clock enable */
    SCI6.SCR.BYTE |= _01_SCI_INTERNAL_SCK_OUTPUT;

    /* Clear the SIMR1.IICM */
    SCI6.SIMR1.BIT.IICM = 0U;

    /* Set control registers */
    SCI6.SPMR.BYTE = _00_SCI_SS_PIN_DISABLE | _00_SCI_SPI_MASTER | _00_SCI_CLOCK_NOT_INVERTED | 
                     _00_SCI_CLOCK_NOT_DELAYED;
    SCI6.SMR.BYTE = _00_SCI_DATA_LENGTH_8 | _80_SCI_CLOCK_SYNCHRONOUS_MODE | _00_SCI_CLOCK_PCLK;
    SCI6.SCMR.BYTE = _00_SCI_SERIAL_MODE | _00_SCI_DATA_INVERT_NONE | _08_SCI_DATA_MSB_FIRST | 
                     _10_SCI_DATA_LENGTH_8_OR_7 | _62_SCI_SCMR_DEFAULT;
    SCI6.SEMR.BYTE = _00_SCI_BIT_MODULATION_DISABLE;

    /* Set bitrate */
    SCI6.BRR = 0x09U;

    /* Set SMISO6 pin */
    MPC.P01PFS.BYTE = 0x0AU;
    PORT0.PMR.BYTE |= 0x02U;

    /* Set SMOSI6 pin */
    MPC.P00PFS.BYTE = 0x0AU;
    PORT0.PMR.BYTE |= 0x01U;

    /* Set SCK6 pin */
    MPC.P02PFS.BYTE = 0x0AU;
    PORT0.PMR.BYTE |= 0x04U;
}
/***********************************************************************************************************************
* Function Name: R_SCI6_Start
* Description  : This function starts SCI6.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SCI6_Start(void)
{
    /* Enable TXI and TEI interrupt */
    IEN(SCI6,TXI6) = 1U;
    ICU.GENBL0.BIT.EN12 = 1U;

    /* Clear interrupt flags */
    IR(SCI6,TXI6) = 0U;
    IR(SCI6,RXI6) = 0U;
}
/***********************************************************************************************************************
* Function Name: R_SCI6_Stop
* Description  : This function stops SCI6.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SCI6_Stop(void)
{
    /* Set SMOSI6 pin */
    PORT0.PMR.BYTE &= 0xFEU;
    /* Set SMISO6 pin */
    PORT0.PMR.BYTE &= 0xFDU;
    /* Disable TXI and TEI interrupt */
    IEN(SCI6,TXI6) = 0U;
    ICU.GENBL0.BIT.EN12 = 0U;

    /* Clear interrupt flags */
    IR(SCI6,TXI6) = 0U;
    IR(SCI6,RXI6) = 0U;
}
/***********************************************************************************************************************
* Function Name: R_SCI6_SPI_Master_Send
* Description  : This function sends SPI6 data to slave device.
* Arguments    : tx_buf -
*                    transfer buffer pointer (Not used when transmit data handled by DTC or DMAC)
*                tx_num -
*                    buffer size (Not used when receive data handled by DTC or DMAC)
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_SCI6_SPI_Master_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_sci6_tx_address = tx_buf;
        g_sci6_tx_count = tx_num;
        /* Set SMOSI6 pin */
        MPC.P00PFS.BYTE = 0x0AU;
        PORT0.PMR.BYTE |= 0x01U;

        SCI6.SCR.BIT.TIE = 1U;
        SCI6.SCR.BIT.TE = 1U;
    }

    return (status);
}
/***********************************************************************************************************************
* Function Name: R_SCI7_Create
* Description  : This function initializes SCI7.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SCI7_Create(void)
{
    /* Cancel SCI7 module stop state */
    MSTP(SCI7) = 0U;

    /* Set interrupt priority */
    IPR(SCI7, RXI7) = _0F_SCI_PRIORITY_LEVEL15;
    IPR(SCI7, TXI7) = _0C_SCI_PRIORITY_LEVEL12;

    /* Clear the control register */
    SCI7.SCR.BYTE = 0x00U;

    /* Set clock enable */
    SCI7.SCR.BYTE = _00_SCI_INTERNAL_SCK_UNUSED;

    /* Clear the SIMR1.IICM, SPMR.CKPH, and CKPOL bit, and set SPMR */
    SCI7.SIMR1.BIT.IICM = 0U;
    SCI7.SPMR.BYTE = _00_SCI_RTS | _00_SCI_CLOCK_NOT_INVERTED | _00_SCI_CLOCK_NOT_DELAYED;

    /* Set control registers */
    SCI7.SMR.BYTE = _00_SCI_CLOCK_PCLK | _00_SCI_STOP_1 | _00_SCI_PARITY_EVEN | _00_SCI_PARITY_DISABLE | 
                    _00_SCI_DATA_LENGTH_8 | _00_SCI_MULTI_PROCESSOR_DISABLE | _00_SCI_ASYNCHRONOUS_MODE;
    SCI7.SCMR.BYTE = _00_SCI_SERIAL_MODE | _00_SCI_DATA_INVERT_NONE | _00_SCI_DATA_LSB_FIRST | 
                     _10_SCI_DATA_LENGTH_8_OR_7 | _62_SCI_SCMR_DEFAULT;
    SCI7.SEMR.BYTE = _00_SCI_LOW_LEVEL_START_BIT | _20_SCI_NOISE_FILTER_ENABLE | _10_SCI_8_BASE_CLOCK | 
                     _00_SCI_BAUDRATE_SINGLE | _04_SCI_BIT_MODULATION_ENABLE;
    SCI7.SNFR.BYTE = _00_SCI_ASYNC_DIV_1;

    /* Set bitrate */
    SCI7.BRR = 0xC2U;
    SCI7.MDDR = 0xFFU;

    /* Set RXD7 pin */
    MPC.P92PFS.BYTE = 0x0AU;
    PORT9.PMR.BYTE |= 0x04U;

    /* Set TXD7 pin */
    PORT9.PODR.BYTE |= 0x01U;
    MPC.P90PFS.BYTE = 0x0AU;
    PORT9.PMR.BYTE |= 0x01U;
}
/***********************************************************************************************************************
* Function Name: R_SCI7_Start
* Description  : This function starts SCI7.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SCI7_Start(void)
{
    /* Clear interrupt flag */
    IR(SCI7,TXI7) = 0U;
    IR(SCI7,RXI7) = 0U;

    /* Enable SCI interrupt */
    IEN(SCI7,TXI7) = 1U;
    ICU.GENBL0.BIT.EN14 = 1U;
    IEN(SCI7,RXI7) = 1U;
    ICU.GENBL0.BIT.EN15 = 1U;
}
/***********************************************************************************************************************
* Function Name: R_SCI7_Stop
* Description  : This function stops SCI7.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SCI7_Stop(void)
{
    PORT9.PMR.BYTE &= 0xFEU;
    SCI7.SCR.BIT.TE = 0U;      /* Disable serial transmit */
    SCI7.SCR.BIT.RE = 0U;      /* Disable serial receive */
    SCI7.SCR.BIT.TIE = 0U;     /* Disable TXI interrupt */
    SCI7.SCR.BIT.RIE = 0U;     /* Disable RXI and ERI interrupt */

    /* Disable SCI interrupt */
    IR(SCI7,TXI7) = 0U;
    IEN(SCI7,TXI7) = 0U;
    ICU.GENBL0.BIT.EN14 = 0U;
    IR(SCI7,RXI7) = 0U;
    IEN(SCI7,RXI7) = 0U;
    ICU.GENBL0.BIT.EN15 = 0U;
}
/***********************************************************************************************************************
* Function Name: R_SCI7_Serial_Receive
* Description  : This function receives SCI7 data.
* Arguments    : rx_buf -
*                    receive buffer pointer (Not used when receive data handled by DTC or DMAC)
*                rx_num -
*                    buffer size (Not used when receive data handled by DTC or DMAC)
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_SCI7_Serial_Receive(uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        g_sci7_rx_count = 0U;
        g_sci7_rx_length = rx_num;
        gp_sci7_rx_address = rx_buf;
        SCI7.SCR.BIT.RIE = 1U;
        SCI7.SCR.BIT.RE = 1U;
    }

    return (status);
}
/***********************************************************************************************************************
* Function Name: R_SCI7_Serial_Send
* Description  : This function transmits SCI7 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer (Not used when transmit data handled by DTC)
*                tx_num -
*                    buffer size (Not used when transmit data handled by DTC or DMAC)
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_SCI7_Serial_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        gp_sci7_tx_address = tx_buf;
        g_sci7_tx_count = tx_num;
        MPC.P90PFS.BYTE = 0x0AU;
        PORT9.PMR.BYTE |= 0x01U;
        SCI7.SCR.BIT.TIE = 1U;
        SCI7.SCR.BIT.TE = 1U;
    }

    return (status);
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
