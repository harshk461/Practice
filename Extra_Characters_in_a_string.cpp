#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, string s, vector<string> &dictionary, vector<int> &dp)
    {
        int n = s.length();
        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index];
        int ans = n;

        for (auto w : dictionary)
        {
            int wLen = w.length();
            if (index + wLen <= n && s.substr(index, wLen) == w)
            {
                int extra = solve(index + wLen, s, dictionary, dp);
                ans = min(ans, extra);
            }
        }

        int noword = 1 + solve(index + 1, s, dictionary, dp);

        ans = min(ans, noword);

        return dp[index] = ans;
    }

public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.length();
        vector<int> dp(n, -1);
        return solve(0, s, dictionary, dp);
    }
};

int main()
{

    return 0;
}