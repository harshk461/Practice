#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int p, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (p == 0)
            return INT_MIN;

        if (index >= nums.size() - 1)
            return 1e9;

        if (dp[index][p] != -1)
            return dp[index][p];

        int ans = INT_MAX;
        // choose the index
        int diff = nums[index + 1] - nums[index];
        ans = min(ans, max(diff, solve(index + 2, p - 1, nums, dp)));

        // don't choose
        ans = min(ans, solve(index + 1, p, nums, dp));

        return dp[index][p] = ans;
    }

    int solveTab(vector<int> &nums, int p)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(p + 1, 0));

        for (int i = 0; i < n; i++)
            dp[i][0] = INT_MIN;

        dp[0] = 0;
        dp[1] = abs(nums[1] - nums[0]);

        for (int index = 2; index < n; index++)
        {
            int ans = INT_MAX;
            // choose the index
            int diff = nums[index + 1] - nums[index];
            ans = min(ans, max(diff, dp[index + 2][p - 1]));

            // don't choose
            ans = min(ans, dp[index + 1][p]);

            dp[index][p] = ans;
        }
    }

    bool isPossible(vector<int> &nums, int p, int mid)
    {
        int i = 0;
        while (i < nums.size() - 1)
        {
            if (abs(nums[i] - nums[i + 1] <= mid))
                p--, i += 2;
            else
                i++;
        }

        return p <= 0 ? 1 : 0;
    }

    int solveBS(vector<int> &nums, int p)
    {
        int start = 0;
        int end = nums[nums.size() - 1];

        int ans = 0;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (isPossible(nums, p, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }

        return ans;
    }

public:
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        if (p == 0)
            return 0;

        vector<vector<int>> dp(nums.size(), vector<int>(p, -1));
        return solve(0, p, nums, dp);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {10, 1, 2, 7, 1, 3};
    s.minimizeMax(arr, 2);
    return 0;
}