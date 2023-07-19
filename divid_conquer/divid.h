#include <stdbool.h>
#ifndef DIVID_H
#define DIVID_H
//! fib_recur
int fib_recur(int i);
int fib_dy(int n);
int hanoi(int n, char from, char to, char others);
void mergesort(int *pa, int len);
void quicksort(int *pa, int len);
int maxSubArray_divide_conquer(int* nums, int numsSize);
int maxSubArray_dy(int* nums, int numsSize);
int majorityElement(int* nums, int numsSize);
bool searchMatrix(int* matrix, int matrixSize, int* matrixColSize, int target);

#endif

