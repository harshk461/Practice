#include <bits/stdc++.h>
using namespace std;

int uniqueMorseRepresentations(vector<string> &words)
{
    string alpha[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    set<string> s;
    for (int i = 0; i < words.size(); i++)
    {
        string ans = "";
        string word = words[i];
        for (int j = 0; j < word.length(); j++)
        {
            ans += alpha[word[j] - 'a'];
        }
        s.insert(ans);
    }
    return s.size();
}

int main()
{
    vector<string> words;
    words.push_back("gin");
    words.push_back("zen");
    words.push_back("gig");
    words.push_back("msg");
    cout << uniqueMorseRepresentations(words);
    return 0;
}