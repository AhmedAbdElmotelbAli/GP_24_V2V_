
#include <ctype.h>
#include "Rte_CarManager.h"


uint8 static AEB_Flag = 0;
uint8 static flag_help=0;
uint8  AEB = 0;
uint8 static AEB_Flag1 = 0;
uint8 static flag = 0;
uint8 speed = 7;
uint8 static lineCount = 0; 
char receivedChar='s';

char receive;
/**
 *
 * Runnable CarManager_SetHeight
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpCarCtrlBtns_HeightBtnState
 *
 */

static boolean bluetoothvoidcontrol (StepMotorStepType* Step) //bluetooth void control
{
	boolean adjustMotor = FALSE;
	char BluetoothBtnState;
	switch (BluetoothBtnState)
              {
                  case 'F':
							*Step= MOTOR_STEP_Forward;
								 adjustMotor =TRUE ;	
                      break;
                case 'B':
								
							*Step= MOTOR_STEP_Backward;
							 adjustMotor = TRUE;			
                      break;
                  case 'L':   
							*Step= MOTOR_STEP_Left;				
							adjustMotor = TRUE;
						break;
                  case 'R':
                    
							
							*Step= MOTOR_STEP_Right;
							adjustMotor = TRUE;				
                  case 'S':
							*Step= MOTOR_STEP_Stop;
								 adjustMotor = TRUE;
                      	default:
					break;
								
									
              }
			  	return adjustMotor;
}

void CarManager_task1(void) {
    while (1) {
      StepMotorStepType* Step;
			SensorPositionType Current_Distance;
		
        // Read from the appropriate Bluetooth module
        if (flag_help == 0) {
             Rte_Read_rpCarCtrlBtns_BluetoothBtnSignal_2(&receive);
        } else if(flag_help == 1) {
            Rte_Read_rpCarCtrlBtns_BluetoothBtnSignal_1(&receive);
        }else{}

        // Check if the received character is a valid command
        if ((receive == 'B' )  || receive == 'H' || 
            receive == 'J' || receive == 'S' || 
            (receive == 'F' && GET_BIT(AEB_Flag, Forward) == 0) || 
            (receive == 'R' && GET_BIT(AEB_Flag, Right) == 0) || 
            (receive == 'L' && GET_BIT(AEB_Flag, LEFT) == 0) || 
            receive == 'W' || receive == 'w' || receive == 'V' || 
            receive == 'v' || receive == 'X' || receive == 'x' || 
            receive == 'U' || receive == 'u' || receive == 'q' ) 
           {
                
			 (void)Rte_Call_rpUltrasonic_FSensor_GetPosition(&Current_Distance);

     if (receive == 'q') {
     
		Rte_Call_rpMotor_Move(MOTOR_Set_Speed);
    } else if (receive == 'R' || receive == 'L' ) {
     		Rte_Call_rpMotor_Move(MOTOR_Set_Speed);
        bluetoothvoidcontrol(Step);
				Rte_Call_rpMotor_Move(*Step);
    } else if (receive == 'F' &&Current_Distance== SENSOR_POSITION_STEP_1 ) {
   		Rte_Call_rpMotor_Move(MOTOR_Set_Speed);
        bluetoothvoidcontrol(Step);
				Rte_Call_rpMotor_Move(*Step);
    } else if (receive == 'F' && Current_Distance == SENSOR_POSITION_STEP_0){
        		Rte_Call_rpMotor_Move(MOTOR_STEP_Stop);
      
    } else {
  
        bluetoothvoidcontrol(Step);
				Rte_Call_rpMotor_Move(*Step);
    }
         
        }
    }
}


/**
 *
 * Runnable CarManager_SetIncline
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpCarCtrlBtns_InclineBtnState
 *
 */


void CarManager_task2(void) {
	
		SensorPositionType Current_Distance;
		SensorPositionType Current_Distance_R;
		SensorPositionType Current_Distance_L;
		Rte_Call_rpLcd_Lcd_Display(message_choose_place, "Zone :(S\\F\\R\\L\\C)",0,0);
		Rte_Call_rpLcd_Lcd_Display(message_choose_place, "S\\N\\ :(N\\S\\S\\S\\N)",0,0);
		Rte_Call_rpLcd_Lcd_Display(message_choose_place, "R",0,4);
	   (void)Rte_Call_rpUltrasonic_R_Sensor_GetPosition(&Current_Distance_R);
		
		Rte_Call_rpLcd_Lcd_Display(message_choose_place, "L",0,4);
	    (void)Rte_Call_rpUltrasonic_LSensor_GetPosition(&Current_Distance_L);
		
		Rte_Call_rpLcd_Lcd_Display(message_choose_place, "N",0,4);
	    (void)Rte_Call_rpUltrasonic_FSensor_GetPosition(&Current_Distance);
		
	 if (Current_Distance == SENSOR_POSITION_STEP_0) {
		Rte_Call_rpMotor_Move(MOTOR_STEP_Stop);
        AEB_Flag1 = 1;
        SET_BIT(AEB_Flag, Forward);
     	
    } else {
        AEB_Flag1 = 0;
        CLR_BIT(AEB_Flag, Forward);
    }

    if (Current_Distance_R == SENSOR_POSITION_STEP_0) {
        if (receive == 'R' || receive == 'I') {
           Rte_Call_rpMotor_Move(MOTOR_STEP_Stop);
        }
        SET_BIT(AEB_Flag, Right);
       
    } else {
        CLR_BIT(AEB_Flag, Right);
    }

    if (Current_Distance_L == SENSOR_POSITION_STEP_0) {
        if (receive == 'L' || receive == 'G') {
      Rte_Call_rpMotor_Move(MOTOR_STEP_Stop);
        }
        SET_BIT(AEB_Flag, LEFT);
      
    } else {
        CLR_BIT(AEB_Flag, LEFT);
    }
		
       
       
    
}






/**
 *
 * Runnable CarManager_SetSlide
 *
 * Triggered By:
 *  - DataReceivedEventImpl.DRE_rpCarCtrlBtns_SlideBtnState
 *
 */
void CarManager_task4(void){
   
       uint8 speedDecrease = 0;
       uint8 newSpeed = 0;
			uint32 distance;
       boolean check;
			Rte_Call_rpIOSetMotor_IOCheckstop(&check);
        // Check if motor is not stopped
        if (!check) {
           
            
            // Check AEB_Flag1 to decide whether to control speed
            if (AEB_Flag1 == 0) {
              	    (void)Rte_Call_rpUltrasonic_FSensor_GetPosition(&distance); // Measure distance using Ultrasonic sensor
                
                // Check if distance is within acceptable range
                if (distance == SENSOR_POSITION_STEP_1) {
                    speedDecrease = 0.3 * speed;
                    newSpeed = speed - speedDecrease; // Calculate new speed
                    speed = newSpeed;
                    AEB_Flag1 = 1; // Set AEB_Flag1 to indicate decrease in speed

                    Rte_Call_rpMotor_Move(MOTOR_Set_Speed); // Set motor speed
                }
            }
        } 
    
    
}
/**
 *
 * Runnable CarManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_CarManager_AutoHeight_200ms
 *
 */
 
void CarManager_task5(void ){
    while (1) {
        // Read the values from the left and right IR sensors
		uint8 Lanevalue;
			boolean check;
		
		(void)Rte_Call_rpLaneSensor_GetLane(&Lanevalue);
					Rte_Call_rpIOSetMotor_IOCheckstop(&check);    
        
        // Check if the motor is not stopped
        if (!check) {
                // Corrective actions for lane errors
                if (Lanevalue == Change_lane_left )
				Rte_Call_rpMotor_Move(MOTOR_Set_Speed); 	

                } else if (	Lanevalue == Change_lane_right && GET_BIT(AEB_Flag, Right)) {
				Rte_Call_rpMotor_Move(MOTOR_Set_Speed); 
                }
             else if (Lanevalue == Same_lane_white) {
               Rte_Call_rpLcd_Lcd_Display(message_choose_place, "W",1,4);
            } else if ( Lanevalue == Same_lane_black) {
                Rte_Call_rpLcd_Lcd_Display(message_choose_place, "B",1,4);
            }
        }
        

    }


/**
 *
 * Runnable CarManager_AutoHeight
 *
 * Triggered By:
 *  - TimingEventImpl.TE_CarManager_AutoHeight_200ms
 *
 */
 
void CarManager_task3(void) {
       MultiStateBtnType warningMessageSignal;
	   MultiStateBtnType carIdSignal;
	   MultiStateBtnType carType;
				MultiStateBtnType	laneSignal;
    if (lineCount == 4) {
         lineCount = 0;
			   
	(void)Rte_Read_rpCarCtrlBtns_warningMessageSignal(&warningMessageSignal);
	(void)Rte_Read_rpCarCtrlBtns_carIdSignal(&carIdSignal);
	(void)Rte_Read_rpCarCtrlBtns_laneSignal(&laneSignal);
	(void)Rte_Read_rpCarCtrlBtns_carTypeSignal(&carType);

    
	
	Rte_Call_rpLcd_Lcd_Display(message_choose_place,&warningMessageSignal,0,0);
	Rte_Call_rpLcd_Lcd_Display(message_choose_place,&carIdSignal ,0,16);
	Rte_Call_rpLcd_Lcd_Display(message_choose_place,&laneSignal,1,0);
  	Rte_Call_rpLcd_Lcd_Display(message_choose_place,&carType,1,16);
    
  

}
}

 
 
