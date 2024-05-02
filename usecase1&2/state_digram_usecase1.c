/*
 ============================================================================
 File Name		: state_digram_usecase1.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of state_digram_usecase1 &2
 Notes			: 
 ============================================================================
 */
#include "state_digram_usecase1.h"
#include "string.h"
#include "WIFI.h"
#include "Lcd.h"
#include "Bluetooth.h"
#include "Motor.h"
#include "IR.h"
#include "UltraSonic.h"


// Define global variables
WarningData warningData; // Data structure to hold warning information
State currentState = NormalState; // Initial state

// Function to handle the "Normal" state
void Normalstate(void) {
  if (UART_is_available(UART_5)) {
            // If not empty, transition to "Car Breaking" state
            currentState = CAR_BREAKING;
				
        }else {
				
				currentState = NormalState;
				}
	}
	


// Function to handle the "Car Breaking" state
void Car_Breaking(void) {
    // Read lane messages from Wi-Fi
	 // strcpy(warningData.warningMessage, "Waring message");
    //warningData.carId = 123;
    //strcpy(warningData.lane, "lane 1");
    //strcpy(warningData.carType, "Normal");
    Wifi_U8ReadLaneMessages(&warningData);
    
    // Indicate the car is breaking
    Bluetooth_VoidWriteString("Car Breaking\n");
    
    // Check if the car is in the same lane as the detected warning
    if (!lanedetect_same((uint8_t)getLaneNumber(warningData.lane))) {
        // If not in the same lane, transition to "Normal" state

        currentState = NormalState;
		
    }
		    Bluetooth_VoidWriteString("Same Lane\n");

    // Measure distance using ultrasonic sensor
    if (Ultrasonic_U32MeasureDistance_F() >= DISTANCE_THRESHOLD) {
        // If distance is above threshold, transition to "Ignore Warning" state
        currentState = IGNORE_WARNING;
    } else {
        // If distance is below threshold, determine action based on car type
        if (strcmp(warningData.carType, "Normal") == 0) {
            currentState = SHOW_WARNING; 
					// Transition to "Show Warning" state
        } else if (strcmp(warningData.carType, "Emergency") == 0) {
            currentState = SWITCHLANESTATE; // Transition to "Switch Lane" state
        }
    }
}

// Function to handle the "Show Warning" state
void show_warning(void) {
    // Indicate the car is showing a warning
    Bluetooth_VoidWriteString("Show Warning\n");
    
    // Display warning message on LCD
    LCD_VoidDisplayStringRowColumn(0, 0, warningData.warningMessage);
    
    // Measure distance using ultrasonic sensor
    uint32_t distance = Ultrasonic_U32MeasureDistance_F();
    
    // Determine action based on distance
    if (distance < 50 && distance > 10) {
        	Bluetooth_VoidWriteString("Slow state\n");
    // Gradually reduce car speed
    Motor_VoidSetSpeed(6);
    Timer4_voidDelayMilliSecond(250);
    Motor_VoidSetSpeed(5);
    Timer4_voidDelayMilliSecond(250);
    Motor_VoidSetSpeed(4);
    Timer4_voidDelayMilliSecond(250);
    Motor_VoidSetSpeed(3);
    Timer4_voidDelayMilliSecond(250);
    } else if (distance < 10) {
			Bluetooth_VoidWriteString("Stop state\n");
    // Stop the car
        Motor_VoidStop();
    }
}

// Function to handle the "Ignore Warning" state
void ignoreWarningState(void) {
    // Indicate the car is ignoring a warning
    Bluetooth_VoidWriteString("Ignore Warning\n");
    
    // Wait for 1 second
    Timer4_voidDelayMilliSecond(500);
    
    // Check if the distance is greater than or equal to the threshold
    if (Ultrasonic_U32MeasureDistance_F() >= DISTANCE_THRESHOLD) {
			Timer4_voidDelayMilliSecond(500);
			if (Ultrasonic_U32MeasureDistance_F() >= DISTANCE_THRESHOLD){
        currentState = NormalState; 
			}// Remain in "Ignore Warning" state
    } else {
        // Determine action based on car type
        if (strcmp(warningData.carType, "Normal") == 0) {
            currentState = SHOW_WARNING; // Transition to "Show Warning" state
        } else if (strcmp(warningData.carType, "Emergency") == 0) {
            currentState = SWITCHLANESTATE; // Transition to "Switch Lane" state
        }
    }
}

// Function to handle the "Slow" state
void SlowState(void) {
	Bluetooth_VoidWriteString("Slow state\n");
    // Gradually reduce car speed
    Motor_VoidSetSpeed(6);
    Timer4_voidDelayMilliSecond(250);
    Motor_VoidSetSpeed(5);
    Timer4_voidDelayMilliSecond(250);
    Motor_VoidSetSpeed(4);
    Timer4_voidDelayMilliSecond(250);
    Motor_VoidSetSpeed(3);
    Timer4_voidDelayMilliSecond(250);
}


// Function to handle the "Switch Lane" state
void SwitchLaneState(void) {
    // Indicate the car is switching lanes
    Bluetooth_VoidWriteString("Switch Lane\n");
    
    // Display warning message on LCD
    LCD_VoidDisplayStringRowColumn(0, 0, warningData.warningMessage);
    
    // Extract lane information and switch lanes accordingly
    uint8_t laneNumber = (uint8_t)getLaneNumber(warningData.lane);
    if (laneNumber == 1) {
        changeLane(2);
    } else if (laneNumber == 2) {
        changeLane(1);
    }
    
    // Stop the car and transition to "Normal" state
    Motor_VoidStop();
    currentState = NormalState;
}

// Function to handle state transitions
void stateTransition1(State currentState) {
    switch (currentState) {
        case NormalState:
            Normalstate();
            break;
        case CAR_BREAKING:
            Car_Breaking();
            break;
        case SHOW_WARNING:
            show_warning();
            break;
        case IGNORE_WARNING:
            ignoreWarningState();
            break;
        case SWITCHLANESTATE:
            SwitchLaneState();
            break;
    }
}

