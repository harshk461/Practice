#include <bits/stdc++.h>
using namespace std;

vector<string> wordSplit(string word)
{
    vector<string> arr;
    string word_temp = "";
    for (int i = 0; i <= word.length(); i++)
    {
        if (word[i] == ' ' || i == word.length())
        {
            arr.push_back(word_temp);
            word_temp = "";
        }
        else
        {
            word_temp = word_temp + word[i];
        }
    }
    return arr;
}

string largestWordCount(vector<string> &messages, vector<string> &senders)
{
    string ans;
    int maxLen = INT_MIN;
    unordered_map<string, int> map;
    for (int i = 0; i < messages.size(); i++)
    {
        string temp = messages[i];
        int word_len = wordSplit(temp).size();
        map[senders[i]] += word_len;
    }
    for (auto i : map)
    {
        if (i.second > maxLen)
        {
            maxLen = i.second;
            ans = i.first;
        }

        else if (i.second == maxLen)
        {
            ans = max(i.first, ans);
        }
    }
    return ans;
}

int main()
{
    vector<string> msg = {"How is leetcode for everyone", "Leetcode is useful for practice"};
    vector<string> send = {"Bob", "Charlie"};
    cout << largestWordCount(msg, send);
    return 0;
}