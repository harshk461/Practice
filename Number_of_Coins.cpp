#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &coins, int target, vector<int> &dp)
    {
        if (target == 0)
            return 0;

        if (dp[target] != -1)
            return dp[target];

        int ans = INT_MAX;

        for (int i = 0; i < coins.size(); i++)
        {
            if (target - coins[i] >= 0)
            {
                int temp = solve(coins, target - coins[i], dp);
                if (temp != -1)
                    ans = min(ans, 1 + temp);
            }
        }

        return dp[target] = ans == INT_MAX ? -1 : ans;
    }

public:
    int minCoins(vector<int> &coins, int m, int v)
    {
        vector<int> dp(v + 1, -1);
        return solve(coins, v, dp);
    }
};

int main()
{

    return 0;
}