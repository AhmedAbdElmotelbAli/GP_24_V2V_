#include "../BITMATH.h"
#include "../Type.h"
#include "../tm4c123gh6pm.h"
#include "SSI.h"

/*
1. Enable the SSI module using the RCGCSSI register (see page 346).
2. Enable the clock to the appropriate GPIO module via the RCGCGPIO register (see page 340).
To find out which GPIO port to enable, refer to Table 23-5 on page 1351.
3. Set the GPIO AFSEL bits for the appropriate pins (see page 671). To determine which GPIOs to
configure, see Table 23-4 on page 1344.
4. Configure the PMCn fields in the GPIOPCTL register to assign the SSI signals to the appropriate
pins. See page 688 and Table 23-5 on page 1351.
5. Program the GPIODEN register to enable the pin's digital function. In addition, the drive strength,
drain select and pull-up/pull-down functions must be configured. Refer to “General-Purpose
Input/Outputs (GPIOs)” on page 649 for more information.
*/

void SSI_Master_Init(uint08_t SSI_n) {
    switch(SSI_n) {
        case SSI_0:
            SET_BIT(SYSCTL_RCGCSSI_R, 0);
            SET_BIT(SYSCTL_RCGCGPIO_R, 0); // Enabling GPIO clock.
            GPIO_PORTA_AFSEL_R |= (1<<2) | (1<<3) | (1<<4) | (1<<5); // Setting SSI GPIO AFSEL bits. (PORT A)
            GPIO_PORTA_PCTL_R |= (2<<8) | (2<<12) | (2<<16) | (2<<20); // PMC 2/3/4/5
            GPIO_PORTA_DEN_R |= (1<<2) | (1<<3) | (1<<4) | (1<<5); // Enabling digital pins
            CLR_BIT(SSI0_CR1_R, 1); //  Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes
            SSI0_CR1_R = 0x00000000; // Master Operation
            SSI0_CC_R = 0x00; // Configuring Clk
            SSI0_CPSR_R = 0x10; // SSI Clock Prescale Divisor. System clk / 10. Can be modified
            SSI0_CR0_R = 0x7; // 8-bit data, Free Scale SSI Frame Format.
            SET_BIT(SSI0_CR1_R, 1); // Enable SSI after Initialization.
            break;
        case SSI_1:
            SET_BIT(SYSCTL_RCGCSSI_R, 1);
            SET_BIT(SYSCTL_RCGCGPIO_R, 5); // Enabling GPIO clock.
            GPIO_PORTF_AFSEL_R |= (1) | (1<<1) | (1<<2) | (1<<3); // Setting SSI GPIO AFSEL bits. (PORT F)
            GPIO_PORTF_PCTL_R |= (2) | (2<<4) | (2<<8) | (2<<12); // PMC 0/1/2/3
            GPIO_PORTF_DEN_R |= (1) | (1<<1) | (1<<2) | (1<<3); // Enabling digital pins
            CLR_BIT(SSI1_CR1_R, 1); //  Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes
            SSI1_CR1_R = 0x00000000; // Master Operation
            SSI1_CC_R = 0x00; // Configuring Clk
            SSI1_CPSR_R = 0x10; // SSI Clock Prescale Divisor. System clk / 10. Can be modified
            SSI1_CR0_R = 0x7; // 8-bit data, Free Scale SSI Frame Format.
            SET_BIT(SSI1_CR1_R, 1); // Enable SSI after Initialization.
            break;
        case SSI_2:
            SET_BIT(SYSCTL_RCGCSSI_R, 1);
            SET_BIT(SYSCTL_RCGCGPIO_R, 1); // Enabling GPIO clock.
            GPIO_PORTB_AFSEL_R |= (1<<4) | (1<<5) | (1<<6) | (1<<7); // Setting SSI GPIO AFSEL bits. (PORT B)
            GPIO_PORTB_PCTL_R |= (2<<16) | (2<<20) | (2<<24) | (2<<28); // PMC 4/5/6/7
            GPIO_PORTB_DEN_R |= (1<<4) | (1<<5) | (1<<6) | (1<<7); // Enabling digital pins
            CLR_BIT(SSI2_CR1_R, 1); //  Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes
            SSI2_CR1_R = 0x00000000; // Master Operation
            SSI2_CC_R = 0x00; // Configuring Clk
            SSI2_CPSR_R = 0x10; // SSI Clock Prescale Divisor. System clk / 10. Can be modified
            SSI2_CR0_R = 0x7; // 8-bit data, Free Scale SSI Frame Format.
            SET_BIT(SSI2_CR1_R, 1); // Enable SSI after Initialization.
            break;
        case SSI_3:
            SET_BIT(SYSCTL_RCGCSSI_R, 1);
            SET_BIT(SYSCTL_RCGCGPIO_R, 3); // Enabling GPIO clock.
            GPIO_PORTD_AFSEL_R |= (1) | (1<<1) | (1<<2) | (1<<3); // Setting SSI GPIO AFSEL bits. (PORT D)
            GPIO_PORTD_PCTL_R |= (2) | (2<<4) | (2<<8) | (2<<12); // PMC 0/1/2/3
            GPIO_PORTD_DEN_R |= (1) | (1<<1) | (1<<2) | (1<<3); // Enabling digital pins
            CLR_BIT(SSI3_CR1_R, 1); //  Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes
            SSI3_CR1_R = 0x00000000; // Master Operation
            SSI3_CC_R = 0x00; // Configuring Clk
            SSI3_CPSR_R = 0x10; // SSI Clock Prescale Divisor. System clk / 10. Can be modified
            SSI3_CR0_R = 0x7; // 8-bit data, Free Scale SSI Frame Format.
            SET_BIT(SSI3_CR1_R, 1); // Enable SSI after Initialization.
            break;
    }
}

void SSI_Slave_Init(uint08_t SSI_n) {
    switch(SSI_n) {
        case SSI_0:
            SET_BIT(SYSCTL_RCGCSSI_R, 0);
            SET_BIT(SYSCTL_RCGCGPIO_R, 0); // Enabling GPIO clock.
            GPIO_PORTA_AFSEL_R |= (1<<2) | (1<<3) | (1<<4) | (1<<5); // Setting SSI GPIO AFSEL bits. (PORT A)
            GPIO_PORTA_PCTL_R |= (2<<8) | (2<<12) | (2<<16) | (2<<20); // PMC 2/3/4/5
            GPIO_PORTA_DEN_R |= (1<<2) | (1<<3) | (1<<4) | (1<<5); // Enabling digital pins
            CLR_BIT(SSI0_CR1_R, 1); //  Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes
            SSI0_CR1_R = 0x00000004; // Slave Operation output enabled
            SSI0_CC_R = 0x00; // Configuring Clk
            SSI0_CPSR_R = 0x10; // SSI Clock Prescale Divisor. System clk / 10. Can be modified
            SSI0_CR0_R = 0x7; // 8-bit data, Free Scale SSI Frame Format.
            SET_BIT(SSI0_CR1_R, 1); // Enable SSI after Initialization.
            break;
        case SSI_1:
            SET_BIT(SYSCTL_RCGCSSI_R, 1);
            SET_BIT(SYSCTL_RCGCGPIO_R, 5); // Enabling GPIO clock.
            GPIO_PORTF_AFSEL_R |= (1) | (1<<1) | (1<<2) | (1<<3); // Setting SSI GPIO AFSEL bits. (PORT F)
            GPIO_PORTF_PCTL_R |= (2) | (2<<4) | (2<<8) | (2<<12); // PMC 0/1/2/3
            GPIO_PORTF_DEN_R |= (1) | (1<<1) | (1<<2) | (1<<3); // Enabling digital pins
            CLR_BIT(SSI1_CR1_R, 1); //  Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes
            SSI1_CR1_R = 0x00000004; // Slave Operation output enabled
            SSI1_CC_R = 0x00; // Configuring Clk
            SSI1_CPSR_R = 0x10; // SSI Clock Prescale Divisor. System clk / 10. Can be modified
            SSI1_CR0_R = 0x7; // 8-bit data, Free Scale SSI Frame Format.
            SET_BIT(SSI1_CR1_R, 1); // Enable SSI after Initialization.
            break;
        case SSI_2:
            SET_BIT(SYSCTL_RCGCSSI_R, 1);
            SET_BIT(SYSCTL_RCGCGPIO_R, 1); // Enabling GPIO clock.
            GPIO_PORTB_AFSEL_R |= (1<<4) | (1<<5) | (1<<6) | (1<<7); // Setting SSI GPIO AFSEL bits. (PORT B)
            GPIO_PORTB_PCTL_R |= (2<<16) | (2<<20) | (2<<24) | (2<<28); // PMC 4/5/6/7
            GPIO_PORTB_DEN_R |= (1<<4) | (1<<5) | (1<<6) | (1<<7); // Enabling digital pins
            CLR_BIT(SSI2_CR1_R, 1); //  Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes
            SSI2_CR1_R = 0x00000004; // Slave Operation output enabled
            SSI2_CC_R = 0x00; // Configuring Clk
            SSI2_CPSR_R = 0x10; // SSI Clock Prescale Divisor. System clk / 10. Can be modified
            SSI2_CR0_R = 0x7; // 8-bit data, Free Scale SSI Frame Format.
            SET_BIT(SSI2_CR1_R, 1); // Enable SSI after Initialization.
            break;
        case SSI_3:
            SET_BIT(SYSCTL_RCGCSSI_R, 1);
            SET_BIT(SYSCTL_RCGCGPIO_R, 3); // Enabling GPIO clock.
            GPIO_PORTD_AFSEL_R |= (1) | (1<<1) | (1<<2) | (1<<3); // Setting SSI GPIO AFSEL bits. (PORT D)
            GPIO_PORTD_PCTL_R |= (2) | (2<<4) | (2<<8) | (2<<12); // PMC 0/1/2/3
            GPIO_PORTD_DEN_R |= (1) | (1<<1) | (1<<2) | (1<<3); // Enabling digital pins
            CLR_BIT(SSI3_CR1_R, 1); //  Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes
            SSI3_CR1_R = 0x00000004; // Slave Operation output enabled
            SSI3_CC_R = 0x00; // Configuring Clk
            SSI3_CPSR_R = 0x10; // SSI Clock Prescale Divisor. System clk / 10. Can be modified
            SSI3_CR0_R = 0x7; // 8-bit data, Free Scale SSI Frame Format.
            SET_BIT(SSI3_CR1_R, 1); // Enable SSI after Initialization.
            break;
    }
}

void SSI_SendByte(uint08_t data, uint08_t SSI_n) {
    switch (SSI_n)
    {
    case SSI_0:
        SSI0_DR_R = data;
        while (!GET_BIT(SSI0_SR_R, 0));
        break;

    case SSI_1:
        SSI1_DR_R = data;
        while (!GET_BIT(SSI1_SR_R, 0));
        break;
    
    case SSI_2:
        SSI2_DR_R = data;
        while (!GET_BIT(SSI2_SR_R, 0));
        break;

    case SSI_3:
        SSI3_DR_R = data;
        while (!GET_BIT(SSI3_SR_R, 0));
        break;
    }    
}

uint08_t SSI_ReceiveByte(uint08_t SSI_n) {
    switch (SSI_n)
    {
    case SSI_0:
        while (!GET_BIT(SSI0_SR_R, 3));
        return SSI0_DR_R; // Return data register as a whole, can be modified to send/receive multiple bytes.
        break;

    case SSI_1:
        while (!GET_BIT(SSI1_SR_R, 3));
        return SSI1_DR_R;
        break;
    
    case SSI_2:
        while (!GET_BIT(SSI2_SR_R, 3));
        return SSI2_DR_R;
        break;

    case SSI_3:
        while (!GET_BIT(SSI3_SR_R, 3));
        return SSI3_DR_R;
        break;
    }   
}