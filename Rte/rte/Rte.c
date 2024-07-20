
#include "Rte_Type.h"
#include "Rte_Main.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"

#include "Rte_Motor.h"
#include "Rte_UltrasonicSensor_F.h"
#include "Rte_HMI.h"
#include "Rte_UltrasonicSensor_L.h"
#include "Rte_UltrasonicSensor_R.h"
#include "Rte_IoHwAbs.h"
#include "Rte_CarManager.h"
#include "Rte_LaneSensor.h"

#include "Rte_Lcd.h"

#include "Com.h"


/* ***************************************************** */
/* 														 */
/* Sender Receiver Variables 							 */
/* 														 */
/* ***************************************************** */

static Rte_SenderReceiverBuffersType Rte_SenderReceiverBuffers;
static Rte_SenderReceiverFlagsType Rte_SenderReceiverFlags;



/* ***************************************************** */
/* 														 */
/* Sender Receiver APIs - IntraECU 					 */
/* 														 */
/* ***************************************************** */

Std_ReturnType Rte_Write_HMI_ppCarCtrlBtns_warningMessageSignal(MultiStateBtnType warningMessageSignal)
{
	Rte_SenderReceiverBuffers.warningMessageSignal = warningMessageSignal;
	

	return RTE_E_OK; 
}

Std_ReturnType Rte_Read_CarManager_rpCarCtrlBtns_warningMessageSignal(MultiStateBtnType* warningMessageSignal)
{
	*warningMessageSignal = Rte_SenderReceiverBuffers.warningMessageSignal;
	return RTE_E_OK; 
}

Std_ReturnType Rte_Write_HMI_ppCarCtrlBtns_carIdSignal(MultiStateBtnType carIdSignal)
{
	Rte_SenderReceiverBuffers.carIdSignal = carIdSignal;
	

	
	return RTE_E_OK; 
}

Std_ReturnType Rte_Read_CarManager_rpCarCtrlBtns_carIdSignal(MultiStateBtnType* carIdSignal)
{
	*carIdSignal = Rte_SenderReceiverBuffers.carIdSignal;
	return RTE_E_OK; 
}

Std_ReturnType Rte_Write_HMI_ppCarCtrlBtns_laneSignal(MultiStateBtnType laneSignal)
{
	Rte_SenderReceiverBuffers.laneSignal = laneSignal;
	
	
	
	return RTE_E_OK; 
}

Std_ReturnType Rte_Read_CarManager_rpCarCtrlBtns_laneSignal(MultiStateBtnType* laneSignal)
{
	*laneSignal = Rte_SenderReceiverBuffers.laneSignal;
	return RTE_E_OK; 
}
Std_ReturnType Rte_Write_HMI_ppCarCtrlBtns_carTypeSignal(MultiStateBtnType carTypeSignal)
{
	Rte_SenderReceiverBuffers.carTypeSignal = carTypeSignal;
	

	
	return RTE_E_OK; 
}

Std_ReturnType Rte_Read_CarManager_rpCarCtrlBtns_carTypeSignal(MultiStateBtnType* carTypeSignal)
{
	*carTypeSignal = Rte_SenderReceiverBuffers.carTypeSignal;
	return RTE_E_OK; 
}
Std_ReturnType Rte_Write_HMI_ppCarCtrlBtns_BluetoothBtnSignal_1(MultiStateBtnType BluetoothBtnSignal_1)
{
	Rte_SenderReceiverBuffers.BluetoothBtnSignal_1 = BluetoothBtnSignal_1;
	
	return RTE_E_OK; 
}

Std_ReturnType Rte_Read_CarManager_rpCarCtrlBtns_BluetoothBtnSignal_1(MultiStateBtnType* BluetoothBtnSignal_1)
{
	*BluetoothBtnSignal_1 = Rte_SenderReceiverBuffers.BluetoothBtnSignal_1;
	return RTE_E_OK; 
}
Std_ReturnType Rte_Write_HMI_ppCarCtrlBtns_BluetoothBtnSignal_2(MultiStateBtnType BluetoothBtnSignal_2)
{
	Rte_SenderReceiverBuffers.BluetoothBtnSignal_2 = BluetoothBtnSignal_2;
	

	
	return RTE_E_OK; 
}

Std_ReturnType Rte_Read_CarManager_rpCarCtrlBtns_BluetoothBtnSignal_2(MultiStateBtnType* BluetoothBtnSignal_2)
{
	*BluetoothBtnSignal_2 = Rte_SenderReceiverBuffers.BluetoothBtnSignal_2;
	return RTE_E_OK; 
}
/* ***************************************************** */
/* 														 */
/* Sender Receiver APIs - InterECU 					 */
/* 														 */
/* ***************************************************** */

Std_ReturnType Rte_Read_HMI_rpCarCtrlData_BluetoothBtnSignal_1(uint8* BluetoothBtnSignal_1)
{
	(void)Com_ReceiveSignal(ComConf_ComSignal_BluetoothBtnSignal_1, (void*)BluetoothBtnSignal_1);
	
	Rte_SenderReceiverFlags.BluetoothBtnSignal_1.IsUpdated = FALSE;
	
	return Rte_SenderReceiverFlags.BluetoothBtnSignal_1.Status;
}

boolean Rte_IsUpdated_HMI_rpCarCtrlData_BluetoothBtnSignal_1(void)
{
	return Rte_SenderReceiverFlags.BluetoothBtnSignal_1.IsUpdated;
}

Std_ReturnType Rte_Read_HMI_rpCarCtrlData_BluetoothBtnSignal_2(uint8* BluetoothBtnSignal_2)
{
	(void)Com_ReceiveSignal(ComConf_ComSignal_BluetoothBtnSignal_2, (void*)BluetoothBtnSignal_2);
	
	Rte_SenderReceiverFlags.BluetoothBtnSignal_2.IsUpdated = FALSE;
	
	return Rte_SenderReceiverFlags.BluetoothBtnSignal_2.Status;
}

boolean Rte_IsUpdated_HMI_rpCarCtrlData_BluetoothBtnSignal_2(void)
{
	return Rte_SenderReceiverFlags.BluetoothBtnSignal_2.IsUpdated;
}

Std_ReturnType Rte_Read_HMI_rpCarCtrlData_warningMessageSignal(uint8* warningMessageSignal)
{
	(void)Com_ReceiveSignal(ComConf_ComSignal_warningMessageSignal, (void*)warningMessageSignal);
	
	Rte_SenderReceiverFlags.warningMessageSignal.IsUpdated = FALSE;
	
	return Rte_SenderReceiverFlags.warningMessageSignal.Status;
}

boolean Rte_IsUpdated_HMI_rpCarCtrlData_warningMessageSignal(void)
{
	return Rte_SenderReceiverFlags.warningMessageSignal.IsUpdated;
}

Std_ReturnType Rte_Read_HMI_rpCarCtrlData_carIdSignal(uint8* carIdSignal)
{
	(void)Com_ReceiveSignal(ComConf_ComSignal_carIdSignal, (void*)carIdSignal);
	
	Rte_SenderReceiverFlags.carIdSignal.IsUpdated = FALSE;
	
	return Rte_SenderReceiverFlags.carIdSignal.Status;
}

boolean Rte_IsUpdated_HMI_rpCarCtrlData_carIdSignal(void)
{
	return Rte_SenderReceiverFlags.carIdSignal.IsUpdated;
}
Std_ReturnType Rte_Read_HMI_rpCarCtrlData_laneSignal(uint8* laneSignal)
{
	(void)Com_ReceiveSignal(ComConf_ComSignal_laneSignal, (void*)laneSignal);
	
	Rte_SenderReceiverFlags.laneSignal.IsUpdated = FALSE;
	
	return Rte_SenderReceiverFlags.laneSignal.Status;
}

boolean Rte_IsUpdated_HMI_rpCarCtrlData_laneSignal(void)
{
	return Rte_SenderReceiverFlags.laneSignal.IsUpdated;
}
Std_ReturnType Rte_Read_HMI_rpCarCtrlData_carTypeSignal(uint8* carTypeSignal)
{
	(void)Com_ReceiveSignal(ComConf_ComSignal_carTypeSignal, (void*)carTypeSignal);
	
	Rte_SenderReceiverFlags.carTypeSignal.IsUpdated = FALSE;
	
	return Rte_SenderReceiverFlags.carTypeSignal.Status;
}

boolean Rte_IsUpdated_HMI_rpCarCtrlData_carTypeSignal(void)
{
	return Rte_SenderReceiverFlags.carTypeSignal.IsUpdated;
}



/* ***************************************************** */
/* 														 */
/* Client Server APIs					 				 */
/* 														 */
/* ***************************************************** */

Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetForward(void)
{
	IoHwAbs_ECUSetForward_Motor();
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetReverse(void)
{
	IoHwAbs_ECUSetReverse_Motor();
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetRight(void)
{
	IoHwAbs_ECUSetRight_Motor();
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetLeft(void)
{
	IoHwAbs_ECUSetLeft_Motor();
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetStop(void)
{
	IoHwAbs_ECUSetStop_Motor();
	return RTE_E_OK;
}
							
Std_ReturnType Rte_Call_Motor_rpIOSetMotor_IOSetSpeed(void)
{
	IoHwAbs_ECUSetSpeed_Motor();
	return RTE_E_OK;
}
Std_ReturnType Rte_Call_CarManager_rpIOSetMotor_IOCheckstop(boolean *check)
{
	IoHwAbs_ECUCheckstop_Motor(check);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_UltrasonicSensor_F_rpIOGetPosition_IOGet(IoPositionSensorReadingType* position)
{
	IoHwAbs_ECUGet_ForwardUltrameasure(position);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_UltrasonicSensor_R_rpIOGetPosition_IOGet(IoPositionSensorReadingType* position)
{
	IoHwAbs_ECUGet_RightUltrameasure(position);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_UltrasonicSensor_L_rpIOGetPosition_IOGet(IoPositionSensorReadingType* position)
{
	IoHwAbs_ECUGet_LeftUltrameasure(position);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_LaneSensor_rpIOGetotherLane_IOGet(IoLaneSensorReadingType* lane)
{
	IoHwAbs_ECUGet_otherLane(lane);
	return RTE_E_OK;
}
Std_ReturnType Rte_Call_LaneSensor_rpIOGetLane_IOGet(IoLaneSensorReadingType* lane)
{
	IoHwAbs_ECUGet_Lane(lane);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_CarManager_rpMotor_Move(StepMotorStepType Step)
{
	Motor_Move(Step);
	return RTE_E_OK;
}
Std_ReturnType Rte_Call_CarManager_rpLcd_Lcd_Display(LcdType message,char * str, unsigned char r, unsigned char col)
{
		Lcd_Display (message,str,r,col);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_LcdSensor_rpIOSetLcd_IOSetClear(){
   IoHwAbs_ECUWritestring_Lcd();
	return RTE_E_OK;
}
Std_ReturnType Rte_Call_LcdSensor_rpIOSetLcd_IOSetDisplay(char * str){
	IoHwAbs_ECUIOSetDisplay_Lcd(str);
	return RTE_E_OK;
}
Std_ReturnType Rte_Call_LcdSensor_rpIOSetLcd_IOchoose_place(uint8 row,uint8 col,char *Str){
	IoHwAbs_ECUIOchoose_place_Lcd(row,col,Str);
	return RTE_E_OK;
}


Std_ReturnType Rte_Call_CarManager_rpUltrasonicSensor_F_GetPosition(SensorPositionType* Position)
{
	UltrasonicSensor_F_GetPosition(Position);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_CarManager_rpUltrasonicSensor_R_GetPosition(SensorPositionType* Position)
{
	UltrasonicSensor_R_GetPosition(Position);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_CarManager_rpUltrasonicSensor_L_GetPosition(SensorPositionType* Position)
{
	UltrasonicSensor_L_GetPosition(Position);
	return RTE_E_OK;
}

Std_ReturnType Rte_Call_CarManager_rpLaneSensor_GetLane(SensorLaneType* lane)
{
	LaneSensor_GetLane(lane);
	return RTE_E_OK;
}



/* ***************************************************** */
/* 														 */
/* Tasks Impl					 						 */
/* 														 */
/* ***************************************************** */
TaskHandle_t Task_Handle1;
TaskHandle_t Task_Handle2;
TaskHandle_t Task_Handle3;
TaskHandle_t Task_Handle4;
TaskHandle_t Task_Handle5;
TaskHandle_t Task_Handle6;
TaskHandle_t Task_Handle7;
// Semaphore to synchronize tasks
SemaphoreHandle_t BluetoothSemaphore;
SemaphoreHandle_t UltraSonicSemaphore;
//states
extern State currentState; // Initial state
extern uint8_t endstate;
extern uint32_t Startstate;
 void Statetr(State Statechange) {
    // Use semaphores to synchronize state transition
    xSemaphoreGive(BluetoothSemaphore);
    xSemaphoreGive(UltraSonicSemaphore);
	 
}
void task1(void* args) {
    while (1) {
						HMI_Main();
						CarManager_task1();
            xSemaphoreGive(BluetoothSemaphore); // Synchronize
				
        }
    }







/*
    This task measures the distance using the Ultrasonic sensor and controls motor operation based on the measured distance.

    Parameters:
        args: Pointer to task arguments (not used).

    Operation:
        - Prints a debug message indicating the task is running.
        - Measures distance using the Ultrasonic sensor.
        - If the measured distance is less than or equal to the MIN_DISTANCE threshold:
            - Stops the motor.
            - Sets the AEB_Flag to indicate an Automatic Emergency Braking condition.
            - Clears the LCD screen and displays a warning message.
        - Otherwise, resets the AEB_Flag to 0.
        - Delays the task for 400 milliseconds.

    Notes:
        - The Ultrasonic sensor is used to measure distance.
        - If the measured distance is below the MIN_DISTANCE threshold, the motor is stopped and AEB_Flag is set.
        - The delay can be adjusted based on system requirements.
*/



void task2(void* args) {
    while (1) {
				CarManager_task2();
        vTaskDelay(80); // Adjust delay time as needed
    }
}


/*
    This task reads messages from WiFi and displays them on the LCD if available, while checking the AEB_Flag condition.

    Parameters:
        args: Pointer to task arguments (not used).

    Operation:
        - Initializes a variable to track the last wake time of the task.
        - Enters an infinite loop to continuously perform the task.
        - Checks if WiFi data is available (UART_5) and AEB_Flag is not set.
        - If WiFi data is available and AEB_Flag is not set:
            - Prints a debug message indicating the task is running.
            - Reads lane messages from WiFi.
            - Displays car type information on the LCD.
            - Sets a flag to indicate that messages have been processed.
            - Delays the task for 1000 milliseconds and an additional 500 milliseconds.
        - Otherwise, delays the task for 100 milliseconds.

    Notes:
        - The task continuously checks for WiFi data and AEB_Flag condition.
        - If data is available and AEB_Flag is not set, it processes the data and updates the flag.
        - Delays are used to control the task execution rate and adjust the responsiveness.
*/


void task3(void* args) {
    while (1) {
			HMI_Main();
			CarManager_task3();
        
        vTaskDelay(60);
    }
}

/*
    This task controls the speed of the motor based on distance measured by the Ultrasonic sensor and the AEB_Flag condition.

    Parameters:
        args: Pointer to task arguments (not used).

    Operation:
        - Initializes a variable to track the start time of the task.
        - Initializes a variable to store the motor speed.
        - Enters an infinite loop to continuously perform the task.
        - Checks if the motor is not stopped.
        - If the motor is not stopped:
            - Prints a debug message indicating the task is running.
            - Checks the AEB_Flag condition to decide whether to control the motor speed.
            - If AEB_Flag is not set:
                - Resets the speed variable.
                - Measures distance using the Ultrasonic sensor.
                - If the distance is within the acceptable range:
                    - Sets the speed to a lower value (5).
                    - Sets the AEB_Flag to indicate a decrease in speed.
                    - Clears the LCD screen and displays a message.
                - Otherwise, sets the speed to a higher value (9).
                - Clears the LCD screen.
                - Sets the motor speed accordingly.
        - If the motor is stopped:
            - Prints a debug message indicating that the motor is stopped.
            - Clears the LCD screen.
            - Delays the task for 400 milliseconds.

    Notes:
        - The task continuously checks the motor status and adjusts the speed based on distance and AEB_Flag condition.
        - Delays are used to control the task execution rate and adjust the responsiveness.
*/
void task4(void* args) {
    while (1) {
				CarManager_task4();
        vTaskDelay(100); // Adjust delay time as needed
    }
}

/*
    This task detects lane errors and displays a warning message on the LCD if detected.

    Parameters:
        args: Pointer to task arguments (not used).

    Operation:
        - Enters an infinite loop to continuously perform the task.
        - Prints a debug message indicating the task is running.
        - Calls the lanedetect function to detect lane errors.
        - If a lane error is detected:
            - Clears the LCD screen.
            - Displays a message to change to the correct lane.
        - Delays the task for 400 milliseconds.

    Notes:
        - The task continuously checks for lane errors.
        - If a lane error is detected, it displays a warning message.
        - Delays are used to control the task execution rate and adjust the responsiveness.
*/
void task5(void* args) {
    while (1) {
        // Read the values from the left and right IR sensors
				CarManager_task5();
        
        // Adjust delay time as needed
        vTaskDelay(120);
    }
}




/*
    This task implements a state machine with a timeout mechanism for state transitions.

    Parameters:
        args: Pointer to task arguments (not used).

    Operation:
        - Initializes variables to track start time, elapsed time, and timeout duration.
        - Enters an infinite loop to continuously perform the task.
        - Checks if the flag is set to indicate that messages have been processed.
        - If the flag is set:
            - Calculates the elapsed time since the task started.
            - If the elapsed time is less than the timeout duration:
                - Sets the priority of the task to 6 for state transition.
                - Performs the state transition.
                - If the current state is NormalState, exits the loop.
                - Prints a debug message indicating the entry into a warning state.
                - If the end state flag is set, transitions to NormalState and exits the loop.
            - If the elapsed time exceeds the timeout duration:
                - Clears the LCD screen.
                - Prints a debug message indicating a timeout.
                - Transitions to NormalState and exits the loop.
        - If the flag is not set, delays the task for 1000 milliseconds.
    - Sets the priority of the task to 4 after exiting the loop.
    - Delays the task for 500 milliseconds.

    Notes:
        - The task continuously checks for flag status and performs state transitions with a timeout mechanism.
        - Delays are used to control the task execution rate and adjust the responsiveness.
*/
void task6(void* args) {
    // Initial setup
    TickType_t xStartTime = xTaskGetTickCount(); // Get the current tick count
    TickType_t xElapsedTime;
    TickType_t xTimeout = pdMS_TO_TICKS(4000); // Convert timeout to ticks

    while (1) {
        xElapsedTime = xTaskGetTickCount() - xStartTime; // Calculate elapsed time

        if (xElapsedTime < xTimeout) { 
            // If elapsed time is less than timeout duration
            Statetr(currentState); // Perform state transition
           

            if (endstate == 1) { // Check if end state flag is set
                currentState = NormalState; // Transition to NormalState
                endstate = 0; // Reset end state flag
                vTaskDelete(NULL); // Delete current task
            }
        } else {
            // If elapsed time exceeds or equals timeout duration
            currentState = NormalState; // Transition to NormalState
            vTaskPrioritySet(NULL, 4); // Set task priority to 4
            vTaskDelete(NULL); // Delete current task
        }
    }
}


/*
    This function performs a state transition.

    Parameters:
        Statechange: The new state to transition to.

    Operation:
        - Uses semaphores to synchronize state transition.
        - Calls an external function to perform the state transition.

    Notes:
        - This function is called by task6 to perform state transitions.
*/



/* ***************************************************** */
/* 														 */
/* RTE State Machine APIs					 			 */
/* 														 */
/* ***************************************************** */


Std_ReturnType Rte_Start()
{

	Rte_SenderReceiverBuffers.warningMessageSignal = 0;
	Rte_SenderReceiverBuffers.carIdSignal = 0;
	Rte_SenderReceiverBuffers.laneSignal = 0;
	Rte_SenderReceiverBuffers.BluetoothBtnSignal_1 = 0;
	Rte_SenderReceiverBuffers.BluetoothBtnSignal_2 = 0;
	Rte_SenderReceiverBuffers.carTypeSignal = 0;
	
	   if ((BluetoothSemaphore = xSemaphoreCreateBinary()) == NULL || 
        (UltraSonicSemaphore = xSemaphoreCreateBinary()) == NULL) {
        while(1); // Handle error
    }
		//Motor_VoidBackward();
    // Create tasks with different priorities
    xTaskCreate(task1, "TASK1", 128, NULL, 4, &Task_Handle1); 
    xTaskCreate(task2, "TASK2", 128, NULL, 5, &Task_Handle2);
    xTaskCreate(task3, "TASK3", 128, NULL, 4, &Task_Handle3);
    xTaskCreate(task4, "TASK4", 128, NULL, 4, &Task_Handle4);  
   	xTaskCreate(task5, "TASK5", 128, NULL, 4, &Task_Handle5);

    // Start FreeRTOS scheduler
    vTaskStartScheduler();
		
    // Should never reach here
    while(1) {
		
		
		}
	
	return RTE_E_OK;
}

