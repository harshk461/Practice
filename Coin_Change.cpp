#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int x, vector<int> &nums)
    {
        if (x == 0)
            return 0;

        int ans = INT_MAX;
        for (int j = 0; j < nums.size(); j++)
        {
            if (x - nums[j] >= 0)
            {
                int sub = solve(x - nums[j], nums);
                if (sub != -1)
                    ans = min(ans, 1 + sub);
            }
        }

        return (ans == INT_MAX) ? -1 : ans;
    }

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

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = solveTab(coins, amount);
        if (ans == INT_MAX)
            return -1;
        return ans;
    }
};

int main()

{

    return 0;
}