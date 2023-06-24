#include <bits/stdc++.h>
using namespace std;

void trim(string &s)
{
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
}
int myAtoi(string s)
{
    trim(s);
    if (s.empty())
    {
        return 0;
    }

    int sign = s[0] == '-' ? -1 : 1;
    if (s[0] == '+' || s[0] == '-')
    {
        s = s.substr(1);
    }

    long num = 0;
    for (auto c : s)
    {
        if (!isdigit(c))
        {
            break;
        }
        num = num * 10 + (c - '0');
        if (sign * num <= INT_MIN)
        {
            return INT_MIN;
        }
        if (sign * num > INT_MAX)
        {
            return INT_MAX;
        }
    }

    return sign * num;
}

int main()
{
    string s = "  31 shj  hsjk  ";
    cout << myAtoi(s);
    return 0;
}