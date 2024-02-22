#ifndef _UART_H_
#define _UART_H_
#include "Type.h"
#define UART_RX_AVAILABLE           (0xAB)
#define UART_RX_UNAVAILABLE         (0xCD)

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

typedef enum {
    UART_RX_INT,
    UART_TX_INT
} UART_INT;

void UART_INIT (uint08_t UART_n);
void UART_TX (uint08_t byte, uint08_t UART_n);
void UART_RX (uint08_t * bytePtr, uint08_t UART_n);
void UARTIntEnable(uint08_t UART_n, uint08_t UART_INT);
void UARTIntDisable(uint08_t UART_n, uint08_t UART_INT);
void UART0_Handler(void);
void UART1_Handler(void);
void UART2_Handler(void);
void UART3_Handler(void);
void UART4_Handler(void);
void UART5_Handler(void);
void UART6_Handler(void);
void UART7_Handler(void);
void UartPrint(char *str,uint08_t UART_n);

#endif
