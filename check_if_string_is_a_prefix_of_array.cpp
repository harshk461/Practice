#include <bits/stdc++.h>
using namespace std;

bool isPrefixString(string s, vector<string> &words)
{
    string temp = "";
    for (auto i : words)
    {
        temp += i;
    }
    if (temp.find(s) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
    vector<string> arr = {"i", "love", "leetcode", "apples"};
    isPrefixString("iloveleetcode", arr);
    return 0;
}