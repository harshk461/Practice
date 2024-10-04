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
    int findTheLongestSubstring(string s)
    {
        int n = s.length();

        // Map to store the bitmask corresponding to each vowel
        map<char, int> vow;
        vow['a'] = 1;  // Assign bit 0 to 'a'
        vow['e'] = 2;  // Assign bit 1 to 'e'
        vow['i'] = 4;  // Assign bit 2 to 'i'
        vow['o'] = 8;  // Assign bit 3 to 'o'
        vow['u'] = 16; // Assign bit 4 to 'u'

        // Prefix XOR to track the current state of vowel counts
        int pref = 0;
        int maxi = 0;

        // Hash map to store the first occurrence of each prefix XOR
        map<int, int> mp;
        mp[0] = -1; // To handle the case where a valid substring starts from index 0

        // Traverse the string and update the prefix XOR
        for (int i = 0; i < n; i++)
        {
            if (vow.find(s[i]) != vow.end())
            {
                // Toggle the bit for the current vowel
                pref ^= vow[s[i]];
            }

            // Check if the current prefix XOR has been seen before
            if (mp.find(pref) != mp.end())
            {
                maxi = max(maxi, i - mp[pref]);
            }
            else
            {
                mp[pref] = i; // Store the first occurrence of this prefix XOR
            }
        }

        return maxi;
    }
};

int main()
{

    return 0;
}