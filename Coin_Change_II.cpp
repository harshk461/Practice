#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> dp(amount + 1, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= amount; j++)
                if (j - coins[i] >= 0)
                    dp[i] = dp[j] + coins[i];
        }

        return dp[amount];
    }

public:
    int change(int amount, vector<int> &coins)
    {
    }
};

int main()
{

    return 0;
}