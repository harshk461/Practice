#include <bits/stdc++.h>
using namespace std;

// recursive
bool checkSubsequence(string s, string t, int i, int j)
{
    if (i == -1)
    {
        return true;
    }
    if (j == -1)
    {
        return false;
    }

    if (s[i] == t[j])
    {
        return checkSubsequence(s, t, i - 1, j - 1);
    }
    return checkSubsequence(s, t, i, j - 1);
}

bool isSubsequence(string s, string t)
{
    return checkSubsequence(s, t, s.size() - 1, t.size() - 1);
}

// 2 Pointer Approach
bool isSubsequence2(string s, string t)
{
    int i = s.size() - 1, j = t.size() - 1;
    while (i >= 0 && j >= 0)
    {
        if (s[i] == t[j])
        {
            i--;
            j--;
        }
        else
        {
            j--;
        }
    }
    if (i >= 0)
    {
        return false;
    }
    return true;
}

int main()
{
    string s = "axc";
    string t = "ahhgdc";
    isSubsequence(s, t);
    return 0;
}