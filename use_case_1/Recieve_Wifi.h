/*
 ============================================================================
 File Name:     Recieve_Wifi.h
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  Recieve WIFI module
 Notes       :  Responsable for recieving data from WIFI module
 ============================================================================
 */

/* start header guard */
#ifndef Recieve_Wifi_h_
#define Recieve_Wifi_h_
/* include state.h */
#include "state.h"
/* define state id enum variable */
enum{
    Recieve_Wifi_busy
}Recieve_Wifi_state_id;
/* initialization */
void Recieve_Wifi_Init();
/* other functions and state functions */
void ST_Recieve_Wifi_busy();
/* state pointer to function */
void (*Recieve_Wifi_state)();
/* end header guard */
#endif