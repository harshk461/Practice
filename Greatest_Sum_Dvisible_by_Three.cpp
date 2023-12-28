#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int currRem, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i >= nums.size())
        {
            if (currRem == 0)
                return 0;
            return INT_MIN;
        }

        if (dp[i][currRem] != -1)
            return dp[i][currRem];

        int include = nums[i] + solve(i + 1, (nums[i] + currRem) % 3, nums, dp);
        int exclude = solve(i + 1, currRem, nums, dp);

        return dp[i][currRem] = max(include, exclude);
    }

public:
    int maxSumDivThree(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(0, 0, nums, dp);
    }
};

int main()
{

    return 0;
}