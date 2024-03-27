/*
 ============================================================================
 File Name		: I2C_private.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 3/27/2023
 Description	: This file contains private registers, Macors and data types used only inside this driver
 Notes			: You can't use any of this in Application layer explicitly
 ============================================================================
 */




#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_

/* Configration Options */
#define I2C_MASTER  0
#define I2C_SLAVE   1

#define	STANDARD_MODE       3
#define	FAST_MODE           4
#define	FAST MODE PLUS      5

/* Base Adresses */
#define I2C0_Base 0x40020000
#define I2C1_Base 0x40021000
#define I2C2_Base 0x40022000
#define I2C3_Base 0x40023000
/*
GPIO Port A (APB) base: 0x40004000
GPIO Port A (AHB) base: 0x40058000
GPIO Port B (APB) base: 0x40005000
GPIO Port B (AHB) base: 0x40059000
GPIO Port C (APB) base: 0x40006000
GPIO Port C (AHB) base: 0x4005A000
GPIO Port D (APB) base: 0x40007000
GPIO Port D (AHB) base: 0x4005B000
GPIO Port E (APB) base: 0x40024000
GPIO Port E (AHB) base: 0x4005C000
GPIO Port F (APB) base: 0x40025000
GPIO Port F (AHB) base: 0x4005D000

*/
#define GPIO_PORTA_APB_BASE   0x40004000
#define GPIO_PORTA_AHB_BASE   0x40058000

#define GPIO_PORTB_APB_BASE   0x40005000
#define GPIO_PORTB_AHB_BASE   0x40059000

#define GPIO_PORTC_APB_BASE   0x40006000
#define GPIO_PORTC_AHB_BASE   0x4005A000

#define GPIO_PORTD_APB_BASE   0x40007000
#define GPIO_PORTD_AHB_BASE   0x4005B000

#define GPIO_PORTE_APB_BASE   0x40024000
#define GPIO_PORTE_AHB_BASE   0x4005C000

#define GPIO_PORTF_APB_BASE   0x40025000
#define GPIO_PORTF_AHB_BASE   0x4005D000
/*
    Open Drain Select Offset: 0x50C (GPIOODR)
*/





#define GPIOA_AFSEL_APB     *((volatile u32*)(GPIO_PORTA_APB_BASE+0x420))
#define GPIOB_AFSEL_APB     *((volatile u32*)(GPIO_PORTB_APB_BASE+0x420))
#define GPIOC_AFSEL_APB     *((volatile u32*)(GPIO_PORTC_APB_BASE+0x420))
#define GPIOD_AFSEL_APB     *((volatile u32*)(GPIO_PORTD_APB_BASE+0x420))
#define GPIOE_AFSEL_APB     *((volatile u32*)(GPIO_PORTE_APB_BASE+0x420))
#define GPIOF_AFSEL_APB     *((volatile u32*)(GPIO_PORTF_APB_BASE+0x420))

#define GPIOA_AFSEL_AHB     *((volatile u32*)(GPIO_PORTA_AHB_BASE+0x420))
#define GPIOB_AFSEL_AHB     *((volatile u32*)(GPIO_PORTB_AHB_BASE+0x420))
#define GPIOC_AFSEL_AHB     *((volatile u32*)(GPIO_PORTC_AHB_BASE+0x420))
#define GPIOD_AFSEL_AHB     *((volatile u32*)(GPIO_PORTD_AHB_BASE+0x420))
#define GPIOE_AFSEL_AHB     *((volatile u32*)(GPIO_PORTE_AHB_BASE+0x420))
#define GPIOF_AFSEL_AHB     *((volatile u32*)(GPIO_PORTF_AHB_BASE+0x420))

#define GPIOA_ODR_APB       *((volatile u32*)(GPIO_PORTA_APB_BASE+0x50C))
#define GPIOB_ODR_APB       *((volatile u32*)(GPIO_PORTB_APB_BASE+0x50C))
#define GPIOC_ODR_APB       *((volatile u32*)(GPIO_PORTC_APB_BASE+0x50C))
#define GPIOD_ODR_APB       *((volatile u32*)(GPIO_PORTD_APB_BASE+0x50C))
#define GPIOE_ODR_APB       *((volatile u32*)(GPIO_PORTE_APB_BASE+0x50C))
#define GPIOF_ODR_APB       *((volatile u32*)(GPIO_PORTF_APB_BASE+0x50C))

#define GPIOA_ODR_AHB       *((volatile u32*)(GPIO_PORTA_AHB_BASE+0x50C))
#define GPIOB_ODR_AHB       *((volatile u32*)(GPIO_PORTB_AHB_BASE+0x50C))
#define GPIOC_ODR_AHB       *((volatile u32*)(GPIO_PORTC_AHB_BASE+0x50C))
#define GPIOD_ODR_AHB       *((volatile u32*)(GPIO_PORTD_AHB_BASE+0x50C))
#define GPIOE_ODR_AHB       *((volatile u32*)(GPIO_PORTE_AHB_BASE+0x50C))
#define GPIOF_ODR_AHB       *((volatile u32*)(GPIO_PORTF_AHB_BASE+0x50C))

#define GPIOA_CTL_APB       *((volatile u32*)(GPIO_PORTA_APB_BASE+0x52C))
#define GPIOB_CTL_APB       *((volatile u32*)(GPIO_PORTB_APB_BASE+0x52C))
#define GPIOC_CTL_APB       *((volatile u32*)(GPIO_PORTC_APB_BASE+0x52C))
#define GPIOD_CTL_APB       *((volatile u32*)(GPIO_PORTD_APB_BASE+0x52C))
#define GPIOE_CTL_APB       *((volatile u32*)(GPIO_PORTE_APB_BASE+0x52C))
#define GPIOF_CTL_APB       *((volatile u32*)(GPIO_PORTF_APB_BASE+0x52C))

#define GPIOA_CTL_AHB       *((volatile u32*)(GPIO_PORTA_AHB_BASE+0x52C))
#define GPIOB_CTL_AHB       *((volatile u32*)(GPIO_PORTB_AHB_BASE+0x52C))
#define GPIOC_CTL_AHB       *((volatile u32*)(GPIO_PORTC_AHB_BASE+0x52C))
#define GPIOD_CTL_AHB       *((volatile u32*)(GPIO_PORTD_AHB_BASE+0x52C))
#define GPIOE_CTL_AHB       *((volatile u32*)(GPIO_PORTE_AHB_BASE+0x52C))
#define GPIOF_CTL_AHB       *((volatile u32*)(GPIO_PORTF_AHB_BASE+0x52C))

#define PMC0    0
#define PMC1    4
#define PMC2    8
#define PMC3    12
#define PMC4    16
#define PMC5    20
#define PMC6    24
#define PMC7    28


#define ONE     1
#define ZERO    0


#define DISABLED     0
#define ENABLED      1


/* Registers */

/* General */
#define RCGCI2C         *((volatile u32*)0x400FE620)
#define RCGCGPIO        *((volatile u32*)0x400FE608)
#define R0  0
#define R1  1
#define R2  2
#define R3  3
#define R4  4
#define R5  5
/* I2C0 */
#define I2C0_MSA        *((volatile u32*)(I2C0_Base+0x000))
#define I2C0_MCS        *((volatile u32*)(I2C0_Base+0x004))
#define I2C0_MCS        *((volatile u32*)(I2C0_Base+0x004))
#define I2C0_MDR        *((volatile u32*)(I2C0_Base+0x008))
#define I2C0_MTPR       *((volatile u32*)(I2C0_Base+0x00C))
#define I2C0_MIMR       *((volatile u32*)(I2C0_Base+0x010))
#define I2C0_MMRIS      *((volatile u32*)(I2C0_Base+0x014))
#define I2C0_MMIS       *((volatile u32*)(I2C0_Base+0x018))
#define I2C0_MIMR       *((volatile u32*)(I2C0_Base+0x010))
#define I2C0_MICR       *((volatile u32*)(I2C0_Base+0x01C))
#define I2C0_MCR        *((volatile u32*)(I2C0_Base+0x020))
#define I2C0_MCLKOCNT   *((volatile u32*)(I2C0_Base+0x024))
#define I2C0_MBMON      *((volatile u32*)(I2C0_Base+0x02C))
#define I2C0_MCR2       *((volatile u32*)(I2C0_Base+0x038))

/* I2C1 */
#define I2C1_MSA        *((volatile u32*)(I2C1_Base+0x000))
#define I2C1_MCS        *((volatile u32*)(I2C1_Base+0x004))
#define I2C1_MCS        *((volatile u32*)(I2C1_Base+0x004))
#define I2C1_MDR        *((volatile u32*)(I2C1_Base+0x008))
#define I2C1_MTPR       *((volatile u32*)(I2C1_Base+0x00C))
#define I2C1_MIMR       *((volatile u32*)(I2C1_Base+0x010))
#define I2C1_MMRIS      *((volatile u32*)(I2C1_Base+0x014))
#define I2C1_MMIS       *((volatile u32*)(I2C1_Base+0x018))
#define I2C1_MIMR       *((volatile u32*)(I2C1_Base+0x010))
#define I2C1_MICR       *((volatile u32*)(I2C1_Base+0x01C))
#define I2C1_MCR        *((volatile u32*)(I2C1_Base+0x020))
#define I2C1_MCLKOCNT   *((volatile u32*)(I2C1_Base+0x024))
#define I2C1_MBMON      *((volatile u32*)(I2C1_Base+0x02C))
#define I2C1_MCR2       *((volatile u32*)(I2C1_Base+0x038))

/* I2C2 */
#define I2C2_MSA        *((volatile u32*)(I2C2_Base+0x000))
#define I2C2_MCS        *((volatile u32*)(I2C2_Base+0x004))
#define I2C2_MCS        *((volatile u32*)(I2C2_Base+0x004))
#define I2C2_MDR        *((volatile u32*)(I2C2_Base+0x008))
#define I2C2_MTPR       *((volatile u32*)(I2C2_Base+0x00C))
#define I2C2_MIMR       *((volatile u32*)(I2C2_Base+0x010))
#define I2C2_MMRIS      *((volatile u32*)(I2C2_Base+0x014))
#define I2C2_MMIS       *((volatile u32*)(I2C2_Base+0x018))
#define I2C2_MIMR       *((volatile u32*)(I2C2_Base+0x010))
#define I2C2_MICR       *((volatile u32*)(I2C2_Base+0x01C))
#define I2C2_MCR        *((volatile u32*)(I2C2_Base+0x020))
#define I2C2_MCLKOCNT   *((volatile u32*)(I2C2_Base+0x024))
#define I2C2_MBMON      *((volatile u32*)(I2C2_Base+0x02C))
#define I2C2_MCR2       *((volatile u32*)(I2C2_Base+0x038))

/* I2C3 */
#define I2C3_MSA        *((volatile u32*)(I2C3_Base+0x000))
#define I2C3_MCS        *((volatile u32*)(I2C3_Base+0x004))
#define I2C3_MDR        *((volatile u32*)(I2C3_Base+0x008))
#define I2C3_MTPR       *((volatile u32*)(I2C3_Base+0x00C))
#define I2C3_MIMR       *((volatile u32*)(I2C3_Base+0x010))
#define I2C3_MMRIS      *((volatile u32*)(I2C3_Base+0x014))
#define I2C3_MMIS       *((volatile u32*)(I2C3_Base+0x018))
#define I2C3_MIMR       *((volatile u32*)(I2C3_Base+0x010))
#define I2C3_MICR       *((volatile u32*)(I2C3_Base+0x01C))
#define I2C3_MCR        *((volatile u32*)(I2C3_Base+0x020))
#define I2C3_MCLKOCNT   *((volatile u32*)(I2C3_Base+0x024))
#define I2C3_MBMON      *((volatile u32*)(I2C3_Base+0x02C))
#define I2C3_MCR2       *((volatile u32*)(I2C3_Base+0x038))





/* Register bits */

/* I2C_MSA 1*/
#define R_S         0
#define S_A         1
/* I2C_MCS 2*/
//RO
#define BUSY        0
#define ERROR       1
#define ADRACK      2
#define DATACK      3
#define ARBLST      4
#define IDLE        5
#define BUSBSY      6
#define CLKTO       7
////WO
#define RUN         0
#define START       1
#define STOP        2
#define ACK         3
#define HS          4
/* I2C_MDR 3*/
#define DATA        0

/* I2C_MTPR 4*/
//Selects speed mode
#define TPR         0
#define HS          7
/* I2C_MIMR 5*/
#define IM          0
#define CLKIM       1
/* I2C_MMRIS 6*/
#define RIS         0
#define CLKRIS      1
/* I2C_MMIS 7*/
#define MIS         0
#define CLKMIS      1
/* I2C_MIMR 8*/
#define IC          0
#define CLKIC       1
/* I2C_MICR 9*/
#define LPBK        0
#define MFE         4
#define SFE         5
#define GFE         6
/* I2C_MCLKOCNT 10*/
#define CNTL        0
/* I2C_MBMON 11*/
#define SCL         0
#define SDA         1
/* I2C_MCR2 12*/
#define GFPW        4

#endif