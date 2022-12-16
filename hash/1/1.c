#include <stdio.h>
#include <stdlib.h>

int *two_sum(int *arr, int len, int target, int *returnSize)
{
	int *result = NULL;
	*returnSize = 2;
	result = calloc(2, sizeof(int));
	for (size_t i = 0; i < len; i++) {
		for (size_t j = i+1; j < len; j++) {
			if (arr[i] + arr[j] == target) {
				result[0] = i;
				result[1] = j;
			}
		}
	}
	
	return result;
}

int *two_sum_mdi(int *arr, int len, int target, int *returnSize)
{
	int *result = NULL;
	*returnSize = 2;
	result = calloc(2, sizeof(int));
	return result;
}

int main(void)
{
	int arr[] = {2, 7, 11, 15};
	int target = 9;
	int returnSize = 0;
	int len = sizeof(arr)/sizeof(int);
	int *result = NULL;
	result = two_sum(arr, len, target, &returnSize);
	for(size_t i = 0; i < returnSize; i++) 
		printf("%d ", result[i]);
	result = two_sum_mdi(arr, len, target, &returnSize);
	for(size_t i = 0; i < returnSize; i++) 
		printf("%d ", result[i]);
	printf("\n");
	if (result)
		free(result);
	return 0;
}
