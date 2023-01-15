#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static int cmp(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

int findDuplicate(int *pa, int numsSize)
{
	int tmp[numsSize];
	int dup = 0;
	memcpy(tmp, pa, sizeof(int)*numsSize);
	qsort(tmp, numsSize, sizeof(int), cmp);
	for (size_t i = 0; i < numsSize - 1; i++) {
		if (tmp[i] == tmp[i + 1]) {
			dup = tmp[i];
			break;
		}
	}
	return dup;
}

int main(void)
{
	int a[] = {1,4,4,2,4};
	int size = sizeof(a)/sizeof(int);
	printf("dup %d \n", findDuplicate(a, size));
	return 0 ;
}
