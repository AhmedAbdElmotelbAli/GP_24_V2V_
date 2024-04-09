/*
 ============================================================================
 File Name		: I2C_program.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 3/27/2023
 Description	: This file contains the implementation of I2C Driver
 Notes			: 
 ============================================================================
 */


#include "I2C_private.h"
#include "I2C_config.h"
#include "I2C_interface.h"

#include "Std_types.h"
#include "Bit_Math.h"
/*
    I2C0	PB2	PB3
    I2C1	PA6	PA7
    I2C2	PE4	PE5
    I2C3	PD0	PD1
    */
void MI2C_voidInit(void){
    /* page 1010 */


    #if I2C0_ENABLE == ENABLED
        /* Enable I2C0	PB2	PB3*/
        /* Enable the I2C clock using RCGCI2C reg */
        //Enable I2C0 R0
        SET_BIT(RCGCI2C,R0);
        /* Enable the clock with GPIO module using RCGCGPIO */
        /* Enable PortB clock R1 */
        SET_BIT(RCGCGPIO,R1);
        /* in GPIO module enable pins for alternate func using GPIOAFSEL reg */
        /* put 0 value in alternate function select register */
        CLR_BIT(GPIOB_AFSEL_APB,2);
        CLR_BIT(GPIOB_AFSEL_APB,3);
        /* Enable I2CSDA for open-drain operation */
        /* put 1 value in open drain register */
        SET_BIT(GPIOB_ODR_APB,2);
        SET_BIT(GPIOB_ODR_APB,3);
        /* Configure the PMCn field in the GPIOPCTL reg to assign I2C signals to appropriate pins */
        //for pin B2
        SET_BIT(GPIOB_CTL_APB,PMC2_0);
        SET_BIT(GPIOB_CTL_APB,PMC2_1);
        CLR_BIT(GPIOB_CTL_APB,PMC2_2);
        CLR_BIT(GPIOB_CTL_APB,PMC2_3);
        //for pin B3
        SET_BIT(GPIOB_CTL_APB,PMC3_0);
        SET_BIT(GPIOB_CTL_APB,PMC3_1);
        CLR_BIT(GPIOB_CTL_APB,PMC3_2);
        CLR_BIT(GPIOB_CTL_APB,PMC3_3);
        /* Initialize the I2C Master by writing the I2CMCR register with a value of 0x0000.0010 */
        I2C0_MCR = 0x00000010;
        /* Set the desired SCL clock speed of 100 Kbps by writing I2CMTPR reg with the number of system clock periods in one SCL clock period */
        // TPR = (System Clock/(20*SCL_CLK))-1;
        I2C0_MTPR |= (SYSTEM_CLK /(2UL * SCL_CLK))-1UL;
        /* Acknowledgement */
        if(I2C_ACKNOWLEDGEMENT == ENABLED){
            SET_BIT(I2C0_MCS,ACK);
        }else{
            CLR_BIT(I2C0_MCS,ACK);
        }
    #endif
            
    #if I2C1_ENABLE == ENABLED
        /* Enable I2C1	PA6	PA7*/
        /* Enable the I2C clock using RCGCI2C reg */
        //Enable I2C1 R1
        SET_BIT(RCGCI2C,R1);
        /* Enable the clock with GPIO module using RCGCGPIO */
        /* Enable PortA clock R0 */
        SET_BIT(RCGCGPIO,R0);
        /* put 0 value in alternate function select register */
        CLR_BIT(GPIOA_AFSEL_APB,6);
        CLR_BIT(GPIOA_AFSEL_APB,7);
        /* put 1 value in open drain register */
        SET_BIT(GPIOA_ODR_APB,6);
        SET_BIT(GPIOA_ODR_APB,7);
        /* Configure the PMCn field in the GPIOPCTL reg to assign I2C signals to appropriate pins */
        //for pin A6
        SET_BIT(GPIOA_CTL_APB,PMC6+0);
        SET_BIT(GPIOA_CTL_APB,PMC6+1);
        CLR_BIT(GPIOA_CTL_APB,PMC6+2);
        CLR_BIT(GPIOA_CTL_APB,PMC6+3);
        //for pin A7
        SET_BIT(GPIOA_CTL_APB,PMC7+0);
        SET_BIT(GPIOA_CTL_APB,PMC7+1);
        CLR_BIT(GPIOA_CTL_APB,PMC7+2);
        CLR_BIT(GPIOA_CTL_APB,PMC7+3);
        /* Configure the PMCn field in the GPIOPCTL reg to assign I2C signals to appropriate pins */
        I2C1_MCR = 0x00000010;
        /* Set the desired SCL clock speed of 100 Kbps by writing I2CMTPR reg with the number of system clock periods in one SCL clock period */
        /* TPR = (System Clock/(20*SCL_CLK))-1; */
        I2C1_MTPR |= (SYSTEM_CLK /(20 * SCL_CLK))-1;
        /* Acknowledgement */
        if(I2C_ACKNOWLEDGEMENT == ENABLED){
            SET_BIT(I2C1_MCS,ACK);
        }else{
            CLR_BIT(I2C1_MCS,ACK);
        }
    #endif

    #if I2C2_ENABLE == ENABLED
        /* Enable I2C2	PE4	PE5*/
        /* Enable the I2C clock using RCGCI2C reg */
        //Enable I2C2 R2
        SET_BIT(RCGCI2C,R2);
        /* Enable PortE clock R4 */
        SET_BIT(RCGCGPIO,R4);
        /* put 0 value in alternate function select register */
        CLR_BIT(GPIOE_AFSEL_APB,4);
        CLR_BIT(GPIOE_AFSEL_APB,5);
        /* put 1 value in open drain register */
        SET_BIT(GPIOE_ODR_APB,4);
        SET_BIT(GPIOE_ODR_APB,5);
        /* Configure the PMCn field in the GPIOPCTL reg to assign I2C signals to appropriate pins */
        //for pin E4
        SET_BIT(GPIOE_CTL_APB,PMC4+0);
        SET_BIT(GPIOE_CTL_APB,PMC4+1);
        CLR_BIT(GPIOE_CTL_APB,PMC4+2);
        CLR_BIT(GPIOE_CTL_APB,PMC4+3);
        //for pin E5
        SET_BIT(GPIOE_CTL_APB,PMC5+0);
        SET_BIT(GPIOE_CTL_APB,PMC5+1);
        CLR_BIT(GPIOE_CTL_APB,PMC5+2);
        CLR_BIT(GPIOE_CTL_APB,PMC5+3);
        /* Configure the PMCn field in the GPIOPCTL reg to assign I2C signals to appropriate pins */
        I2C2_MCR = 0x00000010;
        /* Set the desired SCL clock speed of 100 Kbps by writing I2CMTPR reg with the number of system clock periods in one SCL clock period */
        /* TPR = (System Clock/(20*SCL_CLK))-1; */
        I2C2_MTPR |= (SYSTEM_CLK /(20 * SCL_CLK))-1;
        /* Acknowledgement */
        if(I2C_ACKNOWLEDGEMENT == ENABLED){
            SET_BIT(I2C2_MCS,ACK);
        }else{
            CLR_BIT(I2C2_MCS,ACK);
        }
    #endif

    #if I2C3_ENABLE == ENABLED
        /* Enable I2C3	PD0	PD1*/
        /* Enable the I2C clock using RCGCI2C reg */
        SET_BIT(RCGCI2C,R3);
        /* Enable PortD clock R3 */
        SET_BIT(RCGCGPIO,R3);
        /* put 0 value in alternate function select register */
        CLR_BIT(GPIOD_AFSEL_APB,0);
        CLR_BIT(GPIOD_AFSEL_APB,1);
        /* put 1 value in open drain register */
        SET_BIT(GPIOD_ODR_APB,0);
        SET_BIT(GPIOD_ODR_APB,1);
        /* Configure the PMCn field in the GPIOPCTL reg to assign I2C signals to appropriate pins */
        //for pin D0
        SET_BIT(GPIOD_CTL_APB,PMC0+0);
        SET_BIT(GPIOD_CTL_APB,PMC0+1);
        CLR_BIT(GPIOD_CTL_APB,PMC0+2);
        CLR_BIT(GPIOD_CTL_APB,PMC0+3);
        //for pin D1
        SET_BIT(GPIOD_CTL_APB,PMC1+0);
        SET_BIT(GPIOD_CTL_APB,PMC1+1);
        CLR_BIT(GPIOD_CTL_APB,PMC1+2);
        CLR_BIT(GPIOD_CTL_APB,PMC1+3);
        /* Configure the PMCn field in the GPIOPCTL reg to assign I2C signals to appropriate pins */
        I2C3_MCR = 0x00000010;
        /* Set the desired SCL clock speed of 100 Kbps by writing I2CMTPR reg with the number of system clock periods in one SCL clock period */
        /* TPR = (System Clock/(20*SCL_CLK))-1; */
        I2C3_MTPR = 0;
        I2C3_MTPR |= (SYSTEM_CLK /(20 * SCL_CLK))-1;
        /* Acknowledgement */
        if(I2C_ACKNOWLEDGEMENT == ENABLED){
            SET_BIT(I2C3_MCS,ACK);
        }else{
            CLR_BIT(I2C3_MCS,ACK);
        }
    #endif

}

I2C_ErrorState_t MI2C0_MasterStart(u8 slaveAddress,u8 RW,u8 FirstByte){
    I2C_ErrorState_t Local_ErrorState = enOK;
    /* Specify the slave address of the master and that the next operation using I2CMSA reg with value 0x0000.0076 */
        if((RW == I2C_ReadOperation)||(RW == I2C_WriteOperation)){
            /* Write Slave Address to I2CMSA */
            if(RW == I2C_ReadOperation)
            {//choose read operation and send slave address
                I2C0_MSA = ((slaveAddress<<1U)|1U);
            }
            else
            {//choose write operation and send slave address
                I2C0_MSA = ((slaveAddress<<1U)|0U);
            }
            /* write data to I2CMDR if taransmit*/
            if(RW == I2C_WriteOperation){
                I2C0_MDR = FirstByte;
            }
            /* Wait until BUSBSY is 0 */
            while(GET_BIT(I2C0_MCS,BUSBSY) == ONE){/* Wait */};
            /* Write ---0-011 to I2CMCS on transmit or ---01011 (ACK)*/
            if(RW == I2C_WriteOperation){
                I2C0_MCS &= 0b11101011;
                I2C0_MCS |= 0b00000011;
            }else{
                I2C0_MCS &= 0b11101011;
                I2C0_MCS |= 0b00001011;
            }

            /* Read I2CMCS (Busy bit wait) */
            while(GET_BIT(I2C0_MCS,BUSY) == ZERO){/* Wait */};
            /* Check Error bit */
            if(GET_BIT(I2C0_MCS,ERROR) == ZERO){
                //success
                Local_ErrorState = enSuccess;
            }else{
                //Error
                Local_ErrorState = enFailed;
            }
        }
        else{
            Local_ErrorState = enWrongInputs;
        }

    return Local_ErrorState;
}

I2C_ErrorState_t MI2C0_MasterSendData(u8 DataByte){
    I2C_ErrorState_t Local_ErrorState = enOK;
    if(DataByte != NULL){
        /* Write Data to I2CMDR */
        I2C0_MDR = DataByte;
        /* Write ---0-011 to I2CMCS (start condition + transmitting) */
        I2C0_MCS &= 0b11101001;
        I2C0_MCS |= 0b00000001;
        /* Check if sending busy */
        while(GET_BIT(I2C0_MCS,BUSY) == ONE){/* Wait */};
        /* check the ERROR bit in the I2CMCS to confirm the transmit was acknowledged */
        if(GET_BIT(I2C0_MCS,ERROR) == ZERO){//No error occurred
            Local_ErrorState = enSuccess;
        }
        else {//Error occurred
            Local_ErrorState = enFailed;
        }
    }
    else
    {
        Local_ErrorState = enWrongInputs;
    }
    return Local_ErrorState;
}

I2C_ErrorState_t MI2C0_MasterReceiveData(u8 *RecievedByte){
    I2C_ErrorState_t local_ErrorState = enOK;
    if(RecievedByte != NULL){
        /* Read Data from MDR */
        *RecievedByte = I2C0_MDR;
        /* Write ---01001 to I2CMCS*/
        I2C0_MCS &= 0b11101001;
        I2C0_MCS |= 0b00001001;
        /* Check if sending busy */
        while(GET_BIT(I2C0_MCS,BUSY) == ONE){/* Wait */};
        /* check the ERROR bit in the I2CMCS to confirm the transmit was acknowledged */
        if(GET_BIT(I2C0_MCS,ERROR) == ZERO){//No error occurred
            local_ErrorState = enSuccess;
        }
        else {//Error occurred
            local_ErrorState = enFailed;
        }
    }else{
        local_ErrorState = enWrongInputs;
    }
    return local_ErrorState;
}

void MI2C0_MasterStop(void){
    SET_BIT(I2C0_MCS,STOP);
}