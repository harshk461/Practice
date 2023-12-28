#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int n = s1.length();
    int i;
    for (i = 0; i < n; i++)
    {
        if (tolower(s1[i]) < tolower(s2[i]))
        {
            cout << -1 << endl;
            break;
        }
        else if (tolower(s1[i]) > tolower(s2[i]))
        {
            cout << 1 << endl;
            break;
        }
        else if ((tolower(s1[i]) == tolower(s2[i])) && i == (n - 1))
            cout << 0 << endl;
    }
    return 0;
}