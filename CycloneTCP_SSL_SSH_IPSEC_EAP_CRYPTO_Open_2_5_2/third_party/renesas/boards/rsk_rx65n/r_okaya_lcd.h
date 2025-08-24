/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer 
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.    
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_okaya_lcd.h
* Version      : 1.00
* Device(s)    : R5F565N9AxFB
* Tool-Chain   : CCRX
* H/W Platform : RSK+RX65N
* Description  : This Header file contains the Macro Definitions & prototypes
*                for the functions used in lcd.c
*
*  This function is created to drive the Okaya LCD display with either ST7735 or ST7715 driver device. The commands
*  for both the devices are the same.
*
*  The display is controlled using the SPI bus. In this example, the SCI7 is used. This can be modified to the SCI
*  connected to the PMOD interface. The SCI driver file will also be required.
*
*  The display memory has an offset with respect to the actual pixel. This is not documented but realised from driving
*  the display. The offset is set as LEFT MARGIN and TOP MARGIN. this offset is catered for internally, so as far as
*  the user is concerned, cursor position 0,0 is the top left pixel.
*
*  The simplest procedure to run the display is as follows:
*       Init_LCD(); // Initialize the serial port and set up the display. Clear the display.
*                   // The font color is set to white and background color to black.
*       DisplaySetFontColor(COL_YELLOW);    // set the font color to desired color
*       DisplaySetBackColor(COL_BLUE);      // set the background color to desired value
*       DisplayCenter(1,"Renesas");         // write a title on line 1 of the display.
*                                           // Note: Line 0 is the top line.
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 30.06.2016 1.00     First Release
***********************************************************************************************************************/
/* Multiple inclusion prevention macro */
#ifndef OKAYA_LCD_H
#define OKAYA_LCD_H

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "iorx65n.h"

/***********************************************************************************************************************
*
*  SCREEN
*
*  The screen size is 128 x 128 pixels, with coordinate 0,0 at the top left.
*  The display controller is ST7735 or ST7715.
*
***********************************************************************************************************************/
#define SCREEN_HEIGHT (128)            /* 16 lines @ 8 bits = 128. */
#define SCREEN_WIDTH  (128)

/* DATA/COMMAND select pin */
#define DATA_CMD_PIN              (PORT5.PODR.BIT.B6)

/* DATA/COMMAND select pin */
#define DATA_CMD_PIN_DIR          (PORT5.PDR.BIT.B6)

/* Pin defines common to both displays */

/* Display enable pin */
#define ENABLE_PIN                (PORT9.PODR.BIT.B3)

/* Display enable pin */
#define ENABLE_PIN_DIR            (PORT9.PDR.BIT.B3)

/* Reset pin */
#define RESET_PIN                 (PORT0.PODR.BIT.B2)

/* Reset pin pmr bit */
#define RESET_PIN_PMR             (PORT0.PMR.BIT.B2)

/* Display enable pin */   
#define RESET_PIN_DIR             (PORT0.PDR.BIT.B2)

/* Backlight enable pin */
#define BL_ENABLE_PIN             (PORT5.PODR.BIT.B5)

/* Vdd enable pin */
#define VDD_ENABLE_PIN_DIR        (PORT5.PDR.BIT.B5)

/* Automatic calculation of parameters */
#define FONT_WIDTH                (6)   /* Including a space */
#define FONT_HEIGHT               (8)   /* Including 1 pixel space */
#define MAX_LINES                 (SCREEN_HEIGHT / FONT_HEIGHT)
#define CHAR_PER_LINE             (SCREEN_WIDTH / FONT_WIDTH)

#define LEFT_MARGIN (2)             /* Allow 2 pixel margin on the left and the top */
#define TOP_MARGIN  (3)
#define CR (0x0d)
#define LF (0x0a)
#define BS (0x08)


/***********************************************************************************************************************

  DISPLAY color DEFINITIONS (16 bits) R5G6B5 format

  Only Primary & secondary colors are defined here. Other colors can be created using RGB values.

***********************************************************************************************************************/
#define COL_BLACK       (0X0000)
#define COL_RED         (0Xf800)
#define COL_GREEN       (0X07E0)
#define COL_BLUE        (0X001F)
#define COL_YELLOW      (0XFFE0)
#define COL_CYAN        (0X07FF)
#define COL_MAGENTA     (0XF81F)
#define COL_WHITE       (0XFFFF)

/***********************************************************************************************************************

  DISPLAY COMMAND SET ST7735

***********************************************************************************************************************/
#define ST7735_NOP      (0x0)
#define ST7735_SWRESET  (0x01)
#define ST7735_SLPIN    (0x10)
#define ST7735_SLPOUT   (0x11)
#define ST7735_PTLON    (0x12)
#define ST7735_NORON    (0x13)
#define ST7735_INVOFF   (0x20)
#define ST7735_INVON    (0x21)
#define ST7735_DISPON   (0x29)
#define ST7735_CASET    (0x2A)
#define ST7735_RASET    (0x2B)
#define ST7735_RAMWR    (0x2C)
#define ST7735_COLMOD   (0x3A)
#define ST7735_MADCTL   (0x36)
#define ST7735_FRMCTR1  (0xB1)
#define ST7735_INVCTR   (0xB4)
#define ST7735_DISSET5  (0xB6)
#define ST7735_PWCTR1   (0xC0)
#define ST7735_PWCTR2   (0xC1)
#define ST7735_PWCTR3   (0xC2)
#define ST7735_VMCTR1   (0xC5)
#define ST7735_PWCTR6   (0xFC)
#define ST7735_GMCTRP1  (0xE0)
#define ST7735_GMCTRN1  (0xE1)

/* Delay for delay counter */
#define DELAY_TIMING              (8)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/
/* Initializes the debug LCD */
void R_LCD_Init (void);

/* Display string at specific line of display */
void R_LCD_Display (uint8_t const position,  uint8_t * const string);

/* Display the string at current cursor position */
void R_LCD_DisplayStr (uint8_t * str);

/* Display the string at the center of the specified line */
void R_LCD_DisplayCenter (uint8_t const line_num, uint8_t * const str);

/* Clears the display */
void R_LCD_ClearDisplay (const uint16_t color);

/* Clear a specified line */
void R_LCD_DisplayClearLine (const uint8_t line_num);

/* Set the current cursor position */
void R_LCD_DisplaySetCursor (uint8_t const x, uint8_t const y);

/* Set Font color */
void R_LCD_DisplaySetFontColor (uint16_t const col);

/* Set Background color */
void R_LCD_DisplaySetBackColor (uint16_t const col);

#endif

