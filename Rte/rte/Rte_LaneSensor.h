
 
#ifndef RTE_LaneSENSOR_H
#define RTE_LaneSENSOR_H

#include "Rte_LaneSensor_Type.h"

/* RTE APIs Prototype Declaration */
Std_ReturnType Rte_Call_LaneSensor_rpIOGetLane_IOGet(IoLaneSensorReadingType* lane);
Std_ReturnType Rte_Call_LaneSensor_rpIOGetotherLane_IOGet(IoLaneSensorReadingType* lane);


#define Rte_Call_rpIOGetLane_IOGet 				Rte_Call_LaneSensor_rpIOGetLane_IOGet
#define Rte_Call_rpIOGetotherLane_IOGet 				Rte_Call_LaneSensor_rpIOGetotherLane_IOGet

/* Runnables Prototype Declaration */
void LaneSensor_GetLane(SensorLaneType* Weight);

#endif