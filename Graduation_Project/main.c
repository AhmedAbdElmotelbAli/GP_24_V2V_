/*
 * main.c
 *
 *  Created on: Dec 31, 2023
 *      Author: Ahmed  Abdelmotelb Ali  1901401
 *       Ahmed Adel hassan 1900311
 *
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
    LCD_displayString("Ahmed Abdelmotelb");
    LCD_moveCursorXY(1,4);
    LCD_displayString("test LCD");
    Delay_MS(5000);
    LCD_clearScreen();


}


