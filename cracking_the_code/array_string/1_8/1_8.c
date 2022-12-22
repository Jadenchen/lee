#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(int a[4][4], int len)
{
	for(size_t i = 0; i < len; i++) {
		for (size_t j = 0; j < len; j++) {
			printf("%3d ", a[i][j]);
		}
		printf("\n");
	}
}

int hasZero(int *a, int len)
{
	int bZero = 0;
	for (size_t i = 0; i < len; i++) {
		for (size_t j = 0; j < len; j++) {
			if (!a[i * len + j]) {
				bZero = 1;
				break;
			}
		}
	}
	return bZero;
}

void clear(int (*a)[4], int len)
{
	for (size_t i = 0; i < len; i++) 
		memset(a[i], 0, sizeof(int)*len);
}

int main(void)
{
	int a[4][4] = {{1, 2, 3, 4}, {5, 0, 7, 8}, 
			{9, 10, 11, 12}, {13, 14, 15, 16}};	
	show(a, 4);
	if (hasZero(a[0], 4)) {
		clear(a, 4);
	} 
	show(a, 4);
	return 0;
}
