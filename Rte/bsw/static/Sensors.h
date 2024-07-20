
 
#ifndef Sensors_H
#define Sensors_H

#include "Std_Types.h"
#include "Sensors_Cfg.h"

typedef uint8 				Sensors_GroupType;
typedef uint8				Sensors_ValueGroupType;

extern Std_ReturnType Sensors_ReadGroup(Sensors_GroupType Group, Sensors_ValueGroupType* DataBufferPtr);

#endif