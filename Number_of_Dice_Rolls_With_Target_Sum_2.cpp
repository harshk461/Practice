#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    long long solve(int num_of_dice, int faces, int target, vector<vector<int>> &dp)
    {
        if (target < 0)
            return 0;

        if (num_of_dice == 0 && target != 0)
            return 0;

        // we have to use all dices
        if (num_of_dice != 0 && target == 0)
            return 0;

        if (target == 0 && num_of_dice == 0)
            return 1;

        if (dp[num_of_dice][target] != -1)
            return dp[num_of_dice][target];

        long long ans = 0;
        for (int i = 1; i <= faces; i++)
            ans += solve(num_of_dice - 1, faces, target - i, dp) % MOD;
        return dp[num_of_dice][target] = ans % MOD;
    }

public:
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(n, k, target, dp);
    }
};

int main()
{

    return 0;
}