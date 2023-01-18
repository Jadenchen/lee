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
   for (size_t i = 0; i < len; i++) {
       cur_s  = secret + i;
       cur_g = guess;
       for(size_t j = 0; j < len; j++) {
           if (!strcmp(cur_s, cur_g)) {
               if (i == j)
                   cnt_A++;
               else
                   cnt_B++;

           }
       }
   }
    snprintf(res, 5, "%dA%dB", cnt_A, cnt_B);
    return res;
}

int main(void)
{
	char ser[4] = {'1', '8', '0','7'};
	char gus[4] = {'7','8','1','0'};
	printf("%s\n", ser);
	//printf("%s \n", getHint(ser, gus));	
	return 0;
}
