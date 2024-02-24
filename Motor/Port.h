/****************************************************************************/
/************************* Name: Ahmed Abdelmotelb Ali     ******************/
/*************************    Date: 25/2/2023             ******************/
/*************************      SWC: Motor port             ****************/
/*************************    Version: 2.0                 ******************/
/****************************************************************************/
#ifndef _PORT_H_
#define _PORT_H_
#include "config.h"

/* ***************** This is a Temp Solution ***************** */
#define MOTOR_1_PORT       (GPIO_PORTA)
#define MOTOR_2_PORT       (GPIO_PORTA)
/***************Motor 1***************/

#define MOTOR_1_ENABLE     (GPIO_PIN_0)           /*PF0 PWM */
#define MOTOR_1_IN1        (GPIO_PIN_2)
#define MOTOR_1_IN2        (GPIO_PIN_3)

/***************Motor 2***************/
#define MOTOR_2_ENABLE     (GPIO_PIN_1)           /*PF1 PWM */
#define MOTOR_2_IN1        (GPIO_PIN_6)
#define MOTOR_2_IN2        (GPIO_PIN_7)


#endif
