#include <iostream>
using namespace std;

class Solution
{
private:
    long long solve(int index, int isEven, vector<int> &nums, int k, vector<vector<long long>> &dp)
    {
        if (i == nums.size())
            return isEven == 1 ? 0 : INT_MIN;

        if (dp[index][isEven] != -1)
            return dp[index][isEven];
        long long noXorDone = nums[index] + solve(index + 1, isEven, nums, k, dp);
        long long XorDone = (nums[index] ^ k) + solve(index + 1, isEven ^ 1, nums, k, dp);

        return dp[index][isEven] = max(XorDone, noXorDone);
    }

public:
    long long maximumValueSum(vector<int> &nums, int k, vector<vector<int>> &edges)
    {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return solve(0, 1, nums, k, dp);
    }
};

int main()
{

    return 0;
}