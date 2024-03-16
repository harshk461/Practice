#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, int m, int n, vector<vector<int>> &grid,
              vector<vector<int>> &cost, vector<vector<int>> &dp)
    {
        if (i == m - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = 0; k < n; k++)
            ans = min(ans, cost[grid[i][j]][k] + grid[i][j] + solve(i + 1, k, m, n, grid, cost, dp));
        return dp[i][j] = ans;
    }

public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost)
    {
        int m = grid.size();
        int n = grid[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            ans = min(ans, solve(0, i, m, n, grid, moveCost, dp));

        return ans;
    }
};

int main()
{

    return 0;
}