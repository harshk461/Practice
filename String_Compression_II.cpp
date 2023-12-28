#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int k, string &s, vector<vector<int>> &dp)
    {
        int n = s.length();
        if (n - index == k)
            return 0;

        if (dp[index][k] != -1)
            return dp[index][k];

        int ans = k ? solve(index + 1, k - 1, s, dp) : 1e5;

        int cnt = 1;
        int removeCnt = 0;

        for (int i = index + 1; i <= n; i++)
        {
            int curr = 1 + ((cnt > 99) ? 3 : (cnt > 9) ? 2
                                         : (cnt > 1)   ? 1
                                                       : 0) +
                       solve(i, k - removeCnt, s, dp);
            ans = min(ans, curr);
            if (i < n && s[i] == s[index])
                cnt++;

            else if (k - removeCnt <= 0)
                break;
            else
                removeCnt++;
        }

        return dp[index][k] = ans;
    }

public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));
        return solve(0, k, s, dp);
    }
};

int main()
{
    return 0;
}