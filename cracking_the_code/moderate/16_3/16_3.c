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

int* intersection(int* num1, int num1Size, int *num2, int num2Size, int* returnSize)
{
	hashtable h1[num1Size];
	hashtable h2[num2Size];
	int *result = NULL;
	int count1 = 1;	
	int count2 = 1;
	int cnt = 0;
	int tmp[1000];
	int loop = 0;
	memset(h1, 0, sizeof(hashtable)*num1Size);
	memset(h2, 0, sizeof(hashtable)*num2Size);
	
	qsort(num1, num1Size, sizeof(int), cmp);
	qsort(num2, num2Size, sizeof(int), cmp);
	
	h1[0].val = num1[0];
	h1[0].cnt++;

	for (size_t i = 1; i < num1Size; i++) {
		if (h1[count1 - 1].val == num1[i]) {
			h1[count1 - 1].cnt++;
		} else {
			count1++;
			h1[count1 - 1].val = num1[i];
			h1[count1 - 1].cnt++;
		}
	}

	h2[0].val = num2[0];
	h2[0].cnt++;
	
	for (size_t i = 1; i < num2Size; i++) {
		if (h2[count2 - 1].val == num2[i]) {
			h2[count2 - 1].cnt++;
		} else {
			count2++;
			h2[count2 - 1].val = num2[i];
			h2[count2 - 1].cnt++;
		}
	}
	
#if 0 
	for (int i = 0; i < count1; i++) 
		printf("i %d val %d cnt %d \n", i, h1[i].val, h1[i].cnt);

	printf("\n");

	for (int i = 0; i < count2; i++) 
		printf("i %d val %d cnt %d \n", i, h2[i].val, h2[i].cnt);
#endif
	loop = count1 > count2 ? count2 : count1;	
	for (int i = 0; i < count1; i++) {
		for (int j = 0; j < count2; j++) {
			if (h1[i].val == h2[j].val) {
				tmp[cnt++] = h1[i].val;
				break;
			}
		}
	}

	printf("cnt %d \n", cnt);
	*returnSize = cnt;
	result = calloc(cnt, sizeof(int));

	memcpy(result, tmp, cnt*sizeof(int));
	return result;
}

int main(void)
{
	int a[] = {4,9,5};
	int b[] = {9,4,9,8,4};
	int size_a = sizeof(a)/sizeof(int);
	int size_b = sizeof(b)/sizeof(int);
	int returnSize = 0;
	int *result = NULL;
	result = intersection(a, size_a, b, size_b, &returnSize);
	//! [4, 9]
	for (size_t i = 0; i < returnSize; i++) {
		printf("%d ", result[i]);
	}
	printf("\n");
	return 0;
}
