#include <stdio.h>
#include "comm.h"
#define LEN (1024)

static int arr[1024] = {0};

int dy_fib(int n)
{
	if (n >= 1023) {
		printf("[%s] error \n", __func__);
		return -1;
	}
	arr[0] = 1;
	arr[1] = 1;
	//! fib(n) = fib(n -1) + fib(n-2);
	for(int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i-2];
	}

	return arr[n];

}
