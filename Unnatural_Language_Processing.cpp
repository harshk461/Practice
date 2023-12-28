#include <bits/stdc++.h>
using namespace std;

bool checkVowel(char ch)
{
    return (ch == 'a' || ch == 'e');
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string temp = "";
        vector<string> ans;
        for (int i = n - 1; i >= 0; i--)
        {
            if (!checkVowel(s[i]))
                temp += s[i];
            if()
        }
    }
    return 0;
}