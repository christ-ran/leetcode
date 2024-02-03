#include <vector>

using namespace std;

// the trick here is that we don't need to care about the partition
// tried to write it down all the possiblities.

// eg: 15, 2, 10, 5
// .              5
// .          20  5
// .       30 20  5
// .   50 30 20  5

class Solution
{
public:
    int brute_force(vector<int> &arr, int &k, int index)
    {
        if (index >= arr.size())
            return 0;

        int l = 0, m = 0, total = 0;

        for (int i = index; i < index + k && i < arr.size(); i++)
        {
            l += 1;
            m = max(m, arr[i]);
            total = max(total, (l * m) + brute_force(arr, k, i + 1));
        }

        return total;
    }

    int memoi(vector<int> &arr, vector<int> &dp, int &k, int index)
    {
        if (index >= arr.size())
            return 0;
        if (dp[index] != -1)
            return dp[index];

        int l = 0, m = 0, total = 0;

        for (int i = index; i < index + k && i < arr.size(); i++)
        {
            l += 1;
            m = max(m, arr[i]);
            total = max(total, (l * m) + memoi(arr, dp, k, i + 1));
        }

        return dp[index] = total;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> dp(arr.size(), -1);
        return memoi(arr, dp, k, 0);
    }
};