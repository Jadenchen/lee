#include <stdio.h>
#include <stdlib.h>

static int isanagram(char *ori, char *cmp)
{

}

int main(void)
{
	char *a = "anagram";
	char *b = "nagaram";

	if (isanagram(a, b)) {
		printf("ok\n");
	} else 
		printf("failed\n");
	return 0;
}
