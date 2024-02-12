/*
 * Bluetooth.h
 *
 *  Created on: 9/2/2024
 *      Author: Ahmed Abdelmotelb Ali
 */
#include "Type.h"
#include "UART.h"
#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_
//#define uart_use  UART_5

void Delay(unsigned long counter); // used to add delay
void Bluetooth_init(void); // Initialize UART5 module for HC-05
uint08_t Bluetooth_Read(void); //Read data from Rx5 pin of tm4C123GH6pm
void Bluetooth_Write(unsigned char data); // Transmit a character to HC-05 over Tx5 pin
void Bluetooth_Write_String(char *str); // Transmit a string to HC-05 over Tx5 pin
void Bluetooth_Control(char data);
#endif /* BLUETOOTH_H_ */
