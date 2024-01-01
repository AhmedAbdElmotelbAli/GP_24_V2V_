/*
 ============================================================================
 File Name:     LCDP.c
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  LCD Print module
 Notes       :  responsable for printing warning messages at LCD
 ============================================================================
 */

/* include C liberaries to test*/

/* include MCAL */
#include "../GPIO/GPIO.h"
/* include HAL */
#include "../ON_BOARD_SWITCHS/ON_BOARD_SWITCHS.h"
#include "../LCD/Lcd.h"
#include "../RGB_LEDS/RGB_LEDS.h"
/* include the header file */
#include "LCDP.h"
/* extern state pointer */
extern void (*LCDP_state)();
/* private attributes */
static int warning_state;
/* functions and states */
static void print_warning_state(int local_state){
    if(local_state == 1){
        /* LCD: Warning The car is breaking */
        RGB_LEDS_State(LED_STATE_ON,LED_STATE_OFF,LED_STATE_OFF);
        LCD_clearScreen();
        LCD_moveCursorXY(0,0);
        LCD_displayString("Warning");
    }else if(local_state == 0){
        /* LCD: Nothing to print */
        RGB_LEDS_State(LED_STATE_OFF,LED_STATE_OFF,LED_STATE_OFF);
        LCD_clearScreen();
        LCD_moveCursorXY(0,0);
        LCD_displayString("");
    }else{
        /* Misra Required */
    }
}
void C_print_warning_state(int local_warning_state){
    /* setting attributes*/
    warning_state = local_warning_state;
    /* set new state */
    if(warning_state == 0){
        LCDP_state = STATE(LCDP_normal);
    }else if(warning_state == 1){
        LCDP_state = STATE(LCDP_warning);
    }else{
        /* Misra required */
    }
}
STATE_define(LCDP_normal){
        /* state name */
        LCDP_state_id = LCDP_normal;
        /* state action */
        print_warning_state(warning_state);
        /* event check */
        LCDP_state = STATE(LCDP_normal);
}
STATE_define(LCDP_warning){
        /* state name */
        LCDP_state_id = LCDP_warning;
        /* state action */
        print_warning_state(warning_state);
        /* event check */
        LCDP_state = STATE(LCDP_warning);
}
