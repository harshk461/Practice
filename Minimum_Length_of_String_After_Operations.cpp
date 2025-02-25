#include <bits/stdc++.h>
using namespace std;

// Speed up I/O operations by disabling synchronization with C I/O streams
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization between C and C++ standard streams
    cin.tie(0);                  // Untie cin from cout to improve input/output efficiency
    cout.tie(0);                 // Untie cout from cin
    return 'c';                  // Dummy return to ensure the lambda is executed immediately
}();

// Define a class named Solution
class Solution
{
public:
    // Function to calculate the minimum length of the string after repeatedly removing pairs of characters
    int minimumLength(string s)
    {
        unordered_map<int, int> freq; // Map to store frequency of each character

        // Count the frequency of each character in the string
        for (auto it : s)
            freq[it]++;

        // Adjust the frequency by removing pairs of the same character that have both left and right occurrences
        for (auto it : freq)
        {
            int count = it.second; // Get the frequency of the current character
            while (count > 2)
            {
                // removing left and right character
                // a a a count 3 we have to remove left and right character
                count -= 2; // Simulate the removal of a pair of characters
            }
            freq[it.first] = count; // Update the frequency in the map
        }

        int ans = 0; // Initialize the result to store the minimum length
        // Sum up the adjusted frequencies to get the minimum length of the final string
        for (auto it : freq)
            ans += it.second;

        return ans; // Return the result
    }
};

int main()
{

    return 0;
}