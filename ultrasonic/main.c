
/*header files for TM4C123 device and sprintf library */
#include "tm4c123gh6pm.h"
#include "Type.h"
#include "UltraSonic.h"
#include "PWM.h"
#include "GPIO.h"
void DisableInterrupts(void); // Disable interrupts
void EnableInterrupts(void);  // Enable interrupts
long StartCritical (void);    // previous I bit, disable interrupts
void EndCritical(long sr);    // restore I bit to previous value
void WaitForInterrupt(void);  // low power mode
/* global variables to store and display distance in cm */
uint32_t time; /*stores pulse on time */
uint32_t distance; /* stores measured distance value */
char mesg[20];  /* string format of distance value */
uint16_t duty_cycle=25;
uint16_t freq =50;
/* main code to take distance measurement and send data to UART terminal */
int main(void)
{
	/*    PWM_Init(M1PWM, PWM5, PWM_SYSCLK_DIV_64, Count_DOWN, freq, duty_cycle);
	    GPIO_Init(MOTOR_2_PORT,MOTOR_2_IN1);
    GPIO_Init(MOTOR_2_PORT,MOTOR_2_IN2);
    GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_DIRECTION_OUTPUT);
    GPIO_SetPinDirection(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_DIRECTION_OUTPUT);
	    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN1,GPIO_STATE_HIGH);
    GPIO_SetPinState(MOTOR_2_PORT,MOTOR_2_IN2,GPIO_STATE_LOW);
*/
Timer0A_init();  /*initialize Timer0A in edge edge time */
UART5_init(); /* initialize UART5 module to transmit data to computer */
	while(1)
	{
time = Measure_distance(); /* take pulse duration measurement */ 
distance = (time * 10625)/10000000; /* convert pulse duration into distance */
sprintf(mesg, "\r\nDistance = %d cm", distance); /*convert float type distance data into string */
printstring(mesg); /*transmit data to computer */
Delay1(1000);

	}
	
}









