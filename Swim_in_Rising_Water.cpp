#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

//{time,{,j}}
typedef pair<int, pair<int, int>> pi;

class Solution
{
private:
    vector<pair<int, int>> dirn = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}};
    int brute(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int left = grid[0][0], right = *max_element(grid[0].begin(), grid[0].end());

        for (int i = 1; i < n; i++)
        {
            right = max(right, *max_element(grid[i].begin(), grid[i].end()));
        }

        int ans = right;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            vector<vector<bool>> vis(n, vector<bool>(n, false));
            if (solve(0, 0, mid, grid, vis))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }

    bool solve(int i, int j, int time, vector<vector<int>> &grid, vector<vector<bool>> &vis)
    {
        int n = grid.size();
        if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || grid[i][j] > time)
            return false;

        if (i == n - 1 && j == n - 1)
            return true;

        vis[i][j] = true;

        bool ans = solve(i + 1, j, time, grid, vis) ||
                   solve(i - 1, j, time, grid, vis) ||
                   solve(i, j + 1, time, grid, vis) ||
                   solve(i, j - 1, time, grid, vis);

        vis[i][j] = false;
        return ans;
    }

public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        // Min-heap to get cell with minimum time
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({grid[0][0], {0, 0}});

        // To store the minimum time required to reach each cell
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        time[0][0] = grid[0][0];

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int currentTime = top.first;
            int i = top.second.first;
            int j = top.second.second;

            if (i == n - 1 && j == m - 1)
                return currentTime;

            for (auto it : dirn)
            {
                int x = i + it.first;
                int y = j + it.second;

                if (x >= 0 && x < n && y >= 0 && y < m)
                {
                    int newTime = max(currentTime, grid[x][y]);

                    if (newTime < time[x][y])
                    {
                        time[x][y] = newTime;
                        pq.push({newTime, {x, y}});
                    }
                }
            }
        }

        return -1;
    }
};

int main()
{

    return 0;
}