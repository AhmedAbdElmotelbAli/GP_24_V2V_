/*
 ============================================================================
 File Name		: Timer0.h
 Author			: Ahmed Abdelmotelb Ali
 UpdatedBy      : Mohamed Emad Mostafa
 Version		: 2.0
 Date			: 1/4/2023
 Description	: This file contains the implementation of Timer0 Driver
 Notes			: 
 ============================================================================
 */
#ifndef _Timer_Ultrasonic_H_
#define _Timer_Ultrasonic_H_
#include "tm4c123gh6pm.h"
#include "UltraSonic.h"

#include "BITMATH.h"
#include "GPIO.h"
/* Function Name: Timer0A_voidinit
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :        init timer no pin
 * Description:   Timer0A initialization function  Initialize Timer0A in input-edge time mode with up-count mode 
 * */
void Timer0A_voidinit(void);
void Timer2A_voidinit(void);


void Timer1A_voidinit(void);
void Timer3A_voidinit(void);

#endif
