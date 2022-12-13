#include <stdio.h>
#include <stdlib.h>
#define LEN (26)
#define A (97)
static int isanagram(char *ori, char *cmp)
{
	int ret = -1;
	int str[LEN] = {0};	
	int len1 = 0;
	int len2 = 0;
	int diff = 0;
	len1 = strlen(ori);
	len2 = strlen(cmp);
	if (len1 != len2)
		goto ERR;

	for (size_t i = 0; i < len1; i++) {
		diff = *ori - A;
		str[diff]++;
		ori++;
	}

	for (size_t i = 0; i < len1; i++) {
		diff = *cmp - A;
		str[diff]--;
		cmp++;
	}
	for (size_t i = 0; i < LEN; i++) {
		if (str[i] != 0) {
			goto ERR;
		}
	}
	ret = 0;
ERR:
	return ret;
}

int main(void)
{
	char a[8] = {"anagram"};
	char b[8] = {"nagaram"};
	if (!isanagram(a, b)) {
		printf("ok\n");
	} else 
		printf("failed\n");
	return 0;
}
