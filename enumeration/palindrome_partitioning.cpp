#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partitions;

    bool is_palindrome(string &s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left] != s[right])
                return false;
            left++, right--;
        }
        return true;
    }

    void back_tracking(string &s, vector<string> part, int index)
    {
        if (index == s.length())
            partitions.push_back(part);

        for (int i = index; i < s.length(); i++)
        {
            if (!is_palindrome(s, index, i))
                continue;

            part.push_back(s.substr(index, (i + 1) - index));
            back_tracking(s, part, i + 1);
            part.pop_back();
        }
    }

    vector<vector<string>> partition(string s)
    {
        back_tracking(s, {}, 0);
        return partitions;
    }
};