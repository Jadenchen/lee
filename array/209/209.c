#include <stdio.h>
#include <stdlib.h>

static void merge(int *nums, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int aleft[n1];
	int aright[n2];
	int l_idx = 0;
	int r_idx = 0;
	int idx = left;
	for (size_t i = 0; i < n1; i++)
		aleft[i] = nums[left + i];
	for (size_t i = 0; i < n2; i++) 
		aright[i] = nums[mid + 1 + i];
	while(l_idx < n1 && r_idx < n2) {
		if (aleft[l_idx] > aright[r_idx])
			nums[idx++] = aright[r_idx++];
		else 
			nums[idx++] = aleft[l_idx++];
	}
	while(l_idx < n1)
		nums[idx++] = aleft[l_idx++];
	while(r_idx < n2)
		nums[idx++] = aright[r_idx++];

}

static void sort(int *nums, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left)/2;
		sort(nums, left, mid);
		sort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

static int find(int *nums, int len, int target)
{
	static int size = 0;
	for (size_t i = 0; i 
	
static int find_min_sum(int *nums, int len, int sum)
{
	if (!len)
	      return 0;

	//! sort 
	sort(nums, 0, len -1);
	for (size_t i = 0; i < len; i++)
		printf("%d ", nums[i]);
	printf("\n");
	
	return find(nums, len, sum);
}	

int main(void)
{
	int nums[6] = {2,3,1,2,4,3};
	int len = sizeof(nums)/sizeof(int);
	int sum = 7;
	printf("len %d \n", find_min_sum(nums, len, sum));
	return 0;
}
