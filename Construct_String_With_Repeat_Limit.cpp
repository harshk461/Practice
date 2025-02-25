#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization with C standard library for faster I/O
    cin.tie(0);                  // Untie cin and cout to avoid flushing output unnecessarily
    cout.tie(0);                 // Avoid flushing output after each write operation
    return 'c';
}();

class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> freq(26, 0); // Initialize a frequency array to count occurrences of each character
        for (auto it : s)        // Count the frequency of each character in the string
        {
            freq[it - 'a']++;
        }

        string ans = ""; // String to store the resulting answer
        int curr = 25;   // Start from the largest character ('z')

        while (curr >= 0) // Loop through all characters from 'z' to 'a'
        {
            // Skip the current character if it is not available
            if (freq[curr] == 0)
            {
                curr--; // Move to the next smaller character
                continue;
            }

            // Add the current character to the result up to the limit (repeatLimit)
            int max_char = min(freq[curr], repeatLimit); // Determine how many times to add the current character
            for (int i = 0; i < max_char; i++)
                ans += ('a' + curr); // Append the character to the result string

            freq[curr] -= max_char; // Update the frequency of the current character after adding it

            // If there are still remaining occurrences of the current character, find the next available one
            if (freq[curr] > 0)
            {
                int next_char = curr - 1; // Look for a smaller character
                while (next_char >= 0 && freq[next_char] == 0)
                    next_char--; // Skip over characters with zero frequency

                if (next_char < 0) // If no smaller character is found, break the loop
                    break;

                ans += 'a' + next_char; // Add the next smaller character to the result
                freq[next_char]--;      // Decrease the frequency of the next smaller character
            }
        }

        return ans; // Return the final result string
    }
};

int main()
{

    return 0;
}