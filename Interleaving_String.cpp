#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // wrong answer after 70 test cases 70/106 solved
    bool solve(int i, int j, int k, string s1, string s2, string s3)
    {
        if (i >= s1.length() || j >= s2.length() || k >= s3.length())
            return false;

        if (s1[i] == s3[k])
            return solve(i + 1, j, k + 1, s1, s2, s3);

        if (s2[j] == s3[k])
            return solve(i, j + 1, k + 1, s1, s2, s3);

        else
            return true;
    }

    bool solve2(int i, int j, int k, string s1, string s2, string s3)
    {
        if (i >= s1.length() || j >= s2.length() || k >= s3.length())
            return true;

        if (k >= s3.length() && i < s1.length() || j < s2.length())
            return false;

        return (((s3[k] == s1[i]) && solve(i + 1, j, k + 1, s1, s2, s3)) ||
                    ((s3[k] == s2[j]) && solve(i, j + 1, k + 1, s1, s2, s3));)
    }

    bool solveTab(string s1, string s2, string s3)
    {
        int m = s1.length();
        int n = s2.length();
        if (m + n != s3.length())
            return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1));
        dp[0][0] = true;

        for (int i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];

        for (int i = 1; i <= n; i++)
            dp[0][i] = dp[0][i - 1] && s2[i - 1] == s3[i - 1];

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1] ||
                           dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];

        return dp[m][n];
    }

public:
    bool isInterleave(string s1, string s2, string s3)
    {
        return solve(0, 0, 0, s1, s2, s3);
    }
};

int main()
{

    return 0;
}