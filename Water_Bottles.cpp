#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = 0;

        while (numBottles > numExchange)
        {
            int rem = numBottles / numExchange;
            ans += rem * numExchange;
            numBottles -= rem * numExchange;

            numBottles += rem;
        }

        cout << ans;
        return ans + numBottles;
    }
};

int main()
{
    Solution s;
    s.numWaterBottles(15, 4);
    return 0;
}