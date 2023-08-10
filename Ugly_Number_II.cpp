#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> ugly{1};
        int i2 = 0, i3 = 0, i5 = 0;

        while (ugly.size() < n)
        {
            int next2 = ugly[i2] * 2;
            int next3 = ugly[i3] * 3;
            int next5 = ugly[i5] * 5;
            int next = min({next2, next3, next5});
            if (next == next2)
                ++i2;
            if (next == next3)
                ++i3;
            if (next == next5)
                ++i5;
            ugly.push_back(next);
        }
        return ugly.back();
    }
};

int main()
{
    Solution s;
    s.nthUglyNumber(10);
    return 0;
}