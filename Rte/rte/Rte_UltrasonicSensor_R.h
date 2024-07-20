
 
#ifndef RTE_UltrasonicSensor_R_H
#define RTE_UltrasonicSensor_R_H

#include "Rte_UltrasonicSensor_R_Type.h"

/* RTE APIs Prototype Declaration */
Std_ReturnType Rte_Call_UltrasonicSensor_R_rpIOGetPosition_IOGet(IoPositionSensorReadingType* position);

#define Rte_Call_rpIOGetPosition_IOGet 				Rte_Call_UltrasonicSensor_L_rpIOGetPosition_IOGet

/* Runnables Prototype Declaration */
void UltrasonicSensor_R_GetPosition(SensorPositionType* Position);

#endif