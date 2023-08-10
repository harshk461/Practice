#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> dirs = {0, 1, 0, -1, 0};
        queue<pair<int, int>> q;
        vector<vector<bool>> vis(m, vector<bool>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0)
                {
                    q.emplace(i, j);
                    vis[i][j] = true;
                }

        while (!q.empty())
        {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int x = i + dirs[k];
                int y = j + dirs[k + 1];

                if (x < 0 || x == m || y < 0 || y == n)
                    continue;
                if (vis[x][y])
                    continue;

                mat[x][y] = 1 + mat[i][j];
                q.emplace(x, y);
                vis[x][y] = true;
            }
        }

        return mat;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> arr = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> ans = s.updateMatrix(arr);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}