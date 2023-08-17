#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    bool isInside(int x, int y, int n)
    {
        if (x >= 0 && x < n && y >= 0 && y < n)
            return true;
        return false;
    }
    int solve(int i, int j, int k, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (dp[i][j][k] != -1)
            return dp[i][j][k];
        int n = grid.size();
        int new_x = i + dirs[k][0];
        int new_y = j + dirs[k][1];
        if (!isInside(new_x, new_y, n) || grid[new_x][new_y] == 0)
            return 0;
        return dp[i][j][k] = 1 + solve(new_x, new_y, k, grid, dp);
    }

public:
    int orderOfLargestPlusSign(int n, vector<vector<int>> &mines)
    {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, -1)));
        for (auto i : mines)
            grid[i[0]][i[1]] = 0;

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                    ans = max(ans, 1 + min({solve(i, j, 0, grid, dp), solve(i, j, 1, grid, dp), solve(i, j, 2, grid, dp), solve(i, j, 3, grid, dp)}));
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr = {{4, 2}};
    s.orderOfLargestPlusSign(5, arr);
    return 0;
}