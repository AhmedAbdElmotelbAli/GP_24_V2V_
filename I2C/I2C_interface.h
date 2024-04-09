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

#define I2C_ReadOperation       0U
#define I2C_WriteOperation      1U
/* Error Type: contains different error types that can be returned by a function */
typedef enum I2C_ErrorState_t{
    enOK,
    enWrongInputs,
    enSuccess,
    enFailed
} I2C_ErrorState_t;

/* Functions Prototypes */


/******************************************************************************
 * Function:    MI2C_voidInit
 * Description: Initializes the I2C module.
 * Parameters:  Void
 * Returns:     Void
 ******************************************************************************/
void MI2C_voidInit(void);
/******************************************************************************
 * Function:    MI2C0_MasterStart
 * Description: Starts Master and sends first byte.
 * Parameters:  slaveAddress => one byte contains the address of the slave to communicate with.
 *              RW => Choose to read from slave or write to slave by chosing one of the following values:
 *                 I2C_ReadOperation    I2C_WriteOperation 
 * 
 * Returns:     I2C_ErrorState_t => enum can be one of the following values:
 *                  enOK    enWrongInputs   enSuccess   enFailed
 * Notes:       After Sending all the needed data communication must be stopped using MI2C0_MasterStop function.
 ******************************************************************************/
I2C_ErrorState_t MI2C0_MasterStart(u8 slaveAddress,u8 RW,u8 FirstByte);
/******************************************************************************
 * Function:    MI2C0_MasterSendData
 * Description: Sending data after starting master for Master mode only.
 * Parameters:  DataByte => one byte contains the data to be sent
 * 
 * Returns:     I2C_ErrorState_t => enum can be one of the following values:
 *                  enOK    enWrongInputs   enSuccess   enFailed
 * Notes:       The function used after calling MI2C0_MasterStart function or another sending function.
 *              If we want to send multiple data bytes we call this function multiple times.
 *              After Sending all the needed data, communication must be stopped using MI2C0_MasterStop function.
 ******************************************************************************/
I2C_ErrorState_t MI2C0_MasterSendData(u8 DataByte);
/******************************************************************************
 * Function:    MI2C0_MasterReceiveData
 * Description: Receiveing data after starting master for Master mode only.
 * Parameters:  RecievedByte => contains the address of variable holds one byte.
 *              that will contain the data recieved byte.
 * 
 * Returns:     I2C_ErrorState_t => enum can be one of the following values:
 *                  enOK    enWrongInputs   enSuccess   enFailed
 * Notes:       The function used after calling MI2C0_MasterStart function or another receiveing function.
 *              If we want to recieve multiple data bytes we call this function multiple times.
 *              After Recieving all the needed data, communication must be stopped using MI2C0_MasterStop function.
 ******************************************************************************/
I2C_ErrorState_t MI2C0_MasterReceiveData(u8 *RecievedByte);
/******************************************************************************
 * Function:    MI2C0_MasterStop
 * Description: Ends the communication between master and slave.
 * Parameters:  void
 * Returns:     void
 * Notes:       It must be used after every communication
 ******************************************************************************/
void MI2C0_MasterStop(void);
#endif
