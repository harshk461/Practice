#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int ans = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> maxHeap;
        for (auto pile : piles)
            maxHeap.push(pile);
        for (int i = 0; i < k; i++)
        {
            int top = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(top - top / 2);
            ans -= top / 2;
        }
        return ans;
    }
};

int main()
{

    return 0;
}