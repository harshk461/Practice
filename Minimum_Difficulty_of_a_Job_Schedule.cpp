#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int prev, int d, vector<int> &nums, vector<vector<vector<int>>> &dp)
    {
        if (d == 0)
            return 1e9;

        if (dp[index][prev][d] != -1)
            return dp[index][prev][d];

        if (index >= nums.size())
            return d == 1 ? nums[prev] : 1e9;
        int carry = solve(index + 1, nums[index] > nums[prev] ? index : prev, d, nums, dp);
        int finish = nums[prev] + solve(index + 1, index, d - 1, nums, dp);

        return dp[index][prev][d] = min(carry, finish);
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        if (d > jobDifficulty.size())
            return -1;

        int n = jobDifficulty.size();

        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(11, -1)));

        return solve(1, 0, d, jobDifficulty, dp);
    }
};

class Solution
{
private:
    int solve(vector<int> &nums, int index, int d, vector<vector<int>> &dp)
    {
        int n = nums.size();
        if (d == 1)
        {
            int maxDifficulty = nums[index];
            for (int i = index; i < n; i++)
                maxDifficulty = max(nums[i], maxDifficulty);

            return maxDifficulty;
        }

        if (dp[index][d] != -1)
            return dp[index][d];

        int maxD = nums[index];
        int finalRes = INT_MAX;

        for (int i = index; i <= n - d; i++)
        {
            maxD = max(maxD, nums[i]);
            int res = maxD + solve(nums, i + 1, d - 1, dp);
            finalRes = min(finalRes, res);
        }

        return dp[index][d] = finalRes;
    }

public:
    int minDifficulty(vector<int> &jobDifficulty, int d)
    {
        int n = jobDifficulty.size();
        if (d > n)
            return -1;

        vector<vector<int>> dp(301, vector<int>(11, -1));
        return solve(jobDifficulty, 0, d, dp);
    }
};

int main()
{

    return 0;
}