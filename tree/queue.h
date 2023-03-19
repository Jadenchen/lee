#ifndef QUEUE
#define QUEUE

#define QUEUE_SIZE (20)
#define addr2uint (uint64_t)(void *)(x)
#define uint2addr (void *)(uint64_t)(x)

typedef struct QUEUE {
	int front;
	int end;
	uint64_t data[QUEUE_SIZE];
} QUEUE;

void init_queue(QUEUE *q);
void push_queue(QUEUE *q, void *data);
void *pop_queue(QUEUE *q);
void release_queue(QUEUE *q);
int empty_queue(QUEUE *q);
int getlen_queue(QUEUE *q);
#endif

