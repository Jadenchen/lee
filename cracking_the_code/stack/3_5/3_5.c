#include <stdio.h>
#include <stdlib.h>
#define N (10)
typedef struct stack {
	int data[N];
	int top;
} stack;

//! pop 
int pop(stack *ps)
{
	if (ps->top == 0)
		return 65536;
	ps->top--;	
	return ps->data[ps->top];
}

//! push 
void push(stack *ps, int data)
{
	if (ps->top == N)
		return;
	ps->data[ps->top++] = data;
}

//! peek
int peek(stack *ps)
{
	if (ps->top == 0)
		return 65536;
	int index = ps->top;
	index--;
	return ps->data[index];
}

//! 
int isEmpty(stack *new)
{
	return ( new->top == 0);
}

stack *init_stack(void)
{
	stack *new = calloc(1, sizeof(stack));
	return new;
}

void release_stack(stack *new)
{
	if (new) 
		free(new);
}

void sortstack(stack *new, stack *replace)
{
	while(!isEmpty(new)) {
		int tmp = pop(new);
		while(!isEmpty(replace) && peek(replace) > tmp) {
			push(new, pop(replace));
		}
		push(replace, tmp); 
	}

	while(!isEmpty(replace)) {
		push(new, pop(replace));
	}
}
//! time O(N^2) space O(N)
int main(void)
{
	int a[] = {1, 2, 3, 4};
	stack *new = init_stack();
	stack *tmp = init_stack();
	int data = 0;
	push(new, a[0]);
	push(new, a[1]);
	push(new, a[2]);
	push(new, a[3]);
	sortstack(new, tmp);
	printf("data %d\n", pop(new));
	printf("data %d\n", pop(new));
	printf("data %d\n", pop(new));
	printf("data %d\n", pop(new));
	release_stack(new);
	return 0;
}
