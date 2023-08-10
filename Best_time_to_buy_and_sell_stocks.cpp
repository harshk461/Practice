#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr)
{
    int mini = arr[0];
    int profit = 0;
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i] - mini;
        profit = max(profit, diff);
        mini = min(mini, arr[i]);
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    int buy = prices[0], max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < buy)
        {
            buy = prices[i];
        }

        else if (prices[i] - buy > max_profit)
        {
            max_profit = prices[i] - buy;
        }
    }
    return max_profit;
}
int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(arr);
    return 0;
}