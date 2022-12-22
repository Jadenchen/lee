#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[5] = "pale";
	char b[10] = "tacocat";
	if (ispalindrom(a, b)) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

	return 0;
}
