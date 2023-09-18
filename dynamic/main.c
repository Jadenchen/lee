#include <stdio.h>

int main(void)
{
	int a[] = {1, 2, 5};
	int amout = 11;

	printf("small cnt %d \n", coinchange(a, sizeof(a)/sizeof(int), amout));
	return 0;
}
