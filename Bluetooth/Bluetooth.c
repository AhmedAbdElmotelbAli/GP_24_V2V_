/*
 * Bluetooth.c
 *
 *  Created on: 9/2/2024
 *      Author: Ahmed Abdelmotelb Ali
 */
#include "tm4c123gh6pm.h"
#include "Type.h"
#include "UART.h"
#include "Lcd.h"
#include "RGB_LEDS.h"
void Bluetooth_init(void)
{
    UART_INIT(5);
}
uint08_t Bluetooth_Read(void)
{

       uint08_t data;
       UART_RX(&data,5);
       return  data;
}
void Bluetooth_Write(unsigned char data)
{
    UART_TX(data,5);
}
void Bluetooth_Write_String(char *str)
{
  while(*str)
    {
        Bluetooth_Write(*(str++));
    }
}

void Delay(unsigned long counter)
{
    unsigned long i = 0;

    for(i=0; i< counter; i++);
}

void Bluetooth_Control(char data)
{
    switch (data)
              {
                  case 'A':
                      RGB_LEDS_State(LED_STATE_ON,LED_STATE_OFF,LED_STATE_OFF);
                       Bluetooth_Write_String("RED LED ON\n");
                       LCD_clearScreen();
                       LCD_displayString("RED LED ON");
                      break;
                  case 'B':
                      /*Medium Speed*/
                      RGB_LEDS_State(LED_STATE_OFF,LED_STATE_OFF,LED_STATE_OFF);
                      Bluetooth_Write_String("RED LED OFF\n");
                      LCD_clearScreen();
                      LCD_displayString("RED LED OFF");
                      break;
                  case 'C':
                      RGB_LEDS_State(LED_STATE_OFF,LED_STATE_OFF,LED_STATE_ON);
                      Bluetooth_Write_String("BLUE LED ON\n");
                      LCD_clearScreen();
                      LCD_displayString("BLUE LED ON");
                      break;
                  case 'D':
                      /*Medium Speed*/
                      RGB_LEDS_State(LED_STATE_OFF,LED_STATE_OFF,LED_STATE_OFF);
                      Bluetooth_Write_String("BLUE LED OFF\n");
                      LCD_clearScreen();
                      LCD_displayString("BLUE LED OFF");
                      break;
                  case 'E':
                      RGB_LEDS_State(LED_STATE_OFF,LED_STATE_ON,LED_STATE_OFF);
                      Bluetooth_Write_String("GREEN LED ON\n");
                      LCD_clearScreen();
                      LCD_displayString("GREEN LED ON");
                      break;

                  case 'F':
                      /*Medium Speed*/
                       RGB_LEDS_State(LED_STATE_OFF,LED_STATE_OFF,LED_STATE_OFF);
                      Bluetooth_Write_String("GREEN LED OFF\n");
                      LCD_clearScreen();
                      LCD_displayString("GREEN LED ON");
                      break;


                  default:
                      /*Do nothing*/
                      break;
              }
}
