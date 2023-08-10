#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(string s, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i > j)
            return 0;
        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
            dp[i][j] = 2 + solve(s, i + 1, j - 1, dp);

        else
            dp[i][j] = max(solve(s, i, j - 1, dp), solve(s, i + 1, j, dp));
        return dp[i][j];
    }

    int solveTab(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int d = 1; d < n; d++)
        {
            for (int i = 0; i + d < n; i++)
            {
                int j = i + d;
                if (s[i] == s[j])
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }

public:
    int longestPalindromeSubseq(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(s, 0, n - 1, dp);
    }
};

int main()
{

    return 0;
}