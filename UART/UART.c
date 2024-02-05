#include "UART.h"
#include "../BITMATH.h"
#include "../tm4c123gh6pm.h"
#include "../Type.h"

void UART_INIT (uint08_t UART_n) {
    uint32_t delay;
    /* Baudrate 115200 , Stop 1 , No Paritiy , 8 Bits Data , 16 MHz*/
    switch (UART_n)
    {
        case UART_0:
            SET_BIT(SYSCTL_RCGCUART_R, 0); // Enable the UART module using the RCGCUART register (UART 0)
            SET_BIT(SYSCTL_RCGCGPIO_R, 0); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT A)
            /*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
            SET_BIT(GPIO_PORTA_AFSEL_R, 0); // Configure the GPIO by setting the AFSEL bit (PORT A pin 0)
            SET_BIT(GPIO_PORTA_AFSEL_R, 1); // Configure the GPIO by setting the AFSEL bit (PORT A pin 1)
            
            GPIO_PORTA_PCTL_R = (GPIO_PORTA_PCTL_R & 0xFFFFFF00) + 0x00000011; // Configure the PMCn fields in the GPIOPCTL register (0x1 for each pin to enable UART)
            /*Disable Analog Mode*/
			GPIO_PORTA_AMSEL_R = 0x00;

            /*PINA0 input and enabled*/
			CLR_BIT(GPIO_PORTA_DIR_R,0);
			SET_BIT(GPIO_PORTA_DEN_R,0);
			/*PINA1 output and enabled*/
			SET_BIT(GPIO_PORTA_DIR_R,1);
			SET_BIT(GPIO_PORTA_DEN_R,1);

			CLR_BIT(UART0_CTL_R,0); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
            /*Baud rate*/
			UART0_IBRD_R =8;    //16000000/(16*115200) = 8.6805 Write the integer portion of the BRD to the UARTIBRD register
			UART0_FBRD_R =44;    // 0.6805*64 + 0.5 = 44.05 Write the fractional portion of the BRD to the UARTFBRD register.
            /*1 STOP bit*/
			CLR_BIT(UART0_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART0_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART0_LCRH_R,5);
			SET_BIT(UART0_LCRH_R,6);
			// UART0_LCRH_R |= 0x00000038 -> 1 Stop bit - Enable FIFO - 8 bit Data. (111000) 0-5 bits.
			UART0_CTL_R = 0x0000; // Enable the UART by setting the UARTEN bit in the UARTCTL
            UART0_IM_R |= 0x10;  // Enable receive interrupt
            SET_BIT(NVIC_EN0_R, 5);  // Enable interrupt for UART0
            SET_BIT(UART0_CTL_R, 0); // Enable UART
            SET_BIT(UART0_CTL_R, 8); // Enable TX
            SET_BIT(UART0_CTL_R, 9); // Enable RX
            // Enable UART0 interrupts globally
            
            break;
        case UART_1:
            SET_BIT(SYSCTL_RCGCUART_R, 1); // Enable the UART module using the RCGCUART register (UART 1)
            SET_BIT(SYSCTL_RCGCGPIO_R, 1); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT B)
            /*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
            SET_BIT(GPIO_PORTB_AFSEL_R, 0); // Configure the GPIO by setting the AFSEL bit (PORT B pin 0)
            SET_BIT(GPIO_PORTB_AFSEL_R, 1); // Configure the GPIO by setting the AFSEL bit (PORT B pin 1)
            
            GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0xFFFFFF00) + 0x00000011; // Configure the PMCn fields in the GPIOPCTL register (0x1 for each pin to enable UART)
            /*Disable Analog Mode*/
			GPIO_PORTB_AMSEL_R = 0x00;

            /*PINB0 input and enabled*/
			CLR_BIT(GPIO_PORTB_DIR_R,0);
			SET_BIT(GPIO_PORTB_DEN_R,0);
			/*PINB1 output and enabled*/
			SET_BIT(GPIO_PORTB_DIR_R,1);
			SET_BIT(GPIO_PORTB_DEN_R,1);

			CLR_BIT(UART1_CTL_R,0); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
            /*Baud rate*/
			UART1_IBRD_R =8;    
			UART1_FBRD_R =44;   
            /*1 STOP bit*/
			CLR_BIT(UART1_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART1_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART1_LCRH_R,5);
			SET_BIT(UART1_LCRH_R,6);
			// UART1_LCRH_R |= 0x00000038 -> 1 Stop bit - Enable FIFO - 8 bit Data. (111000) 0-5 bits.
			UART1_CTL_R = 0x0000; // Enable the UART by setting the UARTEN bit in the UARTCTL
            UART1_IM_R |= 0x10;  // Enable receive interrupt
            SET_BIT(NVIC_EN0_R, 6);  // Enable interrupt for UART1
            SET_BIT(UART1_CTL_R, 0); // Enable UART
            SET_BIT(UART1_CTL_R, 8); // Enable TX
            SET_BIT(UART1_CTL_R, 9); // Enable RX
            break;
        case UART_2:
            SET_BIT(SYSCTL_RCGCUART_R, 2); // Enable the UART module using the RCGCUART register (UART 2)
            SET_BIT(SYSCTL_RCGCGPIO_R, 3); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT D)
            /*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
            SET_BIT(GPIO_PORTD_AFSEL_R, 6); // Configure the GPIO by setting the AFSEL bit (PORT D pin 6) - RX
            SET_BIT(GPIO_PORTD_AFSEL_R, 7); // Configure the GPIO by setting the AFSEL bit (PORT D pin 7) - TX
            
            GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0x00FFFFFF)+0x11000000; // Configure the PMCn fields in the GPIOPCTL register (0x1 for each pin to enable UART)
            /*Disable Analog Mode*/
			GPIO_PORTD_AMSEL_R = 0x00;

            /*PIND6 input and enabled*/
			CLR_BIT(GPIO_PORTD_DIR_R,6);
			SET_BIT(GPIO_PORTD_DEN_R,6);
			/*PIND7 output and enabled*/
			SET_BIT(GPIO_PORTD_DIR_R,7);
			SET_BIT(GPIO_PORTD_DEN_R,7);

			CLR_BIT(UART2_CTL_R,0); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
            /*Baud rate*/
			UART2_IBRD_R =8;   
			UART2_FBRD_R =44;  
            /*1 STOP bit*/
			CLR_BIT(UART2_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART2_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART2_LCRH_R,5);
			SET_BIT(UART2_LCRH_R,6);
			// UART2_LCRH_R |= 0x00000038 -> 1 Stop bit - Enable FIFO - 8 bit Data. (111000) 0-5 bits.
			UART2_CTL_R = 0x0000; // Enable the UART by setting the UARTEN bit in the UARTCTL
            UART2_IM_R |= 0x10;  // Enable receive interrupt
            SET_BIT(NVIC_EN0_R, 7);  // Enable interrupt for UART2
            SET_BIT(UART2_CTL_R, 0); // Enable UART
            SET_BIT(UART2_CTL_R, 8); // Enable TX
            SET_BIT(UART2_CTL_R, 9); // Enable RX
            break;
        case UART_3:
            SET_BIT(SYSCTL_RCGCUART_R, 3); // Enable the UART module using the RCGCUART register (UART 3)
            SET_BIT(SYSCTL_RCGCGPIO_R, 2); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT C)
            /*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
            SET_BIT(GPIO_PORTC_AFSEL_R, 6); // Configure the GPIO by setting the AFSEL bit (PORT C pin 6) - RX
            SET_BIT(GPIO_PORTC_AFSEL_R, 7); // Configure the GPIO by setting the AFSEL bit (PORT C pin 7) - TX
            
            GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0x00FFFFFF)+0x11000000; // Configure the PMCn fields in the GPIOPCTL register (0x1 for each pin to enable UART)
            /*Disable Analog Mode*/
			GPIO_PORTC_AMSEL_R = 0x00;

            /*PINC6 input and enabled*/
			CLR_BIT(GPIO_PORTC_DIR_R,6);
			SET_BIT(GPIO_PORTC_DEN_R,6);
			/*PINC7 output and enabled*/
			SET_BIT(GPIO_PORTC_DIR_R,7);
			SET_BIT(GPIO_PORTC_DEN_R,7);

			CLR_BIT(UART3_CTL_R,0); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
            /*Baud rate*/
			UART3_IBRD_R =8;
			UART3_FBRD_R =44;
            /*1 STOP bit*/
			CLR_BIT(UART3_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART3_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART3_LCRH_R,5);
			SET_BIT(UART3_LCRH_R,6);
			// UART3_LCRH_R |= 0x00000038 -> 1 Stop bit - Enable FIFO - 8 bit Data. (111000) 0-5 bits.
			UART3_CTL_R = 0x0000; // Enable the UART by setting the UARTEN bit in the UARTCTL
            UART3_IM_R |= 0x10;  // Enable receive interrupt
            SET_BIT(NVIC_EN0_R, 8);  // Enable interrupt for UART3
            SET_BIT(UART3_CTL_R, 0); // Enable UART
            SET_BIT(UART3_CTL_R, 8); // Enable TX
            SET_BIT(UART3_CTL_R, 9); // Enable RX
            break;
        case UART_4:
            SET_BIT(SYSCTL_RCGCUART_R, 4); // Enable the UART module using the RCGCUART register (UART 4)
            SET_BIT(SYSCTL_RCGCGPIO_R, 2); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT C)
            /*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
            SET_BIT(GPIO_PORTC_AFSEL_R, 4); // Configure the GPIO by setting the AFSEL bit (PORT C pin 4) - RX
            SET_BIT(GPIO_PORTC_AFSEL_R, 5); // Configure the GPIO by setting the AFSEL bit (PORT C pin 5) - TX
            
            GPIO_PORTC_PCTL_R = (GPIO_PORTC_PCTL_R&0xFF00FFFF)+0x00110000; // Configure the PMCn fields in the GPIOPCTL register (0x1 for each pin to enable UART)
            /*Disable Analog Mode*/
			GPIO_PORTC_AMSEL_R = 0x00;

            /*PINC4 input and enabled*/
			CLR_BIT(GPIO_PORTC_DIR_R,4);
			SET_BIT(GPIO_PORTC_DEN_R,4);
			/*PINC5 output and enabled*/
			SET_BIT(GPIO_PORTC_DIR_R,5);
			SET_BIT(GPIO_PORTC_DEN_R,5);

			CLR_BIT(UART4_CTL_R,0); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
            /*Baud rate*/
			UART4_IBRD_R =8;
			UART4_FBRD_R =44;
            /*1 STOP bit*/
			CLR_BIT(UART4_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART4_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART4_LCRH_R,5);
			SET_BIT(UART4_LCRH_R,6);
			// UART4_LCRH_R |= 0x00000038 -> 1 Stop bit - Enable FIFO - 8 bit Data. (111000) 0-5 bits.
			UART4_CTL_R = 0x0000; // Enable the UART by setting the UARTEN bit in the UARTCTL
            UART4_IM_R |= 0x10;  // Enable receive interrupt
            SET_BIT(NVIC_EN0_R, 9);  // Enable interrupt for UART4
            SET_BIT(UART4_CTL_R, 0); // Enable UART
            SET_BIT(UART4_CTL_R, 8); // Enable TX
            SET_BIT(UART4_CTL_R, 9); // Enable RX
            break;
        case UART_5:
            SET_BIT(SYSCTL_RCGCUART_R, 5); // Enable the UART module using the RCGCUART register (UART 5)
            SET_BIT(SYSCTL_RCGCGPIO_R, 4); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT E)
            /*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
            SET_BIT(GPIO_PORTE_AFSEL_R, 4); // Configure the GPIO by setting the AFSEL bit (PORT E pin 4) - RX
            SET_BIT(GPIO_PORTE_AFSEL_R, 5); // Configure the GPIO by setting the AFSEL bit (PORT E pin 5) - TX
            
            GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFF00FFFF)+0x00110000; // Configure the PMCn fields in the GPIOPCTL register (0x1 for each pin to enable UART)
            /*Disable Analog Mode*/
			GPIO_PORTE_AMSEL_R = 0x00;

            /*PINE4 input and enabled*/
			CLR_BIT(GPIO_PORTE_DIR_R,4);
			SET_BIT(GPIO_PORTE_DEN_R,4);
			/*PINE5 output and enabled*/
			SET_BIT(GPIO_PORTE_DIR_R,5);
			SET_BIT(GPIO_PORTE_DEN_R,5);

			CLR_BIT(UART5_CTL_R,0); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
            /*Baud rate*/
			UART5_IBRD_R =8;
			UART5_FBRD_R =44;
            /*1 STOP bit*/
			CLR_BIT(UART5_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART5_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART5_LCRH_R,5);
			SET_BIT(UART5_LCRH_R,6);
			// UART5_LCRH_R |= 0x00000038 -> 1 Stop bit - Enable FIFO - 8 bit Data. (111000) 0-5 bits.
			UART5_CTL_R = 0x0000; // Enable the UART by setting the UARTEN bit in the UARTCTL
            UART5_IM_R |= 0x10;  // Enable receive interrupt
            SET_BIT(NVIC_EN0_R, 10);  // Enable interrupt for UART5
            SET_BIT(UART5_CTL_R, 0); // Enable UART
            SET_BIT(UART5_CTL_R, 8); // Enable TX
            SET_BIT(UART5_CTL_R, 9); // Enable RX
            break;
        case UART_6:
            SET_BIT(SYSCTL_RCGCUART_R, 6); // Enable the UART module using the RCGCUART register (UART 6)
            SET_BIT(SYSCTL_RCGCGPIO_R, 3); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT D)
            /*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
            SET_BIT(GPIO_PORTD_AFSEL_R, 4); // Configure the GPIO by setting the AFSEL bit (PORT D pin 4) - RX
            SET_BIT(GPIO_PORTD_AFSEL_R, 5); // Configure the GPIO by setting the AFSEL bit (PORT D pin 5) - TX
            
            GPIO_PORTD_PCTL_R = (GPIO_PORTD_PCTL_R&0xFF00FFFF)+0x00110000; // Configure the PMCn fields in the GPIOPCTL register (0x1 for each pin to enable UART)
            /*Disable Analog Mode*/
			GPIO_PORTD_AMSEL_R = 0x00;

            /*PIND4 input and enabled*/
			CLR_BIT(GPIO_PORTD_DIR_R,4);
			SET_BIT(GPIO_PORTD_DEN_R,4);
			/*PIND5 output and enabled*/
			SET_BIT(GPIO_PORTD_DIR_R,5);
			SET_BIT(GPIO_PORTD_DEN_R,5);

			CLR_BIT(UART6_CTL_R,0); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
            /*Baud rate*/
			UART6_IBRD_R =8;
			UART6_FBRD_R =44;
            /*1 STOP bit*/
			CLR_BIT(UART6_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART6_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART6_LCRH_R,5);
			SET_BIT(UART6_LCRH_R,6);
			// UART6_LCRH_R |= 0x00000038 -> 1 Stop bit - Enable FIFO - 8 bit Data. (111000) 0-5 bits.
			UART6_CTL_R = 0x0000; // Enable the UART by setting the UARTEN bit in the UARTCTL
            UART6_IM_R |= 0x10;  // Enable receive interrupt
            SET_BIT(NVIC_EN0_R, 24);  // Enable interrupt for UART6
            SET_BIT(UART6_CTL_R, 0); // Enable UART
            SET_BIT(UART6_CTL_R, 8); // Enable TX
            SET_BIT(UART6_CTL_R, 9); // Enable RX
            break;
        case UART_7:
            SET_BIT(SYSCTL_RCGCUART_R, 7); // Enable the UART module using the RCGCUART register (UART 7)
            SET_BIT(SYSCTL_RCGCGPIO_R, 4); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT E)
            /*Wait to ensure that clock had been enabled*/
			(void)(delay = 1);
            SET_BIT(GPIO_PORTE_AFSEL_R, 0); // Configure the GPIO by setting the AFSEL bit (PORT E pin 0) - RX
            SET_BIT(GPIO_PORTE_AFSEL_R, 1); // Configure the GPIO by setting the AFSEL bit (PORT E pin 1) - TX
            
            GPIO_PORTE_PCTL_R = (GPIO_PORTE_PCTL_R&0xFFFFFF00)+0x00000011; // Configure the PMCn fields in the GPIOPCTL register (0x1 for each pin to enable UART)
            /*Disable Analog Mode*/
			GPIO_PORTE_AMSEL_R = 0x00;

            /*PINE0 input and enabled*/
			CLR_BIT(GPIO_PORTE_DIR_R,0);
			SET_BIT(GPIO_PORTE_DEN_R,0);
			/*PINE1 output and enabled*/
			SET_BIT(GPIO_PORTE_DIR_R,1);
			SET_BIT(GPIO_PORTE_DEN_R,1);

			CLR_BIT(UART7_CTL_R,0); // Disable the UART by clearing the UARTEN bit in the UARTCTL register.
            /*Baud rate*/
			UART7_IBRD_R =8;
			UART7_FBRD_R =44;
            /*1 STOP bit*/
			CLR_BIT(UART7_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART7_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART7_LCRH_R,5);
			SET_BIT(UART7_LCRH_R,6);
			// UART7_LCRH_R |= 0x00000038 -> 1 Stop bit - Enable FIFO - 8 bit Data. (111000) 0-5 bits.
			UART7_CTL_R = 0x0000; // Enable the UART by setting the UARTEN bit in the UARTCTL
            UART7_IM_R |= 0x10;  // Enable receive interrupt
            SET_BIT(NVIC_EN0_R, 25);  // Enable interrupt for UART7
            SET_BIT(UART7_CTL_R, 0); // Enable UART
            SET_BIT(UART7_CTL_R, 8); // Enable TX
            SET_BIT(UART7_CTL_R, 9); // Enable RX
            break;
    }
}

void UART_TX (uint08_t byte, uint08_t UART_n) {
    switch (UART_n) {
        case UART_0:
            while(GET_BIT(UART0_FR_R,5)==1); // Wait for TXFF
			UART0_DR_R = byte;
            break;
        case UART_1:
            while(GET_BIT(UART1_FR_R,5)==1); // Wait for TXFF
			UART1_DR_R = byte;
            break;
        case UART_2:
            while(GET_BIT(UART2_FR_R,5)==1); // Wait for TXFF
			UART2_DR_R = byte;
            break;
        case UART_3:
            while(GET_BIT(UART3_FR_R,5)==1); // Wait for TXFF
			UART3_DR_R = byte;
            break;
        case UART_4:
            while(GET_BIT(UART4_FR_R,5)==1); // Wait for TXFF
			UART4_DR_R = byte;
            break;
        case UART_5:
            while(GET_BIT(UART5_FR_R,5)==1); // Wait for TXFF
			UART5_DR_R = byte;
            break;
        case UART_6:
            while(GET_BIT(UART6_FR_R,5)==1); // Wait for TXFF
			UART6_DR_R = byte;
            break;
        case UART_7:
            while(GET_BIT(UART7_FR_R,5)==1); // Wait for TXFF
			UART7_DR_R = byte;
            break;
    }
}

void UART_RX (uint08_t * bytePtr, uint08_t UART_n) {
    switch (UART_n) {
        case UART_0:
            CLR_BIT(UART0_ICR_R, 5); // Clear Receive interrupt
            while(GET_BIT(UART0_FR_R,4)==0); // Wait for RXFE
			* bytePtr = UART0_DR_R;
        case UART_1:
            CLR_BIT(UART1_ICR_R, 5); // Clear Receive interrupt
            while(GET_BIT(UART1_FR_R,4)==0); // Wait for RXFE
			* bytePtr = UART1_DR_R;
        case UART_2:
            CLR_BIT(UART2_ICR_R, 5); // Clear Receive interrupt
            while(GET_BIT(UART2_FR_R,4)==0); // Wait for RXFE
			* bytePtr = UART2_DR_R;
        case UART_3:
            CLR_BIT(UART3_ICR_R, 5); // Clear Receive interrupt
            while(GET_BIT(UART3_FR_R,4)==0); // Wait for RXFE
			* bytePtr = UART3_DR_R;
        case UART_4:
            CLR_BIT(UART4_ICR_R, 5); // Clear Receive interrupt
            while(GET_BIT(UART4_FR_R,4)==0); // Wait for RXFE
			* bytePtr = UART4_DR_R;
        case UART_5:
            CLR_BIT(UART5_ICR_R, 5); // Clear Receive interrupt
            while(GET_BIT(UART5_FR_R,4)==0); // Wait for RXFE
			* bytePtr = UART5_DR_R;
        case UART_6:
            CLR_BIT(UART6_ICR_R, 5); // Clear Receive interrupt
            while(GET_BIT(UART6_FR_R,4)==0); // Wait for RXFE
			* bytePtr = UART6_DR_R;
        case UART_7:
            CLR_BIT(UART7_ICR_R, 5); // Clear Receive interrupt
            while(GET_BIT(UART7_FR_R,4)==0); // Wait for RXFE
			* bytePtr = UART7_DR_R;
    }
}