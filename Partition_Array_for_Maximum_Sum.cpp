#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &arr, int k, vector<int> &dp, int start)
    {
        int N = arr.size();

        if (start >= N)
            return 0;

        if (dp[start] != -1)
            return dp[start];

        int currMax = 0, ans = 0;
        int end = min(N, start + k);
        for (int i = start; i < end; i++)
        {
            currMax = max(currMax, arr[i]);
            ans = max(ans, currMax * (i - start + 1) + maxSum(arr, k, dp, i + 1));
        }

        return dp[start] = ans;
    }

    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> dp(arr.size(), -1);
        return solve(arr, k, dp, 0);
    }
};

int main()
{

    return 0;
}