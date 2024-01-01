/*
 * ON_BOARD_SWITCHS.h
 *
 *  Created on: Dec 28, 2023
 *      Author: Ahmed Adel Hasssan
 */

#ifndef ON_BOARD_SWITCHS_ON_BOARD_SWITCHS_H_
#define ON_BOARD_SWITCHS_ON_BOARD_SWITCHS_H_
#include "GPIO.h"
void ON_BOARD_SWITCHS_Init(void);
GPIO_State_t SW1_State(void);
GPIO_State_t SW2_State(void);



#endif /* ON_BOARD_SWITCHS_ON_BOARD_SWITCHS_H_ */
