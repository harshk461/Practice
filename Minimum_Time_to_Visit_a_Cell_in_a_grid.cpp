#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    vector<pair<int, int>> dirn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

public:
    int minimumTime(vector<vector<int>> &grid)
    {
        if (grid[0][1] > 1 && grid[1][0] > 0)
            return -1;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            int t = top[0];
            int i = top[1];
            int j = top[2];

            if (i == n - 1 && j == m - 1)
                return t;

            if (vis[i][j])
                continue;
            vis[i][j] = true;
            for (auto it : dirn)
            {
                int x = i + it.first;
                int y = j + it.second;

                if (x >= 0 && x < n && y >= 0 && y < m && !vis[x][y])
                {
                    int wait = (grid[x][y] - t) % 2 ? 1 : 0;
                    int new_t = max(grid[x][y] + wait, t + 1);
                    pq.push({new_t, x, y});
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