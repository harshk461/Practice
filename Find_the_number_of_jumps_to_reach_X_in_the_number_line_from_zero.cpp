#include <bits/stdc++.h>
using namespace std;

// TC-O(N) SC-O(1)
int getSum(int x)
{
    return (x * (x + 1)) / 2;
}

int getCount(int n)
{
    n = abs(n);
    int ans = 0;

    while (getSum(ans) < n || (getSum(ans) - n) & 1)
        ans++;

    return ans;
}

int main()
{

    return 0;
}