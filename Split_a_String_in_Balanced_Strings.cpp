#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int balancedStringSplit(string s)
    {
        int ans = 0;
        int balance = s[0] == 'L' ? 1 : -1;
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == 'L')
                balance++;
            if (s[i] == 'R')
                balance--;

            if (balance == 0)
            {
                ans++;
                balance = 0;
            }
        }

        cout << ans;
        return ans;
    }
};

int main()
{
    Solution s;
    s.balancedStringSplit("RLRRRLLRLL");
    return 0;
}