#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int findUnsortedSubarray(int* nums, int numsSize)
{
    int tmp[numsSize];
    int cnt = 0;
    int start = 0;
    int startflag = 0;
    int end = 0;
    int endflag = 0;
    int i = 0;
    int j = 0;
    memset(tmp, 0, sizeof(int)*numsSize);
    memcpy(tmp, nums, sizeof(int)*numsSize);
    qsort(tmp, numsSize, sizeof(int), cmp);

    for ( i = 0, j = numsSize - 1; i < numsSize; i++, j--) {
       if (!startflag && nums[i] != tmp[i]) {
           startflag = 1;
           start = i;
       }
       if (!endflag && nums[j] != tmp[j]) {
           endflag = 1;
           end = j;
       }
       if (endflag && endflag)
	       break;
    }

    if (endflag && startflag) {
        cnt = abs(end - start) + 1;
    } 
    return cnt;
}

int main(void)
{
	//int a[] = {2,6,4,8,10,9,15};
	int a[] = {1,3,2,4,5};
	int size = sizeof(a)/sizeof(int);
	printf("sub cnt %d \n", findUnsortedSubarray(a, size));
	return 0;
}
