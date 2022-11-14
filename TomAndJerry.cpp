#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int K, a, b, c, d;
        cin >> a >> b >> c >> d >> K;
        int distance = abs(a - c) + abs(b - d);
        if (distance > K)
            cout << "No" << endl;
        else if ((K - distance) % 2 == 1)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
