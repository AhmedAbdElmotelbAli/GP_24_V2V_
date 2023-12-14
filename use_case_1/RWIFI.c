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
#include "stdio.h"
#include "stdlib.h"
/* include the header file */
#include "RWIFI.h"
/* extern state pointer */
extern void (*RWIFI_state)();
/* private attributes */
static int data = 0;
/* functions and states */
STATE_define(RWIFI_busy){
    /* state name */
    RWIFI_state_id = RWIFI_busy;
    /* state action */
    printf("Please Enter The WIFI data: ");
    fflush(stdout);
    scanf("%d",&data);
    fflush(stdin);
    RWIFI_sendData(data);
    /* event check */
    RWIFI_state = STATE(RWIFI_busy);
}
