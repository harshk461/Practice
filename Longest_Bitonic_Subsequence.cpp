#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx, mmx, sse2, sse3, sse4")

// static const int disableSync = [](void) noexcept -> int
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return 0;
// }();

class Solution
{
private:
    vector<int> LongestIncreasingSubsequence(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[prev]);
            }
        }

        return dp;
    }

    vector<int> LongestDecreasingSubsequence(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = n - 2; i >= 0; i--)
        {
            for (int next = i + 1; next < n; next++)
            {
                if (nums[next] < nums[i])
                    dp[i] = max(dp[i], 1 + dp[next]);
            }
        }

        return dp;
    }

public:
    int LongestBitonicSequence(int n, vector<int> &nums)
    {
        vector<int> inc = LongestIncreasingSubsequence(nums);
        vector<int> dec = LongestDecreasingSubsequence(nums);

        // for (auto it : inc)
        //     cout << it << " ";
        // cout << endl;
        // for (auto it : dec)
        //     cout << it << " ";
        // cout << endl;

        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
            if (inc[i] > 1 && dec[i] > 1)
                ans = max(ans, inc[i] + dec[i] - 1);
        return ans;
    }
};

int main()
{

    Solution s;
    vector<int> arr = {5, 7, 9};
    cout << s.LongestBitonicSequence(3, arr);
    return 0;
}