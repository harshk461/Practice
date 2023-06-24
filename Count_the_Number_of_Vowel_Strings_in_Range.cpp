#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int vowelStrings(vector<string> &words, int left, int right)
    {
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            string word = words[i];
            int vowel = 0;
            int len = word.length() - 1;
            if ((word[0] == 'a' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u') && (word[len] == 'a' || word[len] == 'e' || word[len] == 'i' || word[len] == 'o' || word[len] == 'u') && i >= left && i <= right)
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    vector<string> words;
    words.push_back("ce");
    words.push_back("ai");
    cout << vowelStrings(words, 1, 1);
    return 0;
}