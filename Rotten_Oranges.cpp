#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }

        vector<vector<int>> dirn = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
        };
        int t = 0;
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int i = top.first.first;
            int j = top.first.second;
            int time = top.second;

            t = max(time, t);
            for (auto it : dirn)
            {
                int x = i + it[0];
                int y = j + it[1];

                if (x < m && x >= 0 && y < n && y >= 0 && vis[x][y] != 2 && grid[x][y] == 1)
                {
                    vis[x][y] = 2;
                    q.push({{x, y}, time + 1});
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                    return -1;
            }
        }

        return t;
    }
};

int main()
{

    return 0;
}