#include <stdio.h>
#include "sort.h"
int main(void)
{
	int a[] = {1, 2, 3, 0, 0, 0};
	int b[] = {2, 5, 6};
	int lena = 3;
	int lenb = 3;
	show_array(a, lena + lenb);
	show_array(b, lenb);
	printf("merge two list ...\n");
	merge_twolist(a, lena, b, lenb);
	show_array(a, lena + lenb);
	return 0;
}
