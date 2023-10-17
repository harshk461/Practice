#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int start, int end, vector<int> &arr, int x, int count, vector<vector<int>> &dp)
    {
        if (x == 0)
            return count;
        if (start > end || x < 0)
            return INT_MAX;

        if (dp[start][end] != -1)
            return dp[start][end];

        int left = solve(start + 1, end, arr, x - arr[start], count + 1, dp);
        int right = solve(start, end - 1, arr, x - arr[end], count + 1, dp);
        return dp[start][end] = min(left, right);
    }

    int solve2(vector<int> &nums, int x)
    {
        int start = 0, end = 0;
        int maxLen = -1, currWindowSum = 0, total = 0;

        total = accumulate(nums.begin(), nums.end(), 0);

        while (end < nums.size())
        {
            currWindowSum += nums[end];
            while (currWindowSum > total - x && start <= end)
                currWindowSum -= nums[start++];
            if (currWindowSum == total - x)
                maxLen = max(maxLen, end - start + 1);
            end++;
        }
        return maxLen != -1 ? nums.size() - maxLen : -1;
    }

public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans = solve(0, n - 1, nums, x, 0, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};

int main()
{

    return 0;
}