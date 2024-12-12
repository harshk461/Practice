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
private:
    // Helper function to check if a subarray is sorted in ascending order and consecutive
    bool isSorted(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; i++)
        {
            // Check if the current element is greater than the next or if the elements are not consecutive
            if (nums[i] > nums[i + 1] || abs(nums[i + 1] - nums[i]) != 1)
                return false; // Return false if not sorted or not consecutive
        }
        return true; // Return true if the entire subarray is sorted and consecutive
    }

    // Brute-force approach to find maximum elements in subarrays of size k that are sorted and consecutive
    vector<int> brute(vector<int> &nums, int k)
    {
        vector<int> ans; // Initialize result vector
        // Iterate over all possible subarrays of size k
        for (int i = 0; i < nums.size() - k + 1; i++)
        {
            // Create a subarray from index i to i + k
            vector<int> temp(nums.begin() + i, nums.begin() + i + k);

            // Check if the subarray is sorted and consecutive
            if (isSorted(temp))
            {
                // Add the last element of the subarray (max element in a sorted subarray)
                ans.push_back(temp.back());
            }
            else
            {
                // If not sorted, add -1 as a placeholder
                ans.push_back(-1);
            }
        }

        return ans; // Return the result vector
    }

public:
    // Optimized approach to return results array for subarrays of size k
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        int n = nums.size(); // Size of the input array
        // Initialize the result array with -1 (default value)
        vector<int> ans(n - k + 1, -1);

        int len = 1; // Keeps track of the length of the current valid subarray

        // Check the initial window of size k
        for (int i = 1; i < k; i++)
        {
            // Check if the current and previous elements are consecutive and sorted
            if (nums[i] == nums[i - 1] + 1)
            {
                len++; // Increment length if condition is met
            }
            else
            {
                len = 1; // Reset the length if condition fails
            }
        }

        // If the initial window is sorted and consecutive, set the result for the first window
        if (len == k)
        {
            ans[0] = nums[k - 1]; // The last element in the subarray is the maximum
        }

        int index = 1; // Start filling the result from the second position
        for (int i = k; i < n; i++)
        {
            // Check if the current and previous elements are consecutive
            if (nums[i] == nums[i - 1] + 1)
            {
                len++; // Increment length if condition is met
            }
            else
            {
                len = 1; // Reset the length if condition fails
            }

            // If a valid subarray of at least length k is found, set the result
            if (len >= k)
            {
                ans[index] = nums[i]; // Add the current element as it is the maximum in a valid subarray
            }
            index++; // Move to the next result index
        }

        return ans; // Return the result array
    }
};

int main()
{

    return 0;
}