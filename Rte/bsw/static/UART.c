#include "UART.h"
#include "BITMATH.h"
#include "tm4c123gh6pm.h"
#include "stdbool.h"


bool UART_is_available(uint8_t UART_n) {
  bool result=false;  
	switch (UART_n) {
			#if 0
        case UART_0:
            return (GET_BIT(UART0_FR_R, 4) == 0);
		break;
        case UART_1:
            return (GET_BIT(UART1_FR_R, 4) == 0);
				break;

        case UART_2:
            return (GET_BIT(UART2_FR_R, 4) == 0);
				break;

        case UART_3:
            return (GET_BIT(UART3_FR_R, 4) == 0);
				break;

				#endif
        case UART_4:
            result = ((UART5_FR_R&UART_FR_RXFE) == 0);
						break;

        case UART_5:
            result = (GET_BIT(UART5_FR_R, 4) == 0);
						break;

					#if 0
        case UART_6:
            return (GET_BIT(UART6_FR_R, 4) == 0);
						break;

        case UART_7:
            return (GET_BIT(UART7_FR_R, 4) == 0);
						break;

				#endif
				
        default:
            // Handle invalid UART number
          break;
    }
	return result;
}



void UART_INIT (uint8_t UART_n) {
    /* Baudrate 9600 , Stop 1 , No Paritiy , 8 Bits Data , 16 MHz*/
    switch (UART_n)  {
			#if 0
        case UART_0:
            SET_BIT(SYSCTL_RCGCUART_R, 0); // Enable the UART module using the RCGCUART register (UART 0)
            SET_BIT(SYSCTL_RCGCGPIO_R, 0); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT A)
            /*Wait to ensure that clock had been enabled*/
			Delay(10);
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
			UART0_IBRD_R = 104;    // Write the integer portion of the BRD to the UARTIBRD register
			UART0_FBRD_R = 11;    // Write the fractional portion of the BRD to the UARTFBRD register.
            /*1 STOP bit*/
			CLR_BIT(UART0_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART0_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART0_LCRH_R,5);
			SET_BIT(UART0_LCRH_R,6);
			
            SET_BIT(UART0_CTL_R, 0); // Enable UART
            SET_BIT(UART0_CTL_R, 8); // Enable TX
            SET_BIT(UART0_CTL_R, 9); // Enable RX
            break;

        case UART_1:
            SET_BIT(SYSCTL_RCGCUART_R, 1); // Enable the UART module using the RCGCUART register (UART 1)
            SET_BIT(SYSCTL_RCGCGPIO_R, 1); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT B)
            /*Wait to ensure that clock had been enabled*/
			Delay(10);
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
			UART1_IBRD_R = 104;    
			UART1_FBRD_R = 11;   
            /*1 STOP bit*/
			CLR_BIT(UART1_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART1_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART1_LCRH_R,5);
			SET_BIT(UART1_LCRH_R,6);
            SET_BIT(UART1_CTL_R, 0); 
            SET_BIT(UART1_CTL_R, 8); 
            SET_BIT(UART1_CTL_R, 9); 
            break;
        case UART_2:
            SET_BIT(SYSCTL_RCGCUART_R, 2); // Enable the UART module using the RCGCUART register (UART 2)
            SET_BIT(SYSCTL_RCGCGPIO_R, 3); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT D)
            /*Wait to ensure that clock had been enabled*/
			Delay(10);
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
			UART2_IBRD_R = 104;   
			UART2_FBRD_R = 11;
            /*1 STOP bit*/
			CLR_BIT(UART2_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART2_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART2_LCRH_R,5);
			SET_BIT(UART2_LCRH_R,6);
            SET_BIT(UART2_CTL_R, 0); 
            SET_BIT(UART2_CTL_R, 8); 
            SET_BIT(UART2_CTL_R, 9); 
            break;
	#endif

        case UART_3:
            SET_BIT(SYSCTL_RCGCUART_R, 3); // Enable the UART module using the RCGCUART register (UART 3)
            SET_BIT(SYSCTL_RCGCGPIO_R, 2); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT C)
            /*Wait to ensure that clock had been enabled*/
			Delay(10);
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
			UART3_IBRD_R = 104;
			UART3_FBRD_R = 11;
            /*1 STOP bit*/
			CLR_BIT(UART3_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART3_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART3_LCRH_R,5);
			SET_BIT(UART3_LCRH_R,6); 
            SET_BIT(UART3_CTL_R, 0); 
            SET_BIT(UART3_CTL_R, 8); 
            SET_BIT(UART3_CTL_R, 9); 
            break;

        case UART_4:
            SET_BIT(SYSCTL_RCGCUART_R, 4); // Enable the UART module using the RCGCUART register (UART 4)
            SET_BIT(SYSCTL_RCGCGPIO_R, 2); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT C)
            /*Wait to ensure that clock had been enabled*/
			Delay(10);
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
			UART4_IBRD_R = 104;
			UART4_FBRD_R = 11;
            /*1 STOP bit*/
			CLR_BIT(UART4_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART4_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART4_LCRH_R,5);
			SET_BIT(UART4_LCRH_R,6); 
            SET_BIT(UART4_CTL_R, 0); 
            SET_BIT(UART4_CTL_R, 8); 
            SET_BIT(UART4_CTL_R, 9); 
            break;

        case UART_5:
            SET_BIT(SYSCTL_RCGCUART_R, 5); // Enable the UART module using the RCGCUART register (UART 5)
            SET_BIT(SYSCTL_RCGCGPIO_R, 4); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT E)
            /*Wait to ensure that clock had been enabled*/
			Delay(10);
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
			UART5_IBRD_R = 104;
			UART5_FBRD_R = 11;
            /*1 STOP bit*/
			CLR_BIT(UART5_LCRH_R,3); // 111000
			/*FIFO enable*/
			CLR_BIT(UART5_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART5_LCRH_R,5);
			SET_BIT(UART5_LCRH_R,6);
            SET_BIT(UART5_CTL_R, 0); 
            SET_BIT(UART5_CTL_R, 8); 
            SET_BIT(UART5_CTL_R, 9); 
            break;
#if 0
        case UART_6:
            SET_BIT(SYSCTL_RCGCUART_R, 6); // Enable the UART module using the RCGCUART register (UART 6)
            SET_BIT(SYSCTL_RCGCGPIO_R, 3); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT D)
            /*Wait to ensure that clock had been enabled*/
			Delay(10);
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
			UART6_IBRD_R = 104;
			UART6_FBRD_R = 11;
            /*1 STOP bit*/
			CLR_BIT(UART6_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART6_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART6_LCRH_R,5);
			SET_BIT(UART6_LCRH_R,6);
            SET_BIT(UART6_CTL_R, 0); 
            SET_BIT(UART6_CTL_R, 8); 
            SET_BIT(UART6_CTL_R, 9); 
            break;

        case UART_7:
            SET_BIT(SYSCTL_RCGCUART_R, 7); // Enable the UART module using the RCGCUART register (UART 7)
            SET_BIT(SYSCTL_RCGCGPIO_R, 4); // Enable the clock to the appropriate GPIO module via the RCGCGPIO register (PORT E)
            /*Wait to ensure that clock had been enabled*/
			Delay(10);
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
			UART7_IBRD_R = 104;
			UART7_FBRD_R = 11;
            /*1 STOP bit*/
			CLR_BIT(UART7_LCRH_R,3); // 111000
			/*FIFO enable*/
			SET_BIT(UART7_LCRH_R,4);
			/*8 bit data*/
			SET_BIT(UART7_LCRH_R,5);
			SET_BIT(UART7_LCRH_R,6);
            SET_BIT(UART7_CTL_R, 0); 
            SET_BIT(UART7_CTL_R, 8); 
            SET_BIT(UART7_CTL_R, 9); 
            break;
						#endif
					 default:
            // Handle invalid UART number
                    break;
    }
}

void UART_TX (uint8_t byte, uint8_t UART_n) {
    switch (UART_n) {
			#if 0
       case UART_0:
            while(GET_BIT(UART0_FR_R,5)==1){} // Wait for TXFF
			UART0_DR_R = byte;
            break;
        case UART_1:
            while(GET_BIT(UART1_FR_R,5)==1){}
			UART1_DR_R = byte;
            break;
        case UART_2:
            while(GET_BIT(UART2_FR_R,5)==1){}
			UART2_DR_R = byte;
            break;
				#endif
		
        case UART_3:
            while(GET_BIT(UART3_FR_R,5)==1){}
			UART3_DR_R = byte;
            break;
        case UART_4:
            while(GET_BIT(UART4_FR_R,5)==1){}
			UART4_DR_R = byte;
            break;
        case UART_5:
            while(GET_BIT(UART5_FR_R,5)==1){}
			UART5_DR_R = byte;
            break;
				#if 0
        case UART_6:
            while(GET_BIT(UART6_FR_R,5)==1){}
			UART6_DR_R = byte;
            break;
        case UART_7:
            while(GET_BIT(UART7_FR_R,5)==1){}
			UART7_DR_R = byte;
            break;
				#endif
		  default:
            // Handle invalid UART number
			break;
    }
}

void UART_RX (uint8_t * bytePtr, uint8_t UART_n) {
    switch (UART_n) {
      #if 0
			case UART_0:
            while(GET_BIT(UART0_FR_R,4)==1){} // Wait for RXFE
			* bytePtr = UART0_DR_R;
            break;
        case UART_1: 
            while(GET_BIT(UART1_FR_R,4)==1){} // Wait for RXFE
			* bytePtr = UART1_DR_R;
            break;
        case UART_2: 
            while(GET_BIT(UART2_FR_R,4)==1){} // Wait for RXFE
			* bytePtr = UART2_DR_R;
            break;
#endif

        case UART_3: 
            while(GET_BIT(UART3_FR_R,4)==1){} // Wait for RXFE
			* bytePtr = UART3_DR_R;
            break;
        case UART_4: 
            while(GET_BIT(UART4_FR_R,4)==1){} // Wait for RXFE
			* bytePtr = UART4_DR_R;
            break;
        case UART_5: 
            while(GET_BIT(UART5_FR_R,4)==1){} // Wait for RXFE
			* bytePtr = UART5_DR_R;
            break;
				#if 0
        case UART_6: 
            while(GET_BIT(UART6_FR_R,4)==1){} // Wait for RXFE
			* bytePtr = UART6_DR_R;
            break;
        case UART_7: 
            while(GET_BIT(UART7_FR_R,4)==1){} // Wait for RXFE
			* bytePtr = UART7_DR_R;
            break;
				#endif
		  default:
            // Handle invalid UART number
			break;

    }
}

// Function that enables the NVIC for the desired UART module. Can be added in the initialization part.
void UARTNVICEn (uint8_t UART_n) {
	switch (UART_n) {
		#if 0
        case UART_0:		
            SET_BIT(NVIC_EN0_R, 5);  // Enable interrupt for UART0
            break;
        case UART_1:
            SET_BIT(NVIC_EN0_R, 6);  // Enable interrupt for UART1
            break;
        case UART_2:  
            SET_BIT(NVIC_EN1_R, 1);  // Enable interrupt for UART2
            break;
				#endif
        case UART_3:
            SET_BIT(NVIC_EN1_R, 27);  // Enable interrupt for UART3
            break;
        case UART_4:
            SET_BIT(NVIC_EN1_R, 28);  // Enable interrupt for UART4
            break;
		
        case UART_5:
            SET_BIT(NVIC_EN1_R, 29);  // Enable interrupt for UART5
            break;
				#if 0
        case UART_6:
            SET_BIT(NVIC_EN1_R, 30);  // Enable interrupt for UART6
            break;
        case UART_7:
            SET_BIT(NVIC_EN1_R, 31);  // Enable interrupt for UART7
            break;
				#endif 
		default:
            // Handle invalid UART number
			break;
    }
}

// Function that enables the desired interrupt. Can be added in the initialization part.

void UARTIntEnable(uint8_t UART_n, uint8_t UART_INT){
    uint8_t bit_no;
    if (UART_INT == UART_RX_INT){
        bit_no = 4; // Receive Interrupts
		}
    else if (UART_INT == UART_TX_INT){
        bit_no = 5; // Transmit Interrupts
		}else{
			
		}
	switch (UART_n) {
		#if 0
        case UART_0:
            /* Enable Interrupts */
			UART0_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(UART0_IM_R, bit_no);  // Enable interrupt (TX / RX)
            break;

        case UART_1:
        	/* Enable Interrupts */
            UART1_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(UART1_IM_R, bit_no); 
            break;

        case UART_2:
        	/* Enable Interrupts */
        	UART2_ICR_R &= ~(0x0780); // Clear interrupt
        	SET_BIT(UART2_IM_R, bit_no);  
            break;
   #endif         
        case UART_3:
        	/* Enable Interrupts */
        	UART3_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(UART3_IM_R, bit_no);
            break;

        case UART_4:
        	/* Enable Interrupts */
        	UART4_ICR_R &= ~(0x0780); // Clear interrupt
        	SET_BIT(UART4_IM_R, bit_no);
            break;

        case UART_5:
        	/* Enable Interrupts */
        	UART5_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(UART5_IM_R, bit_no); 
            break;
#if 0
        case UART_6:
        	/* Enable Interrupts */
        	UART6_ICR_R &= ~(0x0780); // Clear interrupt
        	SET_BIT(UART6_IM_R, bit_no);
            break;

        case UART_7:
        	/* Enable Interrupts */
        	UART7_ICR_R &= ~(0x0780); // Clear interrupt
        	SET_BIT(UART7_IM_R, bit_no);
            break;
#endif
				 default:
            // Handle invalid UART number
				 break;

    }
}

// Function that disables the desired interrupt. Can be added in the initialization part.
#if 0
void UARTIntDisable(uint8_t UART_n, uint8_t UART_INT) {
    uint8_t bit_no;
    if (UART_INT == UART_RX_INT){
        bit_no = 4; // Receive Interrupts
		}
    else if (UART_INT == UART_TX_INT){
        bit_no = 5; // Transmit Interrupts
		}
	switch (UART_n) {
        case UART_0:
            /* Disable Interrupts */
            UART0_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(NVIC_DIS0_R, 5);  // Disable interrupt for UART0
            break;
        
        case UART_1:
        	/* Disable Interrupts */
            UART1_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(NVIC_DIS0_R, 6);  // Disable interrupt for UART1
            break;
        
        case UART_2:
        	/* Disable Interrupts */
        	UART2_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(NVIC_DIS1_R, 1);  // Disable interrupt for UART2
            break;
        
        case UART_3:
        	/* Disable Interrupts */
        	UART3_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(NVIC_DIS1_R, 27);  // Disable interrupt for UART3
            break;
        
        case UART_4:
        	/* Disable Interrupts */
        	UART4_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(NVIC_DIS1_R, 28);  // Disable interrupt for UART4
            break;
        
        case UART_5:
        	/* Disable Interrupts */
        	UART5_ICR_R &= ~(0x0780); // Clear interrupt
            SET_BIT(NVIC_DIS1_R, 29);  // Disable interrupt for UART5
            break;
        
        case UART_6:
        	/* Disable Interrupts */
        	UART6_ICR_R &= ~(0x0780); // Clear interrupt
        	SET_BIT(NVIC_DIS1_R, 30);  // Disable interrupt for UART6
            break;
        
        case UART_7:
        	/* Disable Interrupts */
        	UART7_ICR_R &= ~(0x0780); // Clear interrupt
        	SET_BIT(NVIC_DIS1_R, 31);  // Disable interrupt for UART7
            break;
    }
}
#endif
#if 0
void UART_String_TX(char *str, uint8_t UART_n)
{
    while(*str)
		{
			UART_TX(*(str++), UART_n);
		}
}
#endif

void Delay(unsigned long counter)
{
	unsigned long i = 0;
	
	for(i=0; i< counter; i++){}
}
