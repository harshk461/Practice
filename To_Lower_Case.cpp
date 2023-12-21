#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string toLowerCase(string s)
    {
        for (int i = 0; i < s.length(); i++)
            if (s[i] >= 65 && s[i] <= 90)
                s[i] = s[i] - 65 + 'a';
        return s;
    }
};

int main()
{
    Solution s;
    s.toLowerCase("LOVELU");
    return 0;
}