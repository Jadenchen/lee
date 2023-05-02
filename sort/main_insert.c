#include <stdio.h>
#include "sort.h"
int main(void)
{
	int a[] = {35, 52, 68, 12, 47, 52, 36, 52, 74, 27};
	int len = sizeof(a)/sizeof(int);
	show_array(a, len);
	insert_sort(a, len);
	printf("sortting\n");
	show_array(a, len);
	return 0;
}
