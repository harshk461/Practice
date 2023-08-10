#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(int low, int high, int zero, int one)
    {
        int ans = 0;
        vector<int> dp(high + 1);
        dp[0] = 1;

        for (int i = 1; i <= high; i++)
        {
            if (i >= zero)
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if (i >= one)
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            if (i >= low)
                ans = (ans + dp[i]) % MOD;
        }

        return ans;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        return solve(low, high, zero, one);
    }
};

int main()
{

    return 0;
}