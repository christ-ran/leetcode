#include <vector>

using namespace std;

// link: https://leetcode.com/problems/subsets/

// back_tracking
// time: O(2^n)
// space: O(2^n)
class Solution
{
    vector<vector<int>> sub_sets;

    void back_tracking(vector<int> &nums, vector<int> sub_arr, int start)
    {
        sub_sets.push_back(sub_arr);

        for (int i = start; i < nums.size(); i++)
        {
            sub_arr.push_back(nums[i]);
            back_tracking(nums, sub_arr, i + 1);
            sub_arr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        back_tracking(nums, {}, 0);
        return sub_sets;
    }
};

class Solution1
{
    vector<vector<int>> sub_sets;
    vector<vector<int>> subsets(vector<int> &nums)
    {
        return sub_sets;
    }
};