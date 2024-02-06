#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> sorts;
        vector<vector<string>> r;

        for (string str : strs)
        {
            string str1 = str;
            sort(str1.begin(), str1.end());
            sorts[str1].push_back(str);
        }

        for (auto [key, value] : sorts)
        {
            r.push_back(value);
        }

        return r;
    }
};