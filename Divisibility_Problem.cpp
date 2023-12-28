#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        if (a % b == 0)
            cout << 0 << endl;
        else
        {
            int div = a / b;
            int ans = (div + 1) * b;
            cout << ans - a << endl;
        }
    }
    return 0;
}