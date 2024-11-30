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
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        vector<pair<int, int>> arr;

        // Flatten the k lists into a single list with values and their corresponding list indices.
        for (int i = 0; i < nums.size(); i++)
        {
            for (auto it : nums[i])
                arr.push_back({it, i}); // Store both value and index of the original list
        }

        // Sort the flattened list based on the values.
        sort(arr.begin(), arr.end());

        int left = 0;  // Left pointer of the sliding window
        int right = 0; // Right pointer of the sliding window

        unordered_map<int, int> freq; // To keep track of frequency of numbers from each list
        int start = 0, end = INT_MAX; // To store the smallest range
        int count = 0;                // To count how many lists are included in the current window

        // Expand the right pointer to cover all lists
        while (right < arr.size())
        {
            // Add the element to the frequency map and increase count if this list was not included before
            freq[arr[right].second]++;
            if (freq[arr[right].second] == 1)
                count++; // New list added to the window

            // When all lists are covered (count == nums.size()), try to shrink the window
            while (count == nums.size())
            {
                // Calculate the current range
                int curr_range = arr[right].first - arr[left].first;

                // Check if the current range is smaller than the best (smallest) range found so far
                if (curr_range < end - start)
                {
                    start = arr[left].first; // Update the start of the smallest range
                    end = arr[right].first;  // Update the end of the smallest range
                }

                // Shrink the window from the left side by reducing the frequency of the left element
                freq[arr[left].second]--;

                // If a list is no longer covered in the window, decrease the count
                if (freq[arr[left].second] == 0)
                    count--;

                left++; // Move the left pointer to the right
            }

            right++; // Expand the window by moving the right pointer
        }

        return {start, end}; // Return the smallest range [start, end]
    }
};

int main()
{

    return 0;
}