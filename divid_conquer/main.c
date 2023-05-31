#include <stdio.h>
#include "divid.h"
int main(void)
{
	int recur = 10;
	printf("recursive fib %d \n", fib_recur(recur));
	printf("dynamic programming fib %d \n", fib_dy(recur));
	return 0;
}
