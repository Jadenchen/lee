#include <stdbool.h>
#ifndef GREEDY_H
#define GREEDY_H

bool lemonadeChange(int* bills, int billsSize);

int coinChange(int* coins, int coinsSize, int amount);

int eraseOverlapIntervals(int* intervals, int intervalsSize, int* intervalsColSize);

void stop_gas(int dis, int oil_dis, int *gas_id, int gasnums);
#endif

