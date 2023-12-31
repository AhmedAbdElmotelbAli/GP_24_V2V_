/*
 * main.c
 *
 *  Created on: Dec 31, 2023
 *      Author: Ahmed Adel Hasssan
 */

#include "Type.h"
#include "GPIO.h"
#include "Lcd.h"
void main(void) {
    Lcd_Init();
    LCD_clearScreen();
    LCD_displayString("Ahmed Adel");
    Delay_MS(5000);
    LCD_clearScreen();
    LCD_moveCursorXY(0,4);
    LCD_displayString("Hello (;");
    LCD_moveCursorXY(1,4);
    LCD_displayString("test LCD");
    Delay_MS(5000);
    LCD_clearScreen();


}


