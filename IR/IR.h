/*
 ============================================================================
 File Name		: IR.h
 Author			: Mohamed Emad Mostafa
 Version		: 1.0
 Date			: 20/4/2024
 Description	: This file contains the IR Sensor Header
 Notes			: 
 ============================================================================
 */
 
#ifndef IR_H_
#define IR_H_
#include "GPIO.h"
#include "stdbool.h"
#include "Motor.h"
#include "string.h"
extern uint8_t IR ;
extern uint8_t left_IR;
extern uint8_t right_IR;
#define WHITE   0
#define BLACK   1
#define LANE1   1
#define LANE2   2
#define lINE_Error  3 

/* Function Name: IR_init
 * Inputs:        Nothing
 * Returns:       void
 * Description:   Initializes the Infrared (IR) sensor system
 * */
void IR_init(void);

/* Function Name: LaneDetector_R
 * Inputs:        Nothing
 * Returns:       uint8_t
 * Description:   Detects the right lane and returns its status
 * */
uint8_t LaneDetector_R(void);

/* Function Name: LaneDetector_L
 * Inputs:        Nothing
 * Returns:       uint8_t
 * Description:   Detects the left lane and returns its status
 * */
uint8_t LaneDetector_L(void);

/* Function Name: LaneKeepingSystem
 * Inputs:        Nothing
 * Returns:       void
 * Description:   Manages the lane keeping system to ensure the vehicle stays in its lane
 * */
void LaneKeepingSystem(void);

/* Function Name: getLaneNumber
 * Inputs:        const char *laneString - String representation of the lane
 * Returns:       int
 * Description:   Converts a lane string to a lane number
 * */
int getLaneNumber(const char *laneString);

/* Function Name: changeLane
 * Inputs:        uint8_t targetLane - The lane to switch to
 * Returns:       void
 * Description:   Changes the vehicle's lane to the specified target lane
 * */
void changeLane(uint8_t targetLane);

/* Function Name: lanedetect
 * Inputs:        Nothing
 * Returns:       uint8_t
 * Description:   Detects the current lane and returns its status
 * */
uint8_t lanedetect(void);

/* Function Name: lanedetect_same
 * Inputs:        uint8_t lane - The lane to compare against
 * Returns:       bool
 * Description:   Checks if the current lane is the same as the specified lane
 * */
bool lanedetect_same(uint8_t lane);




#endif /* IR_H_ */
