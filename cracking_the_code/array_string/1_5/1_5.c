#include <stdio.h>
#include <string.h>

int isReplace(char *fir, char *sec)
{
	int diff = 0;
	int bReplace = 1;
	int len = strlen(fir);
	for (size_t i = 0; i < len; i++) {
		if (fir[i] != sec[i]) {
			diff++;
			if (diff > 1) {
				bReplace = 0;
				break;
			}
		} 
	}

	return bReplace;
}
//! index diff
int isInsert(char *fir, char *sec)
{	
	int bInsert = 1;
	int len_fir = strlen(fir);
	int len_sec = strlen(sec);
	int index_fir = 0;
	int index_sec = 0;

	while(index_fir < len_fir && index_sec < len_sec) {
		if (fir[index_fir] != sec[index_sec]) {
			if (index_fir != index_sec) {
				bInsert = 0;
				break;
			}
			index_sec++;
		} else {
			index_fir++;
			index_sec++;
		}
	}	
	return bInsert;
}

int isOneEdit(char *first, char *second)
{
	int len_fir = strlen(first);
	int len_sec = strlen(second);
	if (len_fir == len_sec) {
		//! replace
		return isReplace(first, second);
	} else if ((len_fir + 1) ==  len_sec) {
		//! insert
		return isInsert(first, second);
	} else if ((len_fir - 1) == len_sec) { 
		//! remove
		return isInsert(second, first);
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
