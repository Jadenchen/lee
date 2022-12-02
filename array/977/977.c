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

static void merge(int *nums, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int aleft[n1];
	int aright[n2];
	int index = 0;	
	int n1_idx = 0;
	int n2_idx = 0;
	//! copy data
	for (size_t i = 0; i < n1; i++) 
		aleft[i] = nums[left + i];
	for (size_t i = 0; i < n2; i++)
		aright[i] = nums[mid + i];	

	while(n1_idx < n1 && n2_idx < n2) {
		if (aleft[n1_idx] > aright[n2_idx])
			nums[index++] = aright[n2_idx++];
		else 
			nums[index++] = aleft[n1_idx++];
	}
	//! copy rest data
	while (n1_idx < n1) 
		nums[index++] = aleft[n1_idx++];
	
	while(n2_idx < n2) 
		nums[index++] = aright[n2_idx++];
}

static void merge_sort(int *nums, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left)/2;
		merge_sort(nums, left, mid);
		merge_sort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

int main(void)
{
	int nums[5] = {-4,-1,0,3,10};
	int len = sizeof(nums)/sizeof(int);
	mul(nums, len);
	show(nums, len);
//	bubble_sort(nums, len);	
	merge_sort(nums, 0, len - 1);
	show(nums, len);
	return 0;
}
