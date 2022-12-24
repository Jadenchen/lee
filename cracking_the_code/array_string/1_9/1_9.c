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
	int cnt = 0;
	//! find first 
	int len = strlen(a);
	if (find(&index, *pa, b, len)) {
		for (size_t i = 0; i < len; i++) {
			pb = &b[(index + i +len)%len];
			if (*pa == *pb) {
				cnt++;
			} 
			pa++;
		}
		if (cnt == len) 
			bRotate = 1;
		return bRotate;
	}  

	return bRotate;
}

//! time O(n) space O(1)
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
