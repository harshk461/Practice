#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int brute(vector<int> &nums)
    {
        int ans = INT_MAX;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                for (int k = j + 1; k < n; k++)
                    if (nums[i] < nums[j] && nums[k] < nums[j])
                        ans = min(ans, nums[i] + nums[j] + nums[k]);

        return ans == INT_MAX ? -1 : ans;
    }

    int solve(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MAX;

        vector<int> prefix_min(n, INT_MAX);
        vector<int> suffix_min(n, INT_MAX);

        prefix_min[0] = nums[0];
        suffix_min[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
            prefix_min[i] = min(nums[i], prefix_min[i - 1]);

        for (int i = n - 2; i >= 0; i--)
            suffix_min[i] = min(nums[i], suffix_min[i + 1]);

        for (int i = 0; i < n; i++)
            if (prefix_min[i] < nums[i] && suffix_min[i] < nums[i])
                ans = min(ans, prefix_min[i] + nums[i] + suffix_min[i]);

        return ans == INT_MAX ? -1 : ans;
    }

public:
    int minimumSum(vector<int> &nums)
    {
        return solve(nums);
    }
};

int main()
{

    vector<int> arr = {8, 6, 1, 5, 3};
    Solution s;
    s.minimumSum(arr);
    return 0;
}