#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool isPalindrome(string s, int low, int high)
    {
        while (low < high)
        {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
        }

        return true;
    }

    int solve(string s, int i, int j, vector<vector<int>> &dp)
    {
        if (i >= j)
            return 0;

        if (isPalindrome(s, i, j) || i >= j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i; k <= j; k++)
            if (isPalindrome(s, i, k))
                ans = min(ans, 1 + solve(s, k + 1, j, dp));
        return dp[i][j] = ans;
    }

    int solveTab(string s)
    {
        int n = s.length();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                if (isPalindrome(s, i, j))
                    mini = min(mini, 1 + dp[j + 1]);
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }

    int solve2(int i, int n, string s, vector<int> &dp)
    {
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int mini = INT_MAX;
        for (int j = i; j < n; j++)
            if (isPalindrome(s, i, j))
                mini = min(mini, 1 + solve2(j + 1, n, s, dp));

        return dp[i] = mini;
    }

public:
    int minCut(string s)
    {
        int n = s.length();
        // vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        // return solve(s,0,s.length()-1,dp);
        return solveTab(s);
        // vector<int> dp(n,-1);
        // return solve2(0,n,s,dp)-1;
    }
};

int main()
{

    return 0;
}