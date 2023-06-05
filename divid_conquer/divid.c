#include <stdlib.h>
#include <stdio.h>
#include "divid.h"

int fib_recur(int a)
{
	if (a <= 2)
		return 1;
	return fib_recur(a - 1) + fib_recur(a - 2);
}

int fib_dy(int n)
{
	int i = 0;
	if (n >= 100 || n < 0)
		return -1;
	int fib[100] = {0};
	fib[0] = 0;
	fib[1] = 1;
	for (i = 2; i <= n; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	return fib[i - 1];
}

int hanoi(int n, char from, char to, char others)
{
	if (n == 1) {
		printf("move n %d from %c to %c \n", n, from, to);
		return 1;
	} else {
		int step1 = hanoi(n - 1, from, others, to);
		//! move 1 plate from A to C
		int step2 = 1;
		printf("move n %d from %c to %c \n", n, from, to);
		int step3 = hanoi(n - 1, others, to, from);
		return step1 + step2 + step3;
	}
}

static void mergetwo(int *pa, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	int a1[n1];
	int a2[n2];
	int i, j, k;

	for (i = 0; i < n1; i++)
		a1[i] = pa[left + i];

	for (i = 0; i < n2; i++)
		a2[i] = pa[mid + 1 + i];

	i = 0;
	j = 0;
	k = left;

	while(i < n1 && j < n2) {
		if (a1[i] > a2[j])
			pa[k++] = a2[j++];
		else
			pa[k++] = a1[i++];
	}
	while(i < n1)
		pa[k++] = a1[i++];

	while(j < n2)
		pa[k++] = a2[j++];
}

static void merge(int *pa, int left, int right)
{
	if (right <= left)
		return;
	int mid = left + (right - left)/2;
	merge(pa, left, mid);
	merge(pa, mid + 1, right);
	mergetwo(pa, left, mid, right);
}

void mergesort(int *pa, int len)
{
	merge(pa, 0, len - 1);
}

void quicksort(int *pa, int len)
{

}
