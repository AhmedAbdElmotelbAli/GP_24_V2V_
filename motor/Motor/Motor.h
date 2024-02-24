/****************************************************************************/
/************************* Name: Ahmed Abdelmotelb Ali     ******************/
/*************************    Date: 25/2/2024             ******************/
/*************************      SWC: Motor          	   ******************/
/*************************    Version: 2.0                 ******************/
/****************************************************************************/
#ifndef _MOTOR_H_
#define _MOTOR_H_


typedef enum
{
    MOTOR_SPEED_LOW,
    MOTOR_SPEED_MID,
    MOTOR_SPEED_HIGH

}Motor_Speed_t;
/* Function Name: Motor_Init
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :        init pin PF0,PF1 TO GENERATE PWM AND PA PIN PA2,PA3,PA6,PA7 IN1,IN2,IN3,IN4
 * Description:   GENERATE PWM AND INIT PORTA
 * */
void Motor_Init(void);
/* Function Name: Motor_Start
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :        Enable PF0,PF1
 * Description:   Enable PWM
 * */
void Motor_Start(void);
/* Function Name: Motor_Stop
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :        PUT LOW IN IN1,IN2,IN3,IN4
 * Description:  STOP TWO MOTOR
 * */
void Motor_Stop(void);
/* Function Name: Motor_GoForward
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :       PUT HIGH IN IN1,IN3 low other
 * Description:   MAKE RC GO FORWORD
 * */
void Motor_GoForward(void);
/* Function Name: Motor_SetSpeed
 * Inputs:        Motor_Speed_t
 * Returns:       void 
 * Pins :       DO DUTYCYCLE
 * Description:   PUT DUTY CYCLE ON PIN
 * */
void Motor_SetSpeed(Motor_Speed_t speed);
/* Function Name: Motor_GoForward
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :       PUT HIGH IN IN2,IN4 low other
 * Description:   MAKE RC GO Backward
 * */
void Motor_Backward(void);
/* Function Name: Motor_Right
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :       PUT HIGH IN IN1 low other
 * Description:   MAKE RC GO Right
 * */
void Motor_Right(void);
/* Function Name: Motor_LEFT
 * Inputs:        Nothing
 * Returns:       void 
 * Pins :       PUT HIGH IN IN3 low other
 * Description:   MAKE RC GO LEFT
 * */
void Motor_LEFT(void);

#endif
