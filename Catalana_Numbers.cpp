#include <bits/stdc++.h>
using namespace std;

// solve Binomial Coefficient C(n,k)
long int solve(int n, int k)
{
    long int res = 1;
    // since C(n,k)=C(n,n-k)
    if (k > n - k)
        k = n - k;

    for (int i = 0; i < k; i++)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

int catalan(int n)
{
    long long c = solve(2 * n, n);
    return c / (n + 1);
}

int main()
{

    return 0;
}