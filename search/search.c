#include <stdio.h>
#include <stdlib.h>

#include "search.h"

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

static int bin_search(int *pa, int left, int right, int target)
{
	int mid = -1;
	if (left < right) {
		mid = (left + right)/2;
		if (pa[mid] == target)
			return mid;
		else if (pa[mid] > target) {
			bin_search(pa, left, mid - 1, target);
		} else {
			bin_search(pa, mid + 1, right, target);
		}
	}
	return mid;
}

int bineary_search(int *pa, int len, int target)
{
	if (check(pa))
		return -1;

	return bin_search(pa, 0, len - 1, target);
}
