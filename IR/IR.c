/*
 ============================================================================
 File Name		: IR.h
 Author			: Mohamed Emad Mostafa
 Version		: 1.0
 Date			: 20/4/2024
 Description	: This file contains the implementation of IR Sensor Driver
 Notes			: 
 ============================================================================
 */
#include "GPIO.h"
#include "IR.h"
#include "Delay.h"

uint8_t IR = 0;
uint8_t left_IR;
uint8_t right_IR;

/* Function Name: IR_init
 * Inputs:        Nothing
 * Returns:       void
 * Description:   Initializes the Infrared (IR) sensor system by setting the 
 *                necessary GPIO pins to input floating state.
 * */
void IR_init(void) {
    GPIO_Init(GPIO_PORTD, GPIO_PIN_3);
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN_3, GPIO_DIRECTION_INPUT_FLOAT);
    GPIO_Init(GPIO_PORTB, GPIO_PIN_1);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN_1, GPIO_DIRECTION_INPUT_FLOAT);
}

/* Function Name: LaneDetector_R
 * Inputs:        Nothing
 * Returns:       uint8_t
 * Description:   Detects the right lane by reading the state of the IR sensor
 *                on GPIO port D, pin 3 and returns its status.
 * */
uint8_t LaneDetector_R(void) {
    IR = GPIO_GetPinState(GPIO_PORTD, GPIO_PIN_3);
    return IR;
}

/* Function Name: LaneDetector_L
 * Inputs:        Nothing
 * Returns:       uint8_t
 * Description:   Detects the left lane by reading the state of the IR sensor
 *                on GPIO port B, pin 1 and returns its status.
 * */
uint8_t LaneDetector_L(void) {
    IR = GPIO_GetPinState(GPIO_PORTB, GPIO_PIN_1);
    return IR;
}

/* Function Name: getLaneNumber
 * Inputs:        const char *laneString - String representation of the lane
 * Returns:       int
 * Description:   Converts a lane string ("lane 1" or "lane 2") to a lane number.
 *                Returns 1 for "lane 1", 2 for "lane 2", and 0 for no match.
 * */
int getLaneNumber(const char *laneString) {
    if (strcmp(laneString, "lane 1") == 0) {
        return 1;
    } else if (strcmp(laneString, "lane 2") == 0) {
        return 2;
    } else {
        return 0; // Indicate no match
    }
}

/* Function Name: changeLane
 * Inputs:        uint8_t targetLane - The lane to switch to
 * Returns:       void
 * Description:   Changes the vehicle's lane to the specified target lane by
 *                turning right for lane 1 or left for lane 2, until the target
 *                lane is detected.
 * */
void changeLane(uint8_t targetLane) {
    while (!lanedetect_same(targetLane)) {
        if (targetLane == 1) {
					Motor_VoidSetSpeed(100);
            Motor_VoidRight(); // Turn right for lane 1
					  delay_milli(40);
					  Motor_VoidGoForward();
					  delay_milli(70);
					  Motor_VoidLEFT();
					  delay_milli(50);
					  Motor_VoidGoForward();
					  delay_milli(15);
            Motor_VoidStop(); // Stop motor
						Motor_VoidSetSpeed(70);
        } else if (targetLane == 2) {
					 Motor_VoidSetSpeed(100);
            Motor_VoidLEFT(); // Turn left for lane 2
					 delay_milli(40);
					  Motor_VoidGoForward();
					  delay_milli(70);
					  Motor_VoidRight();
					  delay_milli(50);
					  Motor_VoidGoForward();
					  delay_milli(15);
            Motor_VoidStop(); // Stop motor
						Motor_VoidSetSpeed(70);

        }
        // Add any delay or debounce logic if required
    }
}

/* Function Name: lanedetect
 * Inputs:        Nothing
 * Returns:       uint8_t
 * Description:   Detects the current lane by reading the states of both left and
 *                right IR sensors. Returns LANE1 if both sensors detect WHITE,
 *                returns LANE2 if both sensors detect BLACK, otherwise returns lINE_Error.
 * */
uint8_t lanedetect(void) {
    left_IR = LaneDetector_L();
    right_IR = LaneDetector_R();
    if (left_IR == WHITE && right_IR == WHITE) {
        return LANE1;
    } else if (left_IR == BLACK && right_IR == BLACK) {
        return LANE2;
    }
    return lINE_Error;    
}

/* Function Name: lanedetect_same
 * Inputs:        uint8_t lane - The lane to compare against
 * Returns:       bool
 * Description:   Checks if the current lane detected by lanedetect() is the same
 *                as the specified lane. Returns true if they match, false otherwise.
 * */
bool lanedetect_same(uint8_t lane) {
    uint8_t currentLane = lanedetect();  // Assuming lanedetect() retrieves the current lane
    return currentLane == lane;
}
