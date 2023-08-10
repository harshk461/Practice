#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int n, vector<int> &dp)
    {
        // root of both number is same
        if (sqrt(n) - floor(sqrt(n)) == 0)
            return 1;

        if (n <= 3)
            return n;
        if (dp[n] != -1)
            return dp[n];
        int ans = n;
        for (int i = 1; i <= n; i++)
        {
            int temp = i * i;
            if (temp > n)
                break;
            else
                ans = min(ans, 1 + solve(n - temp, dp));
        }
        return dp[n] = ans;
    }

    int solveTab(int n)
    {
        vector<int> dp(n + 1, n);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
        return dp[n];
    }

public:
    int numSquares(int n)
    {
        return solve(n);
    }
};

int main()
{

    return 0;
}