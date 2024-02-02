#include <vector>

using namespace std;

// link: https://leetcode.com/problems/subsets-ii/description/

class Solution
{
    vector<vector<int>> sub_sets;

    void back_tracking(vector<int> &nums, vector<int> sub_set, int start)
    {
        sub_sets.push_back(sub_set);

        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i - 1] == nums[i])
                continue;
            sub_set.push_back(nums[i]);
            back_tracking(nums, sub_set, i + 1);
            sub_set.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        return sub_sets;
    }
};