#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool bfs(int health, vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, health + grid[0][0]});

        while (!q.empty())
        {
            auto top = q.front();
            int hp = top.second;
            int a = top.first.first;
            int b = top.first.second;

            q.pop();

            if (hp <= 0)
                continue;

            if (a == m - 1 && b == n - 1 && hp > 0)
                return true;

            if (a + 1 < m)
                q.push({{a + 1, b}, hp + grid[a + 1][b]});
            if (b + 1 < n)
                q.push({{a, b + 1}, hp + grid[a][b + 1]});
        }

        return false;
    }

    bool dfs(int i, int j)

        public : int calculateMinimumHP(vector<vector<int>> &dungeon)
    {
        int start = 1;
        int end = 1e9;

        int mid = start + (end - start) / 2;

        int ans = INT_MAX;
        while (start <= end)
        {
            if (bfs(mid, dungeon))
            {
                ans = min(ans, mid);
                end = mid + 1;
            }
            else
                start = mid;
        }

        return ans;
    }
};

class Solution
{
public:
    int pre(int i, int j, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp)
    {
        if (i >= n + 1 or j >= m + 1)
            return 1e9;
        if (i == n and j == m)
            return arr[i][j] > 0 ? 1 : 1 - arr[i][j];
        if (dp[i][j] != -1)
            return dp[i][j];

        int down = pre(i + 1, j, n, m, arr, dp);
        int right = pre(i, j + 1, n, m, arr, dp);
        int res = min(down, right) - arr[i][j];
        return dp[i][j] = res > 0 ? res : 1;
    }
    int calculateMinimumHP(vector<vector<int>> &arr)
    {
        int n = arr.size(), m = arr[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return pre(0, 0, n - 1, m - 1, arr, dp);
    }
};

int main()
{

    return 0;
}