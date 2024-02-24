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

uint16_t duty_cycle=25;
uint16_t freq =50;


void Motor_Init(void)
{
    /*****PWM_MOTOR_1****PORTF***PIN0*****/
    PWM_Init(M1PWM, PWM4, PWM_SYSCLK_DIV_64, Count_DOWN, freq, duty_cycle);
    /*****PWM_MOTOR_2****PORTF***PIN1*****/
    PWM_Init(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq, duty_cycle);
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


void Motor_Start(void)
{

     /*Enable Motor_1*/
     PWMGenEnable(M1PWM,PWM4);
     /*Enable Motor_2*/
     PWMGenEnable(M1PWM,PWM5);

}

void Motor_Stop(void)
{

  /*Disable Motor_1*/
  PWMGenDisable(M1PWM,PWM4);
  /*Disable Motor_2*/
  PWMGenDisable(M1PWM,PWM5);
  /*Disable Motor_3*/
}

void Motor_GoForward(void)
{

    /************Motor_1********/

    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

    /************Motor_2********/

    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);


}
void Motor_Backward(void)
{
    /************Motor_1********/

    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_HIGH);

    /************Motor_2********/

    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_HIGH);


}
void Motor_LEFT(void)
{
    /************Motor_1********/
      GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_LOW);
      GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

      /************Motor_2********/

      GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_HIGH);
      GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);

}
void Motor_Right(void)
{
	    /************Motor_1********/

        GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN1,GPIO_STATE_HIGH);
        GPIO_SetPinState(MOTOR_1_PORT,MOTOR_1_IN2,GPIO_STATE_LOW);

        /************Motor_2********/

        GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_LOW);
        GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);
}

void Motor_SetSpeed(Motor_Speed_t speed)
{

    if (speed == MOTOR_SPEED_LOW)
    {
        PWM_Init(M1PWM, PWM4, PWM_SYSCLK_DIV_64, Count_DOWN, freq,25);
        PWM_Init(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq,25);
        PWM_Init(M1PWM, PWM6, PWM_SYSCLK_DIV_64, Count_DOWN, freq,25);
        PWM_Init(M1PWM, PWM7, PWM_SYSCLK_DIV_64, Count_DOWN, freq,25);
        

    }
    else if (speed == MOTOR_SPEED_MID)
    {
        PWM_Init(M1PWM, PWM4, PWM_SYSCLK_DIV_64, Count_DOWN, freq,50);
        PWM_Init(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq,50);
        PWM_Init(M1PWM, PWM6, PWM_SYSCLK_DIV_64, Count_DOWN, freq,50);
        PWM_Init(M1PWM, PWM7, PWM_SYSCLK_DIV_64, Count_DOWN, freq,50);
        
    }
    else if (speed == MOTOR_SPEED_HIGH)
    {
        PWM_Init(M1PWM, PWM4, PWM_SYSCLK_DIV_64, Count_DOWN, freq,75);
        PWM_Init(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq,75);
        PWM_Init(M1PWM, PWM6, PWM_SYSCLK_DIV_64, Count_DOWN, freq,75);
        PWM_Init(M1PWM, PWM7, PWM_SYSCLK_DIV_64, Count_DOWN, freq,75);
      
    }
    else
    {/*Do no thing*/}

}
