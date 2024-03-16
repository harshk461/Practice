#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int dfs(int i, int j, vector<vector<int>> &grid, int sum, int k,
            vector<vector<vector<int>>> &dp)
    {
        if (i >= grid.size() || j >= grid[0].size())
            return 0;

        if (i == grid.size() - 1 && j == grid[0].size() - 1 && (sum + grid[i][j]) % k == 0)
            return 1;

        if (dp[i][j][sum] != -1)
            return dp[i][j][sum];

        int right = dfs(i, j + 1, grid, (sum + grid[i][j]) % k, k, dp) % MOD;
        int down = dfs(i + 1, j, grid, (sum + grid[i][j]) % k, k, dp) % MOD;
        return dp[i][j][sum] = (right + down) % MOD;
    }

public:
    int numberOfPaths(vector<vector<int>> &grid, int k)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(51, -1)));
        return dfs(0, 0, grid, 0, k, dp);
    }
};

int main()
{

    return 0;
}