#include <bits/stdc++.h>
using namespace std;

// Lambda function to disable synchronization between C++ standard streams and C standard streams
// for faster input and output operations. This is often used in competitive programming.
auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable sync with stdio
    cin.tie(0);                  // Untie cin from cout for faster input
    cout.tie(0);                 // Untie cout from cin for faster output
    return 'c';                  // Return a character to prevent compiler warnings (though this return is unused)
}();

// Define the Solution class
class Solution
{
public:
    // Function to count the number of set bits (1s) in the binary representation of a number
    int countSetBits(int num)
    {
        int count = 0;
        while (num) // Loop until num becomes zero
        {
            count += num & 1; // Add 1 to count if the last bit of num is 1
            num >>= 1;        // Right shift num by 1 bit
        }
        return count; // Return the total count of set bits
    }

    // Function to add a specified number of set bits to the binary representation of a number
    int addSetBits(int num, int bitsToAdd)
    {
        int bitPos = 0;       // Start from the least significant bit
        while (bitsToAdd > 0) // Loop until all bits to add are set
        {
            while ((num >> bitPos) & 1) // Find the next unset bit
                ++bitPos;               // Increment the bit position
            num |= (1 << bitPos);       // Set the bit at position bitPos
            --bitsToAdd;                // Decrease the bitsToAdd counter
        }
        return num; // Return the modified number
    }

    // Function to remove a specified number of set bits from the binary representation of a number
    int removeSetBits(int num, int bitsToRemove)
    {
        while (bitsToRemove > 0) // Loop until all bits to remove are cleared
        {
            num &= (num - 1); // Clear the least significant set bit
            --bitsToRemove;   // Decrease the bitsToRemove counter
        }
        return num; // Return the modified number
    }

    // Function to minimize the XOR result between two numbers
    int minimizeXor(int num1, int num2)
    {
        int setBitsNum1 = countSetBits(num1); // Count set bits in num1
        int setBitsNum2 = countSetBits(num2); // Count set bits in num2

        if (setBitsNum1 == setBitsNum2) // If both have the same number of set bits
            return num1;                // Return num1 as is

        if (setBitsNum1 < setBitsNum2)                          // If num1 has fewer set bits
            return addSetBits(num1, setBitsNum2 - setBitsNum1); // Add the necessary set bits to num1

        // If num1 has more set bits
        return removeSetBits(num1, setBitsNum1 - setBitsNum2); // Remove the excess set bits from num1
    }
};

int main()
{

    return 0;
}