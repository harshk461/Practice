#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int prev, int arr[], int n, vector<vector<int>> &dp)
    {
        if (index >= n)
            return 0;

        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int ans = 0;
        // take
        if (prev == -1 || nums[index] > nums[prev])
            ans = max(ans, arr[index] + solve(index + 1, index, arr, n, dp));

        // not take
        ans = max(ans, solve(index + 1, prev, arr, n, dp));

        return dp[index][prev + 1] = ans;
    }

public:
    int maxSumIS(int arr[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(0, -1, arr, n, dp);
    }
};

int main()
{

    return 0;
}