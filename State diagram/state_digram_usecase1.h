#ifndef _state_digram_usecase2_H_
#define	_state_digram_usecase2_H_
#include <stdbool.h>
#include <stdint.h>
#define DISTANCE_THRESHOLD 50  // Example distance threshold
#define DISTANCE_LESS      10  // Example distance threshold

// Define states
typedef enum {
    NormalState,
    CAR_BREAKING,
    SHOW_WARNING,
    IGNORE_WARNING,
    SWITCHLANESTATE
} State;

// Function declarations

/* Function Name: Normalstate
 * Inputs:        None
 * Returns:       void 
 * Description:   Function representing the "Normal" state
 */
void Normalstate(void);

/* Function Name: readBluetoothData
 * Inputs:        None
 * Returns:       uint8_t 
 * Description:   Function to read data from Bluetooth
 */
uint8_t readBluetoothData(void);

/* Function Name: controlCar
 * Inputs:        uint8_t data
 * Returns:       void 
 * Description:   Function to control the car based on received data
 */
void controlCar(uint8_t data);

/* Function Name: ignoreWarningState
 * Inputs:        None
 * Returns:       void 
 * Description:   Function representing the "Ignore Warning" state
 */
void ignoreWarningState(void);

/* Function Name: Car_Breaking
 * Inputs:        None
 * Returns:       void 
 * Description:   Function representing the "Car Breaking" state
 */
void Car_Breaking(void);

/* Function Name: show_warning
 * Inputs:        None
 * Returns:       void 
 * Description:   Function representing the "Show Warning" state
 */
void show_warning(void);

/* Function Name: SlowState
 * Inputs:        None
 * Returns:       void 
 * Description:   Function representing the "Slow" state
 */
void SlowState(void);

/* Function Name: stateTransition
 * Inputs:        State currentState
 * Returns:       void 
 * Description:   Function to handle state transitions
 */
void stateTransition(State currentState);

/* Function Name: StopState
 * Inputs:        None
 * Returns:       void 
 * Description:   Function representing the "Stop" state
 */
void StopState(void);

/* Function Name: stateTransition1
 * Inputs:        State Statechange
 * Returns:       void 
 * Description:   Function to handle state transitions (alternative version)
 */
void stateTransition1(State Statechange);

/* Function Name: SwitchLaneState
 * Inputs:        None
 * Returns:       void 
 * Description:   Function representing the "Switch Lane" state
 */
void SwitchLaneState(void);

#endif
