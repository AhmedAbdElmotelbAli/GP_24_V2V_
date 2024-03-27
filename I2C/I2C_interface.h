/*
 ============================================================================
 File Name		: I2C_interface.h
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 3/27/2023
 Description	: This file contains the declarations and public types and macros
 Notes			: 
 ============================================================================
 */


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

#define I2C_ReadOperation       0
#define I2C_WriteOperation      1

typedef enum I2C_ErrorState_t{
    enOK,
    enWrongInputs,
    enSuccess,
    enFailed
} I2C_ErrorState_t;

#endif
