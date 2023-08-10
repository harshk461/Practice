#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> ans;
        int n = prices.size();
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (j > i && prices[j] <= prices[i] && !vis[i])
                {
                    prices[i] = abs(prices[i] - prices[j]);
                    vis[i] = true;
                }
            }
        }
        for (auto i : prices)
            cout << i << " ";
        return prices;
    }
};

int main()
{
    vector<int> arr = {8, 4, 6, 2, 3};
    Solution s;
    s.finalPrices(arr);
    return 0;
}