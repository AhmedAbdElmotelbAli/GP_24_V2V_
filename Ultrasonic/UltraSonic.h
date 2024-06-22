/*
 ============================================================================
 File Name		: Ultrasonic.h
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of Ultrasonic Driver
 Notes			: 
 ============================================================================
 */
#ifndef UltraSonic_H_
#define UltraSonic_H_
/*Function prototype for Timer0A and UART module initialization */
#include <stdint.h>
#include "tm4c123gh6pm.h"
#include "Timer0_Ultrasonic.h"
#include "BITMATH.h"
#include "GPIO.h"
#include "Delay.h"
#define Timer0A_CLK 0
#define Timer1A_CLK 1
#define Timer2A_CLK 2
#define Timer3A_CLK 3
#define Timer4A_CLK 4
#define Timer5A_CLK 5
#define PB6_TOCCP0 0x0F000000 
#define PB4_T1CCP0 0x000F0000
#define PB0_T2CCP0 0x0000000F
#define PD2_T5CCP0 0x00000F00

#define PF4_T2CCP0 0x000F0000 
#define PB2_T3CCP0 0x00000F00

#define TIMER_MODE_16BIT     0x04
#define BOTH_EDGES          (0x4 | 0x8)

#define timer_mode16bit  4
#define Capture_mode1		 0
#define Edge_Time_mode	 2
#define Capture_mode2		 1
#define countup_bit      4
#define Both_edge1       2
#define Both_edge2       3
//0124
/* Function Name: UltraSonic_Init
 * Inputs:        void
 * Returns:       void 
 * Pins :         init timer pin 
 * Description:   init timer to call distance
 * */
void UltraSonic_Init_R(void);
void UltraSonic_Init_L(void);
void UltraSonic_Init_F(void);

/* Function Name: Measure_Time
 * Inputs:        Nothing
 * Returns:       uint32_t time difference
 * Pins :         Pins used for ultrasonic sensor using timer0 as counter PA4 (Trigger) - PB6 (Echo)
 * Description:   It's used to measure time till signal returns using HC SR04 Ultrasonic sensor module
 * */
uint32_t Ultrasonic_U32Measure_Time_R(void);

/* Function Name: Measure_Time
 * Inputs:        Nothing
 * Returns:       uint32_t time difference
 * Pins :         Pins used for ultrasonic sensor using timer1 as counter PF3 (Trigger) - PF2 (Echo)
 * Description:   It's used to measure time till signal returns using HC SR04 Ultrasonic sensor module
 * */
uint32_t Ultrasonic_U32Measure_Time_L(void);

/* Function Name: Measure_Time
 * Inputs:        Nothing
 * Returns:       uint32_t time difference
 * Pins :         Pins used for ultrasonic sensor using timer2 as counter PA5 (Trigger) - PF4 (Echo)
 * Description:   It's used to measure time till signal returns using HC SR04 Ultrasonic sensor module
 * */
 
uint32_t Ultrasonic_U32Measure_Time_F(void);

/* Function Name: Measure_Distance
 * Inputs:        Nothing
 * Returns:       uint32_t distance
 * Pins :         Pins used for ultrasonic sensor using timer0 as counter PA4 (Trigger) - PB6 (Echo)
 * Description:   It's used to measure distance using HC SR04 Ultrasonic sensor module
 * */

uint32_t Ultrasonic_U32MeasureDistance_R(void);

/* Function Name: Measure_Distance
 * Inputs:        Nothing
 * Returns:       uint32_t distance
 * Pins :         Pins used for ultrasonic sensor using timer1 as counter PF3 (Trigger) - PF2 (Echo)
 * Description:   It's used to measure distance using HC SR04 Ultrasonic sensor module
 * */

uint32_t Ultrasonic_U32MeasureDistance_L(void);

/* Function Name: Measure_Distance
 * Inputs:        Nothing
 * Returns:       uint32_t distance
 * Pins :         Pins used for ultrasonic sensor using timer1 as counter PA5 (Trigger) - PF4 (Echo)
 * Description:   It's used to measure distance using HC SR04 Ultrasonic sensor module
 * */
 
uint32_t Ultrasonic_U32MeasureDistance_F(void);

#endif /* UltraSonic */
