#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

typedef struct bucket {
	int x;
	int y;
} bucket;

int **pairsum(int *nums, int size, int target, int *returnSize, int **returnColSize)
{
	int **res = NULL;
	bucket arr[size];
	int tmp = 0;
	int find = 0;
	if (size == 0) { 
		*returnSize = 0;
		*returnColSize = NULL;
		return res;
	}
	
	memset(arr, 0, sizeof(bucket)*size);
	
	for (size_t i = 0; i < size; i++) {
		arr[i].x = nums[i];
		tmp = target - nums[i];
		find = 0;
		for (size_t j = 0; j < size; j++) {
			if (nums[j] == tmp) {
				arr[i].y = tmp;
				find = 1;
				break;
			}
		}
		if (!find) 
		       arr[i].y = ERROR;	
	}

	for (size_t i = 0; i < size; i++) {
		if (arr[i].y != ERROR)
			*returnSize = *returnSize + 1;	
	}
		
	*returnColSize = (int *)calloc(*returnSize, sizeof(int));
	for (size_t i = 0; i < *returnSize; i++) 
		(*returnColSize)[i] = 2;
	
	res = (int **) calloc(*returnSize, sizeof(int *));
	for (size_t i = 0; i < *returnSize; i++) {
		res[i] = (int *)calloc((*returnColSize)[i], sizeof(int));
	}
	for (size_t i = 0; i < size; i++) {
		if (arr[i].y != ERROR) {
			res[i][0] = arr[i].x;
			res[i][1] = arr[i].y;
		}
	}
	return res;
}

int main(void)
{
	int a[] = {1, 5, 7, -1, 5};
	int size = sizeof(a)/sizeof(int);
	int target = 6;
	int returnSize = 0;
	int *returnColSize = NULL;
	int **res = NULL;
	res = pairsum(a, size, target, &returnSize, &returnColSize);
	for (size_t i = 0; i < returnSize; i++) {
		for (size_t j = 0; j < returnColSize[i]; j++) {
			printf("%d ", res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
