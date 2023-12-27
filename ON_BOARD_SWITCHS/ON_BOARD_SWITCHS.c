/*
 * ON_BOARD_SWITCHS.c
 *
 *  Created on: Dec 28, 2023
 *      Author: Ahmed Adel Hasssan
 */

#include "ON_BOARD_SWITCHS.h"
void ON_BOARD_SWITCHS_Init(void){
    GPIO_Init(GPIO_PORTF,GPIO_PIN_0);//init SW2
    GPIO_Init(GPIO_PORTF,GPIO_PIN_4);//init SW1
    GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN_0,GPIO_DIRECTION_INPUT_PUSH_PULL);//input pull up SW2
    GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN_4,GPIO_DIRECTION_INPUT_PUSH_PULL);//input pull up SW1
}
GPIO_State_t SW1_State(void){
    return GPIO_GetPinState(GPIO_PORTF,GPIO_PIN_4);
}
GPIO_State_t SW2_State(void){
    return GPIO_GetPinState(GPIO_PORTF,GPIO_PIN_0);
}

