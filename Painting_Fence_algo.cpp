#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

int add(int a, int b)
{
    return (a % MOD * 1LL + b % MOD);
}

int mul(int a, int b)
{
    return (a % MOD * b % MOD);
}

// Recursion TLE
int solve(int n, int k)
{
    // base case
    if (n == 1)
        return k;
    if (n == 2)
        returm add(k, mul(k, k - 1));

    int ans = add(mul(solve(n - 2, k), k - 1), mul(solve(n - 1, k), k - 1));
    return ans;
}

// recursion and memoization
int solve(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
        return k;
    if (n == 2)
        returm add(k, mul(k, k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(mul(solve(n - 2, k), dp, k - 1), mul(solve(n - 1, k, dp), k - 1));
    return dp[n];
}

// using tabulation
int solveTab(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));
    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(mul(dp[i-2], dp, k - 1), mul(dp[i-1], 1, k, dp), k - 1));
    }
    return dp[n];
}

int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1) int ans = solveMem(n, k, dp);
    return ans;
}

int main()
{

    return 0;
}