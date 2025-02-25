#include <bits/stdc++.h>
using namespace std;

// Optimize I/O operations for competitive programming
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
    // Recursive function to count all unique tile arrangements
    int solve(unordered_map<int, int> &freq)
    {
        int count = 0; // Stores the count of unique sequences

        // Iterate over each character's frequency
        for (auto &it : freq)
        {
            if (it.second > 0) // If the character is still available
            {
                it.second--;              // Use the character
                count += 1 + solve(freq); // Recur with reduced frequency
                it.second++;              // Backtrack: Restore the frequency
            }
        }
        return count;
    }

public:
    int numTilePossibilities(string tiles)
    {
        unordered_map<int, int> freq; // Stores the frequency of each character
        for (char it : tiles)
            freq[it]++; // Count occurrences of each character

        return solve(freq); // Start recursion to count all possible sequences
    }
};

int main()
{
    Solution sol;
    string tiles = "AAB";
    cout << sol.numTilePossibilities(tiles) << endl; // Expected output: 8
    return 0;
}
