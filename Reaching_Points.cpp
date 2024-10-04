#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool solve(int sx, int sy, int tx, int ty, vector<vector<int>> &dp)
    {
        if (sx == tx && sy == ty)
            return true;

        if (sx > tx || sy > ty)
            return false;

        if (dp[tx][ty] != -1)
            return dp[tx][ty];

        if (tx > ty)
            return dp[tx][ty] = solve(sx, sy, tx - ty, ty, dp);
        else
            return dp[tx][ty] = solve(sx, sy, tx, ty - tx, dp);
    }

public:
    bool reachingPoints(int sx, int sy, int tx, int ty)
    {
        // vector<vector<int>> dp(tx + 1, vector<int>(ty + 1, -1));
        // return solve(sx, sy, tx, ty, dp);
        // start decreasing from larger value to smaller value
        while (tx >= sx && ty >= sy)
        {
            if (tx == sx && ty == sy)
                return true;

            //(tx-sx) is normally what we have to do because we are going from big to small
            // ()/ty to get the multiple of ty to decrease it from tx
            if (tx > ty)
                tx -= max(1, (tx - sx) / ty) * ty;
            // same as tx
            else
                ty -= max(1, (ty - sy) / tx) * tx;
        }

        return false;
    }
};

int main()
{

    return 0;
}