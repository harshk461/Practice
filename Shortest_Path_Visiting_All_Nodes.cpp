#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dfs(vector<vector<int>> &nums, vector<vector<int>> &dp, int vis, int in)
    {
        if (vis == 0)
            return 0;
        if (dp[vis][in] == -1)
            return INT_MAX;
        if (dp[vis][in] > -1)
            return dp[vis][in];
        dp[vis][in] = -1;
        int k = vis;
        if (vis & (1 << in))
            k = vis ^ (1 << in);
        int sum = INT_MAX;
        for (int i = 0; i < nums[in].size(); ++i)
        {
            sum = min(sum, dfs(nums, dp, k, nums[in][i]));
        }
        if (sum == INT_MAX)
            sum--;
        return dp[vis][in] = sum + 1;
    }
    int shortestPathLength(vector<vector<int>> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(1 << n, vector<int>(n, -2));
        int vis = (1 << n) - 1;
        int re = INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            re = min(re, dfs(nums, dp, vis, i));
        }
        if (re == INT_MAX)
            re = 1;
        return re - 1;
    }
};
int main()
{

    return 0;
}