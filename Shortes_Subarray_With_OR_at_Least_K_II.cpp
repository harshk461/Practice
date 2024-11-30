#include <bits/stdc++.h>
using namespace std;

// This lambda function is used for fast I/O. It disables the synchronization between the C and C++ standard streams,
// which speeds up input and output operations.
auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c'; // Just returning a dummy value to make it a valid expression.
}();

class Solution
{
public:
    // This function finds the minimum length of a contiguous subarray such that the bitwise OR of all its elements is at least `k`.
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size(); // Get the size of the input array.
        int or_val = 0;      // Variable to keep track of the current bitwise OR of the subarray.
        int ans = 1e9;       // Initialize the answer with a large value (infinity equivalent).

        // Vector to count how many times each bit (0 to 30) is set in the current window.
        vector<int> bit_count(31, 0);

        // Use two pointers (i and j) for the sliding window technique.
        for (int i = 0, j = 0; j < n; j++)
        {
            // Add the current number `nums[j]` to the subarray and update bit counts and `or_val`.
            for (int bit = 30; bit >= 0; bit--)
            {
                if (nums[j] & (1 << bit))
                {
                    bit_count[bit]++;     // Increment the count for this bit.
                    or_val |= (1 << bit); // Update `or_val` to include this bit.
                }
            }

            // Shrink the window from the left until `or_val` is less than `k`.
            while (i <= j && or_val >= k)
            {
                // Update the minimum length of the subarray.
                ans = min(ans, j - i + 1);

                // Remove `nums[i]` from the subarray and update `bit_count` and `or_val`.
                for (int bit = 30; bit >= 0; bit--)
                {
                    if (nums[i] & (1 << bit))
                    {
                        bit_count[bit]--; // Decrement the count for this bit.
                        // If this bit is no longer present in the subarray, remove it from `or_val`.
                        if (bit_count[bit] == 0)
                            or_val ^= (1 << bit);
                    }
                }
                i++; // Move the left pointer to shrink the window.
            }
        }

        // If `ans` is still 1e9, it means no valid subarray was found, so return -1. Otherwise, return `ans`.
        return ans == 1e9 ? -1 : ans;
    }
};

int main()
{

    return 0;
}