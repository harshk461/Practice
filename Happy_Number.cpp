#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1 || n == 7)
            return true;

        int sum = n, x = n;
        while (sum > 9)
        {
            sum = 0;
            while (x > 0)
            {
                sum += pow(x % 10, 2);
                x /= 10;
            }
            if (sum == 1)
                return true;
            x = sum;
        }
        if (sum == 7)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}