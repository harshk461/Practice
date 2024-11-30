#include <bits/stdc++.h>
using namespace std;

// Disable synchronization between C and C++ standard streams
auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
private:
    // Recursive function using dynamic programming to find the longest square streak
    int solve(int index, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        // Base case: if we reach the end of the list, return 0
        if (index >= nums.size())
            return 0;

        // Check if this subproblem has already been solved
        if (dp[index][prev + 1] != -1)
            return dp[index][prev + 1];

        int take = 0;
        // If the previous element squared is equal to the current element or prev is -1 (first element),
        // include this element in the streak
        if (prev == -1 || pow(nums[prev], 2) == nums[index])
        {
            take = 1 + solve(index + 1, index, nums, dp);
        }

        // Option to skip the current element and not include it in the streak
        int notTake = solve(index + 1, prev, nums, dp);

        // Store the result in dp array for future use
        return dp[index][prev + 1] = max(take, notTake);
    }

    // Optimized function without dynamic programming to find the longest square streak
    int solve2(vector<int> &nums)
    {
        // Create a set to store all elements in the array for quick access
        set<long long> vis(nums.begin(), nums.end());

        int ans = 0;
        // Iterate over each number to start a streak
        for (auto num : nums)
        {
            int i = 1; // Initial streak length
            int t = num;
            while (i <= 5)
            {
                // Calculate the square of the current number in the streak
                long long int temp = pow(t, 2);

                // If the squared number is not in the set, break the streak
                if (vis.find(temp) == vis.end())
                    break;

                // Continue the streak
                i++;
                ans = max(ans, i); // Update the maximum streak length found
                t = temp;          // Move to the next number in the streak
            }
        }

        // Return -1 if the longest streak is less than 2; otherwise, return the streak length
        return ans < 2 ? -1 : ans;
    }

public:
    // Public function to find the longest square streak
    int longestSquareStreak(vector<int> &nums)
    {
        // Using optimized function without DP for this solution
        return solve2(nums);
    }
};

int main()
{

    return 0;
}