#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void show(int *a, int row, int column)
{
	for(size_t i = 0; i < row; i++) {
		for (size_t j = 0; j < column; j++) {
			printf("%3d ", a[j + i*column]);
		}
		printf("\n");
	}
}

void zero_matrix(int *a, int row, int column)
{	
	int *a_r = calloc(row, sizeof(int));
	int *b_r = calloc(column, sizeof(int));
	
	for (size_t i = 0; i < row; i++) 
		for (size_t j = 0; j < column; j++) {
			if (a[j + i*column] == 0) {
				a_r[i] = 1;
				b_r[j] = 1;
			}
		}	
	
	//! row 
	for (size_t i = 0; i < row; i++) {
		if (a_r[i])
			memset(&a[i*column], 0, sizeof(int)*column);
	}	

	//! column
	for (size_t i = 0; i < column; i++) {
		if (b_r[i]) {
			for (size_t j = 0; j < row; j++) {
				a[i + j*column] = 0;
			}
		}
	}
}

void setZeroes(int matrix[][4], int matrixSize, int* matrixColSize)
{
    int row[matrixSize];
    int col[*matrixColSize];
    memset(row, 1, sizeof(int)*matrixSize);
    memset(col, 1, sizeof(int)* (*matrixColSize));

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (matrix[i][j] == 0) {
                if (row[i])
                    row[i] = 0;
                if (col[j]) 
                    col[j] = 0;
            }
        }
    }

    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < *matrixColSize; j++) {
            if (row[i] == 0 || col[j] == 0)
                matrix[i][j] = 0;
        }
    } 
}

//! time O(M*N) space O(M+N) 
int main(void)
{
#if 0
	int a[3][4] = {{1, 0, 3, 4}, {5, 5, 0, 8}, 
			{9, 10, 11, 12}};	
	int row = sizeof(a)/sizeof(a[0]);
	int column = sizeof(a[0])/sizeof(int);
	show(a[0], row, column);
	zero_matrix(a[0], row, column);	
#endif
	int a[3][4] = {{0,1,2,0}, {3,4,5,2}, 
			{1,3,1,5}};	
	int row = sizeof(a)/sizeof(a[0]);
	int column = sizeof(a[0])/sizeof(int);
	show(a[0], row, column);
	//zero_matrix(a[0], row, column);	
	setZeroes(a, row, &column);
	printf("\n");
	show(a[0], row, column);
	return 0;
}
