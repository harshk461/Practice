#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    int solve(int i, vector<pair<int, int>> &v, vector<int> &dp)
    {
        if (i != -1 && v[i].second >= n)
            return 0;

        if (dp[i + 1] != -1)
            return dp[i + 1];

        int ans = 1e9;
        for (int j = i + 1; j < v.size(); j++)
        {
            if ((i == -1 && v[j].first <= 0) || (i != -1 && v[j].first <= v[i].second))
                ans = min(ans, 1 + solve(j, v));
            else
                break;
        }

        return dp[i + 1] = ans;
    }

    int minTaps(int n, vector<int> &ranges)
    {
        this->n = n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n + 1; i++)
            v.push_back({i - ranges[i], i + ranges[i]});

        sort(v.begin(), v.end());
        vector<int> dp(n + 1, -1);
        return solve(-1, v) == 1e9 ? -1 : solve(-1, v);
    }
};

int main()
{

    return 0;
}