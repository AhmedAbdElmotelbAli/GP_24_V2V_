#include "RTE_Main.h"
#include "stdbool.h"

void RTE_Call_System_voidInit(void){
		Lcd_VoidInit();
		UltraSonic_voidInit();
		Motor_VoidInit();
    Bluetooth_Voidinit();

}
void RTE_Call_Bluetooth_VoidWriteString(char * Data){
				Bluetooth_VoidWriteString(Data);
}

uint32_t RTE_Call_Ultrasonic_U32MeasureDistance(void){
	return Ultrasonic_U32MeasureDistance();
}

void RTE_Call_Motor_VoidMotorGo(char Direction){
	switch (Direction)
              {
                  case 'F':
										
										Motor_VoidGoForward();
										RTE_Call_Bluetooth_VoidWriteString("forword\n");
                      break;
                  case 'B':
                    Motor_VoidBackward();
										RTE_Call_Bluetooth_VoidWriteString("Backward\n");
										
                      break;
                  case 'L':   
	
										Motor_VoidLEFT();
										RTE_Call_Bluetooth_VoidWriteString("LEFT\n");
					
                      break;
                  case 'R':
                      /*Medium Speed*/
							
                     Motor_VoidRight();
											RTE_Call_Bluetooth_VoidWriteString("Right\n");

                      break;
										  case 'G':
		
									
									Motor_VoidLEFT();
										RTE_Call_Bluetooth_VoidWriteString("Farword LEFT\n");
										
                      break;
                  case 'I':
                      /*Medium Speed*/
									
                     Motor_VoidRight();
											RTE_Call_Bluetooth_VoidWriteString("Farword Right\n");
										
                      break;
										case 'H': 
					
								   	Motor_VoidLEFT_B();
										RTE_Call_Bluetooth_VoidWriteString("Back LEFT\n");
										
                      break;
                  case 'J':
											
										
											Motor_VoidRight_B();
											RTE_Call_Bluetooth_VoidWriteString("Back Right\n");
										
                      break;
										
                  case 'S':
									LCD_VoidclearScreen();
									Motor_VoidStop();
									RTE_Call_Bluetooth_VoidWriteString("Stop\n");
                      break;
									
                  default:
                      /*Do nothing*/
                      break;
              }
}
void RTE_Call_Motor_VoidMotorSpeed(char Speed){
	switch (Speed)
              {

					case '0': 
								LCD_VoidclearScreen();											
								Motor_VoidSetSpeed(MOTOR_SPEED_LOW);
								RTE_Call_Bluetooth_VoidWriteString("MOTOR SPEED LOW\n");
									  break;
					 case '5':
								LCD_VoidclearScreen();
                      /*Medium Speed*/
									
                 Motor_VoidSetSpeed(MOTOR_SPEED_MID);
								 									
                      break;
           case 'q':
                    Motor_VoidSetSpeed(MOTOR_SPEED_HIGH);
										
                      break;
					 default:
                      /*Do nothing*/
                      break;
              }
}
void RTE_Call_LCD_VOIDCleanscreen(void){
	LCD_VoidclearScreen();
}
void 	RTE_Call_LCD_VoidDisplayStringRowColumn(uint08_t row,uint08_t col,const char *Str){
	
		LCD_VoidDisplayStringRowColumn(row,col,Str);

}
void RTE_Call_Bluetooth_VoidControl(char data){
		Bluetooth_VoidControl(data);
}
uint08_t RTE_Call_Bluetooth_U8Read(void)
{
	return	Bluetooth_U8Read();
}
bool RTE_Call_motor_boolCheckstop(void){
			return Motor_BoolCheckstop();
}
