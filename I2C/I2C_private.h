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

#define PMC0_0    0U
#define PMC0_1    1U
#define PMC0_2    2U
#define PMC0_3    3U


#define PMC1_0    4U
#define PMC1_1    5U
#define PMC1_2    6U
#define PMC1_3    7U



#define PMC2_0    8U
#define PMC2_1    9U
#define PMC2_2    10U
#define PMC2_3    11U

#define PMC3_0    12U
#define PMC3_1    13U
#define PMC3_2    14U
#define PMC3_3    15U

#define PMC4_0    16U
#define PMC4_1    17U
#define PMC4_2    18U
#define PMC4_3    19U

#define PMC5_0    20U
#define PMC5_1    21U
#define PMC5_2    22U
#define PMC5_3    23U

#define PMC6_0    24U
#define PMC6_1    25U
#define PMC6_2    26U
#define PMC6_3    27U

#define PMC7_0    28U
#define PMC7_1    29U
#define PMC7_2    30U
#define PMC7_3    31U


#define ONE     1U
#define ZERO    0U


#define DISABLED     0U
#define ENABLED      1U


/* Registers */

/* General */
#define RCGCI2C         *((volatile u32*)0x400FE620)
#define RCGCGPIO        *((volatile u32*)0x400FE608)
#define R0  0U
#define R1  1U
#define R2  2U
#define R3  3U
#define R4  4U
#define R5  5U
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
#define R_S         0U
#define S_A         1U
/* I2C_MCS 2*/
//RO
#define BUSY        0U
#define ERROR       1U
#define ADRACK      2U
#define DATACK      3U
#define ARBLST      4U
#define IDLE        5U
#define BUSBSY      6U
#define CLKTO       7U
////WO
#define RUN         0U
#define START       1U
#define STOP        2U
#define ACK         3U
#define HS          4U
/* I2C_MDR 3*/
#define DATA        0U

/* I2C_MTPR 4*/
//Selects speed mode
#define TPR         0U
#define HS          7U
/* I2C_MIMR 5*/
#define IM          0U
#define CLKIM       1U
/* I2C_MMRIS 6*/
#define RIS         0U
#define CLKRIS      1U
/* I2C_MMIS 7*/
#define MIS         0U
#define CLKMIS      1U
/* I2C_MIMR 8*/
#define IC          0U
#define CLKIC       1U
/* I2C_MICR 9*/
#define LPBK        0U
#define MFE         4U
#define SFE         5U
#define GFE         6U
/* I2C_MCLKOCNT 10*/
#define CNTL        0U
/* I2C_MBMON 11*/
#define SCL         0U
#define SDA         1U
/* I2C_MCR2 12*/
#define GFPW        4U

#endif