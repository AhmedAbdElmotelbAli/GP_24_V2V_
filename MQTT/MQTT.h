/*
 * MQTT.h
 *
 *  Created on: Feb 16, 2024
 *      Author: Hassan Bahnasy
 */

#ifndef MQTT_H_
#define MQTT_H_

/**************Includes Section**************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "tm4c123gh6pm.h"
#include "UART.h"
#include "string.h"
/*******************************************************/

/**************APIs*************************************/
void MQTT_Connect(u8* clientID,u8* username,u8* password,u8* willTopic, u8* willMessage);

void MQTT_Publish(u8* topic,u8* msg,u32 len,u8 QoS);

void MQTT_Subscribe(u8* topic);

/*******************************************************/

#endif /* MQTT_H_ */
