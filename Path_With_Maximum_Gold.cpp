#include <bits/stdc++.h>
using namespace std;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2)
        {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

class Solution
{
private:
    int solve(int i, int j, vector<vector<int>> &grid, unordered_map<pair<int, int>, bool, hash_pair> &vis)
    {
        int m = grid.size();
        int n = grid[0].size();

        if (i < 0 || i >= m || j < 0 || j >= n)
            return 0;

        if (grid[i][j] == 0)
            return INT_MIN;

        if (vis[{i, j}])
            return 0;

        int ans = 0;
        // top
        int top = 0;
        if (j - 1 > 0 && grid[i][j - 1] != 0)
        {
            vis[{i, j - 1}] = true;
            top = grid[i][j - 1] + solve(i, j - 1, grid, vis);
            vis[{i, j - 1}] = true;
        }

        // bottom
        int bottom = 0;
        if (j + 1 < n && grid[i][j + 1] != 0)
        {
            vis[{i, j + 1}] = true;
            bottom = grid[i][j + 1] + solve(i, j + 1, grid, vis);
            vis[{i, j + 1}] = true;
        }

        // left
        int left = 0;
        if (i - 1 > 0 && grid[i - 1][j] != 0)
        {
            vis[{i - 1, j}] = true;
            left = grid[i - 1][j] + solve(i - 1, j, grid, vis);
            vis[{i - 1, j}] = true;
        }

        // right
        int right = 0;
        if (i + 1 < m && grid[i + 1][j] != 0)
        {
            vis[{i + 1, j}] = true;
            right = grid[i + 1][j] + solve(i + 1, j, grid, vis);
            vis[{i + 1, j}] = true;
        }

        return ans + max({top, bottom, left, right});
    }

    int f(int i, int j, int &maxi, int output,
          vector<vector<bool>> &vis, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] || grid[i][j] == 0)
            return max(output, maxi);

        vis[i][j] = true;
        output += grid[i][j];
        int downMax = f(i + 1, j, maxi, output, vis, grid);
        int upMax = f(i - 1, j, maxi, output, vis, grid);
        int leftMax = f(i, j + 1, maxi, output, vis, grid);
        int rightMax = f(i, j - 1, maxi, output, vis, grid);

        vis[i][j] = false;
        maxi = max({downMax, upMax, rightMax, leftMax});
        return maxi;
    }

public:
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        int maxi = 0, ouput = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                ans = f(i, j, maxi, ouput, visited, grid);
                maxi = max(maxi, ans);
            }

        return maxi;
    }
};

int main()
{
    vector<vector<int>> arr = {
        {0, 6, 0},
        {5, 8, 7},
        {0, 9, 0},
    };
    Solution s;
    cout << s.getMaximumGold(arr);
    return 0;
}