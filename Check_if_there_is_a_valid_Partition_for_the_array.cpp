#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int index, vector<int> &nums, vector<int> &dp)
    {
        int n = nums.size();
        if (index == n)
            return true;

        if (dp[index] != -1)
            return dp[index];

        if (index + 1 < n && nums[index] == nums[index + 1])
            if (solve(index + 2, nums, dp))
                return dp[index] = true;

        if (index + 2 < n && nums[index] == nums[index + 1] && nums[index + 1] == nums[index + 2])
            if (solve(index + 3, nums, dp))
                return dp[index] = true;

        if (index + 2 < n && nums[index] + 1 == nums[index + 1] && nums[index] + 2 == nums[index + 2])
            if (solve(index + 3, nums, dp))
                return dp[index] = true;

        return dp[index] = false;
    }

public:
    bool validPartition(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        return solve(0, nums, dp);
    }
};

int main()
{

    return 0;
}