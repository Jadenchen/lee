#include <string.h>
#include <stdio.h>
#include "dy.h"
int maxSubArray(int* nums, int numsSize)
{
	int dp[numsSize];
	int max = 0;
	memset(dp, 0, sizeof(int)*numsSize);

	//! max (dp(i - 1) + data(i), data(i));

	dp[0] = nums[0];
	max = dp[0];
	for (int i = 1; i < numsSize; i++) {
		int tmp = dp[i - 1] + nums[i];
		int tmp1 = tmp > nums[i] ? tmp : nums[i];
		dp[i] = tmp1;

		max = max > dp[i] ? max : dp[i];
	}
	return max;
}
