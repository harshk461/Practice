#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string replaceDigits(string s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 != 0)
            {
                s[i] = shift(s[i - 1], s[i]);
            }
        }
        return s;
    }
};

int main()
{

    return 0;
}