#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

typedef struct hashtable {
	int val;
	int cnt;
} hashtable;

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}

int cmph(const void *a, const void *b)
{
	hashtable *pa = (hashtable *)a;
	hashtable *pb = (hashtable *)b;
	return pb->cnt - pa->cnt;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize)
{
	int *result = NULL;
	hashtable hash[numsSize];
	int count = 1;
	if (!nums) {
		*returnSize = 0;
		return result;
	}

	memset(hash, 0, sizeof(hashtable)*numsSize);
	qsort(nums, numsSize, sizeof(int), cmp);

	hash[0].val = nums[0];
	hash[0].cnt++;

	for (size_t i = 1; i < numsSize; i++) {
		if (hash[count - 1].val == nums[i]) {
			hash[count - 1].cnt++;
		} else {
			count++;
			hash[count - 1].val = nums[i];
			hash[count - 1].cnt++;
		}
	}	
	
	for (int i = 0; i < count; i++) 
		printf("i %d val %d cnt %d \n", i, hash[i].val, hash[i].cnt);
	
	printf("\n\n");
	//! sorting hash
	qsort(hash, count, sizeof(hash[0]), cmph);
	for (int i = 0; i < count; i++) 
		printf("i %d val %d cnt %d \n", i, hash[i].val, hash[i].cnt);

	*returnSize = k;
	result = calloc(k, sizeof(int));
	for (size_t i = 0; i < k; i++) {
		result[i] = hash[i].val;
	}
	return result;
}

int main(void)
{
	int a[] = {1,1,1,2,2,3};
	int size = sizeof(a)/sizeof(int);
	int k = 2;
	int returnSize = 0;
	int *result = NULL;
	result = topKFrequent(a, size, k, &returnSize);
	for (size_t i = 0; i < returnSize; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
