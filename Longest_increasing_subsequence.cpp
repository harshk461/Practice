#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC-O(N^2)
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        for (auto i : dp)
            cout << i << " ";
        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    vector<int> a = {10, 9, 2, 5, 3, 7, 101, 18};
    Solution s;
    s.lengthOfLIS(a);
    return 0;
}