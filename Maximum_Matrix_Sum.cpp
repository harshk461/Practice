#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization with C-style I/O for faster input/output
    cin.tie(0);                  // Untie cin from cout for faster input/output
    cout.tie(0);                 // Untie cout from cin for faster output
    return 'c';
}();

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long sum = 0;      // To store the sum of the absolute values of all elements
        int mini = INT_MAX;     // To track the smallest absolute value in the matrix
        int negative_count = 0; // To count the number of negative values in the matrix

        // Step 1: Traverse through the matrix to calculate the sum of absolute values,
        // count negative numbers, and find the smallest absolute value.
        for (auto it : matrix)
        {
            for (auto val : it)
            {
                sum += abs(val); // Add the absolute value of the current element to the sum

                if (val < 0) // Count the negative numbers
                {
                    negative_count++;
                }

                mini = min(mini, abs(val)); // Update the smallest absolute value
            }
        }

        // Step 2: Adjust the sum if there is an odd number of negative values.
        // If the count of negative values is odd, the product of all elements
        // will be negative. To maximize the sum, we flip the sign of the smallest
        // absolute value (subtract it twice).
        if (negative_count % 2 != 0)
            sum -= 2 * mini;

        return sum; // Return the maximum possible sum of the matrix
    }
};

int main()
{

    return 0;
}