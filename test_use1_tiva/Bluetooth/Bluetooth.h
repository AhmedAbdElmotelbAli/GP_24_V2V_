/*
 ============================================================================
 File Name		: Bluetooth.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of Bluetooth Driver
 Notes			: 
 ============================================================================
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
#include "tm4c123gh6pm.h"
#include "Type.h"
#include "Lcd.h"
#include "UART.h"
#include "Motor.h"
#include "UltraSonic.h"
//#define uart_use  UART_5

void Delay(unsigned long counter); // used to add delay
void Bluetooth_Voidinit(void); // Initialize UART5 module for HC-05
uint08_t Bluetooth_U8Read(void); //Read data from Rx5 pin of tm4C123GH6pm
void Bluetooth_VoidWrite(unsigned char data); // Transmit a character to HC-05 over Tx5 pin
void Bluetooth_VoidWriteString(char *str); // Transmit a string to HC-05 over Tx5 pin
void Bluetooth_VoidControl(char data);
#endif /* BLUETOOTH_H_ */
