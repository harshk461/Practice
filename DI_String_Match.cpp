#include <bits/stdc++.h>
using namespace std;

vector<int> diStringMatch(string s)
{
    int n = s.length();
    vector<int> blank;
    for (int i = 0; i <= n; i++)
    {
        blank.push_back(i);
    }
    vector<int> res;
    int front = 0;
    int back = n;
    for (int i = 0; i <= n; i++)
    {
        if (s[i] == 'I')
        {
            int data = blank[back];
            cout << data << " ";
            back--;
            res.push_back(data);
        }
        else
        {
            int data = blank[front];
            front++;
            cout << data << " ";
            res.push_back(data);
        }
    }

    return res;
}

int main()
{
    string s = "III";
    diStringMatch(s);
    return 0;
}