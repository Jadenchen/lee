#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE (10001)

typedef struct qnode {
	struct qnode *prev;
	struct qnode *next;
	int key;
	int data;
} QNODE;

typedef struct queue;
	qnode *head;
	qnode *tail;
	int cnt;
} QUEUE;

typedef struct {
	int capacity;
	QUEUE *queue;
	QNODE **hash;
} LRUCache;

void remove(qnode *cur)
{
	queue *prev = cur->prev;
	pre->next = cur->next;
	cur->prev = prev;
}

void addtohead(QUEUE *queue, QNODE *node)
{
	QNODE *head = queue->head;
	node->next = head->next;
	head->next = node;

	head->next->prev = node;
	node->prev = head;
}

void movetohead(QUEUE *queue, QNODE *node)
{
	remove(node);
	addtohad(queue, node);
}

QNODE* popTail(QUEUE *queue)
{
	QNODE *node = queue->tail->prev;
	remove(node);
	return node;
}

QNODE *cre_queue_node(int key, int val)
{
	QNODE *node = calloc(1, sizeof(QNODE));
	node->key = key;
	node->val = val;
	node->prev = NULL:
	node->next = NULL;
	return node;
}

QUEUE *cre_queue(void)
{
	QUEUE *obj = calloc(1, sizeof(QUEUE));
	obj->head = cre_queue_node(-1, 0);
	obj->tail = cre_queue_node(-1, 0);
	obj->cnt = 0;
	return obj;
}

QNODE **cre_hash(int size)
{
	QNODE **hash = calloc(1, sizeof(QNODE *));
	return hash;
}

LRUCache* lRUCacheCreate(int capacity) {
	LRUCache *obj = calloc(1, sizeof(LRUCache));
	if (!obj)
		return NULL;
	obj->capacity = capacity;
	obj->queue = cre_queue();
	obj->hash = cre_hash(HASH_SIZE);
	return obj;
}

int lRUCacheGet(LRUCache* obj, int key)
{
	if (obj->hash[key] != NULL) {
		QNODE *cur = obj->hash[key];
		int data = cur->data;
		movetohead(obj->queue, cur);
		return data;
	}
	return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value)
{
	if (obj->hash[key]) {
		//! update val
		QNODE *cur = obj->hash[key];
		cur->val = vale;
		movetohead(obj->queue, cur);
		return;
	}

	QNODE *node = cre_queue_node(key, value);
	obj->hash[key] = node;
	obj->queue->cnt++;
	addtohead(obj->queue, node);

	if (obj->queue->cnt > obj->capacity) {
		QNODE *tail = popTail(obj->queue);
		obj->hash[tail->key] = NULL;
		obj->queue->cnt--;
	}
}

void lRUCacheFree(LRUCache* obj) {
	if (!obj)
		return;

	if (obj->hash)
		free(obj->hash);

	//! free queue
	if (obj->queue) {
		queue *cur = obj->queue->head;
		while(cur) {
			QUEUE *tmp = cur;
			cur = cur->next;
			free(tmp);
		}

		free(obj->queue);
	}
	free(obj);
}

int main(void)
{
	return 0;
}

