#include <stdio.h>
#include <stdlib.h>
#define SIZE (4)
#define HASH(key) ((key)*(key) % (SIZE))

//! hash map inplement
#if 0
typedef struct hash {
	int key;
	int index;
	struct hash *next;
} hash;

static hash *g_ptHash[SIZE] = {NULL};

static hash* new_node(int key, int index)
{
	hash *new = calloc(1, sizeof(hash));
	if (!new)
		return NULL;
	new->key = key;
	new->index = index;
	new->next = NULL;
}

static void add_hash(int key, int index)
{
	int hasnum = HASH(key);
	hash **curr = &g_ptHash[hasnum];
	hash *new = new_node(key, index);
	while(*curr)
		curr = &(*curr)->next;

	*curr = new;
}

static void release_hash(void)
{
	hash *curr = NULL;
	hash *remove = NULL;
	for (size_t i = 0; i < SIZE; i++) {
		curr = g_ptHash[i];
		while(curr) {
			remove = curr;
			curr = curr->next;
			free(remove);
		}
	}
}

static void show_hash(void)
{
	hash *curr = NULL;
	for (size_t i = 0; i < SIZE; i++) {
		curr  = g_ptHash[i];
		while(curr) {
			printf("%d ", curr->key);
			curr = curr->next;
		}
		printf("\n");
	}
}

int *two_sum(int *arr, int len, int target, int *returnSize)
{
	int *result = NULL;
	*returnSize = 2;
	result = calloc(2, sizeof(int));
	for (size_t i = 0; i < len; i++) {
		for (size_t j = i+1; j < len; j++) {
			if (arr[i] + arr[j] == target) {
				result[0] = i;
				result[1] = j;
			}
		}
	}

	return result;
}

static int haskey(int key, int *index)
{
	int bKey = 0;
	int hashnum = HASH(key);
	hash *curr = g_ptHash[hashnum];
	while(curr) {
		if (curr->key == key) {
			bKey = 1;
			*index = curr->index;
			break;
		}
		curr = curr->next;
	}

	return bKey;
}

int *two_sum_mdi(int *arr, int len, int target, int *returnSize)
{
	int *result = NULL;
	*returnSize = 2;
	int x = 0;
	int index = 0;
	result = calloc(2, sizeof(int));

	for (size_t i = 0; i < len; i++) {
		x = target - arr[i];
		if (haskey(x, &index)) {
			result[0] = i;
			result[1] = index;
			break;
		}
		add_hash(arr[i], i);
	}

	show_hash();

	release_hash();
	return result;
}
#endif
#define HASH(key, len) (key)*(key)%(len)
typedef struct hash {
	int key;
	int index;
	struct hash *next;
} hash;

void show(hash **head, int len)
{
	hash *curr = NULL;
	for (size_t i = 0; i < len; i++) {
		curr = head[i];
		while(curr) {
			printf("key %d ", curr->key);
			curr = curr->next;
		}
	}
}

int hasKey(hash **patHash, int len, int key, int *index)
{
	int bhit = 0;
	int hashnum = HASH(key, len);
	hash *curr = patHash[hashnum];
	while(curr) {
		if (curr->key == key) {
			bhit = 1;
			*index = curr->index;
			break;
		}
		curr = curr->next;
	}

	return bhit;
}

hash *new_node(int key, int index)
{
	hash *new = calloc(1, sizeof(hash));
	new->key = key;
	new->index = index;
	new->next = NULL;
	return new;
}

void add_hash(hash **patHash, int len, int key, int index)
{
	int hashnum = HASH(key, len);
	hash **curr = &patHash[hashnum];
	hash *new = new_node(key, index);
	while(*curr)
		curr = &(*curr)->next;
	*curr = new;
}

void release_hash(hash **head, int len)
{
	hash *curr = NULL;
	hash *remove = NULL;
	for (size_t i = 0; i < len; i++) {
		curr = head[i];
		while(curr) {
			remove = curr;
			curr = curr->next;
			free(remove);
		}
	}
}

int* twosum(int* nums, int numsSize, int target, int* returnSize)
{
	int *result = NULL;
	*returnSize = 2;
	result = calloc(2, sizeof(int));
	hash *patHash[numsSize];

	int x = 0;
	int index = 0;
	for (size_t i = 0; i < numsSize; i++)
		patHash[i] = NULL;

	for (size_t i = 0; i < numsSize; i++) {
		x = target - nums[i];
		if (hasKey(patHash, numsSize, x, &index)) {
			result[0] = i;
			result[1] = index;
			break;
		}
		add_hash(patHash, numsSize, nums[i], i);
	}

	show(patHash, numsSize);
	release_hash(patHash, numsSize);
	return result;
}

int main(void)
{
	//int arr[] = {2, 7, 11, 15};
	int arr[] = {3, 2, 4};
	int target = 6;
	int returnSize = 0;
	int len = sizeof(arr)/sizeof(int);
	int *result = NULL;
#if 1
	result = two_sum(arr, len, target, &returnSize);
	for(size_t i = 0; i < returnSize; i++)
		printf("%d ", result[i]);
#endif
	//	result = two_sum_mdi(arr, len, target, &returnSize);
	result = twosum(arr, len, target, &returnSize);
	for(size_t i = 0; i < returnSize; i++)
		printf("%d ", result[i]);
	printf("\n");
	if (result)
		free(result);
	return 0;
}
