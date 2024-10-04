#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<pair<int, int>> dirn = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};
    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});

        vis[i][j] = 1;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            for (auto it : dirn)
            {
                int x = top.first + it.first;
                int y = top.second + it.second;

                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y])
                {
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }
    int countIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0;
        vector<vector<bool>> vis(n, vector<bool>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    islands++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return islands;
    }

public:
    int minDays(vector<vector<int>> &grid)
    {
        int islands = countIslands(grid);

        if (islands != 1)
            return 0;

        // try removing each cell and then checking

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j])
                {
                    grid[i][j] = 0;
                    if (countIslands(grid) != 1)
                        return 1;
                    // backtrack
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};

int main()
{

    return 0;
}