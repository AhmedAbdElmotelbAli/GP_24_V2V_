/*
 ============================================================================
 File Name:     C.c
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  Controller module
 Notes       :  Responsable for taking data from other modules and sending data to other modules
 ============================================================================
 */

/* include C liberaries to test*/
#include "stdio.h"
#include "stdlib.h"
/* include the header file */
#include "c.h"
/* extern state pointer */
extern void (*C_state)();
/* private attributes */
static int data = 0;
static int warning_state = 0;
/* functions and states */
void RWIFI_sendData(int local_data){
    data = local_data;
    switch (C_state_id)
    {
    case C_normal:
        if(local_data == 0){
            warning_state = 0;
            C_state = STATE(C_normal);
        }else if(local_data == 1){
            warning_state = 1;
            C_state = STATE(C_emergency);
        } 
        break;
    case C_emergency:
        if(local_data == 0){
            warning_state = 0;
            C_state = STATE(C_normal);
        }else if(local_data == 1){
            warning_state = 1;
            C_state = STATE(C_emergency);
        } 
        break;
    
    default:
        break;
    }
}
STATE_define(C_normal){
	fflush(stdout);
    /* state name */
    C_state_id = C_normal;
	/* state action */
    C_print_warning_state(warning_state);
    /* event check */
    C_state = STATE(C_normal);
}
STATE_define(C_emergency){
	fflush(stdout);
    /* state name */
    C_state_id = C_emergency;
	/* state action */
    C_print_warning_state(warning_state);
    /* event check */
    C_state = STATE(C_emergency);
}
