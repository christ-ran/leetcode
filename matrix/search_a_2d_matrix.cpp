#include <vector>

using namespace std;

class Solution
{
public:
    int m, n;
    bool binarySearch(vector<vector<int>> &matrix, int &target, int row, int col)
    {
        if (row > col)
            return false;

        int mid = (row + col) / 2;

        int value = matrix[mid / n][mid % n];

        if (value == target)
            return true;
        else if (value < target)
            return binarySearch(matrix, target, mid + 1, col);
        else
            return binarySearch(matrix, target, row, mid - 1);
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        m = matrix.size(), n = matrix[0].size();
        return binarySearch(matrix, target, 0, (m * n) - 1);
    }
};