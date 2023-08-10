#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(string &s)
    {
        int n = s.length();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        if (s[0] == '0')
            return 0;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = 0;
            if (s[i - 1] > '0')
                dp[i] = dp[i - 1];
            if (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7')
                dp[i] += dp[i - 2];
        }

        return dp[n];
    }

public:
    int numDecodings(string s)
    {
        return solve(s);
    }
};

int main()
{

    return 0;
}