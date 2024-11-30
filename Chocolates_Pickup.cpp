#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 >= grid[0].size() || j2 >= grid[0].size() || j1 < 0 || j2 < 0)
            return 0;

        if (i == grid.size() - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int ans = 0;
        int result = INT_MIN;
        for (int x = -1; x <= 1; x++)
        {
            for (int y = -1; y <= 1; y++)
            {
                if (j1 == j2)
                    ans = grid[i][j1] + dfs(i + 1, j1 + x, j2 + y, grid, dp);
                else
                    ans = grid[i][j1] + grid[i][j2] + dfs(i + 1, j1 + x, j2 + y, grid, dp);

                result = max(ans, result);
            }
        }

        return dp[i][j1][j2] = result;
    }

public:
    int solve(int n, int m, vector<vector<int>> &grid)
    {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return dfs(0, 0, m - 1, grid, dp);
    }
};

int main()
{

    return 0;
}