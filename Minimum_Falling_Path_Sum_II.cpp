#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, int n, vector<vector<int>> &grid, vector<vecto<int>> &dp)
    {
        if (i == n - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1e9;
        for (int k = 0; k < n; k++)
            if (k != j)
                ans = min(ans, grid[i][j] + solve(i + 1, k, n, grid, dp));

        return dp[i][j] = ans;
    }

public:
    int minFallingPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
            ans = min(ans, solve(0, i, n, grid, dp));
        return ans;
    }
};

int main()
{

    return 0;
}