#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))


void show(int *pa, int len)
{
	for (size_t i = 0; i < len; i++)
		printf("%d ", pa[i]);
	printf("\n");
}



int cmp(const void * a, const void * b)
{
   return ( *(char *)a - *(char *)b );
}

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{			
	char *tmp = strs[0];
	printf("%s \n", tmp);
}


int main(void)
{
	char *a[] = {"eat","tea","tan","ate","nat","bat"};
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	char ***result = NULL;
	result = groupAnagrams(a, 3, &returnSize, &returnColumnSizes); 
	for (size_t i = 0; i < returnSize; i++) {
		for (size_t j = 0; j < returnColumnSizes[i]; j++) {
			char *tmp = result[i][j];
			printf("%s ", tmp);
		}
		printf("\n");
	}
	return 0 ;
}
