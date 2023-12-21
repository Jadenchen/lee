#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE (10001)

typedef struct qnode {
	struct qnode *prev;
	struct qnode *next;
	int key;
	int val;
} QNODE;

typedef struct queue {
	QNODE *head;
	QNODE *tail;
	int cnt;
} QUEUE;

typedef struct {
	int capacity;
	QUEUE *queue;
	QNODE **hash;
} LRUCache;


QNODE *create_node(int key, int val)
{
	QNODE *cur = calloc(1, sizeof(QNODE));
	cur->prev = NULL;
	cur->next = NULL;
	cur->key = key;
	cur->val = val;
	return cur;
}

void remove_node(QNODE *cur)
{
	QNODE *prev = cur->prev;
	prev->next = cur->next;
	cur->next->prev = prev;
}

void addtohead(QUEUE *queue, QNODE *node)
{
	QNODE *head = queue->head;
	node->next = head->next;
	head->next = node;

	node->next->prev = node;
	node->prev = head;
}

void movetohead(QUEUE *queue, QNODE *node)
{
	remove_node(node);
	addtohead(queue, node);
}

QUEUE *create_queue(void)
{
	QUEUE *queue = calloc(1, sizeof(QUEUE));
	queue->cnt = 0;
	queue->head = create_node(-1, 0);
	queue->tail = create_node(-1, 0);
	queue->head->next = queue->tail;
	queue->tail->prev = queue->head;
	return queue;
}

LRUCache* lRUCacheCreate(int capacity) {
	LRUCache *obj = calloc(1, sizeof(LRUCache));
	obj->queue = create_queue();
	obj->hash = calloc(HASH_SIZE, sizeof(QNODE *));
	obj->capacity = capacity;
	return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
	if (obj->hash[key]) {
		QNODE *cur = obj->hash[key];
		int data = cur->val;
		movetohead(obj->queue, cur);
		return data;
	}

	return -1;
}

QNODE *pop_tail(QUEUE *queue)
{
	QNODE *tail = queue->tail->prev;
	return tail;
}

void lRUCachePut(LRUCache* obj, int key, int value) {

	if (obj->hash[key]) {
		//! update value
		QNODE *cur = obj->hash[key];
		cur->val = value;
		movetohead(obj->queue, cur);
		return;
	}

	QNODE *new = create_node(key, value);
	obj->hash[key] = new;
	addtohead(obj->queue, new);
	obj->queue->cnt++;

	if (obj->queue->cnt > obj->capacity) {
		QNODE *tail = pop_tail(obj->queue);
		remove_node(tail);
		obj->hash[tail->key] = NULL;
		obj->queue->cnt--;
	}
}

void lRUCacheFree(LRUCache* obj) {
	if (!obj)
		return;

	if (obj->hash)
		free(obj->hash);

	if (obj->queue) {
		QNODE *cur = obj->queue->head;
		while(cur) {
			QNODE *tmp = cur;
			cur = cur->next;
			free(tmp);
		}
	}
	free(obj);
}

int main(void)
{
	int size = 2;
	LRUCache *cache = lRUCacheCreate(size);
	//! put (1, 1)
	lRUCachePut(cache, 1, 1);

	//! put (2, 2)
	lRUCachePut(cache, 2, 2);

	//! get 1
	printf("get 1 %d \n", lRUCacheGet(cache, 1));

	//! put (3, 3)
	lRUCachePut(cache, 3, 3);

	//! get 2
	printf("get 2 %d \n", lRUCacheGet(cache, 2));

	lRUCacheFree(cache);
	return 0;
}

