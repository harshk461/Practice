#include <bits/stdc++.h>
using namespace std;

// Recursion TLE
int solve(vector<int> &nums, int tar)
{
    // base case
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += solve(nums, tar - nums[i]);
    }
    return sum;
}

// using Recursion and memoization
int solveMem(vector<int> &nums, int tar, vector<int> &dp)
{
    // base case
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    if (dp[tar] != -1)
        return dp[tar];
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += solveMem(nums, tar - nums[i], dp);
    }
    dp[tar] = sum;
    return dp[tar];
}

// using tabulation
int solveMem(vector<int> &nums, int tar)
{
    vector<int> dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= tar; i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i - nums[j] >= 0)
                dp[i] += dp[tar - nums[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int> &nums, int tar)
{
    // memo
    vector<int> dp(tar + 1, -1);
}

int main()
{

    return 0;
}