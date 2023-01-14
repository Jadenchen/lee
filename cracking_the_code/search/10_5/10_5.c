#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define HASH_SIZE (100)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

int search(char *a[], char *target, int len)
{
	int left = 0;
	int right = len - 1;
	int mid = 0;
	int index = -1;
	while(left <= right) {
		mid = (left + right)/2;
		int result = strcmp(a[mid], target);
		if (result == 0) {
			index = mid;
			break;
		} else if (result)  {
			right--;
		} else {
			left++;
		}
	}	
	return index;
}

int main(void)
{
	char *a[] = {"at","","","","ball","", "", "car", "", "", "dad", "", ""};
	char *b = "ball";
	int size = sizeof(a)/sizeof(b);
	printf("index %d \n", search(a, b, size));
	return 0 ;
}
