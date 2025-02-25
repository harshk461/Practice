#include <bits/stdc++.h>
using namespace std;

// Disable synchronization with C-style I/O streams for faster input/output operations
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O streams
    cin.tie(0);                  // Untie cin from cout to avoid unnecessary flushing of cout
    cout.tie(0);                 // Untie cout from cin
    return 'c';                  // Return a character to ensure the lambda has a return type
}();

class Solution
{
private:
    // Brute force approach to calculate the XOR of all possible pairs between nums1 and nums2
    int brute(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0;
        for (int i = 0; i < nums1.size(); i++)
            for (int j = 0; j < nums2.size(); j++)
                ans ^= (nums1[i] ^ nums2[j]); // XOR each pair and accumulate the result

        return ans;
    }

public:
    // Optimized function to calculate the XOR of all pairs without explicitly iterating over each pair
    int xorAllNums(vector<int> &nums1, vector<int> &nums2)
    {
        int xor1 = 0; // XOR of all elements in nums1
        int xor2 = 0; // XOR of all elements in nums2

        // Calculate xor1 by XORing all elements in nums1
        for (auto it : nums1)
            xor1 ^= it;

        // Calculate xor2 by XORing all elements in nums2
        for (auto it : nums2)
            xor2 ^= it;

        int ans = 0;

        // If nums1 has an odd size, each element of nums2 will appear an odd number of times in the XOR
        if (nums1.size() % 2 == 1)
            ans ^= xor2;

        // If nums2 has an odd size, each element of nums1 will appear an odd number of times in the XOR
        if (nums2.size() % 2 == 1)
            ans ^= xor1;

        return ans;
    }
}
;
int main()
{

    return 0;
}