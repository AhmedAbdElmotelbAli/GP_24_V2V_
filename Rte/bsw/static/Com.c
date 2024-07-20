
 
#include "Com.h"
#include "tm4c123gh6pm.h"

char receivedChar1='s';
char receivedChar2='s';
static uint8_t bufferIndex = 0;
char buffer[MAX_LINES][MAX_LANE_LENGTH]; // Array of buffers for each line
static volatile uint8_t lineCount = 0; 


Std_ReturnType Com_ReceiveSignal(Com_SignalIdType SignalId, void* SignalDataPtr)
{
	/* Read from VFB variables */
	switch(SignalId)
	{
		case ComConf_ComSignal_BluetoothBtnSignal_1:
			*((uint8*)SignalDataPtr) = (uint8)receivedChar1;
			break;
			
		case ComConf_ComSignal_BluetoothBtnSignal_2:
			*((uint8*)SignalDataPtr) = (uint8)receivedChar1;
			break;
			
		case ComConf_ComSignal_warningMessageSignal:
			*((uint8*)SignalDataPtr) = (uint8)buffer[0];
			break;
		
		case ComConf_ComSignal_carIdSignal:
			*((uint8*)SignalDataPtr) = (uint8)buffer[1];
			break;
		case ComConf_ComSignal_laneSignal:
			*((uint8*)SignalDataPtr) = (uint8)buffer[2];
			break;
		case ComConf_ComSignal_carTypeSignal:
			*((uint8*)SignalDataPtr) = (uint8)buffer[3];
			break;

		default:
			break;
	}
	
	return E_OK;
}

void UART5_Handler(void) {
    // Clear the interrupt flag
    UART5_ICR_R |= 0x10;
    char receivedChar = (char)(UART5_DR_R & 0xFF);

    // Store the character in the current buffer
    if (lineCount < MAX_LINES) {
        if (receivedChar == '\n' || receivedChar == '\0') {
            // Null-terminate the buffer
            buffer[lineCount][bufferIndex] = '\0';
            lineCount++;
            bufferIndex = 0;    // Reset buffer index for next line
        } else if (receivedChar == '#') {
            // Null-terminate the buffer and increment lineCount
            buffer[lineCount][bufferIndex] = '\0';
            lineCount++;
            bufferIndex = 0;    // Reset buffer index for next line
        } else if (receivedChar == ' ') {
            // Ignore leading spaces
            if (bufferIndex > 0) {
                // Store the character in the buffer
                if (bufferIndex < MAX_LANE_LENGTH - 1) {
                    buffer[lineCount][bufferIndex++] = receivedChar;
                } else {
                    // Buffer full, null-terminate and increment lineCount
                    buffer[lineCount][bufferIndex] = '\0';
                    lineCount++;
                    bufferIndex = 0; // Reset buffer index for next line
                }
            }
        } else {
            // Store the character in the buffer
            if (bufferIndex < MAX_LANE_LENGTH - 1) {
                buffer[lineCount][bufferIndex++] = receivedChar;
            } else {
                // Buffer full, null-terminate and increment lineCount
                buffer[lineCount][bufferIndex] = '\0';
                lineCount++;
                bufferIndex = 0; // Reset buffer index for next line
            }
        }
    }
}
void UART3_Handler(void) {
    // Clear the interrupt flag
     UART3_ICR_R |= 0x10;
     receivedChar2 = UART3_DR_R ;
}
void UART4_Handler(void) {
    // Clear the interrupt flag
    UART4_ICR_R |= 0x10;
     receivedChar1 = UART4_DR_R ;

}
