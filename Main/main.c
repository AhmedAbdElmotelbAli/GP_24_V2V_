#include "RTE_Main.h"
#include "check.h"
int main(void)
{
	char c ;
		RTE_Call_System_voidInit();
		RTE_Call_LCD_VOIDCleanscreen();
		RTE_Call_LCD_VoidDisplayStringRowColumn(0,0,"Hello MR.Ahmed");
		RTE_Call_LCD_VoidDisplayStringRowColumn(1,0,"Abdelmotelb");

  while(1)
    {

		if(checksaveDirection()==false){
			if(RTE_Call_motor_boolCheckstop()==true){
				c=RTE_Call_Bluetooth_U8Read();  
				if(changeDirection(c)==true)
				{
					RTE_Call_Bluetooth_VoidControl(c);
				}
			}else{
				c=Bluetooth_U8Read(); 
       RTE_Call_Bluetooth_VoidControl(c);
			}
		}else{
			c=RTE_Call_Bluetooth_U8Read();
			 
       RTE_Call_Bluetooth_VoidControl(c);
			}

    }

}
		/*	distance=Measure_destance();
			sprintf(mesg, "Distance = %d cm",distance );
				if(distance<12&&c=='F')
				{		
					LCD_VoidclearScreen();
					Motor_Stop();
				  Bluetooth_Write_String("Waring distance less than 12\n");
					LCD_displayString(mesg);
					Delay_MicroSecond(5000);
					LCD_displayStringRowColumn(1,0,"Waring distance");
					c=Bluetooth_Read();
					while(c=='F'){
						c=Bluetooth_Read();
					}
					Delay_MicroSecond(5000);
					Bluetooth_VoidControl(c);
					 continue;
				}else{*/
			      	/* control car */
