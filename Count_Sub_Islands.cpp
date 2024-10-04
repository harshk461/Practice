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
    bool subisland(int i, int j, vector<vector<int>> &grid1, vector<vector<int>> &grid2, vector<vector<bool>> &vis)
    {
        int m = grid1.size();
        int n = grid1[0].size();

        bool isSubisland = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            if (grid1[top.first][top.second] == 0)
                isSubisland = false;

            for (auto it : dirn)
            {
                int x = top.first + it.first;
                int y = top.second + it.second;

                if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && grid2[x][y] == 1)
                {
                    q.push({x, y});
                    vis[x][y] = true;
                }
            }
        }

        return isSubisland;
    }

public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size();
        int n = grid1[0].size();

        int ans = 0;

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!vis[i][j] && grid2[i][j] == 1 && subisland(i, j, grid1, grid2, vis))
                    ans++;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}