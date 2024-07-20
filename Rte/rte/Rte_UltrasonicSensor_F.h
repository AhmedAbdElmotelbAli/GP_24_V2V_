
 
#ifndef RTE_UltrasonicSensor_F_H
#define RTE_UltrasonicSensor_F_H

#include "Rte_UltrasonicSensor_F_Type.h"

/* RTE APIs Prototype Declaration */
																		
Std_ReturnType Rte_Call_UltrasonicSensor_F_rpIOGetPosition_IOGet(IoPositionSensorReadingType* position);

#define Rte_Call_rpIOGetPosition_IOGet 				Rte_Call_UltrasonicSensor_F_rpIOGetPosition_IOGet

/* Runnables Prototype Declaration */
void UltrasonicSensor_F_GetPosition(SensorPositionType* Position);

#endif