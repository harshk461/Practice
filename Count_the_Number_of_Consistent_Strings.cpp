#include <bits/stdc++.h>
using namespace std;

int countConsistentStrings(string allowed, vector<string> &words)
{
    int ans = words.size();
    int list[26] = {};
    for (auto i : allowed)
    {
        list[i - 'a']++;
    }

    for (auto word : words)
    {
        for (auto c : word)
        {
            if (list[c - 'a'] == 0)
            {
                ans--;
                break;
            }
        }
    }
    return ans;
}Kth Distinct String in an Array


int main()
{

    return 0;
}