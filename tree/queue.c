#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"


void init_queue(QUEUE *q)
{
}
void push_queue(QUEUE *q, void *data)
void *pop_queue(QUEUE *q);
void release_queue(QUEUE *q)
{
	if (q)
		free(q);
}

int empty_queue(QUEUE *q)
{
	if (!q)
		return  false;
	return q->front == q->end;
}
