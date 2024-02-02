#include <vector>
#include <string>

using namespace std;

// link: https://leetcode.com/problems/generate-parentheses/description/

// brute_force
// time: O(2^n)
// space: O(n)
class Solution
{
public:
    vector<string> p;

    void brute_force(int &n, string sp, int l, int r)
    {
        if (sp.length() == n * 2)
        {
            p.push_back(sp);
            return;
        }

        if (l < n)
            brute_force(n, sp + '(', l + 1, r);
        if (r < l)
            brute_force(n, sp + ')', l, r + 1);
    }

    vector<string> generateParenthesis(int n)
    {
        brute_force(n, "", 0, 0);
        return p;
    }
};