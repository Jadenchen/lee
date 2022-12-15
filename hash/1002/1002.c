#include <stdio.h>
#include <stdlib.h>
#define LEN (26)
#define A (97)

void show(char *hash)
{
	for (size_t i = 0; i < 26; i++) 
		printf("%d ", hash[i]);
	printf("\n");
}

char **find_comm(char **str, int wordsSize, int *returnSize)
{
	char hash[LEN] = {0};
	char hashother[LEN] = {0};
	char **result = NULL;
	char *curr = NULL;
	int len = 0;

	int index = 0;
	len = strlen(str[0]);
	curr = str[0];
	char tmp[100] = {0};
	int sum = 0;
	for (size_t i = 0; i < len; i++) {
		index = *curr - A;
		hash[index]++;
		curr++;
	}
	
	for (size_t i = 1; i < wordsSize; i++) {
		curr = str[i];
		len = strlen(str[i]);
		memset(hashother, 0, 26);
		for (size_t k = 0; k < len; k++) {
			index = *curr - A;
			hashother[index]++;
			curr++;
		}

		for (size_t j = 0; j < 26; j++) 
			hash[j] = hash[j] > hashother[j] ? hashother[j] : hash[j];
	}	

	show(hash);

	for (size_t i = 0; i < 26; i++) 
		sum += hash[i];


	*returnSize = sum;
	printf("sum %d \n", sum);
	if (sum) {
		result = calloc(*returnSize, sizeof(char *));
		for (size_t i = 0; i < *returnSize; i++) {
			result[i] = calloc(100, sizeof(char));
		}
		index = 0;
		for (size_t i = 0; i < 26; i++) {
			while (hash[i]) {
				char val = i + A;
				memcpy(result[index++], &val, sizeof(char));
				hash[i]--;
			}
		}
	}	
	return result;
}


int main(void)
{
	char *str[10] = {"bella","label","roller"};
	//char *str[10] = {"acabcddd","bcbdbcbd","baddbadb","cbdddcac","aacbcccd","ccccddda","cababaab","addcaccd"};
	char **result = NULL;
	int len = 0;
	result = find_comm(str, 3, &len);
	//result = find_comm(str, 8, &len);
#if 1
	for (size_t i = 0; i < len; i++) 
		printf("%s ", result[i]);

	if (result) {
		for (size_t i = 0; i < len; i++)
			free(result[i]);

		free(result);
	}
#endif	
	return 0;
}
