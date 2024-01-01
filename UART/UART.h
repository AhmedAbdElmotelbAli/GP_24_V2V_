#ifndef _UART_H_
#define _UART_H_

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

void UART_INIT (uint08_t UART_n);
void UART_TX (uint08_t byte, uint08_t UART_n);
uint08_t UART_RX (uint08_t * bytePtr, uint08_t UART_n);

#endif