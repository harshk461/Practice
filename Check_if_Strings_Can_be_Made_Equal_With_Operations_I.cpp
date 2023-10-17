#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canBeEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        int i = 0, j = 2;
        while (i < 4)
        {
            if (s1[i] == s2[i])
                i++, j++, continue;
            else
            {
                if (s1[i] != s2[j])
                    return false;
                else
                {
                    swap(s2[i], s2[j]);
                    i++, j++;
                }
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}