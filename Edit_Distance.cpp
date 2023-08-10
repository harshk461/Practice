#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(string &a, string b, int i, int j)
    {
        // base case
        if (i == a.length())
            return b.length() - j;
        if (j == b.length())
            return a.length() - i;

        int ans = 0;
        // when character match
        if (a[i] == b[j])
            return solve(a, b, i + 1, j + 1);
        else
        {
            // insert
            int insertAns = 1 + solve(a, b, i, j + 1);

            // delete
            int deleteAns = 1 + solve(a, b, i + 1, j);

            // replace
            int replaceAns = 1 + solve(a, b, i + 1, j + 1);

            ans = min(insertAns, min(deleteAns, replaceAns));
        }

        return ans;
    }
    // int solve(string word1, string word2)
    // {
    //     int m = word1.length();
    //     int n = word2.length();

    //     vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    //     for (int i = 1; i <= m; i++)
    //         dp[i][0] = i;
    //     for (int j = 1; j <= n; j++)
    //         dp[0][j] = j;

    //     for (int i = 1; i <= m; i++)
    //     {
    //         for (int j = 1; j <= n; j++)
    //         {
    //             if (word1[i - 1] == word2[j - 1])
    //                 dp[i][j] = dp[i - 1][j - 1];
    //             else
    //                 dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    //         }
    //     }

    //     for (auto i : dp)
    //     {
    //         for (auto j : i)
    //             cout << j << " ";
    //         cout << endl;
    //     }
    //     return dp[m][n];
    // }

public:
    int minDistance(string word1, string word2)
    {
        int i = 0, j = 0;
        return solve(word1, word2);
    }
};

int main()
{
    Solution s;
    s.minDistance("horse", "ros");
    return 0;
}