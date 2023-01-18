#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

int *divingboard(int shorter, int longer, int k, int *returnSize)
{
	int *res = NULL;
	if (k == 0) {
		*returnSize = 0;
		return res;
	}
	if (shorter == longer) {
		res = (int *)calloc(k, sizeof(int));
		*returnSize = k;
		for (size_t i = 0; i < k; i++) 
			res[i] = shorter*k;
	}

	*returnSize = k + 1;
	res = calloc(k + 1, sizeof(int));
	for (size_t i = 0; i < k + 1; i++) {
		res[i] = (k - i)*shorter + i * longer;
	}

	return res;	
}

int main(void)
{
	int shorter = 1;
	int longer = 2;
	int k = 3;
	int *res = 0;
	int returnSize = 0;
	res = divingboard(shorter, longer, k, &returnSize);
	for (size_t i = 0; i < returnSize; i++) {
		printf("%d \n", res[i]);
	}
	return 0;
}
