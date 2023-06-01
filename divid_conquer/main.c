#include <stdio.h>
#include "divid.h"
int main(void)
{
	int times = 10;
	printf("recursive fib %d \n", fib_recur(times));
	printf("dynamic programming fib %d \n", fib_dy(times));
	printf("hanoi %d \n", hanoi(times, 'A', 'C', 'B'));
	return 0;
}
