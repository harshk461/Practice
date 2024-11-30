#include <bits/stdc++.h>
using namespace std;

// #pragma GCC target("avx, mmx, sse2, sse3, sse4")

// static const int disableSync = [](void) noexcept -> int
// {
//     std::ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     std::cout.tie(nullptr);
//     return 0;
// }();

class Solution
{
private:
    int solve(int n, int w, int val[], int wt[], vector<vector<int>> &dp)
    {
        if (n == 0)
            return 0;
        if (w <= 0)
            return 0;
        if (dp[n][w] != -1)
            return dp[n][w];

        int ans = 0;
        if (wt[n - 1] <= w)
        {
            int take = val[n - 1] + solve(n, w - wt[n - 1], val, wt, dp);
            int notTake = solve(n - 1, w, val, wt, dp);

            ans = max(take, notTake);
        }
        else
        {
            ans = solve(n - 1, w, val, wt, dp);
        }

        return dp[n][w] = ans;
    }

public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        return solve(N, W, val, wt, dp);
    }
};

int main()
{

    return 0;
}