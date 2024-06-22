/*
 ============================================================================
 File Name		: Bluetooth.c
 Author			: Ahmed Abdelmotelb Ali
 Version		: 4.0
 Date			: 5/4/2023
 Description	: This file contains the implementation of WIFI Driver
 Notes			: 
 ============================================================================
 */

#ifndef WIFI_H_
#define WIFI_H_
#include "tm4c123gh6pm.h"
#include "UART.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LANE_LENGTH 50 // Maximum length of each lane message
typedef struct {
    char warningMessage[MAX_LANE_LENGTH];
    uint8_t carId;
    char lane[MAX_LANE_LENGTH];
    char carType[MAX_LANE_LENGTH];
} WarningData;
void Wifi_Voidinit(void);
#if 0
uint8_t Wifi_U8Read(void);
void WIFI_VoidWrite(unsigned char data);
void WIFI_VoidWriteString(char *str);
void Wifi_U8ReadLaneMessages(WarningData *warningData);
uint8_t UART_DataAvailable(void) ;
void ReceiveWarningData(WarningData *warning);
void UART_ReadLine(char *buffer, uint16_t maxLength);
#endif
#endif 
