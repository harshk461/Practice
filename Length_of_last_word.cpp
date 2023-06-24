#include <bits/stdc++.h>
using namespace std;

int lengthOfLastWord(string s)
{
    s.erase(0, s.find_first_not_of(' '));
    s.erase(s.find_last_not_of(' ') + 1);
    vector<string> arr;
    string word_temp = "";
    for (int i = 0; i <= s.length(); i++)
    {
        if (s[i] == ' ' || i == s.length())
        {
            arr.push_back(word_temp);
            word_temp = "";
        }
        else
        {
            word_temp = word_temp + s[i];
        }
    }
    return arr[arr.size() - 1].length();
}

int main()
{
    
    return 0;
}