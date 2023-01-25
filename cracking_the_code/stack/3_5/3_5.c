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
	if (ps->top + 1 == N)
		return;
	ps->data[ps->top++] = data;
}

//! peek
int peek(stack *ps)
{
	if (ps->top == 0)
		return 65536;
	return ps->data[ps->top - 1];
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

void sortstack2(stack *new, stack *replace)
{
	while(!isEmpty(new)) {
		int tmp = pop(new);
		while(!isEmpty(replace) && peek(replace) > tmp) {
			push(new, pop(replace));
		}

		push(replace, tmp);
	}

	while(!isEmpty(replace)) 
		push(new, pop(replace));
}
//! time O(N^2) space O(N)
int main(void)
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int size = sizeof(a)/sizeof(int);
	stack *new = init_stack();
	stack *tmp = init_stack();
	int data = 0;
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
		push(new, a[i]);
	}
	printf("\n");
	
	sortstack2(new, tmp);
	for (int i = 0; i < size; i++) {
		printf("%d ", pop(new));
	}
	printf("\n");
	release_stack(new);
	release_stack(tmp);
	return 0;
}
