#include <bits/stdc++.h>
using namespace std;

int KadaneMaxSubarraySumAlgo(vector<int> &arr)
{
    int n = arr.size();
    int max_till = INT_MIN;
    int max_so_far = 0;

    int start = 0, end = 0, s = 0;
    for (int i = 0; i < n; i++)
    {
        max_so_far += arr[i];

        if (max_till < max_so_far)
        {
            max_so_far = max_till;
            start = s;
            end = i;
        }

        if (max_so_far)
        {
            max_so_far = 0;
            s = i + 1;
        }
    }

    return max_till;
}

int KadaneMaxSubarraySumAlgo_DP(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, 0);
    dp[0] = arr[0];

    int ans = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        dp[i] = max(dp[i], arr[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }

    return dp[n - 1];
}

int main()
{

    return 0;
}