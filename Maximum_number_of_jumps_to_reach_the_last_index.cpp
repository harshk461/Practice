#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0]=0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] != -1 && abs(nums[i] - nums[j]) <= target)
                    dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return dp[n - 1];
    }
};

int main()
{
    vector<int> arr = {1, 3, 6, 4, 1, 2};
    Solution s;
    cout << s.maximumJumps(arr, 3);
    return 0;
}