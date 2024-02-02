#include <vector>

using namespace std;

class Solution
{
public:
    int digits[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> r;

    void back_tracking(vector<int> sr, int sum, int index, int &k, int &n)
    {
        if (sr.size() == k && sum == n)
        {
            r.push_back(sr);
            return;
        }

        if (sum > n)
            return;

        for (int i = index; i < 9; i++)
        {
            sr.push_back(digits[i]);
            back_tracking(sr, sum + digits[i], i + 1, k, n);
            sr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        back_tracking({}, 0, 0, k, n);
        return r;
    }
};