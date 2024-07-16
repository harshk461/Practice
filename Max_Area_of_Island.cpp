#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dirn = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}};

    int bfs(int i, int j, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        int area = 0;

        while (!q.empty())
        {
            pair<int, int> top = q.front();
            q.pop();
            area++;
            // cout << top.first << " " << top.second << " " << endl;
            for (auto it : dirn)
            {
                int x = top.first + it[0];
                int y = top.second + it[1];

                if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && vis[x][y] == false)
                {
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }

        // cout << "Next"<<endl;

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));

        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vis[i][j] = 1;
                    int area = bfs(i, j, grid, vis);
                    ans = max(ans, area);
                }
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}