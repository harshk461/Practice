#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, vector<int> &nums, vector<int> &dp)
    {
        if (nums.size() < 3)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int n = nums.size();
        int ans = 0;
        if (index + 2 < n && (nums[index + 1] - nums[index]) == (nums[index + 2] - nums[index + 1]))
            ans = 1 + solve(index + 1, nums, dp);

        return dp[index] = ans;
    }

public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int ans = 0;
        vector<int> dp(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++)
            ans += solve(i, nums, dp);
        return ans;
    }
};

int main()
{

    return 0;
}