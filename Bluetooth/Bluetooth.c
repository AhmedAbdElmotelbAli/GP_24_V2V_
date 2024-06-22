/*
 ============================================================================
 File Name		: Bluetooth.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of Bluetooth Driver
 Notes			: 
 ============================================================================
 */

#include "Bluetooth.h"
#include "Motor.h"
#include "LED.h"
void Bluetooth_Voidinit(void)
{
    UART_INIT(UART_4);

	

}
uint8_t Bluetooth_U8Read(void)
{

       uint8_t data;
       UART_RX(&data,UART_4);
       return  data;
}
void Bluetooth_VoidWrite(unsigned char data)
{
    UART_TX(data,UART_4);
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
  //char c ;
	//char static mesg[20];  //string format of distance value 
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
                      //Medium Speed
							
                     Motor_VoidRight();
											Bluetooth_VoidWriteString("Right\n");

                      break;
										  case 'G':
								   	Motor_VoidLEFT();
										Bluetooth_VoidWriteString("Farword LEFT\n");
										
                      break;
                  case 'I':
                      //Medium Speed/
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
									case 'V':
											Horn_ON();
                      break;
									case 'v':
										Horn_OFF();
                      break;
									case 'U':
											RED_LED_ON();
                      break;
									case 'u':
										RED_LED_OFF();
                      break;
                  case 'S':
									Motor_VoidStop();
									Bluetooth_VoidWriteString("Stop\n");
                      break;
								
									
              }

}

