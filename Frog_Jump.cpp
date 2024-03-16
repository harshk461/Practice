#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int left = solve(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);

    int right = INT_MAX;
    if (n > 1)
        right = solve(n - 2, heights, dp) + abs(heights[n - 2] - heights[n]);

    return dp[n] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n + 1, -1);
    return solve(n - 1, heights, dp);
}

int main()
{

    return 0;
}