/*
 ============================================================================
 File Name:     LCD_Print.h
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  LCD Print module
 Notes       :  responsable for printing warning messages at LCD
 ============================================================================
 */

/* start header guard */
#ifndef LCD_Print_H_
#define LCD_Print_H_
/* include state.h */
#include "state.h"
/* define state id enum variable */
enum{
    LCD_Print_normal,
    LCD_Print_warning
}LCD_Print_state_id;
/* initialization */
void Init();
/* other functions and state functions */
STATE_define(LCD_Print_normal);
STATE_define(LCD_Print_warning);
/* state pointer to function */
void (*LCD_Print_state)();
/* end header guard */
#endif