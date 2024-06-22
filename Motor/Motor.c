/*
 ============================================================================
 File Name		: Motor.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of Motor Driver
 Notes			: 
 ============================================================================
 */

#include "Motor.h"
#include "Delay.h"
#include "LED.h"

uint16_t duty_cycle=50;
uint32_t duty_cycle1;
uint16_t freq =50;


void Motor_VoidInit(void)
{
	

    // Initialize PWM for Motor 3 (Assuming M1PWM, PWM66 for IN1 and PWM77 for IN2)
   PWM_VoidInit(M1PWM, PWM44, PWM_SYSCLK_DIV_64, Count_DOWN, freq, duty_cycle);
   PWM_VoidInit(M1PWM, PWM66, PWM_SYSCLK_DIV_64, Count_DOWN, freq, duty_cycle);

    // Initialize GPIO pins for Motor 3 (IN1 and IN2)
    GPIO_Init(MOTOR_3_PORT, MOTOR_3_IN1);
    GPIO_Init(MOTOR_3_PORT, MOTOR_3_IN2);
    GPIO_SetPinDirection(MOTOR_3_PORT, MOTOR_3_IN1, GPIO_DIRECTION_OUTPUT);
    GPIO_SetPinDirection(MOTOR_3_PORT, MOTOR_3_IN2, GPIO_DIRECTION_OUTPUT);

    // Initialize GPIO pins for Motor 4 (IN1 and IN2)
    GPIO_Init(MOTOR_4_PORT, MOTOR_4_IN1);
    GPIO_Init(MOTOR_4_PORT, MOTOR_4_IN2);
    GPIO_SetPinDirection(MOTOR_4_PORT, MOTOR_4_IN1, GPIO_DIRECTION_OUTPUT);
    GPIO_SetPinDirection(MOTOR_4_PORT, MOTOR_4_IN2, GPIO_DIRECTION_OUTPUT);

    // Initially set motor direction pins to low (stop)
    GPIO_SetPinState(MOTOR_3_PORT, MOTOR_3_IN1, GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_3_PORT, MOTOR_3_IN2, GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_4_PORT, MOTOR_4_IN1, GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_4_PORT, MOTOR_4_IN2, GPIO_STATE_LOW);

}

void Motor_VoidStop(void)
{
       GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_LOW);
       GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_LOW);

    /************Motor_4********/

      GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_LOW);
      GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_LOW);
			RED_LED_ON();
}

void Motor_VoidBackward(void)
{


    GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_LOW);

    /************Motor_4********/

    GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_HIGH);
	  RED_LED_OFF();



}
void Motor_VoidGoForward(void)
{
   
		    /************Motor_3********/

    GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_HIGH);

    /************Motor_4********/

    GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_LOW);
	  RED_LED_OFF();


}
void Motor_VoidRight(void)
{

	/************Motor_3********/
//    YELLOW_LED_ON_R();
    GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_HIGH);

    /************Motor_4********/

    GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_LOW);
    GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_HIGH);
	  RED_LED_OFF();
//	  YELLOW_LED_ON_R();

}
void Motor_VoidLEFT(void)
{
	/************Motor_3********/
 //   YELLOW_LED_ON_L();
    GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_3_PORT,MOTOR_3_IN2,GPIO_STATE_LOW);

    /************Motor_4********/

    GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_4_PORT,MOTOR_4_IN2,GPIO_STATE_LOW);
	  RED_LED_OFF();
	//  YELLOW_LED_OFF_L(); 
	
}
void Motor_VoidLEFT_B(void)
{
      Motor_VoidBackward();
	    delay_milli(200);
     	Motor_VoidLEFT();
		  delay_milli(200);
    	Motor_VoidStop();
}
void Motor_VoidRight_B(void)
{
	    Motor_VoidBackward();
	    delay_milli(200);
     	Motor_VoidRight();
    	delay_milli(200);
    	Motor_VoidStop();
   
}

void Motor_VoidSetSpeed(uint16_t speed)
{
	 
        
        duty_cycle1=100-speed;
	if(duty_cycle1==0){
	    	PWM1_3_CMPA_R = duty_cycle1;
			  PWM_VoidGenEnable(M1PWM,PWM66);
				PWM1_2_CMPA_R=duty_cycle1;
				PWM_VoidGenEnable(M1PWM,PWM77);
	}else{
	      duty_cycle1*=5000;
      	duty_cycle1/=100;
	      duty_cycle1-=1;
        PWM1_3_CMPA_R = duty_cycle1;
			  PWM_VoidGenEnable(M1PWM,PWM66);
				PWM1_2_CMPA_R=duty_cycle1;
				PWM_VoidGenEnable(M1PWM,PWM77);

	}
	
}

bool Motor_BoolCheckstop(void){
	bool Stop = true;
			if(GPIO_GetPinState(MOTOR_3_PORT,MOTOR_3_IN1)==GPIO_STATE_LOW&&GPIO_GetPinState(MOTOR_3_PORT,MOTOR_3_IN2)==GPIO_STATE_LOW&&GPIO_GetPinState(MOTOR_4_PORT,MOTOR_4_IN1)==GPIO_STATE_LOW&&GPIO_GetPinState(MOTOR_4_PORT,MOTOR_4_IN2)==GPIO_STATE_LOW){
				Stop=true;
				return Stop;
			}
			Stop=false;
			return Stop;		
}
