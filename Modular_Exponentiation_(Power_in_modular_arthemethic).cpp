#include <bits/stdc++.h>
using namespace std;

int solve(int x, int y, int p)
{
    // initailize ans
    int res = 1;
    while (y > 0)
    {
        if (y % 2 == 1)
        {
            res *= x;
        }
        y = y / 2;

        x = (x * x);
    }
    return res % p;
}

int main()
{
    int x = 2, y = 3, p = 5;
    cout << solve(x, y, p);
    return 0;
}