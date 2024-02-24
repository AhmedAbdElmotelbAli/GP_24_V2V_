/*
 * RGB_LEDS.c
 *
 *  Created on: Dec 28, 2023
 *      Author: Ahmed Adel Hasssan
 */
#include "config.h"
#include "Type.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "RGB_LEDS.h"
#include "tm4c123gh6pm.h"

void RGB_LEDS_Init(void){
    GPIO_Init(GPIO_PORTF,GPIO_PIN_1);//init Red led
    GPIO_Init(GPIO_PORTF,GPIO_PIN_2);//init blue led
    GPIO_Init(GPIO_PORTF,GPIO_PIN_3);//init green led
    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_LOW);    /* Clear  Data register to turn off the red led */
    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_LOW);    /* Clear  Data register to turn off the blue led */
    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_3,GPIO_STATE_LOW);    /* Clear  Data register to turn off the green led */
}
void RGB_LEDS_State( LED_State red, LED_State green, LED_State blue){
    RGB_LEDS_Init();
    switch (red) {
        case LED_STATE_ON :
            GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_HIGH);    /* turn on the red led */
            break;
        default:
            GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_LOW);    /*turn off the red led */
            break;
    }
    switch (green) {
        case LED_STATE_ON :
            GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_3,GPIO_STATE_HIGH);    /* turn on the green led */
            break;
        default:
            GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_3,GPIO_STATE_LOW);    /*turn off the green led */
            break;
    }
    switch (blue) {
        case LED_STATE_ON :
            GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_HIGH);    /* turn on the blue led */
            break;
        default:
            GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_LOW);    /*turn off the blue led */
            break;
    }

}



