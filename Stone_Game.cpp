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
private:
    int getScore(int i, int j, bool isAlice, vector<int> &piles, vector<vector<vector<int>>> &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
            return piles[i];
        if (dp[i][j][isAlice] != -1)
            return dp[i][j][isAlice];

        int ans = isAlice ? -1e9 : 1e9;

        if (isAlice)
        {
            ans = max(ans, piles[i] + getScore(i + 1, j, !isAlice, piles, dp));
            ans = max(ans, piles[i] + getScore(i, j - 1, !isAlice, piles, dp));
        }
        else
        {
            ans = min(ans, piles[i] + getScore(i + 1, j, !isAlice, piles, dp));
            ans = min(ans, piles[i] + getScore(i, j - 1, !isAlice, piles, dp));
        }

        return dp[i][j][isAlice] = ans;
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
        return getScore(0, n - 1, true, piles, dp);
    }
};

int main()
{

    return 0;
}