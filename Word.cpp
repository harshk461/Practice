#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int lower = 0, upper = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 97 && str[i] <= 123)
            lower++;
        if (str[i] >= 65 && str[i] <= 91)
            upper++;
    }

    if (upper > lower)
    {
        // convert to uppercase
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 97 && str[i] <= 123)
            {
                str[i] = 'A' + (str[i] - 'a');
            }
        }
    }
    else
    {
        // convert to lowercase
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] >= 65 && str[i] <= 91)
            {
                str[i] = 'a' + (str[i] - 'A');
            }
        }
    }
    cout << str << endl;
}