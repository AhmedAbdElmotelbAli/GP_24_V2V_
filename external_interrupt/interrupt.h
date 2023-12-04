#include "stdint.h"

typedef struct{
	volatile uint32_t GPIOIS; 
	volatile uint32_t GPIOIBE; 
	volatile uint32_t GPIOIEV; 	
	volatile uint32_t GPIOIM; 
	volatile uint32_t GPIORIS; 
	volatile uint32_t GPIOMIS;
	volatile uint32_t GPIOICR;
}exti_typedef;

//start address for registers of interrupt in gpio
#define	GPIOA		0x40004404
#define	GPIOB	  0x40005404
#define	GPIOC		0x40006404
#define	GPIOD		0x40007404
#define	GPIOE		0x40024404
#define	GPIOF		0x40025404


#define NVIC_ISER0									*((volatile uint32_t *)(0xE000E000 + 0x100))
#define NVIC_ISER1									*((volatile uint32_t *)(0xE000E000 + 0x104))



#define NVIC_GPIOA_IRQ_ENABLE						NVIC_ISER0 |= 1;
#define NVIC_GPIOB_IRQ_ENABLE						NVIC_ISER0 |= 1<<1;
#define NVIC_GPIOC_IRQ_ENABLE						NVIC_ISER0 |= 1<<2;
#define NVIC_GPIOD_IRQ_ENABLE						NVIC_ISER0 |= 1<<3;
#define NVIC_GPIOE_IRQ_ENABLE						NVIC_ISER0 |= 1<<4;
#define NVIC_GPIOF_IRQ_ENABLE						NVIC_ISER0 |= 1<<30;





typedef struct{
	exti_typedef * portname;
	uint8_t pinnumber;
	uint8_t edge;
	void(* function_ret)(void);
}exti_config;

// portname ref
#define  GPIOA_IR			((exti_typedef *) GPIOA)
#define  GPIOB_IR			((exti_typedef *) GPIOB)
#define  GPIOC_IR			((exti_typedef *) GPIOC)
#define  GPIOD_IR			((exti_typedef *) GPIOD)
#define  GPIOE_IR			((exti_typedef *) GPIOE)
#define  GPIOF_IR			((exti_typedef *) GPIOF)

//edge ref
#define high_edge		0x4
#define low_edge		0
#define both_edge		0x2
#define high_level	0x5
#define low_level		0x1

//pinnumber ref
#define p0		0
#define p1		1
#define p2		2
#define p3		3
#define p4		4
#define p5		5
#define p6		6
#define p7		7






void MCAL_EXTI_GPIO_Init(exti_config *EXTI_CFG);
void MCAL_EXTI_GPIO_DeInit(exti_config *EXTI_CFG);


