#include <bits/stdc++.h>
using namespace std;

string mergeAlternately(string word1, string word2)
{
    int s1 = 0, s2 = 0;
    string ans = "";
    while (s1 < word1.length() && s2 < word2.length())
    {
        ans.push_back(word1[s1++]);
        ans.push_back(word2[s2++]);
    }
    if (s1 < word1.length())
    {
        while (s1 < word1.length())
        {
            ans.push_back(word1[s1++]);
        }
    }
    else
    {
        while (s2 < word2.length())
        {
            ans.push_back(word2[s2++]);
        }
    }
    return ans;
}

int main()
{
    string ans = mergeAlternately("ab", "pgrs");
    cout << ans;
    return 0;
}