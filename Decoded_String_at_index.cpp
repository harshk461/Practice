#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeAtIndex(string s, int k)
    {
        long long len = 0;
        int i = 0;
        while (len < k)
        {
            if (isdigit(s[i]))
                len *= s[i] - '0';
            else
                len++;
            i++;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            if (isdigit(s[j]))
            {
                len /= s[i] - '0';
                k %= len;
            }
            else
            {
                if (k == 0 || k == len)
                    return string(1, s[j]);
                len--;
            }
        }
        return "";
    }
};

int main()
{

    return 0;
}