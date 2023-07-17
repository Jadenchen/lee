#include <stdio.h>
#include "divid.h"
int main(void)
{
	int times = 10;
	int a[] = {19,4,5,21,19,4};
	int b[] = {-2,1,-3,4,-1,2,1,-5,4};
	int c[] = {32,41,21,29,7,53,97,76,71,53,53,
		53,72,53,53,14,22,53,67,53,53,53,54,
		98,53,46,53,53,62,53,76,20,60,53,31,
		53,53,53,95,27,53,53,53,53,36,59,40,
		53,53,64,53,53,53,21,53,51,53,53,2,
		53,53,53,53,53,50,53,53,53,23,88,3,
		53,61,19,53,68,53,35,42,53,53,48,34,
		54,53,75,53,53,50,44,92,41,71,53,53,82,53,53,14,53};
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
	printf("max sub array dy %d \n", maxSubArray_dy(b, sizeof(b)/sizeof(int)));
	printf("max sub array divide %d \n", maxSubArray_divide_conquer(b, sizeof(b)/sizeof(int)));
	printf("majoty element %d \n", majorityElement(c, sizeof(c)/sizeof(int)));
	printf("\n");
	return 0;
}
