#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long MOD = 1e9 + 7;

    long long f(int N, int L, int K, int len, int num)
    {
        if (len == L)
            return num == N;

        int ans = (f(N, L, K, len + 1, num) * max(0, num - K)) % MOD;
        ans += (f(N, L, K, len + 1, num + 1) * (N - num)) % MOD;

        ans %= MOD;

        return ans;
    }

    long long solve(int n, int goal, int k)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, 0));
        dp[1][1] = 1;

        for (int i = 2; i <= n; i++)
            dp[i][i] = (dp[i - 1][i - 1] * i) % MOD;

        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= goal; j++)
                dp[i][j] = (dp[i][j - 1] * ((i > k) ? (i - k) : 0) % MOD + (dp[i - 1][j - 1] * i) % mod) % MOD;

        return dp[n][goal];
    }

public:
    int numMusicPlaylists(int n, int goal, int k)
    {
        return solve(n, goal, k);
    }
};

int main()
{

    return 0;
}