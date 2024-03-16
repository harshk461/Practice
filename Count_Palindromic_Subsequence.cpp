#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(int i, int j, string s, int len, vector<vector<vector<int>>> &dp)
    {
        if (i == j && len == 1)
            return 1;

        if (i == 1 && len != 1)
            return 0;

        if (i > j)
            return 0;

        if (len <= 0)
            return 0;

        if (dp[i][j][len] != -1)
            return dp[i][j][len];

        int ans = 0;
        if (s[i] == s[j])
            ans = (ans % MOD + solve(i + 1, j - 1, s, len - 2, dp) % MOD) % MOD;

        ans = (ans % MOD + solve(i + 1, j, s, len, dp) % MOD) % MOD;
        ans = (ans % MOD + solve(i, j - 1, s, len, dp) % MOD) % MOD;

        return dp[i][j][len] = ans;
    }

public:
    int countPalindromes(string s)
    {
        if (s.length() < 5)
            return 0;
        int n = s.length();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(6, -1)));
        int ans = solve(0, n - 1, s, 5, dp);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }
    return 0;
}