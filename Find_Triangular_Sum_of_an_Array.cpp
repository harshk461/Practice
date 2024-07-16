#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int> &nums)
    {
        deque<int> dq;
        for (auto it : nums)
            dq.pop_back(it);

        while (!dq.size() == 1)
        {
            int n = dq.size();
            while (n--)
            {
                int a = dq.front();
                dq.pop_front();

                int b = dq.front();
                dq.pop_front();

                dq.pop_back(a + b);
            }
        }

        return dq.front();
    }
};

int main()
{

    return 0;
}