#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;
    int factorial(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        return n * (factorial(n - 1));
    }

public:
    int countOrders(int n)
    {
        int ans = (factorial(2 * n)) % MOD;
        ans /= pow(2, n);
        ans %= MOD;
        return ans;
    }
};

int main()
{

    return 0;
}