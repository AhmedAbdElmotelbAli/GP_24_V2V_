/*
 ============================================================================
 File Name		: RGB_LEDS.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 1.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of PWM Driver
 Notes			: 
 ============================================================================
 */

#ifndef RGB_LEDS_RGB_LEDS_H_
#define RGB_LEDS_RGB_LEDS_H_
#include "config.h"
#include "Type.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "tm4c123gh6pm.h"

typedef enum
{
    /* List the gpio pins */
    LED_STATE_OFF,
    LED_STATE_ON

}LED_State;
/*
 * make sure that the configurations of pins PF1,PF2,PF3 (RED,BLUE,GREEN) set as output and turn off all of them
 */
void RGB_LEDS_Init(void);

/*
 * manage the state of three leds (LED_STATE_OFF, LED_STATE_ON)
 */
void RGB_LEDS_State(LED_State red, LED_State green, LED_State blue);




#endif /* RGB_LEDS_RGB_LEDS_H_ */
