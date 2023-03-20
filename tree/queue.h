#ifndef QUEUE
#define QUEUE
#include <stdint.h>

#define QUEUE_SIZE (20)
#define addr2uint(x) (uint64_t)(void *)(x)
#define uint2addr(x) (void *)(uint64_t)(x)

//! bfs
typedef struct queue {
	int front;
	int end;
	uint64_t data[QUEUE_SIZE];
} queue;

void init_queue(queue *q);
void push_queue(queue *q, void *data);
void *pop_queue(queue *q);
void release_queue(queue *q);
int empty_queue(queue *q);
void *peek_queue(queue *q);
#endif

