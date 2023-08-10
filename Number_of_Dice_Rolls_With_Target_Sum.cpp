#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long solve(int dices, int faces, int target)
    {
        // base case
        if (target < 0)
            return 0;

        if (dice == 0 && target != 0)
            return 0;

        if (target == 0 && dice != 0)
            return 0;

        if (dice == 0 && target == 0)
            return 1;
        long long ans = 0;
        for (int i = 1; i <= faces; i++)
            ans += solve(dices - 1, faces, target - i);
        return ans;
    }

    long long solveMem(int dices, int faces, int target, vector<vector<long long>> &dp)
    {
        // base case
        if (target < 0)
            return 0;

        if (dice == 0 && target != 0)
            return 0;

        if (target == 0 && dice != 0)
            return 0;

        if (dice == 0 && target == 0)
            return 1;

        if (dp[dice][target] != -1)
            return dp[dice][target];

        long long ans = 0;
        for (int i = 1; i <= faces; i++)
            ans += solveMem(dices - 1, faces, target - i, dp);

        return dp[dice][target] = ans;
    }

    long long solveTab(int dices, int faces, int target)
    {
        vector<vector<long long>> dp(dices + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;
        for (int d = 1; d <= dices; d++)
        {
            for (int t = 1; t <= target; t++)
            {
                long long ans = 0;
                for (int f = 1; f <= faces; f++)
                {
                    if (target - i >= 0)
                        ans += dp[dices - 1][t - f];
                }
                dp[dice][t] = ans;
            }
        }
        return dp[dices][target];
    }

public:
    long long noOfWays(int M, int N, int X)
    {
        vector<vector<long long>> dp(N + 1, vector<long long>(X + 1, -1));
    }
};

int main()
{

    return 0;
}