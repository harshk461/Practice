#include <bits/stdc++.h>
using namespace std;

// O(logn)
bool isAnagram(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return (s == t);
}

// O(n)
bool isAnagram(string s, string t)
{
    unordered_map<char, int> map;
    bool ans = true;
    for (auto i : s)
    {
        map[i]++;
    }

    for (auto i : t)
    {
        map[i]--;
    }

    for (auto i : map)
    {
        if (i.second != 0)
        {
            ans = false;
            break;
        }
    }
    return ans;
}

int main()
{
    string s = "harsh";
    string t = "hrah";
    cout << isAnagram(s, t);
    return 0;
}