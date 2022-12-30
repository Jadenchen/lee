#include <stdio.h>
#include <stdlib.h>

void bin(unsigned n)
{
    if (n > 1)
        bin(n >> 1);
 
    printf("%d", n & 1);
}

int clearbit(int num, int i)
{
	int mask = ~(1 << i);
	return num & mask;
}

int diff(int a, int b)
{
	int val = a ^ b;
	int cnt = 0;
	while(val) {
		if (val & 0x1)
			cnt++;
		val = val>>1;
	}
	return cnt;
}	
		
int main(void)
{
	int a = 0b11101;
	int b = 0b01111;
	printf("diff %d\n",diff(a, b));
	return 0 ;
}
