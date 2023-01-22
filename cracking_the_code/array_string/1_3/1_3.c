#include <stdio.h>
#include <string.h>

#if 0
void replace(char *a, char *b)
{
	int len = strlen(a);
	int spacecnt = 0;
	char *curr = a;
	char *dst = b;
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
#endif

void replace(char *s, int truelen)
{

	int index = 0;
	int spacecnt = 0;
	
	for (int i = 0; i < truelen; i++) {
		if (s[i] == ' ')  {
			spacecnt++;
		}
	}

	index = truelen + spacecnt*2; 
	printf("%d \n", index);
	
	for(int i = truelen; i >= 0; i--) {
		if (s[i] == ' ') {
			s[index - 2] = '%';
			s[index - 1] = '2';
			s[index] = '0';	
			index = index - 3;
		} else {
			s[index] = s[i];
			index--;
		}
	}

}
int main(void)
{
#if 1
	char a[30] = "Mr John Smith";
	printf("a %s \n", a);
	replace(a, strlen(a)); 
	printf("a %s \n", a);
#else 
	char a[20] = "hello";
	printf("%s \n", a);
#endif
	return 0;
}
