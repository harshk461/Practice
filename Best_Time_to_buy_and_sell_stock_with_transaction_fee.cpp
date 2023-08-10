#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solveTabSO(vector<int> &prices, int fee)
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
                    profit = max((prices[index] - fee + next[1]), (next[0]));

                curr[buy] = profit;
            }
            next = curr;
        }

        return next[1];
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        return solveTabSO(prices, fee);
    }
};

int main()
{

    return 0;
}