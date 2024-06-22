// Include necessary header files

#include "state_digram_usecase1.h"
#include "string.h"
#include "WIFI.h"
#include "Lcd.h"
#include "Bluetooth.h"
#include "Motor.h"
#include "IR.h"
#include "UltraSonic.h"
 uint32_t Startstate= 0;
 uint32_t endstate= 0;
extern uint8_t speed ;
extern uint8_t AEB;
// Define global variables
WarningData warningData; // Data structure to hold warning information
State currentState = CAR_BREAKING; // Initial state

// Function to handle the "Normal" state
void Normalstate(void) {
 
		       
            currentState = CAR_BREAKING;
				
       
	}


// Function to handle the "Car Breaking" state
void Car_Breaking(void) {
    Bluetooth_VoidWriteString("Car Breaking\n");

    // Check if the car is in the same lane as the detected warning
    if (!lanedetect_same((uint8_t)getLaneNumber(warningData.lane))) {
        // If not in the same lane, transition to "Normal" state

        currentState = NormalState;
				LCD_VoidDisplayStringRowColumn(1,10,"ignore");
			  endstate=1;
    }else{
			if (AEB==1) {
            currentState = SWITCHLANESTATE; // Transition to "Switch Lane" state
        }else if (strcmp(warningData.carType, "Normal") == 0) {
					 // Measure distance using ultrasonic sensor
		      uint32_t distance =Ultrasonic_U32MeasureDistance_F();
          if (distance >= DISTANCE_THRESHOLD) {
        // If distance is above threshold, transition to "Ignore Warning" state
        currentState = IGNORE_WARNING;
            }
        else{ 
					currentState = SHOW_WARNING; 
					// Transition to "Show Warning" state
        } 
		

    
    }
	}
}

// Function to handle the "Show Warning" state
void show_warning(void) {
	    uint8_t speedD=0;
			uint8_t Newspeed=0;
    // Indicate the car is showing a warning
    Bluetooth_VoidWriteString("Show Warning\n");
    
    // Display warning message on LCD
  //  LCD_VoidDisplayStringRowColumn(0, 0, warningData.warningMessage);
    
    // Measure distance using ultrasonic sensor
    uint32_t distance = Ultrasonic_U32MeasureDistance_F();
    
    // Determine action based on distance
    if ((distance > DISTANCE_LESS)&&(distance < DISTANCE_THRESHOLD) ) {
        	Bluetooth_VoidWriteString("Slow state\n");
		LCD_VoidDisplayStringRowColumn(1,10,"sl      ");
    // Gradually reduce car speed
    speedD = 0.3*speed;
    Newspeed =speed - speedD ; // Set speed to lower value (5)
		speed=Newspeed;
			if(speed<0) speed=0;
			Motor_VoidSetSpeed(speed*10);
			endstate=1;
			Startstate=0;
    } else if (distance < DISTANCE_LESS) {
		LCD_VoidDisplayStringRowColumn(1,10,"st    ");
			Bluetooth_VoidWriteString("Stop state\n");
      Motor_VoidStop();
	//  	delay_milli(2000);

			endstate=1;
			Startstate=0;
    }
}

// Function to handle the "Ignore Warning" state
void ignoreWarningState(void) {
    // Indicate the car is ignoring a warning
    Bluetooth_VoidWriteString("Ignore Warning\n");
			if (Ultrasonic_U32MeasureDistance_F() >= DISTANCE_THRESHOLD){
        currentState = IGNORE_WARNING; 
				LCD_VoidDisplayStringRowColumn(1,10,"ignore");
			}// Remain in "Ignore Warning" state
      else
				{
        // Determine action based on car type
        if (strcmp(warningData.carType, "Normal") == 0) {
            currentState = SHOW_WARNING; // Transition to "Show Warning" state
        } else if (strcmp(warningData.carType, "Emergency") == 0) {
            currentState = SWITCHLANESTATE; // Transition to "Switch Lane" state
        }
    }
}
#if 0
// Function to handle the "Slow" state
void SlowState(void) {
	Bluetooth_VoidWriteString("Slow state\n");
    // Gradually reduce car speed
    Motor_VoidSetSpeed(6);
    delay_milli(250);
    Motor_VoidSetSpeed(5);
    delay_milli(250);
    Motor_VoidSetSpeed(4);
    delay_milli(250);
    Motor_VoidSetSpeed(3);
    delay_milli(250);
}
#endif

// Function to handle the "Switch Lane" state
void SwitchLaneState(void) {
    // Indicate the car is switching lanes
    Bluetooth_VoidWriteString("Switch Lane\n");
    
    // Display warning message on LCD
   // LCD_VoidDisplayStringRowColumn(0, 0, warningData.warningMessage);
    
    // Extract lane information and switch lanes accordingly
	LCD_VoidDisplayStringRowColumn(1,8,"Lane ch");
    uint8_t laneNumber = (uint8_t)getLaneNumber(warningData.lane);
    if (laneNumber == 1) {
        changeLane(2);
			endstate=1;
			Startstate=0;
			
    } else if (laneNumber == 2) {
      changeLane(1);
			endstate=1;
			Startstate=0;
			
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

