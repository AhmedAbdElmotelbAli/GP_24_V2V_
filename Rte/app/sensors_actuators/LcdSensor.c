
#include "Rte_Lcd.h"


//fill any non used with zero

void Lcd_Display (LcdType message,char * str, unsigned char r, unsigned char col)
{
	if(message == message_clear)
	{
		(void)Rte_Call_rpIOSetLcd_IOSetClear();
	}
	else if(message == message_Display)
	{
		(void)Rte_Call_rpIOSetLcd_IOSetDisplay(str);
	}
	else if (message == message_choose_place)
	{
		(void)Rte_Call_rpIOSetLcd_IOchoose_place( r , col, str);
	}
	
	else
	{
		/* do nothing */
	}
}

