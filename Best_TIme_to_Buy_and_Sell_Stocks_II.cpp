#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // TLE
    int solve(int index, int buy, vector<int> &prices)
    {
        if (index == prices.size())
            return 0;

        int profit = 0;
        if (buy)
            profit = max((-prices[index] + solve(index + 1, 0, prices)), (solve(index + 1, 1, prices)));
        else
            profit = max((prices[index] + solve(index + 1, 1, prices)), (solve(index + 1, 0, prices)));

        return profit;
    }

    int solveMem(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if (buy)
            profit = max((-prices[index] + solveMem(index + 1, 0, prices, dp)), (solveMem(index + 1, 1, prices, dp)));
        else
            profit = max((prices[index] + solveMem(index + 1, 1, prices, dp)), (solveMem(index + 1, 0, prices, dp)));

        return dp[index][buy] = profit;
    }

    int solveTab(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        for (int index = n - 1; index >= 0; index++)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                    profit = max((-prices[index] + dp[index + 1][0]), (dp[index + 1][1]));
                else
                    profit = max((prices[index] + dp[index + 1][1]), (dp[index + 1][0]));

                dp[index][buy] = profit;
            }
        }

        return dp[0][1];
    }

    int solveTabSO(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> curr(2, 0);
        vector<int> next(2, 0);

        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy)
                    profit = max((-prices[index] + next[0]), (next[1]));
                else
                    profit = max((prices[index] + next[1]), (next[0]));

                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solveMem(0, 1, prices, dp);
    }
};

int main()
{

    return 0;
}