/*
 ============================================================================
 File Name		: Motor.h
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of Motor Driver
 Notes			: 
 ============================================================================
 */
#ifndef _MOTOR_H_
#define _MOTOR_H_
#include "stdbool.h"
#include "GPIO.h"
#include "Port.h"
#include <stdint.h>
#include "PWM.h"


#include "config.h"
extern uint16_t duty_cycle;
extern uint16_t freq ;
/*
typedef enum
{
  	
    MOTOR_SPEED_LOW=1,
	  MOTOR_SPEED_TWO,
	  MOTOR_SPEED_THREE,
	  MOTOR_SPEED_FOUR,
    MOTOR_SPEED_MID,
	  MOTOR_SPEED_SIX,
	  MOTOR_SPEED_SEVEN,
	  MOTOR_SPEED_EIGHT,
	  MOTOR_SPEED_NI,
	  MOTOR_SPEED_HIGH

}Motor_Speed_t;*/
/* Function Name: Motor_VoidInit
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :        init pin PF0,PF1 TO GENERATE PWM AND PA PIN PA2,PA3,PA6,PA7 IN1,IN2,IN3,IN4
 * Description:   GENERATE PWM AND INIT PORTA
 * */
void Motor_VoidInit(void);
/* Function Name: Motor_ViodStart
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :        Enable PF0,PF1
 * Description:   Enable PWM
 * */
void Motor_ViodStart(void);
/* Function Name: Motor_VoidStop
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :        PUT LOW IN IN1,IN2,IN3,IN4
 * Description:  STOP TWO MOTOR
 * */
void Motor_VoidStop(void);
/* Function Name: Motor_VoidGoForward
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :       PUT HIGH IN IN1,IN3 low other
 * Description:   MAKE RC GO FORWORD
 * */
void Motor_VoidGoForward(void);
/* Function Name: Motor_VoidSetSpeed
 * Inputs:        Motor_Speed_t
 * Returns:       void 
 * Pins :       DO DUTYCYCLE
 * Description:   PUT DUTY CYCLE ON PIN
 * */
void Motor_VoidSetSpeed(uint16_t speed);
/* Function Name: Motor_VoidGoForward
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :       PUT HIGH IN IN2,IN4 low other
 * Description:   MAKE RC GO Backward
 * */
void Motor_VoidBackward(void);
/* Function Name: Motor_VoidRight
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :       PUT HIGH IN IN1 low other
 * Description:   MAKE RC GO Right
 * */
void Motor_VoidRight(void);
/* Function Name: Motor_VoidLEFT
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :       PUT HIGH IN IN3 low other
 * Description:   MAKE RC GO LEFT
 * */
void Motor_VoidLEFT(void);
void Motor_VoidRight_B(void);
void Motor_VoidLEFT_B(void);
void Motor_VoidWait(char data);
bool Motor_BoolCheckstop(void);
#endif
