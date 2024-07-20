


#include "Rte_IoHwAbs.h"

/* For reading from Position Sensors */
#include "Sensors.h"


/* For reading from Weight Sesnor */


/* For driving Motors (height, slide, incline) */
#include "Dio.h"
#include "Lcd.h"

/* Shall be replaced with Inter Runnable Variable */
/* Internal variables to read Position sensors in one Sensors Group */
static Sensors_ValueGroupType IoHwAb_PositionSensorsReadings[Sensors_GR0_NUM_CHANNELS] =
{
   
   0,
  
   0,

   0,

   0,

   0
};


void IoHwAbs_ECUGet_ForwardUltrameasure(IoPositionSensorReadingType* position)
{
	Std_ReturnType status;

	status = Sensors_ReadGroup(SensorsConf_SensorsGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Sensors resolution "Sensors_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[0];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}




void IoHwAbs_ECUGet_RightUltrameasure(IoPositionSensorReadingType* position)
{
	Std_ReturnType status;

	status = Sensors_ReadGroup(SensorsConf_SensorsGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Sensors resolution "Sensors_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[1];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}




void IoHwAbs_ECUGet_LeftUltrameasure(IoPositionSensorReadingType* position)
{
	Std_ReturnType status;

	status = Sensors_ReadGroup(SensorsConf_SensorsGroup_PositionsSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Sensors resolution "Sensors_ValueGroupType can be uint8 or uint16" */
		*position = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[2];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}



void IoHwAbs_ECUGet_Lane (IoLaneSensorReadingType* lane)
{
	Std_ReturnType status;

	status = Sensors_ReadGroup(SensorsConf_SensorsGroup_LaneSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Sensors resolution "Sensors_ValueGroupType can be uint8 or uint16" */
		*lane = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[3];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}
void IoHwAbs_ECUGet_otherLane (IoLaneSensorReadingType* lane)
{
	Std_ReturnType status;

	status = Sensors_ReadGroup(SensorsConf_SensorsGroup_LaneSensorsGrp, IoHwAb_PositionSensorsReadings);
	
	if(status == E_OK)
	{
		/* IoPositionSensorReadingType has to be adjusted in arxml file */
		/* as per Sensors resolution "Sensors_ValueGroupType can be uint8 or uint16" */
		*lane = (IoPositionSensorReadingType)IoHwAb_PositionSensorsReadings[4];
	}
	else
	{
		/* Operation shall be updated to return failure error code */
	}
}






void IoHwAbs_ECUSetForward_Motor (void)
{
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_ForwardReverseMotorCh, STD_HIGH);
}




void IoHwAbs_ECUSetRight_Motor (void)
{
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_RightLeftMotorCh, STD_HIGH);
}



void IoHwAbs_ECUSetStop_Motor (void)
{
	/* Write HIGH to move forward */
	Dio_WriteChannel(DioConfg_DioChannel_SetspeedStopMotorCh, STD_LOW);
}



void IoHwAbs_ECUSetReverse_Motor(void)
{
	/* Write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_ForwardReverseMotorCh, STD_LOW);
}




void IoHwAbs_ECUSetLeft_Motor(void)
{
	/* Write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_RightLeftMotorCh, STD_LOW);
}


void IoHwAbs_ECUSetSpeed_Motor(void)
{
	/* Write LOW to move reverse */
	Dio_WriteChannel(DioConfg_DioChannel_SetspeedStopMotorCh, STD_HIGH);
}

void IoHwAbs_ECUWritestring_Lcd(void)
{
LCD_VoidclearScreen();
}


void IoHwAbs_ECUIOSetDisplay_Lcd(char * str)
{
	/* Write LOW to move reverse */
LCD_VoidDisplayString(str);
}
void IoHwAbs_ECUIOchoose_place_Lcd(uint8 row,uint8 col,char *Str)
{
	LCD_VoidDisplayStringRowColumn(row,col,Str);
}
void IoHwAbs_ECUCheckstop_Motor(boolean* check)
{
*check= Motor_BoolCheckstop();
}


