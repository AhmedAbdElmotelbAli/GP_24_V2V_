/*
 ============================================================================
 File Name		: check.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of check Driver
 Notes			: 
 ============================================================================
 */

#include "check.h"
	
	char validCommands[] = {'B', 'L', 'R', 'G', 'I', 'H', 'J'};


bool checksaveDirection(void){
  bool Save = true;

	if(RTE_Call_Ultrasonic_U32MeasureDistance()<=20&&RTE_Call_Ultrasonic_U32MeasureDistance()>15){
			Save=false;
			RTE_Call_LCD_VOIDCleanscreen();
			RTE_Call_LCD_VoidDisplayStringRowColumn(0,0,"waring speed ");
			RTE_Call_LCD_VoidDisplayStringRowColumn(1,0,"please low speed ");
		}else if(RTE_Call_Ultrasonic_U32MeasureDistance()<=15&&RTE_Call_Ultrasonic_U32MeasureDistance()>8){
			Save=false;
			RTE_Call_LCD_VOIDCleanscreen();
			RTE_Call_LCD_VoidDisplayStringRowColumn(0,0,"waring body ");
			RTE_Call_LCD_VoidDisplayStringRowColumn(1,0,"change direction");
	}else if(RTE_Call_Ultrasonic_U32MeasureDistance()<=8&&RTE_Call_Ultrasonic_U32MeasureDistance()>0){
			Save=false;
			RTE_Call_LCD_VOIDCleanscreen();
			RTE_Call_LCD_VoidDisplayStringRowColumn(0,0,"waring Accient ");
			RTE_Call_LCD_VoidDisplayStringRowColumn(1,0,"please stop Car");
			Motor_VoidStop();
}
	return Save;
}

bool changeDirection(char command) {
        bool validCommand = false;
        for (int i = 0; i < (int)(sizeof(validCommands) / sizeof(validCommands[0])); i++) {
            if (command == validCommands[i]) {
                validCommand = true;
                break;
            }
        }
				return validCommand;		
}
void delay_s(void){
	for(int i=0;i<16000000;i++);
}
void Delay_s(int x){
for(int i=0;i<x;i++){
	delay_s();
}
}

