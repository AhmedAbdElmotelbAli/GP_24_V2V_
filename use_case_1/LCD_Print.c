/*
 ============================================================================
 File Name:     LCD_Print.c
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  LCD Print module
 Notes       :  responsable for printing warning messages at LCD
 ============================================================================
 */

/* include C liberaries to test*/

#include <stdint.h>
/* include the header file */
#include "LCD_Print.h"
/* extern state pointer */
extern void (*LCD_Print_state)();
/* private attributes */
static int32_t warning_state;
/* functions and states */
static void print_warning_state(int32_t local_state){
    if(local_state == 1){
        //print warning state
    }else if(local_state == 0){
        //don't print warning state
    }else{
        /* Misra Required */
    }
}
void Controller_print_warning_state(int32_t local_warning_state){
    /* setting attributes*/
    warning_state = local_warning_state;
    /* set new state */
    if(warning_state == 0){
        LCD_Print_state = ST_LCD_Print_normal;
    }else if(warning_state == 1){
        LCD_Print_state = ST_LCD_Print_warning;
    }else{
        /* Misra required */
    }
}
void ST_LCD_Print_normal(){
        /* state name */
        LCD_Print_state_id = LCD_Print_normal;
        /* state action */
        print_warning_state(warning_state);
        /* event check */
        LCD_Print_state = ST_LCD_Print_normal;
}
void ST_LCD_Print_warning(){
        /* state name */
        LCD_Print_state_id = LCD_Print_warning;
        /* state action */
        print_warning_state(warning_state);
        /* event check */
        LCD_Print_state = ST_LCD_Print_warning;
}
