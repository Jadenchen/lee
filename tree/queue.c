#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#include "queue.h"


void init_queue(queue *q)
{
	if (!q)
		return;
	q->front = 0;
	q->end = 0;
	memset(q->data, 0, sizeof(uint64_t)*QUEUE_SIZE);
}

void push_queue(queue *q, void *data)
{
	int index = 0;
	if (!q)
		return;
	index = q->front;	
	q->front = (index + 1)%QUEUE_SIZE;
	q->data[index] = addr2uint(data);
}

void *pop_queue(queue *q)
{
	int index = 0;
	if (!q)
		return NULL;
	index = q->end;
	q->end = (index + 1)%QUEUE_SIZE;
	return uint2addr(q->data[index]);
}

void release_queue(queue *q)
{
	if (q) {
		q->front = 0;
		q->end = 0;
		memset(q->data, 0, sizeof(uint64_t)*QUEUE_SIZE);
	}
}

int empty_queue(queue *q)
{
	if (!q)
		return  false;
	return q->front == q->end;
}

void *peek_queue(queue *q)
{
	if (!q || empty_queue(q))
		return NULL;

	return uint2addr(q->data[q->end]);
}
