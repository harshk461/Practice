#include <bits/stdc++.h>
using namespace std;

// TC-O(N);
// SC-O(N)+O(N)
// memoization- storing the previous results for future purposes in thr form of any data structure
// tabulation-
int fib(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];
    // store the current value
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

// int tab(int n, vector<int> &dp) {}

int main()
{
    int n;
    cin >> n;
    // vector<int> dp(n + 1);
    // for (int i = 0; i <= n; i++)
    // {
    //     dp[i] = -1;
    // }
    // cout << fib(n, dp) << endl;
    // tabulation method

    // vector<int> dp(n + 1, -1);
    // dp[0] = 0;
    // dp[1] = 1;
    // for (int i = 2; i <= n; i++)
    // {
    //     dp[i] = dp[i - 1] + dp[i - 2];
    // }
    // cout << dp[n] << " ";

    // Space Optimisation TC-O(n) SC-O(1)

    int prev1 = 1;
    int prev2 = 0;

    if (n == 0)
        return prev2;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;

        // shifting
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1 << " ";
    return 0;
}