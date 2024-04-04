/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 29/12/2023      *************************/
/*************************      SWC: GPS            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#include "GPS_Module.h"

#define UART_MODULE UART_0


u8 Latitude_Buffer[15]; // Adjust the size based on your expected latitude format
u8 Longitude_Buffer[15]; // Adjust the size based on your expected longitude format
u8 Altitude_Buffer[8]; // Adjust the size based on your expected altitude format
u8 Time_Buffer[15]; // Adjust the size based on your expected time format
u8 GGA_String[150];  // Replace this with your actual GGA string
bool	IsItGGAString	= false;
volatile u16 GGA_Index, CommaCounter;
u8 GGA_Comma_Pointers[20];// Adjust the size based on the expected number of commas

void get_Time(void)
{
	UARTIntDisable(UART_MODULE, UART_INT_RX); /* Disable RDA interrupts */
	u8 time_index = 0;
    u16 index;
    u16 hour, min, sec;
    u32 Time_value;

    /* parse Time in GGA string stored in buffer */
    for(index = 0; GGA_String[index]!=','; index++) 
    {
        Time_Buffer[time_index] = GGA_String[index];
        time_index++;
    }

    Time_value = atol(Time_Buffer);  /* convert string to integer */
    hour = (Time_value / 10000);  /* extract hour from integer */
    min = (Time_value % 10000) / 100;  /* extract minute from integer */
    sec = (Time_value % 10000) % 100;  /* extract second from integer*/
    
    sprintf(Time_Buffer, "%d:%d:%d", hour, min, sec); //Replace with LCD

    UARTIntEnable(UART_MODULE, UART_INT_RX); /* Enable RDA interrupts */
}

void get_Latitude(u16 Latitude_Pointer)
{
    UARTIntDisable(UART_MODULE, UART_INT_RX); /* Disable RDA interrupts */
 	u8 lat_index = 0;
    u8 index = (Latitude_Pointer+1);

    /* parse Latitude in GGA string stored in buffer */
    for(; GGA_String[index]!=','; index++) 
    {
        Latitude_Buffer[lat_index] = GGA_String[index];
        lat_index++;
    }

    f32 lat_decimal_value, lat_degrees_value;
    s32 lat_degrees;

    lat_decimal_value = atof(Latitude_Buffer);    /* Latitude in ddmm.mmmm */

    /* convert raw latitude into degree format */
    lat_decimal_value = (lat_decimal_value/100);  /* Latitude in dd.mmmmmm */
    lat_degrees = (int)(lat_decimal_value);   /* dd of latitude */
    lat_decimal_value = (lat_decimal_value - lat_degrees)/0.6;  /* .mmmm/0.6 (Converting minutes to equivalent degrees) */ 
    lat_degrees_value = (float)(lat_degrees + lat_decimal_value);  /* Latitude in dd.dddd format */

    //sprintf(Latitude_Buffer, "%f", lat_degrees_value); //Replace with LCD
    LCD_displayString(Latitude_Buffer);

    UARTIntEnable(UART_MODULE, UART_INT_RX); /* Enable RDA interrupts */
}

void get_Longitude(u16 Longitude_Pointer) {
    UARTIntDisable(UART_MODULE, UART_INT_RX); /* Disable RDA interrupts */

    u8 long_index = 0;
    u8 index = (Longitude_Pointer+1);

    /* parse Longitude in GGA string stored in buffer */
    for(; GGA_String[index]!=','; index++) {
        Longitude_Buffer[long_index] = GGA_String[index];
        long_index++;
    }

    f32 long_decimal_value, long_degrees_value;
    s32 long_degrees;
    long_decimal_value = atof(Longitude_Buffer);    /* Longitude in dddmm.mmmm */

    /* convert raw longitude into degree format */
    long_decimal_value = (long_decimal_value/100);  /* Longitude in ddd.mmmmmm */
    long_degrees = (int)(long_decimal_value);   /* ddd of Longitude */
    long_decimal_value = (long_decimal_value - long_degrees)/0.6;  /* .mmmmmm/0.6 (Converting minutes to equivalent degrees) */
    long_degrees_value = (float)(long_degrees + long_decimal_value);  /* Longitude in dd.dddd format */

    //sprintf(Longitude_Buffer, "%f", long_degrees_value);  //Replace with LCD
    LCD_displayString(Longitude_Buffer);
    UARTIntEnable(UART_MODULE, UART_INT_RX); /* Enable RDA interrupts */
}

void get_Altitude(u16 Altitude_Pointer) {
    UARTIntDisable(UART_MODULE, UART_INT_RX); /* Disable RDA interrupts */

    u8 alt_index = 0;
    u8 index = (Altitude_Pointer+1);

    /* parse Altitude in GGA string stored in buffer */
    for(; GGA_String[index]!=','; index++) {
        Altitude_Buffer[alt_index] = GGA_String[index];
        alt_index++;
    }

    UARTIntEnable(UART_MODULE, UART_INT_RX); /* Enable RDA interrupts */
}



void process_UART_data(void) {
    u32 iir_value;
    u8* received_char_Pointer;
    u8 received_char;
    // Disable UART RX interrupts
    UARTIntDisable(UART_MODULE, UART_INT_RX);

    // Read the UART interrupt identification register
    iir_value = UARTIntStatus(UART_MODULE, true);

    // Loop to process all pending interrupts
    while (iir_value != UART_INT_ID_NO_INT) {
        // Check if the interrupt is due to receiving data
        if (iir_value & UART_INT_RX) {
            // Read the received character
            received_char = UART_RX(received_char_Pointer,UART_MODULE);


            // Process GGA string
            if (received_char == '$') 
            {
                GGA_Index = 0;
                CommaCounter = 0;
                IsItGGAString = false;
            }
            else if (IsItGGAString) 
            {
                if (received_char == ',') 
                {
                    GGA_Comma_Pointers[CommaCounter++] = GGA_Index;
                }
                GGA_String[GGA_Index++] = received_char;
            } 
            else if ((GGA_String[0] == 'G') && (GGA_String[1] == 'G') && (GGA_String[2] == 'A')) 
            {
                IsItGGAString = true;
                GGA_String[0] = GGA_String[1] = GGA_String[2] = 0;
            } 
            else 
            {
                GGA_String[0] = GGA_String[1];
                GGA_String[1] = GGA_String[2];
                GGA_String[2] = received_char;
            }

            // Clear the interrupt flag
            UARTIntClear(UART_MODULE, UART_INT_RX);
        }

        // Read the UART interrupt identification register again
        iir_value = UARTIntStatus(UART_MODULE, true);
    }
}

/*void UART0_Polling(void) {
    u8 received_char;
    u8* received_char_Pointer;
    // Check if there is data available in the receive FIFO
    while (UART_RX(&received_char, UART_0) == UART_RX_AVAILABLE) 
    {
        // Read the received character
        received_char = UART_RX(received_char_Pointer,UART_MODULE);

        // Process GGA string
        if (received_char == '$') {
            GGA_Index = 0;
            CommaCounter = 0;
            IsItGGAString = false;
        } else if (IsItGGAString) {
            if (received_char == ',') {
                GGA_Comma_Pointers[CommaCounter++] = GGA_Index;
            }
            GGA_String[GGA_Index++] = received_char;
        } else if ((GGA_String[0] == 'G') && (GGA_String[1] == 'G') && (GGA_String[2] == 'A')) {
            IsItGGAString = true;
            GGA_String[0] = GGA_String[1] = GGA_String[2] = 0;
        } else {
            GGA_String[0] = GGA_String[1];
            GGA_String[1] = GGA_String[2];
            GGA_String[2] = received_char;
        }
    }
}*/
