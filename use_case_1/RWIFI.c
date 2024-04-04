/*
 ============================================================================
 File Name:     RWIFI.c
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  Recieve WIFI module
 Notes       :  Responsable for recieving data from WIFI module
 ============================================================================
 */

/* include C liberaries to test*/

/* Include MCAL */
#include "../GPIO/GPIO.h"
/* Include HAL */
#include "../ON_BOARD_SWITCHS/ON_BOARD_SWITCHS.h"
/* include the header file */
#include "RWIFI.h"
/* extern state pointer */
extern void (*RWIFI_state)();
/* private attributes */
static int data = 0;
/* functions and states */
#if 0
typedef enum
{
	/* List the gpio pins */
	GPIO_STATE_LOW,
	GPIO_STATE_HIGH,

}GPIO_State_t;
#endif

void RWIFI_Read_Data(int* Pdata){
    /* Reading Button Data */
	GPIO_State_t local_button_state;
    local_button_state = SW1_State();
    if(local_button_state == GPIO_STATE_LOW){
        *Pdata = 0;
    }else if(local_button_state == GPIO_STATE_HIGH){
        *Pdata = 1;
    }else{
        /* shouldn't happen */
    }
}
STATE_define(RWIFI_busy){
    /* state name */
    RWIFI_state_id = RWIFI_busy;
    /* state action */
	RWIFI_Read_Data(&data);
    RWIFI_sendData(data);
    /* event check */
    RWIFI_state = STATE(RWIFI_busy);
}
