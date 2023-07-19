#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &arr, int i, int j)
    {
        if (i + 1 == j)
            return 0;

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
            ans = min(ans, arr[i] * arr[j] * arr[k] + solve(arr, i, k) + solve(arr, k, j));
        return ans;
    }

    int solveMem(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
    {
        if (i + 1 == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
            ans = min(ans, arr[i] * arr[j] * arr[k] + solveMem(arr, i, k, dp) + solveMem(arr, k, j, dp));
        dp[i][j] = ans;
        return dp[i][j];
    }

    int solveTab(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                    ans = min(ans, arr[i] * arr[j] * arr[k] + dp[i][k] + dp[k][j]);
                dp[i][j] = ans;
            }
        }
        return dp[0][n - 1];
    }

public:
    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solveMem(values, 0, n - 1, dp);
    }
};

int main()
{

    return 0;
}