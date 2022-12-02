#include <stdio.h>
#include <stdlib.h>
#define MAX_VAL (65536)

void remove_ele(int *nums, int numsSize, int target)
{
	int index = 0;
	int max_index = 0;
	int i;
	if (!numsSize)
		return;

	for ( i = 0; i < numsSize; i++) {
		if (nums[i] == target)
			nums[i] = MAX_VAL;
	}	

	for ( i = 0; i < numsSize; i++) {
		if (nums[i] != MAX_VAL) {
			nums[index++] = nums[i];
			nums[i] = MAX_VAL;
		}
	}
}

int main(void)
{
	int nums[4] = {3, 2, 2, 3};

	for (size_t i = 0; i < 4; i++)
		printf("%d ", nums[i]);
	printf("\n");

	remove_ele(nums, 4, 3);
	for (size_t i = 0; i < 4; i++)
		printf("%d ", nums[i]);
	printf("\n");
	return 0;
}
