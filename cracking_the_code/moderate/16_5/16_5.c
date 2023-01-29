#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

int frac(int n)
{
	if (n == 0)
		return 1;
	return n * frac(n - 1);
}
//! wrong answer
#if 0
int trailingZeroes(int n)
{
	int val = frac(n);
	int cnt = 0;
	while(val %10 == 0) {
		cnt++;
		val = val/10;
	}

	return cnt;
}
#endif

int trailingZeroes(int n)
{
	int cnt = 0;
	int tmp = 0;
	for (int i = 5; i <= n; i = i + 5) {
		tmp = i;
		while(tmp/5) {
			cnt++;
			tmp = tmp/5;
		}
	}
	return cnt;
}

int main(void)
{
	int n = 7;
	printf(" trailing zeros %d \n", trailingZeroes(n));
	return 0;
}
