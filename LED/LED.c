#include "LED.h"

void LED_init(void){
//RED LED
	GPIO_Init(GPIO_PORTB, GPIO_PIN_3);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN_3, GPIO_DIRECTION_OUTPUT);
	//WHITE LED 
	GPIO_Init(GPIO_PORTF, GPIO_PIN_4);
    GPIO_SetPinDirection(GPIO_PORTF, GPIO_PIN_4, GPIO_DIRECTION_OUTPUT);
	//yellow Led
	/*	GPIO_Init(GPIO_PORTD, GPIO_PIN_2);
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN_2, GPIO_DIRECTION_OUTPUT);
	  GPIO_Init(GPIO_PORTD, GPIO_PIN_0);
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN_0, GPIO_DIRECTION_OUTPUT);*/
}
void Horn_Init(void){
	GPIO_Init(GPIO_PORTF, GPIO_PIN_1);
    GPIO_SetPinDirection(GPIO_PORTF, GPIO_PIN_1, GPIO_DIRECTION_OUTPUT);

}
void RED_LED_ON(void){
	GPIO_SetPinState(GPIO_PORTB,GPIO_PIN_3,GPIO_STATE_HIGH);
}
void RED_LED_OFF(void){
	GPIO_SetPinState(GPIO_PORTB,GPIO_PIN_3,GPIO_STATE_LOW);
}
void WHITE_LED_ON(void){
	GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_4,GPIO_STATE_HIGH);
}
void WHITE_LED_OFF(void){
	GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_4,	GPIO_STATE_LOW);
}
void YELLOW_LED_ON_L(void){
	GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_2,GPIO_STATE_HIGH);
}
void YELLOW_LED_OFF_L(void){
	GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_2,	GPIO_STATE_LOW);
}
void YELLOW_LED_ON_R(void){
	GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_0,GPIO_STATE_HIGH);
}
void YELLOW_LED_OFF_R(void){
	GPIO_SetPinState(GPIO_PORTD,GPIO_PIN_0,	GPIO_STATE_LOW);
}
void Horn_ON(void){
	GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_HIGH);

}
void Horn_OFF(void){
	GPIO_SetPinState(GPIO_PORTF,GPIO_PIN_1,GPIO_STATE_LOW);

}