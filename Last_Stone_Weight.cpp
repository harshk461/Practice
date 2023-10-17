#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (!pq.empty())
        {
            if (pq.size() == 1)
                return pq.top();

            else if (pq.size() > 2)
            {
                int x = pq.top();
                pq.pop();
                int y = pq.top();
                pq.pop();

                if (x != y)
                    pq.push(abs(x - y));
            }
            else if (pq.size() == 2)
            {
                int x = pq.top();
                pq.pop();
                int y = pq.top();
                pq.pop();
                return abs(x - y);
            }
        }
        return 0;
    }
};

int main()
{

    return 0;
}