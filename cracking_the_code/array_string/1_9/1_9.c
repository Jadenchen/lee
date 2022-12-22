#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int find (int *index, char cmp, char *b, int len)
{
	int bFind = 0;
	for (size_t i = 0; i < len; i++) {
		if (b[i] == cmp) {
			bFind = 1;
			*index = i;
			break;
		}
	}
	return bFind;
}
int isRotate(char *a, char *b)
{
	int bRotate = 0;
	char *pa = a;
	char *pb = b;
	int b_cnt = 0;
	int index = 0;
	//! find first 
	int len = strlen(a);
	if (find(&index, *pa, b, len)) {
		pb = pb + index;
		for (size_t i = 0; i < len; i++) {
			if (*pa != *pb) {
				bRotate = 1;
				break;
			}
			pa++;
			pb = pb + ((i + len)%len);
		}
		return bRotate;
	}  

	return bRotate;
		
}
int main(void)
{
	char a[12] = "waterbottle";
	char b[12] = "erbottlewat";
	if (isRotate(a, b)) 
		printf("yes\n");
	else 
		printf("no\n");	
	return 0;
}
