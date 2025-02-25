#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false); // Disable synchronization with C I/O streams for faster I/O.
    cin.tie(0);                  // Untie cin from cout to improve input/output efficiency.
    cout.tie(0);                 // Untie cout from cin for efficiency.
    return 'c';                  // Dummy return value to ensure the lambda is executed at runtime.
}();

class Solution
{
private:
    int MOD = 1e9 + 7; // Modulo value to prevent overflow and keep results within bounds.

    // Function to compute (n^x) % MOD using iterative modular exponentiation.
    long long int power(long long int n, long long int x)
    {
        long long int ans = 1; // Initialize result as 1.

        while (x > 0)
        {
            // If the current power is odd, multiply the current base `n` to the result.
            if (x % 2 == 1)
            {
                ans = (ans * n) % MOD; // Update result under modulo to prevent overflow.
            }

            // Square the base and reduce the exponent by half (x // 2).
            n = (n * n) % MOD;
            x /= 2;
        }

        return ans; // Return the final result of (n^x) % MOD.
    }

public:
    // Function to count the number of "good numbers" of length `n`.
    int countGoodNumbers(long long n)
    {
        // Compute the number of even-indexed digits. There are `(n + 1) / 2` even indices.
        long long int even = power(5, (n + 1) / 2);

        // Compute the number of odd-indexed digits. There are `n / 2` odd indices.
        long long int odd = power(4, n / 2);

        // Combine the results by multiplying and applying modulo to keep the result bounded.
        return (even * odd) % MOD;
    }
};

int main()
{

    return 0;
}