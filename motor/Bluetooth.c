/*
 * Bluetooth.c
 *
 *  Created on: 9/2/2024
 *      Author: Ahmed Abdelmotelb Ali
 */
#include "tm4c123gh6pm.h"
#include "Type.h"
#include "UART.h"
#include "Motor.h"
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
                  case 'F':
										Motor_GoForward();
									Bluetooth_Write_String("forword");

                      break;
                  case 'B':
                     Motor_Backward();
										Bluetooth_Write_String("Backward");

                      break;
                  case 'L':   
									Motor_LEFT();
										Bluetooth_Write_String("LEFT");
                      break;
                  case 'R':
                      /*Medium Speed*/
                     Motor_Right();
											Bluetooth_Write_String("Right");

                      break;
                  case 'S':
									Motor_Stop();
									Bluetooth_Write_String("Stop");
                      break;

                

                  default:
                      /*Do nothing*/
                      break;
              }
}
