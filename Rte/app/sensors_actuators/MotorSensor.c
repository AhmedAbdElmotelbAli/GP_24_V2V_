

#include "Rte_Motor.h"


/**
 *
 * Runnable Motor_Move
 *
 * Triggered By:
 *  - OperationInvokedEventImpl.OIE_pptMotor_Move
 *
 */

void Motor_Move (StepMotorStepType Step)
{
	if(Step == MOTOR_STEP_Forward)
	{
		(void)Rte_Call_rpIOSetMotor_IOSetForward();
	}
	else if(Step == MOTOR_STEP_Backward)
	{
		(void)Rte_Call_rpIOSetMotor_IOSetReverse();
	}
	else if (Step == MOTOR_STEP_Right)
	{
		(void)Rte_Call_rpIOSetMotor_IOSetRight();
	}
	else if (Step == MOTOR_STEP_Left)
	{
		(void)Rte_Call_rpIOSetMotor_IOSetLeft();
	}
	else if (Step == MOTOR_STEP_Stop)
	{
		(void)Rte_Call_rpIOSetMotor_IOSetStop();
	}
	else if (Step == MOTOR_Set_Speed)
	{
		(void)Rte_Call_rpIOSetMotor_IOSetSpeed();
	}
	else
	{
		/* do nothing */
	}
}

