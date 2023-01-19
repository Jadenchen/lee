#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define STACK_SIZE (1000)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

char * getHint(char * secret, char * guess)
{
	int len = strlen(secret);
	char *cur_s = NULL;
	char *cur_g = NULL;
	char *res = calloc(5, sizeof(char));
	int cnt_A = 0;
	int cnt_B = 0;
	int find = 0;
	for (size_t i = 0; i < len; i++) {
		cur_s = secret + i;
		find = 0;
		for(size_t j = 0; j < len; j++) {
			cur_g = guess + j;
			if (*cur_s == *cur_g) {
				if (i == j)
					cnt_A++;
				else
					cnt_B++;
				find = 1;
			}
			if (find)
				break;
		}
	}
	snprintf(res, 5, "%dA%dB", cnt_A, cnt_B);
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
