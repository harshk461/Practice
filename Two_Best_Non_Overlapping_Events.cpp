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
    int solve(int i, int count, vector<vector<int>> &events, vector<vector<int>> &dp)
    {
        if (count == 2 || i >= events.size())
            return 0;

        if (dp[i][count] == -1)
        {
            int end = events[i][1];
            int low = i + 1;
            int high = events.size() - 1;

            while (low < high)
            {
                int mid = (low + high) / 2;
                if (events[mid][0] > end)
                    high = mid;
                else
                    low = mid + 1;
            }

            int include = events[i][2] + (low < events.size() && events[low][0] > end
                                              ? solve(low, count + 1, events, dp)
                                              : 0);
            int exclude = solve(i + 1, count, events, dp);

            dp[i][count] = max(include, exclude);
        }

        return dp[i][count];
    }

public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n, vector<int>(3, -1));
        return solve(0, 0, events, dp);
    }
};

int main()
{

    return 0;
}