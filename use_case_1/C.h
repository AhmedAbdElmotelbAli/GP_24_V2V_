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
#ifndef C_H_
#define C_H_
/* include state.h */
#include "state.h"
/* define state id enum variable */
enum{
    C_normal,
    C_emergency
}C_state_id;
/* initialization */
void C_Init();
/* other functions and state functions */
STATE_define(C_normal);
STATE_define(C_emergency);
/* state pointer to function */
void (*C_state)();
/* end header guard */
#endif
