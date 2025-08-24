/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
***********************************************************************************************************************/
/* Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.   */
/***********************************************************************************************************************
* File Name    : okaya_lcd.c
* Version      : 1.00
* Device(s)    : R5F564MLCxFC
* Tool-Chain   : CCRX
* H/W Platform : RSKRX64M
* Description  : LCD Module utility functions.
*
* Please refer to the header file lcd.h for detailed explanation
***********************************************************************************************************************/
/***********************************************************************************************************************
* History       : 31/03/2014  Ver. 1.00 First Release
***********************************************************************************************************************/

/***********************************************************************************************************************
* User Includes (Project Level Includes)
***********************************************************************************************************************/
/* Includes assembly level definitions */
#include <string.h>
#include "r_cg_macrodriver.h"
#include <iorx64m.h>

/* SPI Driver Layer */
#include "r_cg_sci.h"

/* CMT functions used for delays */
#include "r_cg_cmt.h"

/* LCD controlling function prototypes & macro definitions */
#include "r_okaya_lcd.h"
#include "ascii.h"


/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* LCD cursor co-ordinates */
static uint8_t curx = 0;
static uint8_t cury = 0;

static uint16_t font_colour = COL_WHITE;
static uint16_t back_colour = COL_BLACK;


/***********************************************************************************************************************
* Local Function Prototypes
***********************************************************************************************************************/
static void init_pmod_lcd (void);

static void charput (uint8_t const val);
static void display_write_command (uint8_t const  cmd);
static void display_write_data (uint8_t const data);
static void display_write_pixel (uint8_t const x, uint8_t const y, uint16_t const colour);
static void display_draw_horz_line (uint8_t const line, uint16_t const  colour);
static void display_set_addr_window (uint8_t xs, uint8_t ys, uint8_t xe, uint8_t ye);
static void display_write_char_column (uint8_t const x, uint8_t const y, uint8_t const pattern);

/***********************************************************************************************************************
* Function Name : R_LCD_Init
* Description   : Initialises the serial port and the LCD display. Clear the display with black background.
*                 Set the font colour to white.
* Argument      : none
* Return value  : none
***********************************************************************************************************************/
void R_LCD_Init (void)
{
    /* Start SPI comm channel to LCD Display */
    R_SCI6_Start();

    /* initialise Standard PMOD display */
    init_pmod_lcd();

    /* clear the display before use */
    R_LCD_ClearDisplay(back_colour);
}
/***********************************************************************************************************************
* End of function R_LCD_Init
***********************************************************************************************************************/
/**********************************************************************************************************************
* Function Name : R_LCD_Display
* Description   : This function controls LCD writes to the start of the line  of the LCD.
*                 specified by position of the LCD. If position is greater than the
*                 number of lines available then the LCD write will be to the last line.
* Argument      : (uint8_t)position -   Line number of display
*                 (const char *) string -Pointer to data to be written to
*                                display. Last character should be null.
* Return value  : none
***********************************************************************************************************************/
void R_LCD_Display (uint8_t const position,  uint8_t * const string)
{
    R_LCD_DisplaySetCursor(0, position);
    R_LCD_DisplayStr(string);
}
/***********************************************************************************************************************
* End of function R_LCD_Display
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : R_LCD_DisplayStr
* Description   : Displays a string at the current cursor position
* Argument      : char *string - pointer to a string
* Return value  : none
***********************************************************************************************************************/
void R_LCD_DisplayStr (uint8_t * str)
{
    uint16_t i;
    uint16_t size;

    size = (uint16_t)strlen((const char *)str);
    
    /* load characters into screen bitmap */
    for (i = 0; i < size; i++)
    {
        charput(*str++);
    }
}
/***********************************************************************************************************************
* End of function R_LCD_DisplayStr
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : R_LCD_DisplayCenter
* Description   : Display a string in the center of the specified line.
* Argument      : uint8_t line_num - line number (0-15)
*                 pointer to a string.
* Return value  : none
***********************************************************************************************************************/
void R_LCD_DisplayCenter (uint8_t const line_num, uint8_t * const str)
{
    uint8_t spaces;

    R_LCD_DisplaySetCursor(0, line_num);

    spaces = (uint8_t)((CHAR_PER_LINE - strlen((const char *)str)) / 2);
    while (spaces--)
    {
        charput(' ');
    }
    R_LCD_DisplayStr(str);
}
/***********************************************************************************************************************
* End of function R_LCD_DisplayCenter
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : R_LCD_ClearDisplay
* Description   : This function clears the screen
* Argument      : uint16_t colour - in R5G6B5 format
* Return value  : none
***********************************************************************************************************************/
void R_LCD_ClearDisplay (const uint16_t colour)
{
    uint8_t i;
    uint8_t j;

    display_set_addr_window(0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
    
    /* Write to RAM */
    display_write_command(ST7735_RAMWR);  

    for (i = 0; i < (SCREEN_HEIGHT + 3); i++)
    {
        for (j = 0; j < SCREEN_WIDTH; j++)
        {
            display_write_data((uint8_t)(colour >> 8));  
            display_write_data((uint8_t)colour);
        }
    }
    
    /* Cursor to Home Position */
    R_LCD_DisplaySetCursor(0, 0);
}
/***********************************************************************************************************************
* End of function R_LCD_ClearDisplay
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : R_LCD_DisplayClearLine
* Description   : Clear the specified line
* Argument      : uint8_t line numb 0 - 15
* Return value  : none
***********************************************************************************************************************/
void R_LCD_DisplayClearLine (const uint8_t line_num)
{
    uint8_t i;
    uint8_t y;    
    
    if (line_num < MAX_LINES)
    {
        for (i = 0; i < FONT_HEIGHT; i++)
        {
        y = (uint8_t)((line_num * FONT_HEIGHT) + i);    
            display_draw_horz_line(y, back_colour);
        }
        R_LCD_DisplaySetCursor(0, line_num);
    }
}
/***********************************************************************************************************************
* End of function R_LCD_DisplayClearLine
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : R_LCD_DisplaySetCursor
* Description   : Set the cursor to the specified position. the position must be
*                 within the limits.
* Argument      : uint8_t x - X position
*                         y - Y position
* Return value  : none
***********************************************************************************************************************/
void R_LCD_DisplaySetCursor (uint8_t const x, uint8_t const y)
{
    if (x < CHAR_PER_LINE)
    {
        curx = x;
    }

    if (y < MAX_LINES)
    {
        cury = y;
    }
}
/***********************************************************************************************************************
* End of function R_LCD_DisplaySetCursor
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : R_LCD_DisplaySetFontColour
* Description   : Set the font (foreground) colour
* Argument      : uint16_t col - colour value in r5g6b5 format
* Return value  : none
***********************************************************************************************************************/
void R_LCD_DisplaySetFontColour (uint16_t const col)
{
    font_colour = col;
}
/***********************************************************************************************************************
* End of function R_LCD_DisplaySetFontColour
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : R_LCD_DisplaySetBackColour
* Description   : Set the background colour
* Argument      : uint16_t col - colour value in r5g6b5 format
* Return value  : none
***********************************************************************************************************************/
void R_LCD_DisplaySetBackColour (uint16_t const col)
{
    back_colour = col;
}
/***********************************************************************************************************************
* End of function R_LCD_DisplaySetBackColour
***********************************************************************************************************************/

/***********************************************************************************************************************
* Internal Functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : init_pmod_lcd
* Description   : Initialises the LCD display.
* Argument      : none
* Return value  : none
***********************************************************************************************************************/
static void init_pmod_lcd (void)
{
    /* Preset the output ports for i/o pins prior to setting as outputs */
    DATA_CMD_PIN = 0x1;
    ENABLE_PIN  = 0x1;
    RESET_PIN = 0x1;
    
    /* backlight off */
    BL_ENABLE_PIN = 0x0;

    R_CMT_MsDelay(10);

    /* Clear reset line to reset display */
    RESET_PIN = 0x0;

    /* Wait 10 ms */
    R_CMT_MsDelay(10);

    /* Release reset */
    RESET_PIN = 0x1;

    /* software reset */
    display_write_command(ST7735_SWRESET);  
    R_CMT_MsDelay(120);
    
    /* out of sleep mode */
    display_write_command(ST7735_SLPOUT);   
    R_CMT_MsDelay(120);
    
    /* set color mode */
    display_write_command(ST7735_COLMOD);   
    
    /* 16 bit colour */
    display_write_data(0x05);               
    R_CMT_MsDelay(10);
 
    /* memory access control (directions) */
    display_write_command(ST7735_MADCTL);   
    
    /* row address/col address, bottom to top refresh */
    display_write_data(0xC8);               
    
    /* normal mode */
    display_write_command(ST7735_NORON);   
    R_CMT_MsDelay(10);
    
    /* display on */
    display_write_command(ST7735_DISPON);   
    R_CMT_MsDelay(120);
    
    R_LCD_DisplaySetFontColour(COL_GREEN);
    R_LCD_DisplaySetBackColour(COL_BLACK);
    
    /* enable backlight */
    BL_ENABLE_PIN = 0x01;    
}
/***********************************************************************************************************************
* End of function init_pmod_lcd
***********************************************************************************************************************/

/*======================================================================
           LOW LEVEL FUNCTIONS
  ====================================================================*/

/***********************************************************************************************************************
* Function Name : charput
* Description   : Displays a character at the current cursor position.
*                 Advances the cursor by 1 position.
*                 Cursor wraps to next line at the end of the line.
*                 Cursor wraps to Home position at the end of the display.
*
*                 The following control codes are accepted:
*
*                 LF increments y cursor position
*                 CR resets x cursor to 0.
*                 BS moves x cursor back by 1 place if possible.
* Argument      : none
* Return value  : none
***********************************************************************************************************************/
static void charput (uint8_t const val)
{
    uint8_t * ptr;
    uint8_t   i;
    uint8_t   pattern;
    uint8_t   x;
    uint8_t   y;
    
    switch (val)
    {
        /* Carriage return character */
        case CR:
        {
            curx = 0;
        }    
        break;

        /* Line feed character */
        case LF:
        {
            cury++;
            if (cury >= MAX_LINES)
            {
                cury = 0;
            }
        }    
        break;

        /* Backspace character */
        case BS:
        {
            if (curx > 0)
            {
                curx--;
            }
        }
        break;

        /* Normal displayable characters */
        default:
        {
            /* Ensure value is within the ASCII range */
            if ((val >= 0x20) && (val <= 0x7f))
            {
                /* Get pointer to start of representation of character in ASCII table */
                ptr = (uint8_t *)&g_ascii_table[val - 0x20][0];
                
                /* Copy character over */
                for (i = 0; i < FONT_WIDTH; i++)
                {
                    pattern = (*ptr++);
                    x = (uint8_t)((curx * FONT_WIDTH) + i);
                    y = (uint8_t)(cury * FONT_HEIGHT);
                    display_write_char_column(x, y, pattern);
                }
                
                /* move cursor to next co-ordinate on LCD */
                curx++;

                /* move to next row if reached the end of line */
                if (curx >= CHAR_PER_LINE)
                {
                    curx = 0;
                    cury++;
                    if (cury >= MAX_LINES)
                    {
                        /* loop back to top line if the last line of the display is reached */
                        cury = 0;
                    }
                }
            }
        }
        break;
    }
}
/***********************************************************************************************************************
* End of function charput
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : display_write_command
* Description   : Encapsulation of SPI6 send, sends 1 cmd byte.
* Argument      : cmd - Command to write
* Return value  : None
* Note          : DATA_CMD_PIN is set low for command
***********************************************************************************************************************/
static void display_write_command (uint8_t const cmd)
{
    static uint8_t s_cmd = 0u;

    /* data cmd pin low to indicate a command */
    DATA_CMD_PIN = 0x0;
    
    /* assert chip select */
    ENABLE_PIN  = 0x0;
    
    /* Write the command */
    s_cmd = cmd;
    R_SCI6_SPIMasterTransmit(&s_cmd, 1);

    /* de-assert chip select */
    ENABLE_PIN  = 0x1;

    /* data cmd pin high to signify data */
    DATA_CMD_PIN = 0x1;

}
/***********************************************************************************************************************
* End of function display_write_command
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name : display_write_data
* Description   : Write a data byte to the display
* Argument      : data - data to write
* Return value  : None
* Note          : DATA_CMD_PIN is set hi for data. 
***********************************************************************************************************************/
static void display_write_data (uint8_t const data)
{
    static uint8_t s_data_block_content = 0u;

    /* data cmd pin high to signify data */
    DATA_CMD_PIN = 0x1;
    
    /* assert chip select */
    ENABLE_PIN  = 0x0;
    
    /* Write the data */
    s_data_block_content = data;
    R_SCI6_SPIMasterTransmit(&s_data_block_content, 1);

    /* de-assert chip select */
    ENABLE_PIN  = 0x1;

    /* data cmd pin high to signify data */
    DATA_CMD_PIN = 0x1;
}
/***********************************************************************************************************************
* End of function display_write_data
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : display_write_pixel
* Description   : Write the colour to the current cursor position
* Argument      : x,y - pixel position
*          colour in R5G6B5 format
* Return value  : None
***********************************************************************************************************************/
static void display_write_pixel (uint8_t const x, uint8_t const y, uint16_t const colour)
{
    const uint8_t x1 = (uint8_t)(x + 1);
    const uint8_t y1 = (uint8_t)(y + 1);
    
    display_set_addr_window(x, y, x1, y1);
    display_write_command(ST7735_RAMWR);  
    display_write_data((uint8_t)(colour >> 8));  
    display_write_data((uint8_t)(colour));
}

/***********************************************************************************************************************
* End of function display_write_pixel
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : display_draw_horz_line
* Description   : Draw horz line with the specified colour
* Argument      : line - line number to draw
*          colour in R5G6B5 format    
* Return value  : None
***********************************************************************************************************************/
static void display_draw_horz_line (uint8_t const line, uint16_t const colour)
{
    uint8_t i;
    uint8_t x;
    uint8_t y;
    
    if (line < SCREEN_HEIGHT)
    {
        x = (SCREEN_WIDTH - 1);
        y = (uint8_t)(line + 1);
        display_set_addr_window(0, line, x, y);
        
        /* write to RAM */
        display_write_command(ST7735_RAMWR);
        
        for (i = 0; i < SCREEN_WIDTH; i++)
        {
            display_write_data((uint8_t)(colour >> 8));  
            display_write_data((uint8_t)(colour));
        }        
    }
}
/***********************************************************************************************************************
* End of function display_draw_horz_line
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : display_set_addr_window
* Description   : Draw horz line with the specified colour
* Argument      : xs, ys start pixel position
*                 ys, ye end pixel position
* Return value  : None
***********************************************************************************************************************/
static void display_set_addr_window (uint8_t xs, uint8_t ys, uint8_t xe, uint8_t ye)
{
    if (((ys <= ye) && (xs <= xe)) && ((ye < SCREEN_HEIGHT) && (xe < SCREEN_WIDTH)))
    {
        xs += LEFT_MARGIN;
        xe += LEFT_MARGIN;
        ys += TOP_MARGIN;
        ye += TOP_MARGIN;
        
        /* column addr set */
        display_write_command(ST7735_CASET);   
        display_write_data(0x00);
        
        /* XSTART */
        display_write_data(xs);                
        display_write_data(0x00);
        
        /* XEND   */
        display_write_data(xe);                

        /* row addr set */
        display_write_command(ST7735_RASET);   
        display_write_data(0x00);
        
        
        /* YSTART */
        display_write_data(ys);                
        display_write_data(0x00);
        
        /* YEND   */
        display_write_data(ye);                
        
    }
}
/***********************************************************************************************************************
* End of function display_set_addr_window
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name : display_write_char_column
* Description   : Write a character at a current cursor position
* Argument      : x,y pixel position
*                 pattern to draw 1 = font colour, 0 = back colour
* Return value  : None
***********************************************************************************************************************/
static void display_write_char_column (uint8_t const x, uint8_t const y, uint8_t const pattern)
{
    uint8_t mask;
    uint8_t i;
    uint8_t y1;
    
    mask = 0x80;
    for (i = 0; i < FONT_HEIGHT; i++)
    {
        y1 = (uint8_t)(y + i);
        if (pattern & mask)
        {
            display_write_pixel(x, y1, font_colour);
        }
        else
        {
            display_write_pixel(x, y1, back_colour);
        }
        mask = (uint8_t)(mask >> 1);
    }
}
/***********************************************************************************************************************
* End of function display_write_char_column
***********************************************************************************************************************/




