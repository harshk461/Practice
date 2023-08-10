#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(int i, int j, string &s, string &p)
    {
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
                if (p[k] != '*')
                    return false;
            return true;
        }

        if (s[i] == p[j] || p[j] == '?')
            return solve(i - 1, j - 1, s, p);
        else if (p[j] == '*')
            return solve(i - 1, j, s, p) || solve(i, j - 1, s, p);
        else
            return false;
    }

    bool solveMem(int i, int j, string &s, string &p, vector<vector<bool>> &dp)
    {
        if (i < 0 && j < 0)
            return true;
        if (i >= 0 && j < 0)
            return false;

        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
                if (p[k] != '*')
                    return false;
            return true;
        }

        if (dp[i][j] != false)
            return dp[i][j];

        if (s[i] == p[j] || p[j] == '?')
            return dp[i][j] = solveMem(i - 1, j - 1, s, p, dp);
        else if (p[j] == '*')
            return dp[i][j] = solveMem(i - 1, j, s, p, dp) || solveMem(i, j - 1, s, p, dp);
        else
            return dp[i][j] = false;
    }

    bool solveTab(string s, string p)
    {
        // vector<vector<int>> dp(s.length() + 1, vector<int>(p.length(), 0));
        vector<int> curr(p.length() + 1, 0);
        vector<int> prev(p.length() + 1, 0);
        prev[0] = true;

        for (int j = 1; j <= p.length(); j++)
        {
            bool flag = true;
            for (int k = 1; k <= j; k++)
                if (p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            prev[j] = flag;
        }

        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = 1; j <= p.length(); j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    curr[j] = prev[j - 1];
                else if (p[j - 1] == '*')
                    curr[j] = prev[j] || curr[j - 1];
                else
                    curr[j] = false;
            }
            prev = curr;
        }

        return prev[p.length()];
    }

public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.length(), vector<bool>(p.length(), false));
        return solveMem(s.length() - 1, p.length() - 1, s, p, dp);
    }
};

int main()
{

    return 0;
}