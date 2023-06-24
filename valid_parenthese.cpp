#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char> ch;
    int i = 0;
    if (s.empty())
    {
        return true;
    }

    while (i < s.length())
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            ch.push(s[i]);
        }
        else if ((s[i] == ')' && !ch.empty() && ch.top() == '(') ||
                 (s[i] == '}' && !ch.empty() && ch.top() == '{') ||
                 (s[i] == ']' && !ch.empty() && ch.top() == '['))
        {
            ch.pop();
        }
        else
        {
            return false;
        }
        i++;
    }
    if (ch.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    string s = "{[()]}";
    cout << isValid(s);
    return 0;
}