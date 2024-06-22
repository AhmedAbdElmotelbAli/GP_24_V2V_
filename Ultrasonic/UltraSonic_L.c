/*
 ============================================================================
 File Name		: UltraSonic_L.c
 Author			: Mohamed Emad Mostafa
 Version		: 1.0
 Date			: 14/4/2024
 Description	: This file contains the implementation of Left Ultrasonic Driver
 Notes			: 
 ============================================================================
 */
#include "UltraSonic.h"

void UltraSonic_Init_L(void) 
{
	Timer3A_voidinit();  /*initialize Timer1A in edge edge time */
}
/* This function captures consecutive rising and falling edges of a periodic signal */
/* from Timer Block 1 Timer A and returns the time difference (the period of the signal). */
uint32_t Ultrasonic_U32Measure_Time_L(void)
{
    int lastEdge, thisEdge;
	
	  /* Given 10us trigger pulse */
		CLR_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_5);
	 // GPIO_PORTA_DATA_R&= ~(1<<4); /* make trigger  pin high */
	  delay_micro(10); /*10 seconds delay */
	  SET_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_5); /* make trigger  pin high */
	  delay_micro(10); /*10 seconds delay */
		CLR_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_5); /* make trigger  pin low */

 	while(1)
	{
    TIMER3_ICR_R = 4;            /* clear timer1A capture flag */
    while((TIMER3_RIS_R & 4) == 0) ;    /* wait till captured */
	  if(GPIO_GetPinState(GPIO_PORTB,GPIO_PIN_2)) /*check if rising edge occurs */
		{
    lastEdge = (int)TIMER3_TAR_R;     /* save the timestamp */
		/* detect falling edge */
    TIMER3_ICR_R = 4;            /* clear timer1A capture flag */
    while((TIMER3_RIS_R & 4) == 0) ;    /* wait till captured */
    thisEdge = (int)TIMER3_TAR_R;     /* save the timestamp */
		return (uint32_t)(thisEdge - lastEdge); /* return the time difference */
		}
	}
}

uint32_t Ultrasonic_U32MeasureDistance_L(void)
{
	uint32_t time; /*stores pulse on time */
	uint32_t distance; /* stores measured distance value */
	time = Ultrasonic_U32Measure_Time_L(); /* take pulse duration measurement */ 
	distance = (time * 10625)/10000000; /* convert pulse duration into distance */
	return distance;
}
