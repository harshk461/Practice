#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool checkRow(string word)
    {
        int count1 = 0;
        int count2 = 0;
        int count3 = 0;
        for (int i = 0; i < word.length(); i++)
        {
            if (word[i] == 'q' || word[i] == 'w' || word[i] == 'e' || word[i] == 'r' || word[i] == 't' || word[i] == 'y' || word[i] == 'u' || word[i] == 'i' || word[i] == 'o' || word[i] == 'p')
            {
                count1++;
            }
            if (word[i] == 'a' || word[i] == 's' || word[i] == 'd' || word[i] == 'f' || word[i] == 'g' || word[i] == 'h' || word[i] == 'j' || word[i] == 'k' || word[i] == 'l')
            {
                count2++;
            }
            if (word[i] == 'z' || word[i] == 'x' || word[i] == 'c' || word[i] == 'v' || word[i] == 'b' || word[i] == 'n' || word[i] == 'm')
            {
                count3++;
            }
        }
        if (count1 == word.length() || count2 == word.length() || count3 == word.length())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    vector<string> findWords(vector<string> &words)
    {
        vector<string> ans;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            transform(words[i].begin(), words[i].end(), words[i].begin(), ::tolower);
            if (checkRow(words[i]))
            {
                ans.push_back(word);
            }
        }
        return ans;
    }
};