#include <stdio.h>
#include "greedy.h"
int main(void)
{
	int bills[] = {5,5,5,10,20};

	printf(" lemonadeChange bill1 %d \n",
			lemonadeChange(bills, sizeof(bills)/sizeof(int)));
	return 0;
}
