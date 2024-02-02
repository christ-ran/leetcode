#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Medium
// link: https://leetcode.com/problems/coin-change/
// pattern: memoirization

class Solution
{
    int coinChange(vector<int> &coins, int n)
    {
        if (!n)
            return 0;

        // make an array of n length so that memorize the product.
        // coins: [1, 2, 5] n: n => [0, 1, 2, 3, 4, 5]
        int dp[n + 1];
        dp[0] = 0;

        sort(coins.begin(), coins.end());

        for (int i = 1; i <= n; i++)
        {
            dp[i] = INT_MAX;
            for (int coin : coins)
            {
                if (i - coin < 0)
                    break;
                if (dp[i - coin] != INT_MAX)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }

        return dp[n] != INT_MAX ? -1 : dp[n];
    }
};