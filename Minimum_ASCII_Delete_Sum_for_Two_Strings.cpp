#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        int m = s1.length();
        int n = s2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; i++)
            dp[i + 1][0] = dp[i][0] + s1[i];

        for (int j = 1; j < n; j++)
            dp[0][j + 1] = dp[0][j] + s2[j];

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j];
                else
                    dp[i + 1][j + 1] = min(dp[i][j + 1] + s1[i], dp[i + 1][j] + s2[j]);
            }
        }
        return dp[m][n];
    }
};

int main()
{
    Solution s;
    s.minimumDeleteSum("sea", "eat");
    return 0;
}