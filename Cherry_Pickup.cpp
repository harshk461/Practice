#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dp[51][51][51];
    int dfs(int r1, int c1, int r2, int n, vector<vector<int>> &grid)
    {
        int c2 = r1 + c1 - r2;

        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        if (r1 == n - 1 && c1 == n - 1)
            return grid[r1][c1];

        int ans = grid[r1][c1];

        if (r1 != r2)
            ans += grid[r2][c2];

        // we have 4 option to place our cherry picker
        // DD->both go in down direction
        // DR->first go down and second one in right
        // RR->both go in right direction
        // RD->second go down and first one in right

        // int DD = dfs(r1 + 1, c1, r2 + 1, n, grid);
        // int RR = dfs(r1, c1 + 1, r2, n, grid);
        // int DR = dfs(r1 + 1, c1, r2, n, grid);
        // int RD = dfs(r1, c1 + 1, r2 + 1, n, grid);

        // int temp = max({DD, DR, RD, RR});

        // ans += temp;
        int temp = max(dfs(r1 + 1, c1, r2 + 1, n, grid), dfs(r1, c1 + 1, r2, n, grid));
        temp = max(temp, dfs(r1 + 1, c1, r2, n, grid));
        temp = max(temp, dfs(r1, c1 + 1, r2 + 1, n, grid));

        ans += temp;

        return ans;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int n = grid.size();
        memset(dp, -1, sizeof(dp));
        return max(0, dfs(0, 0, 0, n, grid));
    }
};

int main()
{

    return 0;
}