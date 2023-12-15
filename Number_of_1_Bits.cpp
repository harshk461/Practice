#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        if (n == 0)
            return 0;
        unsigned ans = 0;
        for (; n > 0; n &= (n - 1))
            ans++;
        return ans;
    }
};

int main()
{

    return 0;
}