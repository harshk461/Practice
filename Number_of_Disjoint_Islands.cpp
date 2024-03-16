#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<vector<int>> dirn = {
        {-1, 0},
        {0, -1},
        {1, 0},
        {0, 1},
    };
    void dfs(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &vis,
             vector<pair<int, int>> &vec, int row0, int col0)
    {
        vis[row][col] = 1;
        vec.push_back({row - row0, col - col0});
        for (auto it : dirn)
        {
            int x = row + it[0];
            int y = col + it[1];

            if (x < grid.size() && x >= 0 && y < grid[0].size() && y >= 0 && !vis[x][y] && grid[x][y] == 1)
                dfs(x, y, grid, vis, vec, row0, col0);
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};

int main()
{

    return 0;
}