#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int start, int end, int cut_start, int cut_end, vector<int> &cuts, vector<vector<int>> &dp)
    {
        if (cut_start > cut_end)
            return 0;

        if (dp[cut_start][cut_end] != -1)
            return dp[start][end];

        int ans = 1e9;
        for (int i = cut_start; i <= cut_end; i++)
        {
            ans = min(ans,
                      (end - start) +
                          solve(start, cuts[i], cut_start, i - 1, cuts, dp) + solve(cuts[i], end, i + 1, cut_end, cuts, dp));
        }

        return dp[cut_start][cut_end] = ans;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        sort(cuts.begin(), cuts.end());
        return solve(0, n, 0, cuts.size() - 1, cuts, dp);
    }
};

int main()
{

    return 0;
}