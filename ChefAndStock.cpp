#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        double c, s;
        cin >> s >> a >> b >> c;
        if (c < 0)
        {

            double percentage = (c / 100) * s;
            s += percentage;
        }
        else
        {
            double percentage = (c / 100) * s;
            s += percentage;
        }
        if (s >= a && s <= b)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
