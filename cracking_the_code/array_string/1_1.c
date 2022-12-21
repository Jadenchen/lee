#include <stdio.h>
#include <string.h>
int isunique(char *a)
{
	int bUnique = 1;
	int len = strlen(a);
	int arr[26] = {0};
	int index = 0;
	printf("len %d \n", len);

	for (size_t i = 0; i < len; i++) {
		index = a[i] - 'a';
		if (!arr[index])
			arr[index]++;
		else {
			bUnique = 0;
			break;
		}
	}

	return bUnique;
}	

int main(void)
{
	char a[10] = "abcdef";
	char b[10] = "abbc";
	if (isunique(a)) {
		printf("unique\n");
	} else {
		printf("not unique\n");
	}
	if (isunique(b)) {
		printf("unique\n");
	} else {
		printf("not unique\n");
	}

	return 0;
}
