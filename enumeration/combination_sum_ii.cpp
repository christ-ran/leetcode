#include <vector>

using namespace std;

// link: https://leetcode.com/problems/combination-sum-ii/

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
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            sub_arr.push_back(candidates[i]);
            back_tracking(candidates, target, sub_arr, sum + candidates[i], i + 1);
            sub_arr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        back_tracking(candidates, target, {}, 0, 0);
        return combinations;
    }
};