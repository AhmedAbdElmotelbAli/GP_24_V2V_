/******************************************************************************
 * File:        Lcd.h
 * Author:      Ahmed Adel Hassan
 * Created on:  12/2/2024
 * Description: Header file for controlling an LCD module in an embedded system.
 ******************************************************************************/

#ifndef LCD_H_
#define LCD_H_

#define LCD_PORT_DATA
#define LCD_PORT_DIR
#include "Type.h" // Include necessary header file(s) for types used

/*LCD command */
#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_CURSOR_BLINKING            0x0F
#define LCD_SET_CURSOR_LOCATION        0x80    /*force cursor to beginning of the 1st line */
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_ENTRY_MODE                 0x06


#define LCD_PORT_ID                    GPIO_PORTB

#define LCD_RS_PORT_ID                 GPIO_PORTB
#define LCD_RS_PIN_ID                  GPIO_PIN_4

#define LCD_E_PORT_ID                  GPIO_PORTB
#define LCD_E_PIN_ID                   GPIO_PIN_7

#define LCD_RW_PORT_ID                 GPIO_PORTB
#define LCD_RW_PIN_ID                  GPIO_PIN_5


/******************************************************************************
 * Function:    Lcd_VoidInit
 * Description: Initialization function.
 *              Sets RS, RW, E, and data port as output pins.
 * Parameters:  None
 * Returns:     None
 ******************************************************************************/
void Lcd_VoidInit(void);

/******************************************************************************
 * Function:    LCD_VoidclearScreen
 * Description: Clears the screen of the LCD.
 * Parameters:  None
 * Returns:     None
 ******************************************************************************/
void LCD_VoidclearScreen(void);

/******************************************************************************
 * Function:    LCD_VoidDisplayString
 * Description: Displays a string on the screen of the LCD.
 * Parameters:
 *              str: Pointer to the string to be displayed.
 * Returns:     None
 ******************************************************************************/
void LCD_VoidDisplayString(char * str);

/******************************************************************************
 * Function:    LCD_VoidMoveCursorXY
 * Description: Moves the cursor to a specific row and column.
 * Parameters:
 *              r: Row number (starting from 0).
 *              col: Column number (starting from 0).
 * Returns:     None
 ******************************************************************************/
void LCD_VoidMoveCursorXY(unsigned char r, unsigned char col);

/******************************************************************************
 * Function:    LCD_VoidDisplayStringRowColumn
 * Description: Displays the string in the required position on the screen.
 * Parameters:
 *              row: Row number (starting from 0).
 *              col: Column number (starting from 0).
 *              Str: Pointer to the string to be displayed.
 * Returns:     None
 ******************************************************************************/
void LCD_VoidDisplayStringRowColumn(uint08_t row,uint08_t col,const char *Str);

/******************************************************************************
 * Function:    LCD_VoidIntgerToString
 * Description: Displays the required decimal value on the screen.
 * Parameters:
 *              data: Integer value to be converted to string and displayed.
 * Returns:     None
 ******************************************************************************/
void LCD_VoidIntgerToString(sint16_t data);

/******************************************************************************
 * Function:    LCD_VoidData
 * Description: Sends data to the LCD.
 * Parameters:
 *              data: Data to be sent to the LCD.
 * Returns:     None
 ******************************************************************************/
void LCD_VoidData(uint08_t data);


#endif /* LCD_H_ */
