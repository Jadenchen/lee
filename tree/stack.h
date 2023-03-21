#ifndef STACK 
#define STACK 
#include <stdint.h>

#define STACK_SIZE (20)
#define addr2uint(x) (uint64_t)(void *)(x)
#define uint2addr(x) (void *)(uint64_t)(x)

//! dfs
typedef struct stack {
	int top;
	uint64_t data[STACK_SIZE];
} stack;

void init_stack(stack *q);
void push_stack(stack *q, void *data);
void *pop_stack(stack *q);
void release_stack(stack *q);
int empty_stack(stack *q);
void *peek_stack(stack *q);
#endif

