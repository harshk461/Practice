#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> One_Row_Count(m, 0);
        vector<int> One_Col_Count(n, 0);

        int rowIndex = 0;
        int colIndex = 0;
        for (int i = 0; i < m; i++)
            One_Row_Count[rowIndex++] = count(grid[i].begin(), grid[i].end(), 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[j][i] == 1)
                    One_Col_Count[colIndex]++;
            }
            colIndex++;
        }

        vector<vector<int>> diff(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                diff[i][j] = 2 * One_Row_Count[i] - m + 2 * One_Col_Count[j] - n;
            }
        }

        return diff;
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 1, 1}, {1, 1, 1}};
    Solution s;
    s.onesMinusZeros(arr);
    return 0;
}