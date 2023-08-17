#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve2(int index, bool flag, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (dp[index][flag] != -1)
            return dp[index][flag];

        int maxi = 0;
        for (int i = index + 1; i < nums.size(); i++)
            if ((flag && nums[i] > nums[index]) || (!flag && nums[i] < nums[index]))
                maxi = max(maxi, 1 + solve2(i, !flag, nums, dp));
        return dp[index][flag] = maxi;
    }

    int solveOPT(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 2)
            return n;
        int i = 1;
        vector<int> up(n, 0);
        vector<int> down(n, 0);
        up[0] = down[0] = 1;
        while (i < n)
        {
            if (nums[i] > nums[i - 1])
            {
                up[i] = 1 + down[i - 1];
                down[i] = down[i - 1];
            }
            if (nums[i] < nums[i - 1])
            {
                down[i] = 1 + up[i - 1];
                up[i] = up[i - 1];
            }
            if (nums[i] == nums[i - 1])
            {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
            i++;
        }
        return max(up[n - 1], down[n - 1]);
    }

public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(2, -1));
        return 1 + max(solve2(0, 0, nums), solve2(0, 1, nums, dp));
    }
};

int main()
{

    return 0;
}