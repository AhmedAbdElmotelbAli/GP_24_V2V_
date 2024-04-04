/*
 * RGB_LEDS.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Ahmed Adel Hasssan
 */

#ifndef RGB_LEDS_RGB_LEDS_H_
#define RGB_LEDS_RGB_LEDS_H_

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
