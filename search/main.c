#include <stdio.h>
#include "search.h"
int main(void)
{
	int a[] = {12, 27, 35, 36, 47, 52, 54, 55, 68, 74};
	int len = sizeof(a)/sizeof(int);
	int target = 74;
	show_array(a, len);
	printf("target %d search index %d \n", target, 
			bineary_search(a, len, target));
	return 0;
}
