#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes)
{
	//! sort
	int min = 0; 
	int x[arrSize];
	int y[arrSize];
	int cnt = 0;
	int **result = NULL;
	memset(x, 0, sizeof(int)*arrSize);
	memset(y, 0, sizeof(int)*arrSize);

	qsort(arr, arrSize, sizeof(int), cmp);
#if 0
	for(size_t i = 0; i < arrSize; i++)
		printf("%d ", arr[i]);
#endif

	//! find min
	min = abs(arr[1] - arr[0]);
	for (int i = 2; i < arrSize; i++) {
		int tmp = abs(arr[i] - arr[i - 1]);	
		if (tmp < min)
			min = tmp;
	}
//	printf("\n min %d \n", min);
	//! find pair
	for (int i = 0; i < arrSize - 1; i++) {
		if (abs(arr[i] - arr[i+1]) == min) {
			x[cnt] = arr[i];
			y[cnt] = arr[i+1];
			cnt++;
		}	
	}	
#if 0
	for (size_t i = 0; i < cnt; i++)
		printf("%d %d \n", x[i], y[i]);
#endif

	*returnSize = cnt;
	*returnColumnSizes = calloc(cnt, sizeof(int));
	for (size_t i = 0; i < cnt; i++)
		(*returnColumnSizes)[i] = 2;

	result = calloc(cnt, sizeof(int *));
	for (size_t i = 0; i < cnt; i++) {
		result[i] = calloc(2, sizeof(int));
		result[i][0] = x[i]; 
		result[i][1] = y[i];
	}
#if 0 
	printf("\n");
	for(size_t i = 0; i < cnt; i++) {
		printf("%d %d \n", result[i][0], result[i][1]);

	}
#endif
	return result;	
}

int main(void)
{
	int a[] = {1,3,6,10,15};
//	int a[] = {3, 8,-10,23,19,-4,-14,27};
	int size = sizeof(a)/sizeof(int);
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	int **result = NULL;
	result = minimumAbsDifference(a, size, &returnSize, &returnColumnSizes);
	for (size_t i = 0; i < returnSize; i++) {
		for (size_t j = 0; j < returnColumnSizes[i]; j++) {
			printf("%d ", result[i][j]);	
		}
		printf("\n");
	}
	return 0;
}
