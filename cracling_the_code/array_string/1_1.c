#include <stdio.h>
int isunique(char *a)
{
	
int main(void)
{
	char a[10] = "abcdef";
	char b[10] = "abbc";
	if (isunique(a)) {
		printf("unique\n");
	} else {
		printf("not unique\n");
	}
	return 0;
}
