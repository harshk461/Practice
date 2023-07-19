#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2)
    {
        long long ans = 0;
        int maxPen = total / cost1;

        for (int i = 0; i <= maxPen; i++)
        {
            ans += (total - cost1 * i) / cost2 + 1;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.waysToBuyPensPencils(5, 10, 10);
    return 0;
}