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
    void dfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;

        for (auto it : dirn)
        {
            int x = row + it[0];
            int y = col + it[1];

            if (x < mat.size() && x >= 0 && y < mat[0].size() && y >= 0 && mat[x][y] == 1 && vis[x][y] == 0)
                dfs(x, y, mat, vis);
        }
    }

    void bfs(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty())
        {
            auto top = q.front();

            for (auto it : dirn)
            {
                int x = top.first + it[0];
                int y = top.second + it[1];

                if (x < mat.size() && x >= 0 && y < mat[0].size() && y >= 0 && mat[x][y] == 1 && vis[x][y] == 0)
                {
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for (int row = 0; row < m; row++)
        {
            if (grid[row][0] == 1 && !vis[row][0])
                bfs(row, 0, grid, vis);
            if (grid[row][n - 1] == 1 && !vis[row][n - 1])
                bfs(row, n - 1, grid, vis);
        }

        for (int col = 0; col < n; col++)
        {
            if (grid[0][col] == 1 && !vis[0][col])
                bfs(0, col, grid, vis);
            if (grid[m - 1][col] == 1 && !vis[m - 1][col])
                bfs(m - 1, col, grid, vis);
        }

        // for (auto it : vis)
        // {
        //     for (auto i : it)
        //         cout << i << " ";
        //     cout << endl;
        // }
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    ans++;

        return ans;
    }
};

class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                {
                    if (grid[i][j] == 1)
                    {
                        vis[i][j] = 1;
                        q.push({i, j});
                    }
                }
        vector<vector<int>> dirn = {
            {1, 0},
            {0, 1},
            {-1, 0},
            {0, -1},
        };

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            for (auto it : dirn)
            {
                int x = top.first + it[0];
                int y = top.second + it[1];

                if (x < m && x >= 0 && y < n && y >= 0 && grid[x][y] == 1 && vis[x][y] == 0)
                {
                    vis[x][y] = 1;
                    q.push({x, y});
                }
            }
        }

        for (auto it : vis)
        {
            for (auto i : it)
                cout << i << " ";
            cout << endl;
        }

        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    ans++;

        return ans;
    }
};

int main()
{
    vector<vector<int>> arr = {{0, 1, 1, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}};
    Solution s;
    s.numEnclaves(arr);
    return 0;
}