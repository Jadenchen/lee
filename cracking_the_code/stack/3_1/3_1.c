#include <stdio.h>
#include <stdlib.h>
#define N (3)
#define SIZE (10)
#if 0
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
#endif
//! using one array into two stack 
typedef struct stack {
	int top1;
	int top2;
	int size;
	int *data;
}stack;

void push(stack *s, int val)
{
	int n = s->size/2;
	if (s->top1 < n) {
		s->data[s->top1] = val;
		s->top1++;
	} else {
		s->data[s->top2] = val;
		s->top2++;
	}
}

int pop(stack *s)
{
	int n = s->size/2;
	int data = 0;
	if (s->top2 > n) {
		data = s->data[s->top2 - 1];
		s->top2--;
	} else {
		data = s->data[s->top1 - 1];
		s->top1--;
	}
	return data;
}

int peek(stack *s)
{
	if (s->top2 > s->size/2) 
		return s->data[s->top2 - 1];
	else 
		return s->data[s->top1 - 1];
}

int isEmpty(stack *s)
{
	return s->top1 == 0;
}

stack *init_stack(int n)
{
	stack *new = calloc(1, sizeof(stack));
	new->size = n;
	new->top1 = 0;
	new->top2 = n/2;
	new->data = calloc(n, sizeof(int));
	return new;
}

void release_stack(stack *s)
{
	if (s)
		free(s);
}

int main(void)
{
	int a[] = {1, 2, 3, 4 ,5 ,6, 7};
	int len = sizeof(a)/sizeof(int);
	stack *s = init_stack(10);
	for (int i = 0; i < len; i++) {
		printf("%d ", a[i]);
		push(s, a[i]);
	}
	printf("\n");
	for (int i = 0; i < len; i++) 
		printf("%d ", pop(s));
	printf("\n");

	release_stack(s);
	return 0 ;
}
