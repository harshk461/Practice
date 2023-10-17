#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(int i, int j, int m, int n, int maxMoves, vector<vector<vector<int>>> &dp)
    {
        if (i >= m || j >= n || i < 0 || j < 0)
            return 1;

        if (maxMoves <= 0)
            return 0;

        if (dp[i][j][maxMoves] != -1)
            return dp[i][j][maxMoves];

        int top = solve(i - 1, j, m, n, maxMoves - 1, dp) % MOD;
        int bottom = solve(i + 1, j, m, n, maxMoves - 1, dp) % MOD;
        int right = solve(i, j + 1, m, n, maxMoves - 1, dp) % MOD;
        int left = solve(i, j - 1, m, n, maxMoves - 1, dp) % MOD;

        return dp[i][j][maxMoves] = (top % MOD + bottom % MOD + left % MOD + right % MOD) % MOD;
    }

public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        vector<vector<vector<int>>> dp(51, vector<vector<int>>(51, vector<int>(51, -1)));
        return solve(startRow, startColumn, m, n, maxMove, dp);
    }
};

int main()
{

    return 0;
}