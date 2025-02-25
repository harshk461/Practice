#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
    // Helper function to calculate the maximum sum of `cnt` subarrays of length `k` starting at index `ind`.
    int findIfPos(int ind, vector<int> &preSum, int cnt, int k, int n, vector<vector<int>> &dp)
    {
        // Base case: if no subarrays left to select, return 0 as the sum.
        if (cnt == 0)
            return 0;

        // If the current index exceeds the valid range for selecting a subarray of length `k`, return a very small value.
        if (ind + k > n)
            return -1e9 - 9;

        // If the result is already computed, return it from the memoization table.
        if (dp[ind][cnt] != -1)
            return dp[ind][cnt];

        // Option 1: Take the current subarray and recursively calculate the result for remaining subarrays.
        int take = preSum[ind + k] - preSum[ind] + findIfPos(ind + k, preSum, cnt - 1, k, n, dp);

        // Option 2: Skip the current index and move to the next index.
        int notTake = findIfPos(ind + 1, preSum, cnt, k, n, dp);

        // Store the maximum of the two options in the memoization table and return it.
        return dp[ind][cnt] = max(take, notTake);
    }

    // Helper function to backtrack and find the starting indices of the selected subarrays.
    void findIdx(int ind, vector<int> &preSum, int k, int cnt, int n, vector<int> &result, vector<vector<int>> &dp)
    {
        // Base case: if no subarrays left to select, stop recursion.
        if (cnt == 0)
            return;

        // If the current index exceeds the valid range for selecting a subarray of length `k`, stop recursion.
        if (ind + k > n)
            return;

        // Option 1: Take the current subarray.
        int take = preSum[ind + k] - preSum[ind] + findIfPos(ind + k, preSum, cnt - 1, k, n, dp);

        // Option 2: Skip the current index and move to the next index.
        int notTake = findIfPos(ind + 1, preSum, cnt, k, n, dp);

        // If taking the current subarray gives a better result, include its starting index in the result.
        if (take >= notTake)
        {
            result.emplace_back(ind);
            findIdx(ind + k, preSum, k, cnt - 1, n, result, dp);
        }
        // Otherwise, skip the current index and continue searching.
        else
        {
            findIdx(ind + 1, preSum, k, cnt, n, result, dp);
        }
    }

public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
    {
        vector<int> result; // To store the starting indices of the three subarrays.
        int n = (int)nums.size();

        // Compute the prefix sum of the array for quick subarray sum calculations.
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }

        // Memoization table to store the results of subproblems.
        // dp[ind][cnt] stores the maximum sum for selecting `cnt` subarrays starting from index `ind`.
        vector<vector<int>> dp(n, vector<int>(4, -1));

        // Start finding the indices of the three subarrays.
        findIdx(0, preSum, k, 3, n, result, dp);

        return result;
    }
};

int main()
{

    return 0;
}