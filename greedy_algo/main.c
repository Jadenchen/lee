#include <stdio.h>
#include <stdlib.h>
#include "greedy.h"


int main(void)
{
	int bills[] = {5,5,5,10,20};

	int coins[] = {1,2,5};
	int amount = 11;

	int intervals[][2] = {{1,2},{2,3},{3,4},{1,3}};
	int colmnSize[4] = {2, 2, 2, 2};
	//! min stop
	int dis = 19;
       	int oil_dis = 4;
	int gas_id[10] = {2, 3, 5, 7, 8, 11, 13, 14, 16, 18};
	printf(" lemonadeChange bill %d \n",
			lemonadeChange(bills, sizeof(bills)/sizeof(int)));

#if 0
	printf(" coin exange %d \n",
			coinChange(coins, sizeof(coins)/sizeof(int), amount));
#endif

	printf("erase overlap inteval %d \n",
			eraseOverlapIntervals((int *)intervals, 4, colmnSize));
	stop_gas(dis, oil_dis, gas_id, sizeof(gas_id)/sizeof(int));
	return 0;
}
