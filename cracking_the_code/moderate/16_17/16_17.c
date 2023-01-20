#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))
#define MAX(x, y) (x) > (y) ? (x) : (y)

int findMax(int *nums, int left, int right)
{
	if (left > right)
		return INT_MIN;
	
	int mid = (left + right)/2;
	int curr = 0; 
	int leftmax = 0;
	int rightmax = 0;
	int combinedmax = 0;
	int lefthalf = 0;
	int righthalf = 0;
	//! find left max
	for (int i = mid - 1; i >= left ; i--) {
		curr += nums[i];
		leftmax = MAX(leftmax, curr);
	}

	//! find right max 
	curr = 0;
	for (int i = mid + 1; i <= right; i++) {
		curr += nums[i];
		rightmax = MAX(rightmax, curr);
	}

	combinedmax = rightmax + leftmax + nums[mid];

	lefthalf = findMax(nums, left, mid - 1);
	righthalf = findMax(nums, mid + 1, right);

	return MAX(combinedmax, MAX(righthalf, lefthalf));
}

int findMaxSum(int *nums, int numsSize)
{
#if 0 //! bad solution
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
#endif

#if 0
	//! fast solution 
	//! dynamic solution 
	int curr = nums[0];
	int max = nums[0];
	for (int i = 1; i < numsSize; i++) {
		int num = nums[i];
		curr = MAX(num, curr + num);
		max = MAX(max, curr);
	}

	return max;
#else
	//! divid and conquer
	return findMax(nums, 0, numsSize - 1);
#endif
}

int main(void)
{
	int a[] = {2, -8, 3, -2, 4, -10};
//	int a[] = {1, 2, 3};
	//int a[] = {5,4,-1,7,8};
	int size = sizeof(a)/sizeof(int);
	printf("max sum %d \n", findMaxSum(a, size));
	return 0;
}
