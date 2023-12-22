/*
 * main.c
 *
 *  Created on: Dec 22, 2023
 *      Author: Ahmed Adel Hasssan
 */
#include "GPIO.h"
int main(void)
{
    uint08_t sw_flag = 0;



    /* Initialize the SW1 and Blue LED as GPIO Pins */
    GPIO_Init(GPIO_PORTF,GPIO_PIN_0);//init SW2
    GPIO_Init(GPIO_PORTF,GPIO_PIN_4);//init SW1
    GPIO_Init(GPIO_PORTF,GPIO_PIN_1);//init Red led
    GPIO_Init(GPIO_PORTF,GPIO_PIN_2);//init blue led
    GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN_0,GPIO_DIRECTION_INPUT_PUSH_PULL);//input pull up SW1
    GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN_4,GPIO_DIRECTION_INPUT_PUSH_PULL);//input pull up SW2
    GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN_1,GPIO_DIRECTION_OUTPUT);//red led
    GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN_2,GPIO_DIRECTION_OUTPUT);//blue led
    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_LOW);    /* Clear  Data register to turn off the led */
    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_LOW);    /* Clear  Data register to turn off the led */

    while(1)
    {

        /* Check the switch state */
        if(GPIO_GetPinState(GPIO_PORTF, GPIO_PIN_0))
        {
            Delay_MS(10); /* Delay for the debounce */
            if(GPIO_GetPinState(GPIO_PORTF, GPIO_PIN_0))
            {
                if(sw_flag == 0)
                {
                    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_HIGH);    /* Clear  Data register to turn off the Redled */
                    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_LOW);    /* Clear  Data register to turn off the led */
                    sw_flag = 1;
                }
            }
        }
        else
        {
            sw_flag = 0;
        }


        if(GPIO_GetPinState(GPIO_PORTF, GPIO_PIN_0) && GPIO_GetPinState(GPIO_PORTF, GPIO_PIN_4))
        {
            Delay_MS(10); /* Delay for the debounce */
            if(GPIO_GetPinState(GPIO_PORTF, GPIO_PIN_0) && GPIO_GetPinState(GPIO_PORTF, GPIO_PIN_4))
            {
                if(sw_flag == 0)
                {
                    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_HIGH);    /* Clear  Data register to turn off the Redled */
                    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_HIGH);    /* Clear  Data register to turn off the Blueled */
                    // th leds will be pink
                    sw_flag = 1;
                }
            }
        }
        else
        {
            sw_flag = 0;
        }
        /* Check the switch state */
        if(GPIO_GetPinState(GPIO_PORTF, GPIO_PIN_4))
        {
            Delay_MS(10); /* Delay for the debounce */
            if(GPIO_GetPinState(GPIO_PORTF, GPIO_PIN_4))
            {
                if(sw_flag == 0)
                {
                    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_HIGH);    /* Clear  Data register to turn off the Blueled */
                    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_LOW);    /* Clear  Data register to turn off the led */
                    sw_flag = 1;
                }
            }
        }
        else
        {
            sw_flag = 0;
        }
        /* Check the switch state */
    }
}


