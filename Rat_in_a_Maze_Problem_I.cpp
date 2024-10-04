#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<string> ans;
    void solve(int i, int j, int n, vector<vector<int>> &mat, string s, vector<vector<int>> &vis)
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(s);
            return;
        }

        if (j + 1 < n && !vis[i][j + 1] && mat[i][j + 1])
        {
            vis[i][j + 1] = 1;
            solve(i, j + 1, n, mat, s + 'R', vis);
            vis[i][j + 1] = 0;
        }

        if (j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1])
        {
            vis[i][j - 1] = 1;
            solve(i, j - 1, n, mat, s + 'L', vis);
            vis[i][j - 1] = 0;
        }

        if (i + 1 < n && !vis[i + 1][j] && mat[i + 1][j])
        {
            vis[i + 1][j] = 1;
            solve(i + 1, j, n, mat, s + 'D', vis);
            vis[i + 1][j] = 0;
        }

        if (i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j])
        {
            vis[i - 1][j] = 1;
            solve(i - 1, j, n, mat, s + 'U', vis);
            vis[i - 1][j] = 0;
        }
    }

public:
    vector<string> findPath(vector<vector<int>> &mat)
    {
        string s = "";
        int n = mat.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        solve(0, 0, n, mat, s, vis);

        return ans;
    }
};

int main()
{
    vector<vector<int>> mat = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    Solution s;
    vector<string> ans = s.findPath(mat);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}