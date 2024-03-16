#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        int ans = start;
        for (int i = 0; i < n; i++)
        {
            int t = start + 2 * i;
            ans ^= t;
        }

        return ans;
    }
};

int main()
{

    return 0;
}