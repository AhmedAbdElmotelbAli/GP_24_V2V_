
#ifndef RTE_MAIN_H
#define RTE_MAIN_H

#include "Rte_Type.h"

#define RTE_E_MAX_AGE_EXCEDDED				128


typedef enum {
    NormalState,
    CAR_BREAKING,
    SHOW_WARNING,
    IGNORE_WARNING,
    SWITCHLANESTATE
} State;
typedef struct
{
	boolean IsUpdated;
	Std_ReturnType Status;
} Rte_DataFlagsType;

typedef struct
{
	Rte_DataFlagsType BluetoothBtnSignal_1;
	Rte_DataFlagsType BluetoothBtnSignal_2;
	Rte_DataFlagsType warningMessageSignal;
	Rte_DataFlagsType carIdSignal;
	Rte_DataFlagsType laneSignal;
	Rte_DataFlagsType carTypeSignal;
} Rte_SenderReceiverFlagsType;

typedef struct
{	
	MultiStateBtnType	BluetoothBtnSignal_1;
	MultiStateBtnType	BluetoothBtnSignal_2;
	MultiStateBtnType warningMessageSignal;
	MultiStateBtnType carIdSignal;
	MultiStateBtnType laneSignal;
	MultiStateBtnType	carTypeSignal;
} Rte_SenderReceiverBuffersType;


Std_ReturnType Rte_Start(void);
Std_ReturnType Rte_Stop(void);

#endif