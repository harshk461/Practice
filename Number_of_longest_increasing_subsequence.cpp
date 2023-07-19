#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumberOfLIS(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if (arr[prev] < arr[i] && 1 + dp[prev] == dp[i])
                    // increase count
                    cnt[i] += cnt[prev];
            }
            maxi = max(maxi, dp[i]);
        }

        int nos = 0;
        for (int i = 0; i < n; i++)

            if (dp[i] == maxi)
                nos += cnt[i];
        return nos;
    }
};

int main()
{

    return 0;
}