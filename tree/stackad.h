#ifndef STACKAD
#define STACKAD 
#include <stdint.h>

#define STACKAD_SIZE (20)
#define addr2uint(x) (uint64_t)(void *)(x)
#define uint2addr(x) (void *)(uint64_t)(x)

typedef struct stack_info {
	uint64_t data;
	uint32_t val;
} stack_info;
//! dfs
typedef struct stackad {
	int top;
	stack_info info[STACKAD_SIZE];
} stackad;

void init_stackad(stackad *q);
void push_stackad(stackad *q, stack_info *data);
stack_info *pop_stackad(stackad *q);
void release_stackad(stackad *q);
int empty_stackad(stackad *q);
stack_info *peek_stackad(stackad *q);
#endif

