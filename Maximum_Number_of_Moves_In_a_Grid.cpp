#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i < 0 || i > grid.size() || j < 0 || j > grid[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int max_path = 0;

        if (i - 1 >= 0 && j + 1 < grid[0].size() && grid[i - 1][j + 1] > grid[i][j])
            max_path = max(max_path, 1 + solve(i - 1, j + 1, grid, dp));

        if (j + 1 < grid[0].size() && grid[i][j + 1] > grid[i][j])
            max_path = max(1 + solve(i, j + 1, grid, dp), max_path);

        if (i + 1 < grid.size() && j + 1 < grid[0].size() && grid[i + 1][j + 1] > grid[i][j])
            max_path = max(1 + solve(i + 1, j + 1, grid, dp), max_path);

        return dp[i][j] = max_path;
    }

public:
    int maxMoves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int res = solve(i, 0, grid, dp);
            ans = max(ans, res);
        }

        return ans;
    }
};

int main()
{

    return 0;
}