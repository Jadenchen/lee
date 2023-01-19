#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

int findMaxSum(int *nums, int numsSize)
{
	int asum[numsSize];
	int max = 0;
	memset(asum, 0, sizeof(int)*numsSize);	

	//! find every i max sum
	int sum = 0;
	for (size_t i = 0; i < numsSize; i++) {
		sum = nums[i];	
		max = sum;
		for (size_t j = i + 1; j < numsSize; j++) {
			sum = sum + nums[j];
			if (max < sum) {
				max = sum;
			}
		}
		asum[i] = max;
	}

	max = asum[0];
	for (size_t i = 0; i < numsSize; i++) {
		if (max < asum[i]) 
			max = asum[i];
	}
	return max;
}

int main(void)
{
	int a[] = {2, -8, 3, -2, 4, -10};
	int size = sizeof(a)/sizeof(int);
	printf("max sum %d \n", findMaxSum(a, size));
	return 0;
}
