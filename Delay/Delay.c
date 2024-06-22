/*
 ============================================================================
 File Name		: Timer0.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 1.0
 Date			: 1/1/2023
 Description	: This file contains the implementation of Timer0 Driver
 Notes			: 
 ============================================================================
 */
 #include "Delay.h"
#if 0
 void Timer1_voidDelayMicroSecond(int time)
{
    int i;
    SYSCTL_RCGCTIMER_R |= 2;     // enable clock to Timer Block 1 
    TIMER1_CTL_R = 0;            // disable Timer before initialization 
    TIMER1_CFG_R = 0x04;         // 16-bit option  
    TIMER1_TAMR_R = 0x02;        // periodic mode and down-counter 
    TIMER1_TAILR_R = 16 - 1;  // TimerA interval load value reg 
    TIMER1_ICR_R = 0x1;          // clear the TimerA timeout flag 
    TIMER1_CTL_R |= 0x01;        // enable Timer A after initialization 

    for(i = 0; i < time; i++)
    {
        while ((TIMER1_RIS_R & 0x1) == 0) ;      // wait for TimerA timeout flag 
        TIMER1_ICR_R = 0x1;      // clear the TimerA timeout flag 
    }
}

// Create one microsecond second delay using Timer block 2, 3 and sub timer A 
void Timer2_voidDelayMicroSecond(int time)
{
    int i;
    SYSCTL_RCGCTIMER_R |= 2;     // enable clock to Timer Block 2 
    TIMER2_CTL_R = 0;            // disable Timer before initialization 
    TIMER2_CFG_R = 0x04;         // 16-bit option  
    TIMER2_TAMR_R = 0x02;        // periodic mode and down-counter 
    TIMER2_TAILR_R = 16 - 1;  // TimerA interval load value reg 
    TIMER2_ICR_R = 0x1;          // clear the TimerA timeout flag 
    TIMER2_CTL_R |= 0x01;        // enable Timer A after initialization 

    for(i = 0; i < time; i++)
    {
        while ((TIMER2_RIS_R & 0x1) == 0) ;      // wait for TimerA timeout flag 
        TIMER2_ICR_R = 0x1;      // clear the TimerA timeout flag 
    }
}

/*void Timer3_voidDelayMicroSecond(int time)
{
    int i;
    SYSCTL_RCGCTIMER_R |= 3;     // enable clock to Timer Block 3 
    TIMER3_CTL_R = 0;            // disable Timer before initialization 
    TIMER3_CFG_R = 0x04;         // 16-bit option  
    TIMER3_TAMR_R = 0x02;        // periodic mode and down-counter 
    TIMER3_TAILR_R = 16 - 1;  // TimerA interval load value reg 
    TIMER3_ICR_R = 0x1;          // clear the TimerA timeout flag 
    TIMER3_CTL_R |= 0x01;        // enable Timer A after initialization 

    for(i = 0; i < time; i++)
    {
        while ((TIMER3_RIS_R & 0x1) == 0) ;      // wait for TimerA timeout flag 
        TIMER3_ICR_R = 0x1;      // clear the TimerA timeout flag 
    }
}*/

void Timer3_voidDelayMicroSecond(int time) {
    int i;
    SYSCTL_RCGCTIMER_R |= 0x08;   // Enable clock to Timer Block 3
    TIMER3_CTL_R = 0;             // Disable Timer before initialization
    TIMER3_CFG_R = 0x04;          // 16-bit option
    TIMER3_TAMR_R = 0x02;         // Periodic mode and down-counter
    TIMER3_TAILR_R = 16 - 1;      // TimerA interval load value reg for 1us delay
    TIMER3_ICR_R = 0x1;           // Clear the TimerA timeout flag
    TIMER3_CTL_R |= 0x01;         // Enable Timer A after initialization

    for (i = 0; i < time; i++) {
        while ((TIMER3_RIS_R & 0x1) == 0); // Wait for TimerA timeout flag
        TIMER3_ICR_R = 0x1;               // Clear the TimerA timeout flag
    }
}


void Timer4_voidDelayMilliSecond(int time) {
    int i;
    SYSCTL_RCGCTIMER_R |= 0x10;   // Enable clock to Timer Block 4
    TIMER4_CTL_R = 0;             // Disable Timer before initialization
    TIMER4_CFG_R = 0x04;          // 16-bit option
    TIMER4_TAMR_R = 0x02;         // Periodic mode and down-counter
    TIMER4_TAILR_R = 16000 - 1;   // TimerA interval load value reg for 1ms delay (assuming a 16 MHz clock)
    TIMER4_ICR_R = 0x1;           // Clear the TimerA timeout flag
    TIMER4_CTL_R |= 0x01;         // Enable Timer A after initialization

    for (i = 0; i < time; i++) {
        while ((TIMER4_RIS_R & 0x1) == 0); // Wait for TimerA timeout flag
        TIMER4_ICR_R = 0x1;               // Clear the TimerA timeout flag
    }
}
#endif
void delay_micro (int delay_micro)
{
    int i = 0;
    for (   ; i < delay_micro*16;  i++)
    {
        __asm("NOP");
    }
}
void delay_milli (int delay_milli)
{
    int i = 0;
    for (   ; i < delay_milli * 1000 * 16;  i++)
    {
        __asm("NOP");
    }
}

