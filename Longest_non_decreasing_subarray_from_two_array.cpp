#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2)
    {
        if (i == nums1.size() || j == nums2.size())
            return 0;

        if (nums1[i] < nums2[j])
            return 1 + solve(i + 1, j + 1, nums1, nums2);
        else
            return max(solve(i + 1, j, nums1, nums2), solve(i, j + 1, nums1, nums2));
    }

    int f(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
        int ans = 1;

        // 0->nums1
        // 1->nums2
        for (int i = 1; i < n; i++)
        {
            if (nums1[i] >= nums[i - 1])
                dp[i][0] = max(dp[i][0], dp[i - 1][0] + 1);
            if (nums1[i] >= nums2[i - 1])
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
            if (nums2[i] >= nums1[i - 1])
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
            if (nums2[i] >= nums2[i - 1])
                dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
            ans = max(ans, max(dp[i][0], dp[i][1]));
        }
        return ans;
    }

public:
    int longestSub(vector<int> &arr)
    {
        int maxi = 0, count = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i + 1] < arr[i])
            {
                count = 0;
            }
            else
            {
                count++;
                if (count > maxi)
                    maxi = count;
            }
        }
        return maxi + 1;
    }
    int maxNonDecreasingLength(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int maxi = 0;
        int curr = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums1[i] >= nums1[i - 1] || nums2[i] >= nums1[i - 1])
            {
                curr++;
            }
            else
            {
                maxi = max(maxi, curr);
                curr = 1;
            }
        }
        maxi = max(maxi, curr);
        return maxi;
    }
};

int main()
{
    Solution s;
    vector<int> a1 = {4, 2};
    vector<int> a2 = {10, 4};
    cout << s.maxNonDecreasingLength(a1, a2);
    return 0;
}