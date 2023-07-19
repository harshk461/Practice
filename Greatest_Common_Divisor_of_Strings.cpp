#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    string mod(string &a, string &b)
    {
        while (a.find(b) == 0)
            a = a.substr(b.length());
        return a;
    }

public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1.length() < str2.length())
            return (str2, str1);

        if (str1.find(str2) == str1.end())
            return "";
        if (str2.empty())
            return str1;
        return gcdOfStrings(str2, mod(str1, str2));
    }
};

int main()
{

    return 0;
}