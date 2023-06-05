#include <stdio.h>
#include "divid.h"
int main(void)
{
	int times = 10;
	int a[] = {19,4,5,21,19,4};
	int len = sizeof(a)/sizeof(int);
	printf("recursive fib %d \n", fib_recur(times));
	printf("dynamic programming fib %d \n", fib_dy(times));
	printf("hanoi %d \n", hanoi(times, 'A', 'C', 'B'));
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);	
	printf("\n");
	printf("sort\n");
	quicksort(a, len);
	for (int i = 0; i < len; i++)
		printf("%d ", a[i]);	
	printf("\n");
	return 0;
}
