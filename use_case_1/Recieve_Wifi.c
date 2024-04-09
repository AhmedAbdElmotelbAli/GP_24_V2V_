/*
 ============================================================================
 File Name:     Recieve_Wifi.c
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  Recieve WIFI module
 Notes       :  Responsable for recieving data from WIFI module
 ============================================================================
 */

/* include C liberaries to test*/
#include <stdint.h>
/* include the header file */
#include "Recieve_Wifi.h"
/* extern state pointer */
extern void (*Recieve_Wifi_state)();
/* private attributes */
static int32_t data = 0;
/* functions and states */
void Recieve_Wifi_Read_Data(int32_t* Pdata){
    if(!Pdata){
        //Recieve Data from Wifi Here
    }
}
void ST_Recieve_Wifi_busy(){
    /* state name */
    Recieve_Wifi_state_id = Recieve_Wifi_busy;
    /* state action */
	Recieve_Wifi_Read_Data(&data);
    Recieve_Wifi_sendData(data);
    /* event check */
    Recieve_Wifi_state = ST_Recieve_Wifi_busy;
}
