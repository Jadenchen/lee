#include <stdio.h>
#include "greedy.h"
int main(void)
{
	int bills[] = {5,5,5,10,20};
	int bills1[] = {5,5,10,10,20};
	
	printf(" lemonadeChange bill0 %d \n", 
			lemonadeChange(bills, sizeof(bills)/sizeof(int)));

	printf(" lemonadeChange bill1 %d \n", 
			lemonadeChange(bills1, sizeof(bills1)/sizeof(int)));
	return 0;
}
