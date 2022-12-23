#include <stdio.h>
#include <string.h>

void replace(char *a, char *b)
{
	int len = strlen(a);
	int spacecnt = 0;
	char *curr = a;
	char *dst = b;
	printf("len %d \n", len);
	for (size_t i = 0; i < len; i++) {
		if (*curr != ' ') 
			*dst++ = *curr;
		else {
			*dst++ = '%';
			*dst++ = '2';
			*dst++ = '0';
		}
		curr++;	
	}
}

int main(void)
{
#if 1
	char a[30] = "mr mohn Smith";
	char b[40] = {};
	printf("a %s \n", a);
	replace(a, b); 
	printf("b %s \n", b);
#else 
	char a[20] = "hello";
	printf("%s \n", a);
#endif
	return 0;
}
