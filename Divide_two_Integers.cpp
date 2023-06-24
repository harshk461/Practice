#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    // overflow
    if (dividend == INT_MIN && divisor == -1)
    {
        return INT_MAX;
    }
    int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;

    long long ans = abs(dividend) / abs(divisor);
    return ans * sign;
}

int main()
{
    // cout << divide(-2147483648, -1);
    return 0;
}