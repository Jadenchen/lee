#include <stdio.h>
#include <string.h>
int isperm(char *a, char *b)
{
	int bPermute = 1;
	int index = 0;
	int len1 = strlen(a);
	int len2 = strlen(b);
	char arr1[26] = {0};
	char arr2[26] = {0};
	if (len1 != len2) {
		bPermute = 0;
		return bPermute; 
	}
	
	for (size_t i = 0; i < len1; i++) {
		index = a[i] - 'a';
		arr1[index]++;
	}

	for (size_t i = 0; i < len1; i++) {
		index = b[i] - 'a';
		arr2[index]++;
	}

	for (size_t i = 0; i < len1; i++) {
		if (arr1[i] != arr2[i]) {
			bPermute = 0;
			break;
		}
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
