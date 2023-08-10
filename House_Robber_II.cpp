#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<int> &nums, int l, int r)
    {
        int include = 0;
        int exclude = 0;
        int temp;

        for (int i = l; i <= r; i++)
        {
            temp = max(include, exclude);
            include = exclude + nums[i];
            exclude = temp;
        }
        return max(include, exclude);
    }

    int solve2(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        // dp array
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp.back();
    }

public:
    int rob(vector<int> &nums)
    {
        // vector<int> n1(nums.begin(), nums.end() - 1);
        // vector<int> n2(nums.begin() + 1, nums.end());

        // return max(solve2(n1), solve2(n2));

        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        return max(solve(nums, 0, nums.size() - 2), solve(nums, 1, nums.size() - 1));
    }
};

int main()
{

    return 0;
}