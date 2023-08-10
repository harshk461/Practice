#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int endIndex, vector<int> &slices, int n)
    {
        if (n == 0 || index > endIndex)
            return 0;

        int take = slices[index] + solve(index + 2, endIndex, slices, n - 1);
        int notTake = 0 + solve(index + 1, endIndex, slices, n);
        return max(take, notTake);
    }

    int solveMem(int index, int endIndex, vector<int> &slices, int n, vector<vector<int>> &dp)
    {
        if (n == 0 || index > endIndex)
            return 0;

        if (dp[index][n] != -1)
            return dp[index][n];

        int take = slices[index] + solveMem(index + 2, endIndex, slices, n - 1, dp);
        int notTake = 0 + solveMem(index + 1, endIndex, slices, n, dp);
        return dp[index][n] = max(take, notTake);
    }

    int solveTab(vector<int> &slices)
    {
        int n = slices.size();
        vector<vector<int>> dp1(n + 2, vector<int>(n + 2, 0));
        vector<vector<int>> dp2(n + 2, vector<int>(n + 2, 0));

        for (int index = n - 2; index >= 0; index--)
        {
            for (int k = 1; k <= n / 3; k++)
            {
                int take = slices[index] + dp1[index + 1][k - 1];
                int notTake = 0 + dp1[index + 1][k];

                dp1[index][k] = max(take, notTake);
            }
        }
        int case1 = dp1[0][n / 2];

        for (int index = n - 1; index >= 1; index--)
        {
            for (int k = 1; k <= n / 3; k++)
            {
                int take = slices[index] + dp2[index + 1][k - 1];
                int notTake = 0 + dp2[index + 1][k];

                dp2[index][k] = max(take, notTake);
            }
        }
        int case2 = dp2[1][n / 3];

        return max(case1, case2);
    }

public:
    int maxSizeSlices(vector<int> &slices)
    {
        int k = slices.size();
        vector<vector<int>> dp(k, vector<int>(k, -1));
        int case1 = solveMem(0, k - 2, slices, k / 3, dp);
        int case2 = solveMem(1, k - 1, slices, k / 3, dp);

        return max(case1, case2);
    }
};

int main()
{

    return 0;
}