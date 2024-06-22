#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "GPIO.h"
#include "UART.h"
#include "Bluetooth.h"
#include "Lcd.h"
#include "Motor.h"
#include "WIFI.h"
#include "IR.h"
#include "UltraSonic.h"
#include "state_digram_usecase1.h"
#include <ctype.h>
#include "PWM.h"
#include "LED.h"

/*
    This file contains the declaration of global variables, constants, function prototypes, and task handles used in the application.
*/

#define TIMEOUT_MS 				4000 // Timeout duration in milliseconds
#define MIN_DISTANCE			20
#define DEFAULT_DISTANCE	80
#define MAX_SPEED					10
#define Forward						0
#define Right							1
#define LEFT							2
#define Zero							0
#define MAX_LANE_LENGTH 	16 // Maximum length of each lane message
#define MAX_LINES					 4 // Maximum number of lines to receive
#define CHAR_TO_INT(c)   	 ((c) - '0')
// Define task handles
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
// Declaration of global variables
extern State currentState; // Initial state
extern uint8_t endstate;
extern uint32_t Startstate;
extern WarningData warningData;
static uint8_t bufferIndex = 0;
char buffer[MAX_LINES][MAX_LANE_LENGTH]; // Array of buffers for each line
static volatile uint8_t lineCount = 0; 
// Declaration of global variables used for task synchronization
uint32_t  Current_Distance;
uint32_t  Current_Distance_R;
uint32_t  Current_Distance_L;
char receive;
uint8_t static AEB_Flag = Zero;
uint8_t  AEB = Zero;
uint8_t static AEB_Flag1 = Zero;
uint8_t static flag = Zero;
uint8_t speed = 7;
TickType_t xStartTime ; // Get the current tick count
// Function prototypes
void task1(void* args);
void task2(void* args);
void task3(void* args);
void task4(void* args);
void task5(void* args);
void task6(void* args);
void stateTransition(State Statechange);

/*
    This function initializes hardware modules, creates tasks, and starts the FreeRTOS scheduler.

    Hardware modules initialized:
        - Motor
        - Bluetooth
        - LCD
        - IR
        - WiFi
        - Ultrasonic sensor

    Semaphores created:
        - BluetoothSemaphore: Used for synchronization between tasks for Bluetooth operations.
        - UltraSonicSemaphore: Used for synchronization between tasks for Ultrasonic sensor operations.

    Tasks created:
        - task1: Listens for commands from Bluetooth and controls the motor accordingly.
        - task2: Measures distance using the Ultrasonic sensor and sets the AEB_Flag if the distance is below a threshold.
        - task3: Reads messages from WiFi and displays them on the LCD if available.
        - task4: Controls the speed of the motor based on distance measured by the Ultrasonic sensor and the state of AEB_Flag.
        - task5: Detects lane errors and displays a warning message on the LCD if detected.
        - task6: Implements a state machine with a timeout mechanism for state transitions.

    Error handling:
        - Checks if semaphore creation was successful and handles errors by looping indefinitely.
        - If semaphores are not created successfully, the system halts to prevent undefined behavior.

    Scheduler start:
        - Starts the FreeRTOS scheduler, which begins task execution.
*/
int main(void) {
    // Initialize hardware modules
		Horn_Init();
    Motor_VoidInit();
    Bluetooth_Voidinit();
    Lcd_VoidInit();
    IR_init();
    Wifi_Voidinit();
		UltraSonic_Init_F();
	LCD_VoidDisplayStringRowColumn(ROW0, COLZ, "Ahmed a");

    // Create semaphores and check for successful creation
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
    while(1) {}
}
/*
    This task listens for commands from Bluetooth and controls the motor accordingly.

    Parameters:
        args: Pointer to task arguments (not used).

    Operation:
        - Checks if the AEB_Flag is not set to halt motor control.
        - Prints a debug message indicating the task is running.
        - Reads a character from Bluetooth.
        - If the received character is a valid command ('F', 'B', 'L', 'R', 'G', 'I', 'H', 'J', 'S'):
            - Controls the motor based on the received command.
            - Gives the Bluetooth semaphore for synchronization with other tasks.
        - Delays the task for 15 milliseconds.

    Notes:
        - AEB_Flag is checked to prevent motor control when an Automatic Emergency Braking condition is detected.
        - The delay can be adjusted based on system requirements.
*/



void task1(void* args) {
    
    while (1) {
        
            Bluetooth_VoidWriteString("on task 1\n"); // Print debug message
            
            // Read from Bluetooth
            receive = Bluetooth_U8Read();
            
            // Check if the received character is a valid command
            if ((receive == 'B' || (receive == 'G' && GET_BIT(AEB_Flag, LEFT) == Zero))  || (receive == 'I' && GET_BIT(AEB_Flag, Right) == Zero) || receive == 'H' || receive == 'J' || receive == 'S' || 
                 (receive == 'F' && GET_BIT(AEB_Flag, Forward) == Zero) || 
                 (receive == 'R' && GET_BIT(AEB_Flag, Right) == Zero) || 
                 (receive == 'L' && GET_BIT(AEB_Flag, LEFT) == Zero) || 
						      (receive=='W')||(receive=='w')||
									(receive=='V')||(receive=='v')||
						      (receive=='U')||(receive=='u')||
                (isdigit(receive) && CHAR_TO_INT(receive) <= MAX_SPEED)) {
									if(receive=='w')  WHITE_LED_OFF();
									if(receive=='W') WHITE_LED_ON();

                if (isdigit(receive) && CHAR_TO_INT(receive) <= 10) {
								  	uint8_t speed = CHAR_TO_INT(receive);
                    Motor_VoidSetSpeed(CHAR_TO_INT(receive) * 10);
                } else {
                    // Control motor based on received command
                    Bluetooth_VoidControl(receive);
                }
                
                // Give Bluetooth semaphore for synchronization
                xSemaphoreGive(BluetoothSemaphore);
            }
        
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
        // Measure distance using Ultrasonic sensor
				LCD_VoidDisplayStringRowColumn(0,4,"R");
				UltraSonic_Init_R();
        Current_Distance_R = Ultrasonic_U32MeasureDistance_R();
				LCD_VoidDisplayStringRowColumn(ROW0, COLZ, "Zone :(S\\F\\R\\L\\C)");	      
	  		LCD_VoidDisplayStringRowColumn(ROW1,COLZ,  "S\\N\\ :(N\\S\\S\\S\\N)");
				LCD_VoidDisplayStringRowColumn(0,4,"L");
			  UltraSonic_Init_L();
        Current_Distance_L = Ultrasonic_U32MeasureDistance_L();
        LCD_VoidDisplayStringRowColumn(0,4,"N");
				UltraSonic_Init_F();
        Current_Distance = Ultrasonic_U32MeasureDistance_F();
				LCD_VoidDisplayStringRowColumn(0,4,"Y"); 

			
			//Current_Distance = Ultrasonic_U32MeasureDistance_F();
        // Check if the measured distance is below the minimum threshold
        if (Current_Distance <= MIN_DISTANCE) {
            // Stop motor and set AEB_Flag
						Motor_VoidStop();
				  	AEB_Flag1=1;
           SET_BIT( AEB_Flag ,Forward);
            // Display warning message on LCD
            LCD_VoidDisplayStringRowColumn(ROW1, COL10, "N");
        } else{
					AEB_Flag1=0;
					CLR_BIT( AEB_Flag ,Forward);
				}
				if(Current_Distance_R <= MIN_DISTANCE){
				//	Motor_VoidStop();
					if(receive == 'R'||receive == 'I')  Motor_VoidStop(); 
           SET_BIT( AEB_Flag ,Right);
            // Display warning message on LCD
            LCD_VoidDisplayStringRowColumn(ROW1, 11, "N");
				}else{
					CLR_BIT( AEB_Flag ,Right);
				}if(Current_Distance_L <= MIN_DISTANCE){
				if(receive == 'L'||receive == 'G')  Motor_VoidStop(); 
           SET_BIT( AEB_Flag ,LEFT);
            // Display warning message on LCD
            LCD_VoidDisplayStringRowColumn(ROW1, 13, "N");
				}else{
				   CLR_BIT( AEB_Flag ,LEFT);
				}
			
        vTaskDelay(100); // Adjust delay time as needed
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
    TickType_t lastWakeTime;
    while (1) {
        Bluetooth_VoidWriteString("ready to read wifi 2\n");
        if (lineCount == 4) {
            lineCount = 0;
						vTaskPrioritySet(NULL,6);
            strcpy(warningData.warningMessage, buffer[0]);
            warningData.carId = atoi(buffer[1]);
            strcpy(warningData.lane, buffer[2]);
            strcpy(warningData.carType, buffer[3]);
						LCD_VoidclearScreen();
            LCD_VoidDisplayStringRowColumn(0, 0, warningData.warningMessage);
            LCD_VoidDisplayStringRowColumn(0, 16, buffer[1]);
            LCD_VoidDisplayStringRowColumn(1, 0, warningData.carType);
					if (strcmp(buffer[3], "Emergency") == 0){
						 AEB++;
						}else {
						 AEB = 0;
						}
						if(AEB==1||strcmp(warningData.carType, "Normal") == 0){
            flag = 1;
            xStartTime = xTaskGetTickCount();
            xTaskCreate(task6, "TASK6", 128, NULL, 7, &Task_Handle6);
						AEB=0;
				   	delay_milli(250);
						vTaskPrioritySet(NULL,4);
						}
        } else {
            vTaskDelay(80);
        }
				  vTaskDelay(80);
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
			uint8_t speedD=0;
			uint8_t Newspeed=0;
			
        if (!Motor_BoolCheckstop()) { // Check if motor is not stopped
            Bluetooth_VoidWriteString("on task 4\n"); // Print debug message
            // Check AEB_Flag to decide whether to control speed
            if (AEB_Flag1==0) {
                uint32_t Distance = Ultrasonic_U32MeasureDistance_F(); // Measure distance using Ultrasonic sensor
                // Check if distance is within acceptable range
                if ((Distance < DEFAULT_DISTANCE) && (Distance > MIN_DISTANCE)) {
									   speedD = 0.3*speed;
                    Newspeed =speed - speedD ; // Set speed to lower value (5)
								  	speed=Newspeed;
                    AEB_Flag1= 1; // Set AEB_Flag to indicate decrease in speed
                    LCD_VoidDisplayStringRowColumn(1,7,"D"); // Display message
									
									Motor_VoidSetSpeed(Newspeed*10); // Set motor speed
                }
            }
        } 
        vTaskDelay(120); // Adjust delay time as needed
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
			 left_IR=LaneDetector_L();
		   right_IR=LaneDetector_R();
        Bluetooth_VoidWriteString("on task 5\n"); // Print debug message
			if(Motor_BoolCheckstop()==false){
        if (lanedetect() == lINE_Error) { // Check if lane error is detected
					if((left_IR==WHITE&&right_IR==BLACK)&&GET_BIT( AEB_Flag ,LEFT)){
						LCD_VoidDisplayStringRowColumn(1,15, "L"); // Display warning message
						Motor_VoidLEFT();
						delay_milli(400);
						Motor_VoidGoForward();
						delay_milli(400);
					  Motor_VoidRight();
						delay_milli(400);
					}else if(((right_IR==WHITE)&&(left_IR==BLACK))&&GET_BIT( AEB_Flag ,Right)){
						LCD_VoidDisplayStringRowColumn(1,15, "R"); // Display warning message
            Motor_VoidRight();
						delay_milli(400);
						Motor_VoidGoForward();
						delay_milli(400);
					  Motor_VoidLEFT();
						delay_milli(400);						
					}
        }else if((left_IR==WHITE)&&(right_IR==WHITE)) {
				
				    LCD_VoidDisplayStringRowColumn(1,4,"W");
				}else if((left_IR==BLACK)&&(right_IR==BLACK)) {
				
				    LCD_VoidDisplayStringRowColumn(1,4,"B");
				}
			}
        vTaskDelay(140); // Adjust delay time as needed
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
    TickType_t xStartTime = xTaskGetTickCount(); // Get the current tick count
    TickType_t xElapsedTime;
    TickType_t xTimeout = pdMS_TO_TICKS(TIMEOUT_MS); // Convert timeout to ticks
    while (1) {
            xElapsedTime = xTaskGetTickCount() - xStartTime; // Calculate elapsed time
            if (xElapsedTime < xTimeout)
						{ 
							// Check if elapsed time is less than timeout duration
                // Perform state transition
                stateTransition(currentState);
                Bluetooth_VoidWriteString("enter warning\n"); // Print debug message
            if (endstate == 1) { // Check if end state flag is set
                    currentState = NormalState; // Transition to NormalState
								   	endstate=0;
									vTaskDelete(NULL);                }
						} else {
							LCD_VoidDisplayStringRowColumn(1,6,"TOUT");
							currentState = NormalState; // Transition to NormalState
					   	vTaskPrioritySet(NULL, 4); // Set priority to 4
							vTaskDelete(NULL);              
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
void stateTransition(State Statechange) {
    // Use semaphores to synchronize state transition
    xSemaphoreGive(BluetoothSemaphore);
    xSemaphoreGive(UltraSonicSemaphore);
    stateTransition1(Statechange); // Call external function to perform state transition
}

void UART5_Handler(void) {
    // Clear the interrupt flag
    UART5_ICR_R |= 0x10;
    char receivedChar = (char)(UART5_DR_R & 0xFF);

    // Store the character in the current buffer
    if (lineCount < MAX_LINES) {
        if (receivedChar == '\n' || receivedChar == '\0') {
            // Null-terminate the buffer
            buffer[lineCount][bufferIndex] = '\0';
            lineCount++;
            bufferIndex = 0;    // Reset buffer index for next line
        } else if (receivedChar == '#') {
            // Null-terminate the buffer and increment lineCount
            buffer[lineCount][bufferIndex] = '\0';
            lineCount++;
            bufferIndex = 0;    // Reset buffer index for next line
        } else if (receivedChar == ' ') {
            // Ignore leading spaces
            if (bufferIndex > 0) {
                // Store the character in the buffer
                if (bufferIndex < MAX_LANE_LENGTH - 1) {
                    buffer[lineCount][bufferIndex++] = receivedChar;
                } else {
                    // Buffer full, null-terminate and increment lineCount
                    buffer[lineCount][bufferIndex] = '\0';
                    lineCount++;
                    bufferIndex = 0; // Reset buffer index for next line
                }
            }
        } else {
            // Store the character in the buffer
            if (bufferIndex < MAX_LANE_LENGTH - 1) {
                buffer[lineCount][bufferIndex++] = receivedChar;
            } else {
                // Buffer full, null-terminate and increment lineCount
                buffer[lineCount][bufferIndex] = '\0';
                lineCount++;
                bufferIndex = 0; // Reset buffer index for next line
            }
        }
    }
}


