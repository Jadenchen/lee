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
   printf("len %d \n", len);
   for (size_t i = 0; i < len; i++) {
       cur_s = secret + i;
       cur_g = guess;

       for(size_t j = 0; j < len; j++) {
	       printf("%c %c \n", cur_s[0], cur_g[j]);
           if (cur_s[0] == cur_g[j]) {
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
//	char ser[5] = {'1', '8', '0', '7', '\0'};
//	char gus[5] = {'7', '8', '1', '0', '\0'};
	char ser[5] = {'1', '1', '2', '3', '\0'};
	char gus[5] = {'0', '1', '1', '1', '\0'};

//	printf("%c%c%c%c\n", ser[0], ser[1], ser[2], ser[3]);
	printf("%s \n", getHint(ser, gus));	
	return 0;
}
