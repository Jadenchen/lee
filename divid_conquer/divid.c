#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "divid.h"
#define MAX(a, b) (a) > (b) ? (a) : (b)

int fib_recur(int a)
{
	if (a <= 2)
		return 1;
	return fib_recur(a - 1) + fib_recur(a - 2);
}

int fib_dy(int n)
{
	int i = 0;
	if (n >= 100 || n < 0)
		return -1;
	int fib[100] = {0};
	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[i - 1];
}

int hanoi(int n, char from, char to, char others)
{
	if (n == 1) {
		//printf("move n %d from %c to %c \n", n, from, to);
		return 1;
	} else {
		int step1 = hanoi(n - 1, from, others, to);
		//! move 1 plate from A to C
		int step2 = 1;
		//printf("move n %d from %c to %c \n", n, from, to);
		int step3 = hanoi(n - 1, others, to, from);
		return step1 + step2 + step3;
	}
}

static void mergetwo(int *pa, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int a1[n1];
	int a2[n2];
	int i, j, k;

	for (i = 0; i < n1; i++)
		a1[i] = pa[left + i];

	for (i = 0; i < n2; i++)
		a2[i] = pa[mid + 1 + i];

	i = 0;
	j = 0;
	k = left;

	while(i < n1 && j < n2) {
		if (a1[i] > a2[j])
			pa[k++] = a2[j++];
		else
			pa[k++] = a1[i++];
	}
	while(i < n1)
		pa[k++] = a1[i++];

	while(j < n2)
		pa[k++] = a2[j++];
}

static void merge(int *pa, int left, int right)
{
	if (right <= left)
		return;
	int mid = left + (right - left)/2;
	merge(pa, left, mid);
	merge(pa, mid + 1, right);
	mergetwo(pa, left, mid, right);
}

void mergesort(int *pa, int len)
{
	merge(pa, 0, len - 1);
}
static void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

static int pivation(int *pa, int left, int right)
{
	int key = pa[left];
	while(right > left) {
		while(left < right && pa[right] >= key)
			right--;
		swap(&pa[left], &pa[right]);
		while(left < right && pa[left] <= key)
			left++;
		swap(&pa[left], &pa[right]);
	}
	return left;
}

static void q_sort(int *pa, int left, int right)
{
	if (left > right)
		return ;
	int pivot = pivation(pa,  left, right);
	//printf("pivot %d \n", pivot);
	q_sort(pa, left, pivot - 1);
	q_sort(pa, pivot + 1, right);
}

void quicksort(int *pa, int len)
{
	if (!len)
		return;
	q_sort(pa, 0, len - 1);
}

int maxSubArray_dy(int *nums, int numsSize)
{
	int maxsum = 0;
	int sum = 0;
	maxsum = nums[0];
	for (int i = 0; i < numsSize; i++) {
		sum = sum + nums[i];
		if (nums[i] > sum)
			sum = nums[i];
		if (sum > maxsum)
			maxsum = sum;
	}

	return maxsum;
}

static int helper(int *nums, int left, int right)
{
	int sum = 0;
	int leftsum = 0;
	int rightsum = 0;
	int totalsum = 0;
	int maxleft = 0, maxright = 0;
	if (left >= right)
		return 0;
	//int mid = left + (right - left)/2;
	int mid = (left + right)/2;

	printf("left %d rihgt %d mid %d \n", left, right, mid);
	//! cal left
	for (int i = left; i <= mid - 1; i++) {
		sum += nums[i];
		leftsum = MAX(sum, leftsum);
	}
	sum = 0;
	for (int i = mid + 1; i <= right; i++) {
		sum = sum + nums[i];
		rightsum = MAX(rightsum, sum);
	}
	totalsum = leftsum + nums[mid] + rightsum;
	maxleft = helper(nums, left, mid - 1);
	maxright = helper(nums, mid + 1, right);
	printf("max left %d right %d total %d \n", maxleft, maxright, totalsum);
	return MAX(totalsum, MAX(maxleft, maxright));
}

int maxSubArray_divide_conquer(int* nums, int numsSize)
{
	if (!numsSize)
		return -1;
	return	helper(nums, 0, numsSize - 1);
}

typedef struct {
	int val;
	int cnt;
} data;

void check(data *tmp, int val, int *idx)
{
	for (int i = 0; i < *idx; i++) {
		if (val == tmp[i].val) {
			tmp[i].cnt++;
			return;
		}
	}
	*idx = *idx + 1;
	tmp[*idx - 1].val = val;
	tmp[*idx - 1].cnt = 1;

}
int cmpfunc(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

static int majority(int *nums, int left, int right)
{
	int left_major = 0;
	int right_major = 0;
	int mid = 0;
	int left_cnt = 0;
	int right_cnt = 0;
	int i = 0;
	if (left == right)
		return nums[left];
	mid = left + ((right - left)>>1);
	left_major = majority(nums, left, mid);
	right_major = majority(nums, mid+1, right);
	if (left_major == right_major)
		return left_major;

	for (i = left; i <= mid; i++) {
		if (nums[i] == left_major)
			left_cnt++;
	}

	for (i = mid+1; i <= right; i++) {
		if (nums[i] == right_major)
			right_cnt++;
	}
	return left_cnt > right_cnt ? left_major : right_major;
}

int majorityElement(int* nums, int numsSize)
{
#if 0
	data tmp[numsSize];
	memset(tmp, 0, sizeof(data)*numsSize);
	tmp[0].val = nums[0];
	tmp[0].cnt = 1;
	int total_idx = 1;
	int most_cnt = 0;
	int most_idx = 0;
	for (int i = 1; i < numsSize; i++) {
		check(tmp, nums[i], &total_idx);
	}

	most_cnt = tmp[0].cnt;
	most_idx = 0;
	for (int i = 1; i < total_idx; i++) {
		if (tmp[i].cnt  > most_cnt) {
			most_idx = i;
			most_cnt = tmp[i].cnt;
		}
	}

	return tmp[most_idx].val;
#else
#if 0
	qsort(nums, numsSize, sizeof(int), cmpfunc);
	return nums[numsSize>>1];
#endif
	return majority(nums, 0, numsSize - 1);
#endif
}

static bool search_hori(int *matrix, int left, int right, int target)
{
	int mid = 0;
	bool find = 0;
	if (left > right)
		return false;
	while(right >= left) {
		mid = left + ((right - left)>>1);
		if (matrix[mid] == target) {
			find = 1;
			break;
		} else if (matrix[mid] > target) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return find;
}

bool searchMatrix(int* matrix, int matrixSize, int* matrixColSize, int target)
{
#if 0
	for (int i = 0; i < matrixSize; i++) {
		for (int j = 0; j < matrixColSize[i]; j++) {
			printf("%d ", *(matrix + i*matrixSize +j));
		}
		printf("\n");
	}
#endif
	int find = 0;
	for (int i = 0; i < matrixSize; i++) {
		if (search_hori(matrix + i, 0, matrixColSize[i] - 1, target)) {
			find = 1;
			break;
		}
	}


	return (bool)find;
}
