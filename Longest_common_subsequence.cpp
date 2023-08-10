#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(string text1, string text2, int i, int j)
    {
        if (i == text1.length() || j == text2.length())
            return 0;
        if (text1[i] == text2[j])
            return 1 + solve(text1, text2, i + 1, j + 1);
        else
            return max(solve(text1, text2, i, j + 1), solve(text1, text2, i + 1, j));
    }

    int solveMem(string text1, string text2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == text1.length() || j == text2.length())
            return 0;

        int ans = 0;

        if (text1[i] == text2[j])
            ans = 1 + solveMem(text1, text2, i + 1, j + 1, dp);
        else
            ans = max(solveMem(text1, text2, i, j + 1, dp), solveMem(text1, text2, i + 1, j, dp));

        dp[i][j] = ans;
    }

    int solveTab(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (text1[i] == text2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[0][0];
    }

    int solveTabSO(string text1, string text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                int ans = 0;
                if (text1[i] == text2[j])
                    ans = 1 + next[j + 1];
                else
                    ans = max(curr[j + 1], next[j]);
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                dp[i + 1][j + 1] = text1[i] == text2[j]
                                       ? 1 + dp[i][j]
                                       : max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[m][n];
    }
};

int main()
{

    return 0;
}