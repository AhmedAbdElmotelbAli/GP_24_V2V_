#include "WIFI.h"
int static start=0;
void Wifi_Voidinit(void)
{
    UART_INIT(UART_5);
	  UARTNVICEn(UART_5);
    UARTIntEnable(UART_5, UART_RX_INT);

}
#if 0
uint8_t Wifi_U8Read(void)
{

       uint8_t data;
       UART_RX(&data,UART_5);
       return  data;
}

void WIFI_VoidWrite(unsigned char data)
{
    UART_TX(data,UART_5);
}
void WIFI_VoidWriteString(char *str)
{
	 UART_String_TX(str,UART_5);
  
}
void Wifi_U8ReadLaneMessages(WarningData *warningData) {
    char receivedChar;
    char buffer[MAX_LANE_LENGTH];
    uint8_t bufferIndex = 0;
    uint8_t lineCount = 0;
	
    // Reset warningData
    memset(warningData, 0, sizeof(WarningData));

    while (1) {
        // Read a character from WiFi
		/*	if(start==0)
				{*/
			 receivedChar=Wifi_U8Read();
				//start=1;
			 // }
			/*	else{
        receivedChar = Wifi_U8Read();
				}*/
        // Check for termination conditions
        if (receivedChar == '\n' || receivedChar == '\0') {
            // Null-terminate the buffer
            buffer[bufferIndex] = '\0';

            // Process the line based on line count
            switch (lineCount) {
                case 0:
								  //	memmove(buffer, buffer + 1, strlen(buffer));
                    strcpy(warningData->warningMessage, "Waring message");
                    break;
                case 1:
									
								(warningData->carId) = atoi(buffer);
                 // sscanf(buffer, "Car ID: %hhu", &(warningData->carId));
                    break;
                case 2:
                    strcpy(warningData->lane, buffer);
                    break;
                case 3:
                    strcpy(warningData->carType, buffer);
                    break;
                default:
                    // Do nothing
                    break;
            }

            // Reset buffer index for the next line
            bufferIndex = 0;

            // Increment line count
            lineCount++;

            // Break if all lines are read
            if (lineCount >= 5) {
                break;
            }
        } else {
            // Store the character in the buffer
            if (bufferIndex < MAX_LANE_LENGTH - 1) {
                buffer[bufferIndex++] = receivedChar;
            }
        }
    }
}
#endif


