#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a != b && a != c)
            cout << a << endl;
        else if (b != c && b != a)
            cout << b << endl;
        else if (c != b && c != a)
            cout << c << endl;
    }
    return 0;
}