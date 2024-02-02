#include <vector>

using namespace std;

// level: medium
// link: https://leetcode.com/problems/triangle/

class Solution
{
public:
    // bottom up approach: Time complexity: O(m * n), Space complexity: O(1).
    // could not use even brute force and memoi since it will get TLE
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int size = triangle.size();
        vector<int> minSum(size + 1);

        for (int i = size - 1; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); j++)
            {
                minSum[i] = min(minSum[j], minSum[j + 1]) + triangle[i][j];
            }
        }

        return minSum[0];
    }
};