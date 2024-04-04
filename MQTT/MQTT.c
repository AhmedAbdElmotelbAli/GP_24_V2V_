/*
 * MQTT.c
 *
 *  Created on: Feb 16, 2024
 *      Author: Hassan Bahnasy
 */
/**************Includes Section**************************/
#include "MQTT.h"

/*******************************************************/

/*
 * Packet identifier:
	Represents a sequence number for a transmitted packet.
	Two Bytes start from PacketID = 1 = MSB: 0x00 LSB: 0x01
 */
u16 packetID = 1;

u8 packet[200] = {0};   //Packet Len <= (127 + 2):(REM LEN is one byte only)
u8 packetInd = 0; //Index to fill the packet buffer

void MQTT_Connect(u8* clientID,u8* username,u8* password,u8* willTopic, u8* willMessage)
{
	packetInd = 0;
	u8 remLen = (12 + strlen(clientID)+ strlen(willTopic) + strlen(willMessage) + strlen(username) + strlen(password)); //Remaining Length
	const char protocolName[] = "MQTT";
	//Encode Packet
	packet[packetInd++] = 0x10;  //Connect Packet Type
	packet[packetInd++] = remLen;
	packet[packetInd++] = 0x00;
	packet[packetInd++] =  strlen(protocolName); //0x04
	strcpy(packet+packetInd,protocolName);
	packetInd += strlen(protocolName);
	packet[packetInd++] = 0x04; // Level/Version
	//packet[packetInd++] = 0x02; //flags = clean session only,public broker is used.
	/*
	 * User Name Flag (1)
		Password Flag (1)
		Will Retain (0)
		Will QoS (01)
		Will Flag (1)
		Clean Session (1)
		Reserved (0)
	 * */
	packet[packetInd++] = 0xCE;
	//0xFFFF keep alive time = 18 hours ,12 mins ,15 secs
	packet[packetInd++] = 0xFF;
	packet[packetInd++] = 0xFF;
	//UTF-8
	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(clientID);
	strcpy(packet+packetInd,clientID);
	packetInd += strlen(clientID);
	// Will Topic
	    packet[packetInd++] = 0x00;
	    packet[packetInd++] = strlen(willTopic);
	    strcpy(packet + packetInd, willTopic);
	    packetInd += strlen(willTopic);

	    // Will Message
	    packet[packetInd++] = 0x00;
	    packet[packetInd++] = strlen(willMessage);
	    strcpy(packet + packetInd, willMessage);
	    packetInd += strlen(willMessage);

	    //username
	    packet[packetInd++] = 0x00;
	    packet[packetInd++] = strlen(username);
	    strcpy(packet + packetInd, username);
	    packetInd += strlen(username);

	    //password
	    packet[packetInd++] = 0x00;
	    packet[packetInd++] = strlen(password);
	    strcpy(packet + packetInd, password);
	    packetInd += strlen(password);
	//Send Packet
	Uart_Write_String(packet,packetInd,UART_7);
}

void MQTT_Publish(u8* topic,u8* msg,u32 len,u8 QoS)
{
	packetInd = 0;
	u8 msgInd = 0;
	u8 remLen = (2+ strlen(topic) + len); //Remaining Length

	//Encode Packet
	if(QoS > 0) //Publish Type
	{
		remLen += 2;
		packet[packetInd++] = 0x32; //Dup = 0,RETAIN = 0
	}
	else
	{
		packet[packetInd++] = 0x30; //Dup = 0,RETAIN = 0
	}

	packet[packetInd++] = remLen;
	packet[packetInd++] = 0x00;
	packet[packetInd++] =  strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += strlen(topic);

	if(QoS > 0)
	{
		packet[packetInd++] = (u8)(packetID >> 8); //MSB of packID   if QoS > 0
		packet[packetInd++] = (u8)(packetID); //LSB of packID
		packetID++;
	}
	for(msgInd = 0; msgInd < len; msgInd++)
	{
		packet[packetInd++] = msg[msgInd];
	}
	//Send Packet
	Uart_Write_String(packet,packetInd,UART_7);
}

void MQTT_Subscribe(u8* topic)
{
	u8 remLen = (5 + strlen(topic));
	//encode Packet
	packetInd = 0;
	packet[packetInd++] =0x82; //type
	packet[packetInd++] = remLen;

	packet[packetInd++] = (u8)(packetID >> 8); //MSB of packID
	packet[packetInd++] = (u8)(packetID); //LSB of packID
	packetID++;

	packet[packetInd++] = 0x00;
	packet[packetInd++] =  strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += strlen(topic);
	packet[packetInd++]=0x01; //Requested QoS

	//Send Packet
	Uart_Write_String(packet,packetInd,UART_7);
}

void MQTT_UnSubscribe(u8* topic)
{
	u8 remLen = (5 + strlen(topic));
	//encode Packet
	packetInd = 0;
	packet[packetInd++] =0xA2; //type
	packet[packetInd++] = remLen;

	packet[packetInd++] = (u8)(packetID >> 8); //MSB of packID
	packet[packetInd++] = (u8)(packetID); //LSB of packID
	packetID++;

	packet[packetInd++] = 0x00;
	packet[packetInd++] =  strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += strlen(topic);

	//Send Packet
	Uart_Write_String(packet,packetInd,UART_7);
}

void MQTT_PINGREQ(void)
{
	packetInd = 0;
	packet[packetInd++] = 0xC0; //Type
	//Send Packet
	Uart_Write_String(packet,packetInd,UART_7);
}

void MQTT_Disconnect(void)
{
	packetInd = 0;
	packet[packetInd++] = 0xE0; //Type
	//Send Packet
	Uart_Write_String(packet,packetInd,UART_7);
}
