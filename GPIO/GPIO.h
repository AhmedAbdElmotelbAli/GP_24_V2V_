/******************************************************************************
 * File:        GPIO.h
 * Author:      Ahmed Adel Hassan
 * Description: This file contains the declarations for GPIO initialization and
 *              control functions for an embedded system.
 ******************************************************************************/
#ifndef _GPIO_H_
#define _GPIO_H_

#include "Type.h"
// Define GPIO port enumeration
typedef enum
{
    /* List the GPIO Ports */
    GPIO_PORTA,
    GPIO_PORTB,
    GPIO_PORTC,
    GPIO_PORTD,
    GPIO_PORTE,
    GPIO_PORTF,

}GPIO_PORT_t;


// Define GPIO pin enumeration
typedef enum
{
    /* List the GPIO Pins */
    GPIO_PIN_0,
    GPIO_PIN_1,
    GPIO_PIN_2,
    GPIO_PIN_3,
    GPIO_PIN_4,
    GPIO_PIN_5,
    GPIO_PIN_6,
    GPIO_PIN_7,

}GPIO_PIN_t;



// Define GPIO pin direction enumeration
typedef enum
{
    GPIO_DIRECTION_INPUT_PUSH_PULL,
    GPIO_DIRECTION_INPUT_PULL_DOWN,
    GPIO_DIRECTION_INPUT_FLOAT,
    GPIO_DIRECTION_OUTPUT

}GPIO_Direction_t;


// Define GPIO pin state enumeration
typedef enum
{
    GPIO_STATE_LOW,
    GPIO_STATE_HIGH,

}GPIO_State_t;

#define PORT_HIGH 0xff
#define PORT_LOW  0x00

/*Initialization*/

/******************************************************************************
 * Function:    GPIO_Init
 * Description: Initializes the GPIO module.
 * Parameters:  None
 * Returns:     None
 ******************************************************************************/
void GPIO_Init(GPIO_PORT_t port,GPIO_PIN_t pin);



/*For Pins*/

/******************************************************************************
 * Function:    GPIO_SetPinDirection
 * Description: Sets the direction of a specific pin.
 * Parameters:
 *              port: GPIO port
 *              pin: GPIO pin
 *              direction: Desired direction of the pin
 * Returns:     None
 ******************************************************************************/
void GPIO_SetPinDirection(GPIO_PORT_t port,GPIO_PIN_t pin,GPIO_Direction_t direction);

/******************************************************************************
 * Function:    GPIO_SetPinState
 * Description: Sets the state of a specific pin.
 * Parameters:
 *              port: GPIO port
 *              pin: GPIO pin
 *              state: Desired state of the pin
 * Returns:     None
 ******************************************************************************/
void GPIO_SetPinState(GPIO_PORT_t port,GPIO_PIN_t pin,GPIO_State_t state);

/******************************************************************************
 * Function:    GPIO_GetPinState
 * Description: Gets the state of a specific pin.
 * Parameters:
 *              port: GPIO port
 *              pin: GPIO pin
 * Returns:     Current state of the pin (GPIO_STATE_LOW or GPIO_STATE_HIGH)
 ******************************************************************************/
GPIO_State_t GPIO_GetPinState(GPIO_PORT_t port,GPIO_PIN_t pin);

/*For Ports*/

/******************************************************************************
 * Function:    GPIO_SetPortDirection
 * Description: Sets the direction of a whole port.
 * Parameters:
 *              port: GPIO port
 *              direction: Desired direction of the port
 * Returns:     None
 ******************************************************************************/
void GPIO_SetPortDirection(GPIO_PORT_t port,GPIO_Direction_t direction);

/******************************************************************************
 * Function:    GPIO_SetPortState
 * Description: Sets the state of a whole port.
 * Parameters:
 *              port: GPIO port
 *              state: Desired state of the port
 * Returns:     None
 ******************************************************************************/
void GPIO_SetPortState(GPIO_PORT_t port,uint08_t state);

/******************************************************************************
 * Function:    GPIO_readPort
 * Description: Reads the state of a whole port.
 * Parameters:
 *              port: GPIO port
 * Returns:     Current state of the port
 ******************************************************************************/
uint08_t GPIO_readPort(GPIO_PORT_t port);

#endif
