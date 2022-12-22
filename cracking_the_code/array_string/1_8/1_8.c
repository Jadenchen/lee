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


int main(void)
{
	int a[4][4] = {{1, 2, 3, 4}, {5, 0, 7, 8}, 
			{9, 10, 11, 12}, {13, 14, 15, 16}};	
	show(a, 4);
	rotate(a, 4);
	printf("\n");
	show(a, 4);
	return 0;
}
