#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "sort.h"

#define SIZE (1000)
int main(void)
{
#if 1
	int a[] = {35, 52, 68, 12, 47, 52, 36, 52, 74, 27};
	int len = sizeof(a)/sizeof(int);
	show_array(a, len);
#else
	int a[SIZE] = {0};
	int len = sizeof(a)/sizeof(int);
	srand(time(NULL));
	for (int i = 0; i < len; i++) {
		a[i] = rand()%SIZE;
	}

//	show_array(a, len);

#endif
	shell_sort(a, len);
	printf("sortting\n");
//	show_array(a, len);
	return 0;
}
