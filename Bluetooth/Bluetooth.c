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
#include "UltraSonic.h"
#include "Bluetooth.h"
#include "Lcd.h"

void Bluetooth_Voidinit(void)
{
    UART_INIT(5);
}
uint08_t Bluetooth_U8Read(void)
{

       uint08_t data;
       UART_RX(&data,5);
       return  data;
}
void Bluetooth_VoidWrite(unsigned char data)
{
    UART_TX(data,5);
}
void Bluetooth_VoidWriteString(char *str)
{
  while(*str)
    {
        Bluetooth_VoidWrite(*(str++));
    }
}


void Bluetooth_VoidControl(char data)
{
  /*char c ;
	char static mesg[20];*/  /* string format of distance value */
	//uint32_t distance;  
	switch (data)
              {
                  case 'F':
										
										Motor_VoidGoForward();
										Bluetooth_VoidWriteString("forword\n");
                      break;
                  case 'B':
                    Motor_VoidBackward();
										Bluetooth_VoidWriteString("Backward\n");
										
                      break;
                  case 'L':   
	
										Motor_VoidLEFT();
										Bluetooth_VoidWriteString("LEFT\n");
					
                      break;
                  case 'R':
                      /*Medium Speed*/
							
                     Motor_VoidRight();
											Bluetooth_VoidWriteString("Right\n");

                      break;
										  case 'G':
		
									
									Motor_VoidLEFT();
										Bluetooth_VoidWriteString("Farword LEFT\n");
										
                      break;
                  case 'I':
                      /*Medium Speed*/
									
                     Motor_VoidRight();
											Bluetooth_VoidWriteString("Farword Right\n");
										
                      break;
										case 'H': 
					
								   	Motor_VoidLEFT_B();
										Bluetooth_VoidWriteString("Back LEFT\n");
										
                      break;
                  case 'J':
											
										
											Motor_VoidRight_B();
											Bluetooth_VoidWriteString("Back Right\n");
										
                      break;
										case '0': 
										LCD_VoidclearScreen();											
								   	Motor_VoidSetSpeed(MOTOR_SPEED_LOW);
										Bluetooth_VoidWriteString("MOTOR SPEED LOW\n");
									
                      break;
										 case '5':
										LCD_VoidclearScreen();
                      /*Medium Speed*/
									
                    Motor_VoidSetSpeed(MOTOR_SPEED_MID);
										Bluetooth_VoidWriteString("MOTOR SPEED MID\n");
										LCD_VoidDisplayString("MOTOR SPEED HIGH");
										LCD_VoidclearScreen();										
                      break;
                  case 'q':
                    Motor_VoidSetSpeed(MOTOR_SPEED_HIGH);
										Bluetooth_VoidWriteString("MOTOR SPEED HIGH\n");
										
                      break;
                  case 'S':
									LCD_VoidclearScreen();
									Motor_VoidStop();
									Bluetooth_VoidWriteString("Stop\n");
                      break;
									
                  default:
                      /*Do nothing*/
                      break;
              }

}
