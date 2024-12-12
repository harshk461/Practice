#include <bits/stdc++.h>
using namespace std;

auto speedUP = []()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution
{
public:
    int isPrefixOfWord(string sentence, string searchWord)
    {
        vector<string> words;
        string curr = "";
        for (int i = 0; i <= sentence.size(); i++)
        {
            if (sentence[i] == ' ' || i == sentence.size())
            {
                words.push_back(curr);
                curr = "";
            }
            else
                curr += sentence[i];
        }

        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            if (words[i].size() < searchWord.size())
                continue;
            string prefix = words[i].substr(0, searchWord.size());
            // cout<<prefix<<" ";
            if (prefix == searchWord)
                return i + 1;
        }
        return -1;
    }
};

int main()
{

    return 0;
}