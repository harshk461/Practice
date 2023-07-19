#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

class Solution
{
private:
    // i is the current posn
    int solve(vector<int> location, int i, int end, int fuel, vector<vector<int>> &dp)
    {
        if (fuel < 0)
            return 0;
        if (dp[i][fuel] != -1)
            return dp[i][fuel];

        int res = i == end ? 1 : 0;
        for (int j = 0; j < location.size(); j++)
        {
            if (j == i)
                continue;
            res += solve(location, j, end, fuel - abs(location[i] - location[j]), dp);
            res %= MOD;
        }
        return dp[i][fuel] = res;
    }

public:
    int countRoutes(vector<int> &locations, int start, int finish, int fuel)
    {
        vector<vector<int>> dp(locations.size(), vector<int>(fuel + 1, -1));
        return solve(locations, start, finish, fuel, dp);
    }
};

int main()
{

    return 0;
}