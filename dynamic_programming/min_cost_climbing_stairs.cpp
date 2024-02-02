#include <vector>

using namespace std;

// type: easy
// link: https://leetcode.com/problems/min-cost-climbing-stairs
// pattern: find the mimnimum/maximum from A to B.

class Solution
{
    // Time: 2^n, Space: n
    int brute_force(vector<int> &cost, int n)
    {
        if (n < 0)
            return INT_MAX;
        if (n == 0 || n == 1)
            return cost[n];

        return min(brute_force(cost, n - 2), brute_force(cost, n - 1)) +
               (n == cost.size() ? 0 : cost[n]);
    }

    // Time: 2^n, Space: n
    int memoi(vector<int> &cost, vector<int> &dp, int n)
    {
        if (n < 0)
            return INT_MAX;
        if (n == 0 || n == 1)
            return dp[n] = cost[n];
        if (dp[n] != INT_MAX)
            return dp[n];

        return dp[n] = min(memoi(cost, dp, n - 2), memoi(cost, dp, n - 1)) +
                       (n == cost.size() ? 0 : cost[n]);
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        /*
        int l = cost.size();
        vector<int> dp(l + 1, INT_MAX);
        memoi(cost, dp, l);
        return dp[l];
        */
        int a = cost[0], b = cost[1], c;

        for (int i = 2; i < cost.size(); i++)
        {
            c = min(a, b) + cost[i];
            a = b;
            b = c;
        }

        return min(a, b);
    }
};