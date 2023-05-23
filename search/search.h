#ifndef SEARCH_H
#define SEARCH_H

void show_array(int *pa, int len);
int bineary_search(int *pa, int len, int target);
int interpolation_search(int *pa, int len, int target);
int golden_search(int *pa, int len, int target);
int fib_search(int *pa, int len, int target);
int method_35(int *nums, int numsSize, int target);
//! leetcode 852
int peakIndexInMountainArray(int* arr, int arrSize);
#endif

