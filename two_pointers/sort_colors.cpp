#include <vector>

using namespace std;

// link: https://leetcode.com/problems/sort-colors/

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;

        while (mid <= right)
        {
            if (nums[mid] == 1)
            {
                mid++;
            }
            else if (nums[mid] == 0)
            {
                swap(nums[mid], nums[left]);
                left++;
            }
            else if (nums[mid] == 2)
            {
                swap(nums[mid], nums[right]);
                right--;
            }
        }
    }
};

// Jesus Christ i'm so mind blow
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        unordered_map<int, int> frequencies;

        for (int num : nums)
            frequencies[num]++;

        int index = 0;
        for (int i = 0; i <= 2; i++)
        {
            while (frequencies[i])
            {
                nums[index++] = i;
                frequencies[i]--;
            }
        }
    }
};