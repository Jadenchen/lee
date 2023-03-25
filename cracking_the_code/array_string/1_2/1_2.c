#include <stdio.h>
#include <string.h>
#if 0
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
#endif

int isperm(char *a, char *b)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	int ahash[26];
	int bhash[26];
	int index = 0;
	int isperm = 1;

	if (lena != lenb)
		return 0;

	memset(ahash, 0, sizeof(int)*26);
	memset(bhash, 0, sizeof(int)*26);
	for (int i = 0; i < lena; i++) {
		index = a[i] - 'a';
		ahash[index]++;
	}	
	for (int i = 0; i < lena; i++) {
		index = b[i] - 'a';
		bhash[index]++;
	}

	for (int i = 0; i < 26; i++) {
		if (ahash[i] != ahash[i]) {
			isperm = 0;
			break;
		}
	}
	return isperm;
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
