#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int index, int operationNo, int k, vector<int> &prices)
    {
        if (index == prices.size())
            return 0;

        if (operationNo == 2 * k)
            return 0;

        int profit = 0;

        if (operationNo % 2 == 0)
            // buy allowed
            profit = max(-prices[index] + solve(index + 1, operationNo + 1, k, prices), solve(index + 1, operationNo, k, prices));
        else
            // sell allowes
            profit = max(prices[index] + solve(index + 1, operationNo + 1, k, prices), solve(index + 1, operationNo, k, prices));

        return profit;
    }

    int solveMem(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (operationNo == 2 * k)
            return 0;

        if (dp[index][operationNo] != -1)
            return dp[index][operationNo];

        int profit = 0;

        if (operationNo % 2 == 0)
            // buy allowed
            profit = max(-prices[index] + solveMem(index + 1, operationNo + 1, k, prices, dp), solveMem(index + 1, operationNo, k, prices, dp));
        else
            // sell allowes
            profit = max(prices[index] + solveMem(index + 1, operationNo + 1, k, prices, dp), solveMem(index + 1, operationNo, k, prices, dp));

        return dp[index][operationNo] = profit;
    }

    int solveTab(int k, vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2 * k, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int operation = 0; operation < 2 * k; operation++)
            {
                int profit = 0;

                if (operation % 2 == 0)
                    // buy allowed
                    profit = max(-prices[index] + dp[index + 1][operation + 1], dp[index + 1][operation]);
                else
                    // sell allowes
                    profit = max(prices[index] + dp[index + 1][operation + 1], dp[index + 1][operation]);

                dp[index][operation] = profit;
            }
        }
        return dp[0][k];
    }

    int solveTabSO(vector<int> &prices, int k)
    {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));
        vector<vector<int>> next(2, vector<int>(k + 1, 0));
        for (int index = n - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= k; limit++)
                {
                    int profit = 0;
                    if (buy)
                        profit = max((-prices[index] + next[0][limit]), (next[1][limit]));
                    else
                        profit = max((prices[index] + next[1][limit - 1]), (next[0][limit]));

                    curr[buy][limit] = profit;
                }
                next = curr;
            }
        }
        return next[1][k];
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));
        return solveTabSO(prices, k);
    }
};

int main()
{

    return 0;
}