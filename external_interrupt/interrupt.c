#include "interrupt.h"
void (*IRQ_CallBack[6])(void);

void MCAL_EXTI_GPIO_Init(exti_config *exti_CFG){
	
	//gpio make pin input from gpio_driver
	
	//edge decided
	exti_CFG->portname->GPIOIS 	&= ~ (1<<(exti_CFG->pinnumber));
	exti_CFG->portname->GPIOIBE &= ~(1<<(exti_CFG->pinnumber));
	exti_CFG->portname->GPIOIEV &= ~(1<<(exti_CFG->pinnumber));
	exti_CFG->portname->GPIOIS |=  (exti_CFG->edge&1)<<(exti_CFG->pinnumber);
	exti_CFG->portname->GPIOIBE |= ((exti_CFG->edge&2) >>1)<<(exti_CFG->pinnumber);
	exti_CFG->portname->GPIOIEV  |= ((exti_CFG->edge&4)>>2)<<(exti_CFG->pinnumber);
	//enable mask
		exti_CFG->portname->GPIOIM 	|=  (1<<(exti_CFG->pinnumber));
	//functiom
			
	if(exti_CFG->portname == GPIOA_IR){
		IRQ_CallBack[0]=exti_CFG->function_ret;
			NVIC_ISER0 |= 1;
	}
	else if(exti_CFG->portname == GPIOB_IR){
		IRQ_CallBack[1]=exti_CFG->function_ret;
			NVIC_ISER0 |= 1<<1;
	}
	else if(exti_CFG->portname == GPIOC_IR){
		IRQ_CallBack[2]=exti_CFG->function_ret;
			NVIC_ISER0 |= 1<<2;
	}
	else if(exti_CFG->portname == GPIOD_IR){
		IRQ_CallBack[3]=exti_CFG->function_ret;
		NVIC_ISER0  |= 1<<3;
	}
	else if(exti_CFG->portname == GPIOE_IR){
		IRQ_CallBack[4]=exti_CFG->function_ret;
				NVIC_ISER0 |= 1<<4;
	}
	else if(exti_CFG->portname == GPIOF_IR){
		IRQ_CallBack[5]=exti_CFG->function_ret;
				NVIC_ISER0 |= 1<<30;
	}
				
		
}
void MCAL_EXTI_GPIO_DeInit(exti_config *exti_CFG){
	
	exti_CFG->portname->GPIOIS 	= 0;
	exti_CFG->portname->GPIOIBE = 0;
	exti_CFG->portname->GPIOIEV = 0;
	exti_CFG->portname->GPIOIM 	= 0;
	NVIC_ISER0=0;
	
	
}


void GPIOA_Handler(void){
		IRQ_CallBack[0]();
		GPIOA_IR->GPIORIS=0xff;

	

}
void GPIOB_Handler(void){
		IRQ_CallBack[1]();
		GPIOB_IR->GPIORIS=0xff;

}
void GPIOC_Handler(void){
		IRQ_CallBack[2]();
		GPIOC_IR->GPIORIS=0xff;

}
void GPIOD_Handler(void){
		IRQ_CallBack[3]();
		GPIOD_IR->GPIORIS=0xff;

}
void GPIOE_Handler(void){
		IRQ_CallBack[4]();
		GPIOE_IR->GPIORIS=0xff;

}
void GPIOF_Handler(void){
		IRQ_CallBack[5]();
		GPIOF_IR->GPIORIS=0xff;

}

