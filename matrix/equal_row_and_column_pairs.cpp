#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

// link: https://leetcode.com/problems/equal-row-and-column-pairs/

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        unordered_map<string, int> row_map;
        unordered_map<string, int> col_map;
        int c = 0;

        for (int i = 0; i < m; i++)
        {
            string row = "", col = "";
            for (int j = 0; j < n; j++)
            {
                row += to_string(grid[i][j]);
                row += ',';
                col += to_string(grid[j][i]);
                col += ',';
            }

            row_map[row]++;
            col_map[col]++;
        }

        for (const auto &p : row_map)
        {
            if (col_map.find(p.first) == col_map.end())
                continue;

            c += p.second * col_map[p.first];
        }

        return c;
    }
};