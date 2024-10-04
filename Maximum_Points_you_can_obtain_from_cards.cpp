#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    int recursive(int i, int j, vector<int> &arr, int k, vector<vector<vector<int>>> &dp)
    {
        if (k == 0)
            return 0;

        if (i > j)
            return 0;

        if (dp[i][j][k] != -1)
            return dp[i][j][k];

        int takeFirst = arr[i] + recursive(i + 1, j, arr, k - 1, dp);
        int takeLast = arr[j] + recursive(i, j - 1, arr, k - 1, dp);

        return dp[i][j][k] = max(takeFirst, takeLast);
    }

    int smallestSumSubarray(vector<int> &arr, int k)
    {
        int n = arr.size();
        int window = n - k;

        int curr = 0;
        for (int i = 0; i < window; i++)
            curr += arr[i];
        int ans = curr;
        for (int i = window; i < n; i++)
        {
            curr += arr[i] - arr[i - window];
            ans = min(ans, curr);
        }

        return ans;
    }

public:
    int maxScore(vector<int> &arr, int k)
    {
        // int n = cardPoints.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        // return recursive(0, n - 1, cardPoints, k,dp);

        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        int smallest_sum = smallestSumSubarray(arr, k);

        return total_sum - smallest_sum;
    }
};

int main()
{

    return 0;
}