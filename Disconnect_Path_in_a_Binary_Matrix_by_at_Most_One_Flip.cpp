#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool dfs(int row, int col, int m, int n, vector<vector<int>> &grid)
    {
        if (row >= m || col >= n || grid[row][col] == 0)
            return false;

        if (row == m - 1 && col == n - 1)
            return true;

        grid[row][col] = 0;
        return dfs(row + 1, col, m, n, grid) || dfs(row, col + 1, m, n, grid);
    }

public:
    bool isPossibleToCutPath(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (dfs(0, 0, m, n, grid) == false)
            return false;

        grid[0][0] = 1;
        return !dfs(0, 0, m, n, grid);
    }
};

int main()
{

    return 0;
}