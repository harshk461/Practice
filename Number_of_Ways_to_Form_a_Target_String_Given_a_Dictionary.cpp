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
    vector<vector<int>> A;
    vector<vector<int>> memo;
    const int mod = 1e9 + 7;

    int F(int i, int j, string &T)
    {
        if (j == T.size())
        {
            return 1; // Target string completely matched
        }
        if (i == A.size())
        {
            return 0; // Columns exhausted without fully matching the target
        }
        if (memo[i][j] != -1)
        {
            return memo[i][j]; // Return precomputed result
        }

        // Not taking the current column
        long long count = F(i + 1, j, T);
        count %= mod;

        // Taking the current column if the character matches
        if (A[i][T[j] - 'a'] > 0)
        {
            count += (1LL * A[i][T[j] - 'a'] * F(i + 1, j + 1, T)) % mod;
            count %= mod;
        }

        return memo[i][j] = count;
    }

    int numWays(vector<string> &W, string T)
    {
        int n = W.size();
        int m = W[0].size();
        int t = T.size();

        // Build frequency matrix for characters in each column
        A = vector<vector<int>>(m, vector<int>(26, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                A[j][W[i][j] - 'a']++;
            }
        }

        // Initialize memoization table
        memo = vector<vector<int>>(m, vector<int>(t, -1));

        // Start solving from the first column and first character of the target
        return F(0, 0, T);
    }
};

int main()
{

    return 0;
}