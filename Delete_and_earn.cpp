#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> dp(10001);
        for (int num : nums)
        {
            dp[num] += num;
        }
        int prev1 = 0;
        int prev2 = 0;

        for (int num : dp)
        {
            int temp = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};

class Solution
{
private:
    // Recursive function to find the maximum points we can earn by including/excluding numbers
    int solve(int i, int maxi, vector<int> &nums, vector<int> &freq, vector<int> &dp)
    {
        // Base case: if index exceeds the maximum value in nums, return 0 (no points to earn)
        if (i > maxi)
            return 0;

        // If we've already computed the result for index i, return the stored result
        if (dp[i] != -1)
            return dp[i];

        // Option 1: Take the current number i and add its points
        // Points earned by taking `i` = (frequency of `i`) * i
        // Move to `i + 2` to avoid adjacent deletions (i-1 and i+1)
        int take = freq[i] * i + solve(i + 2, maxi, nums, freq, dp);

        // Option 2: Skip the current number i and check for the next number (i+1)
        int notTake = 0 + solve(i + 1, maxi, nums, freq, dp);

        // Store the maximum points we can earn by either taking or not taking the current number
        return dp[i] = max(take, notTake);
    }

public:
    int deleteAndEarn(vector<int> &nums)
    {
        // Find the maximum number in the array to limit our frequency and dp array size
        int maxi = *max_element(nums.begin(), nums.end());

        // Frequency array to count occurrences of each number in nums
        vector<int> freq(maxi + 1, 0);

        // Initialize dp array with -1 to indicate uncomputed states
        vector<int> dp(maxi + 1, -1);

        // Fill the frequency array where `freq[x]` indicates the count of `x` in nums
        for (auto it : nums)
            freq[it]++;

        // Start the recursive function from index 0 with the maximum number in nums
        return solve(0, maxi, nums, freq, dp);
    }
};

int main()
{

    return 0;
}