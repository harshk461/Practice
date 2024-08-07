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

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i >= grid.size() || j >= grid[0].size())
            return 1e9;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = grid[i][j];
        int down = grid[i][j];

        right += solve(i, j + 1, grid, dp);
        down += solve(i + 1, j, grid, dp);

        return dp[i][j] = min(right, down);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, grid, dp);
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}};
    Solution s;
    s.minPathSum(arr);
    return 0;
}

class Solution
{
private:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i >= grid.size() || j >= grid[0].size())
            return 1e9;

        int right = grid[i][j] + dfs(i, j + 1, grid, dp);
        int down = grid[i][j] + dfs(i + 1, j, grid, dp);

        return dp[i][j] = min(right, down);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, grid, dp);
    }
};