#include <stdio.h>
#include "sort.h"

static void merge(int *pa, int left, int mid, int right)
{
	int l1 = mid - left + 1; //! 3
	int l2 = right - mid; //! 3
	int a[l1];
	int b[l2];
	int idx = left, idx1, idx2;
	printf("l1 %d l2 %d \n", l1, l2);
	for (idx1 = 0; idx1 < l1; idx1++) 
		a[idx1] = pa[left + idx1];

	for (idx2 = 0; idx2 < l2; idx2++) 
		b[idx2] = pa[mid + 1 + idx2];
	idx1 = 0;
	idx2 = 0;
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

static void mergesort(int *pa, int left, int right)
{
	//0 2 5 
	if (left < right) {
		int mid = (left + right)/2; //! 0 + 5 /2
		printf("left %d mid %d right %d \n", left, mid, right);
		mergesort(pa, left, mid); //! 0 2
		mergesort(pa, mid + 1, right); //! 3 5
		merge(pa, left, mid, right);
	}
}

static void sort(int *pa, int len)
{
	if(!len)
		return;
	mergesort(pa, 0, len - 1);
}

int main(void)
{
	int a[6] = {5,1,1,2,0,0};
	int len = sizeof(a)/sizeof(int);
	show_array(a, len);
	printf("sorting ...\n");
	sort(a, len);
	show_array(a, len);
	return 0;
}
