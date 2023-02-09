#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))
#define MAX(x, y) (x) > (y) ? (x) : (y)

#define SIZE (100)

typedef struct hashtable {
    char str[4];
    int len;
} hashtable;


void init_hash(hashtable *ptHash)
{
    ptHash[2].len = 3;
    ptHash[2].str[0] = 'a';
    ptHash[2].str[1] = 'b';
    ptHash[2].str[2] = 'c';
    
    ptHash[3].len = 3;
    ptHash[3].str[0] = 'd';
    ptHash[3].str[1] = 'e';
    ptHash[3].str[2] = 'f';

    ptHash[4].len = 3;
    ptHash[4].str[0] = 'g';
    ptHash[4].str[1] = 'h';
    ptHash[4].str[2] = 'i';
}   

char **letterCombinations(char *digits, int *returnSize)
{
	char **res = NULL;
	*returnSize = 0;
	hashtable hash[10] = {0};
	char tmp[5] = {0};
	int diglen = 0;
	if (!digits) {
		return res;
	}

	init_hash(hash);
	diglen = strlen(digits);
	*returnSize = hash[digits[0] - '0'].len;
	for (int i = 1; i < diglen; i++) {
		*returnSize = hash[digits[i]- '0'].len * (*returnSize);
	}
	printf("returnsize %d \n", *returnSize);
	res = (char **) calloc(*returnSize, sizeof(char *));
	for (int i = 0; i < *returnSize; i++) {
		res[i] = calloc(5, sizeof(char));
	}

}

void combination(int len, int *digits, int *arr)
{
	if (len == 3) {
		printf("%d %d %d \n", arr[0], arr[1], arr[2]);
		return;
	}	

	for (int i = 0; i < len; i++) {
		combination(i + 1, digits, arr);
	}
}

int main(void)
{
#if 0
	char digits[3] = "23";
	char **res = NULL;
	int returnSize = 0;
//	res =  letterCombinations(digit, &returnSize);
	printf("%d \n", digits[0] - '0');

	return 0;
#endif
	int digs[3] = {1, 2, 3};
	int tmp[3] = {0};
	combination(3, digs, tmp);
	return 0;
}
