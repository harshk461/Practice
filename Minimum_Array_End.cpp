#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    long long minEnd(int n, int x)
    {
        long long result = x;
        while (--n)
        {
            result = (result + 1) | x;
        }
        return result;
    }
};

int main()
{

    return 0;
}