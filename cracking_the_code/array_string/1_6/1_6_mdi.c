#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int append_string(char *string, int cnt)
{
	int val = 0;
	char tmp[10];
	val = snprintf(tmp, 10, "%d", cnt);	
	memcpy(string, tmp, val);
	return val;
}

int compress(char *chars, int charsSize)
{
	int index = 1;
	int cnt = 1;
	char target = chars[0];
	for (int i = 1; i < charsSize; i++) {
		if (target == chars[i]) 
			cnt++;
		else {
			if (cnt != 1) {
				index = index + append_string(chars + index, cnt);
				cnt = 1;
			}
			chars[index++] = chars[i];
			target = chars[i];
		}
	}
	if (cnt != 1) {
		index = index + append_string(chars + index, cnt);
	}
	
	printf("index %d \n", index);
	return index;
}
//! time O(n) space(1)
int main(void)
{
	char a[20] = "aabcccccaaa";
	//char a[20] = "abbbbbbbbbbbb";
	printf("%s %d \n", a, strlen(a));
	printf("new len %d \n", compress(a, strlen(a)));
	printf("a %s \n", a);
	return 0;
}
