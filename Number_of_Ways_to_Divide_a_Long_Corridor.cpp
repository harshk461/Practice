#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int numberOfWays(string corridor)
    {
        int zero = 0;
        int one = 0;
        int two = 1;

        for (auto ch : corridor)
        {
            if (ch == 'S')
            {
                zero = one;
                swap(one, two);
            }
            else
                two = (two + zero) % MOD;
        }

        return zero;
    }
};

int main()
{

    return 0;
}