#include <vector>

using namespace std;

// link: https://leetcode.com/problems/permutations/

// back_tracking
// time: O(2^n)
// space: O(n)
class Solution
{
    vector<vector<int>> permutations;

    void back_tracking(vector<int> &nums, vector<int> sub_array)
    {
        if (sub_array.size() == nums.size())
        {
            permutations.push_back(sub_array);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (find(sub_array.begin(), sub_array.end(), nums[i]) != sub_array.end())
                continue;

            sub_array.push_back(nums[i]);
            back_tracking(nums, sub_array);
            sub_array.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        back_tracking(nums, {});
        return permutations;
    }
};