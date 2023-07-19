#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((-1 * target) <= (nums[j] - nums[i]) ||
                    nums[j] - nums[i] <= target)
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
        }
        return dp[n];
    }
};

int main()
{

    return 0;
}