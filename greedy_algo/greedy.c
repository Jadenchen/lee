#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "greedy.h"

bool lemonadeChange(int* bills, int billsSize)
{
	bool enought = true;
	//const int lemon = 5;
	int fivecnts = 0;
	int tencnts = 0;
	for (int i = 0; i < billsSize; i++) {
		if (bills[i] == 5) {
			fivecnts++;
		} else if (bills[i] == 10) {
			if (fivecnts) {
				fivecnts--;
				tencnts++;
			} else {
				enought = false;
				break;
			}
		} else if (bills[i] == 20) {
			if (tencnts && fivecnts) {
				tencnts--;
				fivecnts--;
			} else if (fivecnts >= 3) {
				fivecnts = fivecnts - 3;
			} else {
				enought = false;
				break;
			}
		}
	}
	return enought;
}

static void fillcnt(int *pdata, int coinData, int index, int* coins, int total, int amount)
{
	int cnt = 0;
	int divid = 0;
	int remain = 0;
	int find = 0;
	int i = 0;

	divid = amount/coinData;
	remain = amount % coinData;

	for (i = index; i < index; i++) {
		if (remain % coins[i])
			continue;
		else {
			find = 1;
			break;
		}
	}

	printf("divid %d remain %d \n", divid, remain);

	if (find) {
		remain = remain / coins[i];
		cnt = divid + remain;
	}
	*pdata = cnt;
}

static int cmp(const void *a, const void *b)
{
	return *(int *)b - *(int *)a;
}

int coinChange(int* coins, int coinsSize, int amount)
{
	int cnt = 0;
	int aCnt[coinsSize];
	memset(aCnt, 0, sizeof(int)*coinsSize);
	qsort(coins, coinsSize, sizeof(int), cmp);

	for (int i = 0; i < coinsSize; i++) {
		fillcnt(&aCnt[i], coins[i], i, coins, coinsSize, amount);
	}

	//! find big cnt
	cnt = aCnt[0];
	for (int i = 1; i < coinsSize; i++) {
		if (cnt < aCnt[i])
			cnt = aCnt[i];
	}

	return cnt;
}

int eraseOverlapIntervals(int* intervals, int intervalsSize, int* intervalsColSize)
{


	return 0;
}

void stop_gas(int dis, const int oil_dis, int *gasid, int gasnums)
{
	int last_stop_id = 0;
	int last_stop_pos = 0;
	int stops = 0;
	int totalgasnums = gasnums + 1;
	printf("total nums %d \n", totalgasnums);
	if (!gasid) {
		return;
	}

	for (int i = 0; i < totalgasnums; i++) {
		if ((gasid[i] - last_stop_pos) > oil_dis) {
			if (last_stop_id == (i - 1)) {
				printf("no solution\n");
				break;
			}
			last_stop_id = i - 1;
			last_stop_pos = gasid[i - 1];
			stops++;
			printf("stop nums %d pos %d \n", stops, last_stop_pos);
			i--;
		}
	}
	printf("stop nums %d \n", stops);
}
