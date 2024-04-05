/*
 ============================================================================
 File Name		: Timer0.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 2.0
 Date			: 1/4/2023
 Description	: This file contains the implementation of Timer0 Driver
 Notes			: 
 ============================================================================
 */
#include "Timer0_Ultrasonic.h"
/* Timer0A initialization function */
/* Initialize Timer0A in input-edge time mode with up-count mode */
void Timer0A_voidinit(void)
{

      SET_BIT(SYSCTL_RCGCTIMER_R,Timer0A_CLK);     /* enable clock to Timer Block 0 */
      GPIO_Init(GPIO_PORTB,GPIO_PIN_6);
      GPIO_SetPinDirection(GPIO_PORTB,GPIO_PIN_6,GPIO_DIRECTION_INPUT_PUSH_PULL);  
			SET_BIT( GPIO_PORTB_AFSEL_R,GPIO_PIN_6);       /* use PB6 alternate function */
			GPIO_PORTB_PCTL_R &= ~PB6_TOCCP0;  /* configure PB6 for T0CCP0 */
      SET_BIT(GPIO_PORTB_PCTL_R, 24);
			SET_BIT(GPIO_PORTB_PCTL_R, 25);
			SET_BIT(GPIO_PORTB_PCTL_R, 26);
    
	  /* PB2 as a digital output signal to provide trigger signal */
			GPIO_Init(GPIO_PORTA,GPIO_PIN_4);
      GPIO_SetPinDirection(GPIO_PORTA,GPIO_PIN_4,GPIO_DIRECTION_OUTPUT); 

			CLR_BIT(TIMER0_CTL_R,Timer0A_CLK);          /* disable timer0A during setup */
			TIMER0_CFG_R = timer_mode16bit;            /* 16-bit timer mode */
    	SET_BIT(TIMER0_TAMR_R,countup_bit);      /* up-count*/
			SET_BIT(TIMER0_TAMR_R,Capture_mode1); /*capture mode */
			SET_BIT(TIMER0_TAMR_R,Capture_mode2);
	  	SET_BIT(TIMER0_TAMR_R,Edge_Time_mode);        /*edge-time*/
      SET_BIT(TIMER0_CTL_R,Both_edge1);        /* capture the rising edge pin 2,3 */
			SET_BIT(TIMER0_CTL_R,Both_edge2); 
			SET_BIT(TIMER0_CTL_R,Timer0A_CLK);           /* enable timer0A */
}

