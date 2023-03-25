#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <limits.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))
#define MAX(x, y) (x) > (y) ? (x) : (y)
typedef struct hashtable {
	int index;
	char s[10];
} hashtable;

int hashkey(hashtable *hash, int index, char *str, int patternSize)
{	
	int len = strlen(hash[index].s);
	if (len) {
		return 1;
	} else {
		//! has same string 
		for (int i = 0; i < 26; i++) {
			int lentmp = strlen(hash[i].s);
			if (lentmp) {
				if (strncmp(hash[i].s, str, patternSize)) {
					return 1;
				}
			}
		}
		return 0;
	}
}

void add(hashtable *hash, char val, char *str, int len)
{
	int index = val - 'a';
	memcpy(hash[index].s, str, len);
	hash[index].index = index;
}

int cmp(hashtable *hash, char val, char *str, int len)
{
	int index = val - 'a';
	return strncmp(hash[index].s, str, len);
}	

void show(hashtable *hash)
{
	for (int i = 0; i < 26; i++) 
		if (hash[i].s)
			printf("%s", hash[i].s);
}	

int wordPattern(char *pattern, char *s)
{
	//! two hash map	
	hashtable hash[26];
	int match = 1;
	char *currp = pattern;
	char *currs = s;
	int patternsize = 0;	
	int cnt = 0;
	
	memset(hash, 0, sizeof(hashtable)*26);
	//! cal pattern size
	
	currs = strtok(s, " ");

	while(currs != NULL) {
		printf("currs %s\n", currs);
		currs = strtok(NULL, " ");
		cnt++;
	}	
	printf("cnt %d \n", cnt);
#if 0 
	while(currs[patternsize] != ' ') {
		patternsize++; 
	}

	while(currp[cnt] != '\0') {
		currs = s + (patternsize + 1)*cnt;
		show(hash);
		
		int index = currp[cnt] - 'a';	
		if (!hashkey(hash, index, currs, patternsize)) {
			add(hash, currp[cnt], currs, index); 	
		} else {
			if (strncmp(hash[index].s, currs, index)) {
				match = 0;
				break;
			}
		}

#if 0	
		if (!hashkey(hash, currp[cnt], currs, index)) {
			//! add 
			add(hash, currp[cnt], currs, index); 	
		} else {
			//! compare 
			int hashindex = currp[cnt] - 'a';
			if (strncmp(hash[hashindex].s, currs, index)) {
				match = 0;
				break;
			}
		}	
#endif
		cnt++;
	}
#endif
	
	return match;
}

int main(void)
{
	char pattern[] = "abba";
	//char *s = "dog cat cat dog";
	char s[] = "dog dog dog dog";
	printf("match %d \n", wordPattern(pattern, s));
	return 0;
}
