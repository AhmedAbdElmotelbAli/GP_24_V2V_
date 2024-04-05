/*
 ============================================================================
 File Name		: RTE_main.h
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of RTE Driver
 Notes			: 
 ============================================================================
 */
 #ifndef _RTE_Call_H_
#define _RTE_Call_H_
#include "UltraSonic.h"
#include "Type.h"
#include "Lcd.h"
#include "Motor.h"
#include "Bluetooth.h"
#include "stdbool.h"

uint32_t RTE_Call_Ultrasonic_U32MeasureDistance(void);
void RTE_Call_System_voidInit(void);
void RTE_Call_Motor_VoidMotorGo(char Direction);
void RTE_Call_Motor_VoidMotorSpeed(char Speed);
void RTE_Call_Bluetooth_VoidWriteString(char *Data);
void 	RTE_Call_LCD_VoidDisplayStringRowColumn(uint08_t row,uint08_t col,const char *Str);
void RTE_Call_Bluetooth_VoidControl(char data);
uint08_t RTE_Call_Bluetooth_U8Read(void);
bool RTE_Call_motor_boolCheckstop(void);
void RTE_Call_LCD_VOIDCleanscreen(void);
#endif
