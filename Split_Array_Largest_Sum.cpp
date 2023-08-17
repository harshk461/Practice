#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, vector<int> &nums, int k, vector<vector<int>> &dp)
    {
        if (k == 0 && index == nums.size())
            return 0;
        if (k == 0 || index == nums.size())
            return INT_MAX;

        if (dp[index][k] != -1)
            return dp[index][k];

        int n = nums.size();
        int ans = INT_MAX;
        int currSum = 0;
        for (int i = index; i < n; i++)
        {
            currSum += nums[i];
            int temp = solve(i + 1, nums, k - 1, dp);
            ans = min(ans, max(currSum, temp));
        }
        return dp[index][k] = ans;
    }

public:
    int splitArray(vector<int> &nums, int k)
    {
        vector<vector<int>> dp(nums.size() + 1, vector<int>(k + 1, -1));
        return solve(0, nums, k, dp);
    }
};

int main()
{
    Solution s;
    vector<int> arr = {7, 2, 5, 10, 8};
    s.splitArray(arr, 2);
    return 0;
}