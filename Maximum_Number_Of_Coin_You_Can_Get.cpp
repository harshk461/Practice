#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        deque<int> dq;
        for (auto it : piles)
            dq.push_back(it);

        int ans = 0;
        while (!dq.empty())
        {
            dq.pop_back();
            ans += dq.back();
            dq.pop_back();
            dq.pop_front();
        }

        return ans;
    }
};

int main()
{

    return 0;
}