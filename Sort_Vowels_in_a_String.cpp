#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string sortVowels(string s)
    {
        vector<int> vowel;
        int i = 0;
        for (auto it : s)
        {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u' ||
                it == 'A' || it == 'E' || it == 'I' || it == 'O' || it == 'U')
                vowel.push_back(it);
        }

        sort(vowel.begin(), vowel.end());
        for (int j = 0; j < s.length(); j++)
        {
            if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u' ||
                s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U')
                s[j] = vowel[i++];
        }
        return s;
    }
};

int main()
{

    return 0;
}