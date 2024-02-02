#include <vector>

using namespace std;

// type: medium
// link: https://leetcode.com/problems/minimum-falling-path-sum/
// pattern: dp, memoirization, minimum/maximum

class Solution
{
public:
    int m, n;

    int brute_force(vector<vector<int>> &matrix, int row, int col)
    {
        if (row == m || col < 0 || col == n)
            return INT_MAX;
        if (row == m - 1)
            return matrix[row][col];

        int left = brute_force(matrix, row + 1, col - 1);
        int middle = brute_force(matrix, row + 1, col);
        int right = brute_force(matrix, row + 1, col + 1);

        return min(min(left, middle), right) + matrix[row][col];
    }

    int memoi(vector<vector<int>> &matrix, vector<vector<int>> &dp, int row, int col)
    {
        if (row == m || col < 0 || col == n)
            return INT_MAX;
        if (row == m - 1)
            return dp[row][col] = matrix[row][col];
        if (dp[row][col] != INT_MAX)
            return dp[row][col];

        int left = memoi(matrix, dp, row + 1, col - 1);
        int middle = memoi(matrix, dp, row + 1, col);
        int right = memoi(matrix, dp, row + 1, col + 1);

        return dp[row][col] = min(min(left, middle), right) + matrix[row][col];
    }

    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        m = matrix.size(), n = matrix[0].size();

        // brute force approach Time O(2^m*n), space: O(1) (TLE)
        /*
        int min_sum = INT_MAX;
        for (int i = 0; i < n; i++) {
            min_sum = min(min_sum, brute_force(matrix, 0, i));
        }
        return min_sum;
        */

        // memoi approach Time O(2^m*n), space: O(1) (TLE)
        /*
        int min_sum = INT_MAX;
        vector<vector<int>> dp(m, vector(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            min_sum = min(min_sum, memoi(matrix, dp, 0, i));
        }
        return min_sum;
        */

        // tabular: bottom up approach O(1) Space, Time: O(m*n)
        int minSum = INT_MAX;

        if (m == 1 && n == 1)
            return matrix[0][0];

        for (int i = m - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; ++j)
            {
                int left = INT_MAX, right = INT_MAX, mid;
                if (j - 1 >= 0)
                    left = matrix[i + 1][j - 1];
                mid = matrix[i + 1][j];
                if (j + 1 <= m - 1)
                    right = matrix[i + 1][j + 1];
                matrix[i][j] = min(mid, min(left, right)) + matrix[i][j];
                if (i == 0)
                    minSum = min(minSum, matrix[i][j]);
            }
        }

        return minSum;
    }
};