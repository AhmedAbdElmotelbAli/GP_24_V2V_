/*
 ============================================================================
 File Name		: Bit_Math.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 3/27/2023
 Description	: This file contains macros for operation used in all abstract layers
 Notes			: 
 ============================================================================
 */


#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

#define SET_BIT(Reg, bitnum)       	(Reg |=1<<bitnum)
#define CLR_BIT(Reg, bitnum)     	(Reg &=~(1<<bitnum))
#define TOG_BIT(Reg, bitnum)    	(Reg ^=(1<<bitnum))
#define GET_BIT(Reg, bitnum)       	((Reg>>bitnum)& 0x01)
#define SET_BYTE(Reg,value)         ( Reg = value )

#endif
