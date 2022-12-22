#include <stdio.h>
#include <string.h>

void cal(char *tmp, int len, char *input)
{
	int index = 0;
	for (size_t i = 0; i < len; i++) {
		//! convert 
		index = input[i];
		if (index > 65 && index < 90)
			tmp[index - 65]++;
		else 
			tmp[index - 97]++;
	}
}

int ispalindrom(char *a, char *b)
{
	int isPalin = 1;
	int index = 0;
	int len1 = strlen(a);
	int len2 = strlen(b);
	char arr1[26] = {0};
	char arr2[26] = {0};
	if (len1 != len2) {
		isPalin = 0;
		return isPalin; 
	}

	cal(arr1, len1, a);
	cal(arr2, len1, b);
	
	for (size_t i = 0; i < len1; i++) {
		if (arr1[i] != arr2[i]) {
			printf("1 %d 2 %d i %zu \n",arr1[i], arr2[i], i);
			isPalin = 0;
			break;
		}
	}

	return isPalin;
}	

int main(void)
{
	char a[10] = "TactCoa";
	char b[10] = "tacocat";
	if (ispalindrom(a, b)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	return 0;
}
