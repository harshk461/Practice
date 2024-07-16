#include <iostream>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int solve(int i, int n, int absent, int late, vector<vector<vector<int>>> &dp)
    {
        if (absent >= 2 || late >= 3)
            return 0;

        if (i == n)
            return 1;

        if (dp[i][absent][late] != -1)
            return dp[i][absent][late];

        int Present = solve(i + 1, n, absent, late,dp);
        int Absent = solve(i + 1, n, absent + 1, late,dp);
        int Late = solve(i + 1, n, absent, late + 1,dp);

        return dp[i][absent][late] = (Present % MOD + Absent % MOD + Late % MOD) % MOD;
    }

public:
    int checkRecord(int n)
    {
        int absent = 0;
        int late = 0;
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, n, absent, late, dp);
    }
};

int main()
{

    return 0;
}