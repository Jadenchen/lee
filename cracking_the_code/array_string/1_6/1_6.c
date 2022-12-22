#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cal(int *tmp, int len, char *input)
{
	int index = 0;
	for (size_t i = 0; i < len; i++) {
		index = input[i];
		if (index > 65 && index < 90) 
			tmp[index - 65]++;
		else 
			tmp[index - 97]++;
	}
}
		
char *cmpr(char *input)
{
	int len = strlen(input);
	int arr[26] = {0};
	int new_len = 0;
	cal(arr, len, input);
	for (size_t i = 0; i < 26; i++) {
		if (arr[i]) {
			new_len = new_len + 1 + 1;
		}
	}
	printf("new_len %d len %d \n", new_len, len);
	if (new_len > len)
		return input;
	else {
		char *new = calloc(new_len, sizeof(char));
		int cnt = 0;
		char *curr = new;
		for (size_t i = 0; i < 26; i++) {
			if (arr[i]) {
				*curr++ = i + 'a';
				*curr++ = arr[i] + '0';
			}
		}
		return new;
	}
}

int main(void)
{
	char a[20] = "aabcccccaaa";
	char *tmp = NULL;
	tmp = cmpr(a);
	if (tmp) {
		printf("%s \n", tmp);
	}
	return 0;
}
