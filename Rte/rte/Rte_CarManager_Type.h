
 
#ifndef RTE_CarMANAGER_TYPE_H
#define RTE_CarMANAGER_TYPE_H

#include "Rte_Type.h"
#define SET_BIT(Reg,Bit)                 ( (Reg) |=  ( (1) << (Bit) )  )
#define CLR_BIT(Reg,Bit)                 ( (Reg) &= ~(unsigned int)( (1) << (Bit) )  )
#define GET_BIT(Reg,Bit)                 ( (Reg) >>   (Bit) & ( 1  )  )
#define Forward						0
#define Right							1
#define LEFT							2

#define SENSOR_POSITION_STEP_0				0
#define SENSOR_POSITION_STEP_1				64
#define SENSOR_POSITION_STEP_2				128
#define SENSOR_POSITION_STEP_3				192

#define message_clear				0
#define message_Display			1
#define message_choose_place		2

#define MULTI_STATE_BTN_INIT				0
#define MULTI_STATE_BTN_PLUS				1
#define MULTI_STATE_BTN_MINUS				2

#define MOTOR_STEP_Forward				0
#define MOTOR_STEP_Backward			1
#define MOTOR_STEP_Right			2
#define MOTOR_STEP_Left				3
#define MOTOR_STEP_Stop				4
#define MOTOR_Set_Speed				5

#define Same_lane_white 		0
#define Same_lane_black 		1
#define Change_lane_left 		2
#define Change_lane_right 	3
#endif