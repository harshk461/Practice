#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // TLE
    int solve(int n, vector<int> &days, vector<int> &costs, int index)
    {
        // base case
        if (index >= n)
            return 0;

        // 1 day pass
        int opt1 = cost[0] + solve(n, days, costs, index + 1);

        // 2 day pass
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;

        int opt2 = cost[1] + solve(n, days, costs, i);

        // 30 days pass
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;
        int opt3 = cost[2] + solve(n, days, costs, i);

        return min(opt1, min(opt2, opt3));
    }

    int solveMem(int n, vector<int> &days, vector<int> &costs, int index)
    {
        // base case
        if (index >= n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // 1 day pass
        int opt1 = costs[0] + solve(n, days, costs, index + 1);

        // 2 day pass
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;

        int opt2 = costs[1] + solve(n, days, costs, i);

        // 30 days pass
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;
        int opt3 = costs[2] + solve(n, days, costs, i);

        dp[index] = min(opt1, min(opt2, opt3));
        return dp[index];
    }

    int solveTab(int n, vector<int> &days, vector<int> &costs)
    {
        vector<int> dp(n + 1, INT_MAX);

        dp[n] = 0;

        for (int k = n - 1; k >= 0; k--)
        {
            // 1 day pass
            int opt1 = costs[0] + dp[k + 1];

            // 7 day pass
            int i;
            for (i = k; i < n && days[i] < days[k] + 7; i++)
                ;

            int opt2 = costs[1] + dp[i];

            // 30 days pass
            for (i = k; i < n && days[i] < days[k] + 30; i++)
                ;
            int opt3 = costs[2] + dp[i];

            dp[k] = min(opt1, min(opt2, opt3));
        }

        return dp[n];
    }

    int solveSpaceOpt(int n, vector<int> &days, vector<int> &costs)
    {
        int ans = 0;

        queue<pair<int, int>> week;
        queue<pair<int, int>> month;

        for (auto day : days)
        {

            // remove invalid days
            while (!month.empty() && month.front().first + 30 <= day)
                month.pop();

            while (!week.empty() && week.front().first + 7 <= day)
                week.pop();

            // add cost to current day
            month.push(make_pair(day, ans + cost[2]));
            week.push(make_pair(day, ans + cost[1]));

            // update ans
            ans = min(ans + cost[0], min(week.front().second, month.front().second));
        }
        return ans;
    }

public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int n = days.size();
        // return solve(n, days, costs, 0);
        vector<int> dp(n + 1, -1);
        return solveMem(n, days, costs, 0, dp);
    }
};

int main()
{

    return 0;
}