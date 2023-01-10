#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))


void show(int *pa, int len)
{
	for (size_t i = 0; i < len; i++)
		printf("%d ", pa[i]);
	printf("\n");
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	if (nums1Size && nums2Size) {
		int a[nums1Size];
		int b[nums2Size];
		int i = 0, j = 0, k = 0;
		for (i = 0; i < nums1Size; i++) {

			a[j++] = nums1[i];
		}
		j = 0;
		for (i = 0; i < nums2Size; i++) {

			b[j++] = nums2[i];
		}

		i = 0;
		j = 0;
		k = 0;
		while(i < m && j < n) {
			if (a[i] > b[j])
				nums1[k++] = b[j++];
			else 
				nums1[k++] = a[i++];
		}
		while(i < m)
			nums1[k++] = a[i++];
		while(j < n)
			nums1[k++] = b[j++];

	} else if (nums1Size == 0) {
		for (int i = 0; i < n; i++)
			nums1[i] = nums2[i];
	} else if (nums2Size == 0) {
		return;
	}

}

int main(void)
{
	int a[] = {-1,-1,0,0,0,0};	
	int asize = sizeof(a)/sizeof(int);
	int b[] = {-1, 0};
	int bsize = sizeof(b)/sizeof(int);
	merge(a, 4, asize, b, 2, bsize);
	show(a, asize);
	return 0 ;
}
