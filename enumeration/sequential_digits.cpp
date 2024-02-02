#include <vector>
#include <algorithm>

using namespace std;

// link:

// back_tracking approach
// time: 2^(n)
// space: O(1) maximum digits can have is 45 which is a constant
class Solution0
{
    vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> sd;

    void dfs(int num, int i, int &low, int &high)
    {
        if (num >= low && num <= high)
            sd.push_back(num);
        if (num == 9)
            return;

        dfs(num + digits[i], i + 1, low, high);
    }

    vector<int> sequentialDigits(int low, int high)
    {
        sort(sd.begin(), sd.end());
        return sd;
    }
};

// a different type of approach :)
// time: O(45) -> O(1)
// space: O(45) -> O(1)
class Solution1
{
    int digits[45] = {
        12, 23, 34, 45, 56, 67, 78, 89,
        123, 234, 345, 456, 567, 678, 789,
        1234, 2345, 3456, 4567, 5678, 6789,
        12345, 23456, 34567, 45678, 56789,
        123456, 234567, 345678, 456789,
        1234567, 2345678, 3456789,
        12345678, 23456789,
        123456789};
    vector<int> sd;

    vector<int> sequentialDigits(int low, int high)
    {
        for (int digit : digits)
        {
            if (digit > high)
                break;
            if (digit >= low && digit <= high)
                sd.push_back(digit);
        }

        return sd;
    }
};