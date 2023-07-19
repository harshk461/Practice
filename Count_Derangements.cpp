#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// TLE
long long int countDerangement(int n)
{
    // base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    int ans = (((n - 1) % MOD) + ((countDerangement(n - 1) % MOD) + (countDerangement(n - 2) % MOD)) % MOD);
    return ans;
}

// recursion and memoization

long long int countDerangement2(int n)
{
    vector<long long int> dp(n + 1, -1);
}

int solveMem(int n, vector<long long int> &dp)
{
    // base case
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = (((n - 1) % MOD) * ((solveMem(n - 1, dp) % MOD) + (solveMem(n - 2, dp)) % MOD)) % MOD;
    return dp[n];
}

// using tabulation
long long solveTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 2; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;
        long long int sum = (first + second) % MOD;
        long long int ans = ((n - 1) * sum) % MOD;
        dp[i] = ans;
    }
    return dp[n];
}

int main()
{

    return 0;
}