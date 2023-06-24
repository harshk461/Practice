#include <bits/stdc++.h>
using namespace std;

vector<string> commonChars(vector<string> &words)
{
    vector<string> ans;
    unordered_map<char, int> finalMap;
    for (char c = 'a'; c <= 'z'; ++c)
    {
        finalMap[c] = 100;
    }

    unordered_map<char, int> count;
    for (auto i : words)
    {
        count.clear();
        string word = i;
        for (auto j : word)
        {
            count[j]++;
        }

        for (char c = 'a'; c <= 'z'; c++)
        {
            finalMap[c] = min(finalMap[c], count[c]);
        }
    }
    string temp;
    int times;

    for (char c = 'a'; c <= 'z'; c++)
    {
        times = finalMap[c];
        temp = c;
        while (times > 0)
        {
            ans.push_back(temp);
            --times;
        }
    }

    return ans;
}

int main()
{

    return 0;
}