#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dfs(int i, int zero, vector<int> &cookies, vector<int> &dp)
    {
        if (cookies.size() - 1 == zero)
            return INT_MAX;
        if (i == cookies.size())
            return *max_element(dp.begin(), dp.end());

        int ans = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            zero -= dp[i] == 0 ? 1 : 0;
            dp[i] += cookies[i];

            ans = min(ans, dfs(i + 1, zero, cookies, dp));
            dp[i] -= cookies[i];
            zero += dp[i] == 0 ? 1 : 0;
        }
        return ans;
    }

public:
    int distributeCookies(vector<int> &cookies, int k)
    {
        int dp(k, 0);
        return dfs(0, k, cookies, dp);
    }
};

int main()
{

    return 0;
}