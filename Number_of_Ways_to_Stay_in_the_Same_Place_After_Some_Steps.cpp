#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(int posn, int steps, int arrLen, vector<vector<int>> &dp)
    {
        if (posn < 0 || posn > arrLen - 1)
            return 0;
        if (posn > steps)
            return 0;

        if (steps == 0)
            return posn == 0;

        if (dp[posn][steps] != -1)
            return dp[posn][steps];

        int left = solve(posn - 1, steps - 1, arrLen, dp) % MOD;
        int right = solve(posn + 1, steps - 1, arrLen, dp) % MOD;
        int stay = solve(posn, steps - 1, arrLen, dp) % MOD;
        return dp[posn][steps] = (left + right + stay) % MOD
    }

public:
    int numWays(int steps, int arrLen)
    {
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return solve(0, steps, arrLen, dp);
    }
};

int main()
{

    return 0;
}