#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define HASH_SIZE (100)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

int missint(int *pa, int size)
{
	int ori_sum = 0;
	int act_sum = 0;
	for (size_t i = 0; i < size; i++) 
		ori_sum = ori_sum + pa[i];

	act_sum = (0 + size) * (size + 1) /2;
	return act_sum - ori_sum;
}

int main(void)
{
	int a[] = {9,6,4,2,3,5,7,0,1};
	int size = sizeof(a)/sizeof(int);
	printf("miss int %d \n", missint(a, size));
	return 0 ;
}
