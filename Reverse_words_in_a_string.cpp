#include <bits/stdc++.h>
using namespace std;

void reverseWord(string &s, int n)
{
    int i = 0, j = 0;
    while (i < n)
    {
        // skip spaces
        while (i < j || i < n && s[i] == ' ')
            ++i;

        // size of word
        while (j < i || j < n && s[j] != ' ')
            ++j;
        reverse(s.begin() + i, s.begin() + j);
    }
}

string cleanString(string &s, int n)
{
    int i = 0, j = 0;
    while (j < n)
    {
        // skip space(starting space)
        while (j < n && s[j] == ' ')
            ++j;

        // keep words
        while (j < n && s[j] != ' ')
            s[i++] = s[j++];

        // ending spaces
        while (j < n && s[j] == ' ')
            ++j;
        if (j < n)
            s[i++] = ' ';
    }
    return s.substr(0, i);
}

string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    reverseWord(s, s.length());
    return cleanString(s, s.length());
}

int main()
{
    cout << reverseWords("a good   example");
    return 0;
}