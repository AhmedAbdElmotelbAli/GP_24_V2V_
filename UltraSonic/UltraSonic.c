#include "tm4c123gh6pm.h"
#include "UART.h"
#include <stdio.h>

/*functions prototypes*/
void measure_distance(void);
uint32_t measure_pulse_duration(void)
void Timer0ACapture_init(void);
void Delay_MicroSecond(int time);
void Delay(unsigned long counter);

/* global variables to store and display distance in cm */
uint32_t time; /*stores pulse on time */
uint32_t distance; /* stores measured distance value */
int i;  /*iterartor*/

/* main code to take distance measurement and send data to UART terminal */
void measure_distance(void)
{
    Timer0ACapture_init();  /*initialize Timer0A in edge edge time */
    UART_INIT(5); /* initialize UART5 module to transmit data to computer */
    time = Measure_pulse_duration(); /* take pulse duration measurement */ 
    distance = (time * 10625)/10000000; /* convert pulse duration into distance */
    for(i = 0; i< 4; i++)
        UART_TX((distance>>(8*i) & 0XFF), 5); 
}


/* This function captures consecutive rising and falling edges of a periodic signal */
/* from Timer Block 0 Timer A and returns the time difference (the period of the signal). */
uint32_t measure_pulse_duration(void)
{
    int lastEdge, thisEdge;
	
	  /* Given 10us trigger pulse */
	  GPIOA->DATA &= ~(1<<4); /* make trigger  pin high */
	  Delay_MicroSecond(10); /*10 seconds delay */
	  GPIOA->DATA |= (1<<4); /* make trigger  pin high */
	  Delay_MicroSecond(10); /*10 seconds delay */
	  GPIOA->DATA &= ~(1<<4); /* make trigger  pin low */

 	while(1)
	{
    TIMER0->ICR = 4;            /* clear timer0A capture flag */
    while((TIMER0->RIS & 4) == 0) ;    /* wait till captured */
	  if(GPIOB->DATA & (1<<6)) /*check if rising edge occurs */
		{
    lastEdge = TIMER0->TAR;     /* save the timestamp */
		/* detect falling edge */
    TIMER0->ICR = 4;            /* clear timer0A capture flag */
    while((TIMER0->RIS & 4) == 0) ;    /* wait till captured */
    thisEdge = TIMER0->TAR;     /* save the timestamp */
		return (thisEdge - lastEdge); /* return the time difference */
		}
	}
}

/* Timer0A initialization function */
/* Initialize Timer0A in input-edge time mode with up-count mode */
void Timer0ACapture_init(void)
{
    SYSCTL->RCGCTIMER |= 1;     /* enable clock to Timer Block 0 */
    SYSCTL->RCGCGPIO |= 2;      /* enable clock to PORTB */
    
    GPIOB->DIR &= ~0x40;        /* make PB6 an input pin */
    GPIOB->DEN |= 0x40;         /* make PB6 as digital pin */
    GPIOB->AFSEL |= 0x40;       /* use PB6 alternate function */
    GPIOB->PCTL &= ~0x0F000000;  /* configure PB6 for T0CCP0 */
    GPIOB->PCTL |= 0x07000000;
    
	  /* PB2 as a digital output signal to provide trigger signal */
	  SYSCTL->RCGCGPIO |= 1;      /* enable clock to PORTA */
	  GPIOA->DIR |=(1<<4);         /* set PB2 as a digial output pin */
	  GPIOA->DEN |=(1<<4);         /* make PB2 as digital pin */

    TIMER0->CTL &= ~1;          /* disable timer0A during setup */
    TIMER0->CFG = 4;            /* 16-bit timer mode */
    TIMER0->TAMR = 0x17;        /* up-count, edge-time, capture mode */
    TIMER0->CTL |=0x0C;        /* capture the rising edge */
    TIMER0->CTL |= (1<<0);           /* enable timer0A */
}



/* Create one microsecond second delay using Timer block 1 and sub timer A */

void Delay_MicroSecond(int time)
{
    int i;
    SYSCTL->RCGCTIMER |= 2;     /* enable clock to Timer Block 1 */
    TIMER1->CTL = 0;            /* disable Timer before initialization */
    TIMER1->CFG = 0x04;         /* 16-bit option */ 
    TIMER1->TAMR = 0x02;        /* periodic mode and down-counter */
    TIMER1->TAILR = 16 - 1;  /* TimerA interval load value reg */
    TIMER1->ICR = 0x1;          /* clear the TimerA timeout flag */
    TIMER1->CTL |= 0x01;        /* enable Timer A after initialization */

    for(i = 0; i < time; i++)
    {
        while ((TIMER1->RIS & 0x1) == 0) ;      /* wait for TimerA timeout flag */
        TIMER1->ICR = 0x1;      /* clear the TimerA timeout flag */
    }
}

void Delay(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter*1000; i++);
}
/* This function is called by the startup assembly code to perform system specific initialization tasks. */
void SystemInit(void)
{
    __disable_irq();    /* disable all IRQs */
    
    /* Grant coprocessor access */
    /* This is required since TM4C123G has a floating point coprocessor */
    SCB->CPACR |= 0x00F00000;
}
