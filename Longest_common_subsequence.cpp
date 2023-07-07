#include <bits/stdc++.h>
using namespace std;

class Solution
{
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