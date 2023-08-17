#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, string word1, string word2, vector<vector<int>> dp)
    {
        if (i >= word1.length() || j >= word2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = 1 + solve(i + 1, j + 1, word1, word2, dp);
        else
            return dp[i][j] = max(solve(i, j + 1, word1, word2, dp), solve(i + 1, j, word1, word2, dp));
    }

    int solveTab(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }

        return n + m - 2 * dp[n][m];
    }

public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        return word1.length() + word2.length() - 2 * solve(0, 0, word1, word2, dp);
    }
};

int main()
{

    return 0;
}