/*
 ============================================================================
 File Name: state.h
 Author      : Ahmed Emad Hassan
 Version     : 1.0
 Date        : 26/11/2023
 Description : This file contains state functions generators and connections headers
 Notes       : Include it when you want to define states
 ============================================================================
 */

#ifndef STATE_H_
#define STATE_H_

/* State creation functions */

    /* defines new state function (function prototype)*/
//#define STATE_define(_stateFunc_)	void ST_##_stateFunc_()
    /* get the address of the state function created */
//#define STATE(_stateFunc_)			ST_##_stateFunc_

/* state connections */
/* Here write the connection functions prototype between two modules */
void RWIFI_sendData(int local_data);
void Controller_print_warning_state(int local_warning_state);
#endif /* STATE_H_ */
