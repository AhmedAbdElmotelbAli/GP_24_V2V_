#ifndef _UART_H_
#define _UART_H_
#include "../Type.h"

// UART typedef, usage: UART_n UART_0. Send UART_0 as an argument to functions.
typedef enum {
    UART_0,
    UART_1,
    UART_2,
    UART_3,
    UART_4,
    UART_5,
    UART_6,
    UART_7
} UART_n; 

// UART Interrupts typedef, usage UART_INT UART_RX_INT. Send UART_RX/TX_INT as an argument to UARTIntEnable/Disable.
typedef enum {
    UART_RX_INT,
    UART_TX_INT
} UART_INT;

/* 
UART Initialization function. Takes UART_n as an argument and initializes UART according to the passed module.
Baudrate 9600 , Stop 1 , No Paritiy , 8 Bits Data , 16 MHz, No Interrupts (Interrupts are enabled using UARTIntEnable Function)
*/
void UART_INIT (uint08_t UART_n); 

// UART Transmit Function. Transmits one byte through the passed UART module. Needs UART initialization before usage.
void UART_TX (uint08_t byte, uint08_t UART_n);

/* 
UART Receive Function. 
Receives one byte through the passed UART module and stores it in the location pointed to by the bytePtr argument. 
Needs UART initialization before usage. 
*/
void UART_RX (uint08_t * bytePtr, uint08_t UART_n);

/*
UART Interrupt Enable Function
Enables Interrupts (Receive or Transmit) For a the passed UART module. 
Has 2 arguments: UART_n for the passed UART module and UART_INT (Indicates whether it's Receive or transmit interrupt).
Needs UART initialization before usage
*/
void UARTIntEnable(uint08_t UART_n, uint08_t UART_INT);

/*
UART Interrupt Disable Function
Disables Interrupts (Receive or Transmit) For a the passed UART module. 
Has 2 arguments: UART_n for the passed UART module and UART_INT (Indicates whether it's Receive or transmit interrupt).
Needs UART initialization before usage
*/
void UARTIntDisable(uint08_t UART_n, uint08_t UART_INT);

/*
UART Transmit String Function
Transmits a string byte by byte through the passed UART module. Send the address, length of the string, and UART module as arguments.
Needs UART Initialization before usage.
*/
void UART_String_TX(char *str, uint08_t UART_n);

void Delay(unsigned long counter);

#endif