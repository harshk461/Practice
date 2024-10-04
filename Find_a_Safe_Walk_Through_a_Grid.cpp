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
    bool dfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis, int health, vector<vector<vector<int>>> &dp)
    {
        // int m = grid.size();
        // int n = grid[0].size();

        if (i == grid.size() - 1 && j == grid[0].size() - 1 && health > 0)
            return grid[i][j] == 1 && health == 1 ? false : true;

        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || health <= 0 || vis[i][j])
            return false;

        if (dp[i][j][health] != -1)
            return dp[i][j][health];
        // cout << i << "," << j << "->" << health << endl;

        vis[i][j] = true;

        bool ans = dfs(i, j + 1, grid, vis, health - grid[i][j], dp) ||
                   dfs(i + 1, j, grid, vis, health - grid[i][j], dp) ||
                   dfs(i - 1, j, grid, vis, health - grid[i][j], dp) ||
                   dfs(i, j - 1, grid, vis, health - grid[i][j], dp);

        vis[i][j] = false;

        return dp[i][j][health] = ans;
    }

public:
    bool findSafeWalk(vector<vector<int>> &grid, int health)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(health + 1, -1)));
        return dfs(0, 0, grid, vis, health, dp);
    }
};

int main()
{

    return 0;
}