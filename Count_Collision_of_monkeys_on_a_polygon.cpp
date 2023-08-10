#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    long long power(long long x, long long y, long long p)
    {
        long long res = 1;

        while (y > 0)
        {
            if (y % 2 == 1)
                res = (res * x) % p;

            // y=y/2
            y = y >> 1;

            // x->x^2
            x = (x * x) % p;
        }
        return res % p;
    }

public:
    int monkeyMove(int n)
    {
        long long ans = power(2, n, 1000000007);
        ans = (ans + 1000000007 - 2) % 1000000007;
        return (int)ans;
    }
};

int main()
{
    Solution s;
    s.monkeyMove(3);
    return 0;
}