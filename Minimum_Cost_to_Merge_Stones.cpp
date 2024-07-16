#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mergeStones(vector<int> &stones, int k)
    {
        int n = stones.size();
        if (n % k != 0)
            return -1;

        deque<int> dq;
        for (auto it : stones)
            dq.push_back(it);

        while (dq.size() > 1)
        {
            int sum = 0;
            int K = k;
            while (K--)
            {
                sum += dq.front();
                dq.pop_front();
                K--;
            }

            dq.push_front(sum);
        }

        return dq.front();
    }
};

int main()
{
    return 0;
}