
#ifndef RTE_IOHWABS_H
#define RTE_IOHWABS_H

#include "Rte_IoHwAbs_Type.h"

/* RTE APIs Prototype Declaration */

/* Runnables Prototype Declaration */
void IoHwAbs_ECUGet_ForwardUltrameasure(IoPositionSensorReadingType* position);
void IoHwAbs_ECUGet_RightUltrameasure(IoPositionSensorReadingType* position);
void IoHwAbs_ECUGet_LeftUltrameasure(IoPositionSensorReadingType* position);
void IoHwAbs_ECUGet_Lane (IoLaneSensorReadingType* lane);
void IoHwAbs_ECUGet_otherLane (IoLaneSensorReadingType* lane);
void IoHwAbs_ECUSetForward_Motor (void);
void IoHwAbs_ECUSetRight_Motor (void);
void IoHwAbs_ECUSetReverse_Motor(void);
void IoHwAbs_ECUSetStop_Motor (void);
void IoHwAbs_ECUSetSpeed_Motor(void);
void IoHwAbs_ECUWritestring_Lcd(void);
void IoHwAbs_ECUIOSetDisplay_Lcd(char * str);
void IoHwAbs_ECUIOchoose_place_Lcd(uint8 row,uint8 col,char *Str);
void IoHwAbs_ECUCheckstop_Motor(boolean* check);

#endif