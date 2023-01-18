#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int **result = NULL;
	result = calloc(3, sizeof(int *));
	for (size_t i = 0; i < 3; i++) {
		(*result)[i] = calloc(2, sizeof(int));
	}
	return 0;
}
