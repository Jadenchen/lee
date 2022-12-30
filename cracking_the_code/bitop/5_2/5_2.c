#include <stdio.h>
#include <stdlib.h>

void calint(int a)
{
	while(a) {
		printf("%d", a & 1);
	       a = a >> 1;
	}	       
	printf("\n");
}

int binToString(double val)
{
	int arr[32] = {0};
	int i = 0;
	double r = 0.0;
	if (val >= 1 || val <= 0)
		return -1;
	
	while(val > 0) {
		if (i >= 32) {
			printf("ERROR\n");
			break;
		}
	
		r = val*2;
		if (r >= 1) {
			arr[i++] = 1;
			val = r - 1;	
		} else {
			arr[i++] = 0;
			val = r;
		}
	}	
		
	for (int j = i - 1; j >= 0; j--)
		printf("%d", arr[j]);

	printf("\n");	
	return 0;
}

int main(void)
{	
	int a = 21;
	float b = 0.72;
	calint(a);
	binToString(b);
	return 0 ;
}
