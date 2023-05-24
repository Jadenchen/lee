#include <stdio.h>
#include "search.h"
int main(void)
{
	int a[] = {12, 27, 35, 36, 47, 52, 54, 55, 68, 74};
	int b[] = {12, 27, 35, 36, 47, 52, 54, 55, 68, 74, 68, 56, 42};
	//int c[] = {18,29,38,59,98,100,99,98,90};
	//int c[] = {18,29,38,59,98,100,99,98,90};
	int c[] = {3,5,3,2,0};
	int d[] = {1,3,5,6};

	int len = sizeof(a)/sizeof(int);
	int target = 74;
	show_array(a, len);
	printf("bin target %d search index %d \n", target,
			bineary_search(a, len, target));

	printf("inter target %d search index %d \n", target,
			interpolation_search(a, len, target));

	printf("golder target %d search index %d \n", target,
			golden_search(a, len, target));

	printf("fib search target %d search index %d \n", target,
			fib_search(a, len, target));

	printf("peak index %d \n", peakIndexInMountainArray(c, sizeof(c)/sizeof(int)));
	printf("search index %d \n", searchInsert(d, sizeof(d)/sizeof(int), 5));
	return 0;
}
