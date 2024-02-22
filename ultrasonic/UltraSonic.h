#ifndef UltraSonic_H_
#define UltraSonic_H_
/*Function prototype for Timer0A and UART module initialization */
#include "Type.h"
#define Timer0A_CLK 0
#define PB6_TOCCP0 0x0F000000
#define timer_mode16bit  4
#define Capture_mode1		 0
#define Edge_Time_mode	 2
#define Capture_mode2		 1
#define countup_bit      4
#define Both_edge1       2
#define Both_edge2       3
/* Function Name: Measure_distance
 * Inputs:        Nothing
 * Returns:       uint32_t distance
 * Pins :         Pins used for ultrasonic sensor using timer0 as counter PA4 (Trigger) - PB6 (Echo)
 * Description:   It used to measure distance using HC SR04 Ultrasonic sensor module
 * */
uint32_t Measure_distance(void);
/* Function Name: Timer0A_init
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :        init timer no pin
 * Description:   Timer0A initialization function  Initialize Timer0A in input-edge time mode with up-count mode 
 * */
void Timer0A_init(void);
/* Function Name: Delay_MicroSecond
 * Inputs:        time (int)
 * Returns:       void 
 * Pins :        init timer no pin
 * Description:   Create one microsecond second delay using Timer block 1 and sub timer A
 * */
void Delay_MicroSecond(int time);
/* Function Name: UART5_init
 * Inputs:        void 
 * Returns:       no return tupe 
 * Pins :        init UART  PE4 AS RX PE5 AS TX
 * Description:   INIT UART TO USE BLUETOOTH
 * */
void UART5_init(void);
/* Function Name: UART5_Transmitter
 * Inputs:         data (unsigned char)
 * Returns:       void 
 * Pins :         UART  PE4 AS RX PE5 AS TX
 * Description:   TRANSMITTER CHAR UART TO USE BLUETOOTH
 * */
void UART5_Transmitter(unsigned char data);
/* Function Name: printstring
 * Inputs:         data (unsigned char)
 * Returns:       void 
 * Pins :         UART  PE4 AS RX PE5 AS TX
 * Description:   TRANSMITTER STRING UART TO USE BLUETOOTH
 * */
void printstring(char *str);
/* Function Name: Delay1
 * Inputs:         counter (unsigned long)
 * Returns:       void 
 * Pins :         NO PIN AS LOOP
 * Description:   MAKE DELAY
 * */
void Delay1(unsigned long counter);

int sprintf(char*, const char*, ...);
#endif /* UltraSonic */