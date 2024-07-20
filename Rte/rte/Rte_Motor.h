
#ifndef RTE_MOTOR_H
#define RTE_MOTOR_H

#include "Rte_Motor_Type.h"

/* RTE APIs Prototype Declaration */
Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetForward();
Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetReverse();
Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetRight();
Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetLeft();
Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetSpeed();
Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetStop();

#define Rte_Call_rpIOSetMotor_IOSetForward 		Rte_Call_Motor_rpIOSetMotor_IOSetForward
#define Rte_Call_rpIOSetMotor_IOSetReverse 		Rte_Call_Motor_rpIOSetMotor_IOSetReverse
#define Rte_Call_rpIOSetMotor_IOSetRight 		Rte_Call_Motor_rpIOSetMotor_IOSetRight
#define Rte_Call_rpIOSetMotor_IOSetLeft			Rte_Call_Motor_rpIOSetMotor_IOSetLeft
#define Rte_Call_rpIOSetMotor_IOSetSpeed		Rte_Call_Motor_rpIOSetMotor_IOSetSpeed
#define Rte_Call_rpIOSetMotor_IOSetStop 		Rte_Call_Motor_rpIOSetMotor_IOSetStop

/* Runnables Prototype Declaration */
void Motor_Move(StepMotorStepType Step);

#endif