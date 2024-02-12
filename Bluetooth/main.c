/*
 * Main.c
 *
 *  Created on: 9/2/2024
 *      Author: Ahmed Abdelmotelb Ali
 */
#include "tm4c123gh6pm.h"
#include "Bluetooth.h"
#include "Type.h"
#include "UART.h"
#include "Lcd.h"
#include "RGB_LEDS.h"

int main(void)
{
    Bluetooth_init();
    Lcd_Init();

    /* Set PF1, PF2 and PF3 as digital output pins
       enable clock to GPIOF
       set PF1, PF2 and PF3 as digital output pin
       CON PF1, PF2 and PF3 as digital GPIO pins*/
    RGB_LEDS_Init();
    Delay(10);
    LCD_displayString("hi every one");
    Delay(10);

    while(1)
    {
        char c = Bluetooth_Read();          /* get a character from UART5 */

/* Check the received character and take action to control onboard LEDs of TM4C123 */
/* Send status string to Andriod app after turning on/off LEDs */
        Bluetooth_Control(c);

    }
}





