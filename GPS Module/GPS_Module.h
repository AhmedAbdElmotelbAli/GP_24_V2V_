/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 29/12/2023      *************************/
/*************************      SWC: GPS            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#include "tm4c123gh6pm.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "STD_TYPES.h"
#include "../MCAL/UART/UART.h"
#include "../HAL/Lcd.h"





void get_Time(void);

void get_Latitude(u16 Latitude_Pointer);

void get_Longitude(u16 Longitude_Pointer);

void get_Altitude(u16 Altitude_Pointer);

void process_UART_data(void);

//void UART0_Polling(void);
