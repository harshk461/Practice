#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 1)
            return true;
        if (n % 3 != 0 || n == 0)
            return false;
        return isPowerOfThree(n / 3);
    }
};

int main()
{

    return 0;
}