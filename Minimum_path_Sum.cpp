#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0 && j > 0)
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if (i > 0)
                    grid[i][0] += grid[i - 1][0];
                else if (j > 0)
                    grid[0][j] += grid[0][j - 1];
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return grid[m - 1][n - 1];
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}};
    Solution s;
    s.minPathSum(arr);
    return 0;
}