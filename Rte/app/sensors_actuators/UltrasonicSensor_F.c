

#include "Rte_UltrasonicSensor_F.h"




void UltrasonicSensor_F_GetPosition (SensorPositionType* Position)
{
	IoPositionSensorReadingType position;

	/* Server Call Points */
	(void)Rte_Call_rpIOGetPosition_IOGet(&position);
	
	if(position <= 25)
	{
		*Position = SENSOR_POSITION_STEP_0;   
	}
	else if(position > 25 && position <= 50)
	{
		*Position = SENSOR_POSITION_STEP_1;
	}
	else
	{
		*Position = SENSOR_POSITION_STEP_3;
	}
}

