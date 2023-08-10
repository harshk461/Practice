#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> calculateM_N(string s)
    {
        int m = 0, n = 0;
        for (auto i : s)
        {
            if (i == '1')
                m++;
            else
                n++;
        }

        return {m, n};
    }
    int solve(vector<string> &strs, int m, int n, int index)
    {
        if (index >= strs.size())
            return 0;

        // curr string ones and zeros
        vector<int> curr = calculateM_N(strs[index]);
        int zero = curr[1];
        int one = curr[0];

        // exclude
        int exclude = solve(strs, m, n, index + 1);

        int include = 0;
        if (m >= zero && n >= one)
            include = 1 + solve(strs, m - zero, n - one, index + 1);

        return max(include, exclude);
    }

    int f(vector<string> &strs, int m, int n)
    {
        // m->0
        // n->1
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto s : strs)
        {
            vector<int> curr = calculateM_N(s);
            // curr[0]->number of 1 in string
            // curr[1]->number of 0 in string

            for (int i = m; i >= curr[1]; i--)
                for (int j = n; j >= curr[0]; j--)
                    dp[i][j] = max(dp[i][j], 1 + dp[i - curr[1]][j - curr[0]]);
        }

        return dp[m][n];
    }

public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        return solve(strs, m, n, 0);
    }
};

int main()
{

    return 0;
}