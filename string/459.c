#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int chk_repeat(char *s, int len, int diff)
{
	char cmp[len];
	int totalcnt = len/diff;
	int cnt = 0;
	memcpy(cmp, s, diff);
	if (len % diff != 0)
		return 0;

	for (int i = 0; i < len; i = i + diff) {
		if (!strncmp(s + i, cmp, diff)) {
			cnt++;
		}
	}
	return cnt == totalcnt;
}

bool repeatedSubstringPattern(char* s) {
	int len = strlen(s);
	bool result = false;
	int maxlen = 0;
	if (len % 2)
		return false;

	maxlen = len/2;
	for (int i = 0; i < maxlen; i++) {
		if (chk_repeat(s, len, i + 1)) {
			result = true;
			break;
		}
	}

	return result;
}

int main(void)
{
	char s[] = "abababa";
	printf("repeate string %d \n", repeatedSubstringPattern(s));
	return 0;
}
