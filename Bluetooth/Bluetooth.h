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
#include <stdint.h>
#include "UART.h"
/* Function Name: Bluetooth_VoidInit
 * Inputs:        None
 * Returns:       void 
 * Pins :         PC4,PC5
 * Description:   Initializes UART5 module for HC-05.
 * */

void Bluetooth_Voidinit(void); // Initialize UART5 module for HC-05
/* Function Name: Bluetooth_U8Read
 * Inputs:        None
 * Returns:       uint8_t - Data read from Rx5 pin of tm4C123GH6pm
 * Pins :         PC4,PC5
 * Description:   Reads data from the Rx5 pin of tm4C123GH6pm.
 * */


uint8_t Bluetooth_U8Read(void); //Read data from Rx5 pin of tm4C123GH6pm
/* Function Name: Bluetooth_VoidWrite
 * Inputs:        data - Character to transmit
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:   Transmits a character to HC-05 over the Tx5 pin.
 * */

void Bluetooth_VoidWrite(unsigned char data); // Transmit a character to HC-05 over Tx5 pin
/* Function Name: Bluetooth_VoidWriteString
 * Inputs:        str - Pointer to the string to transmit
 * Returns:       void 
 * Pins :         PC4,PC5
 * Description:   Transmits a string to HC-05 over the Tx5 pin.
 * */
void Bluetooth_VoidWriteString(char *str); // Transmit a string to HC-05 over Tx5 pin
/* Function Name: Bluetooth_VoidControl
 * Inputs:        data - Data to control the DC MOTOR (Hbridge)
 * Returns:       void 
 * Pins :         PC4,PC5
 * Description:   Control function for the Bluetooth module. 
 *                This function enables various functionalities of the module 
 *                based on the input data.
 * */

void Bluetooth_VoidControl(char data);
#endif /* BLUETOOTH_H_ */
