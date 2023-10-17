#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int n)
    {
        if (n < 2)
            return n;
        int ans;
        if (n % 2 == 0)
            ans = solve(n / 2);
        else
            ans = solve(n / 2) + solve(n / 2 + 1);

        return ans;
    }

public:
    int getMaximumGenerated(int n)
    {
        int ans = INT_MIN;
        for (int i = 0; i <= n; i++)
            ans = max(ans, solve(i));
        return ans;
    }
};

int main()
{

    return 0;
}