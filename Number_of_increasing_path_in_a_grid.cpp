#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

class Solution
{
private:
    int n;
    int m;
    vector<vector<int>> dp;
    vector<int> dirs = {0, 1, 0, -1, 0};
    int dfs(vector<vector<int>> &grid, int i, int j)
    {
        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + dirs[k];
            int y = j + dirs[k + 1];
            if (x < 0 || x == m || y < 0 || y == n)
                continue;
            if (grid[x][y] <= grid[i][j])
                continue;

            dp[i][j] += dfs(grid, x, y);
            dp[i][j] %= MOD;
        }
        return dp[i][j];
    }

public:
    int countPaths(vector<vector<int>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans += dfs(grid, i, j);
                ans %= MOD:
            }
        }
        return ans;
    }
};
int main()
{

    return 0;
}