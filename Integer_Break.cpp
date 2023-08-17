#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int n)
    {
        if (n == 2 || n == 3)
            return n - 1;

        int res = 1;
        while (n > 4)
        {
            n -= 3;
            res *= 3;
        }
        return n * res;
    }

public:
    int integerBreak(int n)
    {
        return solve(n);
    }
};

int main()
{

    return 0;
}