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
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis)
    {
        vis[row][col] = 1;

        for (auto it : dirn)
        {
            int x = row + it[0];
            int y = col + it[1];

            if (x < mat.size() && x >= 0 && y < mat[0].size() && y >= 0 && mat[x][y] == 'O' && vis[x][y] == 0)
                dfs(x, y, mat, vis);
        }
    }

public:
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // boundary wale Os help nhi karenge X conversion mein
        //  all boundary row and col check
        for (int row = 0; row < n; row++)
            if (mat[row][0] == 'O' && !vis[row][0])
                dfs(row, 0, mat, vis);
        for (int row = 0; row < n; row++)
            if (mat[row][m - 1] == 'O' && !vis[row][m - 1])
                dfs(row, m - 1, mat, vis);

        for (int col = 0; col < m; col++)
            if (mat[0][col] == 'O' && !vis[0][col])
                dfs(0, col, mat, vis);

        for (int col = 0; col < m; col++)
            if (mat[n - 1][col] == 'O' && !vis[n - 1][col])
                dfs(n - 1, col, mat, vis);

        for (auto it : vis)
        {
            for (auto i : it)
                cout << i << " ";
            cout << endl;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && !vis[i][j])
                    mat[i][j] = 'X';
            }
        }

        return mat;
    }
};

int main()
{
    vector<vector<char>> arr = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'},
    };
    Solution s;
    s.fill(5, 4, arr);
    return 0;
}