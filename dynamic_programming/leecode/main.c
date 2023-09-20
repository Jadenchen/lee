#include <stdio.h>
#include "dy.h"

int main(void)
{
	int a[] = {1, 2, 5};
	int size = sizeof(a)/sizeof(int);
	int amount = 11;
	//printf(" 322 smallest count %d \n", coinexchange(a, size, amount));
	printf(" 322 smallest count %d \n", coinexchange(a, size, amount));
	return 0;
}
