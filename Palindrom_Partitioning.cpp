#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
        bool isPalindrome(int i, int j, string s)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }

    int solve(int start, int end, string s, vector<vector<int>> &dp)
    {
        if (start >= end || isPalindrome(start, end, s))
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        int count = 0;

        for (int i = start; i < end; i++)
        {
            count = solve(start, i, s, dp) + solve(i + 1, end, s, dp) + 1;
            ans = min(ans, count);
        }
        return dp[start][end] = ans;
    }

public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, n - 1, str, dp);
    }
};

int main()
{

    return 0;
}