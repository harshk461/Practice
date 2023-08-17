#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    unordered_map<int, int> map;
    int solve(int n, vector<int> &dp)
    {
        if (n <= 0)
            return 0;

        if (n == 1)
            return 1;

        if (dp[n] != -1)
            return dp[n];
        int r1 = 1 + n % 2 + solve(n / 2);
        int r2 = 1 + n % 3 + solve(n / 3);
        return dp[n] = min(r1, r2);
    }

    int solveMAP(int n)
    {
        if (n <= 1)
            return n;

        if (auto it = map.find(n) != map.cend())
            return map[n];

        return map[n] = 1 + min(solve(n / 2) + n % 2 + solve(n / 3) + n % 3);
    }

    int solve2(int n)
    {
        if (n <= 0)
            return 0;
        if (n == 1)
            return 1;

        int res = INT_MAX;
        if (n % 2 == 0 && n % 3 == 0)
            return 1 + min(solve2(n - 1), min(solve2(n / 2), solve2(n / 3)));
        else if (n % 2 == 0)
            return 1 + min(solve2(n - 1), solve2(n / 2));
        else if (n % 3 == 0)
            return 1 + min(solve2(n - 1), solve2(n / 3));
        else
            return 1 + solve2(n - 1);
    }

    int solveTab(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0 && i % 3 == 0)
                dp[i] = min(dp[i - 1], min(dp[i / 2], dp[i / 3]));
            else if (i % 2 == 0)
                dp[i] = min(dp[i - 1], dp[i / 2]);
            else if (i % 3 == 0)
                dp[i] = min(dp[i - 1], dp[i / 3]);
            else
                dp[i] = dp[i - 1];
        }

        return dp[n];
    }

public:
    int minDays(int n)
    {
        vector<int> dp(n, -1) return solve(n, dp);
    }
};

int main()
{

    return 0;
}