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
		int step1 = hanoi(n - 1, from, to, others);
		int step2 = 1;
		printf("move n %d from %c to %c \n", n, from, to);
		int step3 = hanoi(n - 1, from, to, others);
		return step1 + step2 + step3;
	}
}
