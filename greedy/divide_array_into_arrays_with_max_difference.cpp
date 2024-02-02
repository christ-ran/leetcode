#include <vector>

using namespace std;

// Medium
// link:https://leetcode.com/problems/divide-array-into-arrays-with-max-difference 

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> arr;        
        sort(nums.begin(), nums.end());

        for (int i = 2; i < nums.size(); i += 3) {
            if (nums[i] - nums[i - 1] <= k && nums[i] - nums[i - 2] <= k && nums[i - 1] - nums[i - 2] <= k) {
                arr.push_back({ nums[i - 2], nums[i - 1], nums[i]  });
            } else {
                return {};
            }
        }

        return arr;
    }
};