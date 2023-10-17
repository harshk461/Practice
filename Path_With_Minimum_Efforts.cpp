#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int i, int j, int mid, vector<vector<int>> &heights, vector<vector<bool>> &vis)
    {
        int n = heights.size();
        int m = heights[0].size();
        if (i == n - 1 && j == m - 1)
            return true;

        vis[i][j] = true;

        bool ans = false;

        if (i > 0 && v[i - 1][j] == 0 && abs(heights[i][j] - heights[i - 1][j]) <= mid)
            ans = ans || solve(i - 1, j, mid, heights, vis);
        if (j > 0 && v[i][j - 1] == 0 && abs(heights[i][j] - heights[i][j - 1]) <= mid)
            ans = ans || solve(i, j - 1, mid, heights, vis);
        if (i < n - 1 && v[i + 1][j] == 0 && abs(heights[i][j] - heights[i + 1][j]) <= mid)
            ans = ans || solve(i + 1, j, mid, heights, vis);
        if (j < m - 1 && v[i][j + 1] == 0 && abs(heights[i][j] - heights[i][j + 1]) <= mid)
            ans = ans || solve(i, j + 1, mid, heights, vis);

        return ans;
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        int n = heights.size();
        int m = heights[0].size();
        int start = 0, end = 1e9;
        int ans = INT_MAX;
        while (start <= end)
        {
            vector<vector<bool>> vis(101, vector<bool>(101, false));
            int mid = start + (end - start) / 2;
            if (solve(0, 0, mid, heights, vis))
            {
                ans = min(ans, mid);
                end = mid - 1;
            }
            else
                left = mid + 1;
        }
        return ans;
    }
};

int main()
{

    return 0;
}