#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))
#define min(A, B) (A) > (B) ? (B) : (A)

char * getHint(char * secret, char * guess)
{
	char *cura = NULL;
	char *curb = NULL;
	int dataA[11] = {0};
	int dataB[11] = {0};
	int indexA = 0;
	int indexB = 0;
	int len = strlen(secret);
	int lena = 0;
	int lenb = 0;
	char *res = NULL;
	char *cse = strdup(secret);
	char *cg = strdup(guess);
	cura = cse;
	curb = cg;
	for (int i = 0; i < len; i++) {
		if (cura[i] == curb[i]) {
			lena++;
			cura[i] = 'A';
			curb[i] = 'A';
		}
	}

	for (int i = 0; i < len; i++) {
		if (cura[i] == 'A')
			continue;
		indexA = cura[i] - '0';
		dataA[indexA]++;
	}

	for (int i = 0; i < len; i++) {
		if (curb[i] == 'A')
			continue;
		indexB = curb[i] - '0';
		dataB[indexB]++;
	}

	for (int i = 0; i < 10; i++) {
		if (dataA[i] && dataB[i]) {
			int tmp = min(dataA[i], dataB[i]);
			lenb = lenb + tmp;
		}
	}

	res = calloc(20, sizeof(char));
	snprintf(res, 20, "%dA%dB", lena, lenb);
	return res; 
}
int main(void)
{
#if 0
	char ser[5] = "1807"; 
	char gus[5] = "7810";
#else 
	char ser[5] = "1123";
	char gus[5] = "0111";
#endif
	printf("%s \n", getHint(ser, gus));	
	return 0;
}
