#include <stdio.h>
#include <stdlib.h>
#define SIZE (4)
#define HASH(key) ((key)*(key) % (SIZE))

//! hash map inplement
typedef struct hash {
	int key;
	int index;
	struct hash *next;
} hash;

static hash *g_ptHash[SIZE] = {NULL};

static hash* new_node(int key)
{
	hash *new = calloc(1, sizeof(hash));
	if (!new)
		return NULL;
	new->key = key;
	new->next = NULL;
}

static void add_hash(int key, int index)
{
	int hasnum = HASH(key);
	hash **curr = &g_tHash[hasnum];
	hash *new = new_node(key, index);
	while(*curr) {
		curr = &(*curr)->next;
	}
	
	curr->next = new;
}

static void release_hash(void)
{
	hash *curr = NULL;
	hash *remove = NULL;
	for (size_t i = 0; i < SIZE; i++) {
		curr = &g_tHash[i];
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
		curr  = &g_tHash[i];	
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

static int haskey(int key) 
{
	hash **curr = NULL;
	int index = HASH(key);
	printf("index %d key %d \n", index, key);

	curr = &g_ptHash[index];
	while(*curr) {
		if (curr->key == key)
			break;

		curr = &(*curr)->next;
	}

	return curr->index;
}

int *two_sum_mdi(int *arr, int len, int target, int *returnSize)
{
	int *result = NULL;
	*returnSize = 2;
	int x = 0;
	result = calloc(2, sizeof(int));

	for (size_t i = 0; i < len; i++) {
		x = target - arr[i];
		printf("x %d arr %d \n", x, arr[i]);
		if (haskey(x)) {
			//result[0] = i;
			//result[1] = 
		}
		add_hash(arr[i], i);
	}	

	show_hash();


	release_hash();
	return result;
}

int main(void)
{
	int arr[] = {2, 7, 11, 15};
	int target = 9;
	int returnSize = 0;
	int len = sizeof(arr)/sizeof(int);
	int *result = NULL;
#if 0
	result = two_sum(arr, len, target, &returnSize);
	for(size_t i = 0; i < returnSize; i++) 
		printf("%d ", result[i]);
#endif
	result = two_sum_mdi(arr, len, target, &returnSize);
	for(size_t i = 0; i < returnSize; i++) 
		printf("%d ", result[i]);
	printf("\n");
	if (result)
		free(result);
	return 0;
}
