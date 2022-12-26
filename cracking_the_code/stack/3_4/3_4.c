
#include <stdio.h>
#include <stdlib.h>
#define N (10)

typedef struct queue {
	int dataA[N];
	int topA;
	int dataB[N];
	int topB;
}queue;	

queue *init_queue(void)
{
	queue *new = calloc(1, sizeof(queue));
	return new;
}

void release_queue(queue *new)
{
	if (new)
		free(new);
}

void pushA(queue *new, int data)
{
	if (new->topA == N)
		return;
	new->dataA[new->topA++] = data;
}

void pushB(queue *new, int data)
{
	if (new->topB == N)
		return;
	new->dataB[new->topB++] = data;
}

int popA(queue *new)
{
	int data = 0;
	if (new->topA == 0)
		return data;
	new->topA--;
	data = new->dataA[new->topA];	
	return data;
}

int popB(queue *new)
{
	int data = 0;
	if (new->topB == 0)
		return data;
	new->topB--;
	data = new->dataB[new->topB];
	return data;
}

int isBEmpty(queue *new)
{
	return new->topB == 0;
}

int isAEmpty(queue *new)
{
	return new->topA == 0;
}

void push(queue *new, int data)
{
	//! push A only
	pushA(new, data);
}

int pop(queue *new)
{
	if (isBEmpty(new)) {
		//! copy all data 
		while(!isAEmpty(new)) {
			int data = popA(new);
			pushB(new, data); 
		}
		return popB(new); 
	} else {
		return popB(new);
	}
}

int main(void)
{
	int a[] = {1, 2, 3, 4};
	queue *new = init_queue();
	push(new, 1);
	push(new, 2);
	push(new, 3);
	push(new, 4);
	printf("pop %d \n", pop(new));
	push(new, 5);
	
	printf("pop %d \n", pop(new));
	printf("pop %d \n", pop(new));
	printf("pop %d \n", pop(new));
	printf("pop %d \n", pop(new));
	release_queue(new);
	return 0;
}
