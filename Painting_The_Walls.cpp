#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, vector<int> &cost, vector<int> &time, int remaining_time, vector<int> &dp)
    {
        if (remaining_time <= 0)
            return 0;

        if (index == cost.size())
            return 1e9;

        if (dp[index][remaining_time] != -1)
            return dp[index][remaining_time];

        int paint = cost[index] + solve(index + 1, cost, time, remaining_time - time[index] - 1, dp);
        int dontPaint = solve(index + 1, cost, time, remaining_time, dp);
        return dp[index][remaining_time] = min(paint, dontPaint);
    }

public:
    int paintWalls(vector<int> &cost, vector<int> &time)
    {
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, cost, time, n, dp);
    }
};

int main()
{

    return 0;
}