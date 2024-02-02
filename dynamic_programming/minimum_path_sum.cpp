#include <vector>

using namespace std;

// type: medium
// link: https://leetcode.com/problems/minimum-path-sum/
// pattern: min/max from A to B, memoi, dp

class Solution
{
    int m, n;
    // Time: 2 ^ (m*n) Space: O(1)
    int brute_force(vector<vector<int>> &grid, int row, int col)
    {
        if (row >= m || col >= n)
            return INT_MAX;
        if (row == m - 1 && col == n - 1)
            return grid[row][col];
        return min(brute_force(grid, row + 1, col),
                   brute_force(grid, row, col + 1)) +
               grid[row][col];
    }

    // Time: 2 ^ (m*n) Space: O(m * n)
    int memoi(vector<vector<int>> &grid, vector<vector<int>> &dp, int row,
              int col)
    {
        if (row >= m || col >= n)
            return INT_MAX;
        if (row == m - 1 && col == n - 1)
            return dp[row][col] = grid[row][col];

        if (dp[row][col] != INT_MAX)
            return dp[row][col];

        return dp[row][col] = min(memoi(grid, dp, row + 1, col),
                                  memoi(grid, dp, row, col + 1)) +
                              grid[row][col];
    }

    int minPathSum(vector<vector<int>> &grid)
    {
        /*
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector(n, INT_MAX));
        return memoi(grid, dp, 0, 0);
        */

        m = grid.size(), n = grid[0].size();

        for (int i = 1; i < m; i++)
        {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < n; i++)
        {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }

        return grid[m - 1][n - 1];
    }
};