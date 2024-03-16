#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findComplement(int num)
    {
        int ans = 0;
        int i = 0;
        while (num)
        {
            ans += (((num & 1) ^ 1) << i);
            i++;
            num >>= 1;
        }

        return ans;
    }
};

int main()
{
    Solution s;
    cout << s.findComplement(5);
    return 0;
}