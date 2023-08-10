#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};

int main()
{
    vector<int> arr1 = {2, 5, 1, 2, 5};
    vector<int> arr2 = {10, 5, 2, 1, 5, 2};
    Solution s;
    s.maxUncrossedLines(arr1, arr2);
    return 0;
}