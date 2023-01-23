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
#if 0
void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void rotate(int a[][4], int len)
{
	for (size_t i = 0; i < len; i++) {
		for (size_t j = i + 1; j < len; j++) {
			swap(&a[i][j], &a[j][i]);
		}
	}
}
#endif
void rotate(int matrix[][4], int matrixSize, int* matrixColSize)
{
    int len = matrixSize/2;
    int tmp = 0;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[matrixSize - i - 1][j];
            matrix[matrixSize - i - 1][j] = tmp;
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 1; j < *matrixColSize; j++) {
            tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
}
//! time O(n2) space O(1)
int main(void)
{
#if 0
	int a[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, 
			{9, 10, 11, 12}, {13, 14, 15, 16}};	
#endif
	int a[4][4] = {{5,1,9,11}, {2,4,8,10}, {13,3,6,7}, {15,14,12,16}};
	int columsize = 4;
	show(a, 4);
	rotate(a, 4, &columsize);
	printf("\n");
	show(a, 4);
	return 0;
}
