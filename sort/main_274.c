#include <stdio.h>
#include "sort.h"

static void merge1(int *pa, int left, int mid, int right)
{
	int l1 = mid - left + 1;
	int l2 = right - mid;
	int a[l1];
	int b[l2];
	int idx = left;
	int idx1 = 0;
	int idx2 = 0;

	for (int i = 0; i < l1; i++) 
		a[i] = pa[left + i];
	for (int i = 0; i < l2; i++) 
		b[i] = pa[mid + 1 + i];
	while(idx1 < l1 && idx2 < l2) {
		if (a[idx1] > b[idx2])
			pa[idx++] = b[idx2++];
		else 
			pa[idx++] = a[idx1++];
	}
	while(idx1 < l1)
		pa[idx++] = a[idx1++];
	while(idx2 < l2)
		pa[idx++] = b[idx2++];
}

static void mergesort1(int *pa, int left, int right)
{
	if (left < right) {
		int mid = (left + right)/2;
		mergesort1(pa, left, mid);
		mergesort1(pa, mid + 1, right);
		merge1(pa, left, mid, right);
	}
}

static void sort(int *pa, int len)
{
	mergesort1(pa, 0, len - 1);
}

static int find_idx(int *pa, int size)
{
	int h_idx = -1;
	sort(pa, size);
	show_array(pa, size);
	for (int i = 0; i < size; i++) {
		if (pa[i] > 0) {
			h_idx = pa[i];
			break;
		}	
	}	
	return h_idx;
}

static int find_cite(int *pa, int len)
{
	if (!pa)
		return -1;
	return find_idx(pa, len);
}	

int main(void)
{
	int a[] = {3,0,6,1,5};
	int size = sizeof(a)/sizeof(int);
	show_array(a, size);
	printf("h citation %d \n", find_cite(a, size));
	return 0;
}
