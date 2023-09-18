#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define MIN(a, b) (a) > (b) ? (b) : (a)

#if 0
static int _coinchange(int idxcoin, int* coins, int coinsize, int amount)
{
	if (amount == 0)
		return 0;

	if (idxcoin < coinsize && amount > 0) {
		int maxval = amount / coins[idxcoin];
		int min = INT_MAX;
		for (int x = 0; x <= maxval; x++) {
			if (amount >= x*coins[idxcoin]) {
				int res = _coinchange(idxcoin + 1, coins, coinsize, amount - x*coins[idxcoin]);
				if (res != -1) {
					min = MIN(min, res + x);
				}
			}

		}
		return min == INT_MAX ? -1 : min;
	}
	return -1;
	//archie
}

int coinchange(int *coin, int coinsize, int amount)
{
	return _coinchange(0, coin, coinsize, amount);
}
#endif

#if 0
static int _coinchange(int *coins, int coinsize, int amount)
{
	if (amount < 0)
		return -1;
	if (amount == 0)
		return 0;
	int min = INT_MAX;
	for (int i = 0; i < coinsize; i++) {
		int count = _coinchange(coins, coinsize, amount - coins[i]);
		if (count == -1)
			continue;
		min = MIN(min, count + 1);
	}
	return min == INT_MAX ? -1 : min;
}

int coinchange(int *coin, int coinsize, int amount)
{
	return _coinchange(coin, coinsize, amount);
}
#endif

static int _coinchange(int *coins, int coinsize, int rem, int *arr)
{
	if (rem < 0) return -1;
	if (rem == 0) return 0;
	if (arr[rem - 1] != 0) return arr[rem - 1];
	int min = INT_MAX;
        for (int i = 0; i < coinsize; i++) {
                int count = _coinchange(coins, coinsize, rem - coins[i], arr);
                if (count == -1)
                        continue;
                min = MIN(min, count + 1);
        }
        arr[rem - 1] =  min == INT_MAX ? -1 : min;
	return arr[rem - 1];
}

int coinchange(int *coins, int coinsize, int amount)
{
	int arr[amount];
	if (amount < 1) return 0;
	memset(arr, 0, sizeof(int) * amount);
	return _coinchange(coins, coinsize, amount, arr);
}
