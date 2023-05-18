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

static int gold1(int left, int right)
{
	return left + (right - left)*0.382;
}

static int gold2(int left, int right)
{
	return left + (right - left)*0.618;
}

static int golden(int *pa, int left, int right, int target)
{
	int cut1 = gold1(left, right);
	int cut2 = gold2(left, right);
	while(cut2 > cut1) {
		if (pa[cut1] > pa[cut2]) {
			right = cut2;
			cut2 = cut1;
			cut1 = gold1(left, right);
		} else {
			left = cut1;
			cut1 = cut2;
			cut2 = gold2(left, right);
		}
	}

	for (int i = left; i <= right; i++) {
		if (pa[i] <= pa[i-1] && pa[i] <= pa[i+1])
			return i;
	}
	return -1;
}

int golden_search(int *pa, int len, int target)
{
	if (check(pa))
		return -1;

	return golden(pa, 0, len - 1, target);
}

static int min(int x, int y)
{
	return (x >= y) ? y : x;
}

int fib_search(int *pa, int len, int target)
{
	int fib2 = 0; //! m - 2 th 
	int fib1 = 1; //! m - 1 th
	int fib = fib2 + fib1; //! m th 
	int offset = -1;

	while(fib < len) {
		printf("fib %d fib1 %d fib2 %d \n", fib, fib1, fib2);
		fib2 = fib1;
		fib1 = fib;
		fib =  fib2 + fib1;
	}

	while(fib > 1) {
		int i = min(offset + fib2, len - 1);
		printf("i %d fib2 %d offset %d \n\n", i, fib2, offset);
		if (pa[i] < target) {
			fib = fib1;
			fib1 = fib2;
			fib2 = fib - fib1;
			offset = i;
		} else if (pa[i] > target) {
			fib = fib2;
			fib1 = fib1 - fib2;
			fib2 = fib - fib1;
		} else 
			return i;
	}	

	if (fib1 && pa[offset + 1] == target)
		return offset + 1;
	return -1;
}
