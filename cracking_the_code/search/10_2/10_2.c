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
	int key[26];
	struct hash *next;
}  hash;

int cpmkey(int *pa, int *pb)
{
	int find = 0;
	for (size_t i = 0; i < 26; i++) {
		if (pa[i] != pb[i]) {
			find = 1;
			break;
		}
	}

	return find;
}

int haskey(hash **pptHash, char *tmp, int *pdwKey, int *index)
{
	int len = strlen(tmp);
	int diff = 0;
	int key = 0;
	int find = 0;
	hash *curr = NULL;
	memset(pdwKey, 0, sizeof(int)*26);
	for (size_t i = 0; i < len; i++) {
		diff = *tmp++ - 'a';
		pdwKey[diff]++;
		
	}
	
	for (int i = 0; i < HASH_SIZE; i++) {
		curr = pptHash[i];
		if (curr && !cpmkey(curr->key, pdwKey)) {
			find = 1;
			*index = i;
			break;
		}
	}
	
	return find;
}

void add_hash_string(hash **pptHash, char *tmp, int *key, int index)
{
	hash **curr = &pptHash[index];
	hash *new = calloc(1, sizeof(hash));
	//new->key = key;
	memcpy(new->key, key, sizeof(int)*26);
	new->str = strdup(tmp);
	new->next = NULL;
	while(*curr) 
		curr = &(*curr)->next;
	*curr = new;
}

void add_hash(hash **pptHash, char *tmp, int *key)
{	
	int i;
	hash *new = calloc(1, sizeof(hash));
	//new->key = key;
	memcpy(new->key, key, sizeof(int)*26);
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
			printf("key str %s\n", cur->str);
			cur = cur->next;
		}
	}
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{			
	*returnSize = 0;
	*returnColumnSizes = NULL;
	int j = 0;
	char ***result = NULL;
	int key[26] = {0};
	int index = 0;
	int sum = 0;
	hash *curr = NULL;
	hash *ahash[HASH_SIZE] = {NULL};
	if (!strsSize) {
		return NULL;
	}

	for (size_t i = 0; i < strsSize; i++) {
		char *tmp = strs[i];
		if (!haskey(ahash, tmp, key, &index)) {
			// !push key
			add_hash(ahash, tmp, key); 
		} else {
			//! find key
			add_hash_string(ahash, tmp, key, index);
		}
	}
	//show(ahash);
	
	//! fill data
	for (size_t i = 0; i < HASH_SIZE; i++) {
		curr = ahash[i];
		if (curr) {
			*returnSize = *returnSize + 1;
		}
	}
	//! assume
	*returnColumnSizes = calloc(*returnSize, sizeof(int));
	result = (char ***)calloc(*returnSize, sizeof(char **));
	for (size_t i = 0; i < HASH_SIZE; i++) {
		curr = ahash[i];
		if (curr) {
			sum = 0;
			while (curr) {
				curr = curr->next;
				sum = sum + 1;
			}
			(*returnColumnSizes)[i] = sum;
		}
	}

	for (size_t i = 0; i < *returnSize; i++) {
		result[i] = (char **) calloc((*returnColumnSizes)[i], sizeof(char *));
	}
	
	for (size_t i = 0; i < *returnSize; i++) {
		curr = ahash[i];
		j = 0;
		while(curr) {
			result[i][j++] = strdup(curr->str);			
			curr = curr->next;
		}
	}

	return result;
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
			printf("%s ", result[i][j]);
		}
		printf("\n");
	}
	return 0 ;
}
