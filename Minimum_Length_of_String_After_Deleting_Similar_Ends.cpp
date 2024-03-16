#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumLength(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                auto t = s[i];
                while (s[i] == t && i < j)
                    i++;

                while (s[j] == t && i <= j)
                    j--;
            }
            else
                return j - i + 1;
        }

        return j - i + 1;
    }
};

int main()
{

    return 0;
}