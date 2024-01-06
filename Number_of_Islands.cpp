#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dirn = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1},
    };
    void bfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();

        vis[i][j] = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto it : dirn)
            {
                int x = top.first + it[0];
                int y = top.second + it[1];

                if (x >= 0 && x < m && y < n && y >= 0 && !vis[x][y] && grid[x][y] == '1')
                {
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] != '0')
                {
                    count++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}