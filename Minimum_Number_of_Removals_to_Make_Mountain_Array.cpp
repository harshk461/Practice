#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMountainRemovals(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);

        // left LIS
        for (int i = 0; i < n; i++)
            // check each element from 0 to i that it is less than nums[i]
            for (int j = 0; j < i; j++)
                if (nums[i] > nums[j] && 1 + dp1[j] > dp1[i])
                    dp1[i] = 1 + dp1[j];

        // right LIS
        for (int i = n - 1; i >= 0; i--)
            for (int j = i + 1; j < n; j++)
                if (nums[i] > nums[j] && 1 + dp2[j] > dp2[i])
                    dp2[i] = 1 + dp2[j];

        int ans = 0;

        for (int i = 1; i < n - 1; i++)
            if (dp1[i] > 1 && dp2[i] > 1)
                ans = max(ans, (dp1[i] + dp2[i] - 1));

        return n - ans;
    }
};

class Solution
{
private:
    int lisFromBack(int i, int pre, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == nums.size())
            return 0;

        if (dp[i][pre] != -1)
            return dp[i][pre];

        if (nums[i] < nums[pre])
            return dp[i][pre] = max(1 + lisFromBack(i + 1, i, nums, dp), lisFromBack(i + 1, pre, nums, dp));
        else
            return dp[i][pre] = lisFromBack(i + 1, pre, nums, dp);
    }
    int lis(int i, int pre, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i == -1)
            return 0;

        if (dp[i][pre] != -1)
            return dp[i][pre];

        if (nums[i] < nums[pre])
            return dp[i][pre] = max(1 + lis(i - 1, i, nums, dp), lis(i - 1, pre, nums, dp));

        return dp[i][pre] = lis(i - 1, pre, nums, dp);
    }

public:
    int minimumMountainRemovals(vector<int> &nums)
    {

        int ans = INT_MIN;
        int n = nums.size();
        vector<vector<int>> dp1(n, vector<int>(n, -1));
        vector<vector<int>> dp2(n, vector<int>(n, -1));

        for (int i = 1; i < n - 1; i++)
        {
            int right = lisFromBack(i + 1, i, nums, dp1);

            if (right == 0)
                continue;

            int left = lis(i - 1, i, nums, dp2);

            if (left == 0)
                continue;

            ans = max(ans, left + right + 1);
        }

        return n - ans;
    }
};

int main()
{

    return 0;
}