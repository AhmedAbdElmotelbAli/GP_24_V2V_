#include "tm4c123gh6pm.h"
#include "Bluetooth.h"
#include "Type.h"
#include "UART.h"
#include "Motor.h"
#include "PWM.h"
#include "GPIO.h"
#include "Port.h"

int main(void)
{
	
	
		Motor_Init();
    Bluetooth_init();


   Delay(10);

    while(1)
    {
        char c = Bluetooth_Read();          /* get a character from UART5 */
				/* control car */
        Bluetooth_Control(c);

    }
}
