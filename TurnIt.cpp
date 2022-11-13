#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int u, v, a, s;
        cin >> u >> v >> a >> s;
        double max_v = sqrt(u * u - 2 * a * s);
        cout << max_v << endl;
        if (u <= v)
            cout << "Yes" << endl;
        else if (max_v > v)
            cout << "No" << endl;
    }
    return 0;
}
