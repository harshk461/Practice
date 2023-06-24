#include <bits/stdc++.h>
using namespace std;

int prefixCount(vector<string> &words, string pref)
{
    int n = 0;
    for (auto i : words)
    {
        if (i.find(pref) == 0)
        {
            n++;
        }
    }
    return n;
}

int main()
{
    string s = "attention";
    cout << s.find("en");
    return 0;
}