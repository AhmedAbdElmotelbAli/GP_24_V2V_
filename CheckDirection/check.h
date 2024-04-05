/*
 ============================================================================
 File Name		: check.h
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of check Driver
 Notes			: 
 ============================================================================
 */

#ifndef _Check_H_
#define _Check_H_
#include "stdbool.h"
#include "RTE_Main.h"

extern char validCommands[];
bool checksaveDirection(void);
bool changeDirection(char command);
void delay_s(void);
void Delay_s(int x);
#endif
