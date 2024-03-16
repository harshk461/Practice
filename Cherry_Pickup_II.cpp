#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        if (j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
            return 1e8;

        if (i == grid.size() - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        int maxi = 0;
        for (int dj1 = -1; dj1 <= 1; dj1++)
        {
            for (int dj2 = -1; dj2 <= 1; dj2++)
            {
                if (j1 == j2)
                    maxi = max(maxi, grid[i][j1] + solve(i + 1, j1 + dj1, j2 + dj2, grid, dp));
                else
                    maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + dj1, j2 + dj2, grid, dp));
            }
        }

        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, grid[0].size() - 1, grid, dp);
    }
};

class Solution
{
private:
    int solve(int i, int j1, int j2, vector<vector<int>> &grid)
    {
        if (j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
            return INT_MIN;

        if (i == grid.size() - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            else
                return grid[i][j1] + grid[i][j2];
        }

        int ans = 0;
        ans=max(ans,grid[])
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        return solve(0, 0, n - 1, grid);
    }
};

int main()
{

    return 0;
}