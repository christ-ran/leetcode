#include <vector>

using namespace std;

// link: https://leetcode.com/problems/combination-sum/

class Solution
{
public:
    vector<vector<int>> combinations;

    void back_tracking(vector<int> &candidates, int &target, vector<int> sub_arr, int sum, int start)
    {
        if (sum == target)
        {
            combinations.push_back(sub_arr);
            return;
        }
        if (sum > target)
            return;

        for (int i = start; i < candidates.size(); i++)
        {
            sub_arr.push_back(candidates[i]);
            back_tracking(candidates, target, sub_arr, sum + candidates[i], i);
            sub_arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        back_tracking(candidates, target, {}, 0, 0);
        return combinations;
    }
};