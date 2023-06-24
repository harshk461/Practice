#include <bits/stdc++.h>
using namespace std;

int countPrefixes(vector<string> &words, string s)
{
    int n = 0;
    for (auto i : words)
    {
        if (s.find(i) == 0)
        {
            n++;
        }
    }
    return n;
}

int main()
{

    return 0;
}