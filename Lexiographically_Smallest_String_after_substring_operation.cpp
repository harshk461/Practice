#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestString(string s)
    {
        int n = s.length();
        int i = 0;

        while (i < n && s[i] == 'a')
            i++;
        if (i == n)
        {
            s[n - 1] = 'z';
            return s;
        }

        while (i < n && s[i] != 'a')
            --s[i++];
        return s;
    }
};

int main()
{
    Solution s;
    cout << s.smallestString("cbabc");
    return 0;
}