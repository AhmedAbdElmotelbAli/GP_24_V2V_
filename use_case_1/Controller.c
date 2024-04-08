/*
 ============================================================================
 File Name:     Controller.c
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  Controller module
 Notes       :  Responsable for taking data from other modules and sending data to other modules
 ============================================================================
 */

/* include C liberaries to test*/

#include <stdint.h>
/* include the header file */
#include "Controller.h"
/* extern state pointer */
extern void (*Controller_state)();
/* private attributes */
static int32_t data = 0;
static int32_t warning_state = 0;
/* functions and states */
void RWIFI_sendData(int32_t local_data){
    data = local_data;
    switch (Controller_state_id)
    {
    case Controller_normal:
        if(local_data == 0){
            warning_state = 0;
            Controller_state = STATE(Controller_normal);
        }else if(local_data == 1){
            warning_state = 1;
            Controller_state = STATE(Controller_emergency);
        }else{
            /* Misra required */
        }
        break;
    case Controller_emergency:
        if(local_data == 0){
            warning_state = 0;
            Controller_state = STATE(Controller_normal);
        }else if(local_data == 1){
            warning_state = 1;
            Controller_state = STATE(Controller_emergency);
        }else{
            /* Misra required */
        }
        break;
    
    default:
        break;
    }
}
STATE_define(Controller_normal){
	
    /* state name */
    Controller_state_id = Controller_normal;
	/* state action */
    Controller_print_warning_state(warning_state);
    /* event check */
    Controller_state = STATE(Controller_normal);
}
STATE_define(Controller_emergency){
	
    /* state name */
    Controller_state_id = Controller_emergency;
	/* state action */
    Controller_print_warning_state(warning_state);
    /* event check */
    Controller_state = STATE(Controller_emergency);
}
