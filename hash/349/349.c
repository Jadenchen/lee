#include <stdio.h>
#include <stdlib.h>

int is_inside(int *res, int val, int len)
{
	int ret = 0;
	if (!len) return ret;
	for (size_t i = 0; i < len; i++) {
		if (res[i] == val) {	
			ret = 1;
			break;
		}
	}
	return ret;
}
int *inter(int *num1, int len1, int *num2, int len2, int *returnSize)
{
	int llen = 0;
	int slen = 0;
	int *pl = NULL;
	int *ps = NULL;
	int cmp[1000] = {0};
	int index = 0;
	int *result;
	if (len1 > len2) {
		llen = len1;
		slen = len2;
		pl = num1;
		ps = num2;
	} else {
		llen = len2;
		slen = len1;
		pl = num2;
		ps = num1;
	}	

	result = calloc(slen, sizeof(int));

	for (size_t i = 0; i < llen; i++) {
		index = pl[i];
		index = index - 1;
		if (!cmp[index]) 
			cmp[index]++;
	}

	for (size_t i = 0; i < slen; i++) {
		index = ps[i];
		index = index - 1;
		if (cmp[index] && !is_inside(result, ps[i], *returnSize)) {
			result[*returnSize] = ps[i];
			*returnSize = *returnSize + 1;
		}
	}
	return result;
}

int *inter_j(int *num1, int len1, int *num2, int len2, int *returnSize)
{
	int hash[10] = {0};
	int hashother[10] = {0};
	int *curr = NULL;
	int index = 0;
	int *result = NULL;
	int sum = 0;
	curr = num1;
	for (size_t i = 0; i < len1; i++) {
		index = *curr++;
		if (!hash[index])
			hash[index]++;
	}

	curr = num2;

	for (size_t i = 0; i < len2; i++) {
		index = *curr++;
		if (!hashother[index])
			hashother[index]++;
	}
	for (size_t i = 0; i < 10; i++)
		hash[i] = hash[i] > hashother[i] ? hashother[i] : hash[i];

	
	for (size_t i = 0; i < 10; i++)
		sum += hash[i];
	*returnSize = sum;
	if (sum) {
		result = calloc(sum, sizeof(int));
		index = 0;
		for (size_t i = 0; i < 10; i++) {
			if (hash[i]) 
				result[index++] = i;
		}
	}
	return result;		
}
	
int main(void)
{
	int num1[] = {1, 2, 2, 1};
	int num2[] = {2, 2};
	int *res = NULL;
	int len_res = 0;
	int len1 = sizeof(num1)/sizeof(int);
	int len2 = sizeof(num2)/sizeof(int);
	res = inter(num1, len1, num2, len2, &len_res);
	printf("len res %d \n", len_res);
	for (size_t i = 0 ; i < len_res; i++)
		printf("%d ", res[i]);

	printf("\n");
	res = inter_j(num1, len1, num2, len2, &len_res);
	for (size_t i = 0 ; i < len_res; i++)
		printf(" 111 %d ", res[i]);
	printf("\n");
	if (res)
		free(res);
	return 0;
}
