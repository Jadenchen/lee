#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int *nums, int numsSize, int target)
{
	int ret = -1;
	int mid = 0;
	int low = 0;
	int high = numsSize - 1;
	if (!numsSize)
		return ret;

	while(low <= high) {
		mid = (low + high)/2;
		if (nums[mid] == target) {
			ret = mid;
			break;
		} else if (nums[mid] > target) 
			high--;
		else 
			low++;
	}
	return ret;
}

int search_recu(int *nums, int low, int high, int target)
{
	int mid;
	if (low > high)
		return -1;
	mid = (low + high) >> 1;
	if (nums[mid] == target)
		return mid;
	else if (nums[mid] > target)
		search_recu(nums, low, high - 1, target);
	else 
		search_recu(nums, low + 1, high, target);
}

int main(void)
{
	int nums[6] = {-1,0,3,5,9,12};
	int target = 9;
	printf("index %d \n", search(nums, sizeof(nums)/sizeof(int), target));
	printf("index %d \n", search_recu(nums, 0, sizeof(nums)/sizeof(int), target));
	return 0;
}
