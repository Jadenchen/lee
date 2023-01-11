#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

typedef struct hash {
	int key;
	struct hash *next;
}  hash;

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{			
	if (!strsSize)
		return NULL;

	//! hash len
	*returnSize =  	
	//! create hash
	for (size_t i = 0; i < strsSize; i++) {
		char *tmp = strs[i];

	}
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
