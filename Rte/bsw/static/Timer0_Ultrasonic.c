/*
 ============================================================================
 File Name		: Timer0.c
 Author			: Ahmed Abdelmotelb Ali
 UpdatedBy      : Mohamed Emad Mostafa
 Version		: 2.0
 Date			: 1/4/2023
 Description	: This file contains the implementation of Timer0 Driver
 Notes			: 
 ============================================================================
 */
#include "Timer0_Ultrasonic.h"
// Timer0A initialization function 
// Initialize Timer0A in input-edge time mode with up-count mode 
void Timer0A_voidinit(void)
{

      SET_BIT(SYSCTL_RCGCTIMER_R,Timer0A_CLK);     // enable clock to Timer Block 0 
      GPIO_Init(GPIO_PORTB,GPIO_PIN_6);
      GPIO_SetPinDirection(GPIO_PORTB,GPIO_PIN_6,GPIO_DIRECTION_INPUT_PUSH_PULL);  
			SET_BIT( GPIO_PORTB_AFSEL_R,GPIO_PIN_6);       // use PB6 alternate function 
			GPIO_PORTB_PCTL_R &= (unsigned int)~PB6_TOCCP0;  // configure PB6 for T0CCP0 
      SET_BIT(GPIO_PORTB_PCTL_R, 24);
			SET_BIT(GPIO_PORTB_PCTL_R, 25);
			SET_BIT(GPIO_PORTB_PCTL_R, 26);
    
	  // PB2 as a digital output signal to provide trigger signal 
			GPIO_Init(GPIO_PORTA,GPIO_PIN_4);
      GPIO_SetPinDirection(GPIO_PORTA,GPIO_PIN_4,GPIO_DIRECTION_OUTPUT); 

			CLR_BIT(TIMER0_CTL_R,Timer0A_CLK);          // disable timer0A during setup 
			TIMER0_CFG_R = timer_mode16bit;            // 16-bit timer mode 
    	SET_BIT(TIMER0_TAMR_R,countup_bit);      // up-count
			SET_BIT(TIMER0_TAMR_R,Capture_mode1); //capture mode 
			SET_BIT(TIMER0_TAMR_R,Capture_mode2);
	  	SET_BIT(TIMER0_TAMR_R,Edge_Time_mode);        //edge-time
			TIMER0_CTL_R=0x0C;
     /* SET_BIT(TIMER0_CTL_R,Both_edge1); 
			SET_BIT(TIMER0_CTL_R,Both_edge2); */
	//		TIMER0_ICR_R = 0x1;
			// Enable synchronization for Timer 0A
			SET_BIT(TIMER0_CTL_R,Timer0A_CLK);           // enable timer0A 
}

void Timer3A_voidinit(void)
{

      SET_BIT(SYSCTL_RCGCTIMER_R,Timer3A_CLK);     // enable clock to Timer Block 1 
      GPIO_Init(GPIO_PORTB,GPIO_PIN_2);
      GPIO_SetPinDirection(GPIO_PORTB,GPIO_PIN_2,GPIO_DIRECTION_INPUT_PUSH_PULL);  
		  SET_BIT( GPIO_PORTB_AFSEL_R,GPIO_PIN_2);       //use PF2 alternate function 
		  GPIO_PORTB_PCTL_R &= (unsigned int)~PB2_T3CCP0;  // configure PF2 for T1CCP0 
      SET_BIT(GPIO_PORTB_PCTL_R, 8);
			SET_BIT(GPIO_PORTB_PCTL_R, 9);
			SET_BIT(GPIO_PORTB_PCTL_R, 10);
    
	  // PE3 as a digital output signal to provide trigger signal 
			GPIO_Init(GPIO_PORTA,GPIO_PIN_5);
      GPIO_SetPinDirection(GPIO_PORTA,GPIO_PIN_5,GPIO_DIRECTION_OUTPUT); 

			CLR_BIT(TIMER3_CTL_R,0);          // disable timer2A during setup 
			TIMER3_CFG_R = timer_mode16bit;         // 16-bit timer mode 
    	SET_BIT(TIMER3_TAMR_R,countup_bit);    // up-count
			SET_BIT(TIMER3_TAMR_R,Capture_mode1); //capture mode 
			SET_BIT(TIMER3_TAMR_R,Capture_mode2);
	  	SET_BIT(TIMER3_TAMR_R,Edge_Time_mode);        //edge-time
			TIMER3_CTL_R=0x0C;
     /* SET_BIT(TIMER3_CTL_R,Both_edge1);        // capture the rising edge pin 2,3 
			SET_BIT(TIMER3_CTL_R,Both_edge2); */
			// Enable synchronization for Timer 0A
	//		TIMER3_ICR_R = 0x1;
			SET_BIT(TIMER3_CTL_R,0);           // enable timer2A 
}

void Timer2A_voidinit(void)
{
//pF4 pA5
      SET_BIT(SYSCTL_RCGCTIMER_R,Timer2A_CLK);     // enable clock to Timer Block 2 
      GPIO_Init(GPIO_PORTB,GPIO_PIN_0);
      GPIO_SetPinDirection(GPIO_PORTB,GPIO_PIN_0,GPIO_DIRECTION_INPUT_PUSH_PULL);  
	  	SET_BIT(GPIO_PORTB_AFSEL_R,GPIO_PIN_0);       //use PF4 alternate function 
		  GPIO_PORTB_PCTL_R &= (unsigned int)~PB0_T2CCP0;  // configure PF4 for T2CCP0 
      SET_BIT(GPIO_PORTB_PCTL_R, 0);
			SET_BIT(GPIO_PORTB_PCTL_R, 1);
			SET_BIT(GPIO_PORTB_PCTL_R, 2);
    
	  // PA5 as a digital output signal to provide trigger signal 
			GPIO_Init(GPIO_PORTA,GPIO_PIN_6);
      GPIO_SetPinDirection(GPIO_PORTA,GPIO_PIN_6,GPIO_DIRECTION_OUTPUT); 

			CLR_BIT(TIMER2_CTL_R,0);          // disable timer2A during setup 
			TIMER2_CFG_R = timer_mode16bit;            // 16-bit timer mode 
    	SET_BIT(TIMER2_TAMR_R,countup_bit);      // up-count
			SET_BIT(TIMER2_TAMR_R,Capture_mode1); //capture mode 
			SET_BIT(TIMER2_TAMR_R,Capture_mode2);
	  	SET_BIT(TIMER2_TAMR_R,Edge_Time_mode);        //edge-time
			
			
			TIMER2_CTL_R=0x0C;
//			TIMER2_ICR_R = 0x1;
			
			// Enable synchronization for Timer 0A
     // SYSCTL_RCGCTIMER_R |= (1U << Timer2A_CLK);
			SET_BIT(TIMER2_CTL_R,0);           // enable timer2A 
}

