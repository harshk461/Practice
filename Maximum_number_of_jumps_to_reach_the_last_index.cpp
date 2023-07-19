#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumJumps(vector<int> &nums, int target)
    {
        // int n = nums.size();
        // vector<int> dp(n, -1);
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i + 1; j < n; j++)
        //     {
        //         if (abs(nums[j] - nums[i]) <= target)
        //         {
        //             dp[j] = max(dp[j], dp[i] + 1);
        //         }
        //     }
        // }
        // return dp[n - 1];

        int n = nums.size();
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(nums[j] - nums[i]) <= target)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        if (dp[n - 1] == INT_MAX)
            return -1;
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