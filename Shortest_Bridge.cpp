#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int i, int j, vector<vector<int>> &grid, queue<pair<int, int>> &q)
    {
        int n = grid.size();
        if (i >= n || i < 0 || j >= n || j < 0 || grid[i][j] == -1 || grid[i][j] == 0)
            return;
        // mark the island 1 with -1 and remaining 1 in grid will be island 2

        grid[i][j] = -1;
        q.push({i, j});
        dfs(i - 1, j, grid, q);
        dfs(i + 1, j, grid, q);
        dfs(i, j - 1, grid, q);
        dfs(i, j + 1, grid, q);
    }

public:
    int shortestBridge(vector<vector<int>> &grid)
    {
        vector<vector<int>> dirn = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int n = grid.size();
        queue<pair<int, int>> q;
        int b = true;
        for (int i = 0; i < n; i++)
        {
            if (b)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        dfs(i, j, grid, q);
                        b = false;
                        break;
                    }
                }
            }
        }

        int ans = 0;
        while (!q.empty())
        {
            int a = q.size();
            while (a--)
            {
                int i = q.front().first;
                int j = q.front().second;

                q.pop();

                for (auto it : dirn)
                {
                    int new_r = i + it[0];
                    int new_c = i + it[1];

                    if (new_r < 0 || new_r >= n || new_c < 0 || new_c >= n || grid[new_r][new_c] == -1)
                        continue;

                    if (grid[new_r][new_c] == 1)
                        return ans;

                    grid[new_r][new_c] = -1;
                    q.push({new_r, new_c});
                }
            }
            ans++;
        }

        return ans;
    }
};

int main()
{

    Solution s;
    vector<vector<int>> arr = {{1, 1, 1, 1, 1}, {1, 0, 0, 0, 1}, {1, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {1, 1, 1, 1, 1}};
    s.shortestBridge(arr);
    return 0;
}