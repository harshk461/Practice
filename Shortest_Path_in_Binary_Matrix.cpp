#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> DIRN = {
        {-1, -1},
        {-1, 0},
        {-1, 1},
        {0, -1},
        {0, 1},
        {1, -1},
        {1, 0},
        {1, 1},
    };
    int solve(int i, int j, int n, vector<vector<int>> &grid,
              vector<vector<int>> &vis, int steps)
    {
        if (i < 0 || i > n || j < 0 || j > n || vis[i][j])
            return INT_MAX;

        if (grid[i][j])
            return INT_MAX;

        if (i == n - 1 && j == n - 1)
            return steps;

        vis[i][j] = 1;

        int mini = INT_MAX;

        for (auto it : DIRN)
            mini = min(mini, solve(i + it[0], j + it[1], n, grid, vis, steps + 1));

        return mini;
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        if (grid[0][0] != 0)
            return -1;

        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({0, 0});
        vector<vector<int>> dirn = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1},
        };

        while (!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();
            for (auto it : dirn)
            {
                int x = top.first + it[0];
                int y = top.second + it[1];

                if (x < 0 || x > m || y < 0 || y > n || grid[x][y] != 0)
                    continue;

                if (dist[x][y] > dist[top.first][top.second] + 1)
                {
                    dist[x][y] = dist[top.first][top.second] + 1;
                    q.push({x, y});
                }
            }
        }

        // if (dist[m - 1][n - 1] == INT_MAX)
        //     return -1;
        // return dist[m - 1][n - 1];
        vector<vector<int>>(m, vector<int>(n, 0));
        return solve(0, 0, n, grid, vis, 0)
    }
};

class Solution
{
public:
    vector<int> x = {-1, 1, 0, 0, -1, 1, -1, 1};
    vector<int> y = {0, 0, -1, 1, -1, 1, 1, -1};
    int dp[105][105][105];
    int helper(vector<vector<int>> &grid, int i, int j, int r, int c, int steps, vector<vector<int>> &vis)
    {
        if (i < 0 or i >= r or j < 0 or j >= c or vis[i][j])
        {
            return INT_MAX;
        }

        if (grid[i][j] == 1)
        {
            return INT_MAX;
        }

        if (i == r - 1 and j == c - 1)
        {
            return steps;
        }

        if (dp[i][j][steps] != -1)
        {
            return dp[i][j][steps];
        }

        vis[i][j] = 1;

        int mini = INT_MAX;

        for (int k = 0; k < 8; k++)
        {
            mini = min(mini, helper(grid, i + x[k], j + y[k], r, c, steps + 1, vis));
        }

        vis[i][j] = 0;

        return dp[i][j][steps] = mini;
    }
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int r = grid.size();
        int c = grid[0].size();
        memset(dp, -1, sizeof(dp));
        vector<vector<int>> vis(r, vector<int>(c, 0));
        int ans = helper(grid, 0, 0, r, c, 1, vis);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    return 0;
}