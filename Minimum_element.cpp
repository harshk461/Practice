#include <bits/stdc++.h>
using namespace std;

// TLE
int solve(vector<int> &nums, int x)
{
    // base case
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;
    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solve(nums, x - num[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

// using recursion and memoization
// TLE
int solveMem(vector<int> &nums, int x, vector<int> &dp)
{
    // base case
    if (x == 0)
        return 0;

    if (x < 0)
        return INT_MAX;

    // checking if value already exists
    if (dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        int ans = solve(nums, x - num[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }

    dp[x] = mini;
    return mini;
}

// Tabulation method
int solveTab(vector<int> &nums, int x)
{
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        // trying to solve every amount figure from 1 to x
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0 && dp[i - nums[j]] != INT_MAX)
            {
                dp[i] = min(dp[i], 1 + dp[i - nums[j]]);
            }
        }
    }
    if (dp[x] == INT_MAX)
        return -1;
    return dp[x];
}

int minimumElement(vector<int> &nums, int x)
{
    // int ans = solve(nums, x);
    // if (ans == INT_MAX)
    //     return -1;
    // return ans;

    vector<int> dp(x + 1, -1);
    int ans = solveMem(nums, x, dp);
    if (ans == INT_MAX)
        return -1;
    return ans;
}

int main()
{

    return 0;
}