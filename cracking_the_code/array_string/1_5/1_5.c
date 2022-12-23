#include <stdio.h>
#include <string.h>

int isReplace(char *a, char *b)
{
	char *curr = a;
	char *dst = b;
	int diff = 0;
	int bReplace = 1;
	int len = strlen(a);
	for (size_t i = 0; i < len; i++) {
		if (curr[i] != dst[i]) {
			diff++;
			if (diff > 1) {
				bReplace = 0;
				break;
			}
		} 
	}

	return bReplace;
}

int isInsert(char *a, char *b)
{
	int len = strlen(a);
	int diff = 0;
	int cnt = 0;
	int bInsert = 1;
	len = len + 1;
	for (size_t i = 0; i < len; i++) {
		if (a[i] == b[i])
			cnt++;
		else {
			diff++;
			if (diff > 1) {
				bInsert = 0;
				break;
			}
		}		
	}

	return bInsert;
}

int isRemove(char *a, char *b)
{
	int len = strlen(a);
	int diff = 0;
	int bRemove = 1;
	
	for (size_t i = 0; i < len; i++) {
		if (a[i] != b[i]) {
			diff++;
			if (diff > 1) {
				bRemove = 1;
				break;
			}	
		}
	}

	return bRemove;
}

int isOneEdit(char *a, char *b)
{
	int lena = strlen(a);
	int lenb = strlen(b);
	if (lena == lenb) {
		//! replace
		return isReplace(a, b);
	} else if ((lena + 1) ==  lenb) {
		//! insert
		return isInsert(a, b);
	} else if ((lena - 1) == lenb) { 
		//! remove
		return isRemove(a, b);
	}

	return 0;
}

int main(void)
{
	char a[] = {"pale"};
	char b[] = {"pie"};
	//! insert 
	//! remove
	//! replace 
	if (isOneEdit(a, b)) 
		printf("yes one edit\n");
	else 
		printf("no one edit\n");
	return 0;
}
