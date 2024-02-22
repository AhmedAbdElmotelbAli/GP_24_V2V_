/*  Name: Ahmed Abdelmotelb Ali
 * DATA:        22/2/2024
 * */
#include "tm4c123gh6pm.h"
#include "Type.h"
#include "UltraSonic.h"
#include "UART.h"
#include "BITMATH.h"
#include "GPIO.h"

/* This function captures consecutive rising and falling edges of a periodic signal */
/* from Timer Block 0 Timer A and returns the time difference (the period of the signal). */
uint32_t Measure_distance(void)
{
    int lastEdge, thisEdge;
	
	  /* Given 10us trigger pulse */
		CLR_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_4);
	 // GPIO_PORTA_DATA_R&= ~(1<<4); /* make trigger  pin high */
	  Delay_MicroSecond(10); /*10 seconds delay */
	  SET_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_4); /* make trigger  pin high */
	  Delay_MicroSecond(10); /*10 seconds delay */
		CLR_BIT(GPIO_PORTA_DATA_R,GPIO_PIN_4); /* make trigger  pin low */

 	while(1)
	{
    TIMER0_ICR_R = 4;            /* clear timer0A capture flag */
    while((TIMER0_RIS_R & 4) == 0) ;    /* wait till captured */
	  if(GPIO_GetPinState(GPIO_PORTB,GPIO_PIN_6)) /*check if rising edge occurs */
		{
    lastEdge = TIMER0_TAR_R;     /* save the timestamp */
		/* detect falling edge */
    TIMER0_ICR_R = 4;            /* clear timer0A capture flag */
    while((TIMER0_RIS_R & 4) == 0) ;    /* wait till captured */
    thisEdge = TIMER0_TAR_R;     /* save the timestamp */
		return (thisEdge - lastEdge); /* return the time difference */
		}
	}
}

/* Timer0A initialization function */
/* Initialize Timer0A in input-edge time mode with up-count mode */
void Timer0A_init(void)
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



/* Create one microsecond second delay using Timer block 1 and sub timer A */

void Delay_MicroSecond(int time)
{
    int i;
    SYSCTL_RCGCTIMER_R |= 2;     /* enable clock to Timer Block 1 */
    TIMER1_CTL_R = 0;            /* disable Timer before initialization */
    TIMER1_CFG_R = 0x04;         /* 16-bit option */ 
    TIMER1_TAMR_R = 0x02;        /* periodic mode and down-counter */
    TIMER1_TAILR_R = 16 - 1;  /* TimerA interval load value reg */
    TIMER1_ICR_R = 0x1;          /* clear the TimerA timeout flag */
    TIMER1_CTL_R |= 0x01;        /* enable Timer A after initialization */

    for(i = 0; i < time; i++)
    {
        while ((TIMER1_RIS_R & 0x1) == 0) ;      /* wait for TimerA timeout flag */
        TIMER1_ICR_R = 0x1;      /* clear the TimerA timeout flag */
    }
}
void UART5_init(void)
{
	UART_INIT(UART_5);
}
void UART5_Transmitter(unsigned char data)  
{
    UART_TX(data,UART_5);                
}
void printstring(char *str)
{
			UartPrint(str,UART_5);
}
void Delay1(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter*1000; i++);
}