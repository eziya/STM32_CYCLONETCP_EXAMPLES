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
* Copyright (C) 2016, 2017 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_okaya_lcd.c
* Version      : 1.00
* Device(s)    : R5F565NEDxFC
* Tool-Chain   : CCRX
* H/W Platform : RSK+RX65N-2MB
* Description  : LCD Module utility functions.
*
* Please refer to the header file r_okaya_lcd.h for detailed explanation
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 31.05.2017 1.00     First Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
/* Includes assembly level definitions */
#include <string.h>
#include "r_cg_macrodriver.h"

/* SPI Driver Layer */
#include "Config_SCI6.h"

/* CMT functions used for delays */
#include "Config_CMT0.h"

/* LCD controlling function prototypes & macro definitions */
#include "r_okaya_lcd.h"
#include "ascii.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
/* LCD cursor co-ordinates */
static uint8_t curx = 0;
static uint8_t cury = 0;

static uint16_t font_color = COL_WHITE;
static uint16_t back_color = COL_BLACK;


static void init_pmod_lcd (void);

static void char_put (uint8_t const val);
static void display_write_command (uint8_t const  cmd);
static void display_write_data (uint8_t const data);
static void display_write_pixel (uint8_t const x, uint8_t const y, uint16_t const color);
static void display_draw_horz_line (uint8_t const line, uint16_t const  color);
static void display_set_addr_window (uint8_t xs, uint8_t ys, uint8_t xe, uint8_t ye);
static void display_write_char_column (uint8_t const x, uint8_t const y, uint8_t const pattern);

/***********************************************************************************************************************
* Function Name: R_LCD_Init
* Description  : Initializes the serial port and the LCD display. Clear the display with black background.
*                Set the font color to white.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void R_LCD_Init (void)
{
    /* Start SPI comm channel to LCD Display */
	R_Config_SCI6_Start();

    /* Initialize Standard PMOD display */
    init_pmod_lcd();

    /* Clear the display before use */
    R_LCD_ClearDisplay(back_color);
}
/***********************************************************************************************************************
* End of function R_LCD_Init
***********************************************************************************************************************/

/**********************************************************************************************************************
* Function Name: R_LCD_Display
* Description  : This function controls LCD writes to the start of the line  of the LCD.
*                specified by position of the LCD. If position is greater than the
*                number of lines available then the LCD write will be to the last line.
* Arguments    : (uint8_t)position -   Line number of display
*                (const char *) string -Pointer to data to be written to
*                               display. Last character should be null.
* Return Value : none
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
* Function Name: R_LCD_DisplayStr
* Description  : Displays a string at the current cursor position
* Arguments    : char *string - pointer to a string
* Return Value : none
***********************************************************************************************************************/
void R_LCD_DisplayStr (uint8_t * str)
{
    uint16_t i;
    uint16_t size;

    size = (uint16_t)strlen((const char *)str);

    /* Load characters into screen bitmap */
    for (i = 0; i < size; i++)
    {
        char_put(*str++);
    }
}
/***********************************************************************************************************************
* End of function R_LCD_DisplayStr
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_LCD_DisplayCenter
* Description  : Display a string in the center of the specified line.
* Arguments    : uint8_t line_num - line number (0-15)
*                pointer to a string.
* Return Value : none
***********************************************************************************************************************/
void R_LCD_DisplayCenter (uint8_t const line_num, uint8_t * const str)
{
    uint8_t spaces;

    R_LCD_DisplaySetCursor(0, line_num);

    spaces = (uint8_t)((CHAR_PER_LINE - strlen((const char *)str)) / 2);
    while (spaces--)
    {
        char_put(' ');
    }
    R_LCD_DisplayStr(str);
}
/***********************************************************************************************************************
* End of function R_LCD_DisplayCenter
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_LCD_ClearDisplay
* Description  : This function clears the screen
* Arguments    : uint16_t color - in R5G6B5 format
* Return Value : none
***********************************************************************************************************************/
void R_LCD_ClearDisplay (const uint16_t color)
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
            display_write_data((uint8_t)(color >> 8));
            display_write_data((uint8_t)color);
        }
    }

    /* Cursor to Home Position */
    R_LCD_DisplaySetCursor(0, 0);
}
/***********************************************************************************************************************
* End of function R_LCD_ClearDisplay
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_LCD_DisplayClearLine
* Description  : Clear the specified line
* Arguments    : uint8_t line numb 0 - 15
* Return Value : none
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
            display_draw_horz_line(y, back_color);
        }
        R_LCD_DisplaySetCursor(0, line_num);
    }
}
/***********************************************************************************************************************
* End of function R_LCD_DisplayClearLine
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_LCD_DisplaySetCursor
* Description  : Set the cursor to the specified position. the position must be
*                within the limits.
* Arguments    : uint8_t x - X position
*                        y - Y position
* Return Value : none
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
* Function Name: R_LCD_DisplaySetFontColor
* Description  : Set the font (foreground) color
* Arguments    : uint16_t col - color value in r5g6b5 format
* Return Value : none
***********************************************************************************************************************/
void R_LCD_DisplaySetFontColor (uint16_t const col)
{
    font_color = col;
}
/***********************************************************************************************************************
* End of function R_LCD_DisplaySetFontColor
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_LCD_DisplaySetBackColor
* Description  : Set the background color
* Arguments    : uint16_t col - color value in r5g6b5 format
* Return Value : none
***********************************************************************************************************************/
void R_LCD_DisplaySetBackColor (uint16_t const col)
{
    back_color = col;
}
/***********************************************************************************************************************
* End of function R_LCD_DisplaySetBackColor
***********************************************************************************************************************/

/***********************************************************************************************************************
* Internal Functions
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: init_pmod_lcd
* Description  : Initializes the LCD display.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void init_pmod_lcd (void)
{
    /* Preset the output ports for i/o pins prior to setting as outputs */
    DATA_CMD_PIN = 0x1;
    ENABLE_PIN  = 0x1;
    RESET_PIN = 0x1;

    /* Backlight off */
    BL_ENABLE_PIN = 0x0;

    R_CMT_MsDelay(10);

    /* Clear reset line to reset display */
    RESET_PIN = 0x0;

    /* Wait 10 ms */
    R_CMT_MsDelay(10);

    /* Release reset */
    RESET_PIN = 0x1;

    /* Software reset */
    display_write_command(ST7735_SWRESET);
    R_CMT_MsDelay(120);

    /* Out of sleep mode */
    display_write_command(ST7735_SLPOUT);
    R_CMT_MsDelay(120);

    /* Set color mode */
    display_write_command(ST7735_COLMOD);

    /* 16 bit color */
    display_write_data(0x05);
    R_CMT_MsDelay(10);
 
    /* Memory access control (directions) */
    display_write_command(ST7735_MADCTL);

    /* Row address/col address, bottom to top refresh */
    display_write_data(0xC8);

    /* Normal mode */
    display_write_command(ST7735_NORON);
    R_CMT_MsDelay(10);

    /* Display on */
    display_write_command(ST7735_DISPON);
    R_CMT_MsDelay(120);

    R_LCD_DisplaySetFontColor(COL_GREEN);
    R_LCD_DisplaySetBackColor(COL_BLACK);

    /* Enable backlight */
    BL_ENABLE_PIN = 0x01;
}
/***********************************************************************************************************************
* End of function init_pmod_lcd
***********************************************************************************************************************/

/*======================================================================
           LOW LEVEL FUNCTIONS
  ====================================================================*/

/***********************************************************************************************************************
* Function Name: char_put
* Description  : Displays a character at the current cursor position.
*                Advances the cursor by 1 position.
*                Cursor wraps to next line at the end of the line.
*                Cursor wraps to Home position at the end of the display.
*
*                The following control codes are accepted:
*
*                LF increments y cursor position
*                CR resets x cursor to 0.
*                BS moves x cursor back by 1 place if possible.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void char_put (uint8_t const val)
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

                /* Move cursor to next co-ordinate on LCD */
                curx++;

                /* Move to next row if reached the end of line */
                if (curx >= CHAR_PER_LINE)
                {
                    curx = 0;
                    cury++;
                    if (cury >= MAX_LINES)
                    {
                        /* Loop back to top line if the last line of the display is reached */
                        cury = 0;
                    }
                }
            }
        }
        break;
    }
}
/***********************************************************************************************************************
* End of function char_put
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: display_write_command
* Description  : Encapsulation of SPI6 send, sends 1 cmd byte.
* Arguments    : cmd - Command to write
* Return Value : None
* Note         : DATA_CMD_PIN is set low for command
***********************************************************************************************************************/
static void display_write_command (uint8_t const cmd)
{
    static uint8_t s_cmd = 0u;

    /* Data cmd pin low to indicate a command */
    DATA_CMD_PIN = 0x0;

    /* Assert chip select */
    ENABLE_PIN  = 0x0;

    /* Write the command */
    s_cmd = cmd;
    R_SCI6_SPIMasterTransmit(&s_cmd, 1);

    /* De-assert chip select */
    ENABLE_PIN  = 0x1;

    /* Data cmd pin high to signify data */
    DATA_CMD_PIN = 0x1;

}
/***********************************************************************************************************************
* End of function display_write_command
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: display_write_data
* Description  : Write a data byte to the display
* Arguments    : data - data to write
* Return Value : None
* Note         : DATA_CMD_PIN is set hi for data.
***********************************************************************************************************************/
static void display_write_data (uint8_t const data)
{
    static uint8_t s_data_block_content = 0u;

    /* Data cmd pin high to signify data */
    DATA_CMD_PIN = 0x1;

    /* Assert chip select */
    ENABLE_PIN  = 0x0;

    /* Write the data */
    s_data_block_content = data;
    R_SCI6_SPIMasterTransmit(&s_data_block_content, 1);

    /* De-assert chip select */
    ENABLE_PIN  = 0x1;

    /* Data cmd pin high to signify data */
    DATA_CMD_PIN = 0x1;
}
/***********************************************************************************************************************
* End of function display_write_data
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: display_write_pixel
* Description  : Write the color to the current cursor position
* Arguments    : x,y - pixel position
*                color in R5G6B5 format
* Return Value : None
***********************************************************************************************************************/
static void display_write_pixel (uint8_t const x, uint8_t const y, uint16_t const color)
{
    const uint8_t x1 = (uint8_t)(x + 1);
    const uint8_t y1 = (uint8_t)(y + 1);

    display_set_addr_window(x, y, x1, y1);
    display_write_command(ST7735_RAMWR);
    display_write_data((uint8_t)(color >> 8));
    display_write_data((uint8_t)(color));
}

/***********************************************************************************************************************
* End of function display_write_pixel
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: display_draw_horz_line
* Description  : Draw horz line with the specified color
* Arguments    : line - line number to draw
*                color in R5G6B5 format
* Return Value : None
***********************************************************************************************************************/
static void display_draw_horz_line (uint8_t const line, uint16_t const color)
{
    uint8_t i;
    uint8_t x;
    uint8_t y;

    if (line < SCREEN_HEIGHT)
    {
        x = (SCREEN_WIDTH - 1);
        y = (uint8_t)(line + 1);
        display_set_addr_window(0, line, x, y);

        /* Write to RAM */
        display_write_command(ST7735_RAMWR);

        for (i = 0; i < SCREEN_WIDTH; i++)
        {
            display_write_data((uint8_t)(color >> 8));
            display_write_data((uint8_t)(color));
        }
    }
}
/***********************************************************************************************************************
* End of function display_draw_horz_line
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: display_set_addr_window
* Description  : Draw horz line with the specified color
* Arguments    : xs, ys start pixel position
*                ys, ye end pixel position
* Return Value : None
***********************************************************************************************************************/
static void display_set_addr_window (uint8_t xs, uint8_t ys, uint8_t xe, uint8_t ye)
{
    if (((ys <= ye) && (xs <= xe)) && ((ye < SCREEN_HEIGHT) && (xe < SCREEN_WIDTH)))
    {
        xs += LEFT_MARGIN;
        xe += LEFT_MARGIN;
        ys += TOP_MARGIN;
        ye += TOP_MARGIN;

        /* Column addr set */
        display_write_command(ST7735_CASET);
        display_write_data(0x00);

        /* XSTART */
        display_write_data(xs);
        display_write_data(0x00);

        /* XEND   */
        display_write_data(xe);

        /* Row addr set */
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
* Function Name: display_write_char_column
* Description  : Write a character at a current cursor position
* Arguments    : x,y pixel position
*                pattern to draw 1 = font color, 0 = back color
* Return Value : None
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
            display_write_pixel(x, y1, font_color);
        }
        else
        {
            display_write_pixel(x, y1, back_color);
        }
        mask = (uint8_t)(mask >> 1);
    }
}
/***********************************************************************************************************************
* End of function display_write_char_column
***********************************************************************************************************************/




