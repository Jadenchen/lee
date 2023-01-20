#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

typedef struct hashtable {
	int index;
	int val;
	struct hashtable *next;
} hashtable;

#if 0
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	int left = 0;
	*returnSize = 2;
	int find = 0;
	int *res = calloc(*returnSize, sizeof(int));
	for (int i = 0; i < numsSize; i++) {
		left = target - nums[i];
		for (int j = i + 1; j < numsSize; j++) {
			if (left == nums[j]) {
				res[0] = i;
				res[1] = j;
				find = 1;
				break;
			}
		}
		if (find)
			break;
	}

	return res;
}
#endif
void add(hashtable **hash, int val, int index)
{
	int bucket = abs(val) % SIZE;
	hashtable *new = calloc(1, sizeof(hashtable));
	new->index = index;
	new->val = val;
	new->next = NULL;

	if (hash[bucket]) {
		hashtable *curr = hash[bucket];
		while(curr->next)
			curr = curr->next;
		curr->next = new;
	} else {
		hash[bucket] = new;
	}
}

int lut(hashtable **hash, int val, int target)
{
	int left = target - val;
	int index = -1;
	int bucket = abs(target - val) % SIZE;
	if (!hash[bucket])
		return index;
	
	hashtable *curr = hash[bucket];
	while(curr) {
		if (curr->val == left) {
			index = curr->index;
			break;
		}
		curr = curr->next;
	}
	return index;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	hashtable *hash[SIZE];
	memset(hash, 0, SIZE*sizeof(hashtable *));

	for (int i = 0; i < numsSize; i++) {
		int findIdx = lut(hash, nums[i], target);
		if (findIdx >= 0) {
			int *res = calloc(2, sizeof(int));
			res[0] = i;
			res[1] = findIdx;
			*returnSize = 2;
			return res;
		}
		add(hash, nums[i], i);
	}

	return NULL;	
}

int main(void)
{
	int a[] = {2,7,11,15};
	int size = sizeof(a)/sizeof(int);
	int target = 9;
	int returnSize = 0;
	int *res = NULL; 
	res = twoSum(a, size, target, &returnSize);
	for (size_t i = 0; i < returnSize; i++) {
		printf("%d ", res[i]);
	}
	printf("\n");
	return 0;
}
