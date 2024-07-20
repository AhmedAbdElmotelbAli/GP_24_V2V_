
 
#include "Sensors.h"
#include "UltraSonic.h"
#include "IR.h"


Std_ReturnType Sensors_ReadGroup(Sensors_GroupType Group, Sensors_ValueGroupType* DataBufferPtr)
{
	/* Read position sensors from VFB variables */
	DataBufferPtr[0] = (Sensors_ValueGroupType)Ultrasonic_U32MeasureDistance_F();
	DataBufferPtr[1] = (Sensors_ValueGroupType)Ultrasonic_U32MeasureDistance_R();
	DataBufferPtr[2] = (Sensors_ValueGroupType)Ultrasonic_U32MeasureDistance_L();
	DataBufferPtr[3] = (Sensors_ValueGroupType)LaneDetector_R();
	DataBufferPtr[3] = (Sensors_ValueGroupType)LaneDetector_L();
	return E_OK;
}