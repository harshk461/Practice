#include <bits/stdc++.h>
using namespace std;

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