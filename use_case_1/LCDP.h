/*
 ============================================================================
 File Name:     LCDP.h
 Author      :  Ahmed Emad Hassan
 Version     :  1.0
 Date        :  06/12/2023
 Description :  LCD Print module
 Notes       :  responsable for printing warning messages at LCD
 ============================================================================
 */

/* start header guard */
#ifndef LCDP_H_
#define LCDP_H_
/* include state.h */
#include "state.h"
/* define state id enum variable */
enum{
    LCDP_normal,
    LCDP_warning
}LCDP_state_id;
/* initialization */
void Init();
/* other functions and state functions */
STATE_define(LCDP_normal);
STATE_define(LCDP_warning);
/* state pointer to function */
void (*LCDP_state)();
/* end header guard */
#endif