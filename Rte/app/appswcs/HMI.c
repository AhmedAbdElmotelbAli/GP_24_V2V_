

#include "Rte_HMI.h"


/**
 *
 * Runnable HMI_MainFunction
 *
 * Triggered By:
 *  - TimingEventImpl.TE_MainFunction_100ms
 *
 */

static MultiStateBtnType btnValueToState(uint8 value)
{
	MultiStateBtnType btnState;
	
	if(value == 1)
	{
		btnState = MULTI_STATE_BTN_MINUS;
	}
	else if(value == 2)
	{
		btnState = MULTI_STATE_BTN_PLUS;
	}
	else
	{
		btnState = MULTI_STATE_BTN_INIT;
	}
	
	return btnState;
}

void HMI_Main (void)
{
	Std_ReturnType status;
	MultiStateBtnType BluetoothBtnSignal_1;
	MultiStateBtnType BluetoothBtnSignal_2;
	MultiStateBtnType warningMessageSignal;
	MultiStateBtnType laneSignal;
	MultiStateBtnType carIdSignal;
	MultiStateBtnType carTypeSignal;
	boolean IsUpdated;
							
	IsUpdated = Rte_Read_rpCarCtrlData_BluetoothBtnSignal_1(&BluetoothBtnSignal_1);
	status = Rte_IsUpdated_rpCarCtrlData_BluetoothBtnSignal_1();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
	
		(void)Rte_Write_ppCarCtrlBtns_BluetoothBtnSignal_1(BluetoothBtnSignal_1);
	}
	
	IsUpdated = Rte_Read_rpCarCtrlData_BluetoothBtnSignal_2(&BluetoothBtnSignal_2);
	status = Rte_IsUpdated_rpCarCtrlData_BluetoothBtnSignal_2();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
	
		(void)Rte_Write_ppCarCtrlBtns_BluetoothBtnSignal_2(BluetoothBtnSignal_2);
	}
	
	IsUpdated = Rte_Read_rpCarCtrlData_warningMessageSignal(&warningMessageSignal);
	status = Rte_IsUpdated_rpCarCtrlData_warningMessageSignal();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		
		(void)Rte_Write_ppCarCtrlBtns_warningMessageSignal(warningMessageSignal);
	}
		IsUpdated = Rte_Read_rpCarCtrlData_carIdSignal(&carIdSignal);
	status = Rte_IsUpdated_rpCarCtrlData_carIdSignal();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
	
		(void)Rte_Write_ppCarCtrlBtns_carIdSignal(carIdSignal);
	}
		IsUpdated = Rte_Read_rpCarCtrlData_laneSignal(&laneSignal);
	status = Rte_IsUpdated_rpCarCtrlData_laneSignal();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		
		(void)Rte_Write_ppCarCtrlBtns_laneSignal(laneSignal);
	}
			IsUpdated = Rte_Read_rpCarCtrlData_laneSignal(&carTypeSignal);
	status = Rte_IsUpdated_rpCarCtrlData_laneSignal();
	if(status == RTE_E_OK && IsUpdated == TRUE)
	{
		
		(void)Rte_Write_ppCarCtrlBtns_carTypeSignal(carTypeSignal);
	}
}


