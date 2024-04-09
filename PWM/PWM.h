#ifndef _PWM_H_
#define	_PWM_H_
#include "type.h"


typedef enum
{
    M0PWM,
    M1PWM

}PWM_Module;


typedef enum
{ 
  PWM0,
	PWM1,
	PWM2,
  PWM3,
	PWM4,
	PWM5,
	PWM6,
	PWM7
	
}PWM_Number;


typedef enum
{
  Generator_0,
	Generator_1,
	Generator_2,
	Generator_3,
	
}PWM_Generator;


typedef enum
{
  Control_0,
	Control_1,
	Control_2,
	Control_3,
	
}PWM_Control;


typedef enum
{ 
	Count_UP,
	Count_DOWN,
}PWM_Mode;


typedef enum 
{
    PWM_SYSCLK_DIV_2,
    PWM_SYSCLK_DIV_4,
    PWM_SYSCLK_DIV_8,
    PWM_SYSCLK_DIV_16,
    PWM_SYSCLK_DIV_32,
    PWM_SYSCLK_DIV_64
    
}PWM_SYSCLK_DIV;

/*
 * pwm has 2 module each has 8 pwm at all i have 16 PWM IN TIVA C MODULE CHECK I IN FIRST OR SECOND PWM 
 *PWM_Number NAME OF PWM IN MODULE
 */


/* Function Name: PWMClockSet
 * Inputs:        PWM_Module ,PWM_Number 
 * Returns:       void 
 * Pins :         FOR TYPE OF PWM OPEN CLOCK
 * Description:   ENABLE CLOCK PWM AND PORT 
 * */
void PWM_VoidClockSet(PWM_Module module,PWM_Number number); 
/* Function Name: PWMDiv
 * Inputs:        PWM_SYSCLK_DIV 
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:   Enable System Clock Divisor function AND PUT VALUE
 * */
void PWM_VoidDiv(PWM_SYSCLK_DIV div);
/* Function Name: PWMPinConfigure
 * Inputs:        PWM_Module ,PWM_Number
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:   Enable PORT AND OPEN LOCK
 * */
void PWM_VoidPinConfigure(PWM_Module module,PWM_Number number);  
/* Function Name: PWMGenDisable
 * Inputs:        PWM_Module ,PWM_Number
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:   DISABLE PWM COUNTER MODE
 * */
void PWM_VoidGenDisable(PWM_Module module,PWM_Number number);
/* Function Name: PWMGenConfigure
 * Inputs:        PWM_Module ,PWM_Number,PWM_Mode
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:   CTL TYPE FOR COUNT UP OR DOWEN
 * */
void PWM_VoidGenConfigure(PWM_Module module, PWM_Mode mode, PWM_Number number);                                      
/* Function Name: PWMGenPeriodSet
 * Inputs:        PWM_Module ,PWM_Number,PWM_SYSCLK_DIV,Clock_Required 
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:   SET FRQUENCY AND LOAD VALUE TO PWM
 * */       
void PWM_VoidGenPeriodSet(PWM_Module module, PWM_Number number, PWM_SYSCLK_DIV div, uint32_t Clock_Required);   
/* Function Name: PWMDutyCycleSet
 * Inputs:        PWM_Module ,PWM_Number,PWM_SYSCLK_DIV,duty_cycle 
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:   SET DUTYCYCLE FOR GIVEN LOAD VALUE 
 * */    
void PWM_VoidDutyCycleSet(PWM_Module module, PWM_Number number, PWM_Mode mode, uint32_t duty_cycle);                  
/* Function Name: PWMGenEnable
 * Inputs:        PWM_Module ,PWM_Number
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:   ENABLE PWM
 * */    
void PWM_VoidGenEnable(PWM_Module module,PWM_Number number);
/* Function Name: PWMGenEnable
 * Inputs:        PWM_Module ,PWM_Number, PWM_SYSCLK_DIV,PWM_Mode,Clock_Required,duty_cycle
 * Returns:       void 
 * Pins :         NO PIN HW
 * Description:  DO ALL ABOVE
 * */    
void PWM_VoidInit(PWM_Module module,PWM_Number number,PWM_SYSCLK_DIV div,PWM_Mode mode,uint32_t Clock_Required,uint32_t duty_cycle);


#endif
