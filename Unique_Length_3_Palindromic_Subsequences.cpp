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
    // Helper function to calculate unique palindromic subsequences
    int solve(string s)
    {
        int res = 0; // Result to store the count of unique palindromic subsequences

        // Vectors to store the first and last occurrence of each character
        vector<int> first(26, INT_MAX); // Initialize all first occurrences as INT_MAX
        vector<int> last(26, 0);        // Initialize all last occurrences as 0

        // Traverse the string to find the first and last occurrence of each character
        for (int i = 0; i < s.length(); i++)
        {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i); // Update the first occurrence
            last[s[i] - 'a'] = i;                          // Update the last occurrence
        }

        // Iterate through all lowercase English letters ('a' to 'z')
        for (int i = 0; i < 26; i++)
        {
            // Check if the character appears at least twice in the string
            if (first[i] < last[i])
            {
                // Create a set of unique characters between the first and last occurrence
                unordered_set<char> unique_chars(
                    s.begin() + first[i] + 1, // Start after the first occurrence
                    s.begin() + last[i]       // End before the last occurrence
                );

                // Add the size of the set to the result
                // Each unique character forms a valid palindromic subsequence
                res += unique_chars.size();
            }
        }

        return res; // Return the total count of unique palindromic subsequences
    }

public:
    // Main function to count unique palindromic subsequences of length 3
    int countPalindromicSubsequence(string s)
    {
        return solve(s); // Call the helper function and return the result
    }
};

int main()
{

    return 0;
}