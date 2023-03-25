#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))
#if 0
void swap(int *pa, int *pb)
{
	*pa = *pa ^ *pb;
	*pb = *pb ^ *pa;
	*pa = *pa ^ *pb;
}
#endif
void swap(int *pa, int *pb)
{
	*pa = *pa ^ *pb;
	*pb = *pa ^ *pb;
	*pa = *pa ^ *pb;
}

int main(void)
{
	int a = 10;
	int b = 20;

	//!xor true table
	// 0 0 0
	// 1 0 1
	// 0 1 1
	// 1 1 0

	printf("ori a %d b %d \n", a, b);
	swap(&a, &b);
	printf("mdi a %d b %d \n", a, b);
	return 0;
}
