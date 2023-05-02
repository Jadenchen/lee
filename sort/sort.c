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
