/*
 ============================================================================
 File Name:     C.h
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  Controller module
 Notes       :  Responsable for taking data from other modules and sending data to other modules
 ============================================================================
 */
/* start header guard */
#ifndef Controller_H_
#define Controller_H_
/* include state.h */
#include "state.h"
/* define state id enum variable */
enum{
    Controller_normal,
    Controller_emergency
}Controller_state_id;
/* initialization */
void Controller_Init();
/* other functions and state functions */
void ST_Controller_normal();
void ST_Controller_emergency();
/* state pointer to function */
void (*Controller_state)();
/* end header guard */
#endif
