#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, string s, string p, vector<vector<bool>> &dp)
    {
        int n = s.length();
        int m = p.length();
        if (i >= n && j >= m)
            return true;
        if (j >= m)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (i >= n)
        {
            if (p[j + 1] == '*')
                return dp[i][j] = solve(i, j + 2, s, p, dp);
            return false;
        }

        if (j + 1 < m && p[j + 1] == '*')
            if (p[j] == '.' || p[j] == s[i])
                return dp[i][j] = solve(i + 1, j, s, p, dp) || solve(i, j + 2, s, p, dp);
            else
                return dp[i][j] = solve(i, j + 2, s, p, dp);

        else if (p[j] == '.' || s[i] == p[j])
            return dp[i][j] = solve(i + 1, j + 1, s, p, dp);

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p)
    {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, s, p, dp);
    }
};

int main()
{

    return 0;
}