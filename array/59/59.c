#include <stdio.h>
#include <stdlib.h>

static void gen_matrix(int *pa, int n, int len)
{
#if 0 
	1 (0, 0)

	1  2 (0, 0) (0, 1) 
	4  3 (1, 0) (1, 1)

	1  2  3 (0, 0), (0, 1
	8  9  4 (1, 0  1, 1  1 2
	7  6  5 (2, 0 (2, 1  (2, 2
#endif	
	pa[0] = 1;
	pa[1] = 2;
	pa[2] = 4;
	pa[3] = 3;

	pa[0] = 1;
	pa[1] = 2;
	pa[2] = 3;
	pa[3] = 8
	pa[4] = 9;
	pa[5] = 4
	pa[6] = 7
	pa[7] = 6
	pa[8] = 5
}

int main(void)
{
	int n = 2;
	int len = n * n;
	int *pa = NULL;
	pa = calloc(len, sizeof(int));
	if (!pa) {
		printf("error\n");
		goto ERR;
	}
	
	gen_matrix(pa, n, len);

	for (size_t i = 0; i < len; i++) {
		printf("%d \n", pa[i]);
	}
	
	printf("\n");
ERR:
	if (pa)
		free(pa);
	return 0;
}
