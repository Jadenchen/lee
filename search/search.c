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
	if (left > right)
		return mid;
	mid = (left + right)/2;
	if (pa[mid] == target)
		return mid;
	else if (pa[mid] > target) {
		return bin_search(pa, left, mid - 1, target);
	} else {
		return bin_search(pa, mid + 1, right, target);
	}
	return mid;
}

int bineary_search(int *pa, int len, int target)
{
	if (check(pa))
		return -1;
	return bin_search(pa, 0, len - 1, target);
}

static int interpolation(int *pa, int left, int right, int target)
{
	int pos = -1;
	if (left > right)
		return pos;
	pos = left + ((target - pa[left]) * (right - left)/(pa[right] - pa[left]));
	if (pa[pos] == target) {
		return  pos;
	} else if (pa[pos] > target) {
		return interpolation(pa, left, pos - 1, target);
	} else 
		return interpolation(pa, pos + 1, right, target);

	return pos;
}

int interpolation_search(int *pa, int len, int target)
{
	if (check(pa))
		return -1;
	return interpolation(pa, 0, len - 1, target);
}

int golden_search(int *pa, int len, int target)
{
	if (check(pa))
		return -1;

}
