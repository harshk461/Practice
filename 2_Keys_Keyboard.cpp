#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int curr, int n, int paste, vector<vector<int>> &dp)
    {
        if (curr == n)
            return 0;

        if (curr > n)
            return 1e9;

        if (dp[curr][paste] != -1)
            return dp[curr][paste];

        // copy and paste
        int ans1 = 2 + solve(curr * 2, n, curr, dp);
        // only paste no copy
        int ans2 = 1 + solve(curr + paste, n, paste, dp);

        return dp[curr][paste] = min(ans1, ans2);
    }

public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return 1 + solve(1, n, 1, dp);
    }
};

int main()
{

    return 0;
}