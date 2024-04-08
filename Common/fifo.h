/*
 ============================================================================
 File Name	 	: fifo.c
 Author      	: Ahmed Emad Hassan
 Version     	: 1.0
 Date        	: 11/12/2023
 Description 	: This file contains Queue declarations with configurable type (First in first out)
 Notes       	: 
 ============================================================================
 */
#ifndef FIFO_H_
#define FIFO_H_
#include "stdint.h"


/****** user configuration ******/

/* select element type: uint8_t uint16_t uint32_t */
#define FIFO_element_type uint32_t

/****** end user configuration ******/


/* FIFO data types */
/* pass object reference to functions to make operations on the queue */
typedef struct{
	unsigned int length;
	unsigned int count;
	FIFO_element_type* base;
	FIFO_element_type* head;
	FIFO_element_type* tail;
}FIFO_Buf_t;
/* error state data types returned from functions */
typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_Null
}FIFO_Buf_Status;

/* FIFO functions */
/* initalize Queue by passing struct by refernce to it with all needed paramentrs: used array,length of the array */
FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo,FIFO_element_type* buf,uint32_t length);
/* inserts element to the Queue passed by reference*/
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo, FIFO_element_type item);
/* removes and reads element from the queue passed by reference*/
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo, FIFO_element_type* item);
/* checks if passed queue is full and returns FIFO_full state when full and FIFO_no_error else */
FIFO_Buf_Status FIFO_is_full(FIFO_Buf_t* fifo);
/* checks if passed queue is empty and returns FIFO_empty state when empty and FIFO_no_error else */
FIFO_Buf_Status FIFO_is_empty(FIFO_Buf_t* fifo);
#endif /* FIFO_H_ */
