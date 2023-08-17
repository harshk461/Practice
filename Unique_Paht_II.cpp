#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid)
    {
        if (i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1)
            return 0;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return 1;

        return solve(i + 1, j, grid) + solve(i, j + 1, grid);
    }

    int solveTabSO(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<long> dp(n);
        dp[0] = 1;

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    dp[j] = 0;
                else if (j > 0)
                    dp[j] += dp[j - 1];
        return dp[n - 1];
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<long>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (!grid[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main()
{

    return 0;
}