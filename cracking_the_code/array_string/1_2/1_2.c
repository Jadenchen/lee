#include <stdio.h>
#include <string.h>
int isunique(char *a, char *b)
{
	int bPermute = 1;
	int len1 = strlen(a);
	int len2 = strlen(b);
	if (len1 != len2) {
		bPermute = 0;
		return bPermute; 
	}



	return bPermute;
}	

int main(void)
{
	char a[10] = "abcdef";
	char b[10] = "defabc";
	if (isperm(a, b)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	return 0;
}
