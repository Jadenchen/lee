#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define HASH_SIZE (100)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))
//! fake 
struct ArrayReader {
	int a;
} ArrayReader;

int getElement(struct ArrayReader *reader, int index)
{
	return reader->a;
}

int search(struct ArrayReader* reader, int target) {
    
    int left = 0;
    int right = 1;
     int val = 0;
    //! find boundary
    while(getElement(reader, right) < target) {
        left = right;
        right = right << 1;
    }   

    while(left <= right) {
        int mid = (left + right)/2;
        val = getElement(reader, mid);
       
        if (val == target)
            return mid;
        if (val > target)
            right = mid - 1;
        else 
            left = mid + 1;
    }

    return -1;
}

int main(void)
{
	return 0 ;
}
