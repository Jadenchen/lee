#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

static int check(int *pa)
{
	if (!pa) {
		printf("object error\n");
		return 1;
	}
	return 0;
}

void show_array(int *pa, int len)
{
	if (check(pa))
		return;
	for (int i = 0; i < len; i++)
		printf("%d ", pa[i]);
	printf("\n");
}

static void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//! insert sort
//! time O(n^2)
//! space O(n)
void insert_sort(int *pa, int len)
{
	if (check(pa))
		return;

	for (int i = 1; i < len; i++) {
		int val = pa[i];
		int j = i - 1;
		while(val < pa[j] && j >= 0) {
			pa[j+1] = pa[j];
			j--;
		}
		pa[j+1] = val;
	}
}
//! shell sort
//! time
//! space O(1)
void shell_sort(int *pa, int len)
{
	int gap = 0;
	int j;
	if (check(pa))
		return;

	gap = len/2;
	for (; gap > 0; gap = gap>>1) {
		for (int i = gap; i < len; i++) {
			int tmp = pa[i];
			for (j = i; j >= gap && (pa[j - gap] > tmp); j = j - gap) {
				pa[j] = pa[j - gap];
			}

			pa[j] = tmp;
		}
	}
}

//! time  O(n^2)
//! space O(1)
void select_sort(int *pa, int len)
{
	int i, j;
	if (check(pa))
		return;

	for (i = 0; i < len - 1; i++) {
		int min = i;
		//! find min
		for (j = i+1; j < len; j++) {
			if (pa[j] < pa[min]) {
				min = j;
			}
		}
		if (min != i) {
			//! swap
			int tmp = pa[min];
			pa[min] = pa[i];
			pa[i] = tmp;
		}
	}
}

void bubble_sort(int *pa, int len)
{
	int i, j;
	if (check(pa))
		return;

	for (i = 0; i < (len - 1); i++) {
		for (j = 0; j < (len - 1 - i); j++) {
			if (pa[j+1] < pa[j]) {
				swap(&pa[j], &pa[j+1]);
			}
		}
	}
}

//! shaker sort
void shake_sort(int *pa, int len)
{
	int left = 0;
	int right = len - 1;
	int shift = 1;
	while(left < right) {
		for (int i = left; i < right; i++) {
			if (pa[i] > pa[i+1]) {
				swap(&pa[i], &pa[i+1]);
				shift = i;
			}
		}
		right = shift;
		for (int i = right - 1; i >= left; i--) {
			if (pa[i] > pa[i+1]) {
				swap(&pa[i], &pa[i+1]);
				shift = i + 1;
			}
		}
		left = shift;
	}
}

static void merge(int *pa, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int a1[n1];
	int a2[n2];
	int idx = left;
	int n1_idx = 0;
	int n2_idx = 0;

	for (int i = 0; i < n1; i++)
		a1[n1_idx++] = pa[i + left];
	for (int i = 0; i < n2; i++)
		a2[n2_idx++] = pa[i + mid + 1];

	n1_idx = 0;
	n2_idx = 0;
	while(n1_idx < n1 && n2_idx < n2) {
		if (a1[n1_idx] > a2[n2_idx])
			pa[idx++] = a2[n2_idx++];
		 else
			pa[idx++] = a1[n1_idx++];
	}

	while(n2_idx < n2) {
		pa[idx++] = a2[n2_idx++];
	}
	while(n1_idx < n1) {
		pa[idx++] = a1[n1_idx++];
	}
}

static void merge_sort_build(int *pa, int left, int right)
{
	if (left < right) {
		int mid = left + (right - left)/2; //! could overflow
		merge_sort_build(pa, left, mid);
		merge_sort_build(pa, mid+1, right);
		merge(pa, left, mid, right);
	}
}

//! time O(nlogn)
//! space O(n)
void merge_sort(int *pa, int len)
{
	if (check(pa))
		return;
	merge_sort_build(pa, 0, len-1);
}

static void max_heapify(int *pa, int start, int end)
{
	int dad = start;
	int son = dad*2 + 1;
	while(son <= end) {
		if (son + 1 <= end && pa[son] <= pa[son + 1])
			son++;
		if (pa[dad] > pa[son])
			return;
		else {
			swap(&pa[dad], &pa[son]);
			dad = son;
			son = 2*dad + 1;
		}
	}
}

void heap_sort(int *pa, int len)
{
	if (check(pa))
		return;
	//! build heap
	for (int i = len/2 - 1; i >= 0; i--) {
		max_heapify(pa, i, len - 1);
	}
	//! heap sort
	for (int i = len - 1; i > 0; i--) {
		swap(&pa[0], &pa[i]);
		max_heapify(pa, 0, i - 1);
	}
}

static int partition(int *pa, int left, int right)
{
	int pivotkey;
	pivotkey = pa[left];
	while(left < right) {
		while(left < right && pa[right] >= pivotkey)
			right--;
		swap(&pa[left], &pa[right]);
		while(left < right && pa[left] <= pivotkey)
			left++;
		swap(&pa[left], &pa[right]);
	}
	return left;
}

static void qksort(int *pa, int left, int right)
{
	if (left < right) {
		int pivot = partition(pa, left, right);
		qksort(pa, left, pivot - 1);
		qksort(pa, pivot + 1, right);
	}
}

void quick_sort(int *pa, int len)
{
	if (check(pa))
		return;
	qksort(pa, 0, len - 1);
}
