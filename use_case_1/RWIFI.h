/*
 ============================================================================
 File Name:     RWIFI.h
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  Recieve WIFI module
 Notes       :  Responsable for recieving data from WIFI module
 ============================================================================
 */

/* start header guard */
#ifndef RWIFI_h_
#define RWIFI_h_
/* include state.h */
#include "state.h"
/* define state id enum variable */
enum{
    RWIFI_busy
}RWIFI_state_id;
/* initialization */
void RWIFI_Init();
/* other functions and state functions */
STATE_define(RWIFI_busy);
/* state pointer to function */
void (*RWIFI_state)();
/* end header guard */
#endif