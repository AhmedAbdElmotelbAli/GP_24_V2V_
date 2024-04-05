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
#ifndef _Delay_H_
#define _Delay_H_
#include "tm4c123gh6pm.h"
#include "Type.h"
#include "UltraSonic.h"
#include "UART.h"
#include "BITMATH.h"
#include "GPIO.h"
/* Function Name: Delay_MicroSecond
 * Inputs:        time (int)
 * Returns:       void 
 * Pins :        init timer no pin
 * Description:   Create one microsecond second delay using Timer block 1 and sub timer A
 * */
void Timer1_voidDelayMicroSecond(int time);

#endif
