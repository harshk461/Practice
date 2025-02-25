#include <bits/stdc++.h>
using namespace std;

// Speeding up input/output for competitive programming
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disables synchronization with C standard streams for faster I/O
    cin.tie(0);                  // Unties cin from cout, improving performance
    cout.tie(0);                 // Unties cout from cin
    return 'c';                  // Return a dummy value
}();

class Solution
{
public:
    // Function to check if we can construct k palindromes from string s
    bool canConstruct(string s, int k)
    {
        int n = s.length(); // Get the length of the string

        // If the length of the string is less than k, we can't form k palindromes
        if (n < k)
            return false;

        // Initialize an unordered map to count the frequency of each character
        unordered_map<int, int> freq;

        // Count the frequency of each character in the string
        for (auto it : s)
            freq[it]++;

        // Variable to count the number of characters with an odd frequency
        int odd = 0;

        // Iterate through the frequency map
        for (auto it : freq)
        {
            // If the frequency of the character is odd, increment the odd counter
            if (it.second % 2 != 0)
                odd++;
        }

        // If the number of characters with odd frequencies is more than k, return false
        // Otherwise, return true (we can form k palindromes)
        return odd <= k;
    }
};

int main()
{

    return 0;
}