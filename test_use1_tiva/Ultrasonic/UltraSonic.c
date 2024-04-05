/*
 ============================================================================
 File Name		: Ultrasonic.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of Ultrasonic Driver
 Notes			: 
 ============================================================================
 */
#include "UltraSonic.h"


void UltraSonic_voidInit(void)
{
	Timer0A_voidinit();  /*initialize Timer0A in edge edge time */
}
/* This function captures consecutive rising and falling edges of a periodic signal */
/* from Timer Block 0 Timer A and returns the time difference (the period of the signal). */
uint32_t Ultrasonic_U32Measure_Time(void)
{
    int lastEdge, thisEdge;
	
	  /* Given 10us trigger pulse */
		CLR_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_4);
	 // GPIO_PORTA_DATA_R&= ~(1<<4); /* make trigger  pin high */
	  Timer1_voidDelayMicroSecond(10); /*10 seconds delay */
	  SET_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_4); /* make trigger  pin high */
	  Timer1_voidDelayMicroSecond(10); /*10 seconds delay */
		CLR_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_4); /* make trigger  pin low */

 	while(1)
	{
    TIMER0_ICR_R = 4;            /* clear timer0A capture flag */
    while((TIMER0_RIS_R & 4) == 0) ;    /* wait till captured */
	  if(GPIO_GetPinState(GPIO_PORTB,GPIO_PIN_6)) /*check if rising edge occurs */
		{
    lastEdge = (int)TIMER0_TAR_R;     /* save the timestamp */
		/* detect falling edge */
    TIMER0_ICR_R = 4;            /* clear timer0A capture flag */
    while((TIMER0_RIS_R & 4) == 0) ;    /* wait till captured */
    thisEdge = (int)TIMER0_TAR_R;     /* save the timestamp */
		return (uint32_t)(thisEdge - lastEdge); /* return the time difference */
		}
	}
}
void UART5_voidinit(void)
{
	UART_INIT(UART_5);
}
void UART5_VoidTransmitter(unsigned char data)  
{
    UART_TX(data,UART_5);                
}
void Uart_Voidprintstring(char *str)
{
			UartPrint(str,UART_5);
}
void Delay_VoidDelaycount(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter*1000; i++);
}
uint32_t Ultrasonic_U32MeasureDistance(void)
{
	uint32_t time; /*stores pulse on time */
	uint32_t distance; /* stores measured distance value */
	time = Ultrasonic_U32Measure_Time(); /* take pulse duration measurement */ 
		distance = (time * 10625)/10000000; /* convert pulse duration into distance */
	return distance;
}
