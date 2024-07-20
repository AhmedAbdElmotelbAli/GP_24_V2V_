

#include "Rte_LaneSensor.h"



void LaneSensor_GetLane (SensorLaneType* Lane)
{
	IoLaneSensorReadingType right_IR;
	IoLaneSensorReadingType left_IR;

	/* Server Call Points */
	(void)Rte_Call_rpIOGetLane_IOGet(&right_IR);
	(void)Rte_Call_rpIOGetotherLane_IOGet(&left_IR);

		
		if((left_IR == WHITE) && (right_IR == WHITE))
	{
		*Lane = Same_lane_white;   
	}
	else if((left_IR == BLACK) && (right_IR == BLACK))
	{
		*Lane = Same_lane_black;
	}
	else if((left_IR == WHITE) && (right_IR == BLACK))
	{
		*Lane = Change_lane_left;
	}
		else if((left_IR == BLACK) && (right_IR == WHITE))
	{
		*Lane = Change_lane_right;
	}
	else{
		
	}
}

