#include <bits/stdc++.h>
using namespace std;

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

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] != s[i + 1] && s[i] != '#' && s[i + 1] != '#')
            {
                s[i] = '#';
                s[i + 1] = '#';
            }
        }
        cout << s << endl;
    }
    return 0;
}