#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#if 0
int binsearch(int *nums, int target, int low, int high)
{
    int res = -1;
    int mid = 0;
    while(low != high) {
        mid = (low + high)/2;
        if (nums[mid] == target) {
            res = mid;
            break;
        } else if (nums[mid] > target)
            high = high - 1;
        else
            low = low + 1;
    }
    return res;
}
#endif

int search(int *nums, int numsSize, int target)
{
	int ret = -1;
	int mid = 0;
	int low = 0;
	int high = numsSize;
	if (!numsSize)
		return ret;

	while(low != high) {
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

int main(void)
{
	int nums[6] = {-1,0,3,5,9,12};
	int target = 9;
	printf("index %d \n", search(nums, sizeof(nums)/sizeof(int), target));
	printf("%d ", 5/2);
	return 0;
}
