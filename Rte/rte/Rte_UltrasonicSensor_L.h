
 
#ifndef RTE_UltrasonicSensor_L_H
#define RTE_UltrasonicSensor_L_H

#include "Rte_UltrasonicSensor_L_Type.h"

/* RTE APIs Prototype Declaration */
Std_ReturnType Rte_Call_UltrasonicSensor_L_rpIOGetPosition_IOGet(IoPositionSensorReadingType* position);

#define Rte_Call_rpIOGetPosition_IOGet 				Rte_Call_UltrasonicSensor_L_rpIOGetPosition_IOGet

/* Runnables Prototype Declaration */
void UltrasonicSensor_L_GetPosition(SensorPositionType* Position);

#endif