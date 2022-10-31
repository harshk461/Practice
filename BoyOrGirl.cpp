#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int arr[26] = {0};
    for (int i = 0; i < str.length(); i++)
    {
        int value = str[i] - 'a';
        arr[value]++;
    }
    int val = 0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
        {
            val++;
        }
    }

    if (val % 2 == 0)
    {
        cout << "CHAT WITH HER!" << endl;
    }
    else
    {
        cout << "IGNORE HIM!" << endl;
    }
}