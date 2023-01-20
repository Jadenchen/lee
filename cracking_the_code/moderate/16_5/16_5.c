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
int trailingZeroes(int n)
{
	int val = frac(n);
	int cnt = 0;
	while(val) {
		if (val % 10 == 0) {
			cnt++;
			val = val/10;
		} else {
			break;
		}
	}

	return cnt;
}

int main(void)
{
	int n = 5;
	printf(" trailing zeros %d \n", trailingZeroes(n));
	return 0;
}
