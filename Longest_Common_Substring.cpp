#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
private:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp, int &maxLen)
    {
        if (i >= s1.size() || j >= s2.size())
            return 0; // No substring when out of bounds

        if (dp[i][j] != -1)
            return dp[i][j]; // Return cached result

        // If characters match, increment the length of common substring
        if (s1[i] == s2[j])
        {
            dp[i][j] = 1 + solve(i + 1, j + 1, s1, s2, dp, maxLen);
            maxLen = max(maxLen, dp[i][j]); // Track the maximum length found
        }
        else
        {
            dp[i][j] = 0; // Reset when no match
        }

        // No need to explicitly compute other cases since max length is stored and tracked
        solve(i + 1, j, s1, s2, dp, maxLen); // Move to next character in s1
        solve(i, j + 1, s1, s2, dp, maxLen); // Move to next character in s2

        return dp[i][j];
    }

public:
    int longestCommonSubstr(string str1, string str2)
    {
        int ans = 0;
        int n = str1.size();
        int m = str2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // for (int i = 1; i <= n; i++)
        // {
        //     for (int j = 1; j <= m; j++)
        //     {
        //         if (str1[i - 1] == str2[j - 1])
        //         {
        //             int val = 1 + dp[i - 1][j - 1];
        //             ans = max(ans, val);
        //             dp[i][j] = val;
        //         }
        //         else
        //             dp[i][j] = 0;
        //     }
        // }

        // for (auto it : dp)
        // {
        //     for (auto i : it)
        //         cout << i << " ";
        //     cout << endl;
        // }

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int maxLen = 0; // Track the maximum length of the common substring

        solve(0, 0, str1, str2, dp, maxLen);

        return maxLen;
    }
};

int main()
{

    return 0;
}