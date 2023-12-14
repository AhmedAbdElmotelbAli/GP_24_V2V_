/*
 ============================================================================
 File Name		: fifo.c
 Author			: Ahmed Emad Hassan
 Version		: 1.0
 Date			: 11/12/2023
 Description	: This file contains Queue implementation with configurable type (First in first out)
 Notes			: 
 ============================================================================
 */
#include "fifo.h"
#include "stdio.h"
FIFO_Buf_Status FIFO_init(FIFO_Buf_t* fifo,FIFO_element_type* buf,uint32_t length){
	/* check if there are nulls */
	if(!fifo || !buf)
		return FIFO_Null;
	fifo->length = length;
	fifo->count = 0;
	fifo->base = buf;
	fifo->head = buf;
	fifo->tail = buf;

	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_enqueue(FIFO_Buf_t* fifo, FIFO_element_type item){
	/* check not null */
	if(!fifo)
		return FIFO_Null;
	/* check not full */
	if(fifo->count == fifo->length)
		return FIFO_full;
	/* enqueue */
	/* put new item */
	*(fifo->tail) = item;
	/*increment tail*/
	if(fifo->tail >= (fifo->base + fifo->length*sizeof(FIFO_element_type)))
		fifo->tail = fifo->base;
	else
		fifo->tail++;

	/* increment count */
	fifo->count++;
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_dequeue(FIFO_Buf_t* fifo, FIFO_element_type* item){
	/* check not null */
	if(!fifo || !item)
		return FIFO_Null;
	/* check not empty */
	if(fifo->count == 0)
		return FIFO_empty;
	/**** dequeue ****/

	/* take item */
	*item = *(fifo->head);
	/* increment head */
	if(fifo->head >= (fifo->base + (fifo->length)*sizeof(FIFO_element_type)))
			fifo->head = fifo->base;
		else
			fifo->head++;
	/* decrement count */
	fifo->count--;
	/* return no error */
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_is_full(FIFO_Buf_t* fifo){
	/* check not null */
	if(!fifo)
		return FIFO_Null;
	/* check if full */
	if(fifo->count == fifo->length)
		return FIFO_full;
	/* return not full */
	return FIFO_no_error;
}
FIFO_Buf_Status FIFO_is_empty(FIFO_Buf_t* fifo){
	/* check not null */
	if(!fifo)
		return FIFO_Null;
	/* check if empty */
	if(fifo->count == 0)
		return FIFO_empty;
	/* return not empty s*/
	return FIFO_no_error;
}

