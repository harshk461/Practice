#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int anton = 0, danik = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'A')
        {
            anton++;
        }
        if (str[i] == 'D')
        {
            danik++;
        }
    }
    if (anton > danik)
        cout << "Anton" << endl;
    else if (anton < danik)
        cout << "Danik" << endl;
    else
        cout << "Friendship" << endl;
}