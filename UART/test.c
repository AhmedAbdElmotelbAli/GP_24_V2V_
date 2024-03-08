#include "UART.h"
#include "../BITMATH.h"
#include "../tm4c123gh6pm.h"

/* Testing UART 0 module communication using PuTTY and LED */
char UART0_Receiver(void);
void LEDInit(void);
void UART0_Handler(void);
void UART0_Handler(void) {
    uint08_t data;
    // Check if the interrupt is due to RX
    //if(UART0_MIS_R & UART_MIS_RXMIS) {
    // RX interrupt handling
    // UART_RX(&data, UART_0); // Read the received character from UART0
    // Your RX handling code here
    data = UART0_DR_R;
    //UART0_ICR_R &= ~(0x010); // Clear receive interrupt
    if(data == 'R'){
        // Turn on Red LED (PF1)
        GPIO_PORTF_DATA_R |= (1 << 1);
        // Turn off Blue, Green LED (PF2)
        GPIO_PORTF_DATA_R &= ~(1 << 2);
        GPIO_PORTF_DATA_R &= ~(1 << 3);
        //UART_String_TX("ENTER CHAR: \n", UART_0);
        
    }
    else if(data == 'G'){
        GPIO_PORTF_DATA_R |= (1 << 3);
        // Turn off Red, Blue LEDs (PF1 and PF2)
        GPIO_PORTF_DATA_R &= ~(1 << 1);
        GPIO_PORTF_DATA_R &= ~(1 << 2);
        //UART_String_TX("ENTER CHAR: \n", UART_0);
    }
    else if(data == 'B') {
        // Turn on Blue LED (PF2)
        GPIO_PORTF_DATA_R |= (1 << 2);
        // Turn off Red, Green LED (PF1)
        GPIO_PORTF_DATA_R &= ~(1 << 1);
        GPIO_PORTF_DATA_R &= ~(1 << 3);
        //UART_String_TX("ENTER CHAR: \n", UART_0);
    }
    //}

    // Check if the interrupt is due to TX
    //if(UART0_MIS_R & UART_MIS_TXMIS) {
    // TX interrupt handling
    // Your TX handling code here
    //UART_TX (data, UART_0);
    //GPIO_PORTF_DATA_R = 0x02;
    //UARTIntEnable(UART_TX_INT, UART_0);
    //}

    // Clear the interrupt flags
    //UART0_ICR_R &= ~ (UART_ICR_RXIC | UART_ICR_TXIC);
    UART0_ICR_R &= ~(0x010); // Clear receive interrupt
}

int main(void) {
	UART_INIT(UART_0);
	UARTNVICEn(UART_0);
	UARTIntEnable(UART_0, UART_RX_INT);
	UARTIntEnable(UART_0, UART_TX_INT);
	
	LEDInit();
	// Turn on White LED (PF3)
	GPIO_PORTF_DATA_R |= (1 << 1) | (1 << 2) | (1 << 3);
	UART_String_TX("ENTER CHAR: \n", UART_0);
	while (1) {
	}
}
void LEDInit(void) {
    // Enable clock for GPIO Port F
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R5;

    // Set PF1 and PF2 and PF3 as output pins
    GPIO_PORTF_DIR_R |= (1 << 1) | (1 << 2) | (1 << 3);

    // Enable digital function for PF1 and PF2 and PF3
    GPIO_PORTF_DEN_R |= (1 << 1) | (1 << 2) | (1 << 3);
}
