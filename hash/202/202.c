#include <stdio.h>
#include <stdlib.h>

int ishappy(int n)
{
	int ret = 0;
	int sum = 0;
	int pos = n;
	int remain = 0;
	int val = 0;
	if (n <= 0)
		return ret;

	while(pos) {
		pos = pos/10;
		sum = sum + pos*pos;
	}
	
#if 0
1^2 + 9^2 = 82 = 1 + 81
8^2 + 2^2 = 68 = 64 + 4
6^2 + 8^2 = 100 = 36 + 64
1^2 + 0^2 + 0^2 = 1 
#endif
	
	return ret;
}

int main(void)
{
	int n = 19;
	if (ishappy(n)) 
		printf("happy\n");
	else 
		printf("unhappy\n");
	return 0;
}
