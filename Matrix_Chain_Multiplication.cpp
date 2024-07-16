#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int start, int end, int arr[], vector<vector<int>> &dp)
    {
        if (start == end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int ans = INT_MAX;
        int count = 0;

        for (int i = start; i < end; i++)
        {
            count = solve(start, i, arr, dp) + solve(i + 1, end, arr, dp) + arr[start - 1] * arr[i] * arr[end];

            ans = min(ans, count);
        }

        return dp[start][end] = ans;
    }

public:
    int matrixMultiplication(int n, int arr[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, n - 1, arr, dp);
    }
};

int main()
{

    return 0;
}