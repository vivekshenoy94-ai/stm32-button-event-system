/*
 * event_queue.c
 *
 *  Created on: Apr 3, 2026
 *      Author: vivek
 */


#include "event_queue.h"

static app_event_t queue[EVENT_QUEUE_SIZE];
static uint8_t head = 0;
static uint8_t tail = 0;


void event_queue_init(void){
	/*Initailize both tail and head to 0*/
	head = tail = 0;
}

uint8_t event_queue_push(app_event_t *evt)
{
	/*Find the next element*/
	uint8_t next = (head + 1) % EVENT_QUEUE_SIZE;

	/*Is the queue about to be full?*/
	if(next == tail)
	{
		return 0;
	}

	/*If the queue still has more than 1 slot then fill the current element*/
	queue[head] = *evt;
	head = next;
	return 1;
}

uint8_t event_queue_pop(app_event_t *evt)
{
	/*Is the queue empty?*/
	if(head == tail)
	{
		return 0;
	}
	/*If the queue still has an element then get the current element*/
	*evt = queue[tail];
	tail = (tail+1)% EVENT_QUEUE_SIZE;
	return 1;
}

