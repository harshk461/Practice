#include <bits/stdc++.h>
using namespace std;

// Speed up input/output operations and synchronize C++ streams with standard C streams
auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c'; // Dummy return to ensure the lambda is evaluated once when the program starts
}();

class Solution
{
private:
    // Helper function to generate a sieve of Eratosthenes up to n
    void sieve(vector<bool> &isPrime, int n)
    {
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        // Mark all non-prime numbers as false using the sieve algorithm
        for (int i = 2; i * i <= n; i++)
        {
            if (isPrime[i]) // If i is prime
            {
                // Mark all multiples of i as non-prime starting from i*i
                for (int j = i * i; j <= n; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }

public:
    // Main function to determine if the array can be made strictly increasing
    bool primeSubOperation(vector<int> &nums)
    {
        int n = nums.size();                                 // Length of the input array
        int maxVal = *max_element(nums.begin(), nums.end()); // Find the maximum element in the array
        vector<bool> isPrime(maxVal + 1, true);              // Create a vector to store prime information up to maxVal

        // Generate the prime numbers up to maxVal using the sieve of Eratosthenes
        sieve(isPrime, maxVal);

        // Traverse the array from the second-to-last element to the first
        for (int i = n - 2; i >= 0; i--)
        {
            // If the current element is already less than the next, skip it
            if (nums[i] < nums[i + 1])
                continue;

            bool valid = false; // Flag to indicate if a valid operation was found

            // Try to subtract primes from nums[i] starting from 2 up to nums[i]
            for (int p = 2; p < nums[i]; p++)
            {
                // Check if p is prime and if subtracting p makes nums[i] less than nums[i + 1]
                if (isPrime[p] && nums[i] - p < nums[i + 1])
                {
                    nums[i] -= p; // Subtract the prime from nums[i]
                    valid = true; // Mark as a valid operation found
                    break;        // Exit the loop after the first valid operation
                }
            }

            // If no valid operation was found, return false
            if (!valid)
                return false;
        }

        // If we reach here, the array has been made strictly increasing
        return true;
    }
};

int main()
{

    return 0;
}