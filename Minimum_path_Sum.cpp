#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > 0 && j > 0)
                    grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
                else if (i > 0)
                    grid[i][0] += grid[i - 1][0];
                else if (j > 0)
                    grid[0][j] += grid[0][j - 1];
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return grid[m - 1][n - 1];
    }
};

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i >= grid.size() || j >= grid[0].size())
            return 1e9;

        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = grid[i][j];
        int down = grid[i][j];

        right += solve(i, j + 1, grid, dp);
        down += solve(i + 1, j, grid, dp);

        return dp[i][j] = min(right, down);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return solve(0, 0, grid, dp);
    }
};

int main()
{
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}};
    Solution s;
    s.minPathSum(arr);
    return 0;
}

class Solution
{
private:
    int dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i >= grid.size() || j >= grid[0].size())
            return 1e9;

        int right = grid[i][j] + dfs(i, j + 1, grid, dp);
        int down = grid[i][j] + dfs(i + 1, j, grid, dp);

        return dp[i][j] = min(right, down);
    }

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, grid, dp);
    }
};

#include <vector>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef pair<int, pair<int, int>> pi;

class Solution
{
private:
    // Define directions for moving right or down
    vector<pair<int, int>> dirn = {{1, 0}, {0, 1}};

public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Priority queue to store the minimum path cost and position
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({grid[0][0], {0, 0}});

        // Distance matrix to track minimum cost to reach each cell
        vector<vector<int>> minCost(n, vector<int>(m, INT_MAX));
        minCost[0][0] = grid[0][0];

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int cost = top.first;
            int i = top.second.first;
            int j = top.second.second;

            // If we've reached the bottom-right corner, return the cost
            if (i == n - 1 && j == m - 1)
                return cost;

            // Traverse possible directions (down, right)
            for (auto it : dirn)
            {
                int x = i + it.first;
                int y = j + it.second;

                // Check if (x, y) is within bounds and offers a cheaper path
                if (x >= 0 && x < n && y >= 0 && y < m)
                {
                    int newCost = cost + grid[x][y];
                    if (newCost < minCost[x][y])
                    {
                        minCost[x][y] = newCost;
                        pq.push({newCost, {x, y}});
                    }
                }
            }
        }

        return -1; // In case there's no path, which shouldn't happen for a well-formed grid
    }
};
