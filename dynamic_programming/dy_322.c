#include <limits.h>
#include "dy.h"
#define MIN(a, b) (a) > (b) ? (b) : (a)
#if 0
  public int coinChange(int[] coins, int amount) {
    return coinChange(0, coins, amount);
  }

  private int coinChange(int idxCoin, int[] coins, int amount) {
    if (amount == 0)
      return 0;
    if (idxCoin < coins.length && amount > 0) {
      int maxVal = amount/coins[idxCoin];
      int minCost = Integer.MAX_VALUE;
      for (int x = 0; x <= maxVal; x++) {
        if (amount >= x * coins[idxCoin]) {
          int res = coinChange(idxCoin + 1, coins, amount - x * coins[idxCoin]);
          if (res != -1)
            minCost = Math.min(minCost, res + x);
        }
      }
      return (minCost == Integer.MAX_VALUE)? -1: minCost;
    }
    return -1;
  }
#endif

static int _coinchange(int idxcoin, int *coins, int coinsize, int amount)
{
	if (amount == 0)
		return 0;

	if (idxcoin < coinsize && amount > 0) {
		int max = amount / coins[idxcoin];
		int mincost = INT_MAX;	
		for (int x = 0; x <= max; x++) {
			if (amount >= x*coins[idxcoin]) {
				int res = _coinchange(idxcoin + 1, coins, coinsize, amount - x*coins[idxcoin]);
				if (res != -1)
					mincost = MIN(mincost, res + x);
			}
		}
		return (mincost == INT_MAX) ? -1: mincost;
	} 
	return -1;
}

int coinexchange(int *coins, int coinsize, int amount)
{
	return _coinchange(0, coins, coinsize, amount);
}
