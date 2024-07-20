
#include "Dio.h"

#include "GPIO.h"
#include "UART.h"
#include "Bluetooth.h"
#include "Lcd.h"
#include "Motor.h"
#include "IR.h"
#include "UltraSonic.h"
#include "PWM.h"
#include <stdio.h>

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	/* Write to VFB variables */
	switch(ChannelId)
	{
		case DioConfg_DioChannel_ForwardReverseMotorCh:

			if(Level == STD_HIGH)
			{
			//	VFB_HeightPosition++; forward
			Motor_VoidGoForward();

			}
			else
			{
			//	VFB_HeightPosition--; backward
				Motor_VoidBackward();
			}
			break;
			
		case DioConfg_DioChannel_RightLeftMotorCh:
			
			if(Level == STD_HIGH)
			{
				
					Motor_VoidRight();
			}
			else
			{
				
					Motor_VoidLEFT();
			}
			break;
			
		case DioConfg_DioChannel_SetspeedStopMotorCh:
		
			if(Level == STD_HIGH)
			{
						Motor_VoidSetSpeed(50);
	
			}
			else
			{
					Motor_VoidStop();
				

			}
			break;
			
		default:
			break;
	}


}
