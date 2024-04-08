/*
 ============================================================================
 File Name		: I2C_config.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 3/27/2023
 Description	: This file contains the configrations for init function of the I2C driver
 Notes			: 
 ============================================================================
 */




#ifndef I2C_CONFIG_H_
#define I2C_CONFIG_H_

/*
	Operating Modes: (No Slave Mode Added Yet)
	I2C_MASTER
	I2C_SLAVE

	Speed Modes: 
	STANDARD_MODE
	FAST_MODE
	FAST MODE PLUS

	Enable Modes:
	ENABLED
	DISABLED

	Acknowledgement modes:
	ENABLED
	DISABLED

	System Clk: the clock used by the system

	SCL_CLK: the speed of the I2C peripheral
*/

#define I2C_MODE I2C_MASTER
#define I2C_SPEED_MODE	STANDARD_MODE

#define I2C0_ENABLE			ENABLED
#define I2C1_ENABLE			DISABLED
#define I2C2_ENABLE			DISABLED
#define I2C3_ENABLE			DISABLED


#define I2C_ACKNOWLEDGEMENT ENABLED

#define SYSTEM_CLK	20000000UL
#define SCL_CLK		100000UL
#endif