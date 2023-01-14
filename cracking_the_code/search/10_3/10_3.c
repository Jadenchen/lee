#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define HASH_SIZE (100)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

int search(int *nums, int numsSize, int target)
{
	int min = nums[0];
	int rt_index = 0;
	int index = -1;
	for (size_t i = 1; i < numsSize; i++) {
		if (min > nums[i]) {
			rt_index = i;
			min = nums[i];
		}
	}
	
	for (size_t i = 0; i < numsSize; i++) {
		if (nums[rt_index] == target) {
			index = rt_index;
			break;
		}
		rt_index = (rt_index + 1) % numsSize; 
	}	
	return index;
}

int main(void)
{
	int nums[7] = {4,5,6,7,0,1,2};
	int target = 0;
	printf(" index %d \n", search(nums, sizeof(nums)/sizeof(int), target));
	return 0 ;
}
