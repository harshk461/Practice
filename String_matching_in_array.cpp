#include <bits/stdc++.h>
using namespace std;

bool isSubstr(string a, string b)
{
    int n = a.size(), m = b.size();
    for (int i = 0; i <= n - m; i++)
    {
        if (a.substr(i, m) == b)
            return true;
    }
    return false;
}
vector<string> stringMatching(vector<string> &words)
{
    unordered_set<string> tmp;
    int n = words.size();
    for (int i = 0; i < n - 1; i++)
    {
        string curWord = words[i];
        for (int j = i + 1; j < n; j++)
        {
            string nextWord = words[j];
            if (isSubstr(curWord, nextWord))
                tmp.insert(nextWord);
            if (isSubstr(nextWord, curWord))
                tmp.insert(curWord);
        }
    }
    return vector<string>(tmp.begin(), tmp.end());
}

int main()
{
    vector<string> arr = {"leetcode", "et", "leet"};
    sort(arr.begin(), arr.end());
    set<string> s;
    for (auto i : arr)
    {
        for (auto j : arr)
        {
            if (i.find(j) > i.length())
            {
                s.insert(j);
            }
        }
    }

    for (auto i : s)
    {
        cout << i << " ";
    }
    return 0;
}