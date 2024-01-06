#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeTrailingZeros(string num)
    {
        int i = num.length() - 1;
        while (i >= 0)
        {
            if (num[i] != '0')
                break;
            i--;
        }
        // cout << num.substr(0, i + 1);
        return num.substr(0, i + 1);
    }
};

int main()
{
    Solution s;
    s.removeTrailingZeros("123");
    return 0;
}