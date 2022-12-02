#include <stdio.h>
#include <stdlib.h>

static void swap(int *pa, int *pb)
{
	int tmp;
	tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
	
static void bubble_sort(int *nums, int size)
{
	for (int i = 0; i < size; i++) {
		for (int j = i+1; j < size; j++) {
			if (nums[j] < nums[i]) 
			      swap(&nums[j], &nums[i]);	
		}
	}
}

static void mul(int *nums, int size)
{
	for (size_t i = 0; i < size; i++) {
		nums[i] = nums[i]*nums[i];
	}
}	

static void show(int *nums, int size)
{
	for(size_t i = 0; i < size; i++)
		printf("%d ", nums[i]);
	printf("\n");
}

static void merge_sort(int *nums, int start, int end)
{
		
}

int main(void)
{
	int nums[5] = {-4,-1,0,3,10};
	int len = sizeof(nums)/sizeof(int);
	mul(nums, len);
//	bubble_sort(nums, len);	
	merge_sort(nums, 0, len);
	show(nums, len);
	return 0;
}
