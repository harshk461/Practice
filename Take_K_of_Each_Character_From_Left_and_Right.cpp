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
    int takeCharacters(string s, int k)
    {
        // Create a vector to count occurrences of 'a', 'b', and 'c' in the string
        vector<int> count(3, 0);
        int n = s.length();

        // Count the frequency of each character ('a', 'b', 'c') in the string
        for (auto it : s)
            count[it - 'a']++;

        // Check if it's possible to have at least 'k' occurrences of each character
        for (int i = 0; i < 3; i++)
            if (count[i] < k)
                return -1; // If not, return -1 since it's not possible to satisfy the condition

        // Sliding window technique to find the maximum length of a valid substring
        vector<int> window(3, 0); // Tracks character counts in the current window
        int left = 0;             // Left pointer for the sliding window
        int maxi = 0;             // Maximum valid substring length

        // Iterate through the string with the right pointer
        for (int right = 0; right < n; right++)
        {
            // Increment the count for the current character in the window
            window[s[right] - 'a']++;

            // Adjust the window if any character count in the remaining part falls below 'k'
            while (left <= right &&
                   ((count[0] - window[0] < k) || // Remaining 'a's < k
                    (count[1] - window[1] < k) || // Remaining 'b's < k
                    (count[2] - window[2] < k)))  // Remaining 'c's < k
            {
                // Shrink the window from the left
                window[s[left] - 'a']--;
                left++;
            }

            // Update the maximum valid window size
            maxi = max(maxi, right - left + 1);
        }

        // The result is the total string length minus the maximum valid substring length
        return n - maxi;
    }
};

int main()
{

    return 0;
}