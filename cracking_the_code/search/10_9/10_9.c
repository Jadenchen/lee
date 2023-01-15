#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

bool searchMatrix(int matrix[3][4], int matrixSize, int* matrixColSize, int target)
{
	//! find row
	int row = 0; 
	bool find = false;
	int i = 0;
	if (matrixSize == 0) {
		for ( i = 0; i < *matrixColSize; i++) {
			if (matrix[0][i] == target) {
				find = true;
				break;
			}
		}
	} else {
		for ( i = 1; i < matrixSize; i++) {
			if (matrix[i][0] > target) {
				row = i - 1;
				break;
			} else if (matrix[i][0] == target) {
				row = i;
				find = true;
				break;
			}
		}

		if (!find) {
			if (i == matrixSize)
				row = matrixSize - 1;
			for ( i = 0; i < *matrixColSize; i++) {
				if (target == matrix[row][i]) {
					find = true;
					break;
				}
			}
		}
	}

	return find;
}

int main(void)
{
	int a[3][4] = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
	int matrixSize = 3;
	int matrixColumnSize = 4;
	int target = 30;
	printf("is inside ? %d \n", searchMatrix(a, 3, &matrixColumnSize, target));
	return 0 ;
}
