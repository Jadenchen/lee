#include <stdio.h>
#include <stdlib.h>
#define N (10)
typedef struct stack {
	int data[N];
	int top;
	int min_data[N];
	int min_top;
} stack;

//! pop 
void pop(stack *ps, int *data)
{
	if (ps->top == 0)
		return;
	ps->top--;	
	*data = ps->data[ps->top];
	ps->min_top--;
	ps->min_data[ps->min_top] = 65536;
}

//! push 
void push(stack *ps, int data)
{
	if (ps->top == N)
		return;
	ps->data[ps->top++] = data;
	
	if (!ps->min_top) {
		ps->min_data[ps->min_top++] = data;
	} else {
		int min_data = ps->min_data[ps->min_top - 1];
		min_data = min_data > data ? data : min_data;
		ps->min_data[ps->min_top++] = min_data;
	}

}

//! min
int getmin(stack *ps)
{
	if (ps->top == 0)
		return 65536;
	int index = ps->min_top;
	index--;
	return ps->min_data[index];
}

//! top
int gettop(stack *ps)
{
	if (ps->top == 0)
		return 65536;
	int index = ps->top;
	index--;
	return ps->data[index];
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

void check_min(stack *new)
{
	for (size_t i = 0; i < new->min_top; i++) 
		printf("%d ", new->min_data[i]);
	printf("\n");
}

int main(void)
{
	int a[] = {-2, 0, -3};
	stack *new = init_stack();
	int data = 0;
	push(new, a[0]);
	push(new, a[1]);
	push(new, a[2]);
	pop(new, &data);
	printf("pop data %d \n",data);
	printf("top %d \n", gettop(new));
	printf("min %d \n", getmin(new));
	release_stack(new);
	return 0;
}
