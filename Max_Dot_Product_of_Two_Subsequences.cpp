#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int i, int j, vector<int> &nums1, vector<int> &nums2, vector<vector<int>> &dp)
    {
        if (i == nums1.size() || j == nums2.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = nums1[i] * nums2[j] + solve(i + 1, j + 1, nums1, nums2, dp);
        ans = max(ans, max(solve(i + 1, j, nums1, nums2, dp), solve(i, j + 1, nums1, nums2, dp)));
        return dp[i][j] = ans;
    }

public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        int m = nums2.size();

        int max1 = -1001;
        int min1 = 1001;

        int max2 = -1001;
        int min2 = 1001;

        for (int i = 0; i < n; i++)
        {
            max1 = max(max1, nums1[i]);
            min1 = min(min1, nums1[i]);
        }

        for (int i = 0; i < m; i++)
        {
            max2 = max(max2, nums2[i]);
            min2 = min(min2, nums2[i]);
        }

        if ((min1 < 0 && max1 < 0) && (max2 > 0 && min2 > 0))
            return max1 * min2;
        else if (min1 > 0 || max2 < 0)
            return min1 * max2;

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return max(solve(0, 0, nums1, nums2, dp), max(max2 * min1, max1 * min2));
    }
};

int main()
{

    return 0;
}