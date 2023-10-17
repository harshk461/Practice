#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int i = 0;
        while (i < t.length())
        {
            if (i < s.length())
            {
                if (s[i] != t[i])
                    return t[i];
                i++;
            }
            else
                i++;
        }
        return t[i];
    }
};

int main()
{

    return 0;
}