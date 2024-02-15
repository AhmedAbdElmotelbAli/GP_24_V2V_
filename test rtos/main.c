/*
 * main.c
 *
 *  Created on: Feb 14, 2024
 *      Author: Ahmed Adel Hasssan
 */
#include "RTOS\FreeRTOSConfig.h"
#include "RTOS\FreeRTOS.h"
#include "GPIO.h"
#include "RTOS\task.h"
void Delay_MS(unsigned long long n)
{
    volatile unsigned long long count = 0;
    while(count++ < (364 * n) );
}
TaskHandle_t Task_Handle1 = NULL_PTR;
TaskHandle_t Task_Handle2 = NULL_PTR;
void task1();
void task2();
int main() {
    GPIO_Init(GPIO_PORTF,GPIO_PIN_1);//init Red led
    GPIO_Init(GPIO_PORTF,GPIO_PIN_2);//init blue led
    GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN_1,GPIO_DIRECTION_OUTPUT);//red led
    GPIO_SetPinDirection(GPIO_PORTF,GPIO_PIN_2,GPIO_DIRECTION_OUTPUT);//blue led
    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_LOW);    /* Clear  Data register to turn off the led */
    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_LOW);    /* Clear  Data register to turn off the led */

    GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_HIGH);
    Delay_MS(1000);
    xTaskCreate(task1, "TASK1", 100, NULL, 1, &Task_Handle1);
    xTaskCreate(task2, "TASK2", 100, NULL, 2, &Task_Handle2);



    vTaskStartScheduler();
    while(1){
    }
}

void task1(void* args){

    while(1){
        GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_HIGH);
        vTaskDelay(1000);
        GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_LOW);
        vTaskDelay(1000);
    }
}
void task2(void* args){

    while(1){

        GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_HIGH);
        vTaskDelay(1000);
        GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_2,GPIO_STATE_LOW);
        vTaskDelay(1000);
    }

}


