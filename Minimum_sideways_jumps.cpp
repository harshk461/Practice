#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &obstacles, int currLane, int currPos)
    {
        int n = obstacles.size() - 1;
        if (currPos == n)
            return 0;

        if (obstacles[currPos + 1] != currLane)
            return solve(obstacles, currLane, currPos + 1);

        else
        {
            // side ways
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
                if (currLane != i && obstacles[currPos] != i)
                    ans = min(ans, 1 + solve(obstacles, i, currPos));
            return ans;
        }
    }

    int solveMem(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp)
    {
        int n = obstacles.size() - 1;
        if (currPos == n)
            return 0;

        if (obstacles[currPos + 1] != currLane)
            return solveMem(obstacles, currLane, currPos + 1, dp);

        if (dp[currLane][currPos] != -1)
            return dp[currLane][currPos];

        else
        {
            // side ways
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
                if (currLane != i && obstacles[currPos] != i)
                    ans = min(ans, 1 + solveMem(obstacles, i, currPos, dp));
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }

    int solveTab(vector<int> &obstacles)
    {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(4, vector<int>(n, 1e9));

        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                    dp[currLane][currPos] = dp[currLane][currPos + 1];
                else
                {
                    // sideways jump
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        if (currLane != i && obstacles[currPos] != i)
                            ans = min(ans, 1 + dp[i][currPos + 1]);
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
        return min({dp[2][0], 1 + dp[1][0], 1 + dp[3][0]});
    }

public:
    int minSideJumps(vector<int> &obstacles)
    {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        return solveMem(obstacles, 2, 0, dp);
    }
};

int main()
{

    return 0;
}