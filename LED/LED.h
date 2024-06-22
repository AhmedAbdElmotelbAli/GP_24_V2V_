#ifndef LED_H_
#define LED_H_
#include "GPIO.h"

void LED_init(void);
void RED_LED_ON(void);
void RED_LED_OFF(void);
void WHITE_LED_ON(void);
void WHITE_LED_OFF(void);
void YELLOW_LED_ON_L(void);
void YELLOW_LED_ON_R(void);
void YELLOW_LED_OFF_R(void);
void YELLOW_LED_OFF_L(void);
void Horn_ON(void);
void Horn_OFF(void);
void Horn_Init(void);
#endif
