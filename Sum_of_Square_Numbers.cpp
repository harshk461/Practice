#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // tle
    bool brute(int c)
    {
        for (int a = 0; a < c; i++)
            for (int b = 0; b < c; b++)
                if (a * a + b * b == c)
                    return true;
        return false;
    }

    bool brute2(int c)
    {
        for (long a = 0; a * a <= c; a++)
        {
            double b = sqrt(c - a * a);
            if (b == (int)b)
                return true;
        }
        return false;
    }

public:
    bool judgeSquareSum(int c)
    {
        return brute(c);
    }
};

int main()
{

    return 0;
}