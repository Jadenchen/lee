#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

#if 0
typedef struct hashtable {
	int index;
	int val;
	struct hashtable *next;
} hashtable;

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
#if 0
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
#endif

#define SIZE (239)
#define MAP(val) abs(val % SIZE)

typedef struct hashtable {
        int val;
        int index;
        struct hashtable *next;
} hashtable;
hashtable *new_node(int val, int index)
{
        hashtable *new = calloc(1, sizeof(hashtable));
        new->val = val;
        new->index = index;
        new->next = NULL;
        return new;
}


void add_hash(int val, int index, hashtable *hash)
{
    int id = MAP(val);
    hashtable *new = new_node(val, index);
    hashtable *cur = &hash[id];
    while(cur->next) {
        cur = cur->next;
    }
    cur->next = new;
}

void init_hash(hashtable *hash)
{
    for (int i = 0; i < SIZE; i++) {
        hash[i].index = -1;
        hash[i].val = 0;
        hash[i].next = NULL;
    }
}

int hash_contain(int val, int *index, hashtable *hash)
{
    int id = MAP(val);
    int find = 0;
    struct hashtable *cur = &hash[id];
    while(cur) {
        if (cur->val == val && cur->index != -1) {
            *index = cur->index;
            find = 1;
            break;
        }
        cur = cur->next;
    }

    return find;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
        int remain = 0;
        int index = 0;
        int *res = NULL;
        int hashlen = 0;
        hashtable hash[SIZE];
        *returnSize = 2;

        res = calloc(2, sizeof(int));
        init_hash(hash);
        for (int i = 0; i < numsSize; i++) {
                remain = target - nums[i];
                if (hash_contain(remain, &index, hash)) {
                        res[0] = i;
                        res[1] = index;
                        break;
                } else {
                    add_hash(nums[i], i, hash);
                }
        }

        return res;
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
