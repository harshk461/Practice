#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(int n, int k, vector<vector<int>> &dp)
    {
        if (k <= 0)
            return k == 0;

        if (dp[n][k] != -1)
            return dp[n][k];

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += solve(n - 1, k - i, dp);
            ans %= MOD;
        }
        return dp[n][k] = ans;
    }

public:
    int kInversePairs(int n, int k)
    {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(n, k, dp);
    }
};

int main()
{

    return 0;
}