/****************************************************************************/
/************************* Name: Ahmed Abdelmotelb Ali     ******************/
/*************************    Date: 25/2/2024             ******************/
/*************************      SWC: Motor          	   ******************/
/*************************    Version: 2.0                 ******************/
/****************************************************************************/

#include "config.h"
#include "Motor.h"
#include "GPIO.h"
#include "Port.h"
#include "Type.h"
#include "PWM.h"
#include "Bluetooth.h"
#include "Lcd.h"


uint16_t duty_cycle=75;
uint16_t freq =50;


void Motor_VoidInit(void)
{
    /*****PWM_MOTOR_1****PORTF***PIN0*****/
    PWM_VoidInit(M1PWM, PWM4, PWM_SYSCLK_DIV_64, Count_DOWN, freq, duty_cycle);
    /*****PWM_MOTOR_2****PORTF***PIN1*****/
    PWM_VoidInit(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq, duty_cycle);
    /********MOTOR_1*******/
     GPIO_Init(MOTOR_1_PORT,MOTOR_1_IN1);
     GPIO_Init(MOTOR_1_PORT,MOTOR_1_IN2);
     GPIO_SetPinDirection(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_DIRECTION_OUTPUT);
     GPIO_SetPinDirection(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_DIRECTION_OUTPUT);
     GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
     GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);
    /************Motor_2********/
    GPIO_Init(MOTOR_2_PORT,MOTOR_2_IN1);
    GPIO_Init(MOTOR_2_PORT,MOTOR_2_IN2);
    GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_DIRECTION_OUTPUT);
    GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_DIRECTION_OUTPUT);


    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);

}


void Motor_ViodStart(void)
{

     /*Enable Motor_1*/
     PWM_VoidGenEnable(M1PWM,PWM4);
     /*Enable Motor_2*/
     PWM_VoidGenEnable(M1PWM,PWM5);

}

void Motor_VoidStop(void)
{
	
    /************Motor_1********/

    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

    /************Motor_2********/

    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);

}

void Motor_VoidGoForward(void)
{

    /************Motor_1********/

    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

    /************Motor_2********/

    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);


}
void Motor_VoidBackward(void)
{
    /************Motor_1********/

    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_HIGH);

    /************Motor_2********/

    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_HIGH);


}
void Motor_VoidRight(void)
{
    /************Motor_1********/
      GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
      GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

      /************Motor_2********/

      GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_HIGH);
      GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);

}
void Motor_VoidLEFT(void)
{
	    /************Motor_1********/

        GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_HIGH);
        GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

        /************Motor_2********/

        GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
        GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);
}
void Motor_VoidLEFT_B(void)
{
    /************Motor_1********/
      GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
      GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

      /************Motor_2********/

      GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_HIGH);
      GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);

}
void Motor_VoidRight_B(void)
{
	    /************Motor_1********/

        GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_HIGH);
        GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

        /************Motor_2********/

        GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
        GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);
}

void Motor_VoidSetSpeed(Motor_Speed_t speed)
{

    if (speed == MOTOR_SPEED_LOW)
    {
        PWM_VoidInit(M1PWM, PWM4, PWM_SYSCLK_DIV_64, Count_DOWN, freq,25);
        PWM_VoidInit(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq,25);
        PWM_VoidInit(M1PWM, PWM6, PWM_SYSCLK_DIV_64, Count_DOWN, freq,25);
        PWM_VoidInit(M1PWM, PWM7, PWM_SYSCLK_DIV_64, Count_DOWN, freq,25);
        

    }
    else if (speed == MOTOR_SPEED_MID)
    {
        PWM_VoidInit(M1PWM, PWM4, PWM_SYSCLK_DIV_64, Count_DOWN, freq,50);
        PWM_VoidInit(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq,50);
        PWM_VoidInit(M1PWM, PWM6, PWM_SYSCLK_DIV_64, Count_DOWN, freq,50);
        PWM_VoidInit(M1PWM, PWM7, PWM_SYSCLK_DIV_64, Count_DOWN, freq,50);
        
    }
    else if (speed == MOTOR_SPEED_HIGH)
    {
        PWM_VoidInit(M1PWM, PWM4, PWM_SYSCLK_DIV_64, Count_DOWN, freq,75);
        PWM_VoidInit(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq,75);
        PWM_VoidInit(M1PWM, PWM6, PWM_SYSCLK_DIV_64, Count_DOWN, freq,75);
        PWM_VoidInit(M1PWM, PWM7, PWM_SYSCLK_DIV_64, Count_DOWN, freq,75);
      
    }
    else
    {/*Do no thing*/}

}
void Motor_VoidWait(char data){
	  uint32_t delay;
		Motor_VoidStop();
		LCD_VoidDisplayString("Hello MR.Ahmed");
		LCD_VoidDisplayStringRowColumn(1,0,"Abdelmotelb");
	  (void)(delay = 1);
		LCD_VoidclearScreen();
		LCD_VoidDisplayString("We have Problem");
		LCD_VoidDisplayStringRowColumn(1,0,"MR.Ahmed");
		(void)(delay = 1);
	  LCD_VoidclearScreen();
		LCD_VoidDisplayString("We find car or body in ditance 12");
	switch (data)
              {
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
              }
}
bool Motor_BoolCheckstop(void){
	bool Stop = true;
			if(GPIO_GetPinState(MOTOR_1_PORT,MOTOR_1_IN1)==GPIO_STATE_LOW&&GPIO_GetPinState(MOTOR_1_PORT,MOTOR_1_IN2)==GPIO_STATE_LOW&&GPIO_GetPinState(MOTOR_2_PORT,MOTOR_1_IN1)==GPIO_STATE_LOW&&GPIO_GetPinState(MOTOR_2_PORT,MOTOR_1_IN2)==GPIO_STATE_LOW){
				Stop=true;
				return Stop;
			}
			Stop=false;
			return Stop;		
}
