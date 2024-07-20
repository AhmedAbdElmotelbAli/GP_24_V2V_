
 
#ifndef RTE_Lcd_H
#define RTE_Lcd_H

#include "Rte_Lcd_Type.h"

Std_ReturnType Rte_Call_LcdSensor_rpIOSetLcd_IOSetClear();
Std_ReturnType Rte_Call_LcdSensor_rpIOSetLcd_IOSetDisplay(char * str);
Std_ReturnType Rte_Call_LcdSensor_rpIOSetLcd_IOchoose_place(uint8 row,uint8 col,char *Str);

#define Rte_Call_rpIOSetLcd_IOSetClear 		Rte_Call_LcdSensor_rpIOSetLcd_IOSetClear
#define Rte_Call_rpIOSetLcd_IOSetDisplay 		Rte_Call_LcdSensor_rpIOSetLcd_IOSetDisplay
#define Rte_Call_rpIOSetLcd_IOchoose_place 		Rte_Call_LcdSensor_rpIOSetLcd_IOchoose_place
void Lcd_Display (LcdType message,char * str, unsigned char r, unsigned char col);

#endif