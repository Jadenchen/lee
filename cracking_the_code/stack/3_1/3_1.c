#include <stdio.h>
#include <stdlib.h>
#define N (3)
typedef struct stack {
	int *data;
	int top;
} stack;

typedef struct array_stack {
	stack array[3];
	int size;
	int data[3];
} array_stack;

int isFull(stack *new)
{
	return new->top == 1;
}

int isEmpty(stack *new)
{
	return new->top == 0;
}

void pop(stack *new, int *data)
{
	if (new->top == 0)
		return;
	new->top--;
	*data = new->data[new->top];	
}

//! pop 
void pop_arr(array_stack *arrstack, int *data)
{
	for (size_t i = 0; i < N; i++) {
		if (!isEmpty(&arrstack->array[i])) {
			printf("pop\n");
			pop(&arrstack->array[i], data);
		}
	}
}

void push(stack *new, int data) 
{
	if(new->top == N/3)
		return;
	new->data[new->top] = data;
	new->top++;
}

//! push 
void push_arr(array_stack *arrstack, int data)
{
	for (size_t i = 0; i < N; i++) {
		if (!isFull(&arrstack->array[i])) {
			printf("push\n");
			push(&arrstack->array[i], data);
		}
	}
}

//! top
int gettop(stack *ps)
{
#if 0
	if (ps->top == 0)
		return 65536;
	int index = ps->top;
	index--;
	return ps->data[index];
#endif
}

array_stack *init_arrstack(void)
{
	array_stack *new = calloc(1, sizeof(array_stack));
	new->size = 3;
	for(size_t i = 0; i < N; i++) 
		new->array[i].data = &new->data[i*(N/3)];

	return new;
}

void release_arrstack(array_stack *new)
{
	if (new)
		free(new);
}

void show_array(int *arr, int len)
{
	for (size_t i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int main(void)
{
	int a[N] = {0};
	int data = 0;
	array_stack *new = init_arrstack();
	push_arr(new, 0);
	push_arr(new, 1);
	push_arr(new, 3);
	show_array(new->data, new->size);
	pop_arr(new, &data);
	printf("data %d \n", data);	
	pop_arr(new, &data);
	printf("data %d \n", data);	
	pop_arr(new, &data);
	printf("data %d \n", data);	
	release_arrstack(new);
	//! stack 1 [0, 1)
	//! stack 2 [1, 2)
	//! stack 3 [2, 3)	
	return 0 ;
}
