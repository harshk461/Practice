#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string getSmallestString(string s)
    {
        for (int i = 0; i < s.length() - 1; i++)
        {
            int a1 = s[i] - '0';
            int a2 = a[i + 1] - '0';

            if (a1 % 2 == 0 && a2 % 2 == 0 && a1 < a2 ||
                a1 % 2 != 0 && a2 % 2 != 0 && a1 < a2)
                swap(s[i], s[i + 1]);
        }

        return s;
    }
};

int main()
{

    return 0;
}