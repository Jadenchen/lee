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
				int tmp = pa[j];
				pa[j] = pa[j+1];
				pa[j+1] = tmp;
			}
		}
	}
}
