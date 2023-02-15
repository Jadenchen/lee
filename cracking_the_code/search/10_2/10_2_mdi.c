#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define ERROR (65536)
#define HASH_SIZE (100)
#define addr2uint(x) ((uint64_t)(void *)(x))
#define uint2addr(x) ((void *)(uint64_t)(x))

#define SIZE (10000)
#define STRLEN (26)  
typedef struct hashtalbe {
        char *strs;
        int arr[STRLEN];
        struct hashtalbe *next;
} hashtalbe;

hashtalbe *new_node(char *strs, int *tmp)
{
        hashtalbe *new = calloc(1, sizeof(hashtalbe));
        new->strs = strdup(strs);
        memcpy(new->arr, tmp, sizeof(int)*STRLEN);
        new->next = NULL;
        return new;
}

void add_hash(hashtalbe *hash, char *strs, int *returnSize) 
{
        hashtalbe *cur = NULL;
        int tmp[STRLEN] = {0};
        int  strslen = strlen(strs);
        int i = 0;
        for (i = 0; i < strslen; i++)
                tmp[strs[i] - 'a']++;

        for (i = 0; i < *returnSize; i++) {
                cur = &hash[i];
                if (strslen == strlen(cur->strs) && !memcmp(cur->arr, tmp, sizeof(int)*STRLEN)) {
                        while(cur->next)
                                cur = cur->next;
                        hashtalbe *new = new_node(strs, tmp);
                        cur->next = new;
                        return;
                }
        }

        cur = &hash[i];
        *returnSize = *returnSize + 1;
        cur->strs = strdup(strs);
        memcpy(cur->arr, tmp, sizeof(int)*STRLEN);
        cur->next = NULL;
        return;
}     

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes)
{		
        char ***res = NULL;
        char *curs = NULL;    
        *returnSize = 0;
        hashtalbe hash[SIZE] = {0};
        hashtalbe *cur = NULL;
    
        int idx = 0;
        for (int i = 0; i < strsSize; i++) {
                curs = strs[i];
                add_hash(hash, curs, returnSize);
        }

        *returnColumnSizes = calloc(10000, sizeof(int));
        res = calloc(*returnSize, sizeof(char **));
        for (int i = 0; i < *returnSize; i++) {
                res[i] = calloc(1000, sizeof(char *));
        }

        for (int i = 0; i < *returnSize; i++) {
                cur = &hash[i];
                int j = 0;
                while(cur) {
                        res[i][j++] = strdup(cur->strs);
                        cur = cur->next;
                } 
                (*returnColumnSizes)[i] = j;
                res[i] = realloc(res[i], j*sizeof(char *)) ;
        }
        return res;
} 	
int main(void)
{
	char *a[] = {"eat","tea","tan","ate","nat","bat"};
	int returnSize = 0;
	int *returnColumnSizes = NULL;
	char ***result = NULL;
	result = groupAnagrams(a, 6, &returnSize, &returnColumnSizes); 
	for (size_t i = 0; i < returnSize; i++) {
		for (size_t j = 0; j < returnColumnSizes[i]; j++) {
			printf("%s ", result[i][j]);
		}
		printf("\n");
	}
	return 0 ;
}
