#include <stdio.h>
#include <string.h>

void show(int *hash)
{
	for (size_t i = 0; i < 26; i++)
		printf(" %d ", hash[i]);
	printf("\n");
}

int isPermutationPalindrome(char *s)
{
	int bpp = 1;
	int hash[26] = {0};
	int index = 0;
	int len = strlen(s);
	int diff = 0;
	for (size_t i = 0; i < len; i++) {
		index = s[i] - 'a';
		hash[index]++;
	}

	show(hash);
	//! only one odd and other even
	for (size_t i = 0; i < 26; i++) {
		if (hash[i] %2 == 1) {
			diff++;
			continue;
		} 
	}
	
	if (diff > 1)
		bpp = 0;
	//! time O(N)
	//! space O(1)
	return bpp;
}

int checklen(char *s)
{
	int len = 0;
	char *cur = s;
	while(cur) {
		if (*cur == '\0')
			break;

		if (*cur == ' ') {
			cur++;
			continue;
		}
		len++;
		cur++;
	}
	return len;
}
//! check palindrome
int checkPalindrome(char *s)
{
	int bPalindrome = 1;
	int len = strlen(s);
	for (size_t i = 0; i < len/2; i++) {
		if (s[i] != s[len - 1 - i]) {
			bPalindrome = 0;
			break;
		}
	}
	return bPalindrome;
}

int main(void)
{
	//! assume all lower case
	//! assume no space
	char a[100] = "tactcoa";
       
      	printf("len %d \n", checklen(a));
	printf("palindrome %d \n", checkPalindrome("madam"));
	if (isPermutationPalindrome(a)) {
		printf("yes permute palin\n");
	} else {
		printf("no permute palin\n");
	}
	return 0;
}
