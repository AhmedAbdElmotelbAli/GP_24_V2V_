/* Include Liberaries */
#include "tm4c123gh6pm.h"
#include "stdio.h"
#include "stdint.h"
#include "stdbool.h"
#include "UART.h"
/* defines */
typedef uint8_t uint08_t;
/* Configrations */
#define MAX_LANE_LENGTH 16
#define UART_NUMBER		5

#define IS_UART5_AVAILABLE	((UART5_FR_R&UART_FR_RXFE) == 0)// with RPI
/* with Mobile Application */
#define IS_UART4_AVAILABLE	((UART4_FR_R&UART_FR_RXFE) == 0)// with Mobile App
/* Defined Types */
typedef enum {DN_NotRecieved, DN_dont_need_medical_assist, DN_needs_medical_assist} eDriverNeed_t;
typedef enum {GDS_Normal_state, GDS_Request_state, GDS_Show_Warning_state, GDS_Drive_state} eGuardian_Drive_State_t;
typedef enum {MD_NotRecievedMessage, MD_Not_Recieved_Medical_Assist, MD_Recieved_Medical_Assist} eMedicalAssistStatus_t;
typedef struct {
	uint32_t speed;
} sCarStatus_t;
typedef enum  { Respond_NotRecieved ,Respond_Accept, Respond_Reject} eRespond_t;

/* Global variables */
eRespond_t eDriverRespond;
eMedicalAssistStatus_t eMedicalAssistStatus = MD_NotRecievedMessage;
eDriverNeed_t eDriverNeed;
eGuardian_Drive_State_t eGardianDriveState;
sCarStatus_t sCarStatus;
eDriverNeed_t eDriverNeed = DN_NotRecieved;

/* Prototypes of functions */
void normal_state();//Tested
void request_state();//Tested
void show_warning_state();//Tested
void drive_state();//Tested
void sendWarningToNearbyVeichles();//Completed
void move_car(sCarStatus_t * local_car_status);//COmplete
void copyCarStatus(sCarStatus_t* local_Pcar_status, sCarStatus_t local_car_status);//Completed
bool is_timed_out();
sCarStatus_t GetFrontCarStatus();//Complete
eRespond_t get_respond_from_driver();//Complete
eDriverNeed_t get_driver_need();//Complete
eMedicalAssistStatus_t getMedicalAssistStatus();//Complete

/* Main Function */
/* Calls Different state functions */
int main() {
	eGardianDriveState = GDS_Normal_state;
	while (1) {
		switch (eGardianDriveState) {
		case GDS_Normal_state:
			normal_state();
			break;
		case GDS_Request_state:
			request_state();
			break;
		case GDS_Show_Warning_state:
			show_warning_state();
			break;
		case GDS_Drive_state:
			drive_state();
			break;
		default:
			break;
		}
	}
	return 0;
}
/* Implementation of functions */
/* Checks if time out event happened */
bool is_timed_out(){
	bool result = false;
	//is time cout happenes in c
	return result;
}
/* Checks the need of driver */
eDriverNeed_t get_driver_need() {
	eDriverNeed_t result = DN_NotRecieved;
	uint8_t data;
	//checks driver need
	//what is the response from the driver (Accept or reject)
	/* driver send from mobile application to tiva C */
	if(IS_UART4_AVAILABLE){
		data=UART4_DR_R;
		if(data == 'X'){
			result = DN_needs_medical_assist;
		}else{
			result = DN_dont_need_medical_assist;
		}
	}else{
		result = DN_NotRecieved;
	}
	return result;
}
/* Normal State that checks need of the driver  */
void normal_state() {
	 //Entered normal State
	 eDriverNeed = get_driver_need();
	 if (eDriverNeed == DN_needs_medical_assist) {
		eGardianDriveState = GDS_Request_state;
	 }
	 else {
		 eGardianDriveState = GDS_Normal_state;
	 }
}
void request_state() {
	 //Entered request state
	 sendWarningToNearbyVeichles();
	 eGardianDriveState = GDS_Show_Warning_state;
}
void show_warning_state() {
	 //Entered show warning state
	 //not confirmed yet so stay at the same state
	 if (!is_timed_out()) {// If timeout not happened
		 eDriverRespond = Respond_Accept/*get_respond_from_driver()*/;
		 if (eDriverRespond == Respond_Accept) {
			 eGardianDriveState = GDS_Drive_state;
		 }
		 else if (eDriverRespond == Respond_Reject) {
			 eGardianDriveState = GDS_Normal_state;
		 }
		 else {
			 eGardianDriveState = GDS_Show_Warning_state;
		 } 
	 }
	 else {
		 eGardianDriveState = GDS_Normal_state;
	 }
}
void drive_state() {
	 //Entered Drive State
	 copyCarStatus(&sCarStatus, GetFrontCarStatus());
	 move_car(&sCarStatus);
	 eMedicalAssistStatus = getMedicalAssistStatus();
	 if (eDriverRespond == MD_Recieved_Medical_Assist) {
		//medical Assist Recieved
		 eGardianDriveState = GDS_Normal_state;
	 }
	 else {
		//stay at the same state
		 eGardianDriveState = GDS_Drive_state;
	 }
	 
}
void sendWarningToNearbyVeichles() {
	 //Send warning to nearby vehicles
	 /* UART Number 5 with RPI */

	 /*UART_TX('V',5);*/
	 Bluetooth2_VoidWriteString("Guardian Driver Help");
}
sCarStatus_t GetFrontCarStatus() {
	static sCarStatus_t result = {0};
	uint8_t data;
	/* Recieve Speed from RPI */
	if(IS_UART5_AVAILABLE){
		data=UART5_DR_R;
		result.speed = data;
	}else{
		/* the speed equals the last speed */
		/*result.speed = 0;*/
	}
	return result;
}
void copyCarStatus(sCarStatus_t * local_sPcarStatus, sCarStatus_t local_sCarStatus) {
	local_sPcarStatus->speed = local_sCarStatus.speed;
}
eMedicalAssistStatus_t getMedicalAssistStatus() {
	eMedicalAssistStatus_t result = MD_NotRecievedMessage;
	char data;
	// Checks if medical assist recieved
	/* Send from RPI to TivaC */
	if(IS_UART5_AVAILABLE){
		data=UART5_DR_R;
		if(data == 'H'){
			result = MD_Recieved_Medical_Assist;
		}else{
			result = MD_Not_Recieved_Medical_Assist;
		}
	}else{
		result = MD_Not_Recieved_Medical_Assist;
	}
	return result;
}
eRespond_t get_respond_from_driver() {
	eRespond_t result = Respond_NotRecieved;
	uint8_t data;
	/* get respond from RPI to tiva */
	if(IS_UART5_AVAILABLE){
		/*data= Bluetooth2_U8Read();
		if(data == 'x'){
			result = Respond_Accept;
		}else{
			result = Respond_Reject;
		}*/
	}else{
		result = Respond_NotRecieved;
	}
	
	return result;
}
void move_car(sCarStatus_t * local_car_status) {
	//move Car with speed local_car_status->speed
	/*UART_TX(local_car_status->speed,4);*/
	Bluetooth_VoidControl(local_car_status->speed);
}
