#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfMatches(int n)
    {
        if (n == 1)
            return 0;
        int ans = 1;
        while (n > 2)
        {
            int temp = n / 2;
            ans += temp;
            n -= temp;
        }
        return ans;
    }
};

int main()
{

    return 0;
}