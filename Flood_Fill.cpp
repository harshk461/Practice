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
    void bfs(int i, int j, vector<vector<int>> &image, int start, int color, vector<vector<bool>> &vis)
    {
        int m = image.size();
        int n = image[0].size();

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
                if (x >= 0 && x < m && y < n && y >= 0 && !vis[x][y] && image[x][y] == start)
                {
                    vis[x][y] = true;
                    image[x][y] = color;
                    q.push({x, y});
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int m = image.size();
        int n = image[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n));

        bfs(sr, sc, image, image[sr][sc], color, vis);

        return image;
    }
};

int main()
{

    return 0;
}