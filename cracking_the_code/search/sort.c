#include <stdio.h>


void swap(int *pa, int *pb)
{
	int tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}
//! time O(n*n)
//! space O(1)
void bubblesort(int *pa, int len)
{
	for (size_t i = 0; i < len; i++) {
		for (size_t j = i + 1; j < len; j++) {
			if (pa[i] > pa[j])
				swap(&pa[i], &pa[j]);
		}
	}
}

//! time O(n * n)
//! space O(1)
void selectionsort(int *pa , int len)
{
	int i, j, min;
	for (i = 0; i < len; i++) {
		min = i;
		for (j = i + 1; j < len; j++) {
			if (pa[min] > pa[j])
			       min = j;
		}
		if (min != i)
			swap(&pa[i], &pa[min]);
	}
}

//! time O(n * n)
//! space O(1)
void insertsort(int *pa, int len)
{
	int i, j;
	int tmp = 0;
	for (i = 1; i < len; i++) {
		int target = i;
		for (j = i - 1; j >= 0; j--) {
			if (pa[target] < pa[j]) {
				swap(&pa[target], &pa[j]);
				target = j;
			}
		}
	}
}

void merge(int *pa, int  left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int a[n1];
	int b[n2];
	int l_idx = 0;
	int r_idx = 0;
	int idx = left;
	for (size_t i = 0; i < n1; i++)
		a[i] = pa[left + i];
	for (size_t i = 0; i < n2; i++)
		b[i] = pa[mid + 1 + i];
	
	while(l_idx < n1 && r_idx < n2) {
		if (a[l_idx] > b[r_idx])
			pa[idx++] = b[r_idx++];
		else 
			pa[idx++] = a[l_idx++];
	}
	while(l_idx < n1) 
		pa[idx++] = a[l_idx++];
	while(r_idx < n2)
		pa[idx++] = b[r_idx++];
}

void mergesort(int *pa, int left, int right)
{
	if (left < right) {
		int mid = (left + right)/2;
		mergesort(pa, left, mid);
		mergesort(pa, mid+1, right);
		merge(pa, left, mid, right);
	}
}
//! time O(n)
//! space O(n + logn)
void mergesort_algo(int *pa, int len)
{
	mergesort(pa, 0, len - 1);	
}

int partition(int *pa, int low, int high)
{
	int pivot = pa[low];
	while(low < high) {
		while(low < high && pa[high] >= pivot)
			high--;
		swap(&pa[low], &pa[high]);	
		while(low < high && pa[low] <= pivot) 
			low++;
		swap(&pa[low], &pa[high]);	
	}
	return low;
}
//! time worst O (n*n)
//! space O(logn) recursion 
void quicksort(int *pa, int left, int right)
{
	int pivot;
	if (left < right) {
		pivot = partition(pa, left, right);
		quicksort(pa, left, pivot - 1);
		quicksort(pa, pivot + 1, right);
	}
}

void quicksort_algo(int *pa, int len)
{
	quicksort(pa, 0, len - 1);
}

void show(int *pa, int len)
{
	for (size_t i = 0; i < len; i++) {
		printf("%d ", pa[i]);
	}
	printf("\n");
}

int main(void)
{
	int a[5] = {2, 4, 5, 1, 0};
	int size = sizeof(a)/sizeof(int);

	//bubblesort(a, size);
	//selectionsort(a, size);
	//insertsort(a, size);
	//mergesort_algo(a, size);
	quicksort_algo(a, size);
	show(a, size);
	return 0;
}	
