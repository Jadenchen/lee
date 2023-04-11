#include <stdlib.h>
#include <string.h>
#include "stack.h"

void init_stack(stack *q)
{
	if (!q)
		return;
	q->top = 0;
	memset(q->data, 0, sizeof(uint64_t)*STACK_SIZE);
}

void push_stack(stack *q, void *data)
{
	if (!q || q->top + 1 == STACK_SIZE)
		return;

	q->data[q->top++] = addr2uint(data);
}

void *pop_stack(stack *q)
{
	if (!q || q->top == 0)
		return NULL;
	q->top--;
	return uint2addr(q->data[q->top]);
}

void release_stack(stack *q)
{
	if (!q)
		return ;
	q->top = 0;
	memset(q->data, 0, sizeof(uint64_t)*STACK_SIZE);
}

int empty_stack(stack *q)
{
	if (!q)
		return 1;
	return q->top == 0;
}

void *peek_stack(stack *q)
{
	if (!q || empty_stack(q))
		return NULL;

	return uint2addr(q->data[q->top - 1]);
}

