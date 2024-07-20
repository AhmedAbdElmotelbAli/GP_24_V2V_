
#ifndef COM_H
#define COM_H

#include "Std_Types.h"
#include "Com_Cfg.h"
#include "UART.h"
#define MAX_LANE_LENGTH 	16 // Maximum length of each lane message
#define MAX_LINES					 4 

typedef uint16 				Com_SignalIdType;



Std_ReturnType Com_ReceiveSignal(Com_SignalIdType SignalId, void* SignalDataPtr);

void Com_MainFunction(void);

#endif