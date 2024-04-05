/*
 ============================================================================
 File Name		: Ultrasonic.h
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of Ultrasonic Driver
 Notes			: 
 ============================================================================
 */#ifndef UltraSonic_H_
#define UltraSonic_H_
/*Function prototype for Timer0A and UART module initialization */
#include "Type.h"
#include "tm4c123gh6pm.h"
#include "Type.h"
#include "UART.h"
#include "Timer0_Ultrasonic.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "Delay.h"
#define Timer0A_CLK 0
#define PB6_TOCCP0 0x0F000000
#define timer_mode16bit  4
#define Capture_mode1		 0
#define Edge_Time_mode	 2
#define Capture_mode2		 1
#define countup_bit      4
#define Both_edge1       2
#define Both_edge2       3
void UltraSonic_Init(void);
/* Function Name: Measure_Time
 * Inputs:        Nothing
 * Returns:       uint32_t distance
 * Pins :         Pins used for ultrasonic sensor using timer0 as counter PA4 (Trigger) - PB6 (Echo)
 * Description:   It used to measure distance using HC SR04 Ultrasonic sensor module
 * */
uint32_t Ultrasonic_U32Measure_Time(void);


/* Function Name: UART5_init
 * Inputs:        void 
 * Returns:       no return tupe 
 * Pins :        init UART  PE4 AS RX PE5 AS TX
 * Description:   INIT UART TO USE BLUETOOTH
 * */
void UART5_voidinit(void);
/* Function Name: UART5_Transmitter
 * Inputs:         data (unsigned char)
 * Returns:       void 
 * Pins :         UART  PE4 AS RX PE5 AS TX
 * Description:   TRANSMITTER CHAR UART TO USE BLUETOOTH
 * */
void UART5_VoidTransmitter(unsigned char data);
/* Function Name: printstring
 * Inputs:         data (unsigned char)
 * Returns:       void 
 * Pins :         UART  PE4 AS RX PE5 AS TX
 * Description:   TRANSMITTER STRING UART TO USE BLUETOOTH
 * */
void Uart_Voidprintstring(char *str);
/* Function Name: Delay1
 * Inputs:         counter (unsigned long)
 * Returns:       void 
 * Pins :         NO PIN AS LOOP
 * Description:   MAKE DELAY
 * */
void Delay_VoidDelaycount(unsigned long counter);
/* Function Name: Ultrasonic_U32MeasureDistance
 * Inputs:         counter (unsigned long)
 * Returns:       uint32_t 
 * Pins :         NO PIN 
 * Description:   cal Distane for muser time for go and back
 * */
uint32_t Ultrasonic_U32MeasureDistance(void);
/* Function Name: UltraSonic_Init
 * Inputs:         void
 * Returns:       void 
 * Pins :         init timer pin 
 * Description:   init timer to cal distance
 * */
void UltraSonic_voidInit(void);


int sprintf(char*, const char*, ...);
#endif /* UltraSonic */
