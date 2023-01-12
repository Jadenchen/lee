#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define HASH_SIZE (100)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

typedef struct hash {
	char *str;	
	int key;
	struct hash *next;
}  hash;

int haskey(hash **pptHash, char *tmp, int *pdwKey, int *index)
{
	int len = strlen(tmp);
	int diff = 0;
	int key = 0;
	int find = 0;
	hash *curr = NULL;
	for (size_t i = 0; i < len; i++) {
		diff = *tmp++ - 'a';
		key = key + diff;
	}
	
	*pdwKey = key;	
	for (int i = 0; i < HASH_SIZE; i++) {
		curr = pptHash[i];
		if (curr && curr->key == key) {
			find = 1;
			*index = i;
			break;
		}
	}
	
	return find;
}

void add_hash_string(hash **pptHash, char *tmp, int key, int index)
{
	hash **curr = &pptHash[index];
	hash *new = calloc(1, sizeof(hash));
	new->key = key;
	new->str = strdup(tmp);
	new->next = NULL;
	while(*curr) 
		curr = &(*curr)->next;
	*curr = new;
}

void add_hash(hash **pptHash, char *tmp, int key)
{	
	int i;
	hash *new = calloc(1, sizeof(hash));
	new->key = key;
	new->str = strdup(tmp);
	new->next = NULL;
	for (i = 0; i < HASH_SIZE; i++) {
		if (!pptHash[i])
			break;
	}
	
	pptHash[i] = new;
}

static void show(hash **pptHash)
{
	hash *cur = NULL;
	for (size_t i = 0; i < HASH_SIZE; i++) {
		cur = pptHash[i];
		while(cur) {
			printf("key %d str %s\n", cur->key, cur->str);
			cur = cur->next;

		}
	}
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{			
	if (!strsSize)
		return NULL;

	int key = 0;
	int index = 0;
	hash *curr = NULL;
	hash *ahash[HASH_SIZE] = {NULL};
	for (size_t i = 0; i < strsSize; i++) {
		char *tmp = strs[i];
		if (!haskey(ahash, tmp, &key, &index)) {
			//push key
			add_hash(ahash, tmp, key); 
		} else {
			//! find key
			add_hash_string(ahash, tmp, key, index);
		}
	}
	show(ahash);
	
	//! fill data
	for (size_t i = 0; i < HASH_SIZE; i++) {
		curr = ahash[i];
		if (curr) {
			*returnSize = *returnSize + 1;
		}
	}

	*returnColumnSizes = (int *)calloc(*returnSize, sizeof(int *));

}

int main(void)
{
	char *a[] = {"eat","tea","tan","ate","nat","bat"};
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	char ***result = NULL;
	result = groupAnagrams(a, 6, &returnSize, &returnColumnSizes); 
	for (size_t i = 0; i < returnSize; i++) {
		for (size_t j = 0; j < returnColumnSizes[i]; j++) {
			char *tmp = result[i][j];
			printf("%s ", tmp);
		}
		printf("\n");
	}
	return 0 ;
}
