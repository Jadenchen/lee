#include <stdlib.h>
#include <string.h>
#include "stackad.h"

void init_stackad(stackad *q)
{
	if (!q)
		return;
	q->top = 0;
	memset(q->info, 0, sizeof(stack_info)*STACKAD_SIZE);
}

void push_stackad(stackad *q, stack_info *data)
{
	if (!q || q->top + 1 == STACKAD_SIZE)
		return;
	stack_info *cur = data;
	q->info[q->top].data = addr2uint(cur->data);
	q->info[q->top].val = cur->val;
	q->top++;
}

stack_info *pop_stackad(stackad *q)
{
	if (!q || q->top == 0)
		return NULL;
	q->top--;
	return &q->info[q->top];
}

void release_stackad(stackad *q)
{
	if (!q)
		return ;
	q->top = 0;
	memset(q->info, 0, sizeof(stack_info)*STACKAD_SIZE);
}

int empty_stackad(stackad *q)
{
	if (!q)
		return 1;
	return q->top == 0;
}

stack_info*peek_stackad(stackad *q)
{
	if (!q || empty_stackad(q))
		return NULL;
	int index = q->top - 1;
	return &q->info[index];
}

