#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dp[21][21][21][21];
    int solve(int h_start, int h_end, int v_start, int v_end,
              vector<int> &hc, vector<int> &vc)
    {
        if (h_end - h_start == 1 && v_end - v_start == 1)
            return 0;

        if (dp[h_start][h_end][v_start][v_end] != -1)
            return dp[h_start][h_end][v_start][v_end];

        int ans = 1e9;

        // apply horizontal cut
        for (int i = h_start + 1; i < h_end; i++)
        {
            int cost = hc[i - 1] + solve(h_start, i, v_start, v_end, hc, vc) +
                       solve(i, h_end, v_start, v_end, hc, vc);
            ans = min(ans, cost);
        }

        // apply vertical cut
        for (int i = v_start + 1; i < v_end; i++)
        {
            int cost = vc[i - 1] + solve(h_start, h_end, v_start, i, hc, vc) +
                       solve(h_start, h_end, i, v_end, hc, vc);
            ans = min(ans, cost);
        }

        return dp[h_start][h_end][v_start][v_end] = ans;
    }

public:
    int minimumCost(int m, int n, vector<int> &horizontalCut, vector<int> &verticalCut)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, m, 0, n, horizontalCut, verticalCut);
    }
};

int main()
{

    return 0;
}