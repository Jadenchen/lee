#include <stdio.h>
#include <stdlib.h>

void bin(unsigned n)
{
    if (n > 1)
        bin(n >> 1);
 
    printf("%d", n & 1);
}

int insert(int n, int m, int i, int j)
{
	int mask = ~0;
	int mask_n = 0;
	//! 
	int left = mask << j;
	int right =(0x1 << (i + 1)) - 1;
	mask_n = n & (left | right);
	return mask_n | (m << i);
}

void show(int a)
{
	int arr[32];
	int i = 0;
	while(a) {
		arr[i++] = a%2;
	        a = a/2;
	}
	printf("i %d \n", i);
	for (int j = i - 1; j >= 0; j--)
		printf("%d", arr[j]);
	printf("\n");
}

int main(void)
{
	int n = 0b10000000000;
	int m = 0b10011;
	int i = 2;//! start 
	int j = 6;//! end
	int output = insert(n, m, i, j);
	bin(output);
	printf("\n");
	show(output);
	printf("\n");
	return 0 ;
}
