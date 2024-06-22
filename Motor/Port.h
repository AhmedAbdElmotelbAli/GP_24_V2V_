/*
 ============================================================================
 File Name		: Port.h
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of Port Driver
 Notes			: 
 ============================================================================
 */
#ifndef _PORT_H_
#define _PORT_H_
#include "config.h"

/* ***************** This is a Temp Solution ***************** */

#define MOTOR_3_PORT       (GPIO_PORTA)
#define MOTOR_4_PORT       (GPIO_PORTC)

/***************Motor 3***************/
#define MOTOR_3_ENABLE     (GPIO_PIN_2)			  /*PF0 PWM */
#define MOTOR_3_IN1        (GPIO_PIN_3)
#define MOTOR_3_IN2        (GPIO_PIN_2)

/***************Motor 4***************/
#define MOTOR_4_ENABLE     (GPIO_PIN_3)			   /*PF2 PWM */
#define MOTOR_4_IN1        (GPIO_PIN_6)
#define MOTOR_4_IN2        (GPIO_PIN_7)


#endif
