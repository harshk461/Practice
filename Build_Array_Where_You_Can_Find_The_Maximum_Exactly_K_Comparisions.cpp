#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(int i, int n, int m, int k, vector<vector<vector<int>>> &dp)
    {
        if (n <= 0)
        {
            if (k == 0)
                return 1;
            return 0;
        }

        if (dp[i][n][k] != -1)
            return dp[i][n][k];

        int ans = 0;
        for (int j = 1; j <= m; j++)
        {
            if (j > i)
            {
                if (n >= 1 && k >= 1)
                {
                    ans = (ans + solve(j, n - 1, m, k - 1, dp)) % MOD;
                }
            }
            else
            {
                if (n >= 1)
                {
                    ans = (ans + solve(i, n - 1, m, k, dp)) % MOD;
                }
            }
        }

        return dp[i][n][k] = ans % MOD;
    }

public:
    int numOfArrays(int n, int m, int k)
    {
        vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        return solve(0, n, m, k, dp);
    }
};

int main()
{

    return 0;
}