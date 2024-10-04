#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, string s, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 1 + solve(i + 1, j, s, dp);
        for (int k = i + 1; k <= j; k++)
        {
            if (s[k] == s[i])
                // spiliting the string
                ans = min(ans, solve(i, k - 1, s, dp) + solve(k + 1, j, s, dp));
        }

        return dp[i][j] = ans;
    }

public:
    int strangePrinter(string s)
    {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, s, dp);
    }
};

int main()
{

    return 0;
}