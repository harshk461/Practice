#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        int ans += 2 * solve(i - 1) + solve(i - 3);

        return ans;
    }

    int solve(int n, vector<int> &dp)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        if (dp[n] != -1)
            return dp[n];

        int ans = 0;
        ans += (2 * solve(n - 1, dp)) % MOD + solve(n - 3, dp) % MOD;

        return dp[n] = ans % MOD;
    }

    int solveTab(int n)
    {
        vector<int> dp(n + 5);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++)
            dp[i] += 2 * dp[i - 1] + dp[i - 3];

        return dp[n];
    }

public:
    int numTilings(int n)
    {
        return solve(n);
    }
};

int main()
{

    return 0;
}